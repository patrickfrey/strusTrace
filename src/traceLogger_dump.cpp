/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of immediately dumping method call traces to text file or stdout
/// \file traceLogger_dump.cpp
#include "traceLogger_dump.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "logUtils.hpp"
#include "strus/errorBufferInterface.hpp"
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <cstdio>
#include <cerrno>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <limits>

using namespace strus;

TraceLogger_dump::TraceLogger_dump( const std::string& filename, ErrorBufferInterface* errorhnd_)
	:m_errorhnd(errorhnd_),m_output(0),m_depth(1),m_indentstr(),m_logcnt(0)
{
	if (filename == "-" || filename == "stdout")
	{
		m_output = ::stdout;
	}
	else if (filename == "stderr")
	{
		m_output = ::stderr;
	}
	else
	{
		m_output = ::fopen( filename.c_str(), "w");
		if (m_output == 0)
		{
			throw strus::runtime_error(_TXT("failed to open file '%s' for writing (errno %u, call trace log)"), filename.c_str(), errno);
		}
	}
}

TraceLogger_dump::~TraceLogger_dump()
{
	if (m_output && m_output != ::stderr && m_output != ::stdout)
	{
		::fclose( m_output);
	}
}

TraceLogRecordHandle
	TraceLogger_dump::logMethodCall(
		const char* className,
		const char* methodName,
		const TraceObjectId& objId)
{
	try
	{
		if (!m_output)
		{
			throw strus::runtime_error(_TXT("logged to file already closed"));
		}
		if (m_logcnt >= std::numeric_limits<TraceLogRecordHandle>::max())
		{
			throw strus::runtime_error(_TXT("number of logs out of log handle range"));
		}
		++m_logcnt;
		::fprintf( m_output, "[%u] %s%s<%u>::%s\n", (unsigned int)m_logcnt, m_indentstr.c_str(), className, (unsigned int)objId, methodName);
		::fflush( m_output);
		return m_logcnt;
	}
	CATCH_ERROR_MAP_RETURN( _TXT("trace logger error logging method call (dump): %s"), *m_errorhnd, 0)
}

void TraceLogger_dump::logMethodTermination(
		const TraceLogRecordHandle& loghnd,
		const std::vector<TraceElement>& parameter)
{
	try
	{
		if (!m_output)
		{
			throw strus::runtime_error(_TXT("logged to file already closed"));
		}
		std::ostringstream buf;
		bool delim = false;
		std::vector<TraceElement>::const_iterator ei = parameter.begin(), ee = parameter.end();
		for (int eidx=0; ei != ee; ++ei,++eidx)
		{
			switch (ei->type())
			{
				case TraceElement::TypeVoid:
					if (delim) buf << " ";
					delim = true;
					buf << "()";
					break;
				case TraceElement::TypeInt:
					if (delim) buf << " ";
					delim = true;
					buf << ei->value().Int;
					break;
				case TraceElement::TypeUInt:
					if (delim) buf << " ";
					delim = true;
					buf << ei->value().UInt;
					break;
				case TraceElement::TypeDouble:
					if (delim) buf << " ";
					delim = true;
					buf << std::fixed << std::setprecision(9) << ei->value().Double;
					break;
				case TraceElement::TypeBool:
					if (delim) buf << " ";
					delim = true;
					buf << (ei->value().Bool?"true":"false");
					break;
				case TraceElement::TypeObject:
					if (delim) buf << " ";
					delim = true;
					buf << ei->value().Obj.Class;
					buf << "<" << ei->value().Obj.Id << ">";
					break;
				case TraceElement::TypeString:
					if (delim) buf << " ";
					delim = true;
					buf << utils::encodeText( ei->value().String.Ptr, ei->value().String.Size);
					break;
				case TraceElement::TypeOpenIndex:
					if (delim) buf << " ";
					delim = false;
					buf << utils::encodeNumber( ei->value().Index) << ":{";
					break;
				case TraceElement::TypeOpenTag:
					if (delim) buf << " ";
					delim = false;
					buf << utils::encodeText( ei->value().String.Ptr, ei->value().String.Size);
					buf << ":{";
					break;
				case TraceElement::TypeClose:
					delim = true;
					buf << "}";
					break;
			}
		}
		std::string params( buf.str());
		::fprintf( m_output, "[%u] %s<-- %s\n", (unsigned int)loghnd, m_indentstr.c_str(), params.c_str());
		::fflush( m_output);
	}
	CATCH_ERROR_MAP( _TXT("trace logger error logging method call termination (dump): %s"), *m_errorhnd)
}

void TraceLogger_dump::logOpenBranch()
{
	try
	{
		if (m_depth >= std::numeric_limits<unsigned short>::max())
		{
			m_errorhnd->report(_TXT("illegal call of log open branch (too deep)"));
			return;
		}
		m_depth += 1;
		m_indentstr.append("  ");
	}
	CATCH_ERROR_MAP( _TXT("trace logger error logging open call tree branch (dump): %s"), *m_errorhnd)
}

void TraceLogger_dump::logCloseBranch()
{
	try
	{
		if (m_depth == 1)
		{
			m_errorhnd->report(_TXT("illegal call of log close branch (no open branch)"));
			return;
		}
		m_indentstr.resize(m_indentstr.size() -2);
		m_depth -= 1;
	}
	CATCH_ERROR_MAP( _TXT("trace logger error logging close call tree branch (dump): %s"), *m_errorhnd)
}

bool TraceLogger_dump::close()
{
	if (m_output && m_output != ::stderr && m_output != ::stdout)
	{
		::fclose( m_output);
	}
	m_output = 0;
	return true;
}


