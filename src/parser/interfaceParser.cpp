/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Parser for Strus interfaces
/// \file interfaceParser.cpp
#include "interfaceParser.hpp"
#include <stdexcept>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace strus;

static void skipSpaces( char const*& si, const char* se)
{
	while (si != se && (unsigned char)*si <= 32) ++si;
}
static void skipToEoln( char const*& si, const char* se)
{
	while (si != se && *si != '\n') ++si;
}
static void skipToStr( char const*& si, const char* se, const char* str)
{
	std::size_t strsize = std::strlen(str);
	while (si != se)
	{
		if (si + strsize < se && *si == str[0])
		{
			if (0==std::memcmp( si, str, strsize))
			{
				return;
			}
		}
		else if (*si == '\\' && si+1 < se)
		{
			++si;
		}
		++si;
	}
}

static bool isAlpha( char ch)
{
	if (ch == '_') return true;
	if ((ch|32) >= 'a' || (ch|32) <= 'z') return true;
	return false;
}
static bool isAlnum( char ch)
{
	return isAlpha(ch) || (ch >= '0' && ch <= '9');
}
static std::string parseIdentifier( char const*& si, const char* se)
{
	std::string rt;
	for (; si != se && isAlnum(*si); ++si)
	{
		rt.push_back( *si);
	}
	return rt;
}
static bool isOperator( char ch)
{
	static const char* ar = "<>()*&::";
	return std::strchr( ar, ch) != 0;
}
static void skipSpacesAndComments( char const*& si, const char* se)
{
	while (si != se)
	{
		skipSpaces( si, se);
		if (si + 1 < se && si[0] == '/' && si[1] == '/')
		{
			skipToEoln( si, se);
		}
		else if (si + 1 < se && si[0] == '/' && si[1] == '*')
		{
			skipToStr( si, se, "*/");
			if (si != se) si += 2;
			continue;
		}
	}
}
static void skipBrackets( char const*& si, const char* se, char sb, char eb)
{
	if (si == se || *si != sb) throw std::runtime_error("internal: illegal call of skipBrackets");
	int cnt = 1;
	++si;
	skipSpacesAndComments( si, se);

	while (si != se)
	{
		if (*si == sb)
		{
			++cnt;
		}
		else if (*si == eb)
		{
			--cnt;
			if (cnt == 0)
			{
				++si;
				return;
			}
		}
		skipSpacesAndComments( si, se);
	}
	throw std::runtime_error("unbalanced brackets in source");
}

enum TokenType
{
	TokenOperator,
	TokenIdentifier,
	TokenVariable
};

class TokenDef
{
public:
	TokenDef( const TokenDef& o)
		:m_type(o.m_type),m_value(o.m_value){}
	TokenDef( const TokenType& t, const std::string& v)
		:m_type(t),m_value(v){}

	bool parse( std::map<std::string,std::string>& defmap, char const*& si, const char* se) const
	{
		skipSpaces( si, se);
		const char* start = si;
		if (si == se) return false;
		switch (m_type)
		{
			case TokenOperator:
			{
				std::string::const_iterator ti = m_value.begin(), te = m_value.end();
				for (; ti != te && si != se; ++ti,++si)
				{
					if (*si != *ti) goto FAILED;
				}
				if (ti != te) goto FAILED;
				break;
			}
			case TokenIdentifier:
			{
				std::string::const_iterator ti = m_value.begin(), te = m_value.end();
				for (; ti != te && si != se; ++ti,++si)
				{
					if (*si != *ti) goto FAILED;
				}
				if (ti != te) goto FAILED;
				if (si != se && isAlnum(*si)) goto FAILED;
				break;
			}
			case TokenVariable:
			{
				if (!isAlpha(*si)) goto FAILED;
				defmap[ m_value] = parseIdentifier( si, se);
				break;
			}
		}
		return true;

	FAILED:
		si = start;
		return false;
	}

private:
	TokenType m_type;
	std::string m_value;
};


class PatternDef
{
public:
	PatternDef( const PatternDef& o)
		:m_source(o.m_source),m_tokendefs(o.m_tokendefs){}

	explicit PatternDef( const std::string& src)
		:m_source(src)
	{
		char const* si = src.c_str();
		const char* se = si + src.size();
		skipSpaces( si, se);

		while (si != se)
		{
			if (isAlpha(*si))
			{
				m_tokendefs.push_back( TokenDef( TokenIdentifier, parseIdentifier( si, se)));
			}
			else if (isOperator(*si))
			{
				m_tokendefs.push_back( TokenDef( TokenOperator, std::string( si++, 1)));
			}
			else if (*si == '$')
			{
				++si;
				if (si == se || !isAlpha(*si))
				{
					throw std::runtime_error("identifier expeced in pattern after '$'");
				}
				m_tokendefs.push_back( TokenDef( TokenVariable, parseIdentifier( si, se)));
			}
			else
			{
				throw std::runtime_error( std::string("unknown token in pattern at ") + "'" + si + "'");
			}
			skipSpaces( si, se);
		}
	}

	const std::vector<TokenDef>& tokendefs() const
	{
		return m_tokendefs;
	}
	const std::string& source() const
	{
		return m_source;
	}

private:
	std::string m_source;
	std::vector<TokenDef> m_tokendefs;
};


enum OutputType
{
	OutputString,
	OuputVariable
};

class OutputDef
{
public:
	OutputDef()
		:m_chunks(){}
	OutputDef( const OutputDef& o)
		:m_chunks(o.m_chunks){}
	OutputDef( const std::string& src)
	{
		char const* oi = src.c_str();
		const char* oe = oi + src.size();
		std::string value;
		while (oi != oe)
		{
			if (*oi == '$')
			{
				if (!value.empty())
				{
					m_chunks.push_back( Chunk( OutputString, value));
					value.clear();
				}
				++oi;
				if (oi == oe || !isAlpha(*oi))
				{
					throw std::runtime_error("identifier expected after '$' in output definition");
				}
				m_chunks.push_back( Chunk( OuputVariable, parseIdentifier( oi, oe)));
			}
		}
		if (!value.empty())
		{
			m_chunks.push_back( Chunk( OutputString, value));
			value.clear();
		}
	}

	void print( 
			std::string &out,
			const std::map<std::string,std::string>& defmap,
			const std::string& name,
			const std::string& value) const
	{
		std::vector<Chunk>::const_iterator ci = m_chunks.begin(), ce = m_chunks.end();
		for (; ci != ce; ++ci)
		{
			switch (ci->m_type)
			{
				case OutputString:
					out.append( ci->m_value);
					break;
				case OuputVariable:
					if (ci->m_value == "name" && !name.empty())
					{
						out.append( name);
					}
					else if (ci->m_value == "value" && !value.empty())
					{
						out.append( value);
					}
					else
					{
						std::map<std::string,std::string>::const_iterator
							di = defmap.find( ci->m_value);
						if (di != defmap.end())
						{
							out.append( di->second);
						}
						else
						{
							throw std::runtime_error( std::string("variable '") + ci->m_value + "' in output is not defined");
						}
					}
					break;
			}
		}
	}

private:
	struct Chunk
	{
		OutputType m_type;
		std::string m_value;

		Chunk( const Chunk& o)
			:m_type(o.m_type),m_value(o.m_value){}
		Chunk( const OutputType& type_, const std::string& value_)
			:m_type(type_),m_value(value_){}
	};
	std::vector<Chunk> m_chunks;
};


class VariableType::Impl
{
public:
	explicit Impl( const std::string& pattern)
		:m_patterndef( pattern){}

	bool parse( std::map<std::string,std::string>& defmap, char const*& si, const char* se) const
	{
		std::map<std::string,std::string> defmap_tmp;
		const char* start = si;
		std::vector<TokenDef>::const_iterator
			ti = m_patterndef.tokendefs().begin(),
			te = m_patterndef.tokendefs().end();
		for (; ti != te; ++ti)
		{
			if (!ti->parse( defmap_tmp, si, se))
			{
				si = start;
				return false;
			}
		}
		defmap = defmap_tmp;
		return true;
	}

	void defineOutput( const char* eventname, const char* output)
	{
		if (m_output.find( eventname) != m_output.end())
		{
			throw std::runtime_error( std::string("duplicate definition of event '") + eventname + "' for pattern '" + m_patterndef.source() + "'");
		}
		m_output[ eventname] = OutputDef( output);
	}

	void print( std::string& out, const char* eventname,
			const std::map<std::string,std::string>& defmap,
			const std::string& name, const std::string& value) const
	{
		std::map<std::string,OutputDef>::const_iterator oi = m_output.find( eventname);
		if (oi != m_output.end())
		{
			try
			{
				oi->second.print( out, defmap, name, value);
			}
			catch (const std::runtime_error& err)
			{
				throw std::runtime_error( std::string("error in event '") + eventname + "' of pattern '" + m_patterndef.source() + "': " + err.what());
			}
		}
	}

	const std::string& source() const
	{
		return m_patterndef.source();
	}

private:
	PatternDef m_patterndef;
	std::map<std::string,OutputDef> m_output;
};


VariableType::VariableType( const char* pattern_)
{
	m_impl = new Impl( pattern_);
}

VariableType::VariableType( const VariableType& o)
{
	m_impl = new Impl( o.m_impl->source());
}

VariableType::~VariableType()
{
	delete m_impl;
}

const std::string& VariableType::source() const
{
	return m_impl->source();
}

VariableType& VariableType::operator()( const char* eventname, const char* output)
{
	m_impl->defineOutput( eventname, output);
	return *this;
}

bool VariableType::parse( std::map<std::string,std::string>& defmap, char const*& si, const char* se) const
{
	return m_impl->parse( defmap, si, se);
}

void VariableType::print( std::string& out, const char* eventname,
				const std::map<std::string,std::string>& defmap,
				const std::string& name, const std::string& value) const
{
	m_impl->print( out, eventname, defmap, name, value);
}

VariableType& TypeSystem::defineType( const char* pattern)
{
	m_variableTypes.push_back( VariableType( pattern));
	return m_variableTypes.back();
}

VariableValue TypeSystem::parse( char const*& si, const char* se) const
{
	char const* maxend = 0;
	VariableValue rt;
	std::vector<VariableType>::const_iterator
		vi = m_variableTypes.begin(),
		ve = m_variableTypes.end();
	for (; vi != ve; ++vi)
	{
		std::map<std::string,std::string> defmap;
		const char* enddef = si;
		if (vi->parse( defmap, enddef, se))
		{
			if (maxend < enddef)
			{
				rt = VariableValue( &*vi, defmap);
				maxend = enddef;
			}
		}
	}
	if (maxend)
	{
		return rt;
	}
	else
	{
		std::string msg( si, se-si>60?60:(se-si));
		throw std::runtime_error(std::string("no variable type found for '") + msg + "'");
	}
}

static unsigned int lineNumber( const char* begin, const char* at)
{
	char const* si = begin;
	unsigned int rt = 0;
	for (; si != at; ++si)
	{
		if (*si == '\n') ++rt;
	}
	return rt+1;
}

static unsigned int colNumber( const char* begin, const char* at)
{
	char const* si = at;
	unsigned int rt = 0;
	for (; si != begin; --si,++rt)
	{
		if (*si == '\n') break;
	}
	return rt+1;
}

void InterfacesDef::addSource( const std::string& source)
{
	char const* si = source.c_str();
	const char* se = si + source.size();
	try
	{
		skipSpacesAndComments( si, se);
		while (si != se)
		{
			if (*si == ';')
			{
				++si;
			}
			else if (isAlpha( *si))
			{
				std::string ident = parseIdentifier( si,se);
				if (ident == "namespace")
				{
					skipToStr( si, se, "{");
					if (si != se) si += 1;
				}
				else if (ident == "enum")
				{
					skipToStr( si, se, "{");
					skipBrackets( si, se, '{', '}');
					if (si != se) ++si;
				}
				else if (ident == "class")
				{
					skipSpacesAndComments( si, se);
					if (si == se || !isAlpha(*si))
					{
						throw std::runtime_error("class name expected after 'class'");
					}
					std::string className( parseIdentifier( si, se));
					skipToStr( si, se, "{");
					char const* endClass = si;
					skipBrackets( endClass, se, '{', '}');
					parseClass( className, si, endClass);
					si = endClass+1;
				}
			}
			skipSpacesAndComments( si, se);
		}
	}
	catch (const std::runtime_error& err)
	{
		std::ostringstream linemsg;
		linemsg << "line " << lineNumber( source.c_str(), si) << "column " << colNumber( source.c_str(), si);
		throw std::runtime_error( std::string("error in interface source at ") + linemsg.str() + ": " + err.what());
	}
}

void InterfacesDef::parseClass( const std::string& className, char const*& si, const char* se)
{
	ClassDef classDef( className);
	skipSpacesAndComments( si, se);
	while (si != se)
	{
		if (*si == ';')
		{
			++si;
		}
		else if (isAlpha( *si))
		{
			char const* start = si;
			std::string ident = parseIdentifier( si,se);
			if (ident == "namespace")
			{
				skipToStr( si, se, "{");
				if (si != se) si += 1;
			}
			else if (ident == "enum")
			{
				skipToStr( si, se, "{");
				skipBrackets( si, se, '{', '}');
				if (si != se) ++si;
			}
			else if (ident == "typedef")
			{
				skipToStr( si, se, ";");
				if (si != se) ++si;
			}
			else if (ident == "struct")
			{
				skipToStr( si, se, "{");
				skipBrackets( si, se, '{', '}');
				if (si != se) ++si;
			}
			else if (ident == "class")
			{
				skipToStr( si, se, "{");
				skipBrackets( si, se, '{', '}');
				if (si != se) ++si;
			}
			else
			{
				si = start;
				VariableValue retvaltype = m_typeSystem->parse( si, se);

				skipSpacesAndComments( si, se);
				if (si == se || !isAlpha( *si))
				{
					throw std::runtime_error("method name expected after type definition");
				}
				std::string methodName( parseIdentifier( si, se));
				skipSpacesAndComments( si, se);
				if (si == se || *si != '(')
				{
					throw std::runtime_error("open bracket '(' expected after method name");
				}
				char const* endParams = si;
				skipBrackets( endParams, se, '(', ')');
				++si;
				std::vector<VariableValue> params = parseParameters( si, endParams);
				classDef.addMethod( MethodDef( methodName, retvaltype, params));
				si = endParams+1;
			}
		}
		skipSpacesAndComments( si, se);
	}
	m_classdefar.push_back( classDef);
}

std::vector<VariableValue> InterfacesDef::parseParameters( char const*& si, const char* se)
{
	std::vector<VariableValue> rt;
	while (si != se)
	{
		VariableValue param = m_typeSystem->parse( si, se);
		skipSpacesAndComments( si, se);
		if (si != se && isAlpha( *si))
		{
			(void)parseIdentifier(si,se);	//... name of parameter is not interesting
		}
		skipSpacesAndComments( si, se);
		if (si != se)
		{
			if (*si == ',')
			{
				++si;
				continue;
			}
			else
			{
				throw std::runtime_error("comma expected as separator in method argument list");
			}
		}
	}
	return rt;
}

