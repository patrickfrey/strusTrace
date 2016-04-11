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
	m_notImplInterfaces.insert( "ErrorBuffer");
	m_notImplInterfaces.insert( "AnalyzerErrorBuffer");
}


