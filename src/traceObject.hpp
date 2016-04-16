/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _STRUS_TRACE_OBJECT_HPP_INCLUDED
#define _STRUS_TRACE_OBJECT_HPP_INCLUDED
#include "strus/traceLoggerInterface.hpp"
#include <string>
#include <map>

namespace strus
{
/// \brief Forward declaration
class TraceGlobalContext;

class TraceObjectBase
{
public:
	typedef void (*Deleter)( void* obj_);

	TraceObjectBase( void* obj_, Deleter deleter_, TraceGlobalContext* ctx_);
	TraceObjectBase( const void* obj_, const TraceGlobalContext* ctx_);
	virtual ~TraceObjectBase();

	TraceObjectId objid() const
	{
		return m_id;
	}
	TraceGlobalContext* traceContext() const
	{
		return m_ctx;
	}
	void* objptr()
	{
		return m_obj;
	}
	const void* objptr() const
	{
		return m_obj;
	}

private:
	mutable TraceGlobalContext* m_ctx;
	void* m_obj;
	Deleter m_deleter;
	TraceObjectId m_id;
};


template <class Interface>
class TraceObject
	:public TraceObjectBase
{
private:
	static void deleter( void* obj_)
	{
		delete (Interface*)obj_;
	}

public:
	TraceObject( Interface* obj_, TraceGlobalContext* ctx_)
		:TraceObjectBase(obj_,&deleter,ctx_){}
	TraceObject( const Interface* obj_, const TraceGlobalContext* ctx_)
		:TraceObjectBase(obj_,ctx_){}
	virtual ~TraceObject(){}

	Interface* obj()
	{
		return (Interface*)objptr();
	}
	const Interface* obj() const
	{
		return (Interface*)objptr();
	}
};

}
#endif

