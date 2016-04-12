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
#include "strus/reference.hpp"
#include <map>
#include <cstring>

namespace strus
{
/// \brief Forward declaration
class ErrorBufferInterface;
/// \brief Forward declaration
class TraceLogger;

/// \brief Class for inspecting logged traces
class TraceViewer
	:public TraceViewerInterface
{
public:
	/// \brief Constructor
	/// \param[in] errorhnd_ error buffer interface
	/// \param[in] logger_ logging interface (ownership passed to this) for inspecting values
	explicit TraceViewer( ErrorBufferInterface* errorhnd_, const TraceLogger* logger_)
		:m_errorhnd(errorhnd_),m_logger(logger_){}

	/// \brief Destructor
	virtual ~TraceViewer(){}

	virtual std::vector<TraceRecord> listMethodCalls(
			const TraceQuery& query,
			std::size_t startIndex,
			std::size_t maxNofResults) const;

	virtual TraceTimeCounter getObjectCreationTime(
			const TraceObjectId& objId) const;

private:
	ErrorBufferInterface* m_errorhnd;
	const TraceLogger* m_logger;
};

}//namespace
#endif


