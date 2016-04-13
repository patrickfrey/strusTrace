/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _STRUS_TRACE_SERIALIZE_DESERIALIZE_HPP_INCLUDED
#define _STRUS_TRACE_SERIALIZE_DESERIALIZE_HPP_INCLUDED
#include "internationalization.hpp"
#include "strus/base/hton.hpp"
#include "strus/traceElement.hpp"
#include "strus/traceLoggerInterface.hpp"
#include <string>
#include <vector>
#include <cstring>
#include <map>

namespace strus
{

class Serializer
{
public:
	enum ValueType
	{
		TypeVoid,
		TypeInt8,
		TypeUInt8,
		TypeInt16,
		TypeUInt16,
		TypeInt32,
		TypeUInt32,
		TypeInt64,
		TypeUInt64,
		TypeFloat,
		TypeDouble,
		TypeBool,
		TypeString,
		TypeOpenIndex,
		TypeOpenTag,
		TypeClose
	};
	enum {NofSerializeValueType=TypeClose+1};

	Serializer(){}
	~Serializer(){}

	void packVoid()						{m_buf.push_back( (char)TypeVoid);}
	void packScalar( const int8_t& value)			{m_buf.push_back( (char)TypeUInt8); packAtomicValue( value);}
	void packScalar( const int16_t& value)			{m_buf.push_back( (char)TypeUInt16); packAtomicValue( value);}
	void packScalar( const int32_t& value)			{m_buf.push_back( (char)TypeUInt32); packAtomicValue( value);}
	void packScalar( const int64_t& value)			{m_buf.push_back( (char)TypeUInt64); packAtomicValue( value);}
	void packScalar( const uint8_t& value)			{m_buf.push_back( (char)TypeUInt8); packAtomicValue( value);}
	void packScalar( const uint16_t& value)			{m_buf.push_back( (char)TypeUInt16); packAtomicValue( value);}
	void packScalar( const uint32_t& value)			{m_buf.push_back( (char)TypeUInt32); packAtomicValue( value);}
	void packScalar( const uint64_t& value)			{m_buf.push_back( (char)TypeUInt64); packAtomicValue( value);}
	void packScalar( const float& value)			{m_buf.push_back( (char)TypeFloat); packAtomicValue( value);}
	void packScalar( const double& value)			{m_buf.push_back( (char)TypeDouble); packAtomicValue( value);}
	void packBool( const bool& value)			{m_buf.push_back( (char)TypeBool); packAtomicValue( value);}
	void packString( const std::string& value)		{m_buf.push_back( (char)TypeString); packAtomicValue( value.size()); packBytes( value.c_str(), value.size());}
	void packBuffer( const char* buf, std::size_t size)	{m_buf.push_back( (char)TypeString); packAtomicValue( size); packBytes( buf, size);}
	void packCharp( const char* buf)			{packString( buf);}
	void packCharpp( const char** buf)			{std::size_t bi=0; if (!buf[bi]) packVoid(); for (;buf[bi]; ++bi) {openIndex(bi); packString(buf[bi]); close();}}
	void openIndex( const std::size_t& value)		{m_buf.push_back( (char)TypeOpenIndex); packAtomicValue( value);}
	void openTag( const std::string& name)			{m_buf.push_back( (char)TypeOpenTag); packAtomicValue( name.size()); packBytes( name.c_str(), name.size());}
	void close()						{m_buf.push_back( (char)TypeClose);}

	const std::string& content() const
	{
		return m_buf;
	}


private:
	template <typename Scalar>
	void packAtomicValue( const Scalar& value)
	{
		Scalar value_n = ByteOrder<Scalar>::hton( value);
		m_buf.append( (const char*)&value_n, sizeof(value_n));
	}

	void packBytes( const void* ptr, std::size_t size)
	{
		m_buf.append( (const char*)ptr, size);
	}

private:
	std::string m_buf;
};


class Deserializer
{
public:
	static std::vector<TraceElement> deserialize( const char* struct_, std::size_t structSize_);
};
}
#endif

