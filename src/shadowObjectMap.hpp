/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _STRUS_TRACE_OBJECT_MAP_HPP_INCLUDED
#define _STRUS_TRACE_OBJECT_MAP_HPP_INCLUDED
#include "internationalization.hpp"
#include <string>
#include <map>

namespace strus
{

template <class Interface>
class TraceObjDeleter
{
public:
	static void call( void* objptr)
	{
		delete reinterpret_cast<Interface*>(objptr);
	}
};

class TraceObjectMap
{
public:
	TraceObjectMap(){}
	~TraceObjectMap()
	{
		clear();
	}

	typedef unsigned int ObjectId;

	template <class Interface>
	Interface* getObject( const ObjectId& objId)
	{
		if (objId == 0) return 0;
		if (objId > m_objmap.size()) throw strus::runtime_error(_TXT("non existing object referenced [%u,%u]"), (unsigned int)classId, (unsigned int)objId);
		return reinterpret_cast<Interface*>( m_objmap[ objId-1].ptr);
	}

	template <class Interface>
	const Interface* getObject( const ObjectId& objId) const
	{
		if (objId == 0) return 0;
		if (objId > m_objmap.size()) throw strus::runtime_error(_TXT("non existing object referenced [%u,%u]"), (unsigned int)classId, (unsigned int)objId);
		return reinterpret_cast<const Interface*>( m_objmap[ objId-1].ptr);
	}

	template <class Interface>
	ObjectId createObject( Interface* obj)
	{
		m_objmap.push_back( Object( obj, TraceObjDeleter<Interface>::call));
		return m_objmap.size();
	}

private:
	typedef void (*ObjectDeleter)( void* objptr);

	struct Object
	{
		void* ptr;
		ObjectDeleter deleter;

		Object( void* ptr_, ObjectDeleter deleter_)
			:ptr(ptr_),deleter(deleter_){}
		Object( const Object& o)
			:ptr(o.ptr),deleter(o.deleter){}
		Object()
			:ptr(0),deleter(0){}
	};

	void clear()
	{
		ObjMap::iterator oi = m_objmap.begin(), oe = m_objmap.end();
		for (; oi != oe; ++oi)
		{
			if (oi->deleter)
			{
				oi->deleter( oi->ptr);
				oi->deleter = 0;
				oi->ptr = 0;
			}
			m_objmap.clear();
		}
	}

private:
	typedef std::vector<Object> ObjMap;
	ObjMap m_objmap;
};
}
#endif

