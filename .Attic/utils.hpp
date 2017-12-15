/*
* Copyright (c) 2016 Patrick P. Frey
*
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
/// \brief Some private helpers (mainly BOOST wrappers)
/// \file utils.hpp

#ifndef _STRUS_PRIVATE_UTILS_HPP_INCLUDED
#define _STRUS_PRIVATE_UTILS_HPP_INCLUDED
#include <boost/thread/mutex.hpp>
#include <stdint.h>			///... boost atomic needs this
#include <boost/atomic/atomic.hpp>
#include <string>

namespace strus {
namespace utils {

typedef boost::mutex Mutex;
typedef boost::mutex::scoped_lock ScopedLock;

template <typename IntegralCounterType>
class AtomicCounter
	:public boost::atomic<IntegralCounterType>
{
public:
	///\brief Constructor
	AtomicCounter( IntegralCounterType initialValue_=0)
		:boost::atomic<IntegralCounterType>(initialValue_)
	{}

	///\brief Increment of the counter
	void increment( IntegralCounterType val = 1)
	{
		boost::atomic<IntegralCounterType>::fetch_add( val, boost::memory_order_acquire);
	}

	///\brief Decrement of the counter
	void decrement( IntegralCounterType val = 1)
	{
		boost::atomic<IntegralCounterType>::fetch_sub( val, boost::memory_order_acquire);
	}

	///\brief Increment of the counter
	///\return the new value of the counter after the increment operation
	IntegralCounterType allocIncrement( IntegralCounterType val = 1)
	{
		return boost::atomic<IntegralCounterType>::fetch_add( val, boost::memory_order_acquire);
	}

	///\brief Increment of the counter
	///\return the current value of the counter
	IntegralCounterType value() const
	{
		return boost::atomic<IntegralCounterType>::load( boost::memory_order_acquire);
	}
};

}}//namespace
#endif


