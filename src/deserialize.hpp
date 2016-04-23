/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _STRUS_TRACE_DESERIALIZE_DESERIALIZE_HPP_INCLUDED
#define _STRUS_TRACE_DESERIALIZE_DESERIALIZE_HPP_INCLUDED
#include "strus/traceElement.hpp"
#include <string>
#include <vector>

namespace strus {

class Deserializer
{
public:
	static std::vector<TraceElement> deserialize( const char* struct_, std::size_t structSize_);
};

}//namespace
#endif


