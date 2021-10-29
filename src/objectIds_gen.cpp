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
		"AclReader",
		"AggregatorFunctionInstance",
		"AggregatorFunction",
		"AnalyzerObjectBuilder",
		"AttributeReader",
		"ContentIterator",
		"ContentStatisticsContext",
		"ContentStatistics",
		"DatabaseBackupCursor",
		"DatabaseClient",
		"DatabaseCursor",
		"Database",
		"DatabaseTransaction",
		"DocumentAnalyzerContext",
		"DocumentAnalyzerInstance",
		"DocumentAnalyzerMap",
		"DocumentClassDetector",
		"DocumentTermIterator",
		"FileLocator",
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
		"PosTaggerContext",
		"PosTaggerData",
		"PosTaggerInstance",
		"PosTagger",
		"PostingIterator",
		"PostingJoinOperator",
		"QueryAnalyzerContext",
		"QueryAnalyzerInstance",
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
		"SentenceLexerInstance",
		"StatisticsBuilder",
		"StatisticsMap",
		"StatisticsProcessor",
		"StatisticsStorageClient",
		"StatisticsStorage",
		"StatisticsViewer",
		"StorageClient",
		"StorageDocument",
		"StorageDocumentUpdate",
		"StorageDump",
		"Storage",
		"StorageMetaDataTableUpdate",
		"StorageObjectBuilder",
		"StorageTransaction",
		"StructureIterator",
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
		"VectorStorageTransaction",
		"WeightingFunctionContext",
		"WeightingFunctionInstance",
		"WeightingFunction"
	};

	return classId?ar[ classId-1]:0;
}

const char* AclReaderConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "skipDoc", "getReadAccessList"};
	return ar[mid];
}

const char* AggregatorFunctionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "evaluate", "name", "view"};
	return ar[mid];
}

const char* AggregatorFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance", "name", "view"};
	return ar[mid];
}

const char* AnalyzerObjectBuilderConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getTextProcessor", "createDocumentAnalyzer", "createPosTaggerInstance", "createQueryAnalyzer", "createDocumentAnalyzerMap", "createDocumentClassDetector", "createContentStatistics"};
	return ar[mid];
}

const char* AttributeReaderConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "elementHandle", "skipDoc", "getValue", "getNames"};
	return ar[mid];
}

const char* ContentIteratorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getNext"};
	return ar[mid];
}

const char* ContentStatisticsContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "putContent", "statistics", "nofDocuments"};
	return ar[mid];
}

const char* ContentStatisticsConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addLibraryElement", "addVisibleAttribute", "addSelectorExpression", "createContext", "view"};
	return ar[mid];
}

const char* DatabaseBackupCursorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "fetch"};
	return ar[mid];
}

const char* DatabaseClientConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createTransaction", "createCursor", "createBackupCursor", "writeImm", "removeImm", "readValue", "diskUsage", "config", "compactDatabase", "close"};
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

const char* DocumentAnalyzerInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addSearchIndexFeature", "addForwardIndexFeature", "addSearchIndexField", "addSearchIndexStructure", "defineMetaData", "defineAggregatedMetaData", "defineAttribute", "defineSubDocument", "defineSubContent", "analyze", "createContext", "view"};
	return ar[mid];
}

const char* DocumentAnalyzerMapConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createAnalyzer", "addAnalyzer", "getAnalyzer", "analyze", "createContext", "view"};
	return ar[mid];
}

const char* DocumentClassDetectorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "defineDocumentSchemaDetector", "detect", "view"};
	return ar[mid];
}

const char* DocumentTermIteratorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "skipDoc", "nextTerm", "termDocumentFrequency", "termValue"};
	return ar[mid];
}

const char* FileLocatorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addResourcePath", "getResourceFilePath", "defineWorkingDirectory", "getWorkingDirectory", "getResourcePaths"};
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
	static const char* ar[] = { "Destructor", "elementHandle", "nofElements", "skipDoc", "getValue", "getType", "getName", "getNames"};
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
	static const char* ar[] = { "Destructor", "normalize", "name", "view"};
	return ar[mid];
}

const char* NormalizerFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance", "name", "view"};
	return ar[mid];
}

const char* PatternLexerContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "match", "reset"};
	return ar[mid];
}

const char* PatternLexerInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "defineOption", "defineLexemName", "defineLexem", "defineSymbol", "getSymbol", "getLexemName", "compile", "createContext", "name", "view"};
	return ar[mid];
}

const char* PatternLexerConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getCompileOptionNames", "createInstance", "name", "view"};
	return ar[mid];
}

const char* PatternMatcherContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "putInput", "fetchResults", "getStatistics", "reset"};
	return ar[mid];
}

const char* PatternMatcherInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "defineOption", "defineTermFrequency", "pushTerm", "pushExpression", "pushPattern", "attachVariable", "definePattern", "compile", "createContext", "name", "view"};
	return ar[mid];
}

const char* PatternMatcherConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getCompileOptionNames", "createInstance", "name", "view"};
	return ar[mid];
}

const char* PatternTermFeederInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "defineLexem", "defineSymbol", "getLexem", "lexemTypes", "getSymbol", "name", "view"};
	return ar[mid];
}

const char* PatternTermFeederConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance", "name", "view"};
	return ar[mid];
}

const char* PosTaggerContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "markupDocument"};
	return ar[mid];
}

const char* PosTaggerDataConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "declareIgnoredToken", "insert", "markupSegment"};
	return ar[mid];
}

const char* PosTaggerInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addContentExpression", "addPosTaggerInputPunctuation", "getPosTaggerInput", "markupDocument"};
	return ar[mid];
}

const char* PosTaggerConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance"};
	return ar[mid];
}

const char* PostingIteratorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "skipDoc", "skipDocCandidate", "skipPos", "featureid", "documentFrequency", "frequency", "docno", "posno", "length"};
	return ar[mid];
}

const char* PostingJoinOperatorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createResultIterator", "name", "view"};
	return ar[mid];
}

const char* QueryAnalyzerContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "putField", "groupElements", "analyze"};
	return ar[mid];
}

const char* QueryAnalyzerInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addElement", "queryTermTypes", "queryFieldTypes", "createContext", "view"};
	return ar[mid];
}

const char* QueryEvalConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addTerm", "addSelectionFeature", "addRestrictionFeature", "addExclusionFeature", "getWeightingFeatureSets", "getSelectionFeatureSets", "getRestrictionFeatureSets", "getExclusionFeatureSets", "addSummarizerFunction", "addWeightingFunction", "defineWeightingFormula", "usePositionInformation", "createQuery", "view"};
	return ar[mid];
}

const char* QueryConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "defineTermStatistics", "defineGlobalStatistics", "pushTerm", "pushExpression", "attachVariable", "defineFeature", "addMetaDataRestrictionCondition", "addDocumentEvaluationSet", "addAccess", "setWeightingVariableValue", "evaluate", "view"};
	return ar[mid];
}

const char* QueryProcessorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getResourceFilePath", "definePostingJoinOperator", "getPostingJoinOperator", "defineWeightingFunction", "getWeightingFunction", "defineSummarizerFunction", "getSummarizerFunction", "getFunctionList", "defineScalarFunctionParser", "getScalarFunctionParser"};
	return ar[mid];
}

const char* ScalarFunctionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "setVariableValue", "call", "name", "view"};
	return ar[mid];
}

const char* ScalarFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getVariables", "getNofArguments", "setDefaultVariableValue", "createInstance", "name", "view"};
	return ar[mid];
}

const char* ScalarFunctionParserConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createFunction", "view"};
	return ar[mid];
}

const char* SegmenterContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "putInput", "getNext"};
	return ar[mid];
}

const char* SegmenterInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "defineSelectorExpression", "defineSubSection", "createContext", "createMarkupContext", "name", "view"};
	return ar[mid];
}

const char* SegmenterConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "mimeType", "createInstance", "createContentIterator", "name", "view"};
	return ar[mid];
}

const char* SegmenterMarkupContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getNext", "segmentSize", "tagName", "tagLevel", "putOpenTag", "putAttribute", "putCloseTag", "getContent"};
	return ar[mid];
}

const char* SentenceLexerInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "call", "similarTerms"};
	return ar[mid];
}

const char* StatisticsBuilderConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addNofDocumentsInsertedChange", "addDfChange", "getMessages", "commit", "rollback"};
	return ar[mid];
}

const char* StatisticsMapConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addNofDocumentsInsertedChange", "addDfChange", "processStatisticsMessage", "nofDocuments", "df", "types"};
	return ar[mid];
}

const char* StatisticsProcessorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createViewer", "getUpperBoundTimeStamp", "loadChangeMessage", "createBuilder", "createMap", "releaseStatistics"};
	return ar[mid];
}

const char* StatisticsStorageClientConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "reload", "diskUsage", "getConfigParameters", "config", "nofDocuments", "documentFrequency", "storageTimeStamp", "putStatisticsMessage", "getStatisticsProcessor", "close", "compaction"};
	return ar[mid];
}

const char* StatisticsStorageConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createClient", "createStorage", "getConfigDescription", "getConfigParameters"};
	return ar[mid];
}

const char* StatisticsViewerConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "nofDocumentsInsertedChange", "nextDfChange"};
	return ar[mid];
}

const char* StorageClientConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "reload", "diskUsage", "blockStatistics", "config", "createTermPostingIterator", "createFrequencyPostingIterator", "createStructureIterator", "createBrowsePostingIterator", "createForwardIterator", "createDocumentTermIterator", "createInvAclIterator", "createAclReader", "nofDocumentsInserted", "documentFrequency", "maxDocumentNumber", "documentNumber", "structTypeNumber", "termTypeNumber", "termValueNumber", "isForwardIndexTerm", "createTermTypeIterator", "createStructTypeIterator", "createTermValueIterator", "createDocIdIterator", "createUserNameIterator", "documentStatistics", "createMetaDataReader", "createMetaDataRestriction", "createAttributeReader", "createTransaction", "getNextChangeStatisticsTimeStamp", "loadChangeStatisticsMessage", "loadInitStatisticsMessages", "getStatisticsProcessor", "createDocumentChecker", "createDump", "getConfigParameters", "checkStorage", "close", "compaction"};
	return ar[mid];
}

const char* StorageDocumentConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addSearchIndexTerm", "addSearchIndexStructure", "addForwardIndexTerm", "setMetaData", "setAttribute", "setUserAccessRight", "done"};
	return ar[mid];
}

const char* StorageDocumentUpdateConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addSearchIndexTerm", "addSearchIndexStructure", "addForwardIndexTerm", "clearSearchIndexTerm", "clearSearchIndexStructures", "clearForwardIndexTerm", "setMetaData", "setAttribute", "clearAttribute", "setUserAccessRight", "clearUserAccessRight", "clearUserAccessRights", "done"};
	return ar[mid];
}

const char* StorageDumpConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "nextChunk"};
	return ar[mid];
}

const char* StorageConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createClient", "createStorage", "destroyStorage", "getConfigDescription", "getConfigParameters"};
	return ar[mid];
}

const char* StorageMetaDataTableUpdateConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addElement", "alterElement", "renameElement", "deleteElement", "deleteElements", "clearElement", "done"};
	return ar[mid];
}

const char* StorageObjectBuilderConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getStorage", "getDatabase", "getQueryProcessor", "getStatisticsProcessor", "getVectorStorage", "createQueryEval"};
	return ar[mid];
}

const char* StorageTransactionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createDocument", "createDocumentUpdate", "deleteDocument", "deleteUserAccessRights", "updateMetaData", "updateDocumentFrequency", "createMetaDataTableUpdate", "commit", "rollback"};
	return ar[mid];
}

const char* StructureIteratorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "skipDoc", "levels", "docno", "skipPos", "field", "links", "headerField"};
	return ar[mid];
}

const char* SummarizerFunctionContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addSummarizationFeature", "setVariableValue", "getSummary"};
	return ar[mid];
}

const char* SummarizerFunctionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addStringParameter", "addNumericParameter", "getVariables", "createFunctionContext", "doPopulate", "name", "view"};
	return ar[mid];
}

const char* SummarizerFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance", "name", "view"};
	return ar[mid];
}

const char* TextProcessorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "getResourceFilePath", "getSegmenterByName", "getSegmenterByMimeType", "getSegmenterOptions", "getTokenizer", "getNormalizer", "getAggregator", "getPatternLexer", "getPatternMatcher", "getPatternTermFeeder", "createPosTaggerData", "getPosTagger", "createTokenMarkupInstance", "detectDocumentClass", "defineDocumentClassDetector", "defineSegmenter", "defineSegmenterOptions", "defineTokenizer", "defineNormalizer", "defineAggregator", "definePatternLexer", "definePatternMatcher", "getFunctionList"};
	return ar[mid];
}

const char* TokenizerFunctionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "concatBeforeTokenize", "tokenize", "name", "view"};
	return ar[mid];
}

const char* TokenizerFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance", "name", "view"};
	return ar[mid];
}

const char* TokenMarkupContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "putMarkup", "markupDocument"};
	return ar[mid];
}

const char* TokenMarkupInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createContext", "name", "view"};
	return ar[mid];
}

const char* ValueIteratorConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "skip", "skipPrefix", "fetchValues"};
	return ar[mid];
}

const char* VectorStorageClientConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "prepareSearch", "findSimilar", "createTransaction", "types", "createFeatureValueIterator", "featureTypes", "nofTypes", "nofFeatures", "nofVectors", "featureVector", "vectorSimilarity", "normalize", "createSentenceLexer", "config", "close", "compaction"};
	return ar[mid];
}

const char* VectorStorageDumpConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "nextChunk"};
	return ar[mid];
}

const char* VectorStorageConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createStorage", "createClient", "createDump", "getConfigDescription", "getConfigParameters"};
	return ar[mid];
}

const char* VectorStorageTransactionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "defineVector", "defineFeatureType", "defineFeature", "clear", "commit", "rollback"};
	return ar[mid];
}

const char* WeightingFunctionContextConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addWeightingFeature", "setVariableValue", "call"};
	return ar[mid];
}

const char* WeightingFunctionInstanceConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "addStringParameter", "addNumericParameter", "createFunctionContext", "getVariables", "name", "view"};
	return ar[mid];
}

const char* WeightingFunctionConst::methodName( MethodId mid)
{
	static const char* ar[] = { "Destructor", "createInstance", "name", "view"};
	return ar[mid];
}


