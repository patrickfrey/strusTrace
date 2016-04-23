/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Exported functions of the strus trace object builder library
/// \file libstrus_traceobj.cpp
#include "strus/lib/traceobj.hpp"
#include "traceObjectBuilder.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/base/dll_tags.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"

using namespace strus;
static bool g_intl_initialized = false;

DLL_PUBLIC TraceObjectBuilderInterface*
	strus::traceCreateObjectBuilder(
		TraceProcessorInterface* traceproc,
		const std::string& loggerConfig,
		ErrorBufferInterface* errorhnd)
{
	try
	{
		if (!g_intl_initialized)
		{
			strus::initMessageTextDomain();
			g_intl_initialized = true;
		}
		return new TraceObjectBuilder( traceproc, loggerConfig, errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("error creating trace object builder: %s"), *errorhnd, 0);
}

