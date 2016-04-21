/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of logging and querying call traces to textfile or stdout
/// \file traceLogger_textfile.cpp
#include "traceLogger_textfile.hpp"
#include "strus/lib/tracelog.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/traceIdMapInterface.hpp"
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

TraceLogger_textfile::TraceLogger_textfile( const std::string& filename, ErrorBufferInterface* errorhnd_)
	:m_errorhnd(errorhnd_),m_output(0),m_depth(1),m_indentstr(),m_logcnt(0),m_traceIdMap(createTraceIdMap(errorhnd_))
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

TraceLogger_textfile::~TraceLogger_textfile()
{
	if (m_output != ::stderr && m_output != ::stdout)
	{
		::fclose( m_output);
	}
	delete m_traceIdMap;
}

TraceLogRecordHandle
	TraceLogger_textfile::logMethodCall(
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
		const char* className = m_traceIdMap->getClassName( classId);
		const char* methodName = m_traceIdMap->getMethodName( classId, methodId);
		::fprintf( m_output, "[%u] %s%s<%u>::%s\n", (unsigned int)m_logcnt, m_indentstr.c_str(), className, (unsigned int)objId, methodName);
		::fflush( m_output);
		return m_logcnt;
	}
	CATCH_ERROR_MAP_RETURN( _TXT("trace logger error logging method call"), *m_errorhnd, 0)
}

void TraceLogger_textfile::logObjectCreation(
		const TraceObjectId& objid,
		const TraceLogRecordHandle& rechnd)
{
	try
	{
		::fprintf( m_output, "[%u] * <%u>\n", (unsigned int)rechnd, (unsigned int)objid);
	}
	CATCH_ERROR_MAP( _TXT("trace logger error logging object creation"), *m_errorhnd)
}

static std::string encodeText( const char* buf, std::size_t bufsize)
{
	static const char* cntrlchrs = "\n\t\r\b";
	static const char* cntrlsubs = "ntrb0";
	std::string rt;
	std::size_t bi = 0;
	for (; bi < bufsize; ++bi)
	{
		if ((unsigned char)buf[bi] < 32)
		{
			char const* ci = std::strchr( cntrlchrs, buf[bi]);
			if (ci)
			{
				rt.push_back( '\\');
				rt.push_back( cntrlsubs[ ci-cntrlchrs]);
			}
			else
			{
				rt.push_back( '.');
			}
		}
		else if (buf[bi] == '\'')
		{
			rt.push_back( '\\');
			rt.push_back( buf[bi]);
		}
		else
		{
			rt.push_back( buf[bi]);
		}
	}
	return rt;
}

static std::string encodeNumber( unsigned int num)
{
	std::ostringstream buf;
	buf << num;
	return buf.str();
}


void TraceLogger_textfile::logMethodTermination(
		const TraceLogRecordHandle& loghnd,
		const std::string& packedParameter)
{
	try
	{
		std::ostringstream buf;
		std::vector<std::string> stack;
		bool delim = false;
		const char* name;
		std::vector<TraceElement> elements
			= m_traceIdMap->unpackElements( packedParameter.c_str(), packedParameter.size());
		std::vector<TraceElement>::const_iterator ei = elements.begin(), ee = elements.end();
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
				case TraceElement::TypeFloat:
					if (delim) buf << " ";
					delim = true;
					buf << std::fixed << std::setprecision(3) << ei->value().Float;
					break;
				case TraceElement::TypeDouble:
					if (delim) buf << " ";
					delim = true;
					buf << std::fixed << std::setprecision(6) << ei->value().Double;
					break;
				case TraceElement::TypeBool:
					if (delim) buf << " ";
					delim = true;
					buf << (ei->value().Bool?"true":"false");
					break;
				case TraceElement::TypeObject:
					if (delim) buf << " ";
					delim = true;
					name = m_traceIdMap->getClassName( ei->value().Obj.Class);
					if (name) buf << name; else throw std::runtime_error("unknown class id");
					buf << "<" << ei->value().Obj.Id << ">";
					break;
				case TraceElement::TypeString:
					if (delim) buf << " ";
					delim = true;
					buf << encodeText( ei->value().String.Ptr, ei->value().String.Size);
					break;
				case TraceElement::TypeOpenIndex:
					if (delim) buf << " ";
					delim = false;
					stack.push_back( encodeNumber( ei->value().Index));
					buf << "<" << stack.back() << ">";
					break;
				case TraceElement::TypeOpenTag:
					if (delim) buf << " ";
					delim = false;
					stack.push_back( encodeText( ei->value().String.Ptr, ei->value().String.Size));
					buf << "<" << stack.back() << ">";
					break;
				case TraceElement::TypeClose:
					delim = true;
					if (stack.empty()) throw strus::runtime_error(_TXT("illegal close tag in trace parameter string"));
					buf << "</" << stack.back().c_str() << ">";
					stack.pop_back();
					break;
			}
		}
		std::string params( buf.str());
		::fprintf( m_output, "[%u] %s<-- %s\n", (unsigned int)loghnd, m_indentstr.c_str(), params.c_str());
		::fflush( m_output);
	}
	CATCH_ERROR_MAP( _TXT("trace logger error logging method termination"), *m_errorhnd)
}

void TraceLogger_textfile::logOpenBranch()
{
	try
	{
		if (m_depth >= std::numeric_limits<TraceTreeDepth>::max())
		{
			m_errorhnd->report(_TXT("illegal call of log open branch (too deep)"));
			return;
		}
		m_depth += 1;
		m_indentstr.append("  ");
	}
	CATCH_ERROR_MAP( _TXT("trace logger error logging open call tree branch"), *m_errorhnd)
}

void TraceLogger_textfile::logCloseBranch()
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
	CATCH_ERROR_MAP( _TXT("trace logger error logging close call tree branch"), *m_errorhnd)
}

TraceViewerInterface* TraceLogger_textfile::createViewer() const
{
	m_errorhnd->report(_TXT("not implemented (textfile trace logger cannot be created for this logger instance because previous output is not accessible)"));
	return 0;
}

