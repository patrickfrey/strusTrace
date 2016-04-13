/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "strus/reference.hpp"
#include "strus/databaseInterface.hpp"
#include "strus/databaseClientInterface.hpp"
#include "strus/lib/tracelog.hpp"
#include "strus/lib/error.hpp"
#include "strus/lib/database_leveldb.hpp"
#include "strus/lib/storage.hpp"
#include "strus/lib/queryproc.hpp"
#include "strus/lib/queryeval.hpp"
#include "strus/lib/textproc.hpp"
#include "strus/lib/segmenter_textwolf.hpp"
#include "strus/lib/analyzer.hpp"
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

class StorageObjectBuilder
	:public strus::StorageObjectBuilderInterface
{
public:
	StorageObjectBuilder()
	{
		m_config = "path=storage";
		m_dbi.reset( strus::createDatabase_leveldb( g_errorhnd));
		if (!m_dbi.get())
		{
			throw std::runtime_error( g_errorhnd->fetchError());
		}
		m_sti.reset( strus::createStorage( g_errorhnd));
		if (!m_sti.get())
		{
			throw std::runtime_error( g_errorhnd->fetchError());
		}
		try
		{
			m_dbi->destroyDatabase( m_config);
		}
		catch(...){}
	
		m_dbi->createDatabase( m_config);
	}

	virtual ~StorageObjectBuilder()
	{
		m_dbi->destroyDatabase( m_config);
	}

	virtual const strus::StorageInterface* getStorage() const
	{
		return m_sti.get();
	}

	virtual const strus::DatabaseInterface* getDatabase( const std::string& ) const
	{
		return m_dbi.get();
	}

	virtual const strus::QueryProcessorInterface* getQueryProcessor() const
	{
		return m_qpi.get();
	}

	virtual const strus::StatisticsProcessorInterface* getStatisticsProcessor() const
	{
		return 0;
	}

	virtual strus::StorageClientInterface* createStorageClient( const std::string& config) const
	{
		std::string cfg = config.empty()?m_config:config;
		std::auto_ptr<strus::DatabaseClientInterface> dci( m_dbi->createClient( cfg));
		if (!dci.get())
		{
			g_errorhnd->explain( "failed to create database client: %s");
			return 0;
		}
		strus::StorageClientInterface* rt = m_sti->createClient( cfg, dci.get());
		if (!rt)
		{
			g_errorhnd->explain( "failed to create database client: %s");
			return 0;
		}
		dci.release();
		return rt;
	}

	virtual strus::StorageAlterMetaDataTableInterface* createAlterMetaDataTable( const std::string&) const
	{
		throw std::runtime_error("method 'createAlterMetaDataTable' not implemented");
	}

	virtual strus::QueryEvalInterface* createQueryEval() const
	{
		return strus::createQueryEval( g_errorhnd);
	}

private:
	std::string m_config;
	strus::Reference<strus::DatabaseInterface> m_dbi;
	strus::Reference<strus::StorageInterface> m_sti;
	strus::Reference<strus::QueryProcessorInterface> m_qpi;
};

class AnalyzerObjectBuilder
	:public strus::AnalyzerObjectBuilderInterface
{
public:
	AnalyzerObjectBuilder()
		:m_tpi(strus::createTextProcessor( g_errorhnd))
	{
		if (!m_tpi.get()) throw std::runtime_error( std::string("failed to create text processor: ") + g_errorhnd->fetchError());
	}

	virtual ~AnalyzerObjectBuilder(){}

	virtual const strus::TextProcessorInterface* getTextProcessor() const
	{
		return m_tpi.get();
	}

	virtual strus::SegmenterInterface* createSegmenter( const std::string& segmenterName=std::string()) const
	{
		strus::SegmenterInterface* rt = strus::createSegmenter_textwolf( g_errorhnd);
		if (!rt)
		{
			g_errorhnd->explain( "failed to create document segmenter: %s");
			return 0;
		}
		return rt;
	}

	virtual strus::DocumentAnalyzerInterface* createDocumentAnalyzer( const std::string& segmenterName=std::string()) const
	{
		std::auto_ptr<strus::SegmenterInterface> segmenter( strus::createSegmenter_textwolf( g_errorhnd));
		if (!segmenter.get()) 
		{
			g_errorhnd->explain( "failed to create segmenter: %s");
			return 0;
		}
		strus::DocumentAnalyzerInterface* rt = strus::createDocumentAnalyzer( segmenter.get(), g_errorhnd);
		if (!rt)
		{
			g_errorhnd->explain( "failed to create document analyzer: %s");
			return 0;
		}
		segmenter.release();
		return rt;
	}

	virtual strus::QueryAnalyzerInterface* createQueryAnalyzer() const
	{
		strus::QueryAnalyzerInterface* rt = strus::createQueryAnalyzer( g_errorhnd);
		if (!rt) g_errorhnd->explain( "failed to create query analyzer: %s");
		return rt;
	}

private:
	strus::Reference<strus::TextProcessorInterface> m_tpi;
};


int main( int argc, const char* argv[])
{
	unsigned int argi = 1;
	for (; argc > (int)argi; ++argi)
	{
		if (std::strcmp( argv[argi], "-h") == 0)
		{
			std::cerr << "usage: testStorageOp [options]" << std::endl;
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
		std::auto_ptr<strus::AnalyzerObjectBuilderInterface> analyzerObjectBuilder( new AnalyzerObjectBuilder());
		std::auto_ptr<strus::StorageObjectBuilderInterface> storageObjectBuilder( new StorageObjectBuilder());
		std::auto_ptr<strus::TraceProcessorInterface> traceproc( strus::createTraceProcessor_textfile( g_errorhnd));

		std::auto_ptr<strus::TraceObjectBuilderInterface> traceObjectBuilder( );
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "ERROR memory allocation error" << std::endl;
		return -1;
	}
	catch (const std::runtime_error& err)
	{
		std::cerr << "ERROR " << err.what() << std::endl;
		return -1;
	}
	return 0;
}


