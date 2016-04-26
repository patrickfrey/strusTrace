/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of logging and querying call traces in json
/// \file traceLogger_json.cpp
#include "traceLogger_json.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "logUtils.hpp"
#include "strus/errorBufferInterface.hpp"
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <limits>
#include <cerrno>

using namespace strus;

TraceLogger_json::~TraceLogger_json()
{
	std::vector<utils::StringBlock*>::iterator si = m_strings.begin(), se = m_strings.end();
	for (; si != se; ++si)
	{
		delete *si;
	}
}

TraceLogRecordHandle
	TraceLogger_json::logMethodCall(
		const char* className,
		const char* methodName,
		const TraceObjectId& objId)
{
	try
	{
		m_recordar.push_back( TraceRecord( className, methodName, objId, m_recordar.size()+1, m_depth));
		if (m_recordar.size() > std::numeric_limits<TraceLogRecordHandle>::max())
		{
			throw strus::runtime_error(_TXT("number of logs out of log handle range"));
		}
		return (TraceLogRecordHandle)m_recordar.size();
	}
	CATCH_ERROR_MAP_RETURN( _TXT("trace logger error logging method call"), *m_errorhnd, 0)
}

const char* TraceLogger_json::allocString( const char* str, std::size_t strsize)
{
	const char* rt = 0;
	if (m_strings.empty())
	{
		m_strings.reserve( m_strings.size()+1);//... no bad_alloc on following push_back()
		utils::StringBlock* blk = new utils::StringBlock( str, strsize);
		rt = blk->ptr();
		m_strings.push_back( blk);
	}
	else
	{
		rt = m_strings.back()->alloc( str, strsize);
		if (rt == 0)
		{
			m_strings.reserve( m_strings.size()+1);//... no bad_alloc on following insert()
			utils::StringBlock* blk = new utils::StringBlock( str, strsize);
			rt = blk->ptr();
			m_strings.insert( m_strings.begin()+m_strings.size()-1, blk);
		}
	}
	return rt;
}

void TraceLogger_json::logMethodTermination(
		const TraceLogRecordHandle& loghnd,
		const std::vector<TraceElement>& parameter)
{
	try
	{
		if (loghnd == 0 || loghnd > m_recordar.size())
		{
			m_errorhnd->report(_TXT("call log method termination with illegal log handle"));
			return;
		}
		std::size_t paramidx = m_parameterbuf.size();
		m_parameterbuf.reserve( m_parameterbuf.size() + parameter.size());
		std::vector<TraceElement>::const_iterator pi = parameter.begin(), pe = parameter.end();
		for (; pi != pe; ++pi)
		{
			switch (pi->type())
			{
				case TraceElement::TypeVoid:
				case TraceElement::TypeInt:
				case TraceElement::TypeUInt:
				case TraceElement::TypeDouble:
				case TraceElement::TypeBool:
				case TraceElement::TypeObject:
				case TraceElement::TypeOpenIndex:
				case TraceElement::TypeClose:
					m_parameterbuf.push_back( *pi);
					break;
				case TraceElement::TypeString:
				case TraceElement::TypeOpenTag:
					m_parameterbuf.push_back(
						TraceElement(
							pi->type(),
							allocString( pi->value().String.Ptr, pi->value().String.Size),
							pi->value().String.Size)
						);
					break;
			}
		}
		m_recordar[ loghnd-1].setEndCall( m_recordar.size()+1, paramidx, parameter.size());
	}
	CATCH_ERROR_MAP( _TXT("trace logger error logging method call termination"), *m_errorhnd)
}

void TraceLogger_json::logOpenBranch()
{
	if (m_depth >= std::numeric_limits<unsigned int>::max())
	{
		m_errorhnd->report(_TXT("illegal call of log open branch (too deep)"));
		return;
	}
	m_depth += 1;
}

void TraceLogger_json::logCloseBranch()
{
	if (m_depth == 1)
	{
		m_errorhnd->report(_TXT("illegal call of log close branch (no open branch)"));
		return;
	}
	m_depth -= 1;
}


static std::size_t getStructSize( const TraceElement* param, std::size_t paramSize)
{
	TraceElement const* pi = param;
	const TraceElement* pe = pi + paramSize;
	int brkcnt = 1;
	for (std::size_t pidx=0; pi != pe; ++pi,++pidx)
	{
		if (pi->type() == TraceElement::TypeClose)
		{
			if (--brkcnt == 0)
			{
				return pidx;
			}
		}
		else if (pi->type() == TraceElement::TypeOpenIndex || pi->type() == TraceElement::TypeOpenTag)
		{
			++brkcnt;
		}
	}
	throw std::runtime_error(_TXT("close of structure not found in parameter list"));
}

static void printParameter( FILE* output, const std::string& indentstr, const char* name, const TraceElement* param, std::size_t paramSize)
{
	TraceElement const* pi = param;
	const TraceElement* pe = pi + paramSize;
	unsigned int pidx = 0;
	while (pi != pe)
	{
		switch (pi->type())
		{
			case TraceElement::TypeVoid:
				if (name)
				{
					fprintf( output, "\"%s\":null", name);
					if (paramSize > 1) throw std::runtime_error("error in tragelog: two subsequent values in name context");
				}
				else
				{
					if (pidx++) fprintf( output, ", ");
					fprintf( output, "null");
				}
				++pi;
				break;
			case TraceElement::TypeInt:
				if (name)
				{
					fprintf( output, "\"%s\":%ld", name, pi->value().Int);
					if (paramSize > 1) throw std::runtime_error("error in tragelog: two subsequent values in name context");
				}
				else
				{
					if (pidx++) fprintf( output, ", ");
					fprintf( output, "%ld", pi->value().Int);
				}
				++pi;
				break;
			case TraceElement::TypeUInt:
				if (name)
				{
					fprintf( output, "\"%s\":%lu", name, pi->value().UInt);
					if (paramSize > 1) throw std::runtime_error("error in tragelog: two subsequent values in name context");
				}
				else
				{
					if (pidx++) fprintf( output, ", ");
					fprintf( output, "%lu", pi->value().UInt);
				}
				++pi;
				break;
			case TraceElement::TypeDouble:
				if (name)
				{
					fprintf( output, "\"%s\":%.9g", name, pi->value().Double);
					if (paramSize > 1) throw std::runtime_error("error in tragelog: two subsequent values in name context");
				}
				else
				{
					if (pidx++) fprintf( output, ", ");
					fprintf( output, "%.9g", pi->value().Double);
				}
				++pi;
				break;
			case TraceElement::TypeBool:
				if (name)
				{
					fprintf( output, "\"%s\":%s", name, pi->value().Bool ? "true":"false");
					if (paramSize > 1) throw std::runtime_error("error in tragelog: two subsequent values in name context");
				}
				else
				{
					if (pidx++) fprintf( output, ", ");
					fprintf( output, "%s", pi->value().Bool ? "true":"false");
				}
				++pi;
				break;
			case TraceElement::TypeObject:
				if (name)
				{
					fprintf( output, "\"%s\":'%s<%u>'", name, pi->value().Obj.Class, (unsigned int)pi->value().Obj.Id);
					if (paramSize > 1) throw std::runtime_error("error in tragelog: two subsequent values in name context");
				}
				else
				{
					if (pidx++) fprintf( output, ", ");
					fprintf( output, "'%s<%u>'", pi->value().Obj.Class, (unsigned int)pi->value().Obj.Id);
				}
				++pi;
				break;
			case TraceElement::TypeString:
				{
					std::string value( utils::encodeText( pi->value().String.Ptr, pi->value().String.Size));
					if (name)
					{
						fprintf( output, "\"%s\":\"%s\"", name, value.c_str());
						if (paramSize > 1) throw std::runtime_error("error in tragelog: two subsequent values in name context");
					}
					else
					{
						if (pidx++) fprintf( output, ", ");
						fprintf( output, "\"%s\"", value.c_str());
					}
				}
				++pi;
				break;
			case TraceElement::TypeOpenIndex:
			{
				if (name)
				{
					fprintf( output, "\"%s\":[", name);
					if (paramSize > 1) throw std::runtime_error("error in tragelog: two subsequent values in name context");
				}
				else
				{
					if (pidx++) fprintf( output, ", ");
					fprintf( output, "[");
				}
				int subpidx = 0;
				do
				{
					if (subpidx++) fprintf( output, ",");
					++pi;
					if (pi == pe) throw std::runtime_error(_TXT("unexpected end of structure"));

					fprintf( output, "\n%s", indentstr.c_str());
					std::size_t structsize = getStructSize( pi, paramSize - (pe - pi));
					printParameter( output, indentstr + "\t", (const char*)0, pi, structsize);
					pi += structsize + 1;
				}
				while (pi->type() == TraceElement::TypeOpenIndex);
				fprintf( output, "]");
				break;
			}
			case TraceElement::TypeOpenTag:
			{
				if (name)
				{
					fprintf( output, "\"%s\":{", name);
					if (paramSize > 1) throw std::runtime_error("error in tragelog: two subsequent values in name context");
				}
				else
				{
					if (pidx++) fprintf( output, ", ");
					fprintf( output, "{");
				}
				int subpidx = 0;
				do
				{
					if (subpidx++) fprintf( output, ",");
					const char* namechld = pi->value().String.Ptr;
					++pi;
					if (pi == pe) throw std::runtime_error(_TXT("unexpected end of structure"));

					fprintf( output, "\n%s", indentstr.c_str());
					std::size_t structsize = getStructSize( pi, paramSize - (pe - pi));
					printParameter( output, indentstr + "\t", namechld, pi, structsize);
					pi += structsize + 1;
				}
				while (pi->type() == TraceElement::TypeOpenTag);
				fprintf( output, "}");
				break;
			}
			case TraceElement::TypeClose:
			{
				throw std::runtime_error(_TXT("unexpected end of structure"));
			}
		}
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

static void printOutputJSON( FILE* output, std::size_t ridx_start, const std::string& indentstr, std::vector<TraceRecord>::const_iterator ri, const std::vector<TraceRecord>::const_iterator& re, const std::vector<TraceElement>& parameterbuf)
{
	std::size_t ridx = ridx_start;
	while (ri != re)
	{
		if (!ri->endTime())
		{
			throw strus::runtime_error(_TXT("called close without all method calls terminated"));
		}
		::fprintf( output, "\n%s{", indentstr.c_str());
		::fprintf( output, "\n%s\"time\":%u", indentstr.c_str(), (unsigned int)ridx);
		::fprintf( output, "\n%s\"object\":%u\n", indentstr.c_str(), (unsigned int)ri->objId());
		::fprintf( output, "\n%s\"call\":\"%s::%s\"\n", indentstr.c_str(), ri->className(), ri->methodName());
		if (ri->parameterSize())
		{
			::fprintf( output, "\n%s\"parameter\": {", indentstr.c_str());
			printParameter( output, indentstr + "\t", 0, parameterbuf.data() + ri->parameterIdx(), ri->parameterSize());
			::fprintf( output, "}");
		}
		if (ridx+1 < ri->endTime())
		{
			std::vector<TraceRecord>::const_iterator ri_next = ri + ri->endTime() - ridx;
			std::size_t ridx_next = ri->endTime() /*ridx + ri->endTime() - ridx*/;

			::fprintf( output, "\n%s\"sub\": {", indentstr.c_str());
			printOutputJSON( output, ridx+1, indentstr + "\t", ri+1, ri_next, parameterbuf);
			::fprintf( output, "\n%s}", indentstr.c_str());
			ri = ri_next;
			ridx = ridx_next;
		}
		else
		{
			++ri;
			++ridx;
		}
		::fprintf( output, "\n%s}", indentstr.c_str());
		if (ri != re) ::fprintf( output, ",");
	}
}

void TraceLogger_json::close()
{
	try
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
				throw strus::runtime_error(_TXT("failed to open file '%s' for writing (errno %u, call trace log)"), m_filename.c_str(), errno);
			}
			output.doCloseFile = true;
		}
		std::vector<TraceRecord>::const_iterator ri = m_recordar.begin(), re = m_recordar.end();
		std::vector<std::size_t> stack;

		printOutputJSON( output.file, 1, "", ri, re, m_parameterbuf);
	}
	CATCH_ERROR_MAP( _TXT("trace logger error flushing and closing output"), *m_errorhnd)
}

