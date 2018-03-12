/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Version of the strus trace library
/// \file versionTrace.hpp
#ifndef _STRUS_VERSION_TRACE_HPP_INCLUDED
#define _STRUS_VERSION_TRACE_HPP_INCLUDED

/// \brief strus toplevel namespace
namespace strus
{

/// \brief Version number of strus trace
#define STRUS_TRACE_VERSION (\
	0 * 1000000\
	+ 15 * 10000\
	+ 6\
)

/// \brief Major version number of strus trace
#define STRUS_TRACE_VERSION_MAJOR 0
/// \brief Minor version number of strus trace
#define STRUS_TRACE_VERSION_MINOR 15

/// \brief The version of the strus trace library
#define STRUS_TRACE_VERSION_STRING "0.15.6"

}//namespace
#endif
