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
	ClassId_NormalizerFunctionContext=19,
	ClassId_NormalizerFunctionInstance=20,
	ClassId_NormalizerFunction=21,
	ClassId_PatternLexerContext=22,
	ClassId_PatternLexerInstance=23,
	ClassId_PatternLexer=24,
	ClassId_PatternMatcherContext=25,
	ClassId_PatternMatcherInstance=26,
	ClassId_PatternMatcher=27,
	ClassId_PostingIterator=28,
	ClassId_PostingJoinOperator=29,
	ClassId_QueryAnalyzer=30,
	ClassId_QueryEval=31,
	ClassId_Query=32,
	ClassId_QueryProcessor=33,
	ClassId_ScalarFunctionInstance=34,
	ClassId_ScalarFunction=35,
	ClassId_ScalarFunctionParser=36,
	ClassId_SegmenterContext=37,
	ClassId_SegmenterInstance=38,
	ClassId_Segmenter=39,
	ClassId_SegmenterMarkupContext=40,
	ClassId_StatisticsBuilder=41,
	ClassId_StatisticsIterator=42,
	ClassId_StatisticsProcessor=43,
	ClassId_StatisticsViewer=44,
	ClassId_StorageAlterMetaDataTable=45,
	ClassId_StorageClient=46,
	ClassId_StorageDocument=47,
	ClassId_StorageDocumentUpdate=48,
	ClassId_StorageDump=49,
	ClassId_Storage=50,
	ClassId_StorageObjectBuilder=51,
	ClassId_StorageTransaction=52,
	ClassId_SummarizerFunctionContext=53,
	ClassId_SummarizerFunctionInstance=54,
	ClassId_SummarizerFunction=55,
	ClassId_TextProcessor=56,
	ClassId_TokenizerFunctionContext=57,
	ClassId_TokenizerFunctionInstance=58,
	ClassId_TokenizerFunction=59,
	ClassId_TokenMarkupContext=60,
	ClassId_TokenMarkupInstance=61,
	ClassId_ValueIterator=62,
	ClassId_VectorSpaceModelBuilder=63,
	ClassId_VectorSpaceModelInstance=64,
	ClassId_VectorSpaceModel=65,
	ClassId_WeightingFunctionContext=66,
	ClassId_WeightingFunctionInstance=67,
	ClassId_WeightingFunction=68
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
		Method_getSegmenter=2,
		Method_findMimeTypeSegmenter=3,
		Method_createDocumentAnalyzer=4,
		Method_createQueryAnalyzer=5
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
		Method_config=7
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
		Method_analyze=7,
		Method_createContext=8
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
		Method_hasElement=1,
		Method_elementHandle=2,
		Method_nofElements=3,
		Method_skipDoc=4,
		Method_getValue=5,
		Method_getType=6,
		Method_getName=7
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

class NormalizerFunctionContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_normalize=1
	};
	static const char* methodName( MethodId mid);
};

class NormalizerFunctionInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createFunctionContext=1
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
		Method_match=1
	};
	static const char* methodName( MethodId mid);
};

class PatternLexerInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_definePattern=1,
		Method_defineSymbol=2,
		Method_getSymbol=3,
		Method_compile=4,
		Method_createContext=5
	};
	static const char* methodName( MethodId mid);
};

class PatternLexerConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getCompileOptions=1,
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
		Method_getStatistics=3
	};
	static const char* methodName( MethodId mid);
};

class PatternMatcherInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_defineTermFrequency=1,
		Method_pushTerm=2,
		Method_pushExpression=3,
		Method_pushPattern=4,
		Method_attachVariable=5,
		Method_definePattern=6,
		Method_compile=7,
		Method_createContext=8
	};
	static const char* methodName( MethodId mid);
};

class PatternMatcherConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_getCompileOptions=1,
		Method_createInstance=2,
		Method_getDescription=3
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
		Method_posno=8
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

class QueryAnalyzerConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_definePhraseType=1,
		Method_analyzePhrase=2,
		Method_analyzePhraseBulk=3
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
		Method_pushExpression=2,
		Method_attachVariable=3,
		Method_defineFeature=4,
		Method_defineTermStatistics=5,
		Method_defineGlobalStatistics=6,
		Method_addMetaDataRestrictionCondition=7,
		Method_addDocumentEvaluationSet=8,
		Method_setMaxNofRanks=9,
		Method_setMinRank=10,
		Method_addUserName=11,
		Method_setWeightingVariableValue=12,
		Method_evaluate=13,
		Method_tostring=14
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
		Method_createInstance=2
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
		Method_createForwardIterator=4,
		Method_createDocumentTermIterator=5,
		Method_createInvAclIterator=6,
		Method_nofDocumentsInserted=7,
		Method_documentFrequency=8,
		Method_maxDocumentNumber=9,
		Method_documentNumber=10,
		Method_createTermTypeIterator=11,
		Method_createTermValueIterator=12,
		Method_createDocIdIterator=13,
		Method_createUserNameIterator=14,
		Method_documentStatistics=15,
		Method_createMetaDataReader=16,
		Method_createMetaDataRestriction=17,
		Method_createAttributeReader=18,
		Method_createTransaction=19,
		Method_createInitStatisticsIterator=20,
		Method_createUpdateStatisticsIterator=21,
		Method_getStatisticsProcessor=22,
		Method_createDocumentChecker=23,
		Method_checkStorage=24,
		Method_createDump=25
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
		Method_setMetaData=1,
		Method_setAttribute=2,
		Method_clearAttribute=3,
		Method_setUserAccessRight=4,
		Method_clearUserAccessRight=5,
		Method_clearUserAccessRights=6,
		Method_done=7
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
		Method_getConfigParameters=5
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
		Method_getVectorSpaceModel=5,
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
		Method_commit=6,
		Method_rollback=7
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
		Method_getSummary=2
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
		Method_createFunctionContext=3,
		Method_tostring=4
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
		Method_getTokenizer=3,
		Method_getNormalizer=4,
		Method_getAggregator=5,
		Method_getPatternLexer=6,
		Method_getPatternMatcher=7,
		Method_detectDocumentClass=8,
		Method_defineDocumentClassDetector=9,
		Method_defineTokenizer=10,
		Method_defineNormalizer=11,
		Method_defineAggregator=12,
		Method_definePatternLexer=13,
		Method_definePatternMatcher=14,
		Method_getFunctionList=15
	};
	static const char* methodName( MethodId mid);
};

class TokenizerFunctionContextConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_tokenize=1
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
		Method_createFunctionContext=2
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

class VectorSpaceModelBuilderConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_addFeature=1,
		Method_commit=2,
		Method_finalize=3
	};
	static const char* methodName( MethodId mid);
};

class VectorSpaceModelInstanceConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_mapVectorToConcepts=1,
		Method_featureConcepts=2,
		Method_featureVector=3,
		Method_featureName=4,
		Method_featureIndex=5,
		Method_conceptFeatures=6,
		Method_nofConcepts=7,
		Method_nofFeatures=8,
		Method_config=9
	};
	static const char* methodName( MethodId mid);
};

class VectorSpaceModelConst
{
public:
	enum MethodId
	{
		Method_Destructor=0,
		Method_createRepository=1,
		Method_resetRepository=2,
		Method_createInstance=3,
		Method_createBuilder=4
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
		Method_call=2
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
		Method_tostring=4
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

