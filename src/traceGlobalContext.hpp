/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Global context of the Strus trace
#ifndef _STRUS_TRACE_GLOBAL_CONTEXT_HPP_INCLUDED
#define _STRUS_TRACE_GLOBAL_CONTEXT_HPP_INCLUDED
#include "strus/traceLoggerInterface.hpp"

namespace strus
{
/// \brief Forward declaration
class ErrorBufferInterface;

/// \brief Global context of the Strus trace
class TraceGlobalContext
{
public:
	/// \brief Constructor
	TraceGlobalContext( TraceLoggerInterface* logger_, ErrorBufferInterface* errhnd_)
		:m_errhnd(errhnd_),m_idcnt(0),m_logger(logger_){}
	/// \brief Destructor
	~TraceGlobalContext(){}

	/// \brief Create a new object id (unique for this trace context)
	TraceObjectId createId()
	{
		return ++m_idcnt;
	}
	/// \brief Get the logger to log traces of method calls
	TraceLoggerInterface* logger() const
	{
		return m_logger;
	}
	ErrorBufferInterface* errorbuf() const
	{
		return m_errhnd;
	}

private:
	TraceGlobalContext( const TraceGlobalContext&){}	///< non copyable
	void operator=( const TraceGlobalContext&){}		///< non copyable

private:
	ErrorBufferInterface* m_errhnd;
	TraceObjectId m_idcnt;
	TraceLoggerInterface* m_logger;
};

} //namespace
#endif

