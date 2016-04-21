/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Toplevel interface for logging and querying call traces
/// \file traceObjectBuilderInterface.hpp
#ifndef _STRUS_TRACE_OBJECT_BUILDER_INTERFACE_HPP_INCLUDED
#define _STRUS_TRACE_OBJECT_BUILDER_INTERFACE_HPP_INCLUDED
#include <string>

namespace strus
{

/// \brief Forward declaration
class StorageObjectBuilderInterface;
/// \brief Forward declaration
class AnalyzerObjectBuilderInterface;
/// \brief Forward declaration
class TraceIdMapInterface;

/// \brief Interface for creating proxies for Strus objects that log methods called besides calling them
class TraceObjectBuilderInterface
{
public:
	/// \brief Destructor
	virtual ~TraceObjectBuilderInterface(){}

	/// \brief Create a proxy of an analyzer object builder that prints a trace log before and after every method call before executing the method itself
	/// \param[in] errorhnd error buffer for error messages and exceptions
	/// \param[in] builder builder object to build a proxy universe of
	virtual AnalyzerObjectBuilderInterface*
		createAnalyzerObjectBuilder(
			AnalyzerObjectBuilderInterface* builder) const=0;
	
	/// \brief Create a proxy of an storage object builder that prints a trace log before and after every method call before executing the method itself
	/// \param[in] errorhnd error buffer for error messages and exceptions
	/// \param[in] builder builder object to build a proxy universe of
	virtual StorageObjectBuilderInterface*
		createStorageObjectBuilder(
			StorageObjectBuilderInterface* builder) const=0;

	/// \brief Get the map of identifiers (class names, method names) used
	/// \return a read only reference to the identifier map
	virtual const TraceIdMapInterface* getIdMap() const=0;
};

}//namespace
#endif


