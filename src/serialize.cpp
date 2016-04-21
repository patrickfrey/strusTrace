/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "serialize.hpp"
#include "internationalization.hpp"
#include "strus/base/hton.hpp"

using namespace strus;

template <typename Scalar>
static Scalar unpackAtomicValue( char const*& si, const char* se)
{
	Scalar rt;
	if (si + sizeof(Scalar) > se)
	{
		throw strus::runtime_error(_TXT("deserializer read at end of buffer"));
	}
	std::memcpy( &rt, si, sizeof(Scalar));
	si += sizeof(Scalar);
	return ByteOrder<Scalar>::ntoh(rt);
}

static Serializer::ValueType unpackMarker( char const*& si, const char* se)
{
	if (si == se)
	{
		throw strus::runtime_error(_TXT("deserializer read at end of buffer"));
	}
	if ((unsigned char)Serializer::NofSerializeValueType <= (unsigned char)*si)
	{
		throw strus::runtime_error(_TXT("deserializer read unknown value type marker"));
	}
	return (Serializer::ValueType)*si++;
}

static void unpackBytesWithSize( char const*& si, const char* se, const char*& out_ptr, std::size_t& out_size)
{
	out_size = unpackAtomicValue<SizeType>( si, se);
	if (si+out_size > se)
	{
		throw strus::runtime_error(_TXT("deserializer read at end of buffer"));
	}
	out_ptr = si;
	si += out_size;
}

std::vector<TraceElement> Deserializer::deserialize( const char* struct_, std::size_t structSize_)
{
	std::vector<TraceElement> rt;
	char const* si = struct_;
	const char* se = struct_ + structSize_;
	const char* strptr;
	std::size_t strsize;

	while (si != se)
	{
		switch (unpackMarker(si,se))
		{
			case Serializer::TypeVoid:
				rt.push_back( TraceElement());
				break;
			case Serializer::TypeInt8:
				rt.push_back( TraceElement( (TraceElement::IntType)unpackAtomicValue<int8_t>( si, se)));
				break;
			case Serializer::TypeUInt8:
				rt.push_back( TraceElement( (TraceElement::UIntType)unpackAtomicValue<uint8_t>( si, se)));
				break;
			case Serializer::TypeInt16:
				rt.push_back( TraceElement( (TraceElement::IntType)unpackAtomicValue<int16_t>( si, se)));
				break;
			case Serializer::TypeUInt16:
				rt.push_back( TraceElement( (TraceElement::UIntType)unpackAtomicValue<uint16_t>( si, se)));
				break;
			case Serializer::TypeInt32:
				rt.push_back( TraceElement( (TraceElement::IntType)unpackAtomicValue<int32_t>( si, se)));
				break;
			case Serializer::TypeUInt32:
				rt.push_back( TraceElement( (TraceElement::UIntType)unpackAtomicValue<int32_t>( si, se)));
				break;
			case Serializer::TypeInt64:
				rt.push_back( TraceElement( (TraceElement::IntType)unpackAtomicValue<int64_t>( si, se)));
				break;
			case Serializer::TypeUInt64:
				rt.push_back( TraceElement( (TraceElement::UIntType)unpackAtomicValue<uint64_t>( si, se)));
				break;
			case Serializer::TypeFloat:
				rt.push_back( TraceElement( unpackAtomicValue<float>( si, se)));
				break;
			case Serializer::TypeDouble:
				rt.push_back( TraceElement( unpackAtomicValue<double>( si, se)));
				break;
			case Serializer::TypeBool:
				rt.push_back( TraceElement( unpackAtomicValue<bool>( si, se)));
				break;
			case Serializer::TypeObject:
			{
				TraceClassId cid = unpackAtomicValue<TraceClassId>( si, se);
				TraceObjectId oid = unpackAtomicValue<TraceObjectId>( si, se);
				rt.push_back( TraceElement( TraceElement::TypeObject, cid, oid));
				break;
			}
			case Serializer::TypeString:
				unpackBytesWithSize( si, se, strptr, strsize);
				rt.push_back( TraceElement( TraceElement::TypeString, strptr, strsize));
				break;
			case Serializer::TypeOpenIndex:
				rt.push_back( TraceElement( TraceElement::TypeOpenIndex, (SizeType)unpackAtomicValue<SizeType>( si, se)));
				break;
			case Serializer::TypeOpenTag:
				unpackBytesWithSize( si, se, strptr, strsize);
				rt.push_back( TraceElement( TraceElement::TypeOpenTag, strptr, strsize));
				break;
			case Serializer::TypeClose:
				rt.push_back( TraceElement( TraceElement::TypeClose));
				break;
		}
	}
	return rt;
}
