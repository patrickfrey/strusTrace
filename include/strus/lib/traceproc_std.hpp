/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Exported functions of the standard strus trace processor library
/// \file "traceproc_std.hpp"
#ifndef _STRUS_TRACE_PROC_STANDARD_LIB_HPP_INCLUDED
#define _STRUS_TRACE_PROC_STANDARD_LIB_HPP_INCLUDED

/// \brief strus toplevel namespace
namespace strus {

/// \brief Forward declaration
class ErrorBufferInterface;
/// \brief Forward declaration
class TraceProcessorInterface;

/// \brief Create an interface to the trace logger creating a trace in memory that can be queried in the same session (no recovery of previous sessions) with a viewer. 
TraceProcessorInterface* createTraceProcessor_memory( ErrorBufferInterface* errorhnd);

/// \brief Create an interface to the trace logger writing a trace directly to stdout.
TraceProcessorInterface* createTraceProcessor_textfile( ErrorBufferInterface* errorhnd);

/// \brief Create an interface to the trace logger than enables you to set debugger breakpoints on specific events.
TraceProcessorInterface* createTraceProcessor_breakpoint( ErrorBufferInterface* errorhnd);

}//namespace
#endif

