/*
* Copyright (c) 2016 Patrick P. Frey
*
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
/// \brief Identifiers for objects and methods for serialization
/// \note PROGRAM (strusTraceCodeGen) GENERATED FILE! DO NOT MODIFY!!!
/// \file objectIds_gen.hpp
#ifndef _STRUS_TRACE_PARSER_objectIds_gen_HPP_INCLUDED
#define _STRUS_TRACE_PARSER_objectIds_gen_HPP_INCLUDED
namespace strus {

enum ClassId
{
	ClassId_AclReader=1,
	ClassId_AggregatorFunctionInstance=2,
	ClassId_AggregatorFunction=3,
	ClassId_AnalyzerObjectBuilder=4,
	ClassId_AttributeReader=5,
	ClassId_ContentIterator=6,
	ClassId_ContentStatisticsContext=7,
	ClassId_ContentStatistics=8,
	ClassId_DatabaseBackupCursor=9,
	ClassId_DatabaseClient=10,
	ClassId_DatabaseCursor=11,
	ClassId_Database=12,
	ClassId_DatabaseTransaction=13,
	ClassId_DocumentAnalyzerContext=14,
	ClassId_DocumentAnalyzerInstance=15,
	ClassId_DocumentAnalyzerMap=16,
	ClassId_DocumentClassDetector=17,
	ClassId_DocumentTermIterator=18,
	ClassId_FileLocator=19,
	ClassId_ForwardIterator=20,
	ClassId_InvAclIterator=21,
	ClassId_MetaDataReader=22,
	ClassId_MetaDataRestrictionInstance=23,
	ClassId_MetaDataRestriction=24,
	ClassId_NormalizerFunctionInstance=25,
	ClassId_NormalizerFunction=26,
	ClassId_PatternLexerContext=27,
	ClassId_PatternLexerInstance=28,
	ClassId_PatternLexer=29,
	ClassId_PatternMatcherContext=30,
	ClassId_PatternMatcherInstance=31,
	ClassId_PatternMatcher=32,
	ClassId_PatternTermFeederInstance=33,
	ClassId_PatternTermFeeder=34,
	ClassId_PosTaggerContext=35,
	ClassId_PosTaggerData=36,
	ClassId_PosTaggerInstance=37,
	ClassId_PosTagger=38,
	ClassId_PostingIterator=39,
	ClassId_PostingJoinOperator=40,
	ClassId_QueryAnalyzerContext=41,
	ClassId_QueryAnalyzerInstance=42,
	ClassId_QueryEval=43,
	ClassId_Query=44,
	ClassId_QueryProcessor=45,
	ClassId_ScalarFunctionInstance=46,
	ClassId_ScalarFunction=47,
	ClassId_ScalarFunctionParser=48,
	ClassId_SegmenterContext=49,
	ClassId_SegmenterInstance=50,
	ClassId_Segmenter=51,
	ClassId_SegmenterMarkupContext=52,
	ClassId_SentenceAnalyzerInstance=53,
	ClassId_SentenceLexerContext=54,
	ClassId_SentenceLexerInstance=55,
	ClassId_StatisticsBuilder=56,
	ClassId_StatisticsIterator=57,
	ClassId_StatisticsMap=58,
	ClassId_StatisticsProcessor=59,
	ClassId_StatisticsViewer=60,
	ClassId_StorageClient=61,
	ClassId_StorageDocument=62,
	ClassId_StorageDocumentUpdate=63,
	ClassId_StorageDump=64,
	ClassId_Storage=65,
	ClassId_StorageMetaDataTransaction=66,
	ClassId_StorageObjectBuilder=67,
	ClassId_StorageTransaction=68,
	ClassId_StructIterator=69,
	ClassId_SummarizerFunctionContext=70,
	ClassId_SummarizerFunctionInstance=71,
	ClassId_SummarizerFunction=72,
	ClassId_TextProcessor=73,
	ClassId_TokenizerFunctionInstance=74,
	ClassId_TokenizerFunction=75,
	ClassId_TokenMarkupContext=76,
	ClassId_TokenMarkupInstance=77,
	ClassId_ValueIterator=78,
	ClassId_VectorStorageClient=79,
	ClassId_VectorStorageDump=80,
	ClassId_VectorStorage=81,
	ClassId_VectorStorageTransaction=82,
	ClassId_WeightingFunctionContext=83,
	ClassId_WeightingFunctionInstance=84,
	ClassId_WeightingFunction=85
};

struct TraceClassNameMap
{
	static const char* className( unsigned int classId);
};

class AclReaderConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_skipDoc=1,
		Method_getReadAccessList=2
	};
	static const char* methodName( MethodId mid);
};

class AggregatorFunctionInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_evaluate=1,
		Method_name=2,
		Method_view=3
	};
	static const char* methodName( MethodId mid);
};

class AggregatorFunctionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createInstance=1,
		Method_name=2,
		Method_view=3
	};
	static const char* methodName( MethodId mid);
};

class AnalyzerObjectBuilderConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getTextProcessor=1,
		Method_createDocumentAnalyzer=2,
		Method_createPosTaggerInstance=3,
		Method_createQueryAnalyzer=4,
		Method_createDocumentAnalyzerMap=5,
		Method_createDocumentClassDetector=6,
		Method_createContentStatistics=7
	};
	static const char* methodName( MethodId mid);
};

class AttributeReaderConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_elementHandle=1,
		Method_skipDoc=2,
		Method_getValue=3,
		Method_getNames=4
	};
	static const char* methodName( MethodId mid);
};

class ContentIteratorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getNext=1
	};
	static const char* methodName( MethodId mid);
};

class ContentStatisticsContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_putContent=1,
		Method_statistics=2,
		Method_nofDocuments=3
	};
	static const char* methodName( MethodId mid);
};

class ContentStatisticsConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addLibraryElement=1,
		Method_addVisibleAttribute=2,
		Method_addSelectorExpression=3,
		Method_createContext=4,
		Method_view=5
	};
	static const char* methodName( MethodId mid);
};

class DatabaseBackupCursorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_fetch=1
	};
	static const char* methodName( MethodId mid);
};

class DatabaseClientConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createTransaction=1,
		Method_createCursor=2,
		Method_createBackupCursor=3,
		Method_writeImm=4,
		Method_removeImm=5,
		Method_readValue=6,
		Method_config=7,
		Method_compactDatabase=8,
		Method_close=9
	};
	static const char* methodName( MethodId mid);
};

class DatabaseCursorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_seekUpperBound=1,
		Method_seekUpperBoundRestricted=2,
		Method_seekFirst=3,
		Method_seekLast=4,
		Method_seekNext=5,
		Method_seekPrev=6,
		Method_key=7,
		Method_value=8
	};
	static const char* methodName( MethodId mid);
};

class DatabaseConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_exists=1,
		Method_createClient=2,
		Method_createDatabase=3,
		Method_restoreDatabase=4,
		Method_destroyDatabase=5,
		Method_getConfigDescription=6,
		Method_getConfigParameters=7
	};
	static const char* methodName( MethodId mid);
};

class DatabaseTransactionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createCursor=1,
		Method_write=2,
		Method_remove=3,
		Method_removeSubTree=4,
		Method_commit=5,
		Method_rollback=6
	};
	static const char* methodName( MethodId mid);
};

class DocumentAnalyzerContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_putInput=1,
		Method_analyzeNext=2
	};
	static const char* methodName( MethodId mid);
};

class DocumentAnalyzerInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addSearchIndexFeature=1,
		Method_addForwardIndexFeature=2,
		Method_defineMetaData=3,
		Method_defineAggregatedMetaData=4,
		Method_defineAttribute=5,
		Method_defineSubDocument=6,
		Method_defineSubContent=7,
		Method_addPatternLexem=8,
		Method_defineTokenPatternMatcher=9,
		Method_defineContentPatternMatcher=10,
		Method_addSearchIndexFeatureFromPatternMatch=11,
		Method_addForwardIndexFeatureFromPatternMatch=12,
		Method_defineMetaDataFromPatternMatch=13,
		Method_defineAttributeFromPatternMatch=14,
		Method_analyze=15,
		Method_createContext=16,
		Method_view=17
	};
	static const char* methodName( MethodId mid);
};

class DocumentAnalyzerMapConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createAnalyzer=1,
		Method_addAnalyzer=2,
		Method_getAnalyzer=3,
		Method_analyze=4,
		Method_createContext=5,
		Method_view=6
	};
	static const char* methodName( MethodId mid);
};

class DocumentClassDetectorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_defineDocumentSchemaDetector=1,
		Method_detect=2,
		Method_view=3
	};
	static const char* methodName( MethodId mid);
};

class DocumentTermIteratorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_skipDoc=1,
		Method_nextTerm=2,
		Method_termDocumentFrequency=3,
		Method_termValue=4
	};
	static const char* methodName( MethodId mid);
};

class FileLocatorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addResourcePath=1,
		Method_getResourceFilePath=2,
		Method_defineWorkingDirectory=3,
		Method_getWorkingDirectory=4,
		Method_getResourcePaths=5
	};
	static const char* methodName( MethodId mid);
};

class ForwardIteratorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_skipDoc=1,
		Method_skipPos=2,
		Method_fetch=3
	};
	static const char* methodName( MethodId mid);
};

class InvAclIteratorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_skipDoc=1
	};
	static const char* methodName( MethodId mid);
};

class MetaDataReaderConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_elementHandle=1,
		Method_nofElements=2,
		Method_skipDoc=3,
		Method_getValue=4,
		Method_getType=5,
		Method_getName=6,
		Method_getNames=7
	};
	static const char* methodName( MethodId mid);
};

class MetaDataRestrictionInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_match=1
	};
	static const char* methodName( MethodId mid);
};

class MetaDataRestrictionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addCondition=1,
		Method_createInstance=2,
		Method_tostring=3
	};
	static const char* methodName( MethodId mid);
};

class NormalizerFunctionInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_normalize=1,
		Method_name=2,
		Method_view=3
	};
	static const char* methodName( MethodId mid);
};

class NormalizerFunctionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createInstance=1,
		Method_name=2,
		Method_view=3
	};
	static const char* methodName( MethodId mid);
};

class PatternLexerContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_match=1,
		Method_reset=2
	};
	static const char* methodName( MethodId mid);
};

class PatternLexerInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_defineOption=1,
		Method_defineLexemName=2,
		Method_defineLexem=3,
		Method_defineSymbol=4,
		Method_getSymbol=5,
		Method_getLexemName=6,
		Method_compile=7,
		Method_createContext=8,
		Method_name=9,
		Method_view=10
	};
	static const char* methodName( MethodId mid);
};

class PatternLexerConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getCompileOptionNames=1,
		Method_createInstance=2,
		Method_name=3,
		Method_view=4
	};
	static const char* methodName( MethodId mid);
};

class PatternMatcherContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_putInput=1,
		Method_fetchResults=2,
		Method_getStatistics=3,
		Method_reset=4
	};
	static const char* methodName( MethodId mid);
};

class PatternMatcherInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_defineOption=1,
		Method_defineTermFrequency=2,
		Method_pushTerm=3,
		Method_pushExpression=4,
		Method_pushPattern=5,
		Method_attachVariable=6,
		Method_definePattern=7,
		Method_compile=8,
		Method_createContext=9,
		Method_name=10,
		Method_view=11
	};
	static const char* methodName( MethodId mid);
};

class PatternMatcherConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getCompileOptionNames=1,
		Method_createInstance=2,
		Method_name=3,
		Method_view=4
	};
	static const char* methodName( MethodId mid);
};

class PatternTermFeederInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_defineLexem=1,
		Method_defineSymbol=2,
		Method_getLexem=3,
		Method_lexemTypes=4,
		Method_getSymbol=5,
		Method_name=6,
		Method_view=7
	};
	static const char* methodName( MethodId mid);
};

class PatternTermFeederConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createInstance=1,
		Method_name=2,
		Method_view=3
	};
	static const char* methodName( MethodId mid);
};

class PosTaggerContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_markupDocument=1
	};
	static const char* methodName( MethodId mid);
};

class PosTaggerDataConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_declareIgnoredToken=1,
		Method_insert=2,
		Method_markupSegment=3
	};
	static const char* methodName( MethodId mid);
};

class PosTaggerInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addContentExpression=1,
		Method_addPosTaggerInputPunctuation=2,
		Method_getPosTaggerInput=3,
		Method_markupDocument=4
	};
	static const char* methodName( MethodId mid);
};

class PosTaggerConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createInstance=1
	};
	static const char* methodName( MethodId mid);
};

class PostingIteratorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_skipDoc=1,
		Method_skipDocCandidate=2,
		Method_skipPos=3,
		Method_featureid=4,
		Method_documentFrequency=5,
		Method_frequency=6,
		Method_docno=7,
		Method_posno=8,
		Method_length=9
	};
	static const char* methodName( MethodId mid);
};

class PostingJoinOperatorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createResultIterator=1,
		Method_name=2,
		Method_view=3
	};
	static const char* methodName( MethodId mid);
};

class QueryAnalyzerContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_putField=1,
		Method_groupElements=2,
		Method_analyze=3
	};
	static const char* methodName( MethodId mid);
};

class QueryAnalyzerInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addElement=1,
		Method_addPatternLexem=2,
		Method_defineTokenPatternMatcher=3,
		Method_defineContentPatternMatcher=4,
		Method_addElementFromPatternMatch=5,
		Method_queryTermTypes=6,
		Method_queryFieldTypes=7,
		Method_createContext=8,
		Method_view=9
	};
	static const char* methodName( MethodId mid);
};

class QueryEvalConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addTerm=1,
		Method_addSelectionFeature=2,
		Method_addRestrictionFeature=3,
		Method_addExclusionFeature=4,
		Method_getWeightingFeatureSets=5,
		Method_getSelectionFeatureSets=6,
		Method_getRestrictionFeatureSets=7,
		Method_getExclusionFeatureSets=8,
		Method_addSummarizerFunction=9,
		Method_addWeightingFunction=10,
		Method_defineWeightingFormula=11,
		Method_createQuery=12,
		Method_view=13
	};
	static const char* methodName( MethodId mid);
};

class QueryConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_pushTerm=1,
		Method_pushDocField=2,
		Method_pushExpression=3,
		Method_attachVariable=4,
		Method_defineFeature=5,
		Method_defineTermStatistics=6,
		Method_defineGlobalStatistics=7,
		Method_addMetaDataRestrictionCondition=8,
		Method_addDocumentEvaluationSet=9,
		Method_addAccess=10,
		Method_setWeightingVariableValue=11,
		Method_setDebugMode=12,
		Method_evaluate=13,
		Method_view=14
	};
	static const char* methodName( MethodId mid);
};

class QueryProcessorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getResourceFilePath=1,
		Method_definePostingJoinOperator=2,
		Method_getPostingJoinOperator=3,
		Method_defineWeightingFunction=4,
		Method_getWeightingFunction=5,
		Method_defineSummarizerFunction=6,
		Method_getSummarizerFunction=7,
		Method_getFunctionList=8,
		Method_defineScalarFunctionParser=9,
		Method_getScalarFunctionParser=10
	};
	static const char* methodName( MethodId mid);
};

class ScalarFunctionInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_setVariableValue=1,
		Method_call=2,
		Method_name=3,
		Method_view=4
	};
	static const char* methodName( MethodId mid);
};

class ScalarFunctionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getVariables=1,
		Method_getNofArguments=2,
		Method_setDefaultVariableValue=3,
		Method_createInstance=4,
		Method_name=5,
		Method_view=6
	};
	static const char* methodName( MethodId mid);
};

class ScalarFunctionParserConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createFunction=1,
		Method_view=2
	};
	static const char* methodName( MethodId mid);
};

class SegmenterContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_putInput=1,
		Method_getNext=2
	};
	static const char* methodName( MethodId mid);
};

class SegmenterInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_defineSelectorExpression=1,
		Method_defineSubSection=2,
		Method_createContext=3,
		Method_createMarkupContext=4,
		Method_name=5,
		Method_view=6
	};
	static const char* methodName( MethodId mid);
};

class SegmenterConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_mimeType=1,
		Method_createInstance=2,
		Method_createContentIterator=3,
		Method_name=4,
		Method_view=5
	};
	static const char* methodName( MethodId mid);
};

class SegmenterMarkupContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getNext=1,
		Method_segmentSize=2,
		Method_tagName=3,
		Method_tagLevel=4,
		Method_putOpenTag=5,
		Method_putAttribute=6,
		Method_putCloseTag=7,
		Method_getContent=8
	};
	static const char* methodName( MethodId mid);
};

class SentenceAnalyzerInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_pushTerm=1,
		Method_pushNone=2,
		Method_pushAlt=3,
		Method_pushSequenceImm=4,
		Method_pushRepeat=5,
		Method_defineSentence=6,
		Method_compile=7,
		Method_analyzeSentence=8
	};
	static const char* methodName( MethodId mid);
};

class SentenceLexerContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_fetchFirstSplit=1,
		Method_fetchNextSplit=2,
		Method_nofTokens=3,
		Method_featureValue=4,
		Method_featureTypes=5,
		Method_rankSentences=6
	};
	static const char* methodName( MethodId mid);
};

class SentenceLexerInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addSeparator=1,
		Method_addSpace=2,
		Method_addLink=3,
		Method_defineGroupSimilarityDistance=4,
		Method_createContext=5
	};
	static const char* methodName( MethodId mid);
};

class StatisticsBuilderConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addNofDocumentsInsertedChange=1,
		Method_addDfChange=2,
		Method_createIteratorAndRollback=3,
		Method_commit=4,
		Method_rollback=5,
		Method_releaseStatistics=6
	};
	static const char* methodName( MethodId mid);
};

class StatisticsIteratorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getNext=1
	};
	static const char* methodName( MethodId mid);
};

class StatisticsMapConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addNofDocumentsInsertedChange=1,
		Method_addDfChange=2,
		Method_processStatisticsMessage=3,
		Method_nofDocuments=4,
		Method_df=5,
		Method_types=6
	};
	static const char* methodName( MethodId mid);
};

class StatisticsProcessorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createViewer=1,
		Method_createIterator=2,
		Method_getChangeTimeStamps=3,
		Method_loadChangeMessage=4,
		Method_createBuilder=5,
		Method_createMap=6
	};
	static const char* methodName( MethodId mid);
};

class StatisticsViewerConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_nofDocumentsInsertedChange=1,
		Method_nextDfChange=2
	};
	static const char* methodName( MethodId mid);
};

class StorageClientConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_config=1,
		Method_createTermPostingIterator=2,
		Method_createStructIterator=3,
		Method_createBrowsePostingIterator=4,
		Method_createFieldPostingIterator=5,
		Method_createForwardIterator=6,
		Method_createDocumentTermIterator=7,
		Method_createInvAclIterator=8,
		Method_createAclReader=9,
		Method_nofDocumentsInserted=10,
		Method_documentFrequency=11,
		Method_maxDocumentNumber=12,
		Method_documentNumber=13,
		Method_termTypeNumber=14,
		Method_isForwardIndexTerm=15,
		Method_createTermTypeIterator=16,
		Method_createStructTypeIterator=17,
		Method_createTermValueIterator=18,
		Method_createDocIdIterator=19,
		Method_createUserNameIterator=20,
		Method_documentStatistics=21,
		Method_createMetaDataReader=22,
		Method_createMetaDataRestriction=23,
		Method_createAttributeReader=24,
		Method_createTransaction=25,
		Method_createMetaDataTransaction=26,
		Method_createAllStatisticsIterator=27,
		Method_createChangeStatisticsIterator=28,
		Method_getChangeStatisticTimeStamps=29,
		Method_loadChangeStatisticsMessage=30,
		Method_getStatisticsProcessor=31,
		Method_createDocumentChecker=32,
		Method_createDump=33,
		Method_checkStorage=34,
		Method_close=35,
		Method_compaction=36
	};
	static const char* methodName( MethodId mid);
};

class StorageDocumentConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addSearchIndexTerm=1,
		Method_addSearchIndexStructure=2,
		Method_addForwardIndexTerm=3,
		Method_setMetaData=4,
		Method_setAttribute=5,
		Method_setUserAccessRight=6,
		Method_done=7
	};
	static const char* methodName( MethodId mid);
};

class StorageDocumentUpdateConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addSearchIndexTerm=1,
		Method_addSearchIndexStructure=2,
		Method_addForwardIndexTerm=3,
		Method_clearSearchIndexTerm=4,
		Method_clearSearchIndexStructure=5,
		Method_clearForwardIndexTerm=6,
		Method_setMetaData=7,
		Method_setAttribute=8,
		Method_clearAttribute=9,
		Method_setUserAccessRight=10,
		Method_clearUserAccessRight=11,
		Method_clearUserAccessRights=12,
		Method_done=13
	};
	static const char* methodName( MethodId mid);
};

class StorageDumpConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_nextChunk=1
	};
	static const char* methodName( MethodId mid);
};

class StorageConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createClient=1,
		Method_createStorage=2,
		Method_getConfigDescription=3,
		Method_getConfigParameters=4
	};
	static const char* methodName( MethodId mid);
};

class StorageMetaDataTransactionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addElement=1,
		Method_alterElement=2,
		Method_renameElement=3,
		Method_deleteElement=4,
		Method_clearElement=5,
		Method_commit=6,
		Method_rollback=7
	};
	static const char* methodName( MethodId mid);
};

class StorageObjectBuilderConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getStorage=1,
		Method_getDatabase=2,
		Method_getQueryProcessor=3,
		Method_getStatisticsProcessor=4,
		Method_getVectorStorage=5,
		Method_createQueryEval=6,
		Method_createSentenceAnalyzer=7
	};
	static const char* methodName( MethodId mid);
};

class StorageTransactionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createDocument=1,
		Method_createDocumentUpdate=2,
		Method_deleteDocument=3,
		Method_deleteUserAccessRights=4,
		Method_updateMetaData=5,
		Method_updateDocumentFrequency=6,
		Method_commit=7,
		Method_rollback=8,
		Method_nofDocumentsAffected=9
	};
	static const char* methodName( MethodId mid);
};

class StructIteratorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_skipDoc=1,
		Method_skipPosSource=2,
		Method_skipPosSink=3,
		Method_source=4,
		Method_sink=5
	};
	static const char* methodName( MethodId mid);
};

class SummarizerFunctionContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addSummarizationFeature=1,
		Method_setVariableValue=2,
		Method_getSummary=3,
		Method_debugCall=4
	};
	static const char* methodName( MethodId mid);
};

class SummarizerFunctionInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addStringParameter=1,
		Method_addNumericParameter=2,
		Method_defineResultName=3,
		Method_getVariables=4,
		Method_createFunctionContext=5,
		Method_name=6,
		Method_view=7
	};
	static const char* methodName( MethodId mid);
};

class SummarizerFunctionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createInstance=1,
		Method_name=2,
		Method_view=3
	};
	static const char* methodName( MethodId mid);
};

class TextProcessorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getResourceFilePath=1,
		Method_getSegmenterByName=2,
		Method_getSegmenterByMimeType=3,
		Method_getSegmenterOptions=4,
		Method_getTokenizer=5,
		Method_getNormalizer=6,
		Method_getAggregator=7,
		Method_getPatternLexer=8,
		Method_getPatternMatcher=9,
		Method_getPatternTermFeeder=10,
		Method_createPosTaggerData=11,
		Method_getPosTagger=12,
		Method_createTokenMarkupInstance=13,
		Method_detectDocumentClass=14,
		Method_defineDocumentClassDetector=15,
		Method_defineSegmenter=16,
		Method_defineSegmenterOptions=17,
		Method_defineTokenizer=18,
		Method_defineNormalizer=19,
		Method_defineAggregator=20,
		Method_definePatternLexer=21,
		Method_definePatternMatcher=22,
		Method_getFunctionList=23
	};
	static const char* methodName( MethodId mid);
};

class TokenizerFunctionInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_concatBeforeTokenize=1,
		Method_tokenize=2,
		Method_name=3,
		Method_view=4
	};
	static const char* methodName( MethodId mid);
};

class TokenizerFunctionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createInstance=1,
		Method_name=2,
		Method_view=3
	};
	static const char* methodName( MethodId mid);
};

class TokenMarkupContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_putMarkup=1,
		Method_markupDocument=2
	};
	static const char* methodName( MethodId mid);
};

class TokenMarkupInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createContext=1,
		Method_name=2,
		Method_view=3
	};
	static const char* methodName( MethodId mid);
};

class ValueIteratorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_skip=1,
		Method_skipPrefix=2,
		Method_fetchValues=3
	};
	static const char* methodName( MethodId mid);
};

class VectorStorageClientConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_prepareSearch=1,
		Method_findSimilar=2,
		Method_createTransaction=3,
		Method_types=4,
		Method_createFeatureValueIterator=5,
		Method_featureTypes=6,
		Method_nofTypes=7,
		Method_nofFeatures=8,
		Method_nofVectors=9,
		Method_featureVector=10,
		Method_vectorSimilarity=11,
		Method_normalize=12,
		Method_createSentenceLexer=13,
		Method_config=14,
		Method_close=15,
		Method_compaction=16
	};
	static const char* methodName( MethodId mid);
};

class VectorStorageDumpConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_nextChunk=1
	};
	static const char* methodName( MethodId mid);
};

class VectorStorageConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createStorage=1,
		Method_createClient=2,
		Method_createDump=3,
		Method_getConfigDescription=4,
		Method_getConfigParameters=5
	};
	static const char* methodName( MethodId mid);
};

class VectorStorageTransactionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_defineVector=1,
		Method_defineFeature=2,
		Method_clear=3,
		Method_commit=4,
		Method_rollback=5
	};
	static const char* methodName( MethodId mid);
};

class WeightingFunctionContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addWeightingFeature=1,
		Method_setVariableValue=2,
		Method_call=3,
		Method_debugCall=4
	};
	static const char* methodName( MethodId mid);
};

class WeightingFunctionInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addStringParameter=1,
		Method_addNumericParameter=2,
		Method_createFunctionContext=3,
		Method_getVariables=4,
		Method_name=5,
		Method_view=6
	};
	static const char* methodName( MethodId mid);
};

class WeightingFunctionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createInstance=1,
		Method_name=2,
		Method_view=3
	};
	static const char* methodName( MethodId mid);
};


}//namespace
#endif

