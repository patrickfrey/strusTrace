/*
* Copyright (c) 2016 Patrick P. Frey
*
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
/// \brief Identifiers for objects and methods for serialization
/// \note PROGRAM (strusTraceCodeGen) GENERATED FILE! DO NOT MODIFY!!!
/// \file objectIds_gen.cpp
#include "objectIds_gen.hpp"

using namespace strus;

const char* TraceClassNameMap::className( unsigned int classId)
{
	static const char* ar[] = {
		"AggregatorFunctionInstance",
		"AggregatorFunction",
		"AnalyzerObjectBuilder",
		"AttributeReader",
		"DatabaseBackupCursor",
		"DatabaseClient",
		"DatabaseCursor",
		"Database",
		"DatabaseTransaction",
		"DocumentAnalyzerContext",
		"DocumentAnalyzer",
		"DocumentClassDetector",
		"DocumentTermIterator",
		"ForwardIterator",
		"InvAclIterator",
		"MetaDataReader",
		"MetaDataRestrictionInstance",
		"MetaDataRestriction",
		"NormalizerFunctionInstance",
		"NormalizerFunction",
		"PatternLexerContext",
		"PatternLexerInstance",
		"PatternLexer",
		"PatternMatcherContext",
		"PatternMatcherInstance",
		"PatternMatcher",
		"PatternTermFeederInstance",
		"PatternTermFeeder",
		"PostingIterator",
		"PostingJoinOperator",
		"QueryAnalyzerContext",
		"QueryAnalyzer",
		"QueryEval",
		"Query",
		"QueryProcessor",
		"ScalarFunctionInstance",
		"ScalarFunction",
		"ScalarFunctionParser",
		"SegmenterContext",
		"SegmenterInstance",
		"Segmenter",
		"SegmenterMarkupContext",
		"StatisticsBuilder",
		"StatisticsIterator",
		"StatisticsProcessor",
		"StatisticsViewer",
		"StorageAlterMetaDataTable",
		"StorageClient",
		"StorageDocument",
		"StorageDocumentUpdate",
		"StorageDump",
		"Storage",
		"StorageObjectBuilder",
		"StorageTransaction",
		"SummarizerFunctionContext",
		"SummarizerFunctionInstance",
		"SummarizerFunction",
		"TextProcessor",
		"TokenizerFunctionInstance",
		"TokenizerFunction",
		"TokenMarkupContext",
		"TokenMarkupInstance",
		"ValueIterator",
		"VectorStorageClient",
		"VectorStorageDump",
		"VectorStorage",
		"VectorStorageSearch",
		"VectorStorageTransaction",
		"WeightingFunctionContext",
		"WeightingFunctionInstance",
		"WeightingFunction"
	};

	return classId?ar[ classId-1]:0;
}

const char* AggregatorFunctionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "evaluate"};
	return ar[mid];
}

const char* AggregatorFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance", "getDescription"};
	return ar[mid];
}

const char* AnalyzerObjectBuilderConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getTextProcessor", "getSegmenter", "findMimeTypeSegmenter", "createDocumentAnalyzer", "createQueryAnalyzer"};
	return ar[mid];
}

const char* AttributeReaderConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "elementHandle", "skipDoc", "getValue", "getAttributeNames"};
	return ar[mid];
}

const char* DatabaseBackupCursorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "fetch"};
	return ar[mid];
}

const char* DatabaseClientConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createTransaction", "createCursor", "createBackupCursor", "writeImm", "removeImm", "readValue", "config"};
	return ar[mid];
}

const char* DatabaseCursorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "seekUpperBound", "seekUpperBoundRestricted", "seekFirst", "seekLast", "seekNext", "seekPrev", "key", "value"};
	return ar[mid];
}

const char* DatabaseConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "exists", "createClient", "createDatabase", "restoreDatabase", "destroyDatabase", "getConfigDescription", "getConfigParameters"};
	return ar[mid];
}

const char* DatabaseTransactionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createCursor", "write", "remove", "removeSubTree", "commit", "rollback"};
	return ar[mid];
}

const char* DocumentAnalyzerContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "putInput", "analyzeNext"};
	return ar[mid];
}

const char* DocumentAnalyzerConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addSearchIndexFeature", "addForwardIndexFeature", "defineMetaData", "defineAggregatedMetaData", "defineAttribute", "defineSubDocument", "addPatternLexem", "definePatternMatcherPostProc", "definePatternMatcherPreProc", "addSearchIndexFeatureFromPatternMatch", "addForwardIndexFeatureFromPatternMatch", "defineMetaDataFromPatternMatch", "defineAttributeFromPatternMatch", "analyze", "createContext"};
	return ar[mid];
}

const char* DocumentClassDetectorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "detect"};
	return ar[mid];
}

const char* DocumentTermIteratorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "skipDoc", "nextTerm", "termDocumentFrequency", "termValue"};
	return ar[mid];
}

const char* ForwardIteratorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "skipDoc", "skipPos", "fetch"};
	return ar[mid];
}

const char* InvAclIteratorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "skipDoc"};
	return ar[mid];
}

const char* MetaDataReaderConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "hasElement", "elementHandle", "nofElements", "skipDoc", "getValue", "getType", "getName"};
	return ar[mid];
}

const char* MetaDataRestrictionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "match"};
	return ar[mid];
}

const char* MetaDataRestrictionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addCondition", "createInstance", "tostring"};
	return ar[mid];
}

const char* NormalizerFunctionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "normalize"};
	return ar[mid];
}

const char* NormalizerFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance", "getDescription"};
	return ar[mid];
}

const char* PatternLexerContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "match", "reset"};
	return ar[mid];
}

const char* PatternLexerInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "defineOption", "defineLexem", "defineSymbol", "getSymbol", "compile", "createContext"};
	return ar[mid];
}

const char* PatternLexerConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getCompileOptionNames", "createInstance", "getDescription"};
	return ar[mid];
}

const char* PatternMatcherContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "putInput", "fetchResults", "getStatistics", "reset"};
	return ar[mid];
}

const char* PatternMatcherInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "defineOption", "defineTermFrequency", "pushTerm", "pushExpression", "pushPattern", "attachVariable", "definePattern", "compile", "createContext"};
	return ar[mid];
}

const char* PatternMatcherConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getCompileOptionNames", "createInstance", "getDescription"};
	return ar[mid];
}

const char* PatternTermFeederInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "defineLexem", "defineSymbol", "getLexem", "lexemTypes", "getSymbol"};
	return ar[mid];
}

const char* PatternTermFeederConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance"};
	return ar[mid];
}

const char* PostingIteratorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "skipDoc", "skipDocCandidate", "skipPos", "featureid", "documentFrequency", "frequency", "docno", "posno"};
	return ar[mid];
}

const char* PostingJoinOperatorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createResultIterator", "getDescription"};
	return ar[mid];
}

const char* QueryAnalyzerContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "putField", "groupElements", "analyze"};
	return ar[mid];
}

const char* QueryAnalyzerConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addSearchIndexElement", "addMetaDataElement", "addPatternLexem", "definePatternMatcherPostProc", "definePatternMatcherPreProc", "addSearchIndexElementFromPatternMatch", "addMetaDataElementFromPatternMatch", "createContext"};
	return ar[mid];
}

const char* QueryEvalConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addTerm", "addSelectionFeature", "addRestrictionFeature", "addExclusionFeature", "addSummarizerFunction", "addWeightingFunction", "defineWeightingFormula", "createQuery"};
	return ar[mid];
}

const char* QueryConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "pushTerm", "pushDocField", "pushExpression", "attachVariable", "defineFeature", "defineTermStatistics", "defineGlobalStatistics", "addMetaDataRestrictionCondition", "addDocumentEvaluationSet", "setMaxNofRanks", "setMinRank", "addUserName", "setWeightingVariableValue", "evaluate", "tostring"};
	return ar[mid];
}

const char* QueryProcessorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "definePostingJoinOperator", "getPostingJoinOperator", "defineWeightingFunction", "getWeightingFunction", "defineSummarizerFunction", "getSummarizerFunction", "getFunctionList", "defineScalarFunctionParser", "getScalarFunctionParser"};
	return ar[mid];
}

const char* ScalarFunctionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "setVariableValue", "call", "tostring"};
	return ar[mid];
}

const char* ScalarFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getVariables", "getNofArguments", "setDefaultVariableValue", "createInstance", "tostring"};
	return ar[mid];
}

const char* ScalarFunctionParserConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createFunction"};
	return ar[mid];
}

const char* SegmenterContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "putInput", "getNext"};
	return ar[mid];
}

const char* SegmenterInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "defineSelectorExpression", "defineSubSection", "createContext", "createMarkupContext"};
	return ar[mid];
}

const char* SegmenterConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "mimeType", "createInstance"};
	return ar[mid];
}

const char* SegmenterMarkupContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getNext", "segmentSize", "tagName", "tagLevel", "putOpenTag", "putAttribute", "putCloseTag", "getContent"};
	return ar[mid];
}

const char* StatisticsBuilderConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "setNofDocumentsInsertedChange", "addDfChange", "start", "rollback", "fetchMessage"};
	return ar[mid];
}

const char* StatisticsIteratorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getNext"};
	return ar[mid];
}

const char* StatisticsProcessorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createViewer", "createBuilder"};
	return ar[mid];
}

const char* StatisticsViewerConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "nofDocumentsInsertedChange", "nextDfChange"};
	return ar[mid];
}

const char* StorageAlterMetaDataTableConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addElement", "alterElement", "renameElement", "deleteElement", "clearElement", "commit", "rollback"};
	return ar[mid];
}

const char* StorageClientConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "config", "createTermPostingIterator", "createBrowsePostingIterator", "createFieldPostingIterator", "createForwardIterator", "createDocumentTermIterator", "createInvAclIterator", "nofDocumentsInserted", "documentFrequency", "maxDocumentNumber", "documentNumber", "createTermTypeIterator", "createTermValueIterator", "createDocIdIterator", "createUserNameIterator", "documentStatistics", "createMetaDataReader", "createMetaDataRestriction", "createAttributeReader", "createTransaction", "createInitStatisticsIterator", "createUpdateStatisticsIterator", "getStatisticsProcessor", "createDocumentChecker", "checkStorage"};
	return ar[mid];
}

const char* StorageDocumentConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addSearchIndexTerm", "addForwardIndexTerm", "setMetaData", "setAttribute", "setUserAccessRight", "done"};
	return ar[mid];
}

const char* StorageDocumentUpdateConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "setMetaData", "setAttribute", "clearAttribute", "setUserAccessRight", "clearUserAccessRight", "clearUserAccessRights", "done"};
	return ar[mid];
}

const char* StorageDumpConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "nextChunk"};
	return ar[mid];
}

const char* StorageConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createClient", "createStorage", "createAlterMetaDataTable", "getConfigDescription", "getConfigParameters", "createDump"};
	return ar[mid];
}

const char* StorageObjectBuilderConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getStorage", "getDatabase", "getQueryProcessor", "getStatisticsProcessor", "getVectorStorage", "createQueryEval"};
	return ar[mid];
}

const char* StorageTransactionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createDocument", "createDocumentUpdate", "deleteDocument", "deleteUserAccessRights", "updateMetaData", "commit", "rollback", "nofDocumentsAffected"};
	return ar[mid];
}

const char* SummarizerFunctionContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addSummarizationFeature", "getSummary"};
	return ar[mid];
}

const char* SummarizerFunctionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addStringParameter", "addNumericParameter", "defineResultName", "createFunctionContext", "tostring"};
	return ar[mid];
}

const char* SummarizerFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance", "getDescription"};
	return ar[mid];
}

const char* TextProcessorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addResourcePath", "getResourcePath", "getTokenizer", "getNormalizer", "getAggregator", "getPatternLexer", "getPatternMatcher", "getPatternTermFeeder", "detectDocumentClass", "defineDocumentClassDetector", "defineTokenizer", "defineNormalizer", "defineAggregator", "definePatternLexer", "definePatternMatcher", "getFunctionList"};
	return ar[mid];
}

const char* TokenizerFunctionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "concatBeforeTokenize", "tokenize"};
	return ar[mid];
}

const char* TokenizerFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance", "getDescription"};
	return ar[mid];
}

const char* TokenMarkupContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "putMarkup", "markupDocument"};
	return ar[mid];
}

const char* TokenMarkupInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createContext"};
	return ar[mid];
}

const char* ValueIteratorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "skip", "fetchValues"};
	return ar[mid];
}

const char* VectorStorageClientConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createSearcher", "createTransaction", "conceptClassNames", "conceptFeatures", "nofConcepts", "featureConcepts", "featureVector", "featureName", "featureIndex", "nofFeatures", "config"};
	return ar[mid];
}

const char* VectorStorageDumpConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "nextChunk"};
	return ar[mid];
}

const char* VectorStorageConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createStorage", "createClient", "createDump", "runBuild"};
	return ar[mid];
}

const char* VectorStorageSearchConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "findSimilar", "close"};
	return ar[mid];
}

const char* VectorStorageTransactionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addFeature", "defineFeatureConceptRelation", "commit", "rollback"};
	return ar[mid];
}

const char* WeightingFunctionContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addWeightingFeature", "call"};
	return ar[mid];
}

const char* WeightingFunctionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addStringParameter", "addNumericParameter", "createFunctionContext", "tostring"};
	return ar[mid];
}

const char* WeightingFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance", "getDescription"};
	return ar[mid];
}


