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
	defineType( "void")
		("pack_msg", "msg.packVoid();")
	;
	defineType( "const Index&")
		("pack_msg", "msg.packScalar($name);")
	;
	defineType( "const GlobalCounter&")
		("pack_msg", "msg.packScalar($name);")
	;
	defineType( "Index")
		("pack_msg", "msg.packScalar($name);")
	;
	defineType( "unsigned int")
		("pack_msg", "msg.packScalar($name);")
	;
	defineType( "int")
		("pack_msg", "msg.packScalar($name);")
	;
	defineType( "std::size_t")
		("pack_msg", "msg.packScalar($name);")
	;
	defineType( "bool")
		("pack_msg", "msg.packBool($name);")
	;
	defineType( "std::string")
		("pack_msg", "msg.packString($name);")
	;
	defineType( "const std::string&")
		("pack_msg", "msg.packString($name);")
	;
	defineType( "std::string&")
		("pack_msg", "msg.packString($name);")
	;
	defineType( "const std::vector<std::string>&")
		("pack_msg", "msg.packStringVector($name);")
	;
	defineType( "std::vector<std::string>")
		("pack_msg", "msg.packStringVector($name);")
	;
	defineType( "const char*")
		("pack_msg", "msg.packCharp($name);")
	;
	defineType( "const char**")
		("pack_msg", "msg.packCharpp($name);")
	;
	defineType( "const char* $bufname, std::size_t")
		("pack_msg", "msg.packBuffer( $bufname, $name);")
	;
	defineType( "const char*& $bufname, std::size_t&")
		("pack_msg", "msg.packBuffer( $bufname, $name);")
	;
	defineType( "const double* $bufname, std::size_t")
		("pack_msg", "msg.packBufferFloat( $bufname, $name);")
	;
	defineType( "const NumericVariant&")
		("pack_msg", "msg.packNumericVariant($name);")
	;
	defineType( "NumericVariant")
		("pack_msg", "msg.packNumericVariant($name);")
	;
	defineType( "const DocumentClass&")
		("pack_msg", "msg.packDocumentClass($name);")
	;
	defineType( "const TermStatistics&")
		("pack_msg", "msg.packTermStatistics($name);")
	;
	defineType( "const GlobalStatistics&")
		("pack_msg", "msg.packGlobalStatistics($name);")
	;
	defineType( "const CompareOperator&", "MetaDataRestriction")
		("pack_msg", "msg.packMetaDataRestrictionCompareOperator($name);")
	;
	defineType( "const DatabaseOptions&")
		("pack_msg", "msg.packDatabaseOptions($name);")
	;
	defineType( "const ConfigType&", "Database")
		("pack_msg", "msg.packDatabaseConfigType($name);")
	;
	defineType( "const ConfigType&", "Storage")
		("pack_msg", "msg.packStorageConfigType($name);")
	;
	defineType( "const FeatureOptions&", "DocumentAnalyzer")
		("pack_msg", "msg.packFeatureOptions($name);")
	;
	defineType( "const SummaryElement&")
		("pack_msg", "msg.packSummaryElement($name);")
	;
	defineType( "const SummarizationVariable&")
		("pack_msg", "msg.packSummarizationVariable($name);")
	;
	defineType( "Term&", "DocumentTermIterator")
		("pack_msg", "msg.packDocumentTermIteratorTerm($name);")
	;
	defineType( "const Slice&", "DatabaseCursor")
		("pack_msg", "msg.packSlice($name);")
	;
	defineType( "Slice", "DatabaseCursor")
		("pack_msg", "msg.packSlice($name);")
	;
	defineType( "const analyzer::Document&")
		("pack_msg", "msg.packAnalyzerDocument($name);")
	;
	defineType( "const analyzer::Attribute&")
		("pack_msg", "msg.packAnalyzerAttribute($name);")
	;
	defineType( "const analyzer::MetaData&")
		("pack_msg", "msg.packAnalyzerMetaData($name);")
	;
	defineType( "const analyzer::Term&")
		("pack_msg", "msg.packAnalyzerTerm($name);")
	;
	defineType( "const analyzer::TermVector&")
		("pack_msg", "msg.packAnalyzerTermVector($name);")
	;
	defineType( "const analyzer::Token&")
		("pack_msg", "msg.packAnalyzerToken($name);")
	;
	defineType( "const WeightedDocument&")
		("pack_msg", "msg.packWeightedDocument($name);")
	;
	defineType( "const ResultDocument&")
		("pack_msg", "msg.packResultDocument($name);")
	;
	defineType( "const QueryResult&")
		("pack_msg", "msg.packQueryResult($name);")
	;
	defineType( "const FeatureParameter&", "QueryEval")
		("pack_msg", "msg.packFeatureParameter($name);")
	;
	defineType( "const std::vector<FeatureParameter>&", "QueryEval")
		("pack_msg", "msg.packFeatureParameterVector($name);")
	;
	defineType( "const Phrase&", "QueryAnalyzer")
		("pack_msg", "msg.packPhrase($name);")
	;
	defineType( "const DocumentStatisticsType&", "StorageClient")
		("pack_msg", "msg.packDocumentStatisticsType($name);")
	;
	defineType( "const BuilderOptions&", "StatisticsProcessor")
		("pack_msg", "msg.packStatisticsProcessorBuilderOptions($name);")
	;
	defineType( "const DocumentFrequencyChange&", "StatisticsViewer")
		("pack_msg", "msg.packStatisticsViewerDocumentFrequencyChange($name);")
	;
	defineType( "const FunctionType&", "QueryProcessor")
		("pack_msg", "msg.packQueryProcessorFunctionType($name);")
	;
	defineType( "const FunctionType&", "TextProcessor")
		("pack_msg", "msg.packTextProcessorFunctionType($name);")
	;
	defineType( "Description", "PostingJoinOperator")
		("pack_msg", "msg.packPostingJoinOperatorDescription($name);")
	;
	defineType( "const std::vector<Reference<PostingIteratorInterface> >&")
		("pack_msg", "const std::vector<Reference<PostingIteratorInterface> >::const_iterator i_$name = $name.begin(), e_$name = $name.end(); for (std::size_t idx_$name=0; i_$name != e_$name; ++i_$name,++idx_$name) {msg.openIndex( idx_$name); msg.packObject(**i_$name); msg.close();}")
	;
	defineType( "FunctionDescription")
		("pack_msg", "msg.packFunctionDescription($name);")
	;
	defineType( "$objid~Interface*")
		("pack_msg", "msg.packObject($name);")
	;
	defineType( "const $objid~Interface*")
		("pack_msg", "msg.packObject($name);")
	;
	defineType( "const char*&")
		("pack_msg", "msg.packCharp($name);")
	;
	defineType( "const char*&")
		("pack_msg", "msg.packCharp($name);")
	;
	defineType( "const std::string&")
		("pack_msg", "msg.packString($name);")
	;
}

