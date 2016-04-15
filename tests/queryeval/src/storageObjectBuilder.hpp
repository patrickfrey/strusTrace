/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _STRUS_TRACE_TEST_STORAGE_OBJECT_BUILDER_HPP_INCLUDED
#define _STRUS_TRACE_TEST_STORAGE_OBJECT_BUILDER_HPP_INCLUDED
#include "strus/lib/database_leveldb.hpp"
#include "strus/lib/storage.hpp"
#include "strus/lib/queryproc.hpp"
#include "strus/lib/queryeval.hpp"
#include "strus/databaseInterface.hpp"
#include "strus/databaseClientInterface.hpp"
#include "strus/storageInterface.hpp"
#include "strus/storageClientInterface.hpp"
#include "strus/storageTransactionInterface.hpp"
#include "strus/storageDocumentInterface.hpp"
#include "strus/storageObjectBuilderInterface.hpp"
#include "strus/queryProcessorInterface.hpp"
#include "strus/reference.hpp"
#include "strus/errorBufferInterface.hpp"
#include <string>
#include <stdexcept>
#include <memory>

/// \brief strus toplevel namespace
namespace strus {

class StorageObjectBuilder
	:public strus::StorageObjectBuilderInterface
{
public:
	explicit StorageObjectBuilder( ErrorBufferInterface* errorhnd_)
		:m_errorhnd(errorhnd_)
	{
		m_config = "path=storage";
		m_dbi.reset( strus::createDatabase_leveldb( m_errorhnd));
		if (!m_dbi.get())
		{
			throw std::runtime_error( m_errorhnd->fetchError());
		}
		m_sti.reset( strus::createStorage( m_errorhnd));
		if (!m_sti.get())
		{
			throw std::runtime_error( std::string("failed to create storage: ") + m_errorhnd->fetchError());
		}
		try
		{
			m_dbi->destroyDatabase( m_config);
		}
		catch(...){}
	
		if (!m_dbi->createDatabase( m_config))
		{
			throw std::runtime_error( std::string("failed to create database: ") + m_errorhnd->fetchError());
		}
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
			m_errorhnd->explain( "failed to create database client: %s");
			return 0;
		}
		strus::StorageClientInterface* rt = m_sti->createClient( cfg, dci.get());
		if (!rt)
		{
			m_errorhnd->explain( "failed to create database client: %s");
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
		return strus::createQueryEval( m_errorhnd);
	}

private:
	ErrorBufferInterface* m_errorhnd;
	std::string m_config;
	strus::Reference<strus::DatabaseInterface> m_dbi;
	strus::Reference<strus::StorageInterface> m_sti;
	strus::Reference<strus::QueryProcessorInterface> m_qpi;
};

}//namespace
#endif

