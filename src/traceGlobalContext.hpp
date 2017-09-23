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
#include "traceObject.hpp"
#include "strus/reference.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/traceLoggerInterface.hpp"
#include "internationalization.hpp"
#include "utils.hpp"
#include <limits>

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
		:m_errhnd(errhnd_),m_mutex(),m_logger(logger_),m_idcnt(0){}
	/// \brief Destructor
	~TraceGlobalContext(){}

	/// \brief Create a new object id (unique for this trace context)
	TraceObjectId createId()
	{
		utils::ScopedLock lock( m_mutex);
		if (m_idcnt >= std::numeric_limits<TraceObjectId>::max())
		{
			throw strus::runtime_error( "%s", _TXT("number of objects created out of range"));
		}
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
	template <class Interface, class InterfaceImpl>
	const Interface* createInterfaceImpl_const( const Interface* wrapped)
	{
		try
		{
			if (!wrapped) return 0;
			InterfaceImpl* rt = new InterfaceImpl( wrapped, this);

			utils::ScopedLock lock( m_mutex);
			m_const_objects.push_back( Reference<TraceObjectBase>( rt));
			return rt;
		}
		catch (const std::bad_alloc&)
		{
			m_errhnd->report(_TXT("memory allocation error"));
			delete wrapped;
			return 0;
		}
	}
	template <class Interface, class InterfaceImpl>
	Interface* createInterfaceImpl( Interface* wrapped)
	{
		try
		{
			if (!wrapped) return 0;
			InterfaceImpl* rt = new InterfaceImpl( wrapped, this);
			return rt;
		}
		catch (const std::bad_alloc&)
		{
			m_errhnd->report(_TXT("memory allocation error"));
			delete wrapped;
			return 0;
		}
	}

private:
	TraceGlobalContext( const TraceGlobalContext&){}	///< non copyable
	void operator=( const TraceGlobalContext&){}		///< non copyable

private:
	ErrorBufferInterface* m_errhnd;				///< error buffer interface for exception handling
	utils::Mutex m_mutex;					///< mutex for critical sections
	TraceLoggerInterface* m_logger;
	TraceObjectId m_idcnt;					///< counter for allocating unique object idetifiers
	mutable std::vector<Reference<TraceObjectBase> > m_const_objects;
};

} //namespace
#endif

