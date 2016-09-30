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
		("pack_msg", "parambuf.packVoid();")
	;
	typesystem.defineType( "const Index&")
		("pack_msg", "parambuf.packIndex($name);")
	;
	typesystem.defineType( "const GlobalCounter&")
		("test_null", "$name < 0")
		("pack_msg", "parambuf.packGlobalCounter($name);")
	;
	typesystem.defineType( "Index")
		("test_null", "$name < 0")
		("pack_msg", "parambuf.packIndex($name);")
	;
	typesystem.defineType( "const SegmenterOptions&")
		("pack_msg", "parambuf.packSegmenterOptions($name);")
	;
	typesystem.defineType( "const SegmenterPosition&")
		("pack_msg", "parambuf.packGlobalCounter($name);")
	;
	typesystem.defineType( "SegmenterPosition&")
		("pack_msg", "parambuf.packGlobalCounter($name);")
	;
	typesystem.defineType( "unsigned int")
		("pack_msg", "parambuf.packUInt($name);")
	;
	typesystem.defineType( "int")
		("pack_msg", "parambuf.packInt($name);")
	;
	typesystem.defineType( "int&")
		("pack_msg", "parambuf.packInt($name);")
	;
	typesystem.defineType( "std::size_t")
		("pack_msg", "parambuf.packSize( $name);")
	;
	typesystem.defineType( "bool")
		("pack_msg", "parambuf.packBool($name);")
	;
	typesystem.defineType( "float")
		("pack_msg", "parambuf.packFloat($name);")
	;
	typesystem.defineType( "double")
		("pack_msg", "parambuf.packDouble($name);")
	;
	typesystem.defineType( "std::string")
		("pack_msg", "parambuf.packString($name);")
	;
	typesystem.defineType( "const std::string&")
		("pack_msg", "parambuf.packString($name);")
	;
	typesystem.defineType( "std::string&")
		("pack_msg", "parambuf.packString($name);")
	;
	typesystem.defineType( "const std::vector<std::string>&")
		("pack_msg", "parambuf.packStringVector($name);")
	;
	typesystem.defineType( "std::vector<std::string>")
		("pack_msg", "parambuf.packStringVector($name);")
	;
	typesystem.defineType( "const std::vector<Index>&")
		("pack_msg", "parambuf.packIndexVector($name);")
	;
	typesystem.defineType( "std::vector<Index>")
		("pack_msg", "parambuf.packIndexVector($name);")
	;
	typesystem.defineType( "const std::vector<unsigned int>&")
		("pack_msg", "parambuf.packUintVector($name);")
	;
	typesystem.defineType( "std::vector<unsigned int>")
		("pack_msg", "parambuf.packUintVector($name);")
	;
	typesystem.defineType( "const std::vector<double>&")
		("pack_msg", "parambuf.packFloatVector($name);")
	;
	typesystem.defineType( "std::vector<double>")
		("pack_msg", "parambuf.packFloatVector($name);")
	;
	typesystem.defineType( "const char*")
		("test_null", "$name == 0")
		("pack_msg", "parambuf.packCharp($name);")
	;
	typesystem.defineType( "const char**")
		("test_null", "$name == 0")
		("pack_msg", "parambuf.packCharpp($name);")
	;
	typesystem.defineType( "const char* $bufname, std::size_t")
		("pass_param", "$bufname, $name")
		("pack_msg", "parambuf.packBuffer( $bufname, $name);")
	;
	typesystem.defineType( "const char*& $bufname, std::size_t&")
		("test_null", "$bufname == 0")
		("pass_param", "$bufname, $name")
		("pack_msg", "parambuf.packBuffer( $bufname, $name);")
	;
	typesystem.defineType( "const double* $bufname, std::size_t")
		("test_null", "$bufname == 0")
		("pass_param", "$bufname, $name")
		("pack_msg", "parambuf.packBufferFloat( $bufname, $name);")
	;
	typesystem.defineType( "const NumericVariant&")
		("pack_msg", "parambuf.packNumericVariant($name);")
	;
	typesystem.defineType( "NumericVariant")
		("test_null", "!$name.defined()")
		("pack_msg", "parambuf.packNumericVariant($name);")
	;
	typesystem.defineType( "const DocumentClass&")
		("pack_msg", "parambuf.packDocumentClass($name);")
	;
	typesystem.defineType( "DocumentClass&")
		("pack_msg", "parambuf.packDocumentClass($name);")
	;
	typesystem.defineType( "const TermStatistics&")
		("pack_msg", "parambuf.packTermStatistics($name);")
	;
	typesystem.defineType( "const GlobalStatistics&")
		("pack_msg", "parambuf.packGlobalStatistics($name);")
	;
	typesystem.defineType( "const CompareOperator&", "MetaDataRestriction")
		("pack_msg", "parambuf.packMetaDataRestrictionCompareOperator($name);")
	;
	typesystem.defineType( "MetaDataRestrictionInterface::CompareOperator")
		("pack_msg", "parambuf.packMetaDataRestrictionCompareOperator($name);")
	;
	typesystem.defineType( "const DatabaseOptions&")
		("pack_msg", "parambuf.packDatabaseOptions($name);")
	;
	typesystem.defineType( "const ConfigType&", "Database")
		("pack_msg", "parambuf.packDatabaseConfigType($name);")
	;
	typesystem.defineType( "const ConfigType&", "Storage")
		("pack_msg", "parambuf.packStorageConfigType($name);")
	;
	typesystem.defineType( "const FeatureOptions&", "DocumentAnalyzer")
		("pack_msg", "parambuf.packFeatureOptions($name);")
	;
	typesystem.defineType( "const SummaryElement&")
		("pack_msg", "parambuf.packSummaryElement($name);")
	;
	typesystem.defineType( "std::vector<SummaryElement>")
		("pack_msg", "parambuf.packSummaryElementVector($name);")
	;
	typesystem.defineType( "const SummarizationVariable&")
		("pack_msg", "parambuf.packSummarizationVariable($name);")
	;
	typesystem.defineType( "const std::vector<SummarizationVariable>& ")
		("pack_msg", "parambuf.packSummarizationVariableVector($name);")
	;
	typesystem.defineType( "Term&", "DocumentTermIterator")
		("pack_msg", "parambuf.packDocumentTermIteratorTerm($name);")
	;
	typesystem.defineType( "const Slice&", "DatabaseCursor")
		("pack_msg", "parambuf.packSlice($name);")
	;
	typesystem.defineType( "Slice", "DatabaseCursor")
		("scopedtype", "DatabaseCursorInterface::Slice")
		("pack_msg", "parambuf.packSlice($name);")
	;
	typesystem.defineType( "const analyzer::Document&")
		("pack_msg", "parambuf.packAnalyzerDocument($name);")
	;
	typesystem.defineType( "analyzer::Document&")
		("pack_msg", "parambuf.packAnalyzerDocument($name);")
	;
	typesystem.defineType( "analyzer::Document")
		("pack_msg", "parambuf.packAnalyzerDocument($name);")
	;
	typesystem.defineType( "const analyzer::Attribute&")
		("pack_msg", "parambuf.packAnalyzerAttribute($name);")
	;
	typesystem.defineType( "const analyzer::MetaData&")
		("pack_msg", "parambuf.packAnalyzerMetaData($name);")
	;
	typesystem.defineType( "const analyzer::Term&")
		("pack_msg", "parambuf.packAnalyzerTerm($name);")
	;
	typesystem.defineType( "std::vector<analyzer::Term>")
		("pack_msg", "parambuf.packAnalyzerTermVector($name);")
	;
	typesystem.defineType( "std::vector<analyzer::TermVector>")
		("pack_msg", "parambuf.packAnalyzerTermVectorVector($name);")
	;
	typesystem.defineType( "const analyzer::Token&")
		("pack_msg", "parambuf.packAnalyzerToken($name);")
	;
	typesystem.defineType( "std::vector<analyzer::Token>")
		("pack_msg", "parambuf.packAnalyzerTokenVector($name);")
	;
	typesystem.defineType( "const WeightedDocument&")
		("pack_msg", "parambuf.packWeightedDocument($name);")
	;
	typesystem.defineType( "const ResultDocument&")
		("pack_msg", "parambuf.packResultDocument($name);")
	;
	typesystem.defineType( "QueryResult")
		("pack_msg", "parambuf.packQueryResult($name);")
	;
	typesystem.defineType( "const FeatureParameter&", "QueryEval")
		("pack_msg", "parambuf.packFeatureParameter($name);")
	;
	typesystem.defineType( "const std::vector<FeatureParameter>&", "QueryEval")
		("pack_msg", "parambuf.packFeatureParameterVector($name);")
	;
	typesystem.defineType( "const Phrase&", "QueryAnalyzer")
		("pack_msg", "parambuf.packPhrase($name);")
	;
	typesystem.defineType( "const std::vector<Phrase>&", "QueryAnalyzer")
		("pack_msg", "parambuf.packPhraseVector($name);")
	;
	typesystem.defineType( "const DocumentStatisticsType&", "StorageClient")
		("pack_msg", "parambuf.packDocumentStatisticsType($name);")
	;
	typesystem.defineType( "const BuilderOptions&", "StatisticsProcessor")
		("pack_msg", "parambuf.packStatisticsProcessorBuilderOptions($name);")
	;
	typesystem.defineType( "DocumentFrequencyChange&", "StatisticsViewer")
		("pack_msg", "parambuf.packStatisticsViewerDocumentFrequencyChange($name);")
	;
	typesystem.defineType( "const FunctionType&", "QueryProcessor")
		("pack_msg", "parambuf.packQueryProcessorFunctionType($name);")
	;
	typesystem.defineType( "const FunctionType&", "TextProcessor")
		("pack_msg", "parambuf.packTextProcessorFunctionType($name);")
	;
	typesystem.defineType( "Description", "PostingJoinOperator")
		("scopedtype", "PostingJoinOperatorInterface::Description")
		("pack_msg", "parambuf.packPostingJoinOperatorDescription($name);")
	;
	typesystem.defineType( "FunctionDescription")
		("pack_msg", "parambuf.packFunctionDescription($name);")
	;
	typesystem.defineType( "$objid~Interface*")
		("wrap_return", "$name = traceContext()->createInterfaceImpl<$objid~Interface,$objid~Impl>( $name);")
		("test_null", "$name == 0")
		("pack_msg", "TraceObjectBase* objbase_$name = dynamic_cast<TraceObjectBase*>( $name);\nif (!objbase_$name) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_$objid), objbase_$name->objid());")
		("objid", "objbase_$name->objid()")
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
			("wrap_return", "$name = traceContext()->createInterfaceImpl<$objid~Interface,$objid~Impl>( $name);")
			("test_null", "$name == 0")
			("pack_msg", "TraceObjectBase* objbase_$name = dynamic_cast<TraceObjectBase*>( $name);\nif (!objbase_$name) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_$objid), objbase_$name->objid());")
		;
	}
	typesystem.defineType( "const $objid~Interface*")
		("wrap_return", "$name = traceContext()->createInterfaceImpl_const<$objid~Interface,$objid~Impl>( $name);")
		("test_null", "$name == 0")
		("pack_msg", "const TraceObjectBase* objbase_$name = dynamic_cast<const TraceObjectBase*>( $name);\nif (!objbase_$name) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_$objid), objbase_$name->objid());")
		("objid", "objbase_$name->objid()")
	;
	typesystem.defineType( "const std::vector<Reference<$objid~Interface> >&")
		("pack_msg", "std::vector<Reference<$objid~Interface> >::const_iterator\n\ti_$name = $name.begin(), e_$name = $name.end();\nfor (std::size_t idx_$name=0; i_$name != e_$name; ++i_$name,++idx_$name)\n{\n\tparambuf.openIndex( idx_$name); \n\tconst TraceObjectBase* objbase = dynamic_cast<const TraceObjectBase*>( i_$name->get());\n\tif (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_$objid), objbase->objid());\n\tparambuf.close();\n}")
	;
	typesystem.defineType( "const std::vector<$objid~Interface*>&")
		("pack_msg", "std::vector<$objid~Interface*>::const_iterator\n\ti_$name = $name.begin(), e_$name = $name.end();\nfor (std::size_t idx_$name=0; i_$name != e_$name; ++i_$name,++idx_$name)\n{\n\tparambuf.openIndex( idx_$name); \n\tTraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_$name);\n\tif (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_$objid), objbase->objid());\n\tparambuf.close();\n}")
		("delete", "std::vector<$objid~Interface*>::const_iterator\n\ti_$name = $name.begin(), e_$name = $name.end();\nfor (std::size_t idx_$name=0; i_$name != e_$name; ++i_$name,++idx_$name)\n{\n\tdelete *i_$name;\n}")
	;
	typesystem.defineType( "const char*&")
		("test_null", "$name == 0")
		("pack_msg", "parambuf.packCharp($name);")
	;
	typesystem.defineType( "const std::string&")
		("pack_msg", "parambuf.packString($name);")
	;
	typesystem.defineType( "std::ostream&")
		("pack_msg", "")
	;
}

