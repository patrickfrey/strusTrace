/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of a traceLogger that counts defined method call events grouped by class or method call
/// \file traceLogger_count.hpp
#ifndef _STRUS_TRACE_LOGGER_COUNT_IMPLEMENTATION_HPP_INCLUDED
#define _STRUS_TRACE_LOGGER_COUNT_IMPLEMENTATION_HPP_INCLUDED
#include "strus/traceLoggerInterface.hpp"
#include "strus/traceElement.hpp"
#include "strus/base/thread.hpp"
#include <string>
#include <vector>
#include <map>
#include <cstdlib>

namespace strus
{
///\brief Forward declaration
class ErrorBufferInterface;

/// \brief Strus standard call trace logger implementation
class TraceLogger_count
	:public TraceLoggerInterface
{
public:
	/// \brief Constructor
	/// \param[in] filename_ file where to write result to
	/// \param[in] className_groupBy_ name of the class to groupd by
	/// \param[in] methodName_groupBy_ name of the method to group by
	/// \param[in] className_ name of the class to count the methods
	/// \param[in] methodName_ name of the method to count
	/// \param[in] errorhnd_ error message buffer
	TraceLogger_count(
		const std::string& filename_,
		const std::string& className_groupBy_,
		const std::string& methodName_groupBy_,
		const std::string& className_,
		const std::string& methodName_,
		ErrorBufferInterface* errorhnd_);

	/// \brief Destructor
	virtual ~TraceLogger_count();

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
	std::string m_filename;					///< file to write output to
	std::string m_className_groupBy;			///< class name to group results by
	std::string m_methodName_groupBy;			///< method name to group results by
	std::string m_className;				///< class name of events to count results of
	std::string m_methodName;				///< method name of events to count results of
	std::map<TraceObjectId,std::size_t> m_groupByMap;	///< map to group events
	std::vector<unsigned int> m_counters;			///< counters of events
	typedef std::map<TraceLogRecordHandle,std::size_t> GroupMap;
	GroupMap m_currentGroupMap;				///< current group event handles
	TraceLogRecordHandle m_logcnt;				///< current event count
};

}//namespace
#endif

