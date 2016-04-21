/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of logging and querying call traces
/// \file TraceLogger_memory.hpp
#ifndef _STRUS_TRACE_LOGGER_IMPLEMENTATION_HPP_INCLUDED
#define _STRUS_TRACE_LOGGER_IMPLEMENTATION_HPP_INCLUDED
#include "strus/traceLoggerInterface.hpp"
#include "strus/traceRecord.hpp"
#include "strus/traceQuery.hpp"
#include <string>
#include <vector>
#include <map>
#include <cstdlib>

namespace strus
{
///\brief Forward declaration
class ErrorBufferInterface;

/// \brief Helper structure to allocate strings as char*
class StringBlock
{
public:
	~StringBlock();
	StringBlock( const char* blk_, std::size_t blksize_);

	const char* ptr() const;
	std::size_t size() const;

	const char* alloc( const char* blk_, std::size_t blksize_);

private:
	StringBlock( const StringBlock& );	//< non copyable
	void operator=( const StringBlock& );	//< non copyable

private:
	char* m_blk;
	std::size_t m_size;
	std::size_t m_allocsize;
};


/// \brief Strus standard call trace logger implementation
class TraceLogger_memory
	:public TraceLoggerInterface
{
public:
	/// \brief Constructor
	explicit TraceLogger_memory( ErrorBufferInterface* errorhnd_)
		:m_errorhnd(errorhnd_),m_depth(0){}

	/// \brief Destructor
	virtual ~TraceLogger_memory();

	virtual TraceLogRecordHandle
		logMethodCall(
			const TraceClassId& classId,
			const TraceMethodId& methodId,
			const TraceObjectId& objId);

	virtual void logObjectCreation(
			const TraceObjectId& objId,
			const TraceLogRecordHandle& loghnd);

	virtual void logMethodTermination(
			const TraceLogRecordHandle& loghnd,
			const std::string& packedParameter);

	virtual void logOpenBranch();
	virtual void logCloseBranch();

	virtual TraceViewerInterface* createViewer() const;

public://TraceViewer:
	std::vector<TraceRecord> listMethodCalls(
			const TraceQuery& query,
			std::size_t startIndex,
			std::size_t maxNofResults) const;

	TraceTimeCounter getObjectCreationTime(
			const TraceObjectId& objId) const;

private:
	ErrorBufferInterface* m_errorhnd;
	std::vector<TraceRecord> m_recordar;
	std::vector<StringBlock*> m_strings;
	TraceTreeDepth m_depth;
	std::map<TraceObjectId,TraceTimeCounter> m_creatmap;
};

}//namespace
#endif

