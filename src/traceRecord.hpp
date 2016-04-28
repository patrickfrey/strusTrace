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

namespace strus
{

/// \brief One logged data row (method call)
class TraceRecord
{
public:
	/// \brief Constructor
	TraceRecord(
			const char* className_,
			const char* methodName_,
			TraceObjectId objId_,
			TraceTimeCounter time_)
		:m_className(className_)
		,m_methodName(methodName_)
		,m_objId(objId_)
		,m_startTime(time_)
		,m_endTime(0)
		,m_parameterIdx(0)
		,m_parameterSize(0){}

	/// \brief Copy constructor
	TraceRecord( const TraceRecord& o)
		:m_className(o.m_className)
		,m_methodName(o.m_methodName)
		,m_objId(o.m_objId)
		,m_startTime(o.m_startTime)
		,m_endTime(o.m_endTime)
		,m_parameterIdx(o.m_parameterIdx)
		,m_parameterSize(o.m_parameterSize){}

	/// \brief Get the caller internal class id
	/// \return the internal interface identifier starting with 1
	const char* className() const			{return m_className;}
	/// \brief Get the called internal method id
	/// \return the internal method identifier starting with 1
	const char* methodName() const			{return m_methodName;}
	/// \brief Get the internal object id
	/// \return the internal object identifier starting with 1
	TraceObjectId objId() const			{return m_objId;}
	/// \brief Get the start time counter of this method call
	/// \return the time count starting with 1
	TraceTimeCounter startTime() const		{return m_startTime;}
	/// \brief Get the termination time counter of this method call
	/// \return the time count starting with 1
	TraceTimeCounter endTime() const		{return m_endTime;}
	/// \brief Get the packed parameter structure of the call
	/// \return the serialized parameter structure
	std::size_t parameterIdx() const		{return m_parameterIdx;}
	/// \brief Get the size of packed parameter structure of the call in bytes
	/// \return the size of the serialized parameter structure
	std::size_t parameterSize() const		{return m_parameterSize;}

public:/*TraceLoggerInterface*/
	/// \brief Set the time of termination of the method
	void setEndCall(
		const TraceTimeCounter& endTime_,
		std::size_t parameterIdx_,
		std::size_t parameterSize_)
	{
		m_endTime = endTime_;
		m_parameterIdx = parameterIdx_;
		m_parameterSize = parameterSize_;
	}

private:
	const char* m_className;
	const char* m_methodName;
	TraceObjectId m_objId;
	TraceTimeCounter m_startTime;
	TraceTimeCounter m_endTime;
	std::size_t m_parameterIdx;
	std::size_t m_parameterSize;
};

} //namespace
#endif

