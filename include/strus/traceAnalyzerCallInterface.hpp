/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Builder object for all toplevel interfaces related to the analyzer with tracing of all methods called.
/// \file traceAnalyzerCallInterface.hpp
#ifndef _STRUS_TRACE_STORAGE_CALL_INTERFACE_HPP_INCLUDED
#define _STRUS_TRACE_STORAGE_CALL_INTERFACE_HPP_INCLUDED

namespace strus
{
/// \brief Forward declaration
class AnalyzerObjectBuilderInterface;
/// \brief Forward declaration
class TraceLoggerInterface;

/// \brief Interface providing a storage object builde interface with tracing and querying of traces
class TraceAnalyzerCallInterface
{
public:
	/// \brief Destructor
	virtual ~TraceAnalyzerCallInterface(){}

	/// \brief Create an object builder with logging of all method calls with the trace logger specified
	/// \param[in] builder the real object builder implementation (caller keeps ownership)
	/// \param[in] tracelog the tracelogger for logging and querying traces (caller keeps ownership)
	/// \return the object builder interface (ownership to caller)
	virtual AnalyzerObjectBuilderInterface* createObjectBuilder(
			AnalyzerObjectBuilderInterface* builder,
			TraceLoggerInterface* tracelog)=0;

	/// \brief Create an viewer for inspecting trace logs
	/// \return the viewer interface (ownership to caller)
	virtual TraceViewerInterface* createViewer() const=0;
};

}//namespace
#endif

