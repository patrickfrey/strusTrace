/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of inspecting elements of logged traces
/// \file traceViewer.cpp
#include "traceViewer.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "serialize.hpp"
#include "strus/errorBufferInterface.hpp"

using namespace strus;

const char* TraceViewer::getClassName( const TraceClassId& classId) const
{
	if (!classId) return 0;
	if (classId >= m_classnamear.size())
	{
		m_errorhnd->report(_TXT("trace viewer illegal class id: %u"), (unsigned int)classId);
		return 0;
	}
	return m_classnamear[ classId-1].c_str();
}

const char* TraceViewer::getMethodName( const TraceClassId& classId, const TraceMethodId& methodId) const
{
	try
	{
		MethodNameInvMap::const_iterator mi = m_methodnameinvmap.find( MethodIdRef( classId, methodId));
		if (mi == m_methodnameinvmap.end())
		{
			m_errorhnd->report(_TXT("trace viewer illegal method id: %u/%u"), (unsigned int)classId, (unsigned int)methodId);
			return 0;
		}
		return mi->second.c_str();
	}
	CATCH_ERROR_MAP_RETURN( "trace viewer error getting method name", *m_errorhnd, 0)
}

TraceClassId TraceViewer::getClassId( const char* className) const
{
	try
	{
		ClassNameMap::const_iterator ci = m_classnamemap.find( className);
		if (ci == m_classnamemap.end())
		{
			m_errorhnd->report(_TXT("trace viewer illegal class name: %s"), className);
			return 0;
		}
		return ci->second;
	}
	CATCH_ERROR_MAP_RETURN( "trace viewer error getting method name", *m_errorhnd, 0)
}

TraceMethodId TraceViewer::getMethodId( const TraceClassId& classId, const char* methodName) const
{
	try
	{
		MethodNameMap::const_iterator mi = m_methodnamemap.find( MethodNameRef( classId, methodName));
		if (mi == m_methodnamemap.end())
		{
			m_errorhnd->report(_TXT("trace viewer illegal method name reference: %u/%s"), (unsigned int)classId, methodName);
			return 0;
		}
		return mi->second;
	}
	CATCH_ERROR_MAP_RETURN( "trace viewer error getting method name", *m_errorhnd, 0)
}

std::vector<TraceElement> TraceViewer::unpackElements( const char* packedStruct, std::size_t packedStructSize) const
{
	try
	{
		return Deserializer::deserialize( packedStruct, packedStructSize);
	}
	CATCH_ERROR_MAP_RETURN( "trace viewer error getting method name", *m_errorhnd, std::vector<TraceElement>())
}



