/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "analyzerObjectBuilder.hpp"
#include "storageObjectBuilder.hpp"
#include "strus/base/configParser.hpp"
#include "strus/reference.hpp"
#include "strus/databaseInterface.hpp"
#include "strus/databaseClientInterface.hpp"
#include "strus/lib/traceproc_std.hpp"
#include "strus/lib/traceobj.hpp"
#include "strus/lib/error.hpp"
#include "strus/base/fileio.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/queryProcessorInterface.hpp"
#include "strus/queryEvalInterface.hpp"
#include "strus/queryInterface.hpp"
#include "strus/postingJoinOperatorInterface.hpp"
#include "strus/postingIteratorInterface.hpp"
#include "strus/storageInterface.hpp"
#include "strus/storageClientInterface.hpp"
#include "strus/storageTransactionInterface.hpp"
#include "strus/storageDocumentInterface.hpp"
#include "strus/storageObjectBuilderInterface.hpp"
#include "strus/weightingFunctionInterface.hpp"
#include "strus/weightingFunctionInstanceInterface.hpp"
#include "strus/summarizerFunctionInterface.hpp"
#include "strus/summarizerFunctionInstanceInterface.hpp"
#include "strus/analyzerObjectBuilderInterface.hpp"
#include "strus/textProcessorInterface.hpp"
#include "strus/documentAnalyzerInterface.hpp"
#include "strus/queryAnalyzerInterface.hpp"
#include "strus/normalizerFunctionInterface.hpp"
#include "strus/normalizerFunctionInstanceInterface.hpp"
#include "strus/normalizerFunctionContextInterface.hpp"
#include "strus/tokenizerFunctionInterface.hpp"
#include "strus/tokenizerFunctionInstanceInterface.hpp"
#include "strus/tokenizerFunctionContextInterface.hpp"
#include "strus/aggregatorFunctionInterface.hpp"
#include "strus/aggregatorFunctionInstanceInterface.hpp"
#include "strus/valueIteratorInterface.hpp"
#include "strus/traceObjectBuilderInterface.hpp"
#include "strus/traceProcessorInterface.hpp"
#include "strus/traceLoggerInterface.hpp"
#include "strus/traceViewerInterface.hpp"
#include "strus/traceIdMapInterface.hpp"
#include "strus/traceElement.hpp"
#include "strus/traceQuery.hpp"
#include "strus/traceRecord.hpp"
#include "objectIds_gen.hpp"
#include <string>
#include <cstdarg>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <memory>

static strus::ErrorBufferInterface* g_errorhnd = 0;

static strus::StorageClientInterface* createStorage( const strus::StorageObjectBuilderInterface* sob, const char* storageconfig)
{
	const strus::DatabaseInterface* dbi = sob->getDatabase( storageconfig);
	if (!dbi) throw std::runtime_error( "failed to get database interface");
	if (g_errorhnd->hasError()) throw std::runtime_error( g_errorhnd->fetchError());
	(void) dbi->destroyDatabase( storageconfig);
	(void) g_errorhnd->fetchError();
	if (!dbi->createDatabase( storageconfig)) throw std::runtime_error("failed to create database");
	std::auto_ptr<strus::DatabaseClientInterface> database( dbi->createClient( storageconfig));
	if (!database.get()) throw std::runtime_error( "failed to create database client");
	const strus::StorageInterface* sti = sob->getStorage();
	if (!sti) throw std::runtime_error( "failed to get storage interface");
	if (!sti->createStorage( storageconfig, database.get())) throw std::runtime_error( "failed to create storage");
	std::auto_ptr<strus::StorageClientInterface> storage( sti->createClient( storageconfig, database.get()));
	database.release();
	if (!storage.get()) throw std::runtime_error( "failed to get create storage client");
	return storage.release();
}

static std::vector<std::string> split( const char* cfg, const char chr)
{
	std::vector<std::string> rt;
	char const* si = cfg;
	char const* se = std::strchr( si, chr);
	while (se)
	{
		rt.push_back( std::string( si, se-si));
		se = std::strchr( si = se+1, chr);
	}
	rt.push_back( std::string( si, std::strchr( si, '\0')-si));
	return rt;
}

static void parseFunction( std::string& name, std::vector<std::string>& arg, const std::string& src)
{
	arg.clear();
	const char* argstr = std::strchr( src.c_str(), '(');
	if (argstr)
	{
		const char* argend = std::strchr( argstr, ')');
		if (!argend || *(argend+1) != '\0') throw std::runtime_error( "syntax error in function arguments");
		std::string argstrbuf( argstr+1, argend-argstr-1);
		arg = split( argstrbuf.c_str(),',');
		name = std::string( src.c_str(), argstr - src.c_str());
	}
	else
	{
		name = src;
	}
}

enum IndexType
{
	SearchIndex,
	ForwardIndex,
	MetaData,
	Attribute
};

struct DocumentAnalyzerConfig
{
	IndexType indextype;
	const char* type;
	const char* normalizer;
	const char* tokenizer;
	const char* path;
};

struct AnalyzerFunctionDef
{
	AnalyzerFunctionDef( const strus::TextProcessorInterface* textproc, const char* normalizersrc, const char* tokenizersrc)
		:tokenizer(0)
	{
		try
		{
			std::string funcname;
			std::vector<std::string> funcarg;

			std::vector<std::string> nar( split( normalizersrc, ':'));
			std::vector<std::string>::const_iterator ni = nar.begin(), ne = nar.end();
			for (; ni != ne; ++ni)
			{
				parseFunction( funcname, funcarg, *ni); 
				const strus::NormalizerFunctionInterface* normalizer = textproc->getNormalizer( funcname);
				if (!normalizer) throw std::runtime_error( std::string("unknown normalizer '") + *ni + "'");
	
				normalizers.push_back( normalizer->createInstance( funcarg, textproc));
				if (!normalizers.back()) throw std::runtime_error( std::string( "failed to create normalizer '") + *ni + "'");
			}
			{
				parseFunction( funcname, funcarg, tokenizersrc); 
				const strus::TokenizerFunctionInterface* tk = textproc->getTokenizer( funcname);
				if (!tk) throw std::runtime_error( std::string("unknown tokenizer '") + funcname + "'");
	
				tokenizer = tk->createInstance( funcarg, textproc);
				if (!tokenizer) throw std::runtime_error( std::string("failed to create tokenizer '") + funcname + "'");
			}
		}
		catch (const std::bad_alloc&)
		{
			clear();
			throw std::bad_alloc();
		}
		catch (const std::runtime_error& err)
		{
			clear();
			throw std::runtime_error( err.what());
		}
	}

	void clear()
	{
		std::vector<strus::NormalizerFunctionInstanceInterface*>::const_iterator
			ni = normalizers.begin(), ne = normalizers.end();
		for (; ni != ne; ++ni)
		{
			delete *ni;
		}
		normalizers.clear();
		if (tokenizer)
		{
			delete tokenizer;
			tokenizer = 0;
		}
	}

	std::vector<strus::NormalizerFunctionInstanceInterface*> normalizers;
	strus::TokenizerFunctionInstanceInterface* tokenizer;
};

static strus::DocumentAnalyzerInterface* createDocumentAnalyzer( const strus::AnalyzerObjectBuilderInterface* aob, const DocumentAnalyzerConfig* config)
{
	std::auto_ptr<strus::DocumentAnalyzerInterface> analyzer( aob->createDocumentAnalyzer());
	if (!analyzer.get()) throw std::runtime_error( "failed to get create document analyzer");
	const strus::TextProcessorInterface* textproc = aob->getTextProcessor();
	const char* countfeatname = 0;

	std::size_t ai = 0;
	for (; config[ai].type; ++ai)
	{
		AnalyzerFunctionDef anafundef( textproc, config[ai].normalizer, config[ai].tokenizer);
		switch (config[ai].indextype)
		{
			case SearchIndex:
				if (!countfeatname) countfeatname = config[ai].type;
				analyzer->addSearchIndexFeature(
					config[ai].type, config[ai].path, anafundef.tokenizer, anafundef.normalizers);
				break;
			case ForwardIndex:
				analyzer->addForwardIndexFeature(
					config[ai].type, config[ai].path, anafundef.tokenizer, anafundef.normalizers);
				break;
			case MetaData:
				analyzer->defineMetaData(
					config[ai].type, config[ai].path, anafundef.tokenizer, anafundef.normalizers);
				break;
			case Attribute:
				analyzer->defineAttribute(
					config[ai].type, config[ai].path, anafundef.tokenizer, anafundef.normalizers);
				break;
		}
	}
	if (countfeatname)
	{
		std::string funcname = "count";
		std::vector<std::string> funcarg;
		funcarg.push_back( countfeatname);
		const strus::AggregatorFunctionInterface* agf = textproc->getAggregator( funcname);
		if (!agf) throw std::runtime_error( std::string("unknown aggregator '") + funcname + "'");
		strus::AggregatorFunctionInstanceInterface* aggregator = agf->createInstance( funcarg);
		if (!aggregator) throw std::runtime_error( std::string("failed to create aggregator '") + funcname + "'");
		analyzer->defineAggregatedMetaData( "doclen", aggregator);
	}
	return analyzer.release();
}

static strus::QueryAnalyzerInterface* createQueryAnalyzer( const strus::AnalyzerObjectBuilderInterface* aob, const DocumentAnalyzerConfig* config)
{
	std::auto_ptr<strus::QueryAnalyzerInterface> analyzer( aob->createQueryAnalyzer());
	if (!analyzer.get()) throw std::runtime_error( "failed to get create query analyzer");
	const strus::TextProcessorInterface* textproc = aob->getTextProcessor();

	std::size_t ai = 0;
	for (; config[ai].type && config[ai].indextype != SearchIndex; ++ai){}
	if (!config[ai].type) throw std::runtime_error( "no search index feature defined in analyzer configuration");
	
	AnalyzerFunctionDef anafundef( textproc, config[ai].normalizer, config[ai].tokenizer);
	analyzer->definePhraseType( "querystring", config[ai].type, anafundef.tokenizer, anafundef.normalizers);
	return analyzer.release();
}

struct TestDocument
{
	const char* docid;
	const char* content;
};

static void insertDocuments(
	const strus::StorageObjectBuilderInterface* sob,
	const char* storageconfig,
	const strus::AnalyzerObjectBuilderInterface* aob,
	const DocumentAnalyzerConfig* anaconfig,
	const TestDocument* testdocs)
{
	std::auto_ptr<strus::StorageClientInterface> storage( createStorage( sob, storageconfig));
	std::auto_ptr<strus::DocumentAnalyzerInterface> analyzer( createDocumentAnalyzer( aob, anaconfig));
	if (g_errorhnd->hasError()) throw std::runtime_error( std::string( "create document analyzer failed: ") + g_errorhnd->fetchError());

	std::auto_ptr<strus::StorageTransactionInterface> transaction( storage->createTransaction());
	if (!transaction.get()) throw std::runtime_error("create insert transaction failed");
	strus::DocumentClass dclass( "xml", "UTF-8");

	std::size_t di = 0;
	for (; testdocs[di].docid; ++di)
	{
		std::auto_ptr<strus::StorageDocumentInterface>
			stodoc( transaction->createDocument( testdocs[di].docid));

		strus::analyzer::Document 
			anadoc = analyzer->analyze( testdocs[di].content, dclass);
		if (g_errorhnd->hasError()) throw std::runtime_error( std::string( "analyze of document '") + testdocs[di].docid + "' failed: " + g_errorhnd->fetchError());

		std::vector<strus::analyzer::Term>::const_iterator
			ti = anadoc.searchIndexTerms().begin(), te = anadoc.searchIndexTerms().end();
		for (; ti != te; ++ti)
		{
			stodoc->addSearchIndexTerm( ti->type(), ti->value(), ti->pos());
		}
		ti = anadoc.forwardIndexTerms().begin(), te = anadoc.forwardIndexTerms().end();
		for (; ti != te; ++ti)
		{
			stodoc->addForwardIndexTerm( ti->type(), ti->value(), ti->pos());
		}
		std::vector<strus::analyzer::Attribute>::const_iterator
			ai = anadoc.attributes().begin(), ae = anadoc.attributes().end();
		for (; ai != ae; ++ai)
		{
			stodoc->setAttribute( ai->name(), ai->value());
		}
		std::vector<strus::analyzer::MetaData>::const_iterator
			mi = anadoc.metadata().begin(), me = anadoc.metadata().end();
		for (; mi != me; ++mi)
		{
			stodoc->setMetaData( mi->name(), mi->value());
		}
		stodoc->setAttribute( "docid", testdocs[di].docid);
		stodoc->done();
	}
	if (!transaction->commit()) throw std::runtime_error( "storage transaction failed");
	if (g_errorhnd->hasError()) throw std::runtime_error( "error inserting documents");
}

static strus::QueryEvalInterface* createQueryEval( const strus::StorageObjectBuilderInterface* sob)
{
	std::auto_ptr<strus::QueryEvalInterface> qeval( sob->createQueryEval());
	if (!qeval.get()) throw std::runtime_error("failed to create query evaluation");
	const strus::QueryProcessorInterface* qproc = sob->getQueryProcessor();
	if (!qproc) throw std::runtime_error("failed to get query processor");
	qeval->addSelectionFeature( "selfeat");

	const strus::WeightingFunctionInterface* wfunc = qproc->getWeightingFunction( "BM25");
	if (!wfunc) throw std::runtime_error( std::string("undefined weigthing function ") + "BM25");
	std::auto_ptr<strus::WeightingFunctionInstanceInterface> wfuncinst( wfunc->createInstance( qproc));
	if (!wfuncinst.get()) throw std::runtime_error("failed to create weighting function instance");
	wfuncinst->addNumericParameter( "k1", 1.2);
	wfuncinst->addNumericParameter( "b", 0.75);
	wfuncinst->addNumericParameter( "avgdoclen", 15);
	typedef strus::QueryEvalInterface::FeatureParameter FeatureParameter;
	std::vector<FeatureParameter> featureParameters;
	featureParameters.push_back( FeatureParameter( "match", "docfeat"));
	qeval->addWeightingFunction( "BM25", wfuncinst.release(), featureParameters);

	const strus::SummarizerFunctionInterface* sfunc = qproc->getSummarizerFunction( "Attribute");
	if (!sfunc) throw std::runtime_error( std::string("undefined summarizer function ") + "Attribute");
	std::auto_ptr<strus::SummarizerFunctionInstanceInterface> sfuncinst( sfunc->createInstance( qproc));
	if (!sfuncinst.get()) throw std::runtime_error(std::string("failed to create summarizer function instance ") + "Attribute");
	sfuncinst->addStringParameter( "name", "docid");
	qeval->addSummarizerFunction( "attribute", sfuncinst.release(), std::vector<FeatureParameter>());

	sfunc = qproc->getSummarizerFunction( "MatchPos");
	if (!sfunc) throw std::runtime_error( std::string("undefined summarizer function ") + "MatchPos");
	sfuncinst.reset( sfunc->createInstance( qproc));
	if (!sfuncinst.get()) throw std::runtime_error( std::string("failed to create summarizer function instance ") + "MatchPos");
	featureParameters.clear();
	featureParameters.push_back( FeatureParameter( "match", "docfeat"));
	qeval->addSummarizerFunction( "matchpos", sfuncinst.release(), featureParameters);
	return qeval.release();
}

static std::vector<strus::analyzer::Term> analyzeQuery( const strus::AnalyzerObjectBuilderInterface* aob, const DocumentAnalyzerConfig* anaconfig, const char* querystr)
{
	std::auto_ptr<strus::QueryAnalyzerInterface> qana( createQueryAnalyzer( aob, anaconfig));
	if (!qana.get()) throw std::runtime_error("failed to create query analyzer");
	return qana->analyzePhrase( "querystring", querystr);
}

static strus::QueryInterface* createQuery(
		const strus::StorageObjectBuilderInterface* sob,
		const strus::AnalyzerObjectBuilderInterface* aob,
		const strus::StorageClientInterface* storage,
		const strus::QueryEvalInterface* qeval,
		const DocumentAnalyzerConfig* anaconfig,
		const char* querystr)
{
	const strus::QueryProcessorInterface* qproc = sob->getQueryProcessor();
	if (!qproc) throw std::runtime_error("failed to get query processor");

	std::vector<strus::analyzer::Term> qterms = analyzeQuery( aob, anaconfig, querystr);
	if (qterms.empty()) throw std::runtime_error("no query terms in query");

	std::auto_ptr<strus::QueryInterface> query( qeval->createQuery( storage));
	std::vector<strus::analyzer::Term>::const_iterator qi = qterms.begin(), qe = qterms.end();
	for (; qi != qe; ++qi)
	{
		query->pushTerm( qi->type(), qi->value());
		query->defineFeature( "docfeat");
	}
	for (qi = qterms.begin(); qi != qe; ++qi)
	{
		query->pushTerm( qi->type(), qi->value());
	}
	const strus::PostingJoinOperatorInterface* contains = qproc->getPostingJoinOperator("contains");
	query->pushExpression( contains, qterms.size(), 0, 1/*cardinality*/);
	query->defineFeature( "selfeat");
	return query.release();
}


static void testEvaluateQuery(
		const strus::StorageObjectBuilderInterface* sob,
		const strus::AnalyzerObjectBuilderInterface* aob,
		const char* storageconfig,
		const DocumentAnalyzerConfig* analyzerconfig,
		const TestDocument* testdocs,
		const char* querystr)
{
	const strus::QueryProcessorInterface* qproc = sob->getQueryProcessor();
	if (!qproc) throw std::runtime_error("failed to get query processor");

	insertDocuments( sob, storageconfig, aob, analyzerconfig, testdocs);

	std::auto_ptr<strus::StorageClientInterface> storage( sob->createStorageClient( storageconfig));
	std::auto_ptr<strus::QueryEvalInterface> qeval( createQueryEval( sob));
	std::auto_ptr<strus::QueryInterface> query( createQuery( sob, aob, storage.get(), qeval.get(), analyzerconfig, querystr));

	strus::QueryResult result = query->evaluate();
	if (g_errorhnd->hasError()) throw std::runtime_error( "failed to evaluate query");

	std::vector<strus::ResultDocument>::const_iterator ri = result.ranks().begin(), re = result.ranks().end();
	for (; ri != re; ++ri)
	{
		std::cout << ri->docno() << " " << ri->weight() << std::endl;
		std::vector<strus::SummaryElement>::const_iterator
			si = ri->summaryElements().begin(), se = ri->summaryElements().end();
		for (; si != se; ++si)
		{
			std::cout << "\t" << si->name() << " '" << si->value() << "'" << std::endl;
		}
	}
}

static bool diffFiles( const char* file1, const char* file2)
{
	std::string content1;
	unsigned int ec = strus::readFile( file1, content1);
	if (ec) throw std::runtime_error( std::string("could not read file ") + file1 + ": " + ::strerror(ec));
	std::string content2;
	ec = strus::readFile( file2, content2);
	if (ec) throw std::runtime_error( std::string("could not read file ") + file2 + ": " + ::strerror(ec));
	char const* ci1 = content1.c_str();
	char const* ce1 = ci1 + content1.size();
	char const* ci2 = content2.c_str();
	char const* ce2 = ci2 + content2.size();
	while (ci1 != ce1 && ci2 != ce2)
	{
		bool eoln1 = false;
		while (ci1 != ce1 && (*ci1 == '\n' || *ci1 == '\r'))
		{
			eoln1 = true;
			++ci1;
		}
		bool eoln2 = false;
		while (ci2 != ce2 && (*ci2 == '\n' || *ci2 == '\r'))
		{
			eoln2 = true;
			++ci2;
		}
		char ch1 = (!eoln1 && ci1 != ce1)?(*ci1++):'\0';
		char ch2 = (!eoln2 && ci2 != ce2)?(*ci2++):'\0';
		if (eoln1 != eoln2 || ch1 != ch2) return false;
	}
	return ci1 == ce1 && ci2 == ce2;
}


static void envelope(
		std::auto_ptr<strus::StorageObjectBuilderInterface>& sob,
		const strus::TraceObjectBuilderInterface* tob)
{
	strus::StorageObjectBuilderInterface*
		sob_envelope = tob->createStorageObjectBuilder( sob.get());
	if (sob_envelope)
	{
		sob.release();
		sob = std::auto_ptr<strus::StorageObjectBuilderInterface>( sob_envelope);
	}
	else
	{
		throw std::runtime_error("failed to storage object builder proxy");
	}
}

static void envelope(
		std::auto_ptr<strus::AnalyzerObjectBuilderInterface>& aob,
		const strus::TraceObjectBuilderInterface* tob)
{
	strus::AnalyzerObjectBuilderInterface*
		aob_envelope = tob->createAnalyzerObjectBuilder( aob.get());
	if (aob_envelope)
	{
		aob.release();
		aob = std::auto_ptr<strus::AnalyzerObjectBuilderInterface>( aob_envelope);
	}
	else
	{
		throw std::runtime_error("failed to analyzer object builder proxy");
	}
}

struct TestQuery
{
	const char* description;
	strus::TraceClassId classId;
	strus::TraceMethodId methodId;
	strus::TraceObjectId objId;
	strus::TraceTimeCounter time_from;
	strus::TraceTimeCounter time_to;
	strus::TraceTreeDepth depth_from;
	strus::TraceTreeDepth depth_to;
	std::size_t startIndex;
	std::size_t maxNofResults;
};


static std::string encodeText( const char* buf, std::size_t bufsize)
{
	static const char* cntrlchrs = "\n\t\r\b";
	static const char* cntrlsubs = "ntrb0";
	std::string rt;
	std::size_t bi = 0;
	for (; bi < bufsize; ++bi)
	{
		if ((unsigned char)buf[bi] < 32)
		{
			char const* ci = std::strchr( cntrlchrs, buf[bi]);
			if (ci)
			{
				rt.push_back( '\\');
				rt.push_back( cntrlsubs[ ci-cntrlchrs]);
			}
			else
			{
				rt.push_back( '.');
			}
		}
		else if (buf[bi] == '\'')
		{
			rt.push_back( '\\');
			rt.push_back( buf[bi]);
		}
		else
		{
			rt.push_back( buf[bi]);
		}
	}
	return rt;
}

static std::string unpackParam( const strus::TraceIdMapInterface* idmap, char const* param, std::size_t paramsize)
{
	std::ostringstream buf;
	std::vector<std::string> stack;
	bool delim = false;
	const char* name;
	std::vector<strus::TraceElement> elements
		= idmap->unpackElements( param, paramsize);
	std::vector<strus::TraceElement>::const_iterator ei = elements.begin(), ee = elements.end();
	for (int eidx=0; ei != ee; ++ei,++eidx)
	{
		switch (ei->type())
		{
			case strus::TraceElement::TypeVoid:
				if (delim) buf << " ";
				delim = true;
				buf << "()";
				break;
			case strus::TraceElement::TypeInt:
				if (delim) buf << " ";
				delim = true;
				buf << ei->value().Int;
				break;
			case strus::TraceElement::TypeUInt:
				if (delim) buf << " ";
				delim = true;
				buf << ei->value().UInt;
				break;
			case strus::TraceElement::TypeFloat:
				if (delim) buf << " ";
				delim = true;
				buf << std::fixed << std::setprecision(3) << ei->value().Float;
				break;
			case strus::TraceElement::TypeDouble:
				if (delim) buf << " ";
				delim = true;
				buf << std::fixed << std::setprecision(6) << ei->value().Double;
				break;
			case strus::TraceElement::TypeBool:
				if (delim) buf << " ";
				delim = true;
				buf << (ei->value().Bool?"true":"false");
				break;
			case strus::TraceElement::TypeObject:
				if (delim) buf << " ";
				delim = true;
				name = idmap->getClassName( ei->value().Obj.Class);
				if (name) buf << name; else throw std::runtime_error("unknown class id");
				buf << "<" << ei->value().Obj.Id << ">";
				break;
			case strus::TraceElement::TypeString:
				if (delim) buf << " ";
				delim = true;
				buf << encodeText( ei->value().String.Ptr, ei->value().String.Size);
				break;
			case strus::TraceElement::TypeOpenIndex:
				if (delim) buf << " ";
				delim = false;
				stack.push_back( "");
				buf << "<" << ei->value().Index << ">";
				break;
			case strus::TraceElement::TypeOpenTag:
				if (delim) buf << " ";
				delim = false;
				stack.push_back( encodeText( ei->value().String.Ptr, ei->value().String.Size));
				buf << "<" << stack.back() << ">";
				break;
			case strus::TraceElement::TypeClose:
				delim = true;
				if (stack.empty()) throw std::runtime_error( "illegal close tag in trace parameter string");
				buf << "</" << stack.back().c_str() << ">";
				stack.pop_back();
				break;
		}
	}
	return buf.str();
}

static void executeViewerQueries( std::ostream& out, const strus::TraceIdMapInterface* idmap, const strus::TraceViewerInterface* viewer, const TestQuery testQueries[])
{
	std::size_t qi = 0;
	for (; testQueries[qi].description; ++qi)
	{
		out << "QUERY " << testQueries[qi].description << std::endl;

		strus::TraceQuery query;
		if (testQueries[qi].classId) query.restrictClassId( testQueries[qi].classId);
		if (testQueries[qi].methodId) query.restrictMethodId( testQueries[qi].methodId);
		if (testQueries[qi].objId) query.restrictObjId( testQueries[qi].objId);
		if (testQueries[qi].time_from||testQueries[qi].time_to) query.restrictTime( testQueries[qi].time_from, testQueries[qi].time_to);
		if (testQueries[qi].depth_from||testQueries[qi].depth_to) query.restrictDepth( testQueries[qi].depth_from, testQueries[qi].depth_to);

		std::vector<strus::TraceRecord> reclist = viewer->listMethodCalls( query, testQueries[qi].startIndex, testQueries[qi].maxNofResults+1);
		std::vector<strus::TraceRecord>::const_iterator ri = reclist.begin(), re = reclist.end();
		bool hasMore = false;
		if (reclist.size() > testQueries[qi].maxNofResults)
		{
			hasMore = true;
			--re;
		}
		for (; ri != re; ++ri)
		{
			out << "class=" << idmap->getClassName( ri->classId())
				<< "<" << ri->objId() << ">"
				<< "::" << idmap->getMethodName( ri->classId(), ri->methodId())
				<< " start=" <<  ri->startTime()
				<< " end=" <<  ri->endTime()
				<< " depth=" <<  ri->depth()
				<< " param:" << unpackParam( idmap, ri->packedParameter(), ri->packedParameterSize())
				<< std::endl;
		}
		if (hasMore)
		{
			out << "..." << std::endl;
		}
		out << std::endl;
	}
}

static const DocumentAnalyzerConfig g_analyzerconfig[] =
{
	{SearchIndex,"stem","convdia(en):stem(en):lc","word","//text()"},
	{ForwardIndex,"orig","text","split","//text()"},
	{SearchIndex,0,0,0,0}
};
static const TestDocument g_testdocs[] =
{
	{"Doc1", "<doc><text>One morning, when Gregor Samsa woke from troubled dreams, he found himself transformed in his bed into a horrible vermin.</text></doc>"},
	{"Doc2", "<doc><text>He lay on his armour-like back, and if he lifted his head a little he could see his brown belly, slightly domed and divided by arches into stiff sections.</text></doc>"},
	{"Doc3", "<doc><text>The bedding was hardly able to cover it and seemed ready to slide off any moment. His many legs, pitifully thin compared with the size of the rest of him, waved about helplessly as he looked.</text></doc>"},
	{"Doc4", "<doc><text>\"What's happened to me?\" he thought. It wasn't a dream. His room, a proper human room although a little too small, lay peacefully between its four familiar walls.</text></doc>"},
	{"Doc5", "<doc><text>A collection of textile samples lay spread out on the table - Samsa was a travelling salesman - and above it there hung a picture that he had recently cut out of an illustrated magazine and housed in a nice, gilded frame.</text></doc>"},
	{"Doc6", "<doc><text>It showed a lady fitted out with a fur hat and fur boa who sat upright, raising a heavy fur muff that covered the whole of her lower arm towards the viewer. Gregor then turned to look out the window at the dull weather.</text></doc>"},
	{0,0}
};
static const char* g_querystring = "dream transformed vermin";

static const TestQuery g_testQueries[] =
{
	//{description,classId,methodId,objId,time_from,time_to,depth_from,depth_to, I,N}
	{"analyze document (restrict time to 52-150)", 0,0,0,52,150,0,0,0,300},
	{"analyze document (restrict time to 52-150 and depth 1)", 0,0,0,52,150,1,1,0,300},
	{"storage add document (restrict to StorageDocument<26>)", strus::ClassId_StorageDocument,0,26,0,0,0,0,0,300},
	{"database cursor (restrict to StorageDocument<26>)", strus::ClassId_DatabaseCursor,strus::DatabaseCursorConst::Method_seekUpperBound,298,0,0,0,0,0,300},
	{0,0,0,0,0,0,0,0,0,0}
};


int main( int argc, const char* argv[])
{
	if (argc < 4)
	{
		std::cerr << "too few arguments" << std::endl;
		std::cerr << "usage: " << argv[0] << " <config> <outfile> <expfile>" << std::endl;
		return -1;
	}
	if (argc > 5)
	{
		std::cerr << "too many arguments" << std::endl;
		std::cerr << "usage: " << argv[0] << " <config> <outfile> <expfile>" << std::endl;
		return -1;
	}
	std::string outputstr;
	char storagecfg[ 1024];
	snprintf( storagecfg, sizeof(storagecfg), "%s; metadata=doclen UINT16", argv[1]);
	const char* outfile = argv[2];
	char outcfg[ 1024];
	snprintf( outcfg, sizeof(outcfg), "file=%s", outfile);
	const char* expfile = argv[3];
	const char* breakpoints = argc>4?argv[4]:(const char*)0;

	g_errorhnd = strus::createErrorBuffer_standard( stderr, 1);
	if (!g_errorhnd)
	{
		std::cerr << "error allocating error buffer";
		return -1;
	}
	try
	{
		{//begin scope trace processor:

		const strus::TraceIdMapInterface* idmap = 0;
		std::auto_ptr<strus::TraceObjectBuilderInterface> traceObjectBuilder_breakpoint;

		// If breakpoints configured, create trace processor 'breakpoints':
		if (breakpoints)
		{
			strus::TraceProcessorInterface*
				traceproc_breakpoint = strus::createTraceProcessor_breakpoint( g_errorhnd);
			if (!traceproc_breakpoint)
			{
				throw std::runtime_error("failed to create trace processor (textfile)");
			}
			traceObjectBuilder_breakpoint =
				std::auto_ptr<strus::TraceObjectBuilderInterface>(
					strus::traceCreateObjectBuilder(
						traceproc_breakpoint, breakpoints, g_errorhnd));
			if (!traceObjectBuilder_breakpoint.get())
			{
				delete traceproc_breakpoint;
				throw std::runtime_error("failed to create trace object builder (breakpoint)");
			}
		}

		// Create trace processor 'textfile':
		strus::TraceProcessorInterface* 
			traceproc_textfile = strus::createTraceProcessor_textfile( g_errorhnd);
		if (!traceproc_textfile)
		{
			throw std::runtime_error("failed to create trace processor (textfile)");
		}
		std::auto_ptr<strus::TraceObjectBuilderInterface>
			traceObjectBuilder_logtext(
				strus::traceCreateObjectBuilder(
					traceproc_textfile, outcfg, g_errorhnd));
		if (!traceObjectBuilder_logtext.get())
		{
			delete traceproc_textfile;
			throw std::runtime_error("failed to create trace processor (textfile)");
		}

		// Create trace processor 'memory':
		strus::TraceProcessorInterface*
			traceproc_memory = strus::createTraceProcessor_memory( g_errorhnd);
		if (!traceproc_memory)
		{
			throw std::runtime_error("failed to create trace processor (memory)");
		}
		std::auto_ptr<strus::TraceObjectBuilderInterface>
			traceObjectBuilder_memory(
				strus::traceCreateObjectBuilder(
					traceproc_memory, "", g_errorhnd));
		if (!traceObjectBuilder_memory.get())
		{
			delete traceproc_memory;
			throw std::runtime_error("failed to create trace object builder (memory)");
		}
		std::auto_ptr<strus::TraceViewerInterface> viewer( traceObjectBuilder_memory->createViewer());
		if (!viewer.get())
		{
			throw std::runtime_error("failed to create trace viewer (memory)");
		}
		idmap = traceObjectBuilder_memory->getIdMap();

		std::auto_ptr<strus::AnalyzerObjectBuilderInterface>
			aob( new strus::AnalyzerObjectBuilder( g_errorhnd));
		std::auto_ptr<strus::StorageObjectBuilderInterface>
			sob( new strus::StorageObjectBuilder( g_errorhnd));

		if (traceObjectBuilder_breakpoint.get())
		{
			envelope( aob, traceObjectBuilder_breakpoint.get());
			envelope( sob, traceObjectBuilder_breakpoint.get());
		}
		envelope( aob, traceObjectBuilder_logtext.get());
		envelope( aob, traceObjectBuilder_memory.get());
		envelope( sob, traceObjectBuilder_logtext.get());
		envelope( sob, traceObjectBuilder_memory.get());

		// Build storage and query evaluation test:
		testEvaluateQuery(
			sob.get(), aob.get(), storagecfg, 
			g_analyzerconfig, g_testdocs, g_querystring);
		if (g_errorhnd->hasError())
		{
			throw std::runtime_error(std::string("unhandled error: ") + g_errorhnd->fetchError());
		}

		// Test selective view of output:
		std::ostringstream out;
		executeViewerQueries( out, idmap, viewer.get(), g_testQueries);
		outputstr.append( out.str());

		// Test object creation time:
		unsigned int creatTime = viewer->getObjectCreationTime( 298);
		if (creatTime != 2969)
		{
			throw std::runtime_error( "error in reported creation time of object");
		}
		}//end scope trace processor

		// Concat output of all tests together:
		std::string outputstr1;
		unsigned int ec = strus::readFile( outfile, outputstr1);
		if (ec) throw std::runtime_error( std::string( "error reading output file: ") + ::strerror(ec));
		ec = strus::writeFile( outfile, outputstr1 + outputstr);
		if (ec) throw std::runtime_error( std::string( "error writing output file: ") + ::strerror(ec));

		// Compare output with expected:
		if (!diffFiles( outfile, expfile))
		{
			throw std::runtime_error( "input file and expected output file differ"); 
		}
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "ERROR memory allocation error" << std::endl;
		return -1;
	}
	catch (const std::runtime_error& err)
	{
		if (g_errorhnd && g_errorhnd->hasError())
		{
			std::cerr << "ERROR " << err.what() << ": " << g_errorhnd->fetchError() << std::endl;
		}
		else
		{
			std::cerr << "ERROR " << err.what() << std::endl;
		}
		return -1;
	}
	return 0;
}


