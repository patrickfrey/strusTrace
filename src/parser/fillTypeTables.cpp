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
	typesystem.defineType( "const IndexRange&")
		("pack_msg", "parambuf.packIndexRange($name);")
	;
	typesystem.defineType( "GlobalCounter")
		("pack_msg", "parambuf.packGlobalCounter($name);")
	;
	typesystem.defineType( "const GlobalCounter&")
		("test_null", "$name < 0")
		("pack_msg", "parambuf.packGlobalCounter($name);")
	;
	typesystem.defineType( "Index")
		("pack_msg", "parambuf.packIndex($name);")
	;
	typesystem.defineType( "IndexRange")
		("pack_msg", "parambuf.packIndexRange($name);")
	;
	typesystem.defineType( "const analyzer::SegmenterOptions&")
		("pack_msg", "parambuf.packAnalyzerSegmenterOptions($name);")
	;
	typesystem.defineType( "analyzer::SegmenterOptions")
		("pack_msg", "parambuf.packAnalyzerSegmenterOptions($name);")
	;
	typesystem.defineType( "const SegmenterPosition&")
		("pack_msg", "parambuf.packGlobalCounter($name);")
	;
	typesystem.defineType( "SegmenterPosition&")
		("pack_msg", "parambuf.packGlobalCounter($name);")
	;
	typesystem.defineType( "unsigned char")
		("pack_msg", "parambuf.packUInt8($name);")
	;
	typesystem.defineType( "char")
		("pack_msg", "parambuf.packInt8($name);")
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
	typesystem.defineType( "std::vector<VectorQueryResult>")
		("scopedtype", "std::vector<VectorQueryResult>")
		("pack_msg", "parambuf.packVectorQueryResult($name);")
	;
	typesystem.defineType( "SentenceTerm")
		("pack_msg", "parambuf.packSentenceTerm($name);")
	;
	typesystem.defineType( "const SentenceTerm&")
		("pack_msg", "parambuf.packSentenceTerm($name);")
	;
	typesystem.defineType( "SentenceTermList")
		("pack_msg", "parambuf.packSentenceTermVector($name);")
	;
	typesystem.defineType( "const SentenceTermList&")
		("pack_msg", "parambuf.packSentenceTermVector($name);")
	;
	typesystem.defineType( "std::vector<SentenceTermList>")
		("pack_msg", "parambuf.packSentenceTermListVector($name);")
	;
	typesystem.defineType( "const std::vector<SentenceTermList>&")
		("pack_msg", "parambuf.packSentenceTermListVector($name);")
	;
	typesystem.defineType( "SentenceGuess")
		("pack_msg", "parambuf.packSentenceGuess($name);")
	;
	typesystem.defineType( "const SentenceGuess&")
		("pack_msg", "parambuf.packSentenceGuess($name);")
	;
	typesystem.defineType( "std::vector<SentenceGuess>")
		("pack_msg", "parambuf.packSentenceGuessVector($name);")
	;
	typesystem.defineType( "const std::vector<SentenceGuess>&")
		("pack_msg", "parambuf.packSentenceGuessVector($name);")
	;
	typesystem.defineType( "const std::vector<unsigned int>&")
		("pack_msg", "parambuf.packUintVector($name);")
	;
	typesystem.defineType( "std::vector<unsigned int>")
		("pack_msg", "parambuf.packUintVector($name);")
	;
	typesystem.defineType( "const std::vector<int>&")
		("pack_msg", "parambuf.packIntVector($name);")
	;
	typesystem.defineType( "std::vector<int>")
		("pack_msg", "parambuf.packIntVector($name);")
	;
	typesystem.defineType( "const std::vector<double>&")
		("pack_msg", "parambuf.packDoubleVector($name);")
	;
	typesystem.defineType( "std::vector<double>")
		("pack_msg", "parambuf.packDoubleVector($name);")
	;
	typesystem.defineType( "const std::vector<float>&")
		("pack_msg", "parambuf.packFloatVector($name);")
	;
	typesystem.defineType( "std::vector<float>")
		("pack_msg", "parambuf.packFloatVector($name);")
	;
	typesystem.defineType( "const WordVector&")
		("pack_msg", "parambuf.packFloatVector($name);")
	;
	typesystem.defineType( "WordVector")
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
	typesystem.defineType( "const double* $bufname, unsigned int")
		("test_null", "$bufname == 0")
		("pass_param", "$bufname, $name")
		("pack_msg", "parambuf.packBufferFloat( $bufname, $name);")
	;
	typesystem.defineType( "const void* $bufname, std::size_t")
		("pass_param", "$bufname, $name")
		("pack_msg", "parambuf.packBlob( $bufname, $name);")
	;
	typesystem.defineType( "const void*& $bufname, std::size_t&")
		("test_null", "$bufname == 0")
		("pass_param", "$bufname, $name")
		("pack_msg", "parambuf.packBlob( $bufname, $name);")
	;
	typesystem.defineType( "const NumericVariant&")
		("pack_msg", "parambuf.packNumericVariant($name);")
	;
	typesystem.defineType( "NumericVariant")
		("test_null", "!$name.defined()")
		("pack_msg", "parambuf.packNumericVariant($name);")
	;
	typesystem.defineType( "const analyzer::DocumentClass&")
		("pack_msg", "parambuf.packAnalyzerDocumentClass($name);")
	;
	typesystem.defineType( "analyzer::DocumentClass&")
		("pack_msg", "parambuf.packAnalyzerDocumentClass($name);")
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
	typesystem.defineType( "const MetaDataRestrictionInterface::CompareOperator&")
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
	typesystem.defineType( "const ConfigType&", "VectorStorage")
		("pack_msg", "parambuf.packVectorStorageConfigType($name);")
	;
	typesystem.defineType( "const analyzer::FeatureOptions&")
		("pack_msg", "parambuf.packFeatureOptions($name);")
	;
	typesystem.defineType( "const GroupBy&", "QueryAnalyzer")
		("pack_msg", "parambuf.packAnalyzerQueryGroupBy($name);")
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
	typesystem.defineType( "const TimeStamp&")
		("pack_msg", "parambuf.packTimeStamp($name);")
	;
	typesystem.defineType( "const std::vector<TimeStamp>&")
		("pack_msg", "parambuf.packTimeStampVector($name);")
	;
	typesystem.defineType( "std::vector<TimeStamp>")
		("pack_msg", "parambuf.packTimeStampVector($name);")
	;
	typesystem.defineType( "StatisticsMessage")
		("pack_msg", "parambuf.packStatisticsMessage($name);")
	;
	typesystem.defineType( "const analyzer::QueryTermExpression&")
		("pack_msg", "parambuf.packAnalyzerQueryTermExpression($name);")
	;
	typesystem.defineType( "analyzer::QueryTermExpression")
		("pack_msg", "parambuf.packAnalyzerQueryTermExpression($name);")
	;
	typesystem.defineType( "const analyzer::QueryTerm&")
		("pack_msg", "parambuf.packAnalyzerQueryTerm($name);")
	;
	typesystem.defineType( "std::vector<analyzer::QueryTerm>")
		("pack_msg", "parambuf.packAnalyzerQueryTermArray($name);")
	;
	typesystem.defineType( "analyzer::Query")
		("pack_msg", "parambuf.packAnalyzerQuery($name);")
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
	typesystem.defineType( "const analyzer::DocumentAttribute&")
		("pack_msg", "parambuf.packAnalyzerDocumentAttribute($name);")
	;
	typesystem.defineType( "const analyzer::DocumentMetaData&")
		("pack_msg", "parambuf.packAnalyzerDocumentMetaData($name);")
	;
	typesystem.defineType( "const analyzer::DocumentTerm&")
		("pack_msg", "parambuf.packAnalyzerDocumentTerm($name);")
	;
	typesystem.defineType( "std::vector<analyzer::DocumentTerm>")
		("pack_msg", "parambuf.packAnalyzerDocumentTermArray($name);")
	;
	typesystem.defineType( "const std::vector<analyzer::DocumentTerm>&")
		("pack_msg", "parambuf.packAnalyzerDocumentTermArray($name);")
	;
	typesystem.defineType( "const analyzer::Position&")
		("pack_msg", "parambuf.packAnalyzerPosition($name);")
	;
	typesystem.defineType( "const analyzer::Token&")
		("pack_msg", "parambuf.packAnalyzerToken($name);")
	;
	typesystem.defineType( "const analyzer::PatternLexem&")
		("pack_msg", "parambuf.packAnalyzerPatternLexem($name);")
	;
	typesystem.defineType( "std::vector<analyzer::Token>")
		("pack_msg", "parambuf.packAnalyzerTokenVector($name);")
	;
	typesystem.defineType( "std::vector<analyzer::PatternLexem>")
		("pack_msg", "parambuf.packAnalyzerPatternLexemVector($name);")
	;
	typesystem.defineType( "analyzer::PositionBind")
		("pack_msg", "parambuf.packAnalyzerPositionBind($name);")
	;
	typesystem.defineType( "const analyzer::TokenMarkup&")
		("pack_msg", "parambuf.packAnalyzerTokenMarkup($name);")
	;
	typesystem.defineType( "analyzer::FunctionView")
		("pack_msg", "parambuf.packAnalyzerFunctionView($name);")
	;
	typesystem.defineType( "analyzer::FeatureView")
		("pack_msg", "parambuf.packAnalyzerFeatureView($name);")
	;
	typesystem.defineType( "analyzer::AggregatorView")
		("pack_msg", "parambuf.packAnalyzerAggregatorView($name);")
	;
	typesystem.defineType( "analyzer::SubDocumentDefinitionView")
		("pack_msg", "parambuf.packAnalyzerSubDocumentDefinitionView($name);")
	;
	typesystem.defineType( "analyzer::SubContentDefinitionView")
		("pack_msg", "parambuf.packAnalyzerSubContentDefinitionView($name);")
	;
	typesystem.defineType( "analyzer::DocumentAnalyzerView")
		("pack_msg", "parambuf.packAnalyzerDocumentAnalyzerView($name);")
	;
	typesystem.defineType( "analyzer::DocumentAnalyzerMapView")
		("pack_msg", "parambuf.packAnalyzerDocumentAnalyzerMapView($name);")
	;
	typesystem.defineType( "analyzer::QueryElementView")
		("pack_msg", "parambuf.packAnalyzerQueryElementView($name);")
	;
	typesystem.defineType( "analyzer::QueryAnalyzerView")
		("pack_msg", "parambuf.packAnalyzerQueryAnalyzerView($name);")
	;
	typesystem.defineType( "analyzer::ContentStatisticsElementView")
		("pack_msg", "parambuf.packAnalyzerContentStatisticsElementView($name);")
	;
	typesystem.defineType( "analyzer::ContentStatisticsView")
		("pack_msg", "parambuf.packAnalyzerContentStatisticsView($name);")
	;
	typesystem.defineType( "std::vector<analyzer::PatternMatcherResult>")
		("pack_msg", "parambuf.packAnalyzerPatternMatcherResultVector($name);")
	;
	typesystem.defineType( "const std::vector<analyzer::PatternMatcherResult>&")
		("pack_msg", "parambuf.packAnalyzerPatternMatcherResultVector($name);")
	;
	typesystem.defineType( "analyzer::PatternMatcherStatistics")
		("pack_msg", "parambuf.packAnalyzerPatternMatcherStatistics($name);")
	;
	typesystem.defineType( "PatternMatcherInstanceInterface::JoinOperation")
		("pack_msg", "parambuf.packPatternMatcherJoinOperation($name);")
	;
	typesystem.defineType( "JoinOperation")
		("pack_msg", "parambuf.packPatternMatcherJoinOperation($name);")
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
	typesystem.defineType( "const std::vector<Element>&", "PosTaggerDataInterface")
		("pack_msg", "parambuf.packPosTaggerDataElementVector($name);")
	;
	typesystem.defineType( "TermStatisticsChange&")
		("pack_msg", "parambuf.packTermStatisticsChange($name);")
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
	typesystem.defineType( "StructView")
		("pack_msg", "parambuf.packStructView($name);")
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
		("pack_msg", "{std::vector<Reference<$objid~Interface> >::const_iterator\n\ti_$name = $name.begin(), e_$name = $name.end();\nfor (std::size_t idx_$name=0; i_$name != e_$name; ++i_$name,++idx_$name)\n{\n\tparambuf.openIndex( idx_$name); \n\tconst TraceObjectBase* objbase = dynamic_cast<const TraceObjectBase*>( i_$name->get());\n\tif (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_$objid), objbase->objid());\n\tparambuf.close();\n}}")
	;
	typesystem.defineType( "const std::vector<$objid~Interface*>&")
		("pack_msg", "{std::vector<$objid~Interface*>::const_iterator\n\ti_$name = $name.begin(), e_$name = $name.end();\nfor (std::size_t idx_$name=0; i_$name != e_$name; ++i_$name,++idx_$name)\n{\n\tparambuf.openIndex( idx_$name); \n\tTraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_$name);\n\tif (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_$objid), objbase->objid());\n\tparambuf.close();\n}}")
		("delete", "{std::vector<$objid~Interface*>::const_iterator\n\ti_$name = $name.begin(), e_$name = $name.end();\nfor (std::size_t idx_$name=0; i_$name != e_$name; ++i_$name,++idx_$name)\n{\n\tdelete *i_$name;\n}}")
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
	typesystem.defineType( "std::vector<analyzer::ContentStatisticsItem>")
		("pack_msg", "parambuf.packAnalyzerContentStatisticsItemVector($name);")
	;
	typesystem.defineType( "analyzer::ContentStatisticsResult")
		("pack_msg", "parambuf.packAnalyzerContentStatisticsResult($name);")
	;
}

