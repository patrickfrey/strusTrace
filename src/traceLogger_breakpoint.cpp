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
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "strus/errorBufferInterface.hpp"
#include <stdexcept>
#include <limits>

using namespace strus;

static void strus_breakpoint(){}

TraceLogger_breakpoint::TraceLogger_breakpoint( const std::vector<TraceTimeCounter>& breakpoints_, ErrorBufferInterface* errorhnd_)
	:m_errorhnd(errorhnd_),m_mutex(),m_logcnt(0)
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
		const char*,
		const char*,
		const TraceObjectId& objId)
{
	try
	{
		utils::ScopedLock lock( m_mutex);

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
	CATCH_ERROR_MAP_RETURN( _TXT("trace logger error logging method call (breakpoint): %s"), *m_errorhnd, 0)
}

void TraceLogger_breakpoint::logMethodTermination(
		const TraceLogRecordHandle&,
		const std::vector<TraceElement>&)
{}

bool TraceLogger_breakpoint::close()
{
	return true;
}


