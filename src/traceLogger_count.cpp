/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of a traceLogger that counts defined method call events grouped by class or method call
/// \file traceLogger_count.cpp
#include "traceLogger_count.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/base/fileio.hpp"
#include <stdexcept>
#include <cerrno>

using namespace strus;

TraceLogger_count::TraceLogger_count( const std::string& filename_, const std::string& className_groupBy_, const std::string& methodName_groupBy_, const std::string& className_, const std::string& methodName_, ErrorBufferInterface* errorhnd_)
	:m_filename(filename_) 
	,m_className_groupBy(className_groupBy_)
	,m_methodName_groupBy(methodName_groupBy_)
	,m_className(className_)
	,m_methodName(methodName_)
	,m_currentGroupHnd(0)
	,m_currentIdx(0)
	,m_logcnt(0)
	,m_errorhnd(errorhnd_){}

TraceLogger_count::~TraceLogger_count()
{
	(void)close();
}

TraceLogRecordHandle
	TraceLogger_count::logMethodCall(
		const char* className,
		const char* methodName,
		const TraceObjectId& objId)
{
	try
	{
		++m_logcnt;
		if (m_className.empty() && m_methodName.empty()) return m_logcnt;

		bool groupByClassMatch = (m_className_groupBy.empty() || m_className_groupBy == className);
		bool groupByMethodMatch = (m_methodName_groupBy.empty() || m_methodName_groupBy == methodName);
		bool anyMatch = m_methodName_groupBy.empty() && m_className_groupBy.empty();
		bool countClassMatch = (m_className.empty() || m_className == className);
		bool countMethodMatch = (m_methodName.empty() || m_methodName == methodName);
		if (anyMatch)
		{
			/// No group by, just count all events:
			if (m_counters.empty())
			{
				m_counters.push_back(0);
				m_groupByMap[ 0] = 0;
			}
			if (countClassMatch && countMethodMatch)
			{
				++m_counters[0];
			}
		}
		else
		{
			/// Test if we got into a new group and set current counter if yes:
			if (groupByClassMatch && groupByMethodMatch)
			{
				std::map<TraceObjectId,std::size_t>::const_iterator
					gi = m_groupByMap.find( objId);
				if (gi == m_groupByMap.end())
				{
					m_groupByMap[ objId] = m_counters.size();
					m_currentGroupHnd = m_logcnt;
					m_currentIdx = m_counters.size();
					m_counters.push_back(0);
				}
			}
			/// Test if we got a match and count it if we are in a group context:
			if (countClassMatch && countMethodMatch)
			{
				if (m_currentGroupHnd)
				{
					++m_counters[ m_currentIdx];
				}
			}
		}
		return m_logcnt;
	}
	CATCH_ERROR_MAP_RETURN( _TXT("trace logger error logging method call (count): %s"), *m_errorhnd, 0)
}

void TraceLogger_count::logMethodTermination(
		const TraceLogRecordHandle& loghnd,
		const std::vector<TraceElement>&)
{
	if (loghnd == m_currentGroupHnd)
	{
		/// ... terminate counting
		m_currentGroupHnd = 0;
		m_currentIdx = 0;
	}
}

struct FileRAII
{
	FILE* file;
	bool doCloseFile;

	FileRAII()
		:file(0),doCloseFile(false)
	{}
	~FileRAII()
	{
		if (doCloseFile && file) fclose(file);
	}
};

bool TraceLogger_count::close()
{
	FileRAII output;
	if (m_filename == "-" || m_filename == "stdout")
	{
		output.file = ::stdout;
	}
	else if (m_filename == "stderr")
	{
		output.file = ::stderr;
	}
	else
	{
		output.file = ::fopen( m_filename.c_str(), "w");
		if (output.file == 0)
		{
			throw strus::runtime_error(_TXT("failed to open file '%s' for writing (errno %u, call trace log '%s')"), m_filename.c_str(), errno, "count");
		}
		output.doCloseFile = true;
	}
	std::map<TraceObjectId,std::size_t>::const_iterator
		mi = m_groupByMap.begin(), me = m_groupByMap.end();
	for (; mi != me; ++mi)
	{
		if (!mi->first && m_counters.size() == 1)
		{
			::fprintf( output.file, "%u\n", (unsigned int)m_counters[ mi->second]);
		}
		else
		{
			::fprintf( output.file, "%u\t%u\n", (unsigned int)mi->first, (unsigned int)m_counters[ mi->second]);
		}
	}
	::fflush( output.file);
	return true;
}


