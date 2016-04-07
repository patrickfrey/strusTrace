/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Filling tables for Strus interface parser
/// \file interfaceParser_fillTables.cpp
#include "interfaceParser.hpp"
#include <stdexcept>

using namespace strus;

void TypeSystem::fillTypeTables()
{
	defineType( "const char*&")
		("pack_msg", "msg.packCharp($name);");
	defineType( "const char*&")
		("pack_msg", "msg.packCharp($name);");
	defineType( "const std::string&")
		("pack_msg", "msg.packString($name);");
	defineType( "const Index&")
		("pack_msg", "msg.packScalar($name);");
	defineType( "Index")
		("pack_msg", "msg.packScalar($name);");
	defineType( "unsigned int")
		("pack_msg", "msg.packScalar($name);");
	defineType( "int")
		("pack_msg", "msg.packScalar($name);");
	defineType( "std::size_t")
		("pack_msg", "msg.packScalar($name);");
}

