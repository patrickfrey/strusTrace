/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of a traceLogger that enables to set breakpoints on defined method call events
/// \file traceLogger_breakpoint.hpp
#ifndef _STRUS_TRACE_LOGGER_BREAKPOINT_IMPLEMENTATION_HPP_INCLUDED
#define _STRUS_TRACE_LOGGER_BREAKPOINT_IMPLEMENTATION_HPP_INCLUDED
#include "strus/traceLoggerInterface.hpp"
#include "strus/traceElement.hpp"
#include "strus/base/thread.hpp"
#include <string>
#include <vector>
#include <set>
#include <cstdlib>

namespace strus
{
///\brief Forward declaration
class ErrorBufferInterface;

/// \brief Strus standard call trace logger implementation
class TraceLogger_breakpoint
	:public TraceLoggerInterface
{
public:
	/// \brief Constructor
	TraceLogger_breakpoint( const std::vector<TraceTimeCounter>& breakpoints, ErrorBufferInterface* errorhnd_);

	/// \brief Destructor
	virtual ~TraceLogger_breakpoint();

	virtual TraceLogRecordHandle
		logMethodCall(
			const char* className,
			const char* methodName,
			const TraceObjectId& objId);

	virtual void logMethodTermination(
			const TraceLogRecordHandle& loghnd,
			const std::vector<TraceElement>& parameter);

	virtual bool close();

private:
	ErrorBufferInterface* m_errorhnd;			///< error buffer interface
	strus::mutex m_mutex;					///< mutex for critical sections
	std::set<TraceTimeCounter> m_breakpoints;
	TraceLogRecordHandle m_logcnt;
};

}//namespace
#endif

