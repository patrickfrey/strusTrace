/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Interface for logging call traces
/// \file traceLoggerInterface.hpp
#ifndef _STRUS_TRACE_LOGGER_INTERFACE_HPP_INCLUDED
#define _STRUS_TRACE_LOGGER_INTERFACE_HPP_INCLUDED
#include "strus/traceElement.hpp"
#include <string>
#include <vector>

namespace strus
{

/// \brief Interface providing a storage object builder interface with tracing and querying of traces
class TraceLoggerInterface
{
public:
	/// \brief Destructor
	virtual ~TraceLoggerInterface(){}

	/// \brief Writes an entry to the method call log
	/// \param[in] className identifier of the caller object class
	/// \param[in] methodName identifier of the method called
	/// \param[in] objId object identifier of the caller
	/// \return handle of the log message written. Used to reference the record in logMethodTermination
	virtual TraceLogRecordHandle
		logMethodCall(
			const char* className,
			const char* methodName,
			const TraceObjectId& objId)=0;

	/// \brief Log the termination of a method call
	/// \param[in] loghnd handl of the record that specifies the method call, returned by logMethodCall.
	/// \param[in] parameter return value and in/out parameter values
	virtual void logMethodTermination(
			const TraceLogRecordHandle& loghnd,
			const std::vector<TraceElement>& parameter)=0;

	/// \brief Open a new sub branch in the tree (depth+1)
	virtual void logOpenBranch()=0;

	/// \brief Close the current sub branch in the tree (depth-1)
	virtual void logCloseBranch()=0;

	/// \brief Terminate logging, flush data logged to storage
	virtual void close()=0;
};

}//namespace
#endif

