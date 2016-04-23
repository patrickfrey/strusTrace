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
#include "fillTypeTables.hpp"
#include "printFrame.hpp"
#include "strus/base/fileio.hpp"
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

static std::string expandIndent( const std::string& indent, const std::string& source)
{
	std::string rt ( indent);
	std::string::const_iterator si = source.begin(), se = source.end();
	for (; si != se; ++si)
	{
		rt.push_back( *si);
		if (*si == '\n')
		{
			rt.append( indent);
		}
	}
	return rt;
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
	for (int cidx=1; ci != ce; ++ci,++cidx)
	{
		out << "\tClassId_" << ci->name() << "=" << cidx;
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
		out << "\t\tMethod_Destructor=0";
		std::vector<strus::MethodDef>::const_iterator
			mi = ci->methodDefs().begin(),
			me = ci->methodDefs().end();
		for (int midx=1; mi != me; ++mi,++midx)
		{
			out << ","  << std::endl << "\t\tMethod_" << mi->name() << "=" << midx;
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
	out << "#include <string>" << std::endl;
	out << "#include <vector>" << std::endl;
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
			<< "\t\t,public "  << ci->name() << "Const" << std::endl
			<< "{" << std::endl
			<< "public:" << std::endl
			<< "\t" << ci->name() << "Impl( " << ci->name() << "Interface* obj_, TraceGlobalContext* ctx_)" << std::endl
			<< "\t\t:TraceObject<" << ci->name() << "Interface>(obj_,ctx_)" << "{}" << std::endl
			<< "\t" << ci->name() << "Impl( const " << ci->name() << "Interface* obj_, TraceGlobalContext* ctx_)" << std::endl
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
			<< "\tvirtual " << mi->returnValue().expand("type") << ' ' << mi->name() << "(";
			std::vector<strus::VariableValue>::const_iterator
				pi = mi->parameters().begin(),
				pe = mi->parameters().end();
			for (int pidx=1; pi != pe; ++pi,++pidx)
			{
				if (pidx > 1) out << ", ";
				out << std::endl << expandIndent( "\t\t\t", pi->expand("type")) << " p" << pidx;
			}
			out << (mi->isconst()?") const;":");") << std::endl;
		}
		out
			<< "};" << std::endl << std::endl;
	}
	out
		<< std::endl
		<< "}//namespace" << std::endl;
	strus::printHppFrameTail( out);
}


static void print_ObjectsCpp( std::ostream& out, const strus::InterfacesDef& interfaceDef)
{
	strus::printCppFrameHeader( out, "objects_gen", "Identifiers for objects and methods for serialization");
	out << "#include \"objects_gen.hpp\"" << std::endl;
	out << "#include \"traceGlobalContext.hpp\"" << std::endl;
	out << "#include \"traceSerializer.hpp\"" << std::endl;

	out
		<< std::endl
		<< "using namespace strus;" << std::endl;

	std::vector<strus::ClassDef>::const_iterator
		ci = interfaceDef.classDefs().begin(),
		ce = interfaceDef.classDefs().end();
	for (; ci != ce; ++ci)
	{
		std::string implclassname( ci->name() + "Impl");
		std::string classid( std::string("ClassId_") + ci->name());
		out
			<< implclassname << "::~" << implclassname << "()" << std::endl
			<< "{" << std::endl
			<< "\tTraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( "
			<< classid << ", Method_Destructor, objid());" << std::endl
			<<"\ttraceContext()->logger()->logMethodTermination( callhnd, \"\");" << std::endl
			<< "}" << std::endl << std::endl;

		std::vector<strus::MethodDef>::const_iterator
			mi = ci->methodDefs().begin(),
			me = ci->methodDefs().end();
		for (; mi != me; ++mi)
		{
			// Function header:
			std::string returnType( mi->returnValue().expand("scopedtype"));
			bool hasReturnValue = (returnType != "void");
			out
			<< returnType << ' ' << implclassname << "::" << mi->name() << "(";
			std::vector<strus::VariableValue>::const_iterator
				pi = mi->parameters().begin(),
				pe = mi->parameters().end();
			for (int pidx=1; pi != pe; ++pi,++pidx)
			{
				if (pidx > 1) out << ", ";
				out << std::endl << expandIndent( "\t\t\t", pi->expand("type")) << " p" << pidx;
			}
			out << (mi->isconst()?") const":")") << std::endl;

			// Log method call:
			out
			<< "{" << std::endl
			<< "\tTraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( "
			<< classid << ", Method_" << mi->name() << ", objid());" << std::endl
			<< "\ttraceContext()->logger()->logOpenBranch();" << std::endl;

			// Call real function:
			if (hasReturnValue)
			{
				out << "\t" << returnType << " p0 = ";
			}
			else
			{
				out << "\t";
			}
			out << "obj()->" << mi->name() << "(";
			pi = mi->parameters().begin();
			for (int pidx=0; pi != pe; ++pi,++pidx)
			{
				char namebuf[ 128];
				snprintf( namebuf, sizeof( namebuf), "p%d", pidx +1);
				std::string passparam( pi->expand( "pass_param", namebuf));
				if (passparam.empty()) passparam.append( namebuf);
				if (pidx) out << ", ";
				out << passparam;
			}
			out
			<< ");" << std::endl
			<< "\ttraceContext()->logger()->logCloseBranch();" << std::endl;

			// Wrap returned interface objects:
			if (hasReturnValue)
			{
				std::string wrapInterface( mi->returnValue().expand("wrap_return", "p0"));
				if (!wrapInterface.empty())
				{
					out << expandIndent( "\t", wrapInterface) << std::endl;
				}
			}
			out << "\tTraceSerializer parambuf;" << std::endl;

			// Create string with packed function in/out parameters:
			// Return value:
			std::string source_packparam;
			std::string source_packret( mi->returnValue().expand( "pack_ret", "p0"));
			if (source_packret.empty())
			{
				source_packparam.append( mi->returnValue().expand( "pack_msg", "p0"));
			}
			else
			{
				source_packparam.append( source_packret);
			}
			// Parameter:
			pi = mi->parameters().begin();
			for (int pidx=0; pi != pe; ++pi,++pidx)
			{
				char namebuf[ 128];
				snprintf( namebuf, sizeof( namebuf), "p%d", pidx +1);
				source_packparam.append( "\n");
				source_packparam.append( pi->expand( "pack_msg", namebuf));
			}

			// Check result:
			if (hasReturnValue)
			{
				std::string test_null( mi->returnValue().expand( "test_null", "p0"));
				if (!test_null.empty())
				{
					out
					<< expandIndent( "\t", std::string("if (") + test_null + ")") << std::endl
					<< "\t{" << std::endl
					<< "\t\ttraceContext()->errorbuf()->report(_TXT(\"method call '%s' failed: %s\"), \"" << mi->name() << "\", traceContext()->errorbuf()->fetchError());" << std::endl
					<< "\t}" << std::endl
					<< "\telse" << std::endl
					<< "\t{" << std::endl
					<< expandIndent( "\t\t", source_packparam) << std::endl
					<< "\t}" << std::endl;
				}
				else
				{
					out << expandIndent( "\t", source_packparam) << std::endl;
				}
			}
			else
			{
				out << expandIndent( "\t", source_packparam) << std::endl;
			}
			// Check for error and set return value to NULL in this case:
			out
			<< "\tif (parambuf.hasError())" << std::endl
			<< "\t{" << std::endl
			<< "\t\ttraceContext()->errorbuf()->report( _TXT(\"memory allocation error when logging trace\"));" << std::endl;
			std::string deleteInstr( mi->returnValue().expand( "delete", "p0"));
			if (!deleteInstr.empty())
			{
				out << expandIndent( "\t\t", deleteInstr) << std::endl;
			}
			pi = mi->parameters().begin();
			for (int pidx=0; pi != pe; ++pi,++pidx)
			{
				char namebuf[ 128];
				snprintf( namebuf, sizeof( namebuf), "p%d", pidx +1);
				deleteInstr = pi->expand( "delete", namebuf);
				if (!deleteInstr.empty())
				{
					out << expandIndent( "\t\t", deleteInstr) << std::endl;
				}
			}
			out
			<<"\t\ttraceContext()->logger()->logMethodTermination( callhnd, \"\");" << std::endl
			<< "\t}" << std::endl
			<< "\telse" << std::endl
			<< "\t{" << std::endl
			<<"\t\ttraceContext()->logger()->logMethodTermination( callhnd, parambuf.content());" << std::endl
			<< "\t}" << std::endl;

			// Return result if there is one:
			if (hasReturnValue)
			{
				out << "\treturn p0;" << std::endl;
			}
			out << "}" << std::endl << std::endl;
		}
	}
	out << std::endl;
}


static void print_IdMapCpp( std::ostream& out, const strus::InterfacesDef& interfaceDef)
{
	strus::printCppFrameHeader( out, "traceIdMap_gen", "Fill map of strings to identifiers and back for objects and methods for serialization");
	out << "#include \"traceIdMap.hpp\"" << std::endl;
	out << "#include \"objectIds_gen.hpp\"" << std::endl;

	out
	<< std::endl
	<< "using namespace strus;" << std::endl << std::endl;

	out
	<< "void TraceIdMap::fillMaps()" << std::endl
	<< "{" << std::endl;
	std::vector<strus::ClassDef>::const_iterator
		ci = interfaceDef.classDefs().begin(),
		ce = interfaceDef.classDefs().end();
	for (; ci != ce; ++ci)
	{
		std::string implclassname( ci->name() + "Impl");
		std::string classid( std::string("ClassId_") + ci->name());

		out
		<< "\tm_classnamemap[\"" << ci->name() << "\"] = ClassId_" << ci->name() << ";" << std::endl
		<< "\tm_classnamear.push_back( \"" << ci->name() << "\");" << std::endl;
	}
	ci = interfaceDef.classDefs().begin();
	for (; ci != ce; ++ci)
	{
		out
		<< "\tm_methodnamemap[ MethodNameRef( ClassId_" << ci->name() << ", \"Destructor\")] = " << ci->name() << "Const::Method_Destructor;" << std::endl
		<< "\tm_methodnameinvmap[ MethodIdRef( ClassId_" << ci->name() << ", " << ci->name() << "Const::Method_Destructor)] = \"Destructor\";" << std::endl;

		std::vector<strus::MethodDef>::const_iterator
			mi = ci->methodDefs().begin(),
			me = ci->methodDefs().end();
		for (; mi != me; ++mi)
		{
			out
			<< "\tm_methodnamemap[ MethodNameRef( ClassId_" << ci->name() << ", \"" << mi->name() << "\")] = " << ci->name() << "Const::Method_" << mi->name() << ";" << std::endl
			<< "\tm_methodnameinvmap[ MethodIdRef( ClassId_" << ci->name() << ", " << ci->name() << "Const::Method_" << mi->name() << ")] = \"" << mi->name() << "\";" << std::endl;
		}
	}
	out
	<< "}" << std::endl;
}
	


int main( int argc, const char* argv[])
{
	int ec = 0;
	try
	{
		strus::TypeSystem typeSystem;
		strus::fillTypeTables( typeSystem);

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
		printOutput( "src/objectIds_gen.hpp", &print_ObjectIdsHpp, interfaceDef);

#ifdef STRUS_LOWLEVEL_DEBUG
		print_ObjectsHpp( std::cout, interfaceDef);
#endif

		printOutput( "src/objects_gen.hpp", &print_ObjectsHpp, interfaceDef);

#ifdef STRUS_LOWLEVEL_DEBUG
		print_ObjectsCpp( std::cout, interfaceDef);
#endif
		printOutput( "src/objects_gen.cpp", &print_ObjectsCpp, interfaceDef);

#ifdef STRUS_LOWLEVEL_DEBUG
		print_ObjectsCpp( std::cout, interfaceDef);
#endif
		printOutput( "src/traceIdMap_gen.cpp", &print_IdMapCpp, interfaceDef);

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


