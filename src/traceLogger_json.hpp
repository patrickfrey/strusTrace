/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of logging and querying call traces
/// \file TraceLogger_json.hpp
#ifndef _STRUS_TRACE_LOGGER_IMPLEMENTATION_HPP_INCLUDED
#define _STRUS_TRACE_LOGGER_IMPLEMENTATION_HPP_INCLUDED
#include "strus/traceLoggerInterface.hpp"
#include "traceRecord.hpp"
#include "logUtils.hpp"
#include <string>
#include <vector>
#include <map>
#include <cstdlib>

namespace strus
{
///\brief Forward declaration
class ErrorBufferInterface;

/// \brief Strus standard call trace logger implementation
class TraceLogger_json
	:public TraceLoggerInterface
{
public:
	/// \brief Constructor
	explicit TraceLogger_json( const std::string& filename_, ErrorBufferInterface* errorhnd_)
		:m_errorhnd(errorhnd_),m_filename(filename_){}

	/// \brief Destructor
	virtual ~TraceLogger_json();

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
	const char* allocString( const char* str, std::size_t strsize);

private:
	ErrorBufferInterface* m_errorhnd;
	std::string m_filename;
	std::vector<TraceRecord> m_recordar;
	std::vector<utils::StringBlock*> m_strings;
	std::vector<TraceElement> m_parameterbuf;
};

}//namespace
#endif

