/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Toplevel object for logging and querying call traces
/// \file traceObjectBuilder.hpp
#ifndef _STRUS_TRACE_OBJECT_BUILDER_IMPLEMENTATION_HPP_INCLUDED
#define _STRUS_TRACE_OBJECT_BUILDER_IMPLEMENTATION_HPP_INCLUDED
#include "strus/traceObjectBuilderInterface.hpp"
#include "strus/reference.hpp"
#include "traceGlobalContext.hpp"

namespace strus
{
/// \brief Forward declaration
class ErrorBufferInterface;
/// \brief Forward declaration
class TraceLoggerInterface;

/// \brief Standard implementation of the interface creating proxies for Strus objects that log methods called besides calling them
class TraceObjectBuilder
	:public TraceObjectBuilderInterface
{
public:
	/// \brief Constructor
	/// \param[in] tracelog_ trace logger interface to use (ownership passed to this)
	/// \param[in] errorhnd_ error buffer for error messages and exceptions
	TraceObjectBuilder(
			TraceLoggerInterface* traceproc_,
			ErrorBufferInterface* errorhnd_);

	virtual ~TraceObjectBuilder(){}

	virtual AnalyzerObjectBuilderInterface*
		createAnalyzerObjectBuilder(
			AnalyzerObjectBuilderInterface* builder);
	
	virtual StorageObjectBuilderInterface*
		createStorageObjectBuilder(
			StorageObjectBuilderInterface* builder);

private:
	ErrorBufferInterface* m_errorhnd;
	Reference<TraceLoggerInterface> m_logger;
	TraceGlobalContext m_ctx;
};

}//namespace
#endif


