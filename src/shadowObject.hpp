/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _STRUS_TRACE_OBJECT_HPP_INCLUDED
#define _STRUS_TRACE_OBJECT_HPP_INCLUDED
#include "internationalization.hpp"
#include "traceObjectMap.hpp"
#include <string>
#include <map>

namespace strus
{

template <class Interface>
class TraceObject
{
public:
	typedef TraceObjectMap::ObjectId Id;

	TraceObject( TraceObjectMap* objectmap_, Interface* obj)
		:m_objectmap(objectmap),m_obj(obj),m_id(objectmap_->createObject(obj)){}

	~TraceObject(){}

	Id id() const
	{
		return m_id;
	}

private:
	TraceObjectMap* m_objectmap;
	Interface* m_obj;
	TraceObjectMap::ObjectId m_id;
};
}
#endif

