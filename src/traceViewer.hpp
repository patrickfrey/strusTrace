/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of inspecting elements of logged traces
/// \file traceViewer.hpp
#ifndef _STRUS_TRACE_VIEWER_IMPLEMENTATION_HPP_INCLUDED
#define _STRUS_TRACE_VIEWER_IMPLEMENTATION_HPP_INCLUDED
#include "strus/traceViewerInterface.hpp"
#include <map>
#include <cstring>

namespace strus
{
/// \brief Forward declaration
class ErrorBufferInterface;

/// \brief Class for inspecting logged traces
class TraceViewer
	:public TraceViewerInterface
{
public:
	/// \brief Constructor
	explicit TraceViewer( ErrorBufferInterface* errorhnd_)
		:m_errorhnd(errorhnd_){}

	/// \brief Destructor
	virtual ~TraceViewer(){}

	virtual const char* getClassName( const TraceClassId& classid) const;
	virtual const char* getMethodName( const TraceClassId& classid, const TraceMethodId& methodid) const;
	virtual TraceClassId getClassId( const char* classname) const;
	virtual TraceMethodId getMethodId( const TraceClassId& id, const char* methodname) const;

	virtual std::vector<TraceElement> unpackElements( const char* packedStruct, std::size_t packedStructSize) const;

private:
	void fillMaps();

	struct MethodNameRef
	{
		MethodNameRef( const TraceClassId& classid_, const std::string& methodname_)
			:classid(classid_),methodname(methodname_){}
		MethodNameRef( const MethodNameRef& o)
			:classid(o.classid),methodname(o.methodname){}

		bool operator < (const MethodNameRef& o) const
		{
			if (classid == o.classid) return std::strcmp(methodname.c_str(), o.methodname.c_str()) < 0;
			return classid < o.classid;
		}

		TraceClassId classid;
		std::string methodname;
	};

	struct MethodIdRef
	{
		MethodIdRef( const TraceClassId& classid_, const TraceMethodId& methodid_)
			:classid(classid_),methodid(methodid_){}
		MethodIdRef( const MethodIdRef& o)
			:classid(o.classid),methodid(o.methodid){}

		bool operator < (const MethodIdRef& o) const
		{
			if (classid == o.classid) return methodid < o.methodid;
			return classid < o.classid;
		}

		TraceClassId classid;
		TraceMethodId methodid;
	};

	struct EnumIdRef
	{
		EnumIdRef( const TraceEnumTypeId& typeId_, const TraceEnumValueId& valueId_)
			:typeId(typeId_),valueId(valueId_){}
		EnumIdRef( const EnumIdRef& o)
			:typeId(o.typeId),valueId(o.valueId){}

		bool operator < (const EnumIdRef& o) const
		{
			if (typeId == o.typeId) return valueId < o.valueId;
			return typeId < o.typeId;
		}

		TraceEnumTypeId typeId;
		TraceEnumValueId valueId;
	};

	ErrorBufferInterface* m_errorhnd;
	typedef std::map<std::string,TraceClassId> ClassNameMap; 
	typedef std::map<MethodNameRef,TraceMethodId> MethodNameMap; 
	typedef std::map<MethodIdRef,std::string> MethodNameInvMap; 
	typedef std::map<EnumIdRef,std::string> EnumNameMap; 

	ClassNameMap m_classnamemap;
	std::vector<std::string> m_classnamear;

	MethodNameMap m_methodnamemap;
	MethodNameInvMap m_methodnameinvmap;
};

}//namespace
#endif


