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
#include <stdint.h>

namespace strus
{

typedef unsigned char TraceClassId;		///< Id of an interface class subject to logging (enum)
typedef unsigned char TraceMethodId;		///< Id of a method of an interface class subject to logging (enum)
typedef unsigned int TraceObjectId;		///< Unique object identifier
typedef unsigned int TraceTimeCounter;		///< Unique timestamp of logged events
typedef unsigned int TraceTreeDepth;		///< Counter value of the depth in the call tree
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
		TypeFloat,
		TypeDouble,
		TypeBool,
		TypeString,
		TypeOpenIndex,
		TypeOpenTag,
		TypeClose
	};

	union Value
	{
		UIntType UInt;
		IntType Int;
		float Float;
		double Double;
		bool Bool;
		std::size_t Index;
		const char* String;
	};

	/// \brief Get the element type
	Type type() const;
	/// \brief Get the element value
	Value value() const;
	/// \brief Get the element size in bytes (for strings)
	std::size_t size() const;

	/// \brief Default constructor
	TraceElement() :m_type(TypeVoid),m_size(0)			{}
	/// \brief Constructor
	TraceElement( IntType value_) :m_type(TypeInt),m_size(0)	{m_value.Int = value_;}
	/// \brief Constructor
	TraceElement( UIntType value_) :m_type(TypeUInt),m_size(0)	{m_value.UInt = value_;}
	/// \brief Constructor
	TraceElement( float value_) :m_type(TypeFloat),m_size(0)	{m_value.Float = value_;}
	/// \brief Constructor
	TraceElement( double value_) :m_type(TypeDouble),m_size(0)	{m_value.Double = value_;}
	/// \brief Constructor
	TraceElement( bool value_) :m_type(TypeBool),m_size(0)		{m_value.Bool = value_;}
	/// \brief Constructor
	TraceElement( Type type_, std::size_t index_)
		:m_type(type_),m_size(0) {m_value.Index = index_;}
	/// \brief Constructor
	TraceElement( Type type_, const char* ptr_, std::size_t size_)
		:m_type(type_),m_size(size_) {m_value.String = ptr_;}
	TraceElement( Type type_)
		:m_type(type_),m_size(0) {}

	/// \brief Copy constructor
	TraceElement( const TraceElement& o)
		:m_type(o.m_type),m_value(o.m_value),m_size(o.m_size){}

private:
	Type m_type;
	Value m_value;
	std::size_t m_size;
};

} //namespace
#endif

