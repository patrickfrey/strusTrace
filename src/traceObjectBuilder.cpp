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
#include "strus/errorBufferInterface.hpp"
#include "strus/analyzerObjectBuilderInterface.hpp"
#include "strus/storageObjectBuilderInterface.hpp"
#include <stdexcept>

using namespace strus;

TraceObjectBuilder::TraceObjectBuilder( TraceLoggerInterface* logger_, ErrorBufferInterface* errorhnd_)
	:m_errorhnd(errorhnd_),m_idmap(new TraceIdMap(errorhnd_)),m_logger(logger_),m_ctx(logger_,errorhnd_){}

AnalyzerObjectBuilderInterface*
	TraceObjectBuilder::createAnalyzerObjectBuilder(
		AnalyzerObjectBuilderInterface* builder)
{
	try
	{
		return new AnalyzerObjectBuilderImpl( builder, &m_ctx);
	}
	CATCH_ERROR_MAP_RETURN( "failed to create analyzer object builder builder proxy for generating call traces", *m_errorhnd, 0)
}
	
StorageObjectBuilderInterface*
	TraceObjectBuilder::createStorageObjectBuilder(
		StorageObjectBuilderInterface* builder)
{
	try
	{
		return new StorageObjectBuilderImpl( builder, &m_ctx);
	}
	CATCH_ERROR_MAP_RETURN( "failed to create analyzer object builder builder proxy for generating call traces", *m_errorhnd, 0)
}

const TraceIdMapInterface* TraceObjectBuilder::getIdMap() const
{
	return m_idmap.get();
}


