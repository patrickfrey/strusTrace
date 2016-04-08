/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Codegeneator for strusTrace
/// \file strusTraceCodeGen.cpp
#include "interfaceParser.hpp"
#include "printFrame.hpp"
#include "strus/private/fileio.hpp"
#include <stdexcept>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <sstream>

static void print_ObjectIdsHpp( std::ostream& out, const strus::InterfacesDef& interfaceDef)
{
	strus::printHppFrameHeader( out, "objectIds_gen", "Identifiers for objects and methods for serialization");
	out
		<< "namespace strus {" << std::endl
		<< std::endl
		<< "enum ClassId" << std::endl
		<< "{" << std::endl;

	std::vector<strus::ClassDef>::const_iterator
		ci = interfaceDef.classDefs().begin(),
		ce = interfaceDef.classDefs().end();
	for (; ci != ce; ++ci)
	{
		out << "\tClassId_" << ci->name();
		if (ci+1 != ce) out << ",";
		out << std::endl;
	}
	out << "};" << std::endl;

	out << "}//namespace" << std::endl;
	strus::printHppFrameTail( out);
}

int main( int argc, const char* argv[])
{
	int ec = 0;
	try
	{
		strus::TypeSystem typeSystem;
		/*[-]*/std::cout << "TYPESYSTEM" << std::endl << typeSystem.tostring() << std::endl;

		strus::InterfacesDef interfaceDef( &typeSystem);
		int argi=1;
		for (; argi < argc; ++argi)
		{
			std::string source;
			ec = strus::readFile( argv[ argi], source);
			if (ec)
			{
				std::ostringstream msg;
				msg << ec;
				throw std::runtime_error( std::string( "error '") + ::strerror(ec) + "' (errno " + msg.str() + ") reading file " + argv[argi]);
			}
			try
			{
				interfaceDef.addSource( source);
			}
			catch (const std::runtime_error& err)
			{
				throw std::runtime_error( std::string( "error parsing interface file ") + argv[argi] + ": " + err.what());
			}
			std::cerr << "processed file " << argv[argi] << std::endl;

			//Output:
			print_ObjectIdsHpp( std::cout, interfaceDef);
		}
		std::cerr << "done." << std::endl;
		return 0;
	}
	catch (const std::bad_alloc&)
	{
		std::cerr << "ERROR memory allocation error in code generator" << std::endl;
		return 12/*ENOMEM*/;
	}
	catch (const std::runtime_error& err)
	{
		std::cerr << "ERROR in code generator: " << err.what() << std::endl;
		return (ec == 0)?-1:ec;
	}
	catch (...)
	{
		std::cerr << "ERROR uncaught exception in code generator" << std::endl;
		return -1;
	}
}


