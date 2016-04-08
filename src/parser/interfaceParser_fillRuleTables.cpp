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

void TypeSystem::fillRuleTables()
{
	m_notImplMethods.insert( "checkStorage");
	m_notImplMethods.insert( "createResultIterator");

	m_notImplInterfaces.insert( "ErrorBuffer");
	m_notImplInterfaces.insert( "AnalyzerErrorBuffer");
	
	m_passOwnershipMethod .insert( "definePostingJoinOperator");
	m_passOwnershipMethod .insert( "defineWeightingFunction");
	m_passOwnershipMethod .insert( "defineSummarizerFunction");
	m_passOwnershipMethod .insert( "defineScalarFunctionParser");
	
	m_passOwnershipMethod .insert( "defineDocumentClassDetector");
	m_passOwnershipMethod .insert( "defineTokenizer");
	m_passOwnershipMethod .insert( "defineNormalizer");
	m_passOwnershipMethod .insert( "defineAggregator");
	
	m_passOwnershipMethod .insert( "createClient");
	m_passOwnershipMethod .insert( "createAlterMetaDataTable");
	m_passOwnershipMethod .insert( "createBrowsePostingIterator");
	
	m_passOwnershipMethod .insert( "definePhraseType");
	
	m_passOwnershipMethod .insert( "addSearchIndexFeature");
	m_passOwnershipMethod .insert( "addForwardIndexFeature");
	m_passOwnershipMethod .insert( "defineMetaData");
	m_passOwnershipMethod .insert( "defineAggregatedMetaData");
	m_passOwnershipMethod .insert( "defineAttribute");
	
	m_passOwnershipMethod .insert( "addWeightingFunction");
	m_passOwnershipMethod .insert( "addSummarizerFunction");
	m_passOwnershipMethod .insert( "defineWeightingFormula");
}


