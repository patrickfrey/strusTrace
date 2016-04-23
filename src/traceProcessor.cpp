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
#include "traceIdMap.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/base/configParser.hpp"
#include "traceViewer_memory.hpp"
#include "traceLogger_memory.hpp"
#include "traceLogger_textfile.hpp"
#include "traceLogger_breakpoint.hpp"
#include <string>
#include <cstring>

using namespace strus;

TraceLoggerInterface* TraceProcessor_memory::createLogger( const std::string& /*config (not needed)*/) const
{
	try
	{
		return new TraceLogger_memory( m_errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("failed to create trace logger (memory)"), *m_errorhnd, 0)
}

TraceViewerInterface* TraceProcessor_memory::createViewer( const std::string& /*config (not needed)*/) const
{
	m_errorhnd->report(_TXT("not implemented (in memory trace logger cannot be created from a configuration because nothing is persistently stored)"));
	return 0;
}

const TraceIdMapInterface* TraceProcessor_memory::getIdMap() const
{
	return &m_idmap;
}

TraceLoggerInterface* TraceProcessor_textfile::createLogger( const std::string& config_) const
{
	try
	{
		std::string filename;
		std::string config = config_;
		if (!extractStringFromConfigString( filename, config, "file", m_errorhnd))
		{
			throw strus::runtime_error( _TXT("configuration variable '%s' undefined"), "file");
		}
		return new TraceLogger_textfile( filename, &m_idmap, m_errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("failed to create trace logger (textfile)"), *m_errorhnd, 0)
}

TraceViewerInterface* TraceProcessor_textfile::createViewer( const std::string& /*config (not needed)*/) const
{
	m_errorhnd->report(_TXT("not implemented (stdout trace logger cannot be created from a configuration because nothing is persistently stored)"));
	return 0;
}

const TraceIdMapInterface* TraceProcessor_textfile::getIdMap() const
{
	return &m_idmap;
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

TraceLoggerInterface* TraceProcessor_breakpoint::createLogger( const std::string& config_) const
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
		return new TraceLogger_breakpoint( breakpoints, m_errorhnd);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("failed to create trace logger (breakpoint)"), *m_errorhnd, 0)
}

TraceViewerInterface* TraceProcessor_breakpoint::createViewer( const std::string& config) const
{
	m_errorhnd->report(_TXT("not implemented (viewer on break points in a tracelog)"));
	return 0;
}

const TraceIdMapInterface* TraceProcessor_breakpoint::getIdMap() const
{
	return &m_idmap;
}

