/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of logging and querying call traces to textfile or stdout
/// \file traceLogger_textfile.hpp
#ifndef _STRUS_TRACE_LOGGER_TEXTFILE_IMPLEMENTATION_HPP_INCLUDED
#define _STRUS_TRACE_LOGGER_TEXTFILE_IMPLEMENTATION_HPP_INCLUDED
#include "strus/traceLoggerInterface.hpp"
#include "strus/traceElement.hpp"
#include <string>
#include <cstdlib>

namespace strus
{
///\brief Forward declaration
class ErrorBufferInterface;

/// \brief Strus standard call trace logger implementation
class TraceLogger_textfile
	:public TraceLoggerInterface
{
public:
	/// \brief Constructor
	TraceLogger_textfile( const std::string& filename, ErrorBufferInterface* errorhnd_);

	/// \brief Destructor
	virtual ~TraceLogger_textfile();

	virtual TraceLogRecordHandle
		logMethodCall(
			const char* className,
			const char* methodName,
			const TraceObjectId& objId);

	virtual void logMethodTermination(
			const TraceLogRecordHandle& loghnd,
			const std::vector<TraceElement>& parameter);

	virtual void logOpenBranch();
	virtual void logCloseBranch();

	virtual void close();

private:
	ErrorBufferInterface* m_errorhnd;
	FILE* m_output;
	unsigned int m_depth;
	std::string m_indentstr;
	TraceLogRecordHandle m_logcnt;
};

}//namespace
#endif

