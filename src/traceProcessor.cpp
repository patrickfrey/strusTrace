/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of the trace processor interface for logging and querying traces in memory and readable logging to stdout
/// \file traceProcesor.cpp
#include "traceProcessor.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/base/configParser.hpp"
#include "traceLogger.hpp"
#include "traceLogger_textfile.hpp"
#include "traceLogger_breakpoint.hpp"
#include "traceViewer.hpp"
#include <string>
#include <cstring>

using namespace strus;

TraceLoggerInterface* TraceProcessor::createLogger( const std::string& /*config (not needed)*/)
{
	try
	{
		return new TraceLogger( m_errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( "failed to create trace logger (memory)", *m_errorhnd, 0)
}

TraceViewerInterface* TraceProcessor::createViewer( const std::string& /*config (not needed)*/)
{
	m_errorhnd->report(_TXT("not implemented (in memory trace logger cannot be created from a configuration because nothing is persistently stored)"));
	return 0;
}

TraceLoggerInterface* TraceProcessor_textfile::createLogger( const std::string& config)
{
	try
	{
		return new TraceLogger_textfile( m_errorhnd, config);
	}
	CATCH_ERROR_MAP_RETURN( "failed to create trace logger (textfile)", *m_errorhnd, 0)
}

TraceViewerInterface* TraceProcessor_textfile::createViewer( const std::string& /*config (not needed)*/)
{
	m_errorhnd->report(_TXT("not implemented (stdout trace logger cannot be created from a configuration because nothing is persistently stored)"));
	return 0;
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
		throw strus::runtime_error( "illegal breakpoint index in configuration string");
	}
	return rt;
}

TraceLoggerInterface* TraceProcessor_breakpoint::createLogger( const std::string& config_)
{
	try
	{
		std::vector<TraceTimeCounter> breakpoints;
		std::string valstr;
		std::string config = config_;
		if (extractStringFromConfigString( valstr, config, "call", m_errorhnd))
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
		return new TraceLogger_breakpoint( m_errorhnd, breakpoints);
	}
	CATCH_ERROR_MAP_RETURN( "failed to create trace logger (breakpoint)", *m_errorhnd, 0)
}

TraceViewerInterface* TraceProcessor_breakpoint::createViewer( const std::string& config)
{
	m_errorhnd->report(_TXT("not implemented (viewer on break points in a tracelog)"));
	return 0;
}

