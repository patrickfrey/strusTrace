/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Some private logging helpers
/// \file logUtils.cpp
#include "logUtils.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace strus;
using namespace strus::utils;

std::string utils::encodeText( const char* buf, std::size_t bufsize)
{
	static const char* cntrlchrs = "\n\t\r\b";
	static const char* cntrlsubs = "ntrb";
	std::string rt;
	std::size_t bi = 0;
	for (; bi < bufsize; ++bi)
	{
		if ((unsigned char)buf[bi] > 127 || buf[bi] == '\\')
		{
			char encoded[ 32];
			(void)::snprintf( encoded, sizeof(encoded), "&#%u;", (unsigned int)(unsigned char)buf[bi]);
			rt.append( encoded);
		}
		else if ((unsigned char)buf[bi] < 32)
		{
			if ((unsigned char)buf[bi] == 0)
			{
				rt.append( "&#0;");
			}
			else
			{
				char const* ci = std::strchr( cntrlchrs, buf[bi]);
				if (ci)
				{
					rt.push_back( '\\');
					rt.push_back( cntrlsubs[ ci-cntrlchrs]);
				}
				else
				{
					char encoded[ 32];
					(void)::snprintf( encoded, sizeof(encoded), "&#%u;", (unsigned int)(unsigned char)buf[bi]);
					rt.append( encoded);
				}
			}
		}
		else if (buf[bi] == '\'')
		{
			rt.append( "&apos;");
		}
		else if (buf[bi] == '"')
		{
			rt.append( "&quot;");
		}
		else
		{
			rt.push_back( buf[bi]);
		}
	}
	return rt;
}

std::string utils::encodeNumber( unsigned int num)
{
	std::ostringstream buf;
	buf << num;
	return buf.str();
}

enum {MaxBlockSize=1<<14};
StringBlock::~StringBlock()
{
	std::free( m_blk);
}

StringBlock::StringBlock( const char* blk_, std::size_t blksize_)
{
	m_allocsize = (blksize_ > MaxBlockSize) ? blksize_:MaxBlockSize;
	m_blk = (char*)std::malloc( m_allocsize);
	if (!m_blk) throw std::bad_alloc();
	std::memcpy( m_blk, blk_, blksize_);
	m_size = blksize_;
}

const char* StringBlock::ptr() const
{
	return m_blk;
}

std::size_t StringBlock::size() const
{
	return m_size;
}

const char* StringBlock::alloc( const char* blk_, std::size_t blksize_)
{
	if (m_size + blksize_ > m_allocsize || blksize_ > m_allocsize) return 0;
	char* rt = m_blk + m_size;
	std::memcpy( rt, blk_, blksize_);
	m_size += blksize_;
	return rt;
}


