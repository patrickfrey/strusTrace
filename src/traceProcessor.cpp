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
#include "traceLogger.hpp"
#include "traceLogger_textfile.hpp"
#include "traceViewer.hpp"
#include <string>

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


