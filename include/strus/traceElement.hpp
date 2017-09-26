/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Element type used to describe traced structures
/// \file traceElement.hpp
#ifndef _STRUS_TRACE_ELEMENT_HPP_INCLUDED
#define _STRUS_TRACE_ELEMENT_HPP_INCLUDED
#include <string>
#include <cstring>
#include "strus/base/stdint.h"

namespace strus
{

typedef unsigned int TraceObjectId;		///< Unique object identifier
typedef unsigned int TraceTimeCounter;		///< Unique timestamp of logged events
typedef std::size_t TraceLogRecordHandle;	///< Handle of a trace log entry

/// \brief Element type used to describe traced structures. Any atomic value or structure is described as sequence of trace elements
struct TraceElement
{
	typedef int64_t IntType;
	typedef uint64_t UIntType;

	enum Type
	{
		TypeVoid,
		TypeInt,
		TypeUInt,
		TypeDouble,
		TypeBool,
		TypeObject,
		TypeString,
		TypeOpenIndex,
		TypeOpenTag,
		TypeClose
	};

	union Value
	{
		UIntType UInt;
		IntType Int;
		double Double;
		bool Bool;
		std::size_t Index;
		struct { TraceObjectId Id; const char* Class; } Obj;
		struct { const char* Ptr; std::size_t Size; } String;
	};

	/// \brief Get the element type
	Type type() const
	{
		return m_type;
	}
	/// \brief Get the element value
	Value value() const
	{
		return m_value;
	}

	/// \brief Default constructor
	TraceElement() :m_type(TypeVoid)				{m_value.UInt = 0;}
	/// \brief Constructor
	TraceElement( IntType value_) :m_type(TypeInt)			{m_value.Int = value_;}
	/// \brief Constructor
	TraceElement( UIntType value_) :m_type(TypeUInt)		{m_value.UInt = value_;}
	/// \brief Constructor
	TraceElement( double value_) :m_type(TypeDouble)		{m_value.Double = value_;}
	/// \brief Constructor
	TraceElement( bool value_) :m_type(TypeBool)			{m_value.Bool = value_;}
	/// \brief Constructor
	TraceElement( Type type_, std::size_t index_) :m_type(type_)	{m_value.Index = index_;}
	TraceElement( Type type_, TraceObjectId oid_, const char* cid_)
		:m_type(type_) {m_value.Obj.Class = cid_; m_value.Obj.Id = oid_;}
	/// \brief Constructor
	TraceElement( Type type_, const char* ptr_, std::size_t size_)
		:m_type(type_) {m_value.String.Ptr = ptr_; m_value.String.Size = size_;}
	TraceElement( Type type_, const char* ptr_)
		:m_type(type_) {m_value.String.Ptr = ptr_; m_value.String.Size = ptr_?std::strlen(ptr_):0;}
	TraceElement( Type type_)
		:m_type(type_) {m_value.UInt = 0;}

	/// \brief Copy constructor
	TraceElement( const TraceElement& o)
	{
		std::memcpy( this, &o, sizeof(*this));
	}

private:
	Type m_type;
	Value m_value;
};

} //namespace
#endif

