/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Interface for logging and querying call traces
/// \file traceLoggerInterface.hpp
#ifndef _STRUS_TRACE_LOGGER_INTERFACE_HPP_INCLUDED
#define _STRUS_TRACE_LOGGER_INTERFACE_HPP_INCLUDED
#include <string>
#include <vector>

namespace strus
{

typedef unsigned char TraceClassId;
typedef unsigned char TraceMethodId;
typedef unsigned int TraceObjectId;
typedef unsigned int TraceTimeCounter;
typedef unsigned int TraceTreeDepth;
typedef unsigned char TraceEnumTypeId;
typedef unsigned char TraceEnumValueId;

typedef std::size_t TraceLogRecordHandle;

/// \brief Interface providing a storage object builder interface with tracing and querying of traces
class TraceLoggerInterface
{
public:
	/// \brief Destructor
	virtual ~TraceLoggerInterface(){}

	/// \brief One logged data row
	class Record
	{
	public:
		/// \brief Constructor
		Record(
				TraceClassId classId_,
				TraceMethodId methodId_,
				TraceObjectId objId_,
				TraceTimeCounter time_,
				TraceTreeDepth depth_,
				TraceObjectId resultObjId_,
				const char* packedParameter_,
				std::size_t packedParameterSize_)
			:m_classId(classId_)
			,m_methodId(methodId_)
			,m_objId(objId_)
			,m_startTime(time_)
			,m_depth(depth_)
			,m_resultObjId(resultObjId_)
			,m_packedParameter(packedParameter_)
			,m_packedParameterSize(packedParameterSize_){}

		Record( const Record& o)
			:m_classId(o.m_classId)
			,m_methodId(o.m_methodId)
			,m_objId(o.m_objId)
			,m_startTime(o.m_startTime)
			,m_endTime(o.m_endTime)
			,m_depth(o.m_depth)
			,m_resultObjId(o.m_resultObjId)
			,m_packedParameter(o.m_packedParameter){}

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
		/// \brief Get the internal object id of the returned value
		/// \return the object id or 0 if not defined
		TraceObjectId resultObjId() const	{return m_resultObjId;}
		/// \brief Get the packed parameter structure of the call
		/// \return the serialized parameter structure
		const char* packedParameter()		{return m_packedParameter;}
		/// \brief Get the size of packed parameter structure of the call in bytes
		/// \return the size of the serialized parameter structure
		std::size_t packedParameterSize()	{return m_packedParameterSize;}

		/// \brief Set the time of termination of the method
		void setEndTime( const TraceTimeCounter& endTime_)
		{
			m_endTime = endTime_;
		}

	private:
		TraceClassId m_classId;
		TraceMethodId m_methodId;
		TraceObjectId m_objId;
		TraceTimeCounter m_startTime;
		TraceTimeCounter m_endTime;
		TraceTreeDepth m_depth;
		TraceObjectId m_resultObjId;
		const char* m_packedParameter;
		std::size_t m_packedParameterSize;
	};

	/// \brief Structure describing a query on a trace log
	class Query
	{
	public:
		/// \brief Constructor
		Query()
			:m_classId(0),m_methodId(0),m_objId(0),m_time_from(0),m_time_to(0),m_depth_from(0),m_depth_to(0){}

		/// \brief Define a class restriction
		void restrictClassId( const TraceClassId& classId_)	{m_classId=classId_;}
		/// \brief Define a method restriction
		void restrictMethodId( const TraceMethodId& methodId_)	{m_methodId=methodId_;}
		/// \brief Define an object restriction
		void restrictObjId( const TraceObjectId& objId_)	{m_objId=objId_;}
		/// \brief Define a time restriction
		void restrictTime( const TraceTimeCounter& from_, const TraceTimeCounter& to_)	{m_time_from=from_; m_time_to=to_;}
		/// \brief Define a depth restriction
		void restrictDepth( const TraceTreeDepth& from_, const TraceTreeDepth& to_)	{m_depth_from=from_; m_depth_to=to_;}
		/// \brief Define a result object restriction
		void restrictResultObjId( const TraceObjectId& objId_)	{m_resultObjId=objId_;}

		bool match( const Record& rec) const;
		TraceTimeCounter time_from() const			{return m_time_from;}
		TraceTimeCounter time_to() const			{return m_time_to;}

	private:
		TraceClassId m_classId;
		TraceMethodId m_methodId;
		TraceObjectId m_objId;
		TraceTimeCounter m_time_from;
		TraceTimeCounter m_time_to;
		TraceTreeDepth m_depth_from;
		TraceTreeDepth m_depth_to;
		TraceObjectId m_resultObjId;
	};

	/// \brief Writes an entry to the method call log
	/// \param[in] classId identifier of the caller object class
	/// \param[in] methodId identifier of the method called in the context of the class
	/// \param[in] objId object identifier of the caller
	/// \param[in] resultObjId identifier of the result object of the call or 0, if the result is not an object
	/// \param[in] packedParameter packed parameter string
	/// \return handle of the log message written. Used to reference the record in logMethodTermination
	virtual TraceLogRecordHandle
		logMethodCall(
			TraceClassId classId,
			TraceMethodId methodId,
			TraceObjectId objId,
			TraceObjectId resultObjId,
			const std::string& packedParameter)=0;

	/// \brief Log the termination of a method call
	/// \param[in] loghnd handl of the record that specifies the method call, returned by logMethodCall.
	virtual void logMethodTermination(
			TraceLogRecordHandle loghnd)=0;

	/// \brief Open a new sub branch in the tree (depth+1)
	virtual void logOpenBranch()=0;

	/// \brief Close the current sub branch in the tree (depth-1)
	virtual void logCloseBranch()=0;

	/// \brief Retrieves all method call logs matching to a query
	/// \param[in] query method call log query
	/// \param[in] startIndex index (starting with 0) of first result
	/// \param[in] maxNofResults maximum number of records to retrieve
	/// \return the list of matching records
	virtual std::vector<Record> listMethodCalls(
			const Query& query,
			std::size_t startIndex,
			std::size_t maxNofResults)=0;
};

}//namespace
#endif

