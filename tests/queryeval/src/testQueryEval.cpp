/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "strus/lib/analyzer_objbuild.hpp"
#include "strus/lib/storage_objbuild.hpp"
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
#include "strus/queryAnalyzerContextInterface.hpp"
#include "strus/normalizerFunctionInterface.hpp"
#include "strus/normalizerFunctionInstanceInterface.hpp"
#include "strus/tokenizerFunctionInterface.hpp"
#include "strus/tokenizerFunctionInstanceInterface.hpp"
#include "strus/aggregatorFunctionInterface.hpp"
#include "strus/aggregatorFunctionInstanceInterface.hpp"
#include "strus/valueIteratorInterface.hpp"
#include "strus/traceObjectBuilderInterface.hpp"
#include "strus/traceLoggerInterface.hpp"
#include "strus/traceElement.hpp"
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
	std::string configstr( storageconfig);
	std::string dbname;
	(void)strus::extractStringFromConfigString( dbname, configstr, "database", g_errorhnd);
	if (g_errorhnd->hasError())
	{
		throw std::runtime_error( "cannot evaluate database");
	}
	const strus::DatabaseInterface* dbi = sob->getDatabase( dbname);
	if (!dbi) throw std::runtime_error( "failed to get database interface");
	if (g_errorhnd->hasError()) throw std::runtime_error( g_errorhnd->fetchError());
	(void) dbi->destroyDatabase( configstr);
	(void) g_errorhnd->fetchError();
	const strus::StorageInterface* sti = sob->getStorage();
	if (!sti) throw std::runtime_error( "failed to get storage interface");
	if (!sti->createStorage( configstr, dbi)) throw std::runtime_error( "failed to create storage");
	std::auto_ptr<strus::StorageClientInterface> storage( sti->createClient( configstr, dbi));
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
	const strus::TextProcessorInterface* textproc = aob->getTextProcessor();
	const strus::SegmenterInterface* segmenter = textproc->getSegmenterByName("");
	if (!segmenter) throw std::runtime_error( "failed to get document segmenter");
	std::auto_ptr<strus::DocumentAnalyzerInterface> analyzer( aob->createDocumentAnalyzer( segmenter));
	if (!analyzer.get()) throw std::runtime_error( "failed to create document analyzer");
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
					config[ai].type, config[ai].path, anafundef.tokenizer, anafundef.normalizers, strus::analyzer::FeatureOptions());
				break;
			case ForwardIndex:
				analyzer->addForwardIndexFeature(
					config[ai].type, config[ai].path, anafundef.tokenizer, anafundef.normalizers, strus::analyzer::FeatureOptions());
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
	analyzer->addSearchIndexElement( config[ai].type, "querystring", anafundef.tokenizer, anafundef.normalizers);
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
	strus::analyzer::DocumentClass dclass( "xml", "UTF-8");

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

static strus::analyzer::Query analyzeQuery( const strus::AnalyzerObjectBuilderInterface* aob, const DocumentAnalyzerConfig* anaconfig, const char* querystr)
{
	std::auto_ptr<strus::QueryAnalyzerInterface> qai( createQueryAnalyzer( aob, anaconfig));
	if (!qai.get()) throw std::runtime_error("failed to create query analyzer");
	std::auto_ptr<strus::QueryAnalyzerContextInterface> qac( qai->createContext());
	if (!qac.get()) throw std::runtime_error("failed to create query analyzer context");
	qac->putField( 1, "querystring", querystr);
	return qac->analyze();
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
	std::auto_ptr<strus::QueryInterface> query( qeval->createQuery( storage));

	// The query analysis is only rudimentary and does not make use of latest query analysis capabilities
	// to deal with query structures (trees):
	strus::analyzer::Query querystruct = analyzeQuery( aob, anaconfig, querystr);
	if (querystruct.instructions().empty()) throw std::runtime_error("query is empty");

	std::vector<unsigned int> selfeat;
	std::vector<strus::analyzer::Query::Instruction>::const_iterator
		ei = querystruct.instructions().begin(), ee = querystruct.instructions().end();
	for (; ei != ee; ++ei)
	{
		switch (ei->opCode())
		{
			case strus::analyzer::Query::Instruction::Term:
			{
				const strus::analyzer::Term& term = querystruct.term( ei->idx());
				query->pushTerm( term.type(), term.value(), term.len());
				query->defineFeature( "docfeat");
				selfeat.push_back( ei->idx());
				break;
			}
			case strus::analyzer::Query::Instruction::MetaData:
				throw std::runtime_error("no metadata support in this test yet");

			case strus::analyzer::Query::Instruction::Operator:
				throw std::runtime_error("structured query support not complete yet in this test");
		}
	}
	std::vector<unsigned int>::const_iterator si = selfeat.begin(), se = selfeat.end();
	for (; si != se; ++si)
	{
		const strus::analyzer::Term& term = querystruct.term( *si);
		query->pushTerm( term.type(), term.value(), term.len());
	}
	const strus::PostingJoinOperatorInterface* contains = qproc->getPostingJoinOperator("contains");
	query->pushExpression( contains, selfeat.size(), 0, 1/*cardinality*/);
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

	std::auto_ptr<strus::StorageClientInterface>
		storage( strus::createStorageClient( sob, g_errorhnd, storageconfig));
	
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
		strus::TraceObjectBuilderInterface* tob)
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
		throw std::runtime_error("failed to create storage object builder proxy");
	}
}

static void envelope(
		std::auto_ptr<strus::AnalyzerObjectBuilderInterface>& aob,
		strus::TraceObjectBuilderInterface* tob)
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
		throw std::runtime_error("failed to create analyzer object builder proxy");
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

	char out_dump[ 1024];
	snprintf( out_dump, sizeof(out_dump), "%s.txt", argv[2]);
	char outcfg_dump[ 1024];
	snprintf( outcfg_dump, sizeof(outcfg_dump), "file=%s.txt", argv[2]);

	char out_json[ 1024];
	snprintf( out_json, sizeof(out_json), "%s.json", argv[2]);
	char outcfg_json[ 1024];
	snprintf( outcfg_json, sizeof(outcfg_json), "file=%s.json", argv[2]);

	char out_count[ 1024];
	snprintf( out_count, sizeof(out_count), "%s.cnt", argv[2]);
	char outcfg_count[ 1024];
	snprintf( outcfg_count, sizeof(outcfg_count), "groupby=PostingIterator;count=DatabaseCursor/seekUpperBound;file=%s.cnt", argv[2]);

	char res_dump[ 1024];
	snprintf( res_dump, sizeof(res_dump), "%s.txt", argv[3]);
	char res_json[ 1024];
	snprintf( res_json, sizeof(res_json), "%s.json", argv[3]);
	char res_count[ 1024];
	snprintf( res_count, sizeof(res_count), "%s.cnt", argv[3]);

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

		std::auto_ptr<strus::TraceObjectBuilderInterface> traceObjectBuilder_breakpoint;

		// If breakpoints configured, create trace object builder 'breakpoints':
		if (breakpoints)
		{
			strus::TraceLoggerInterface*
				logger_breakpoint = strus::createTraceLogger_breakpoint( breakpoints, g_errorhnd);
			if (!logger_breakpoint)
			{
				throw std::runtime_error("failed to create trace logger (breakpoint)");
			}
			traceObjectBuilder_breakpoint =
				std::auto_ptr<strus::TraceObjectBuilderInterface>(
					strus::traceCreateObjectBuilder( logger_breakpoint, g_errorhnd));
			if (!traceObjectBuilder_breakpoint.get())
			{
				delete logger_breakpoint;
				throw std::runtime_error("failed to create trace object builder (breakpoint)");
			}
		}

		// Create trace object builder 'dump':
		strus::TraceLoggerInterface* 
			logger_dump = strus::createTraceLogger_dump( outcfg_dump, g_errorhnd);
		if (!logger_dump)
		{
			throw std::runtime_error("failed to create trace logger (dump)");
		}
		std::auto_ptr<strus::TraceObjectBuilderInterface>
			traceObjectBuilder_dump(
				strus::traceCreateObjectBuilder( logger_dump, g_errorhnd));
		if (!traceObjectBuilder_dump.get())
		{
			delete logger_dump;
			throw std::runtime_error("failed to create trace object builder (dump)");
		}

		// Create trace processor 'json':
		strus::TraceLoggerInterface*
			logger_json = strus::createTraceLogger_json( outcfg_json, g_errorhnd);
		if (!logger_json)
		{
			throw std::runtime_error("failed to create trace logger (json)");
		}
		std::auto_ptr<strus::TraceObjectBuilderInterface>
			traceObjectBuilder_json(
				strus::traceCreateObjectBuilder(
					logger_json, g_errorhnd));
		if (!traceObjectBuilder_json.get())
		{
			delete logger_json;
			throw std::runtime_error("failed to create trace object builder (json)");
		}

		strus::TraceLoggerInterface* 
			logger_count = strus::createTraceLogger_count( outcfg_count, g_errorhnd);
		if (!logger_count)
		{
			throw std::runtime_error("failed to create trace logger (count)");
		}
		std::auto_ptr<strus::TraceObjectBuilderInterface>
			traceObjectBuilder_count(
				strus::traceCreateObjectBuilder( logger_count, g_errorhnd));
		if (!traceObjectBuilder_count.get())
		{
			delete logger_count;
			throw std::runtime_error("failed to create trace object builder (count)");
		}

		std::auto_ptr<strus::AnalyzerObjectBuilderInterface>
			aob( strus::createAnalyzerObjectBuilder_default( g_errorhnd));
		std::auto_ptr<strus::StorageObjectBuilderInterface>
			sob( strus::createStorageObjectBuilder_default( g_errorhnd));

		if (traceObjectBuilder_breakpoint.get())
		{
			envelope( aob, traceObjectBuilder_breakpoint.get());
			envelope( sob, traceObjectBuilder_breakpoint.get());
		}
		envelope( aob, traceObjectBuilder_dump.get());
		envelope( aob, traceObjectBuilder_json.get());
		envelope( aob, traceObjectBuilder_count.get());
		envelope( sob, traceObjectBuilder_dump.get());
		envelope( sob, traceObjectBuilder_json.get());
		envelope( sob, traceObjectBuilder_count.get());

		// Build storage and query evaluation test:
		testEvaluateQuery(
			sob.get(), aob.get(), storagecfg, 
			g_analyzerconfig, g_testdocs, g_querystring);
		if (g_errorhnd->hasError())
		{
			throw std::runtime_error(std::string("unhandled error: ") + g_errorhnd->fetchError());
		}
		}//end scope trace processor

		// Compare output with expected:
		if (!diffFiles( out_dump, res_dump))
		{
			throw std::runtime_error( "input file and expected output file (dump) differ"); 
		}
		if (!diffFiles( out_json, res_json))
		{
			throw std::runtime_error( "input file and expected output file (json) differ"); 
		}
		if (!diffFiles( out_count, res_count))
		{
			throw std::runtime_error( "input file and expected output file (count) differ"); 
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


