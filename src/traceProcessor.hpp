/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of the trace processor interface for logging and querying traces in memory and readable logging to a textfile or stdout
/// \file traceProcesor.hpp
#ifndef _STRUS_TRACE_PROCESSOR_IMPLEMENTATION_HPP_INCLUDED
#define _STRUS_TRACE_PROCESSOR_IMPLEMENTATION_HPP_INCLUDED
#include "strus/traceProcessorInterface.hpp"
#include <string>

namespace strus
{
/// \brief Forward declaration
class ErrorBufferInterface;
/// \brief Forward declaration
class TraceLoggerInterface;
/// \brief Forward declaration
class TraceViewerInterface;
/// \brief Forward declaration
class TraceIdMapInterface;

/// \brief Implementation of the trace processor interface for logging and querying traces in memory
class TraceProcessor
	:public TraceProcessorInterface
{
public:
	explicit TraceProcessor( ErrorBufferInterface* errorhnd_)
		:m_errorhnd(errorhnd_){}

	virtual TraceLoggerInterface* createLogger( const std::string& config);
	virtual TraceViewerInterface* createViewer( const std::string& config);

private:
	ErrorBufferInterface* m_errorhnd;
};

/// \brief Implementation of the trace processor interface for logging and querying traces in readable to a textfile or stdout
class TraceProcessor_textfile
	:public TraceProcessorInterface
{
public:
	explicit TraceProcessor_textfile( ErrorBufferInterface* errorhnd_)
		:m_errorhnd(errorhnd_){}

	virtual TraceLoggerInterface* createLogger( const std::string& config);
	virtual TraceViewerInterface* createViewer( const std::string& config);

private:
	ErrorBufferInterface* m_errorhnd;
	
};

}//namespace
#endif

