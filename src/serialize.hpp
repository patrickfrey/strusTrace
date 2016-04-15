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
#include "strus/index.hpp"
#include "strus/traceElement.hpp"
#include "strus/traceLoggerInterface.hpp"
#include <string>
#include <vector>
#include <cstring>
#include <map>

namespace strus
{
typedef uint32_t SizeType;

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
	void packInt( const int& value)				{m_buf.push_back( (char)TypeInt32); packAtomicValue( (int32_t)value);}
	void packInt8( const int8_t& value)			{m_buf.push_back( (char)TypeInt8); packAtomicValue( value);}
	void packInt16( const int16_t& value)			{m_buf.push_back( (char)TypeInt16); packAtomicValue( value);}
	void packInt32( const int32_t& value)			{m_buf.push_back( (char)TypeInt32); packAtomicValue( value);}
	void packInt64( const int64_t& value)			{m_buf.push_back( (char)TypeInt64); packAtomicValue( value);}
	void packUInt( const unsigned int& value)		{m_buf.push_back( (char)TypeInt32); packAtomicValue( (uint32_t)value);}
	void packUInt8( const uint8_t& value)			{m_buf.push_back( (char)TypeUInt8); packAtomicValue( value);}
	void packUInt16( const uint16_t& value)			{m_buf.push_back( (char)TypeUInt16); packAtomicValue( value);}
	void packUInt32( const uint32_t& value)			{m_buf.push_back( (char)TypeUInt32); packAtomicValue( value);}
	void packUInt64( const uint64_t& value)			{m_buf.push_back( (char)TypeUInt64); packAtomicValue( value);}
	void packSize( const std::size_t& value)		{m_buf.push_back( (char)TypeUInt32); packAtomicValue( (uint32_t)value);}
	void packIndex( const Index& value)			{m_buf.push_back( (char)TypeUInt32); packAtomicValue( (Index)value);}
	void packGlobalCounter( const GlobalCounter& value)	{m_buf.push_back( (char)TypeUInt64); packAtomicValue( (GlobalCounter)value);}
	void packFloat( const float& value)			{m_buf.push_back( (char)TypeFloat); packAtomicValue( value);}
	void packDouble( const double& value)			{m_buf.push_back( (char)TypeDouble); packAtomicValue( value);}
	void packBool( const bool& value)			{m_buf.push_back( (char)TypeBool); packAtomicValue( value);}
	void packString( const std::string& value)		{m_buf.push_back( (char)TypeString); packSize( value.size()); packBytes( value.c_str(), value.size());}
	void packBuffer( const char* buf, std::size_t size)	{m_buf.push_back( (char)TypeString); packSize( size); packBytes( buf, size);}
	void packCharp( const char* buf)			{packString( buf);}
	void packCharpp( const char** buf)			{std::size_t bi=0; if (!buf[bi]) packVoid(); for (;buf[bi]; ++bi) {openIndex(bi); packString(buf[bi]); close();}}
	void openIndex( const std::size_t& value)		{m_buf.push_back( (char)TypeOpenIndex); packSize( value);}
	void openTag( const std::string& name)			{m_buf.push_back( (char)TypeOpenTag); packSize( name.size()); packBytes( name.c_str(), name.size());}
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

