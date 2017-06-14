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
	ClassId_AggregatorFunctionInstance=1,
	ClassId_AggregatorFunction=2,
	ClassId_AnalyzerObjectBuilder=3,
	ClassId_AttributeReader=4,
	ClassId_DatabaseBackupCursor=5,
	ClassId_DatabaseClient=6,
	ClassId_DatabaseCursor=7,
	ClassId_Database=8,
	ClassId_DatabaseTransaction=9,
	ClassId_DocumentAnalyzerContext=10,
	ClassId_DocumentAnalyzer=11,
	ClassId_DocumentClassDetector=12,
	ClassId_DocumentTermIterator=13,
	ClassId_ForwardIterator=14,
	ClassId_InvAclIterator=15,
	ClassId_MetaDataReader=16,
	ClassId_MetaDataRestrictionInstance=17,
	ClassId_MetaDataRestriction=18,
	ClassId_NormalizerFunctionInstance=19,
	ClassId_NormalizerFunction=20,
	ClassId_PatternLexerContext=21,
	ClassId_PatternLexerInstance=22,
	ClassId_PatternLexer=23,
	ClassId_PatternMatcherContext=24,
	ClassId_PatternMatcherInstance=25,
	ClassId_PatternMatcher=26,
	ClassId_PatternTermFeederInstance=27,
	ClassId_PatternTermFeeder=28,
	ClassId_PostingIterator=29,
	ClassId_PostingJoinOperator=30,
	ClassId_QueryAnalyzerContext=31,
	ClassId_QueryAnalyzer=32,
	ClassId_QueryEval=33,
	ClassId_Query=34,
	ClassId_QueryProcessor=35,
	ClassId_ScalarFunctionInstance=36,
	ClassId_ScalarFunction=37,
	ClassId_ScalarFunctionParser=38,
	ClassId_SegmenterContext=39,
	ClassId_SegmenterInstance=40,
	ClassId_Segmenter=41,
	ClassId_SegmenterMarkupContext=42,
	ClassId_StatisticsBuilder=43,
	ClassId_StatisticsIterator=44,
	ClassId_StatisticsProcessor=45,
	ClassId_StatisticsViewer=46,
	ClassId_StorageAlterMetaDataTable=47,
	ClassId_StorageClient=48,
	ClassId_StorageDocument=49,
	ClassId_StorageDocumentUpdate=50,
	ClassId_StorageDump=51,
	ClassId_Storage=52,
	ClassId_StorageObjectBuilder=53,
	ClassId_StorageTransaction=54,
	ClassId_SummarizerFunctionContext=55,
	ClassId_SummarizerFunctionInstance=56,
	ClassId_SummarizerFunction=57,
	ClassId_TextProcessor=58,
	ClassId_TokenizerFunctionInstance=59,
	ClassId_TokenizerFunction=60,
	ClassId_TokenMarkupContext=61,
	ClassId_TokenMarkupInstance=62,
	ClassId_ValueIterator=63,
	ClassId_VectorStorageClient=64,
	ClassId_VectorStorageDump=65,
	ClassId_VectorStorage=66,
	ClassId_VectorStorageSearch=67,
	ClassId_VectorStorageTransaction=68,
	ClassId_WeightingFunctionContext=69,
	ClassId_WeightingFunctionInstance=70,
	ClassId_WeightingFunction=71
};

struct TraceClassNameMap
{
	static const char* className( unsigned int classId);
};

class AggregatorFunctionInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_evaluate=1
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
		Method_getDescription=2
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
		Method_createQueryAnalyzer=3
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
		Method_getAttributeNames=4
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
		Method_close=7,
		Method_config=8
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

class DocumentAnalyzerConst
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
		Method_definePatternMatcherPostProc=9,
		Method_definePatternMatcherPreProc=10,
		Method_addSearchIndexFeatureFromPatternMatch=11,
		Method_addForwardIndexFeatureFromPatternMatch=12,
		Method_defineMetaDataFromPatternMatch=13,
		Method_defineAttributeFromPatternMatch=14,
		Method_analyze=15,
		Method_createContext=16
	};
	static const char* methodName( MethodId mid);
};

class DocumentClassDetectorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_detect=1
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
		Method_getName=6
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
		Method_normalize=1
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
		Method_getDescription=2
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
		Method_defineLexem=2,
		Method_defineSymbol=3,
		Method_getSymbol=4,
		Method_compile=5,
		Method_createContext=6
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
		Method_getDescription=3
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
		Method_createContext=9
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
		Method_getDescription=3
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
		Method_getSymbol=5
	};
	static const char* methodName( MethodId mid);
};

class PatternTermFeederConst
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
		Method_getDescription=2
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

class QueryAnalyzerConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addSearchIndexElement=1,
		Method_addMetaDataElement=2,
		Method_addPatternLexem=3,
		Method_definePatternMatcherPostProc=4,
		Method_definePatternMatcherPreProc=5,
		Method_addSearchIndexElementFromPatternMatch=6,
		Method_addMetaDataElementFromPatternMatch=7,
		Method_createContext=8
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
		Method_addSummarizerFunction=5,
		Method_addWeightingFunction=6,
		Method_defineWeightingFormula=7,
		Method_createQuery=8
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
		Method_setMaxNofRanks=10,
		Method_setMinRank=11,
		Method_addUserName=12,
		Method_setWeightingVariableValue=13,
		Method_setDebugMode=14,
		Method_evaluate=15,
		Method_tostring=16
	};
	static const char* methodName( MethodId mid);
};

class QueryProcessorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_definePostingJoinOperator=1,
		Method_getPostingJoinOperator=2,
		Method_defineWeightingFunction=3,
		Method_getWeightingFunction=4,
		Method_defineSummarizerFunction=5,
		Method_getSummarizerFunction=6,
		Method_getFunctionList=7,
		Method_defineScalarFunctionParser=8,
		Method_getScalarFunctionParser=9
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
		Method_tostring=3
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
		Method_tostring=5
	};
	static const char* methodName( MethodId mid);
};

class ScalarFunctionParserConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createFunction=1
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
		Method_createMarkupContext=4
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
		Method_getDescription=3
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

class StatisticsBuilderConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_setNofDocumentsInsertedChange=1,
		Method_addDfChange=2,
		Method_start=3,
		Method_rollback=4,
		Method_fetchMessage=5
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

class StatisticsProcessorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createViewer=1,
		Method_createBuilder=2
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

class StorageAlterMetaDataTableConst
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

class StorageClientConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_config=1,
		Method_createTermPostingIterator=2,
		Method_createBrowsePostingIterator=3,
		Method_createFieldPostingIterator=4,
		Method_createForwardIterator=5,
		Method_createDocumentTermIterator=6,
		Method_createInvAclIterator=7,
		Method_nofDocumentsInserted=8,
		Method_documentFrequency=9,
		Method_maxDocumentNumber=10,
		Method_documentNumber=11,
		Method_createTermTypeIterator=12,
		Method_createTermValueIterator=13,
		Method_createDocIdIterator=14,
		Method_createUserNameIterator=15,
		Method_documentStatistics=16,
		Method_createMetaDataReader=17,
		Method_createMetaDataRestriction=18,
		Method_createAttributeReader=19,
		Method_createTransaction=20,
		Method_createAllStatisticsIterator=21,
		Method_createChangeStatisticsIterator=22,
		Method_getStatisticsProcessor=23,
		Method_createDocumentChecker=24,
		Method_checkStorage=25,
		Method_close=26
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
		Method_addForwardIndexTerm=2,
		Method_setMetaData=3,
		Method_setAttribute=4,
		Method_setUserAccessRight=5,
		Method_done=6
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
		Method_addForwardIndexTerm=2,
		Method_clearSearchIndexTerm=3,
		Method_clearForwardIndexTerm=4,
		Method_setMetaData=5,
		Method_setAttribute=6,
		Method_clearAttribute=7,
		Method_setUserAccessRight=8,
		Method_clearUserAccessRight=9,
		Method_clearUserAccessRights=10,
		Method_done=11
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
		Method_createAlterMetaDataTable=3,
		Method_getConfigDescription=4,
		Method_getConfigParameters=5,
		Method_createDump=6
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
		Method_createQueryEval=6
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
		Method_tostring=6
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
		Method_getDescription=2
	};
	static const char* methodName( MethodId mid);
};

class TextProcessorConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addResourcePath=1,
		Method_getResourcePath=2,
		Method_getSegmenterByName=3,
		Method_getSegmenterByMimeType=4,
		Method_getSegmenterOptions=5,
		Method_getTokenizer=6,
		Method_getNormalizer=7,
		Method_getAggregator=8,
		Method_getPatternLexer=9,
		Method_getPatternMatcher=10,
		Method_getPatternTermFeeder=11,
		Method_detectDocumentClass=12,
		Method_defineDocumentClassDetector=13,
		Method_defineSegmenter=14,
		Method_defineSegmenterOptions=15,
		Method_defineTokenizer=16,
		Method_defineNormalizer=17,
		Method_defineAggregator=18,
		Method_definePatternLexer=19,
		Method_definePatternMatcher=20,
		Method_getFunctionList=21
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
		Method_tokenize=2
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
		Method_getDescription=2
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
		Method_createContext=1
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
		Method_fetchValues=2
	};
	static const char* methodName( MethodId mid);
};

class VectorStorageClientConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createSearcher=1,
		Method_createTransaction=2,
		Method_conceptClassNames=3,
		Method_conceptFeatures=4,
		Method_nofConcepts=5,
		Method_featureConcepts=6,
		Method_featureVector=7,
		Method_featureName=8,
		Method_featureIndex=9,
		Method_vectorSimilarity=10,
		Method_nofFeatures=11,
		Method_config=12
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
		Method_runBuild=4
	};
	static const char* methodName( MethodId mid);
};

class VectorStorageSearchConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_findSimilar=1,
		Method_findSimilarFromSelection=2,
		Method_close=3
	};
	static const char* methodName( MethodId mid);
};

class VectorStorageTransactionConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addFeature=1,
		Method_defineFeatureConceptRelation=2,
		Method_commit=3,
		Method_rollback=4
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
		Method_tostring=5
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
		Method_getDescription=2
	};
	static const char* methodName( MethodId mid);
};


}//namespace
#endif

