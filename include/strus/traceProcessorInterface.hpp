/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Interface for logging and querying call traces
/// \file traceProcesorInterface.hpp
#ifndef _STRUS_TRACE_PROCESSOR_INTERFACE_HPP_INCLUDED
#define _STRUS_TRACE_PROCESSOR_INTERFACE_HPP_INCLUDED
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

/// \brief Interface for creating loggers and viewers of call traces
class TraceProcessorInterface
{
public:
	/// \brief Destructor
	virtual ~TraceProcessorInterface(){}

	/// \brief Create an interface for logging call traces
	/// \param[in] idmap trace identifier map
	/// \param[in] config configuration string of the logger built
	/// \return the logger
	virtual TraceLoggerInterface*
		createLogger(
			const strus::TraceIdMapInterface* idmap,
			const std::string& config) const=0;

	/// \brief Create an interface for recovering and inspecting persistently logged call traces
	/// \param[in] idmap trace identifier map
	/// \param[in] config configuration string of the call trace to inspect
	/// \return the viewer
	virtual TraceViewerInterface*
		createViewer(
			const std::string& config) const=0;
};

}//namespace
#endif


