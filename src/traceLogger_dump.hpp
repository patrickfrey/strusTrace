/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of immediately dumping method call traces to text file or stdout
/// \file traceLogger_dump.hpp
#ifndef _STRUS_TRACE_LOGGER_DUMP_IMPLEMENTATION_HPP_INCLUDED
#define _STRUS_TRACE_LOGGER_DUMP_IMPLEMENTATION_HPP_INCLUDED
#include "strus/traceLoggerInterface.hpp"
#include "strus/traceElement.hpp"
#include "utils.hpp"
#include <string>
#include <cstdlib>

namespace strus
{
///\brief Forward declaration
class ErrorBufferInterface;

/// \brief Strus standard call trace logger implementation
class TraceLogger_dump
	:public TraceLoggerInterface
{
public:
	/// \brief Constructor
	TraceLogger_dump( const std::string& filename, ErrorBufferInterface* errorhnd_);

	/// \brief Destructor
	virtual ~TraceLogger_dump();

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
	ErrorBufferInterface* m_errorhnd;	///< error buffer interface
	utils::Mutex m_mutex;			///< mutex for critical sections
	FILE* m_output;				///< file to write output to
	std::string m_indentstr;		///< current indentiation string
	TraceLogRecordHandle m_logcnt;		///< counter for log handles
};

}//namespace
#endif

