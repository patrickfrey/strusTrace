/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Exported functions of the strus tracelog library
/// \file "scalarfunc.hpp"
#ifndef _STRUS_TRACE_LOG_LIB_HPP_INCLUDED
#define _STRUS_TRACE_LOG_LIB_HPP_INCLUDED

/// \brief strus toplevel namespace
namespace strus {

/// \brief Forward declaration
class ErrorBufferInterface;
/// \brief Forward declaration
class TraceProcessorInterface;
/// \brief Forward declaration
class TraceLoggerInterface;
/// \brief Forward declaration
class TraceIdMapInterface;
/// \brief Forward declaration
class TraceObjectBuilderInterface;

/// \brief Create a map of identifiers used in call trace logs
/// \return the map
TraceIdMapInterface* createTraceIdMap( ErrorBufferInterface* errorhnd);

/// \brief Create an interface to the trace logger creating a trace in memory that can be queried in the same session (no recovery of previous sessions) with a viewer. 
TraceProcessorInterface* createTraceProcessor_memory( ErrorBufferInterface* errorhnd);

/// \brief Create an interface to the trace logger writing a trace directly to stdout.
TraceProcessorInterface* createTraceProcessor_textfile( ErrorBufferInterface* errorhnd);

/// \brief Create an interface to the trace logger than enables you to set debugger breakpoints on specific events.
TraceProcessorInterface* createTraceProcessor_breakpoint( ErrorBufferInterface* errorhnd);

/// \brief Create a proxy object to wrap storage and analyzer object builder and all descendant objects to log all methods called besides calling them
/// \param[in] tracelog trace logger interface to use
/// \param[in] errorhnd error buffer for error messages and exceptions
TraceObjectBuilderInterface*
	traceCreateObjectBuilder(
		TraceLoggerInterface* tracelog,
		ErrorBufferInterface* errorhnd);

}//namespace
#endif

