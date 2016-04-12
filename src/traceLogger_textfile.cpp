/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of logging and querying call traces
/// \file traceLogger.cpp
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

TraceLogger_textfile::TraceLogger_textfile( ErrorBufferInterface* errorhnd_, const std::string& filename)
	:m_output(0),m_errorhnd(errorhnd_),m_depth(0),m_logcnt(0),m_traceIdMap(createTraceIdMap(errorhnd_))
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
		++m_logcnt;
		const char* className = m_traceIdMap->getClassName( classId);
		const char* methodName = m_traceIdMap->getMethodName( classId, methodId);
		::fprintf( m_output, "[%9u]%s%s<%u>::%s\n", (unsigned int)m_logcnt, m_indentstr.c_str(), className, (unsigned int)objId, methodName);
		return m_logcnt;
	}
	CATCH_ERROR_MAP_RETURN( "trace logger error logging method call", *m_errorhnd, 0)
}

void TraceLogger_textfile::logObjectCreation(
		const TraceObjectId& objid,
		const TraceLogRecordHandle& rechnd)
{
	try
	{
		::fprintf( m_output, "[%9u] * <%u>\n", (unsigned int)rechnd, (unsigned int)objid);
	}
	CATCH_ERROR_MAP( "trace logger error logging object creation", *m_errorhnd)
}

void TraceLogger_textfile::logMethodTermination(
		const TraceLogRecordHandle& loghnd,
		const std::string& packedParameter)
{
	try
	{
		std::ostringstream buf;
		std::vector<std::string> m_stack;
		std::vector<TraceElement> elements
			= m_traceIdMap->unpackElements( packedParameter.c_str(), packedParameter.size());
		std::vector<TraceElement>::const_iterator ei = elements.begin(), ee = elements.end();
		for (int eidx=0; ei != ee; ++ei,++eidx)
		{
			if (eidx) buf << ", ";
			switch (ei->type())
			{
				case TraceElement::TypeVoid:
					buf << "()";
					break;
				case TraceElement::TypeInt:
					buf << ei->value().Int;
					break;
				case TraceElement::TypeUInt:
					buf << ei->value().UInt;
					break;
				case TraceElement::TypeFloat:
					buf << std::fixed << std::setprecision(3) << ei->value().Float;
					break;
				case TraceElement::TypeDouble:
					buf << std::fixed << std::setprecision(6) << ei->value().Double;
					break;
				case TraceElement::TypeBool:
					buf << (ei->value().Bool?"true":"false");
					break;
				case TraceElement::TypeString:
					buf << ei->value().String;
					break;
				case TraceElement::TypeOpenIndex:
					buf << ei->value().Index << ":";
					break;
				case TraceElement::TypeOpenTag:
					buf << "<" << ei->value().String << ">";
					m_stack.push_back( ei->value().String);
					break;
				case TraceElement::TypeClose:
					if (m_stack.empty()) throw strus::runtime_error(_TXT("illegal close tag in trace parameter string"));
					buf << "</" << m_stack.back().c_str() << ">";
					m_stack.pop_back();
					break;
			}
			std::string params( buf.str());
			::fprintf( m_output, "[%9u]%s <-- %s\n", (unsigned int)loghnd, m_indentstr.c_str(), params.c_str());
		}
	}
	CATCH_ERROR_MAP( "trace logger error logging method termination", *m_errorhnd)
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
	CATCH_ERROR_MAP( "trace logger error logging open call tree branch", *m_errorhnd)
}

void TraceLogger_textfile::logCloseBranch()
{
	try
	{
		if (m_depth == 0)
		{
			m_errorhnd->report(_TXT("illegal call of log close branch (no open branch)"));
			return;
		}
		m_indentstr.resize(m_indentstr.size() -2);
		m_depth -= 1;
	}
	CATCH_ERROR_MAP( "trace logger error logging close call tree branch", *m_errorhnd)
}

TraceViewerInterface* TraceLogger_textfile::createViewer() const
{
	m_errorhnd->report(_TXT("not implemented (textfile trace logger cannot be created for this logger instance because previous output is not accessible)"));
	return 0;
}

