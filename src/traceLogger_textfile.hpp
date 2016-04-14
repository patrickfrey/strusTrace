/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of logging and querying call traces to textfile or stdout
/// \file traceLogger.hpp
#ifndef _STRUS_TRACE_LOGGER_TEXTFILE_IMPLEMENTATION_HPP_INCLUDED
#define _STRUS_TRACE_LOGGER_TEXTFILE_IMPLEMENTATION_HPP_INCLUDED
#include "strus/traceLoggerInterface.hpp"
#include "strus/traceElement.hpp"
#include <string>
#include <cstdlib>

namespace strus
{
///\brief Forward declaration
class ErrorBufferInterface;
///\brief Forward declaration
class TraceViewerInterface;
///\brief Forward declaration
class TraceIdMapInterface;

/// \brief Strus standard call trace logger implementation
class TraceLogger_textfile
	:public TraceLoggerInterface
{
public:
	/// \brief Constructor
	TraceLogger_textfile( ErrorBufferInterface* errorhnd_, const std::string& filename);

	/// \brief Destructor
	virtual ~TraceLogger_textfile();

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

private:
	FILE* m_output;
	ErrorBufferInterface* m_errorhnd;
	TraceTreeDepth m_depth;
	std::string m_indentstr;
	TraceLogRecordHandle m_logcnt;
	TraceIdMapInterface* m_traceIdMap;
};

}//namespace
#endif
