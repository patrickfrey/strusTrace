/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of a traceLogger that enables to set breakpoints on defined method call events
/// \file traceLogger_breakpoint.cpp
#include "traceLogger_breakpoint.hpp"
#include "strus/lib/tracelog.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/traceIdMapInterface.hpp"
#include <stdexcept>
#include <limits>

using namespace strus;

static void strus_breakpoint(){}

TraceLogger_breakpoint::TraceLogger_breakpoint( ErrorBufferInterface* errorhnd_, const std::vector<TraceTimeCounter>& breakpoints_)
	:m_errorhnd(errorhnd_),m_depth(0),m_logcnt(0)
{
	std::vector<TraceTimeCounter>::const_iterator bi = breakpoints_.begin(), be = breakpoints_.end();
	for (; bi != be; ++bi)
	{
		m_breakpoints.insert( *bi);
	}
}

TraceLogger_breakpoint::~TraceLogger_breakpoint()
{
}

TraceLogRecordHandle
	TraceLogger_breakpoint::logMethodCall(
		const TraceClassId& classId,
		const TraceMethodId& methodId,
		const TraceObjectId& objId)
{
	try
	{
		if (m_logcnt >= std::numeric_limits<TraceLogRecordHandle>::max())
		{
			throw strus::runtime_error(_TXT("number of logs out of log handle range"));
		}
		++m_logcnt;
		if (m_breakpoints.find( m_logcnt) != m_breakpoints.end())
		{
			strus_breakpoint();
		}
		return m_logcnt;
	}
	CATCH_ERROR_MAP_RETURN( "trace logger error logging method call", *m_errorhnd, 0)
}

void TraceLogger_breakpoint::logObjectCreation(
		const TraceObjectId&,
		const TraceLogRecordHandle&)
{}

void TraceLogger_breakpoint::logMethodTermination(
		const TraceLogRecordHandle&,
		const std::string&)
{}

void TraceLogger_breakpoint::logOpenBranch()
{
	try
	{
		if (m_depth >= std::numeric_limits<TraceTreeDepth>::max())
		{
			m_errorhnd->report(_TXT("illegal call of log open branch (too deep)"));
			return;
		}
		m_depth += 1;
	}
	CATCH_ERROR_MAP( "trace logger error logging open call tree branch", *m_errorhnd)
}

void TraceLogger_breakpoint::logCloseBranch()
{
	try
	{
		if (m_depth == 0)
		{
			m_errorhnd->report(_TXT("illegal call of log close branch (no open branch)"));
			return;
		}
		m_depth -= 1;
	}
	CATCH_ERROR_MAP( "trace logger error logging close call tree branch", *m_errorhnd)
}

TraceViewerInterface* TraceLogger_breakpoint::createViewer() const
{
	m_errorhnd->report(_TXT("not implemented (textfile trace logger cannot be created for this logger instance because previous output is not accessible)"));
	return 0;
}

