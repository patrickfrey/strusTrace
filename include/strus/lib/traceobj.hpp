/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Exported functions of the strus trace object builder library
/// \file "traceobj.hpp"
#ifndef _STRUS_TRACE_OBJECT_BUILDER_LIB_HPP_INCLUDED
#define _STRUS_TRACE_OBJECT_BUILDER_LIB_HPP_INCLUDED
#include <string>

/// \brief strus toplevel namespace
namespace strus {

/// \brief Forward declaration
class ErrorBufferInterface;
/// \brief Forward declaration
class TraceProcessorInterface;
/// \brief Forward declaration
class TraceObjectBuilderInterface;

/// \brief Create a proxy object to wrap storage and analyzer object builder and all descendant objects to log all methods called besides calling them
/// \param[in] traceproc trace processor interface to use (ownership passed to returned object)
/// \param[in] loggerConfig trace logger configuration
/// \param[in] errorhnd error buffer for error messages and exceptions
TraceObjectBuilderInterface*
	traceCreateObjectBuilder(
		TraceProcessorInterface* traceproc,
		const std::string& loggerConfig,
		ErrorBufferInterface* errorhnd);

}//namespace
#endif

