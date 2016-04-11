/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Filling tables for Strus interface parser
/// \file interfaceParser_fillTables.cpp
#include "fillTypeTables.hpp"
#include "interfaceParser.hpp"
#include <stdexcept>

using namespace strus;

void strus::fillTypeTables( TypeSystem& typesystem)
{
	typesystem.defineType( "void")
		("pack_msg", "msg.packVoid();")
	;
	typesystem.defineType( "const Index&")
		("pack_msg", "msg.packScalar($name);")
	;
	typesystem.defineType( "const GlobalCounter&")
		("test_null", "$name < 0")
		("pack_msg", "msg.packScalar($name);")
	;
	typesystem.defineType( "Index")
		("test_null", "$name < 0")
		("pack_msg", "msg.packScalar($name);")
	;
	typesystem.defineType( "SegmenterPosition&")
		("pack_msg", "msg.packScalar($name);")
	;
	typesystem.defineType( "unsigned int")
		("pack_msg", "msg.packScalar($name);")
	;
	typesystem.defineType( "int")
		("pack_msg", "msg.packScalar($name);")
	;
	typesystem.defineType( "int&")
		("pack_msg", "msg.packScalar($name);")
	;
	typesystem.defineType( "std::size_t")
		("test_null", "$name < 0")
		("pack_msg", "msg.packScalar($name);")
	;
	typesystem.defineType( "bool")
		("pack_msg", "msg.packBool($name);")
	;
	typesystem.defineType( "float")
		("pack_msg", "msg.packScalar($name);")
	;
	typesystem.defineType( "double")
		("pack_msg", "msg.packScalar($name);")
	;
	typesystem.defineType( "std::string")
		("pack_msg", "msg.packString($name);")
	;
	typesystem.defineType( "const std::string&")
		("pack_msg", "msg.packString($name);")
	;
	typesystem.defineType( "std::string&")
		("pack_msg", "msg.packString($name);")
	;
	typesystem.defineType( "const std::vector<std::string>&")
		("pack_msg", "msg.packStringVector($name);")
	;
	typesystem.defineType( "std::vector<std::string>")
		("pack_msg", "msg.packStringVector($name);")
	;
	typesystem.defineType( "const std::vector<Index>&")
		("pack_msg", "msg.packIndexVector($name);")
	;
	typesystem.defineType( "const char*")
		("test_null", "$name == 0")
		("pack_msg", "msg.packCharp($name);")
	;
	typesystem.defineType( "const char**")
		("test_null", "$name == 0")
		("pack_msg", "msg.packCharpp($name);")
	;
	typesystem.defineType( "const char* $bufname, std::size_t")
		("pass_param", "$bufname, $name")
		("pack_msg", "msg.packBuffer( $bufname, $name);")
	;
	typesystem.defineType( "const char*& $bufname, std::size_t&")
		("test_null", "$bufname == 0")
		("pass_param", "$bufname, $name")
		("pack_msg", "msg.packBuffer( $bufname, $name);")
	;
	typesystem.defineType( "const double* $bufname, std::size_t")
		("test_null", "$bufname == 0")
		("pass_param", "$bufname, $name")
		("pack_msg", "msg.packBufferFloat( $bufname, $name);")
	;
	typesystem.defineType( "const NumericVariant&")
		("pack_msg", "msg.packNumericVariant($name);")
	;
	typesystem.defineType( "NumericVariant")
		("test_null", "!$name.defined()")
		("pack_msg", "msg.packNumericVariant($name);")
	;
	typesystem.defineType( "const DocumentClass&")
		("pack_msg", "msg.packDocumentClass($name);")
	;
	typesystem.defineType( "DocumentClass&")
		("pack_msg", "msg.packDocumentClass($name);")
	;
	typesystem.defineType( "const TermStatistics&")
		("pack_msg", "msg.packTermStatistics($name);")
	;
	typesystem.defineType( "const GlobalStatistics&")
		("pack_msg", "msg.packGlobalStatistics($name);")
	;
	typesystem.defineType( "const CompareOperator&", "MetaDataRestriction")
		("pack_msg", "msg.packMetaDataRestrictionCompareOperator($name);")
	;
	typesystem.defineType( "MetaDataRestrictionInterface::CompareOperator")
		("pack_msg", "msg.packMetaDataRestrictionCompareOperator($name);")
	;
	typesystem.defineType( "const DatabaseOptions&")
		("pack_msg", "msg.packDatabaseOptions($name);")
	;
	typesystem.defineType( "const ConfigType&", "Database")
		("pack_msg", "msg.packDatabaseConfigType($name);")
	;
	typesystem.defineType( "const ConfigType&", "Storage")
		("pack_msg", "msg.packStorageConfigType($name);")
	;
	typesystem.defineType( "const FeatureOptions&", "DocumentAnalyzer")
		("pack_msg", "msg.packFeatureOptions($name);")
	;
	typesystem.defineType( "const SummaryElement&")
		("pack_msg", "msg.packSummaryElement($name);")
	;
	typesystem.defineType( "std::vector<SummaryElement>")
		("pack_msg", "msg.packSummaryElement($name);")
	;
	typesystem.defineType( "const SummarizationVariable&")
		("pack_msg", "msg.packSummarizationVariable($name);")
	;
	typesystem.defineType( "const std::vector<SummarizationVariable>& ")
		("pack_msg", "msg.packSummarizationVariableVector($name);")
	;
	typesystem.defineType( "Term&", "DocumentTermIterator")
		("pack_msg", "msg.packDocumentTermIteratorTerm($name);")
	;
	typesystem.defineType( "const Slice&", "DatabaseCursor")
		("pack_msg", "msg.packSlice($name);")
	;
	typesystem.defineType( "Slice", "DatabaseCursor")
		("pack_msg", "msg.packSlice($name);")
	;
	typesystem.defineType( "const analyzer::Document&")
		("pack_msg", "msg.packAnalyzerDocument($name);")
	;
	typesystem.defineType( "analyzer::Document&")
		("pack_msg", "msg.packAnalyzerDocument($name);")
	;
	typesystem.defineType( "analyzer::Document")
		("pack_msg", "msg.packAnalyzerDocument($name);")
	;
	typesystem.defineType( "const analyzer::Attribute&")
		("pack_msg", "msg.packAnalyzerAttribute($name);")
	;
	typesystem.defineType( "const analyzer::MetaData&")
		("pack_msg", "msg.packAnalyzerMetaData($name);")
	;
	typesystem.defineType( "const analyzer::Term&")
		("pack_msg", "msg.packAnalyzerTerm($name);")
	;
	typesystem.defineType( "std::vector<analyzer::Term>")
		("pack_msg", "msg.packAnalyzerTermVector($name);")
	;
	typesystem.defineType( "std::vector<analyzer::TermVector>")
		("pack_msg", "msg.packAnalyzerTermVectorVector($name);")
	;
	typesystem.defineType( "const analyzer::Token&")
		("pack_msg", "msg.packAnalyzerToken($name);")
	;
	typesystem.defineType( "std::vector<analyzer::Token>")
		("pack_msg", "msg.packAnalyzerTokenVector($name);")
	;
	typesystem.defineType( "const WeightedDocument&")
		("pack_msg", "msg.packWeightedDocument($name);")
	;
	typesystem.defineType( "const ResultDocument&")
		("pack_msg", "msg.packResultDocument($name);")
	;
	typesystem.defineType( "QueryResult")
		("pack_msg", "msg.packQueryResult($name);")
	;
	typesystem.defineType( "const FeatureParameter&", "QueryEval")
		("pack_msg", "msg.packFeatureParameter($name);")
	;
	typesystem.defineType( "const std::vector<FeatureParameter>&", "QueryEval")
		("pack_msg", "msg.packFeatureParameterVector($name);")
	;
	typesystem.defineType( "const Phrase&", "QueryAnalyzer")
		("pack_msg", "msg.packPhrase($name);")
	;
	typesystem.defineType( "const std::vector<Phrase>& phraseBulk", "QueryAnalyzer")
		("pack_msg", "msg.packPhraseVector($name);")
	;
	typesystem.defineType( "const DocumentStatisticsType&", "StorageClient")
		("pack_msg", "msg.packDocumentStatisticsType($name);")
	;
	typesystem.defineType( "const BuilderOptions&", "StatisticsProcessor")
		("pack_msg", "msg.packStatisticsProcessorBuilderOptions($name);")
	;
	typesystem.defineType( "DocumentFrequencyChange&", "StatisticsViewer")
		("pack_msg", "msg.packStatisticsViewerDocumentFrequencyChange($name);")
	;
	typesystem.defineType( "const FunctionType&", "QueryProcessor")
		("pack_msg", "msg.packQueryProcessorFunctionType($name);")
	;
	typesystem.defineType( "const FunctionType&", "TextProcessor")
		("pack_msg", "msg.packTextProcessorFunctionType($name);")
	;
	typesystem.defineType( "Description", "PostingJoinOperator")
		("pack_msg", "msg.packPostingJoinOperatorDescription($name);")
	;
	typesystem.defineType( "const std::vector<Reference<PostingIteratorInterface> >&")
		("pack_msg", "const std::vector<Reference<PostingIteratorInterface> >::const_iterator\n\ti_$name = $name.begin(), e_$name = $name.end();\nfor (std::size_t idx_$name=0; i_$name != e_$name; ++i_$name,++idx_$name)\n{\n\tmsg.openIndex( idx_$name); \n\tmsg.packObject(**i_$name);\n\tmsg.close();\n}")
	;
	typesystem.defineType( "FunctionDescription")
		("pack_msg", "msg.packFunctionDescription($name);")
	;
	typesystem.defineType( "$objid~Interface*")
		("test_null", "$name == 0")
		("pack_msg", "msg.packObject($name);")
		("delete", "if ($name) {delete $name; $name = 0;}")
	;
	//Define explicit pass by reference exceptions:
	static const char* interfacePassByReferenceException[7][2] = {
		{"Database", "restoreDatabase"},
		{"Storage", "createStorage"},
		{"SummarizerFunctionContext", "addSummarizationFeature"},
		{"WeightingFunctionContext", "addWeightingFeature"},
		{"SummarizerFunctionInstance", "createFunctionContext"},
		{"WeightingFunctionInstance", "createFunctionContext"},
		{0,0}
	};
	for (std::size_t ei=0; interfacePassByReferenceException[ei][0]; ++ei)
	{
		const char* classname = interfacePassByReferenceException[ei][0];
		const char* methodname = interfacePassByReferenceException[ei][1];
		typesystem.defineType( "$objid~Interface*", classname, methodname)
			("test_null", "$name == 0")
			("pack_msg", "msg.packObject($name);")
		;
	}
	typesystem.defineType( "const $objid~Interface*")
		("test_null", "$name == 0")
		("pack_msg", "msg.packObject($name);")
	;
	typesystem.defineType( "const std::vector<Reference<$objid~Interface> >&")
		("pack_msg", "std::vector<Reference<$objid~Interface> >::const_iterator\n\ti_$name = $name.begin(), e_$name = $name.end();\nfor (std::size_t idx_$name=0; i_$name != e_$name; ++i_$name,++idx_$name)\n{\n\tmsg.openIndex( idx_$name);\n\tmsg.packObject(**i_$name);\n\tmsg.close();\n}")
	;
	typesystem.defineType( "const std::vector<$objid~Interface*>&")
		("pack_msg", "std::vector<$objid~Interface*>::const_iterator\n\ti_$name = $name.begin(), e_$name = $name.end();\nfor (std::size_t idx_$name=0; i_$name != e_$name; ++i_$name,++idx_$name)\n{\n\tmsg.openIndex( idx_$name);\n\tmsg.packObject(**i_$name);\n\tmsg.close();\n}")
		("delete", "std::vector<$objid~Interface*>::const_iterator\n\ti_$name = $name.begin(), e_$name = $name.end();\nfor (std::size_t idx_$name=0; i_$name != e_$name; ++i_$name,++idx_$name)\n{\n\tdelete *i_$name;\n}\n$name.clear();")
	;
	typesystem.defineType( "const char*&")
		("test_null", "$name == 0")
		("pack_msg", "msg.packCharp($name);")
	;
	typesystem.defineType( "const std::string&")
		("pack_msg", "msg.packString($name);")
	;
	typesystem.defineType( "std::ostream&")
		("pack_msg", "")
	;
}

