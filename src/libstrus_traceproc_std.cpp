/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Exported functions of the strus standard trace processor library
/// \file libstrus_traceproc_std.cpp
#include "strus/lib/traceproc_std.hpp"
#include "traceLogger_textfile.hpp"
#include "traceLogger_breakpoint.hpp"
#include "traceLogger_json.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/base/dll_tags.hpp"
#include "strus/base/configParser.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"

using namespace strus;
static bool g_intl_initialized = false;

DLL_PUBLIC TraceLoggerInterface* strus::createTraceLogger_json( const std::string& config, ErrorBufferInterface* errorhnd)
{
	try
	{
		if (!g_intl_initialized)
		{
			strus::initMessageTextDomain();
			g_intl_initialized = true;
		}
		std::string configstr( config);
		std::string filename;
		if (!extractStringFromConfigString( filename, configstr, "file", errorhnd))
		{
			throw strus::runtime_error( _TXT("configuration variable '%s' undefined"), "file");
		}
		return new TraceLogger_json( filename, errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("error creating trace logger (json): %s"), *errorhnd, 0);
}


DLL_PUBLIC TraceLoggerInterface* strus::createTraceLogger_textfile( const std::string& config, ErrorBufferInterface* errorhnd)
{
	try
	{
		if (!g_intl_initialized)
		{
			strus::initMessageTextDomain();
			g_intl_initialized = true;
		}
		std::string configstr( config);
		std::string filename;
		if (!extractStringFromConfigString( filename, configstr, "file", errorhnd))
		{
			throw strus::runtime_error( _TXT("configuration variable '%s' undefined"), "file");
		}
		return new TraceLogger_textfile( filename, errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("failed to create trace logger (textfile)"), *errorhnd, 0)
}


static TraceTimeCounter parseTimeCounter( char const* si, const char* se)
{
	TraceTimeCounter rt = 0;
	for (; si != se && *si >= '0' && *si <= '9'; ++si)
	{
		rt = rt * 10 + (*si - '0');
	}
	if (si != se || rt == 0)
	{
		throw strus::runtime_error( _TXT("illegal breakpoint index in configuration string"));
	}
	return rt;
}

DLL_PUBLIC TraceLoggerInterface* strus::createTraceLogger_breakpoint( const std::string& config, ErrorBufferInterface* errorhnd)
{
	try
	{
		if (!g_intl_initialized)
		{
			strus::initMessageTextDomain();
			g_intl_initialized = true;
		}
		std::vector<TraceTimeCounter> breakpoints;
		std::string valstr;
		std::string configstr( config);
		if (extractStringFromConfigString( valstr, configstr, "call", errorhnd))
		{
			char const* si = valstr.c_str();
			char const* se = std::strchr( si, ',');
			while (se)
			{
				breakpoints.push_back( parseTimeCounter( si, se));
				se = std::strchr( si = se+1, ',');
			}
			breakpoints.push_back( parseTimeCounter( si, std::strchr( si, '\0')));
		}
		return new TraceLogger_breakpoint( breakpoints, errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("failed to create trace logger (breakpoint)"), *errorhnd, 0)
}


