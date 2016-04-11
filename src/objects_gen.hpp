/*
* Copyright (c) 2016 Patrick P. Frey
*
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
/// \brief Identifiers for objects and methods for serialization
/// \note PROGRAM (strusTraceCodeGen) GENERATED FILE! DO NOT MODIFY!!!
/// \file objects_gen.hpp
#ifndef _STRUS_TRACE_PARSER_objects_gen_HPP_INCLUDED
#define _STRUS_TRACE_PARSER_objects_gen_HPP_INCLUDED
#include "objectIds_gen.hpp"
#include "traceObject.hpp"
#include "strus/aggregatorFunctionInstanceInterface.hpp"
#include "strus/aggregatorFunctionInterface.hpp"
#include "strus/analyzerObjectBuilderInterface.hpp"
#include "strus/attributeReaderInterface.hpp"
#include "strus/databaseBackupCursorInterface.hpp"
#include "strus/databaseClientInterface.hpp"
#include "strus/databaseCursorInterface.hpp"
#include "strus/databaseInterface.hpp"
#include "strus/databaseTransactionInterface.hpp"
#include "strus/documentAnalyzerContextInterface.hpp"
#include "strus/documentAnalyzerInterface.hpp"
#include "strus/documentClassDetectorInterface.hpp"
#include "strus/documentTermIteratorInterface.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/forwardIteratorInterface.hpp"
#include "strus/invAclIteratorInterface.hpp"
#include "strus/metaDataReaderInterface.hpp"
#include "strus/metaDataRestrictionInstanceInterface.hpp"
#include "strus/metaDataRestrictionInterface.hpp"
#include "strus/normalizerFunctionContextInterface.hpp"
#include "strus/normalizerFunctionInstanceInterface.hpp"
#include "strus/normalizerFunctionInterface.hpp"
#include "strus/postingIteratorInterface.hpp"
#include "strus/postingJoinOperatorInterface.hpp"
#include "strus/queryAnalyzerInterface.hpp"
#include "strus/queryEvalInterface.hpp"
#include "strus/queryInterface.hpp"
#include "strus/queryProcessorInterface.hpp"
#include "strus/scalarFunctionInstanceInterface.hpp"
#include "strus/scalarFunctionInterface.hpp"
#include "strus/scalarFunctionParserInterface.hpp"
#include "strus/segmenterContextInterface.hpp"
#include "strus/segmenterInstanceInterface.hpp"
#include "strus/segmenterInterface.hpp"
#include "strus/statisticsBuilderInterface.hpp"
#include "strus/statisticsIteratorInterface.hpp"
#include "strus/statisticsProcessorInterface.hpp"
#include "strus/statisticsViewerInterface.hpp"
#include "strus/storageAlterMetaDataTableInterface.hpp"
#include "strus/storageClientInterface.hpp"
#include "strus/storageDocumentInterface.hpp"
#include "strus/storageDocumentUpdateInterface.hpp"
#include "strus/storageDumpInterface.hpp"
#include "strus/storageInterface.hpp"
#include "strus/storageObjectBuilderInterface.hpp"
#include "strus/storageTransactionInterface.hpp"
#include "strus/summarizerFunctionContextInterface.hpp"
#include "strus/summarizerFunctionInstanceInterface.hpp"
#include "strus/summarizerFunctionInterface.hpp"
#include "strus/textProcessorInterface.hpp"
#include "strus/tokenizerFunctionContextInterface.hpp"
#include "strus/tokenizerFunctionInstanceInterface.hpp"
#include "strus/tokenizerFunctionInterface.hpp"
#include "strus/valueIteratorInterface.hpp"
#include "strus/weightingFunctionContextInterface.hpp"
#include "strus/weightingFunctionInstanceInterface.hpp"
#include "strus/weightingFunctionInterface.hpp"
#include <string>
#include <vector>

namespace strus {

class AggregatorFunctionInstanceImpl
		:public TraceObject<AggregatorFunctionInstanceInterface>
		,public AggregatorFunctionInstanceInterface
{
public:
	AggregatorFunctionInstanceImpl( AggregatorFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AggregatorFunctionInstanceInterface>(obj_,ctx_){}

	virtual ~AggregatorFunctionInstanceImpl();
	virtual double evaluate(
			const analyzer::Document& p1);
};

class AggregatorFunctionImpl
		:public TraceObject<AggregatorFunctionInterface>
		,public AggregatorFunctionInterface
{
public:
	AggregatorFunctionImpl( AggregatorFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AggregatorFunctionInterface>(obj_,ctx_){}

	virtual ~AggregatorFunctionImpl();
	virtual AggregatorFunctionInstanceInterface* createInstance(
			const std::vector<std::string>& p1);
	virtual const char* getDescription();
};

class AnalyzerObjectBuilderImpl
		:public TraceObject<AnalyzerObjectBuilderInterface>
		,public AnalyzerObjectBuilderInterface
{
public:
	AnalyzerObjectBuilderImpl( AnalyzerObjectBuilderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AnalyzerObjectBuilderInterface>(obj_,ctx_){}

	virtual ~AnalyzerObjectBuilderImpl();
	virtual const TextProcessorInterface* getTextProcessor();
	virtual SegmenterInterface* createSegmenter(
			const std::string& p1);
	virtual DocumentAnalyzerInterface* createDocumentAnalyzer(
			const std::string& p1);
	virtual QueryAnalyzerInterface* createQueryAnalyzer();
};

class AttributeReaderImpl
		:public TraceObject<AttributeReaderInterface>
		,public AttributeReaderInterface
{
public:
	AttributeReaderImpl( AttributeReaderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AttributeReaderInterface>(obj_,ctx_){}

	virtual ~AttributeReaderImpl();
	virtual Index elementHandle(
			const char* p1);
	virtual void skipDoc(
			const Index& p1);
	virtual std::string getValue(
			const Index& p1);
	virtual std::vector<std::string> getAttributeNames();
};

class DatabaseBackupCursorImpl
		:public TraceObject<DatabaseBackupCursorInterface>
		,public DatabaseBackupCursorInterface
{
public:
	DatabaseBackupCursorImpl( DatabaseBackupCursorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseBackupCursorInterface>(obj_,ctx_){}

	virtual ~DatabaseBackupCursorImpl();
	virtual bool fetch(
			const char*& key, std::size_t& p1, 
			const char*& blk, std::size_t& p2);
};

class DatabaseClientImpl
		:public TraceObject<DatabaseClientInterface>
		,public DatabaseClientInterface
{
public:
	DatabaseClientImpl( DatabaseClientInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseClientInterface>(obj_,ctx_){}

	virtual ~DatabaseClientImpl();
	virtual DatabaseTransactionInterface* createTransaction();
	virtual DatabaseCursorInterface* createCursor(
			const DatabaseOptions& p1);
	virtual DatabaseBackupCursorInterface* createBackupCursor();
	virtual void writeImm(
			const char* key, std::size_t p1, 
			const char* value, std::size_t p2);
	virtual void removeImm(
			const char* key, std::size_t p1);
	virtual bool readValue(
			const char* key, std::size_t p1, 
			std::string& p2, 
			const DatabaseOptions& p3);
};

class DatabaseCursorImpl
		:public TraceObject<DatabaseCursorInterface>
		,public DatabaseCursorInterface
{
public:
	DatabaseCursorImpl( DatabaseCursorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseCursorInterface>(obj_,ctx_){}

	virtual ~DatabaseCursorImpl();
	virtual Slice seekUpperBound(
			const char* key, std::size_t p1, 
			std::size_t p2);
	virtual Slice seekUpperBoundRestricted(
			const char* key, std::size_t p1, 
			const char* upkey, std::size_t p2);
	virtual Slice seekFirst(
			const char* domainkey, std::size_t p1);
	virtual Slice seekLast(
			const char* domainkey, std::size_t p1);
	virtual Slice seekNext();
	virtual Slice seekPrev();
	virtual Slice key();
	virtual Slice value();
};

class DatabaseImpl
		:public TraceObject<DatabaseInterface>
		,public DatabaseInterface
{
public:
	DatabaseImpl( DatabaseInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseInterface>(obj_,ctx_){}

	virtual ~DatabaseImpl();
	virtual bool exists(
			const std::string& p1);
	virtual DatabaseClientInterface* createClient(
			const std::string& p1);
	virtual bool createDatabase(
			const std::string& p1);
	virtual bool restoreDatabase(
			const std::string& p1, 
			DatabaseBackupCursorInterface* p2);
	virtual bool destroyDatabase(
			const std::string& p1);
	virtual const char* getConfigDescription(
			const ConfigType& p1);
	virtual const char** getConfigParameters(
			const ConfigType& p1);
};

class DatabaseTransactionImpl
		:public TraceObject<DatabaseTransactionInterface>
		,public DatabaseTransactionInterface
{
public:
	DatabaseTransactionImpl( DatabaseTransactionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseTransactionInterface>(obj_,ctx_){}

	virtual ~DatabaseTransactionImpl();
	virtual DatabaseCursorInterface* createCursor(
			const DatabaseOptions& p1);
	virtual void write(
			const char* key, std::size_t p1, 
			const char* value, std::size_t p2);
	virtual void remove(
			const char* key, std::size_t p1);
	virtual void removeSubTree(
			const char* domainkey, std::size_t p1);
	virtual bool commit();
	virtual void rollback();
};

class DocumentAnalyzerContextImpl
		:public TraceObject<DocumentAnalyzerContextInterface>
		,public DocumentAnalyzerContextInterface
{
public:
	DocumentAnalyzerContextImpl( DocumentAnalyzerContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentAnalyzerContextInterface>(obj_,ctx_){}

	virtual ~DocumentAnalyzerContextImpl();
	virtual void putInput(
			const char* chunk, std::size_t p1, 
			bool p2);
	virtual bool analyzeNext(
			analyzer::Document& p1);
};

class DocumentAnalyzerImpl
		:public TraceObject<DocumentAnalyzerInterface>
		,public DocumentAnalyzerInterface
{
public:
	DocumentAnalyzerImpl( DocumentAnalyzerInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentAnalyzerInterface>(obj_,ctx_){}

	virtual ~DocumentAnalyzerImpl();
	virtual void addSearchIndexFeature(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			const FeatureOptions& p5);
	virtual void addForwardIndexFeature(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			const FeatureOptions& p5);
	virtual void defineMetaData(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4);
	virtual void defineAggregatedMetaData(
			const std::string& p1, 
			AggregatorFunctionInstanceInterface* p2);
	virtual void defineAttribute(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4);
	virtual void defineSubDocument(
			const std::string& p1, 
			const std::string& p2);
	virtual analyzer::Document analyze(
			const std::string& p1, 
			const DocumentClass& p2);
	virtual DocumentAnalyzerContextInterface* createContext(
			const DocumentClass& p1);
};

class DocumentClassDetectorImpl
		:public TraceObject<DocumentClassDetectorInterface>
		,public DocumentClassDetectorInterface
{
public:
	DocumentClassDetectorImpl( DocumentClassDetectorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentClassDetectorInterface>(obj_,ctx_){}

	virtual ~DocumentClassDetectorImpl();
	virtual bool detect(
			DocumentClass& p1, 
			const char* contentBegin, std::size_t p2);
};

class DocumentTermIteratorImpl
		:public TraceObject<DocumentTermIteratorInterface>
		,public DocumentTermIteratorInterface
{
public:
	DocumentTermIteratorImpl( DocumentTermIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentTermIteratorInterface>(obj_,ctx_){}

	virtual ~DocumentTermIteratorImpl();
	virtual Index skipDoc(
			const Index& p1);
	virtual bool nextTerm(
			Term& p1);
	virtual unsigned int termDocumentFrequency(
			const Index& p1);
	virtual std::string termValue(
			const Index& p1);
};

class ForwardIteratorImpl
		:public TraceObject<ForwardIteratorInterface>
		,public ForwardIteratorInterface
{
public:
	ForwardIteratorImpl( ForwardIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ForwardIteratorInterface>(obj_,ctx_){}

	virtual ~ForwardIteratorImpl();
	virtual void skipDoc(
			const Index& p1);
	virtual Index skipPos(
			const Index& p1);
	virtual std::string fetch();
};

class InvAclIteratorImpl
		:public TraceObject<InvAclIteratorInterface>
		,public InvAclIteratorInterface
{
public:
	InvAclIteratorImpl( InvAclIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<InvAclIteratorInterface>(obj_,ctx_){}

	virtual ~InvAclIteratorImpl();
	virtual Index skipDoc(
			const Index& p1);
};

class MetaDataReaderImpl
		:public TraceObject<MetaDataReaderInterface>
		,public MetaDataReaderInterface
{
public:
	MetaDataReaderImpl( MetaDataReaderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<MetaDataReaderInterface>(obj_,ctx_){}

	virtual ~MetaDataReaderImpl();
	virtual bool hasElement(
			const std::string& p1);
	virtual Index elementHandle(
			const std::string& p1);
	virtual Index nofElements();
	virtual void skipDoc(
			const Index& p1);
	virtual NumericVariant getValue(
			const Index& p1);
	virtual const char* getType(
			const Index& p1);
	virtual const char* getName(
			const Index& p1);
};

class MetaDataRestrictionInstanceImpl
		:public TraceObject<MetaDataRestrictionInstanceInterface>
		,public MetaDataRestrictionInstanceInterface
{
public:
	MetaDataRestrictionInstanceImpl( MetaDataRestrictionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<MetaDataRestrictionInstanceInterface>(obj_,ctx_){}

	virtual ~MetaDataRestrictionInstanceImpl();
	virtual bool match(
			const Index& p1);
};

class MetaDataRestrictionImpl
		:public TraceObject<MetaDataRestrictionInterface>
		,public MetaDataRestrictionInterface
{
public:
	MetaDataRestrictionImpl( MetaDataRestrictionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<MetaDataRestrictionInterface>(obj_,ctx_){}

	virtual ~MetaDataRestrictionImpl();
	virtual void addCondition(
			const CompareOperator& p1, 
			const std::string& p2, 
			const NumericVariant& p3, 
			bool p4);
	virtual MetaDataRestrictionInstanceInterface* createInstance();
	virtual std::string tostring();
};

class NormalizerFunctionContextImpl
		:public TraceObject<NormalizerFunctionContextInterface>
		,public NormalizerFunctionContextInterface
{
public:
	NormalizerFunctionContextImpl( NormalizerFunctionContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<NormalizerFunctionContextInterface>(obj_,ctx_){}

	virtual ~NormalizerFunctionContextImpl();
	virtual std::string normalize(
			const char* src, std::size_t p1);
};

class NormalizerFunctionInstanceImpl
		:public TraceObject<NormalizerFunctionInstanceInterface>
		,public NormalizerFunctionInstanceInterface
{
public:
	NormalizerFunctionInstanceImpl( NormalizerFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<NormalizerFunctionInstanceInterface>(obj_,ctx_){}

	virtual ~NormalizerFunctionInstanceImpl();
	virtual NormalizerFunctionContextInterface* createFunctionContext();
};

class NormalizerFunctionImpl
		:public TraceObject<NormalizerFunctionInterface>
		,public NormalizerFunctionInterface
{
public:
	NormalizerFunctionImpl( NormalizerFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<NormalizerFunctionInterface>(obj_,ctx_){}

	virtual ~NormalizerFunctionImpl();
	virtual NormalizerFunctionInstanceInterface* createInstance(
			const std::vector<std::string>& p1, 
			const TextProcessorInterface* p2);
	virtual const char* getDescription();
};

class PostingIteratorImpl
		:public TraceObject<PostingIteratorInterface>
		,public PostingIteratorInterface
{
public:
	PostingIteratorImpl( PostingIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PostingIteratorInterface>(obj_,ctx_){}

	virtual ~PostingIteratorImpl();
	virtual Index skipDoc(
			const Index& p1);
	virtual Index skipDocCandidate(
			const Index& p1);
	virtual Index skipPos(
			const Index& p1);
	virtual const char* featureid();
	virtual Index documentFrequency();
	virtual unsigned int frequency();
	virtual Index docno();
	virtual Index posno();
};

class PostingJoinOperatorImpl
		:public TraceObject<PostingJoinOperatorInterface>
		,public PostingJoinOperatorInterface
{
public:
	PostingJoinOperatorImpl( PostingJoinOperatorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PostingJoinOperatorInterface>(obj_,ctx_){}

	virtual ~PostingJoinOperatorImpl();
	virtual PostingIteratorInterface* createResultIterator(
			const std::vector<Reference<PostingIteratorInterface> >& p1, 
			int p2, 
			unsigned int p3);
	virtual Description getDescription();
};

class QueryAnalyzerImpl
		:public TraceObject<QueryAnalyzerInterface>
		,public QueryAnalyzerInterface
{
public:
	QueryAnalyzerImpl( QueryAnalyzerInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryAnalyzerInterface>(obj_,ctx_){}

	virtual ~QueryAnalyzerImpl();
	virtual void definePhraseType(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4);
	virtual std::vector<analyzer::Term> analyzePhrase(
			const std::string& p1, 
			const std::string& p2);
	virtual std::vector<analyzer::TermVector> analyzePhraseBulk(
			const std::vector<Phrase>& phraseBulk p1);
};

class QueryEvalImpl
		:public TraceObject<QueryEvalInterface>
		,public QueryEvalInterface
{
public:
	QueryEvalImpl( QueryEvalInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryEvalInterface>(obj_,ctx_){}

	virtual ~QueryEvalImpl();
	virtual void addTerm(
			const std::string& p1, 
			const std::string& p2, 
			const std::string& p3);
	virtual void addSelectionFeature(
			const std::string& p1);
	virtual void addRestrictionFeature(
			const std::string& p1);
	virtual void addExclusionFeature(
			const std::string& p1);
	virtual void addSummarizerFunction(
			const std::string& p1, 
			SummarizerFunctionInstanceInterface* p2, 
			const std::vector<FeatureParameter>& p3);
	virtual void addWeightingFunction(
			const std::string& p1, 
			WeightingFunctionInstanceInterface* p2, 
			const std::vector<FeatureParameter>& p3);
	virtual void defineWeightingFormula(
			ScalarFunctionInterface* p1);
	virtual QueryInterface* createQuery(
			const StorageClientInterface* p1);
};

class QueryImpl
		:public TraceObject<QueryInterface>
		,public QueryInterface
{
public:
	QueryImpl( QueryInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryInterface>(obj_,ctx_){}

	virtual ~QueryImpl();
	virtual void pushTerm(
			const std::string& p1, 
			const std::string& p2);
	virtual void pushExpression(
			const PostingJoinOperatorInterface* p1, 
			std::size_t p2, 
			int p3, 
			unsigned int p4);
	virtual void attachVariable(
			const std::string& p1);
	virtual void defineFeature(
			const std::string& p1, 
			double p2);
	virtual void defineTermStatistics(
			const std::string& p1, 
			const std::string& p2, 
			const TermStatistics& p3);
	virtual void defineGlobalStatistics(
			const GlobalStatistics& p1);
	virtual void addMetaDataRestrictionCondition(
			MetaDataRestrictionInterface::CompareOperator p1, 
			const std::string& p2, 
			const NumericVariant& p3, 
			bool p4);
	virtual void addDocumentEvaluationSet(
			const std::vector<Index>& p1);
	virtual void setMaxNofRanks(
			std::size_t p1);
	virtual void setMinRank(
			std::size_t p1);
	virtual void addUserName(
			const std::string& p1);
	virtual void setWeightingVariableValue(
			const std::string& p1, 
			double p2);
	virtual QueryResult evaluate();
};

class QueryProcessorImpl
		:public TraceObject<QueryProcessorInterface>
		,public QueryProcessorInterface
{
public:
	QueryProcessorImpl( QueryProcessorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryProcessorInterface>(obj_,ctx_){}

	virtual ~QueryProcessorImpl();
	virtual void definePostingJoinOperator(
			const std::string& p1, 
			PostingJoinOperatorInterface* p2);
	virtual const PostingJoinOperatorInterface* getPostingJoinOperator(
			const std::string& p1);
	virtual void defineWeightingFunction(
			const std::string& p1, 
			WeightingFunctionInterface* p2);
	virtual const WeightingFunctionInterface* getWeightingFunction(
			const std::string& p1);
	virtual void defineSummarizerFunction(
			const std::string& p1, 
			SummarizerFunctionInterface* p2);
	virtual const SummarizerFunctionInterface* getSummarizerFunction(
			const std::string& p1);
	virtual std::vector<std::string> getFunctionList(
			const FunctionType& p1);
	virtual void defineScalarFunctionParser(
			const std::string& p1, 
			ScalarFunctionParserInterface* p2);
	virtual const ScalarFunctionParserInterface* getScalarFunctionParser(
			const std::string& p1);
};

class ScalarFunctionInstanceImpl
		:public TraceObject<ScalarFunctionInstanceInterface>
		,public ScalarFunctionInstanceInterface
{
public:
	ScalarFunctionInstanceImpl( ScalarFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ScalarFunctionInstanceInterface>(obj_,ctx_){}

	virtual ~ScalarFunctionInstanceImpl();
	virtual void setVariableValue(
			const std::string& p1, 
			double p2);
	virtual double call(
			const double* args, std::size_t p1);
	virtual std::string tostring();
};

class ScalarFunctionImpl
		:public TraceObject<ScalarFunctionInterface>
		,public ScalarFunctionInterface
{
public:
	ScalarFunctionImpl( ScalarFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ScalarFunctionInterface>(obj_,ctx_){}

	virtual ~ScalarFunctionImpl();
	virtual std::vector<std::string> getVariables();
	virtual std::size_t getNofArguments();
	virtual void setDefaultVariableValue(
			const std::string& p1, 
			double p2);
	virtual ScalarFunctionInstanceInterface* createInstance();
	virtual std::string tostring();
};

class ScalarFunctionParserImpl
		:public TraceObject<ScalarFunctionParserInterface>
		,public ScalarFunctionParserInterface
{
public:
	ScalarFunctionParserImpl( ScalarFunctionParserInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ScalarFunctionParserInterface>(obj_,ctx_){}

	virtual ~ScalarFunctionParserImpl();
	virtual ScalarFunctionInterface* createFunction(
			const std::string& p1, 
			const std::vector<std::string>& p2);
};

class SegmenterContextImpl
		:public TraceObject<SegmenterContextInterface>
		,public SegmenterContextInterface
{
public:
	SegmenterContextImpl( SegmenterContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SegmenterContextInterface>(obj_,ctx_){}

	virtual ~SegmenterContextImpl();
	virtual void putInput(
			const char* chunk, std::size_t p1, 
			bool p2);
	virtual bool getNext(
			int& p1, 
			SegmenterPosition& p2, 
			const char*& segment, std::size_t& p3);
};

class SegmenterInstanceImpl
		:public TraceObject<SegmenterInstanceInterface>
		,public SegmenterInstanceInterface
{
public:
	SegmenterInstanceImpl( SegmenterInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SegmenterInstanceInterface>(obj_,ctx_){}

	virtual ~SegmenterInstanceImpl();
	virtual void defineSelectorExpression(
			int p1, 
			const std::string& p2);
	virtual void defineSubSection(
			int p1, 
			int p2, 
			const std::string& p3);
	virtual SegmenterContextInterface* createContext(
			const DocumentClass& p1);
};

class SegmenterImpl
		:public TraceObject<SegmenterInterface>
		,public SegmenterInterface
{
public:
	SegmenterImpl( SegmenterInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SegmenterInterface>(obj_,ctx_){}

	virtual ~SegmenterImpl();
	virtual const char* mimeType();
	virtual SegmenterInstanceInterface* createInstance();
};

class StatisticsBuilderImpl
		:public TraceObject<StatisticsBuilderInterface>
		,public StatisticsBuilderInterface
{
public:
	StatisticsBuilderImpl( StatisticsBuilderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsBuilderInterface>(obj_,ctx_){}

	virtual ~StatisticsBuilderImpl();
	virtual void setNofDocumentsInsertedChange(
			int p1);
	virtual void addDfChange(
			const char* p1, 
			const char* p2, 
			int p3);
	virtual void start();
	virtual void rollback();
	virtual bool fetchMessage(
			const char*& blk, std::size_t& p1);
};

class StatisticsIteratorImpl
		:public TraceObject<StatisticsIteratorInterface>
		,public StatisticsIteratorInterface
{
public:
	StatisticsIteratorImpl( StatisticsIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsIteratorInterface>(obj_,ctx_){}

	virtual ~StatisticsIteratorImpl();
	virtual bool getNext(
			const char*& msg, std::size_t& p1);
};

class StatisticsProcessorImpl
		:public TraceObject<StatisticsProcessorInterface>
		,public StatisticsProcessorInterface
{
public:
	StatisticsProcessorImpl( StatisticsProcessorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsProcessorInterface>(obj_,ctx_){}

	virtual ~StatisticsProcessorImpl();
	virtual StatisticsViewerInterface* createViewer(
			const char* msgptr, std::size_t p1);
	virtual StatisticsBuilderInterface* createBuilder(
			const BuilderOptions& p1);
};

class StatisticsViewerImpl
		:public TraceObject<StatisticsViewerInterface>
		,public StatisticsViewerInterface
{
public:
	StatisticsViewerImpl( StatisticsViewerInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsViewerInterface>(obj_,ctx_){}

	virtual ~StatisticsViewerImpl();
	virtual int nofDocumentsInsertedChange();
	virtual bool nextDfChange(
			DocumentFrequencyChange& p1);
};

class StorageAlterMetaDataTableImpl
		:public TraceObject<StorageAlterMetaDataTableInterface>
		,public StorageAlterMetaDataTableInterface
{
public:
	StorageAlterMetaDataTableImpl( StorageAlterMetaDataTableInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageAlterMetaDataTableInterface>(obj_,ctx_){}

	virtual ~StorageAlterMetaDataTableImpl();
	virtual void addElement(
			const std::string& p1, 
			const std::string& p2);
	virtual void alterElement(
			const std::string& p1, 
			const std::string& p2, 
			const std::string& p3);
	virtual void renameElement(
			const std::string& p1, 
			const std::string& p2);
	virtual void deleteElement(
			const std::string& p1);
	virtual void clearElement(
			const std::string& p1);
	virtual bool commit();
	virtual void rollback();
};

class StorageClientImpl
		:public TraceObject<StorageClientInterface>
		,public StorageClientInterface
{
public:
	StorageClientImpl( StorageClientInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageClientInterface>(obj_,ctx_){}

	virtual ~StorageClientImpl();
	virtual PostingIteratorInterface* createTermPostingIterator(
			const std::string& p1, 
			const std::string& p2);
	virtual PostingIteratorInterface* createBrowsePostingIterator(
			const MetaDataRestrictionInterface* p1, 
			const Index& p2);
	virtual ForwardIteratorInterface* createForwardIterator(
			const std::string& p1);
	virtual DocumentTermIteratorInterface* createDocumentTermIterator(
			const std::string& p1);
	virtual InvAclIteratorInterface* createInvAclIterator(
			const std::string& p1);
	virtual Index nofDocumentsInserted();
	virtual Index documentFrequency(
			const std::string& p1, 
			const std::string& p2);
	virtual Index maxDocumentNumber();
	virtual Index documentNumber(
			const std::string& p1);
	virtual ValueIteratorInterface* createTermTypeIterator();
	virtual ValueIteratorInterface* createTermValueIterator();
	virtual ValueIteratorInterface* createDocIdIterator();
	virtual ValueIteratorInterface* createUserNameIterator();
	virtual Index documentStatistics(
			const Index& p1, 
			const DocumentStatisticsType& p2, 
			const std::string& p3);
	virtual MetaDataReaderInterface* createMetaDataReader();
	virtual MetaDataRestrictionInterface* createMetaDataRestriction();
	virtual AttributeReaderInterface* createAttributeReader();
	virtual StorageTransactionInterface* createTransaction();
	virtual StatisticsIteratorInterface* createInitStatisticsIterator(
			bool p1);
	virtual StatisticsIteratorInterface* createUpdateStatisticsIterator();
	virtual const StatisticsProcessorInterface* getStatisticsProcessor();
	virtual StorageDocumentInterface* createDocumentChecker(
			const std::string& p1, 
			const std::string& p2);
	virtual bool checkStorage(
			std::ostream& p1);
	virtual StorageDumpInterface* createDump(
			const std::string& p1);
};

class StorageDocumentImpl
		:public TraceObject<StorageDocumentInterface>
		,public StorageDocumentInterface
{
public:
	StorageDocumentImpl( StorageDocumentInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageDocumentInterface>(obj_,ctx_){}

	virtual ~StorageDocumentImpl();
	virtual void addSearchIndexTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3);
	virtual void addForwardIndexTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3);
	virtual void setMetaData(
			const std::string& p1, 
			const NumericVariant& p2);
	virtual void setAttribute(
			const std::string& p1, 
			const std::string& p2);
	virtual void setUserAccessRight(
			const std::string& p1);
	virtual void done();
};

class StorageDocumentUpdateImpl
		:public TraceObject<StorageDocumentUpdateInterface>
		,public StorageDocumentUpdateInterface
{
public:
	StorageDocumentUpdateImpl( StorageDocumentUpdateInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageDocumentUpdateInterface>(obj_,ctx_){}

	virtual ~StorageDocumentUpdateImpl();
	virtual void setMetaData(
			const std::string& p1, 
			const NumericVariant& p2);
	virtual void setAttribute(
			const std::string& p1, 
			const std::string& p2);
	virtual void clearAttribute(
			const std::string& p1);
	virtual void setUserAccessRight(
			const std::string& p1);
	virtual void clearUserAccessRight(
			const std::string& p1);
	virtual void clearUserAccessRights();
	virtual void done();
};

class StorageDumpImpl
		:public TraceObject<StorageDumpInterface>
		,public StorageDumpInterface
{
public:
	StorageDumpImpl( StorageDumpInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageDumpInterface>(obj_,ctx_){}

	virtual ~StorageDumpImpl();
	virtual bool nextChunk(
			const char*& chunk, std::size_t& p1);
};

class StorageImpl
		:public TraceObject<StorageInterface>
		,public StorageInterface
{
public:
	StorageImpl( StorageInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageInterface>(obj_,ctx_){}

	virtual ~StorageImpl();
	virtual StorageClientInterface* createClient(
			const std::string& p1, 
			DatabaseClientInterface* p2, 
			const StatisticsProcessorInterface* p3);
	virtual bool createStorage(
			const std::string& p1, 
			DatabaseClientInterface* p2);
	virtual StorageAlterMetaDataTableInterface* createAlterMetaDataTable(
			DatabaseClientInterface* p1);
	virtual const char* getConfigDescription(
			const ConfigType& p1);
	virtual const char** getConfigParameters(
			const ConfigType& p1);
};

class StorageObjectBuilderImpl
		:public TraceObject<StorageObjectBuilderInterface>
		,public StorageObjectBuilderInterface
{
public:
	StorageObjectBuilderImpl( StorageObjectBuilderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageObjectBuilderInterface>(obj_,ctx_){}

	virtual ~StorageObjectBuilderImpl();
	virtual const StorageInterface* getStorage();
	virtual const DatabaseInterface* getDatabase(
			const std::string& p1);
	virtual const QueryProcessorInterface* getQueryProcessor();
	virtual const StatisticsProcessorInterface* getStatisticsProcessor();
	virtual StorageClientInterface* createStorageClient(
			const std::string& p1);
	virtual StorageAlterMetaDataTableInterface* createAlterMetaDataTable(
			const std::string& p1);
	virtual QueryEvalInterface* createQueryEval();
};

class StorageTransactionImpl
		:public TraceObject<StorageTransactionInterface>
		,public StorageTransactionInterface
{
public:
	StorageTransactionImpl( StorageTransactionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageTransactionInterface>(obj_,ctx_){}

	virtual ~StorageTransactionImpl();
	virtual StorageDocumentInterface* createDocument(
			const std::string& p1);
	virtual StorageDocumentUpdateInterface* createDocumentUpdate(
			const Index& p1);
	virtual void deleteDocument(
			const std::string& p1);
	virtual void deleteUserAccessRights(
			const std::string& p1);
	virtual void updateMetaData(
			const Index& p1, 
			const std::string& p2, 
			const NumericVariant& p3);
	virtual bool commit();
	virtual void rollback();
};

class SummarizerFunctionContextImpl
		:public TraceObject<SummarizerFunctionContextInterface>
		,public SummarizerFunctionContextInterface
{
public:
	SummarizerFunctionContextImpl( SummarizerFunctionContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SummarizerFunctionContextInterface>(obj_,ctx_){}

	virtual ~SummarizerFunctionContextImpl();
	virtual void addSummarizationFeature(
			const std::string& p1, 
			PostingIteratorInterface* p2, 
			const std::vector<SummarizationVariable>&  p3, 
			double p4, 
			const TermStatistics& p5);
	virtual std::vector<SummaryElement> getSummary(
			const Index& p1);
};

class SummarizerFunctionInstanceImpl
		:public TraceObject<SummarizerFunctionInstanceInterface>
		,public SummarizerFunctionInstanceInterface
{
public:
	SummarizerFunctionInstanceImpl( SummarizerFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SummarizerFunctionInstanceInterface>(obj_,ctx_){}

	virtual ~SummarizerFunctionInstanceImpl();
	virtual void addStringParameter(
			const std::string& p1, 
			const std::string& p2);
	virtual void addNumericParameter(
			const std::string& p1, 
			const NumericVariant& p2);
	virtual SummarizerFunctionContextInterface* createFunctionContext(
			const StorageClientInterface* p1, 
			MetaDataReaderInterface* p2, 
			const GlobalStatistics& p3);
	virtual std::string tostring();
};

class SummarizerFunctionImpl
		:public TraceObject<SummarizerFunctionInterface>
		,public SummarizerFunctionInterface
{
public:
	SummarizerFunctionImpl( SummarizerFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SummarizerFunctionInterface>(obj_,ctx_){}

	virtual ~SummarizerFunctionImpl();
	virtual SummarizerFunctionInstanceInterface* createInstance(
			const QueryProcessorInterface* p1);
	virtual FunctionDescription getDescription();
};

class TextProcessorImpl
		:public TraceObject<TextProcessorInterface>
		,public TextProcessorInterface
{
public:
	TextProcessorImpl( TextProcessorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TextProcessorInterface>(obj_,ctx_){}

	virtual ~TextProcessorImpl();
	virtual void addResourcePath(
			const std::string& p1);
	virtual std::string getResourcePath(
			const std::string& p1);
	virtual const TokenizerFunctionInterface* getTokenizer(
			const std::string& p1);
	virtual const NormalizerFunctionInterface* getNormalizer(
			const std::string& p1);
	virtual const AggregatorFunctionInterface* getAggregator(
			const std::string& p1);
	virtual bool detectDocumentClass(
			DocumentClass& p1, 
			const char* contentBegin, std::size_t p2);
	virtual void defineDocumentClassDetector(
			DocumentClassDetectorInterface* p1);
	virtual void defineTokenizer(
			const std::string& p1, 
			TokenizerFunctionInterface* p2);
	virtual void defineNormalizer(
			const std::string& p1, 
			NormalizerFunctionInterface* p2);
	virtual void defineAggregator(
			const std::string& p1, 
			AggregatorFunctionInterface* p2);
	virtual std::vector<std::string> getFunctionList(
			const FunctionType& p1);
};

class TokenizerFunctionContextImpl
		:public TraceObject<TokenizerFunctionContextInterface>
		,public TokenizerFunctionContextInterface
{
public:
	TokenizerFunctionContextImpl( TokenizerFunctionContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TokenizerFunctionContextInterface>(obj_,ctx_){}

	virtual ~TokenizerFunctionContextImpl();
	virtual std::vector<analyzer::Token> tokenize(
			const char* src, std::size_t p1);
};

class TokenizerFunctionInstanceImpl
		:public TraceObject<TokenizerFunctionInstanceInterface>
		,public TokenizerFunctionInstanceInterface
{
public:
	TokenizerFunctionInstanceImpl( TokenizerFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TokenizerFunctionInstanceInterface>(obj_,ctx_){}

	virtual ~TokenizerFunctionInstanceImpl();
	virtual bool concatBeforeTokenize();
	virtual TokenizerFunctionContextInterface* createFunctionContext();
};

class TokenizerFunctionImpl
		:public TraceObject<TokenizerFunctionInterface>
		,public TokenizerFunctionInterface
{
public:
	TokenizerFunctionImpl( TokenizerFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TokenizerFunctionInterface>(obj_,ctx_){}

	virtual ~TokenizerFunctionImpl();
	virtual TokenizerFunctionInstanceInterface* createInstance(
			const std::vector<std::string>& p1, 
			const TextProcessorInterface* p2);
	virtual const char* getDescription();
};

class ValueIteratorImpl
		:public TraceObject<ValueIteratorInterface>
		,public ValueIteratorInterface
{
public:
	ValueIteratorImpl( ValueIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ValueIteratorInterface>(obj_,ctx_){}

	virtual ~ValueIteratorImpl();
	virtual void skip(
			const char* value, std::size_t p1);
	virtual std::vector<std::string> fetchValues(
			std::size_t p1);
};

class WeightingFunctionContextImpl
		:public TraceObject<WeightingFunctionContextInterface>
		,public WeightingFunctionContextInterface
{
public:
	WeightingFunctionContextImpl( WeightingFunctionContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<WeightingFunctionContextInterface>(obj_,ctx_){}

	virtual ~WeightingFunctionContextImpl();
	virtual void addWeightingFeature(
			const std::string& p1, 
			PostingIteratorInterface* p2, 
			double p3, 
			const TermStatistics& p4);
	virtual double call(
			const Index& p1);
};

class WeightingFunctionInstanceImpl
		:public TraceObject<WeightingFunctionInstanceInterface>
		,public WeightingFunctionInstanceInterface
{
public:
	WeightingFunctionInstanceImpl( WeightingFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<WeightingFunctionInstanceInterface>(obj_,ctx_){}

	virtual ~WeightingFunctionInstanceImpl();
	virtual void addStringParameter(
			const std::string& p1, 
			const std::string& p2);
	virtual void addNumericParameter(
			const std::string& p1, 
			const NumericVariant& p2);
	virtual WeightingFunctionContextInterface* createFunctionContext(
			const StorageClientInterface* p1, 
			MetaDataReaderInterface* p2, 
			const GlobalStatistics& p3);
	virtual std::string tostring();
};

class WeightingFunctionImpl
		:public TraceObject<WeightingFunctionInterface>
		,public WeightingFunctionInterface
{
public:
	WeightingFunctionImpl( WeightingFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<WeightingFunctionInterface>(obj_,ctx_){}

	virtual ~WeightingFunctionImpl();
	virtual WeightingFunctionInstanceInterface* createInstance(
			const QueryProcessorInterface* p1);
	virtual FunctionDescription getDescription();
};


}//namespace
#endif

