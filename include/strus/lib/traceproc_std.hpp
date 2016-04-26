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
#include <string>

/// \brief strus toplevel namespace
namespace strus {

/// \brief Forward declaration
class ErrorBufferInterface;
/// \brief Forward declaration
class TraceLoggerInterface;

/// \brief Create an interface to the trace logger creating a trace in memory
/// \param[in] config configuration string of the logger
/// \return the logger interface
TraceLoggerInterface* createTraceLogger_json( const std::string& config, ErrorBufferInterface* errorhnd);

/// \brief Create an interface to the trace logger writing a trace directly to stdout
/// \param[in] config configuration string of the logger
/// \return the logger interface
TraceLoggerInterface* createTraceLogger_textfile( const std::string& config, ErrorBufferInterface* errorhnd);

/// \brief Create an interface to the trace logger than enables you to set debugger breakpoints on specific method calls
/// \param[in] config configuration string of the logger
/// \return the logger interface
TraceLoggerInterface* createTraceLogger_breakpoint( const std::string& config, ErrorBufferInterface* errorhnd);

}//namespace
#endif

