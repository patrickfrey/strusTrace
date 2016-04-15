/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "analyzerObjectBuilder.hpp"
#include "storageObjectBuilder.hpp"
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
		std::auto_ptr<strus::AnalyzerObjectBuilderInterface> analyzerObjectBuilder( new strus::AnalyzerObjectBuilder( g_errorhnd));
		std::auto_ptr<strus::StorageObjectBuilderInterface> storageObjectBuilder( new strus::StorageObjectBuilder( g_errorhnd));
		std::auto_ptr<strus::TraceProcessorInterface> traceproc( strus::createTraceProcessor_textfile( g_errorhnd));
		if (!traceproc.get())
		{
			throw std::runtime_error("failed to create trace processor");
		}
		std::auto_ptr<strus::TraceObjectBuilderInterface>
			traceObjectBuilder(
				strus::traceCreateObjectBuilder(
					traceproc->createLogger( "stdout"), g_errorhnd));
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


