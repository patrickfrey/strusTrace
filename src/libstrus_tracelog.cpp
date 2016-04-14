/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Exported functions of the strus tracelog library
/// \file libstrus_tracelog.cpp
#include "strus/lib/tracelog.hpp"
#include "traceProcessor.hpp"
#include "traceIdMap.hpp"
#include "traceObjectBuilder.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/analyzerObjectBuilderInterface.hpp"
#include "strus/storageObjectBuilderInterface.hpp"
#include "strus/base/dll_tags.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"

using namespace strus;

/// \brief Get the map of identifiers used in call trace logs
/// \return the map
DLL_PUBLIC TraceIdMapInterface* strus::createTraceIdMap( ErrorBufferInterface* errorhnd)
{
	try
	{
		static bool intl_initialized = false;
		if (!intl_initialized)
		{
			strus::initMessageTextDomain();
			intl_initialized = true;
		}
		return new TraceIdMap( errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("error creating trace id map: %s"), *errorhnd, 0);
}

DLL_PUBLIC TraceProcessorInterface* strus::createTraceProcessor_memory( ErrorBufferInterface* errorhnd)
{
	try
	{
		static bool intl_initialized = false;
		if (!intl_initialized)
		{
			strus::initMessageTextDomain();
			intl_initialized = true;
		}
		return new TraceProcessor( errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("error creating trace processor (memory): %s"), *errorhnd, 0);
}


DLL_PUBLIC TraceProcessorInterface* strus::createTraceProcessor_textfile( ErrorBufferInterface* errorhnd)
{
	try
	{
		static bool intl_initialized = false;
		if (!intl_initialized)
		{
			strus::initMessageTextDomain();
			intl_initialized = true;
		}
		return new TraceProcessor_textfile( errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("error creating trace processor (textfile): %s"), *errorhnd, 0);
}

DLL_PUBLIC TraceObjectBuilderInterface*
	strus::traceCreateObjectBuilder(
		TraceLoggerInterface* tracelog,
		ErrorBufferInterface* errorhnd)
{
	try
	{
		static bool intl_initialized = false;
		if (!intl_initialized)
		{
			strus::initMessageTextDomain();
			intl_initialized = true;
		}
		return new TraceObjectBuilder( tracelog, errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("error creating trace object builder: %s"), *errorhnd, 0);
}

