/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief List of strus enum identifiers 
/// \file enumIdentifiers.hpp
#ifndef _STRUS_TRACE_ENUM_IDENTIFIERS_HPP_INCLUDED
#define _STRUS_TRACE_ENUM_IDENTIFIERS_HPP_INCLUDED

namespace strus
{
	enum TraceEnumType
	{
		Database_ConfigType=0x01,
		Storage_ConfigType=0x02,
		FunctionDescription_Parameter_Type=0x11,
		NumericVariant_Type=0x12,
		MetaDataRestriction_CompareOperator=0x13,
		QueryProcessor_FunctionType=0x21,
		TextProcessor_FunctionType=0x22,
		StatisticsProcessor_BuilderOptions_Set=0x31,
		StorageClient_DocumentStatisticsType=0x32,
		DocumentAnalyzer_PositionBind=41
	};
}//namespace
#endif

