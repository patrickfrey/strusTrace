/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Interface for inspecting elements of logged traces
/// \file traceViewerInterface.hpp
#ifndef _STRUS_TRACE_VIEWER_INTERFACE_HPP_INCLUDED
#define _STRUS_TRACE_VIEWER_INTERFACE_HPP_INCLUDED
#include "strus/traceElement.hpp"
#include "strus/traceLoggerInterface.hpp"
#include <string>
#include <vector>

namespace strus
{

/// \brief Interface for inspecting logged traces
class TraceViewerInterface
{
public:
	/// \brief Destructor
	virtual ~TraceViewerInterface(){}

	/// \brief Get the name of the interface (without "Interface" suffix) associated with the class id specified
	/// \param[in] id internal identifier of the class
	/// \return the name of the class (without "Interface" suffix) 
	virtual const char* getClassName(
			const TraceClassId& id) const=0;

	/// \brief Get the name of the method associated with the method id specified
	/// \param[in] id internal identifier of the method in the context of the interface
	/// \return the name of the method
	virtual const char* getMethodName(
			const TraceClassId& classid,
			const TraceMethodId& id) const=0;

	/// \brief Get the internal identifier of the interface given by name
	/// \param[in] classname name of the class (without "Interface" suffix)
	/// \return the internal id of the class
	virtual TraceClassId getClassId(
			const char* classname) const=0;

	/// \brief Get the internal identifier of the method given by name
	/// \param[in] methodname name of the method
	/// \return the internal id of the method
	virtual TraceMethodId getMethodId( 
			const TraceClassId& classid,
			const char* methodname) const=0;

	/// \brief Unpack the elements from a serialized structure
	/// \param[in] packedStructure serialized structure as returned by TraceLoggerInterface::Record::packedParameter()
	/// \param[in] packedStructSize size of packedStruct in bytes
	/// \return the list of unpacked elements
	virtual std::vector<TraceElement> unpackElements(
			const char* packedStruct,
			std::size_t packedStructSize)=0;
};

}//namespace
#endif


