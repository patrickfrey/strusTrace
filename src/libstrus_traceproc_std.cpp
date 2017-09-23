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
#include "traceLogger_dump.hpp"
#include "traceLogger_breakpoint.hpp"
#include "traceLogger_json.hpp"
#include "traceLogger_count.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/base/dll_tags.hpp"
#include "strus/base/configParser.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include <cstring>
#include <utility>
#include <string>

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


DLL_PUBLIC TraceLoggerInterface* strus::createTraceLogger_dump( const std::string& config, ErrorBufferInterface* errorhnd)
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
		return new TraceLogger_dump( filename, errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("failed to create trace logger (dump): %s"), *errorhnd, 0)
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
		throw strus::runtime_error( "%s", _TXT("illegal breakpoint index in configuration string"));
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
	CATCH_ERROR_MAP_RETURN( _TXT("failed to create trace logger (breakpoint): %s"), *errorhnd, 0)
}


static std::pair<std::string,std::string> parseEventDef( const std::string& calldef)
{
	std::pair<std::string,std::string> rt;
	char const* pi = std::strstr( calldef.c_str(), "::");
	char const* pe = pi;
	if (pi)
	{
		pe = pi+2;
	}
	else
	{
		pi = std::strchr( calldef.c_str(), '/');
		if (pi) pe = pi+1;
	}
	if (pi)
	{
		rt.first.append( calldef.c_str(), pi - calldef.c_str());
		rt.second.append( pe);
	}
	else
	{
		rt.first = calldef;
	}
	return rt;
}

DLL_PUBLIC TraceLoggerInterface* strus::createTraceLogger_count( const std::string& config, ErrorBufferInterface* errorhnd)
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
		std::string groupBy;
		std::string groupByClass;
		std::string groupByMethod;
		if (extractStringFromConfigString( groupBy, configstr, "groupby", errorhnd))
		{
			static std::pair<std::string,std::string> ev = parseEventDef( groupBy);
			groupByClass = ev.first;
			groupByMethod = ev.second;
		}
		std::string countEvent;
		std::string countEventClass;
		std::string countEventMethod;
		if (extractStringFromConfigString( countEvent, configstr, "count", errorhnd))
		{
			static std::pair<std::string,std::string> ev = parseEventDef( countEvent);
			countEventClass = ev.first;
			countEventMethod = ev.second;
		}
		return new TraceLogger_count( filename, groupByClass, groupByMethod, countEventClass, countEventMethod, errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("failed to create trace logger (count): %s"), *errorhnd, 0)
}


