/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Structure describing a query for inspecting elements of a strus call trace
/// \file traceElement.hpp
#ifndef _STRUS_TRACE_QUERY_HPP_INCLUDED
#define _STRUS_TRACE_QUERY_HPP_INCLUDED
#include "strus/traceElement.hpp"

namespace strus
{

/// \brief Structure describing a query on a trace log
class TraceQuery
{
public:
	/// \brief Constructor
	TraceQuery()
		:m_classId(0),m_methodId(0),m_objId(0),m_time_from(0),m_time_to(0),m_depth_from(0),m_depth_to(0){}
	/// \brief Copy constructor
	TraceQuery( const TraceQuery& o)
		:m_classId(o.m_classId),m_methodId(o.m_methodId),m_objId(o.m_objId),m_time_from(o.m_time_from),m_time_to(o.m_time_to),m_depth_from(o.m_depth_from),m_depth_to(o.m_depth_to){}

	/// \brief Define a caller class restriction
	void restrictClassId( const TraceClassId& classId_)	{m_classId=classId_;}
	/// \brief Define a caller method restriction
	void restrictMethodId( const TraceMethodId& methodId_)	{m_methodId=methodId_;}
	/// \brief Define a caller object restriction
	void restrictObjId( const TraceObjectId& objId_)	{m_objId=objId_;}
	/// \brief Define a call time restriction
	void restrictTime( const TraceTimeCounter& from_, const TraceTimeCounter& to_)	{m_time_from=from_; m_time_to=to_;}
	/// \brief Define a call depth restriction
	void restrictDepth( const TraceTreeDepth& from_, const TraceTreeDepth& to_)	{m_depth_from=from_; m_depth_to=to_;}

	/// \brief Get the caller class identifier
	TraceClassId classId() const				{return m_classId;}
	/// \brief Get the caller method identifier
	TraceMethodId methodId() const				{return m_methodId;}
	/// \brief Get the caller object identifier
	TraceObjectId objId() const				{return m_objId;}
	/// \brief Get the start time of the queried trace
	TraceTimeCounter time_from() const			{return m_time_from;}
	/// \brief Get the end time of the queried trace
	TraceTimeCounter time_to() const			{return m_time_to;}
	/// \brief Get the start depth of the queried trace
	TraceTreeDepth depth_from() const			{return m_depth_from;}
	/// \brief Get the end depth of the queried trace
	TraceTreeDepth depth_to() const				{return m_depth_to;}

private:
	TraceClassId m_classId;
	TraceMethodId m_methodId;
	TraceObjectId m_objId;
	TraceTimeCounter m_time_from;
	TraceTimeCounter m_time_to;
	TraceTreeDepth m_depth_from;
	TraceTreeDepth m_depth_to;
};

} //namespace
#endif

