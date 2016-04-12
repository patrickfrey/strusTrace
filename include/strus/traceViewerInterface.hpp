/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Interface for inspecting call traces
/// \file traceViewerInterface.hpp
#ifndef _STRUS_TRACE_VIEWER_INTERFACE_HPP_INCLUDED
#define _STRUS_TRACE_VIEWER_INTERFACE_HPP_INCLUDED
#include "strus/traceElement.hpp"
#include "strus/traceRecord.hpp"
#include "strus/traceQuery.hpp"
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

	/// \brief Retrieves all method call logs matching to a query
	/// \param[in] query method call log query
	/// \param[in] startIndex index (starting with 0) of first result
	/// \param[in] maxNofResults maximum number of records to retrieve
	/// \return the list of matching records
	virtual std::vector<TraceRecord> listMethodCalls(
			const TraceQuery& query,
			std::size_t startIndex,
			std::size_t maxNofResults) const=0;

	/// \brief Get the creation time of an object
	/// \param[in] objId identifier of the object
	/// \return the creation time counter
	virtual TraceTimeCounter getObjectCreationTime(
			const TraceObjectId& objId) const=0;
};

}//namespace
#endif


