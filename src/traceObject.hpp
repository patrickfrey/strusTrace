/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _STRUS_TRACE_OBJECT_HPP_INCLUDED
#define _STRUS_TRACE_OBJECT_HPP_INCLUDED
#include "internationalization.hpp"
#include "strus/traceLoggerInterface.hpp"
#include <string>
#include <map>

namespace strus
{

class TraceObjectIdGen
{
public:
	TraceObjectIdGen()
		:m_idcnt(0){}

	TraceObjectId createId()
	{
		return ++m_idcnt;
	}

private:
	TraceObjectId m_idcnt;
};


class TraceObjectBase
{
public:
	typedef void (*Deleter)( void* obj_);

	TraceObjectBase( void* obj_, Deleter deleter_, TraceObjectIdGen* idgen_)
		:m_idgen(idgen_),m_obj(obj_),m_deleter(deleter_),m_id(idgen_->createId()){}
	virtual ~TraceObjectBase()
	{
		m_deleter( m_obj);
	}

	TraceObjectId id() const
	{
		return m_id;
	}
	TraceObjectIdGen* idgen() const
	{
		return m_idgen;
	}
	void* obj()
	{
		return m_obj;
	}
	const void* obj() const
	{
		return m_obj;
	}

private:
	TraceObjectIdGen* m_idgen;
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
	TraceObject( Interface* obj_, TraceObjectIdGen* idgen_)
		:TraceObjectBase(obj,&deleter,idgen_){}

	virtual ~TraceObject(){}
};

}
#endif

