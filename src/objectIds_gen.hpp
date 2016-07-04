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
	ClassId_PostingIterator=22,
	ClassId_PostingJoinOperator=23,
	ClassId_QueryAnalyzer=24,
	ClassId_QueryEval=25,
	ClassId_Query=26,
	ClassId_QueryProcessor=27,
	ClassId_ScalarFunctionInstance=28,
	ClassId_ScalarFunction=29,
	ClassId_ScalarFunctionParser=30,
	ClassId_SegmenterContext=31,
	ClassId_SegmenterInstance=32,
	ClassId_Segmenter=33,
	ClassId_SegmenterMarkupContext=34,
	ClassId_StatisticsBuilder=35,
	ClassId_StatisticsIterator=36,
	ClassId_StatisticsProcessor=37,
	ClassId_StatisticsViewer=38,
	ClassId_StorageAlterMetaDataTable=39,
	ClassId_StorageClient=40,
	ClassId_StorageDocument=41,
	ClassId_StorageDocumentUpdate=42,
	ClassId_StorageDump=43,
	ClassId_Storage=44,
	ClassId_StorageObjectBuilder=45,
	ClassId_StorageTransaction=46,
	ClassId_SummarizerFunctionContext=47,
	ClassId_SummarizerFunctionInstance=48,
	ClassId_SummarizerFunction=49,
	ClassId_TextProcessor=50,
	ClassId_TokenizerFunctionContext=51,
	ClassId_TokenizerFunctionInstance=52,
	ClassId_TokenizerFunction=53,
	ClassId_ValueIterator=54,
	ClassId_WeightingFunctionContext=55,
	ClassId_WeightingFunctionInstance=56,
	ClassId_WeightingFunction=57
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
		Method_readValue=6
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
		Method_evaluate=13
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
		Method_tagName=2,
		Method_tagLevel=3,
		Method_putOpenTag=4,
		Method_putAttribute=5,
		Method_putCloseTag=6,
		Method_getContent=7
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
		Method_createTermPostingIterator=1,
		Method_createBrowsePostingIterator=2,
		Method_createForwardIterator=3,
		Method_createDocumentTermIterator=4,
		Method_createInvAclIterator=5,
		Method_nofDocumentsInserted=6,
		Method_documentFrequency=7,
		Method_maxDocumentNumber=8,
		Method_documentNumber=9,
		Method_createTermTypeIterator=10,
		Method_createTermValueIterator=11,
		Method_createDocIdIterator=12,
		Method_createUserNameIterator=13,
		Method_documentStatistics=14,
		Method_createMetaDataReader=15,
		Method_createMetaDataRestriction=16,
		Method_createAttributeReader=17,
		Method_createTransaction=18,
		Method_createInitStatisticsIterator=19,
		Method_createUpdateStatisticsIterator=20,
		Method_getStatisticsProcessor=21,
		Method_createDocumentChecker=22,
		Method_checkStorage=23,
		Method_createDump=24
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
		Method_createQueryEval=5
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
		Method_detectDocumentClass=6,
		Method_defineDocumentClassDetector=7,
		Method_defineTokenizer=8,
		Method_defineNormalizer=9,
		Method_defineAggregator=10,
		Method_getFunctionList=11
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

