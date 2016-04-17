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
#include "strus/lib/tracelog.hpp"
#include "strus/lib/error.hpp"
#include "strus/base/fileio.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/queryProcessorInterface.hpp"
#include "strus/postingJoinOperatorInterface.hpp"
#include "strus/postingIteratorInterface.hpp"
#include "strus/storageInterface.hpp"
#include "strus/storageClientInterface.hpp"
#include "strus/storageTransactionInterface.hpp"
#include "strus/storageDocumentInterface.hpp"
#include "strus/storageObjectBuilderInterface.hpp"
#include "strus/analyzerObjectBuilderInterface.hpp"
#include "strus/textProcessorInterface.hpp"
#include "strus/documentAnalyzerInterface.hpp"
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
#include "strus/traceIdMapInterface.hpp"
#include <string>
#include <cstdarg>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <memory>

static strus::ErrorBufferInterface* g_errorhnd = 0;
static const char* g_storageconfig = "path=storage; metadata=doclen UINT16";

static strus::StorageClientInterface* createStorage( const strus::StorageObjectBuilderInterface* sob)
{
	const strus::DatabaseInterface* database = sob->getDatabase( g_storageconfig);
	if (!database) throw std::runtime_error( "failed to get database interface");
	if (g_errorhnd->hasError()) throw std::runtime_error( g_errorhnd->fetchError());
	(void) database->destroyDatabase( g_storageconfig);
	(void) g_errorhnd->fetchError();
	if (!database->createDatabase( g_storageconfig)) throw std::runtime_error("failed to create database");
	strus::StorageClientInterface* rt = sob->createStorageClient( g_storageconfig);
	if (!rt) throw std::runtime_error( "failed to get create storage client");
	return rt;
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
		std::string argstrbuf( argstr+1, argend-argstr-2);
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

struct AnalyzerConfig
{
	IndexType indextype;
	const char* type;
	const char* normalizer;
	const char* tokenizer;
	const char* path;
};

static strus::DocumentAnalyzerInterface* createAnalyzer( const strus::AnalyzerObjectBuilderInterface* aob, const AnalyzerConfig* config)
{
	std::auto_ptr<strus::DocumentAnalyzerInterface> analyzer( aob->createDocumentAnalyzer());
	if (!analyzer.get()) throw std::runtime_error( "failed to get create document analyzer");
	const strus::TextProcessorInterface* textproc = aob->getTextProcessor();
	std::string funcname;
	std::vector<std::string> funcarg;
	const char* countfeatname = 0;

	std::size_t ai = 0;
	for (; config[ai].type; ++ai)
	{
		std::vector<strus::NormalizerFunctionInstanceInterface*> normalizers;
		strus::TokenizerFunctionInstanceInterface* tokenizer;

		std::vector<std::string> nar( split( config[ai].normalizer, ':'));
		std::vector<std::string>::const_iterator ni = nar.begin(), ne = nar.end();
		for (; ni != ne; ++ni)
		{
			parseFunction( funcname, funcarg, *ni); 
			const strus::NormalizerFunctionInterface* normalizer = textproc->getNormalizer( funcname);
			if (!normalizer) throw std::runtime_error( std::string("unknonwn normalizer '") + *ni + "'");

			normalizers.push_back( normalizer->createInstance( funcarg, textproc));
			if (!normalizers.back()) throw std::runtime_error( std::string( "failed to create normalizer '") + *ni + "'");
		}
		{
			parseFunction( funcname, funcarg, config[ai].tokenizer); 
			const strus::TokenizerFunctionInterface* tk = textproc->getTokenizer( funcname);
			if (!tk) throw std::runtime_error( std::string("unknown tokenizer '") + funcname + "'");

			tokenizer = tk->createInstance( funcarg, textproc);
			if (!tokenizer) throw std::runtime_error( std::string("failed to create tokenizer '") + funcname + "'");
		}
		switch (config[ai].indextype)
		{
			case SearchIndex:
				if (!countfeatname) countfeatname = config[ai].type;
				analyzer->addSearchIndexFeature(
					config[ai].type, config[ai].path, tokenizer, normalizers);
				break;
			case ForwardIndex:
				analyzer->addForwardIndexFeature(
					config[ai].type, config[ai].path, tokenizer, normalizers);
				break;
			case MetaData:
				analyzer->defineMetaData(
					config[ai].type, config[ai].path, tokenizer, normalizers);
				break;
			case Attribute:
				analyzer->defineAttribute(
					config[ai].type, config[ai].path, tokenizer, normalizers);
				break;
		}
	}
	if (countfeatname)
	{
		funcname = "count";
		funcarg.clear();
		funcarg.push_back( countfeatname);
		const strus::AggregatorFunctionInterface* agf = textproc->getAggregator( funcname);
		if (!agf) throw std::runtime_error( std::string("unknonwn aggregator '") + funcname + "'");
		strus::AggregatorFunctionInstanceInterface* aggregator = agf->createInstance( funcarg);
		if (!aggregator) throw std::runtime_error( std::string("failed to create aggregator '") + funcname + "'");
		analyzer->defineAggregatedMetaData( "doclen", aggregator);
	}
	return analyzer.release();
}

struct TestDocument
{
	const char* docid;
	const char* content;
};

static void insertDocuments(
	const strus::AnalyzerObjectBuilderInterface* aob,
	const strus::StorageObjectBuilderInterface* sob,
	const AnalyzerConfig* anaconfig,
	const TestDocument* testdocs)
{
	std::auto_ptr<strus::StorageClientInterface> storage( createStorage( sob));
	std::auto_ptr<strus::DocumentAnalyzerInterface> analyzer( createAnalyzer( aob, anaconfig));
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
		stodoc->done();
	}
	if (!transaction->commit()) throw std::runtime_error( "storage transaction failed");
	if (g_errorhnd->hasError()) throw std::runtime_error( "uncaught expcetion in transaction");
}

static const AnalyzerConfig g_anaconfig[] =
{
	{SearchIndex,0,0,0,0}
};
static const TestDocument g_testdocs[] =
{
	{0,0}
};

static void testEvaluateQuery( const strus::AnalyzerObjectBuilderInterface* aob, const strus::StorageObjectBuilderInterface* sob)
{
	insertDocuments( aob, sob, g_anaconfig, g_testdocs);
}


int main( int argc, const char* argv[])
{
	unsigned int argi = 1;
	for (; argc > (int)argi; ++argi)
	{
		if (std::strcmp( argv[argi], "-h") == 0)
		{
			std::cerr << "usage: testQueryEval [options]" << std::endl;
			std::cerr << "options:" << std::endl;
			std::cerr << "  -h      :print usage" << std::endl;
		}
		else if (argv[argi][0] == '-')
		{
			std::cerr << "unknown option " << argv[argi] << std::endl;
			return -1;
		}
		else
		{
			std::cerr << "unexpected argument" << std::endl;
			return -1;
		}
	}
	g_errorhnd = strus::createErrorBuffer_standard( stderr, 1);
	if (!g_errorhnd)
	{
		std::cerr << "error allocating error buffer";
		return -1;
	}
	try
	{
		std::auto_ptr<strus::TraceProcessorInterface>
			traceproc( strus::createTraceProcessor_textfile( g_errorhnd));
		std::auto_ptr<strus::TraceObjectBuilderInterface>
			traceObjectBuilder(
				strus::traceCreateObjectBuilder(
					traceproc->createLogger( "stdout"), g_errorhnd));

		std::auto_ptr<strus::AnalyzerObjectBuilderInterface> analyzerObjectBuilder( new strus::AnalyzerObjectBuilder( g_errorhnd));
		std::auto_ptr<strus::StorageObjectBuilderInterface> storageObjectBuilder( new strus::StorageObjectBuilder( g_errorhnd));
		if (!traceproc.get())
		{
			throw std::runtime_error("failed to create trace processor");
		}
		strus::AnalyzerObjectBuilderInterface*
			ao = traceObjectBuilder->createAnalyzerObjectBuilder( analyzerObjectBuilder.get());
		if (ao)
		{
			analyzerObjectBuilder.release();
			analyzerObjectBuilder = std::auto_ptr<strus::AnalyzerObjectBuilderInterface>( ao);
		}
		else
		{
			throw std::runtime_error("failed to analyzer object builder proxy");
		}
		strus::StorageObjectBuilderInterface*
			so = traceObjectBuilder->createStorageObjectBuilder( storageObjectBuilder.get());
		if (so)
		{
			storageObjectBuilder.release();
			storageObjectBuilder = std::auto_ptr<strus::StorageObjectBuilderInterface>( so);
		}
		else
		{
			throw std::runtime_error("failed to storage object builder proxy");
		}

		testEvaluateQuery( analyzerObjectBuilder.get(), storageObjectBuilder.get());
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


