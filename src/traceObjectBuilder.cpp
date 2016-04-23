/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Toplevel object for logging and querying call traces
/// \file traceObjectBuilder.cpp
#include "traceObjectBuilder.hpp"
#include "traceIdMap.hpp"
#include "objects_gen.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "strus/traceProcessorInterface.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/analyzerObjectBuilderInterface.hpp"
#include "strus/storageObjectBuilderInterface.hpp"
#include <stdexcept>

using namespace strus;

TraceObjectBuilder::TraceObjectBuilder(
		const TraceProcessorInterface* traceproc,
		const std::string& loggerConfig,
		ErrorBufferInterface* errorhnd_)
	:m_errorhnd(errorhnd_),m_idmap(errorhnd_),m_logger(),m_ctx()
{
	m_logger.reset( traceproc->createLogger( &m_idmap, loggerConfig));
	if (!m_logger.get()) throw std::runtime_error( "failed to create trace logger");
	m_ctx.reset( new TraceGlobalContext( m_logger.get(), m_errorhnd)); 
	if (!m_ctx.get()) throw std::runtime_error( "failed to create trace global context");
}

AnalyzerObjectBuilderInterface*
	TraceObjectBuilder::createAnalyzerObjectBuilder(
		AnalyzerObjectBuilderInterface* builder) const
{
	try
	{
		return new AnalyzerObjectBuilderImpl( builder, m_ctx.get());
	}
	CATCH_ERROR_MAP_RETURN( _TXT("failed to create analyzer object builder builder proxy for generating call traces"), *m_errorhnd, 0)
}
	
StorageObjectBuilderInterface*
	TraceObjectBuilder::createStorageObjectBuilder(
		StorageObjectBuilderInterface* builder) const
{
	try
	{
		return new StorageObjectBuilderImpl( builder, m_ctx.get());
	}
	CATCH_ERROR_MAP_RETURN( _TXT("failed to create analyzer object builder builder proxy for generating call traces"), *m_errorhnd, 0)
}

const TraceIdMapInterface* TraceObjectBuilder::getIdMap() const
{
	return &m_idmap;
}

TraceViewerInterface* TraceObjectBuilder::createViewer() const
{
	return m_logger->createViewer();
}

