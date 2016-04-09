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
#include <fstream>
#include <sstream>
#include <cerrno>

#undef STRUS_LOWLEVEL_DEBUG

/// \brief List of interface files parsed without path
std::vector<std::string> g_inputFiles;

typedef void (*PrintInterface)( std::ostream& out, const strus::InterfacesDef& interfaceDef);

static void printOutput( const char* filename, PrintInterface print, const strus::InterfacesDef& interfaceDef)
{
	try
	{
		std::ofstream out;
		out.open( filename, std::ofstream::out);
		if (!out)
		{
			throw std::runtime_error( std::string("could not open file '") + filename + "' for writing: " + std::strerror( errno));
		}
		print( out, interfaceDef);
		out.close();
	}
	catch (const std::exception& err)
	{
		throw std::runtime_error( std::string("could not write file '") + filename + "'");
	}
}

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
	out << "};" << std::endl << std::endl;

	ci = interfaceDef.classDefs().begin();
	for (; ci != ce; ++ci)
	{
		out << "class " << ci->name() << "Const" << std::endl;
		out << "{" << std::endl;
		out << "public:" << std::endl;
		out << "\tenum MethodId" << std::endl;
		out << "\t{" << std::endl;
		out << "\t\tMethod_Destructor";
		std::vector<strus::MethodDef>::const_iterator
			mi = ci->methodDefs().begin(),
			me = ci->methodDefs().end();
		for (; mi != me; ++mi)
		{
			out << ","  << std::endl << "\t\tMethod_" << mi->name();
		}
		out << std::endl << "\t};" << std::endl;
		out << "};" << std::endl << std::endl;
	}
	out
		<< std::endl
		<< "}//namespace" << std::endl;
	strus::printHppFrameTail( out);
}

static void print_ObjectsHpp( std::ostream& out, const strus::InterfacesDef& interfaceDef)
{
	strus::printHppFrameHeader( out, "objects_gen", "Identifiers for objects and methods for serialization");
	out << "#include \"objectIds_gen.hpp\"" << std::endl;
	out << "#include \"traceObject.hpp\"" << std::endl;

	std::vector<std::string>::const_iterator fi = g_inputFiles.begin(), fe = g_inputFiles.end();
	for (; fi != fe; ++fi)
	{
		out << "#include \"strus/" << *fi << "\"" << std::endl;
	}
	out
		<< std::endl
		<< "namespace strus {" << std::endl
		<< std::endl;

	std::vector<strus::ClassDef>::const_iterator
		ci = interfaceDef.classDefs().begin(),
		ce = interfaceDef.classDefs().end();
	for (; ci != ce; ++ci)
	{
		out 
			<< "class " << ci->name() << "Impl" << std::endl
			<< "\t\t:public TraceObject<" << ci->name() << "Interface>" << std::endl
			<< "\t\t,public "  << ci->name() << "Interface" << std::endl
			<< "{" << std::endl
			<< "public:" << std::endl
			<< "\t" << ci->name() << "Impl( " << ci->name() << "Interface* obj_, TraceGlobalContext* ctx_)" << std::endl
			<< "\t\t:TraceObject<" << ci->name() << "Interface>(obj_,ctx_)" << "{}" << std::endl
			<< std::endl
			<< "\tvirtual ~" << ci->name() << "Impl();" << std::endl
		;
		std::vector<strus::MethodDef>::const_iterator
			mi = ci->methodDefs().begin(),
			me = ci->methodDefs().end();
		for (; mi != me; ++mi)
		{
			out 
			<< "\tvirtual " << mi->returnValue().expand("definition") << ' ' << mi->name() << "(";
			std::vector<strus::VariableValue>::const_iterator
				pi = mi->parameters().begin(),
				pe = mi->parameters().end();
			for (int pidx=1; pi != pe; ++pi,++pidx)
			{
				if (pidx > 1) out << ", ";
				out << std::endl << "\t\t\t" << pi->expand("definition") << " p" << pidx;
			}
			out << ");" << std::endl;
		}
		out
			<< "};" << std::endl;
	}
	out
		<< std::endl
		<< "}//namespace" << std::endl;
	strus::printHppFrameTail( out);
}


int main( int argc, const char* argv[])
{
	int ec = 0;
	try
	{
		strus::TypeSystem typeSystem;
#ifdef STRUS_LOWLEVEL_DEBUG
		std::cout << "TypeSystem:" << std::endl << typeSystem.tostring() << std::endl;
#endif
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
				char const* fi = argv[ argi];
				char const* fn = std::strchr( fi, strus::dirSeparator());
				for (;fn; fi=fn+1,fn=std::strchr( fi, strus::dirSeparator())){}

				g_inputFiles.push_back( fi);
				interfaceDef.addSource( source);
			}
			catch (const std::runtime_error& err)
			{
				throw std::runtime_error( std::string( "error parsing interface file ") + argv[argi] + ": " + err.what());
			}
			std::cerr << "processed file " << argv[argi] << std::endl;
		}
		//Output:
#ifdef STRUS_LOWLEVEL_DEBUG
		print_ObjectIdsHpp( std::cout, interfaceDef);
#endif
		printOutput( "src/objectIds_gen.hpp.test", &print_ObjectIdsHpp, interfaceDef);

		print_ObjectsHpp( std::cout, interfaceDef);

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


