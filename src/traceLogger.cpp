/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of logging and querying call traces
/// \file traceLogger.cpp
#include "traceLogger.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "strus/errorBufferInterface.hpp"
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <limits>

using namespace strus;

enum {MaxBlockSize=1<<14};
StringBlock::~StringBlock()
{
	std::free( m_blk);
}

StringBlock::StringBlock( const StringBlock& o)
	:m_blk(o.m_blk),m_size(o.m_size),m_allocsize(o.m_allocsize)
{}

StringBlock::StringBlock( const char* blk_, std::size_t blksize_)
{
	m_allocsize = (blksize_ > MaxBlockSize) ? blksize_:MaxBlockSize;
	m_blk = (char*)std::malloc( m_allocsize);
	if (!m_blk) throw std::bad_alloc();
	std::memcpy( m_blk, blk_, blksize_);
	m_size = blksize_;
}

const char* StringBlock::ptr() const
{
	return m_blk;
}

std::size_t StringBlock::size() const
{
	return m_size;
}

char* StringBlock::alloc( std::size_t blksize_)
{
	if (m_size + blksize_ > m_allocsize || blksize_ > m_allocsize) return 0;
	char* rt = m_blk + m_size;
	m_size += blksize_;
	return rt;
}


TraceLogRecordHandle
	TraceLogger::logMethodCall(
		TraceClassId classId,
		TraceMethodId methodId,
		TraceObjectId objId,
		TraceObjectId resultObjId,
		const std::string& packedParameter)
{
	try
	{
		const char* paramptr;
		if (m_strings.empty())
		{
			StringBlock blk( packedParameter.c_str(), packedParameter.size());
			paramptr = blk.ptr();
			m_strings.push_back( blk);
		}
		else
		{
			paramptr = m_strings.back().alloc( packedParameter.size());
			if (paramptr == 0)
			{
				StringBlock blk( packedParameter.c_str(), packedParameter.size());
				paramptr = blk.ptr();
				m_strings.insert( m_strings.begin()+m_strings.size()-1, blk);
			}
		}
		m_recordar.push_back(
			Record( classId, methodId, objId, m_recordar.size()+1, m_depth, resultObjId, paramptr, packedParameter.size()));
		return (TraceLogRecordHandle)m_recordar.size();
	}
	CATCH_ERROR_MAP_RETURN( "trace logger error logging method call", *m_errorhnd, 0)
}

void TraceLogger::logMethodTermination(
		TraceLogRecordHandle loghnd)
{
	if (loghnd == 0 || loghnd > m_recordar.size())
	{
		m_errorhnd->report(_TXT("call log method termination with illegal log handle"));
		return;
	}
	m_recordar[ loghnd-1].setEndTime( m_recordar.size()+1);
}

bool TraceLogger::Query::match( const TraceLoggerInterface::Record& rec) const
{
	if (m_classId && m_classId != rec.classId()) return false;
	if (m_methodId && m_methodId != rec.methodId()) return false;
	if (m_time_from && m_time_from > rec.startTime()) return false;
	if (m_time_to && m_time_to <= rec.endTime()) return false;
	if (m_depth_from && m_depth_from > rec.depth()) return false;
	if (m_depth_to && m_depth_to <= rec.depth()) return false;
	if (m_resultObjId && m_resultObjId != rec.resultObjId()) return false;
	return true;
}

void TraceLogger::logOpenBranch()
{
	if (m_depth >= std::numeric_limits<TraceTreeDepth>::max())
	{
		m_errorhnd->report(_TXT("illegal call of log open branch (too deep)"));
		return;
	}
	m_depth += 1;
}

void TraceLogger::logCloseBranch()
{
	if (m_depth == 0)
	{
		m_errorhnd->report(_TXT("illegal call of log close branch (no open branch)"));
		return;
	}
	m_depth -= 1;
}

std::vector<TraceLoggerInterface::Record> TraceLogger::listMethodCalls(
		const Query& query,
		std::size_t startIndex,
		std::size_t maxNofResults)
{
	try
	{
		std::vector<Record> rt;
		std::vector<Record>::const_iterator ri = m_recordar.begin(), re = m_recordar.end();

		if (query.time_from()) ri += query.time_from()-1;
		if (query.time_to()) re = m_recordar.begin() + query.time_to()-1;

		for (std::size_t residx=0; ri != re && rt.size() < maxNofResults; ++ri)
		{
			if (query.match( *ri))
			{
				if (residx++ >= startIndex)
				{
					rt.push_back( *ri);
				}
			}
		}
		return rt;
	}
	CATCH_ERROR_MAP_RETURN( "trace logger error listing method calls", *m_errorhnd, std::vector<TraceLoggerInterface::Record>())
}



