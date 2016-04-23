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
#include "traceIdMap.hpp"

namespace strus
{
/// \brief Forward declaration
class ErrorBufferInterface;
/// \brief Forward declaration
class TraceLoggerInterface;
/// \brief Forward declaration
class TraceProcessorInterface;
/// \brief Forward declaration
class TraceViewerInterface;

/// \brief Standard implementation of the interface creating proxies for Strus objects that log methods called besides calling them
class TraceObjectBuilder
	:public TraceObjectBuilderInterface
{
public:
	/// \brief Constructor
	/// \param[in] traceproc_ trace processor interface to use (ownership passed to this)
	/// \param[in] loggerConfig trace logger configuration
	/// \param[in] errorhnd_ error buffer for error messages and exceptions
	TraceObjectBuilder(
			TraceProcessorInterface* traceproc_,
			const std::string& loggerConfig,
			ErrorBufferInterface* errorhnd_);

	virtual ~TraceObjectBuilder(){}

	virtual AnalyzerObjectBuilderInterface*
		createAnalyzerObjectBuilder(
			AnalyzerObjectBuilderInterface* builder) const;
	
	virtual StorageObjectBuilderInterface*
		createStorageObjectBuilder(
			StorageObjectBuilderInterface* builder) const;

	virtual const TraceIdMapInterface* getIdMap() const;

	virtual TraceViewerInterface* createViewer() const;

private:
	ErrorBufferInterface* m_errorhnd;
	Reference<TraceProcessorInterface> m_traceproc;
	TraceIdMap m_idmap;
	Reference<TraceLoggerInterface> m_logger;
	mutable Reference<TraceGlobalContext> m_ctx;
};

}//namespace
#endif


