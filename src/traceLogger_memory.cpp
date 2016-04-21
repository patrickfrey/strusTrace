/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of logging and querying call traces in memory
/// \file traceLogger_memory.cpp
#include "traceLogger_memory.hpp"
#include "traceViewer_memory.hpp"
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

const char* StringBlock::alloc( const char* blk_, std::size_t blksize_)
{
	if (m_size + blksize_ > m_allocsize || blksize_ > m_allocsize) return 0;
	char* rt = m_blk + m_size;
	std::memcpy( rt, blk_, blksize_);
	m_size += blksize_;
	return rt;
}

TraceLogger_memory::~TraceLogger_memory()
{
	std::vector<StringBlock*>::iterator si = m_strings.begin(), se = m_strings.end();
	for (; si != se; ++si)
	{
		delete *si;
	}
}

TraceLogRecordHandle
	TraceLogger_memory::logMethodCall(
		const TraceClassId& classId,
		const TraceMethodId& methodId,
		const TraceObjectId& objId)
{
	try
	{
		m_recordar.push_back(
			TraceRecord( classId, methodId, objId, m_recordar.size()+1, m_depth, 0, 0));
		if (m_recordar.size() > std::numeric_limits<TraceLogRecordHandle>::max())
		{
			throw strus::runtime_error(_TXT("number of logs out of log handle range"));
		}
		return (TraceLogRecordHandle)m_recordar.size();
	}
	CATCH_ERROR_MAP_RETURN( _TXT("trace logger error logging method call"), *m_errorhnd, 0)
}

void TraceLogger_memory::logObjectCreation(
		const TraceObjectId& objId,
		const TraceLogRecordHandle& loghnd)
{
	try
	{
		if (!loghnd || loghnd > m_recordar.size())
		{
			m_errorhnd->report( _TXT("illegal handle passed to log object creation call"));
			return;
		}
		m_creatmap[ objId] = loghnd;
	}
	CATCH_ERROR_MAP( _TXT("trace logger error logging object creation"), *m_errorhnd)
}

void TraceLogger_memory::logMethodTermination(
		const TraceLogRecordHandle& loghnd,
		const std::string& packedParameter)
{
	if (loghnd == 0 || loghnd > m_recordar.size())
	{
		m_errorhnd->report(_TXT("call log method termination with illegal log handle"));
		return;
	}
	const char* paramptr;
	if (m_strings.empty())
	{
		m_strings.reserve( m_strings.size()+1);//... no bad_alloc on following push_back()
		StringBlock* blk = new StringBlock( packedParameter.c_str(), packedParameter.size());
		paramptr = blk->ptr();
		m_strings.push_back( blk);
	}
	else
	{
		paramptr = m_strings.back()->alloc( packedParameter.c_str(), packedParameter.size());
		if (paramptr == 0)
		{
			m_strings.reserve( m_strings.size()+1);//... no bad_alloc on following insert()
			StringBlock* blk = new StringBlock( packedParameter.c_str(), packedParameter.size());
			paramptr = blk->ptr();
			m_strings.insert( m_strings.begin()+m_strings.size()-1, blk);
		}
	}

	TraceRecord& callrec = m_recordar[ loghnd-1];
	callrec.setEndCall( m_recordar.size()+1, paramptr, packedParameter.size());
}

static bool match_query( const TraceQuery& query, const TraceRecord& rec)
{
	if (query.classId() && query.classId() != rec.classId()) return false;
	if (query.methodId() && query.methodId() != rec.methodId()) return false;
	if (query.objId() && query.objId() != rec.objId()) return false;
	if (query.time_from() && query.time_from() > rec.startTime()) return false;
	if (query.time_to() && query.time_to() < rec.endTime()) return false;
	if (query.depth_from() && query.depth_from() > rec.depth()) return false;
	if (query.depth_to() && query.depth_to() <= rec.depth()) return false;
	return true;
}

void TraceLogger_memory::logOpenBranch()
{
	if (m_depth >= std::numeric_limits<TraceTreeDepth>::max())
	{
		m_errorhnd->report(_TXT("illegal call of log open branch (too deep)"));
		return;
	}
	m_depth += 1;
}

void TraceLogger_memory::logCloseBranch()
{
	if (m_depth == 0)
	{
		m_errorhnd->report(_TXT("illegal call of log close branch (no open branch)"));
		return;
	}
	m_depth -= 1;
}

std::vector<TraceRecord> TraceLogger_memory::listMethodCalls(
		const TraceQuery& query,
		std::size_t startIndex,
		std::size_t maxNofResults) const
{
	try
	{
		std::vector<TraceRecord> rt;
		std::vector<TraceRecord>::const_iterator ri = m_recordar.begin(), re = m_recordar.end();

		if (query.time_from()) ri += query.time_from()-1;
		if (query.time_to()) re = m_recordar.begin() + query.time_to()-1;

		for (std::size_t residx=0; ri != re && rt.size() < maxNofResults; ++ri)
		{
			if (match_query( query, *ri))
			{
				if (residx++ >= startIndex)
				{
					rt.push_back( *ri);
				}
			}
		}
		return rt;
	}
	CATCH_ERROR_MAP_RETURN( _TXT("trace logger error listing method calls"), *m_errorhnd, std::vector<TraceRecord>())
}


TraceTimeCounter TraceLogger_memory::getObjectCreationTime( const TraceObjectId& objId) const
{
	std::map<TraceObjectId,TraceTimeCounter>::const_iterator ci = m_creatmap.find( objId);
	if (ci == m_creatmap.end())
	{
		return 0;
	}
	return ci->second;
}

TraceViewerInterface* TraceLogger_memory::createViewer() const
{
	try
	{
		return new TraceViewer_memory( m_errorhnd, this);
	}
	CATCH_ERROR_MAP_RETURN( _TXT("error creating trace viewer for inspecting the trace logs in memory"), *m_errorhnd, 0)
}

