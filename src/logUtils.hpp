/*
* Copyright (c) 2016 Patrick P. Frey
*
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
/// \brief Some private logging helpers
/// \file logUtils.hpp

#ifndef _STRUS_TRACE_LOG_UTILS_HPP_INCLUDED
#define _STRUS_TRACE_LOG_UTILS_HPP_INCLUDED
#include <string>

namespace strus {
namespace utils {

std::string encodeText( const char* buf, std::size_t bufsize);
std::string encodeNumber( unsigned int num);

/// \brief Helper structure to allocate strings as char*
class StringBlock
{
public:
	~StringBlock();
	StringBlock( const char* blk_, std::size_t blksize_);

	const char* ptr() const;
	std::size_t size() const;

	const char* alloc( const char* blk_, std::size_t blksize_);

private:
	StringBlock( const StringBlock& );	//< non copyable
	void operator=( const StringBlock& );	//< non copyable

private:
	char* m_blk;
	std::size_t m_size;
	std::size_t m_allocsize;
};

}}//namespace
#endif



