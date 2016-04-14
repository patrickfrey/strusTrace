/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Structure describing a record (method call) of a strus call trace
/// \file traceRecord.hpp
#ifndef _STRUS_TRACE_RECORD_HPP_INCLUDED
#define _STRUS_TRACE_RECORD_HPP_INCLUDED
#include "strus/traceElement.hpp"
#include <stdint.h>

namespace strus
{

/// \brief One logged data row (method call)
class TraceRecord
{
public:
	/// \brief Constructor
	TraceRecord(
			TraceClassId classId_,
			TraceMethodId methodId_,
			TraceObjectId objId_,
			TraceTimeCounter time_,
			TraceTreeDepth depth_,
			const char* packedParameter_,
			std::size_t packedParameterSize_)
		:m_classId(classId_)
		,m_methodId(methodId_)
		,m_objId(objId_)
		,m_startTime(time_)
		,m_endTime(0)
		,m_depth(depth_)
		,m_packedParameter(packedParameter_)
		,m_packedParameterSize(packedParameterSize_){}

	/// \brief Copy constructor
	TraceRecord( const TraceRecord& o)
		:m_classId(o.m_classId)
		,m_methodId(o.m_methodId)
		,m_objId(o.m_objId)
		,m_startTime(o.m_startTime)
		,m_endTime(o.m_endTime)
		,m_depth(o.m_depth)
		,m_packedParameter(o.m_packedParameter)
		,m_packedParameterSize(o.m_packedParameterSize){}

	/// \brief Get the caller internal class id
	/// \return the internal interface identifier starting with 1
	TraceClassId classId() const		{return m_classId;}
	/// \brief Get the called internal method id
	/// \return the internal method identifier starting with 1
	TraceMethodId methodId() const		{return m_methodId;}
	/// \brief Get the internal object id
	/// \return the internal object identifier starting with 1
	TraceObjectId objId() const		{return m_objId;}
	/// \brief Get the start time counter of this method call
	/// \return the time count starting with 1
	TraceTimeCounter startTime() const	{return m_startTime;}
	/// \brief Get the termination time counter of this method call
	/// \return the time count starting with 1
	TraceTimeCounter endTime() const	{return m_endTime;}
	/// \brief Get the depht in the call dependency tree
	/// \return the depht starting with 0
	TraceTreeDepth depth() const		{return m_depth;}
	/// \brief Get the packed parameter structure of the call
	/// \return the serialized parameter structure
	const char* packedParameter()		{return m_packedParameter;}
	/// \brief Get the size of packed parameter structure of the call in bytes
	/// \return the size of the serialized parameter structure
	std::size_t packedParameterSize()	{return m_packedParameterSize;}

	/// \brief Set the time of termination of the method
	void setEndCall(
		const TraceTimeCounter& endTime_,
		const char* packedParameter_,
		std::size_t packedParameterSize_)
	{
		m_endTime = endTime_;
		m_packedParameter = packedParameter_;
		m_packedParameterSize = packedParameterSize_;
	}

private:
	TraceClassId m_classId;
	TraceMethodId m_methodId;
	TraceObjectId m_objId;
	TraceTimeCounter m_startTime;
	TraceTimeCounter m_endTime;
	TraceTreeDepth m_depth;
	const char* m_packedParameter;
	std::size_t m_packedParameterSize;
};

} //namespace
#endif

