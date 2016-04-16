/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Interface of the maps of call trace identifiers to their internal representation as number and back
/// \file traceIdMap.hpp
#ifndef _STRUS_TRACE_IDMAP_IMPLEMENTATION_HPP_INCLUDED
#define _STRUS_TRACE_IDMAP_IMPLEMENTATION_HPP_INCLUDED
#include "strus/traceIdMapInterface.hpp"
#include <map>
#include <cstring>

namespace strus
{

/// \brief Forward declaration
class ErrorBufferInterface;

/// \brief Class for inspecting logged traces
class TraceIdMap
	:public TraceIdMapInterface
{
public:
	/// \brief Constructor
	/// \param[in] errorhnd_ error buffer interface
	/// \param[in] logger_ logging interface (ownership passed to this) for inspecting values
	explicit TraceIdMap( ErrorBufferInterface* errorhnd_);

	/// \brief Destructor
	virtual ~TraceIdMap(){}

	virtual const char* getClassName(
			const TraceClassId& classid) const;
	virtual const char* getMethodName(
			const TraceClassId& classid,
			const TraceMethodId& methodid) const;
	virtual TraceClassId getClassId(
			const char* classname) const;
	virtual TraceMethodId getMethodId(
			const TraceClassId& id,
			const char* methodname) const;

	virtual std::vector<TraceElement> unpackElements(
			const char* packedStruct,
			std::size_t packedStructSize) const;

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

	ErrorBufferInterface* m_errorhnd;
	typedef std::map<std::string,TraceClassId> ClassNameMap; 
	typedef std::map<MethodNameRef,TraceMethodId> MethodNameMap; 
	typedef std::map<MethodIdRef,std::string> MethodNameInvMap; 

	ClassNameMap m_classnamemap;
	std::vector<std::string> m_classnamear;

	MethodNameMap m_methodnamemap;
	MethodNameInvMap m_methodnameinvmap;
};

}//namespace
#endif


