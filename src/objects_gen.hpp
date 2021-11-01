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
#include "strus/aclReaderInterface.hpp"
#include "strus/aggregatorFunctionInstanceInterface.hpp"
#include "strus/aggregatorFunctionInterface.hpp"
#include "strus/analyzerObjectBuilderInterface.hpp"
#include "strus/attributeReaderInterface.hpp"
#include "strus/contentIteratorInterface.hpp"
#include "strus/contentStatisticsContextInterface.hpp"
#include "strus/contentStatisticsInterface.hpp"
#include "strus/databaseBackupCursorInterface.hpp"
#include "strus/databaseClientInterface.hpp"
#include "strus/databaseCursorInterface.hpp"
#include "strus/databaseInterface.hpp"
#include "strus/databaseTransactionInterface.hpp"
#include "strus/documentAnalyzerContextInterface.hpp"
#include "strus/documentAnalyzerInstanceInterface.hpp"
#include "strus/documentAnalyzerMapInterface.hpp"
#include "strus/documentClassDetectorInterface.hpp"
#include "strus/documentTermIteratorInterface.hpp"
#include "strus/fileLocatorInterface.hpp"
#include "strus/forwardIteratorInterface.hpp"
#include "strus/invAclIteratorInterface.hpp"
#include "strus/metaDataReaderInterface.hpp"
#include "strus/metaDataRestrictionInstanceInterface.hpp"
#include "strus/metaDataRestrictionInterface.hpp"
#include "strus/normalizerFunctionInstanceInterface.hpp"
#include "strus/normalizerFunctionInterface.hpp"
#include "strus/patternLexerContextInterface.hpp"
#include "strus/patternLexerInstanceInterface.hpp"
#include "strus/patternLexerInterface.hpp"
#include "strus/patternMatcherContextInterface.hpp"
#include "strus/patternMatcherInstanceInterface.hpp"
#include "strus/patternMatcherInterface.hpp"
#include "strus/patternTermFeederInstanceInterface.hpp"
#include "strus/patternTermFeederInterface.hpp"
#include "strus/posTaggerContextInterface.hpp"
#include "strus/posTaggerDataInterface.hpp"
#include "strus/posTaggerInstanceInterface.hpp"
#include "strus/posTaggerInterface.hpp"
#include "strus/postingIteratorInterface.hpp"
#include "strus/postingJoinOperatorInterface.hpp"
#include "strus/queryAnalyzerContextInterface.hpp"
#include "strus/queryAnalyzerInstanceInterface.hpp"
#include "strus/queryEvalInterface.hpp"
#include "strus/queryInterface.hpp"
#include "strus/queryProcessorInterface.hpp"
#include "strus/scalarFunctionInstanceInterface.hpp"
#include "strus/scalarFunctionInterface.hpp"
#include "strus/scalarFunctionParserInterface.hpp"
#include "strus/segmenterContextInterface.hpp"
#include "strus/segmenterInstanceInterface.hpp"
#include "strus/segmenterInterface.hpp"
#include "strus/segmenterMarkupContextInterface.hpp"
#include "strus/sentenceLexerInstanceInterface.hpp"
#include "strus/statisticsBuilderInterface.hpp"
#include "strus/statisticsMapInterface.hpp"
#include "strus/statisticsProcessorInterface.hpp"
#include "strus/statisticsStorageClientInterface.hpp"
#include "strus/statisticsStorageInterface.hpp"
#include "strus/statisticsViewerInterface.hpp"
#include "strus/storageClientInterface.hpp"
#include "strus/storageDocumentInterface.hpp"
#include "strus/storageDocumentUpdateInterface.hpp"
#include "strus/storageDumpInterface.hpp"
#include "strus/storageInterface.hpp"
#include "strus/storageMetaDataTableUpdateInterface.hpp"
#include "strus/storageObjectBuilderInterface.hpp"
#include "strus/storageTransactionInterface.hpp"
#include "strus/structureIteratorInterface.hpp"
#include "strus/summarizerFunctionContextInterface.hpp"
#include "strus/summarizerFunctionInstanceInterface.hpp"
#include "strus/summarizerFunctionInterface.hpp"
#include "strus/textProcessorInterface.hpp"
#include "strus/tokenizerFunctionInstanceInterface.hpp"
#include "strus/tokenizerFunctionInterface.hpp"
#include "strus/tokenMarkupContextInterface.hpp"
#include "strus/tokenMarkupInstanceInterface.hpp"
#include "strus/valueIteratorInterface.hpp"
#include "strus/vectorStorageClientInterface.hpp"
#include "strus/vectorStorageDumpInterface.hpp"
#include "strus/vectorStorageInterface.hpp"
#include "strus/vectorStorageTransactionInterface.hpp"
#include "strus/weightingFunctionContextInterface.hpp"
#include "strus/weightingFunctionInstanceInterface.hpp"
#include "strus/weightingFunctionInterface.hpp"
#include <string>
#include <vector>

namespace strus {
namespace trace {

class AclReaderImpl
		:public TraceObject<AclReaderInterface>
		,public AclReaderInterface
		,public AclReaderConst
{
public:
	AclReaderImpl( AclReaderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AclReaderInterface>(obj_,ctx_){}
	AclReaderImpl( const AclReaderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AclReaderInterface>(obj_,ctx_){}

	virtual ~AclReaderImpl();
	virtual void skipDoc(
			const Index& p1);
	virtual std::vector<std::string> getReadAccessList() const;
};

class AggregatorFunctionInstanceImpl
		:public TraceObject<AggregatorFunctionInstanceInterface>
		,public AggregatorFunctionInstanceInterface
		,public AggregatorFunctionInstanceConst
{
public:
	AggregatorFunctionInstanceImpl( AggregatorFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AggregatorFunctionInstanceInterface>(obj_,ctx_){}
	AggregatorFunctionInstanceImpl( const AggregatorFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AggregatorFunctionInstanceInterface>(obj_,ctx_){}

	virtual ~AggregatorFunctionInstanceImpl();
	virtual NumericVariant evaluate(
			const analyzer::Document& p1) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class AggregatorFunctionImpl
		:public TraceObject<AggregatorFunctionInterface>
		,public AggregatorFunctionInterface
		,public AggregatorFunctionConst
{
public:
	AggregatorFunctionImpl( AggregatorFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AggregatorFunctionInterface>(obj_,ctx_){}
	AggregatorFunctionImpl( const AggregatorFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AggregatorFunctionInterface>(obj_,ctx_){}

	virtual ~AggregatorFunctionImpl();
	virtual AggregatorFunctionInstanceInterface* createInstance(
			const std::vector<std::string>& p1) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class AnalyzerObjectBuilderImpl
		:public TraceObject<AnalyzerObjectBuilderInterface>
		,public AnalyzerObjectBuilderInterface
		,public AnalyzerObjectBuilderConst
{
public:
	AnalyzerObjectBuilderImpl( AnalyzerObjectBuilderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AnalyzerObjectBuilderInterface>(obj_,ctx_){}
	AnalyzerObjectBuilderImpl( const AnalyzerObjectBuilderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AnalyzerObjectBuilderInterface>(obj_,ctx_){}

	virtual ~AnalyzerObjectBuilderImpl();
	virtual const TextProcessorInterface* getTextProcessor() const;
	virtual DocumentAnalyzerInstanceInterface* createDocumentAnalyzer(
			const SegmenterInterface* p1, 
			const analyzer::SegmenterOptions& p2) const;
	virtual PosTaggerInstanceInterface* createPosTaggerInstance(
			const SegmenterInterface* p1, 
			const analyzer::SegmenterOptions& p2) const;
	virtual QueryAnalyzerInstanceInterface* createQueryAnalyzer() const;
	virtual DocumentAnalyzerMapInterface* createDocumentAnalyzerMap() const;
	virtual DocumentClassDetectorInterface* createDocumentClassDetector() const;
	virtual ContentStatisticsInterface* createContentStatistics() const;
};

class AttributeReaderImpl
		:public TraceObject<AttributeReaderInterface>
		,public AttributeReaderInterface
		,public AttributeReaderConst
{
public:
	AttributeReaderImpl( AttributeReaderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AttributeReaderInterface>(obj_,ctx_){}
	AttributeReaderImpl( const AttributeReaderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<AttributeReaderInterface>(obj_,ctx_){}

	virtual ~AttributeReaderImpl();
	virtual Index elementHandle(
			const std::string& p1) const;
	virtual void skipDoc(
			const Index& p1);
	virtual std::string getValue(
			const Index& p1) const;
	virtual std::vector<std::string> getNames() const;
};

class ContentIteratorImpl
		:public TraceObject<ContentIteratorInterface>
		,public ContentIteratorInterface
		,public ContentIteratorConst
{
public:
	ContentIteratorImpl( ContentIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ContentIteratorInterface>(obj_,ctx_){}
	ContentIteratorImpl( const ContentIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ContentIteratorInterface>(obj_,ctx_){}

	virtual ~ContentIteratorImpl();
	virtual bool getNext(
			const char*& expression, std::size_t& p1, 
			const char*& segment, std::size_t& p2);
};

class ContentStatisticsContextImpl
		:public TraceObject<ContentStatisticsContextInterface>
		,public ContentStatisticsContextInterface
		,public ContentStatisticsContextConst
{
public:
	ContentStatisticsContextImpl( ContentStatisticsContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ContentStatisticsContextInterface>(obj_,ctx_){}
	ContentStatisticsContextImpl( const ContentStatisticsContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ContentStatisticsContextInterface>(obj_,ctx_){}

	virtual ~ContentStatisticsContextImpl();
	virtual void putContent(
			const std::string& p1, 
			const std::string& p2, 
			const analyzer::DocumentClass& p3);
	virtual analyzer::ContentStatisticsResult statistics();
	virtual int nofDocuments() const;
};

class ContentStatisticsImpl
		:public TraceObject<ContentStatisticsInterface>
		,public ContentStatisticsInterface
		,public ContentStatisticsConst
{
public:
	ContentStatisticsImpl( ContentStatisticsInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ContentStatisticsInterface>(obj_,ctx_){}
	ContentStatisticsImpl( const ContentStatisticsInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ContentStatisticsInterface>(obj_,ctx_){}

	virtual ~ContentStatisticsImpl();
	virtual void addLibraryElement(
			const std::string& p1, 
			const std::string& p2, 
			int p3, 
			int p4, 
			int p5, 
			TokenizerFunctionInstanceInterface* p6, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p7);
	virtual void addVisibleAttribute(
			const std::string& p1);
	virtual void addSelectorExpression(
			const std::string& p1);
	virtual ContentStatisticsContextInterface* createContext() const;
	virtual StructView view() const;
};

class DatabaseBackupCursorImpl
		:public TraceObject<DatabaseBackupCursorInterface>
		,public DatabaseBackupCursorInterface
		,public DatabaseBackupCursorConst
{
public:
	DatabaseBackupCursorImpl( DatabaseBackupCursorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseBackupCursorInterface>(obj_,ctx_){}
	DatabaseBackupCursorImpl( const DatabaseBackupCursorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseBackupCursorInterface>(obj_,ctx_){}

	virtual ~DatabaseBackupCursorImpl();
	virtual bool fetch(
			const char*& key, std::size_t& p1, 
			const char*& blk, std::size_t& p2);
};

class DatabaseClientImpl
		:public TraceObject<DatabaseClientInterface>
		,public DatabaseClientInterface
		,public DatabaseClientConst
{
public:
	DatabaseClientImpl( DatabaseClientInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseClientInterface>(obj_,ctx_){}
	DatabaseClientImpl( const DatabaseClientInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseClientInterface>(obj_,ctx_){}

	virtual ~DatabaseClientImpl();
	virtual DatabaseTransactionInterface* createTransaction();
	virtual DatabaseCursorInterface* createCursor(
			const DatabaseOptions& p1) const;
	virtual DatabaseBackupCursorInterface* createBackupCursor() const;
	virtual void writeImm(
			const char* key, std::size_t p1, 
			const char* value, std::size_t p2);
	virtual void removeImm(
			const char* key, std::size_t p1);
	virtual bool readValue(
			const char* key, std::size_t p1, 
			std::string& p2, 
			const DatabaseOptions& p3) const;
	virtual long diskUsage() const;
	virtual std::string config() const;
	virtual bool compactDatabase();
	virtual void close();
};

class DatabaseCursorImpl
		:public TraceObject<DatabaseCursorInterface>
		,public DatabaseCursorInterface
		,public DatabaseCursorConst
{
public:
	DatabaseCursorImpl( DatabaseCursorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseCursorInterface>(obj_,ctx_){}
	DatabaseCursorImpl( const DatabaseCursorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseCursorInterface>(obj_,ctx_){}

	virtual ~DatabaseCursorImpl();
	virtual Slice seekUpperBound(
			const char* keystr, std::size_t p1, 
			std::size_t p2);
	virtual Slice seekUpperBoundRestricted(
			const char* keystr, std::size_t p1, 
			const char* upkey, std::size_t p2);
	virtual Slice seekFirst(
			const char* domainkey, std::size_t p1);
	virtual Slice seekLast(
			const char* domainkey, std::size_t p1);
	virtual Slice seekNext();
	virtual Slice seekPrev();
	virtual Slice key() const;
	virtual Slice value() const;
};

class DatabaseImpl
		:public TraceObject<DatabaseInterface>
		,public DatabaseInterface
		,public DatabaseConst
{
public:
	DatabaseImpl( DatabaseInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseInterface>(obj_,ctx_){}
	DatabaseImpl( const DatabaseInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseInterface>(obj_,ctx_){}

	virtual ~DatabaseImpl();
	virtual bool exists(
			const std::string& p1) const;
	virtual DatabaseClientInterface* createClient(
			const std::string& p1) const;
	virtual bool createDatabase(
			const std::string& p1) const;
	virtual bool restoreDatabase(
			const std::string& p1, 
			DatabaseBackupCursorInterface* p2) const;
	virtual bool destroyDatabase(
			const std::string& p1) const;
	virtual const char* getConfigDescription() const;
	virtual const char** getConfigParameters() const;
};

class DatabaseTransactionImpl
		:public TraceObject<DatabaseTransactionInterface>
		,public DatabaseTransactionInterface
		,public DatabaseTransactionConst
{
public:
	DatabaseTransactionImpl( DatabaseTransactionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseTransactionInterface>(obj_,ctx_){}
	DatabaseTransactionImpl( const DatabaseTransactionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DatabaseTransactionInterface>(obj_,ctx_){}

	virtual ~DatabaseTransactionImpl();
	virtual DatabaseCursorInterface* createCursor(
			const DatabaseOptions& p1) const;
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
		,public DocumentAnalyzerContextConst
{
public:
	DocumentAnalyzerContextImpl( DocumentAnalyzerContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentAnalyzerContextInterface>(obj_,ctx_){}
	DocumentAnalyzerContextImpl( const DocumentAnalyzerContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentAnalyzerContextInterface>(obj_,ctx_){}

	virtual ~DocumentAnalyzerContextImpl();
	virtual void putInput(
			const char* chunk, std::size_t p1, 
			bool p2);
	virtual bool analyzeNext(
			analyzer::Document& p1);
};

class DocumentAnalyzerInstanceImpl
		:public TraceObject<DocumentAnalyzerInstanceInterface>
		,public DocumentAnalyzerInstanceInterface
		,public DocumentAnalyzerInstanceConst
{
public:
	DocumentAnalyzerInstanceImpl( DocumentAnalyzerInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentAnalyzerInstanceInterface>(obj_,ctx_){}
	DocumentAnalyzerInstanceImpl( const DocumentAnalyzerInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentAnalyzerInstanceInterface>(obj_,ctx_){}

	virtual ~DocumentAnalyzerInstanceImpl();
	virtual void addSearchIndexFeature(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			int p5, 
			const analyzer::FeatureOptions& p6);
	virtual void addForwardIndexFeature(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			int p5, 
			const analyzer::FeatureOptions& p6);
	virtual void addSearchIndexField(
			const std::string& p1, 
			const std::string& p2, 
			const std::string& p3, 
			const std::string& p4);
	virtual void addSearchIndexStructure(
			const std::string& p1, 
			const std::string& p2, 
			const std::string& p3, 
			const StructureType& p4);
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
	virtual void defineSubContent(
			const std::string& p1, 
			const analyzer::DocumentClass& p2);
	virtual analyzer::Document analyze(
			const std::string& p1, 
			const analyzer::DocumentClass& p2) const;
	virtual DocumentAnalyzerContextInterface* createContext(
			const analyzer::DocumentClass& p1) const;
	virtual StructView view() const;
};

class DocumentAnalyzerMapImpl
		:public TraceObject<DocumentAnalyzerMapInterface>
		,public DocumentAnalyzerMapInterface
		,public DocumentAnalyzerMapConst
{
public:
	DocumentAnalyzerMapImpl( DocumentAnalyzerMapInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentAnalyzerMapInterface>(obj_,ctx_){}
	DocumentAnalyzerMapImpl( const DocumentAnalyzerMapInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentAnalyzerMapInterface>(obj_,ctx_){}

	virtual ~DocumentAnalyzerMapImpl();
	virtual DocumentAnalyzerInstanceInterface* createAnalyzer(
			const std::string& p1, 
			const std::string& p2) const;
	virtual void addAnalyzer(
			const std::string& p1, 
			const std::string& p2, 
			DocumentAnalyzerInstanceInterface* p3);
	virtual const DocumentAnalyzerInstanceInterface* getAnalyzer(
			const std::string& p1, 
			const std::string& p2) const;
	virtual analyzer::Document analyze(
			const std::string& p1, 
			const analyzer::DocumentClass& p2) const;
	virtual DocumentAnalyzerContextInterface* createContext(
			const analyzer::DocumentClass& p1) const;
	virtual StructView view() const;
};

class DocumentClassDetectorImpl
		:public TraceObject<DocumentClassDetectorInterface>
		,public DocumentClassDetectorInterface
		,public DocumentClassDetectorConst
{
public:
	DocumentClassDetectorImpl( DocumentClassDetectorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentClassDetectorInterface>(obj_,ctx_){}
	DocumentClassDetectorImpl( const DocumentClassDetectorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentClassDetectorInterface>(obj_,ctx_){}

	virtual ~DocumentClassDetectorImpl();
	virtual void defineDocumentSchemaDetector(
			const std::string& p1, 
			const std::string& p2, 
			const std::vector<std::string>& p3, 
			const std::vector<std::string>& p4);
	virtual bool detect(
			analyzer::DocumentClass& p1, 
			const char* contentBegin, std::size_t p2, 
			bool p3) const;
	virtual StructView view() const;
};

class DocumentTermIteratorImpl
		:public TraceObject<DocumentTermIteratorInterface>
		,public DocumentTermIteratorInterface
		,public DocumentTermIteratorConst
{
public:
	DocumentTermIteratorImpl( DocumentTermIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentTermIteratorInterface>(obj_,ctx_){}
	DocumentTermIteratorImpl( const DocumentTermIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<DocumentTermIteratorInterface>(obj_,ctx_){}

	virtual ~DocumentTermIteratorImpl();
	virtual Index skipDoc(
			const Index& p1);
	virtual bool nextTerm(
			Term& p1);
	virtual int termDocumentFrequency(
			const Index& p1) const;
	virtual std::string termValue(
			const Index& p1) const;
};

class FileLocatorImpl
		:public TraceObject<FileLocatorInterface>
		,public FileLocatorInterface
		,public FileLocatorConst
{
public:
	FileLocatorImpl( FileLocatorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<FileLocatorInterface>(obj_,ctx_){}
	FileLocatorImpl( const FileLocatorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<FileLocatorInterface>(obj_,ctx_){}

	virtual ~FileLocatorImpl();
	virtual void addResourcePath(
			const std::string& p1);
	virtual std::string getResourceFilePath(
			const std::string& p1) const;
	virtual void defineWorkingDirectory(
			const std::string& p1);
	virtual std::string getWorkingDirectory() const;
	virtual std::vector<std::string> getResourcePaths() const;
};

class ForwardIteratorImpl
		:public TraceObject<ForwardIteratorInterface>
		,public ForwardIteratorInterface
		,public ForwardIteratorConst
{
public:
	ForwardIteratorImpl( ForwardIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ForwardIteratorInterface>(obj_,ctx_){}
	ForwardIteratorImpl( const ForwardIteratorInterface* obj_, TraceGlobalContext* ctx_)
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
		,public InvAclIteratorConst
{
public:
	InvAclIteratorImpl( InvAclIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<InvAclIteratorInterface>(obj_,ctx_){}
	InvAclIteratorImpl( const InvAclIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<InvAclIteratorInterface>(obj_,ctx_){}

	virtual ~InvAclIteratorImpl();
	virtual Index skipDoc(
			const Index& p1);
};

class MetaDataReaderImpl
		:public TraceObject<MetaDataReaderInterface>
		,public MetaDataReaderInterface
		,public MetaDataReaderConst
{
public:
	MetaDataReaderImpl( MetaDataReaderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<MetaDataReaderInterface>(obj_,ctx_){}
	MetaDataReaderImpl( const MetaDataReaderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<MetaDataReaderInterface>(obj_,ctx_){}

	virtual ~MetaDataReaderImpl();
	virtual Index elementHandle(
			const std::string& p1) const;
	virtual Index nofElements() const;
	virtual void skipDoc(
			const Index& p1);
	virtual NumericVariant getValue(
			const Index& p1) const;
	virtual const char* getType(
			const Index& p1) const;
	virtual const char* getName(
			const Index& p1) const;
	virtual std::vector<std::string> getNames() const;
};

class MetaDataRestrictionInstanceImpl
		:public TraceObject<MetaDataRestrictionInstanceInterface>
		,public MetaDataRestrictionInstanceInterface
		,public MetaDataRestrictionInstanceConst
{
public:
	MetaDataRestrictionInstanceImpl( MetaDataRestrictionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<MetaDataRestrictionInstanceInterface>(obj_,ctx_){}
	MetaDataRestrictionInstanceImpl( const MetaDataRestrictionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<MetaDataRestrictionInstanceInterface>(obj_,ctx_){}

	virtual ~MetaDataRestrictionInstanceImpl();
	virtual bool match(
			const Index& p1) const;
};

class MetaDataRestrictionImpl
		:public TraceObject<MetaDataRestrictionInterface>
		,public MetaDataRestrictionInterface
		,public MetaDataRestrictionConst
{
public:
	MetaDataRestrictionImpl( MetaDataRestrictionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<MetaDataRestrictionInterface>(obj_,ctx_){}
	MetaDataRestrictionImpl( const MetaDataRestrictionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<MetaDataRestrictionInterface>(obj_,ctx_){}

	virtual ~MetaDataRestrictionImpl();
	virtual void addCondition(
			const CompareOperator& p1, 
			const std::string& p2, 
			const NumericVariant& p3, 
			bool p4);
	virtual MetaDataRestrictionInstanceInterface* createInstance() const;
	virtual std::string tostring() const;
};

class NormalizerFunctionInstanceImpl
		:public TraceObject<NormalizerFunctionInstanceInterface>
		,public NormalizerFunctionInstanceInterface
		,public NormalizerFunctionInstanceConst
{
public:
	NormalizerFunctionInstanceImpl( NormalizerFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<NormalizerFunctionInstanceInterface>(obj_,ctx_){}
	NormalizerFunctionInstanceImpl( const NormalizerFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<NormalizerFunctionInstanceInterface>(obj_,ctx_){}

	virtual ~NormalizerFunctionInstanceImpl();
	virtual std::string normalize(
			const char* src, std::size_t p1) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class NormalizerFunctionImpl
		:public TraceObject<NormalizerFunctionInterface>
		,public NormalizerFunctionInterface
		,public NormalizerFunctionConst
{
public:
	NormalizerFunctionImpl( NormalizerFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<NormalizerFunctionInterface>(obj_,ctx_){}
	NormalizerFunctionImpl( const NormalizerFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<NormalizerFunctionInterface>(obj_,ctx_){}

	virtual ~NormalizerFunctionImpl();
	virtual NormalizerFunctionInstanceInterface* createInstance(
			const std::vector<std::string>& p1, 
			const TextProcessorInterface* p2) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class PatternLexerContextImpl
		:public TraceObject<PatternLexerContextInterface>
		,public PatternLexerContextInterface
		,public PatternLexerContextConst
{
public:
	PatternLexerContextImpl( PatternLexerContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternLexerContextInterface>(obj_,ctx_){}
	PatternLexerContextImpl( const PatternLexerContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternLexerContextInterface>(obj_,ctx_){}

	virtual ~PatternLexerContextImpl();
	virtual std::vector<analyzer::PatternLexem> match(
			const char* src, std::size_t p1);
	virtual void reset();
};

class PatternLexerInstanceImpl
		:public TraceObject<PatternLexerInstanceInterface>
		,public PatternLexerInstanceInterface
		,public PatternLexerInstanceConst
{
public:
	PatternLexerInstanceImpl( PatternLexerInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternLexerInstanceInterface>(obj_,ctx_){}
	PatternLexerInstanceImpl( const PatternLexerInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternLexerInstanceInterface>(obj_,ctx_){}

	virtual ~PatternLexerInstanceImpl();
	virtual void defineOption(
			const std::string& p1, 
			double p2);
	virtual void defineLexemName(
			unsigned int p1, 
			const std::string& p2);
	virtual void defineLexem(
			unsigned int p1, 
			const std::string& p2, 
			unsigned int p3, 
			unsigned int p4, 
			analyzer::PositionBind p5);
	virtual void defineSymbol(
			unsigned int p1, 
			unsigned int p2, 
			const std::string& p3);
	virtual unsigned int getSymbol(
			unsigned int p1, 
			const std::string& p2) const;
	virtual const char* getLexemName(
			unsigned int p1) const;
	virtual bool compile();
	virtual PatternLexerContextInterface* createContext() const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class PatternLexerImpl
		:public TraceObject<PatternLexerInterface>
		,public PatternLexerInterface
		,public PatternLexerConst
{
public:
	PatternLexerImpl( PatternLexerInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternLexerInterface>(obj_,ctx_){}
	PatternLexerImpl( const PatternLexerInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternLexerInterface>(obj_,ctx_){}

	virtual ~PatternLexerImpl();
	virtual std::vector<std::string> getCompileOptionNames() const;
	virtual PatternLexerInstanceInterface* createInstance() const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class PatternMatcherContextImpl
		:public TraceObject<PatternMatcherContextInterface>
		,public PatternMatcherContextInterface
		,public PatternMatcherContextConst
{
public:
	PatternMatcherContextImpl( PatternMatcherContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternMatcherContextInterface>(obj_,ctx_){}
	PatternMatcherContextImpl( const PatternMatcherContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternMatcherContextInterface>(obj_,ctx_){}

	virtual ~PatternMatcherContextImpl();
	virtual void putInput(
			const analyzer::PatternLexem& p1);
	virtual std::vector<analyzer::PatternMatcherResult> fetchResults();
	virtual analyzer::PatternMatcherStatistics getStatistics() const;
	virtual void reset();
};

class PatternMatcherInstanceImpl
		:public TraceObject<PatternMatcherInstanceInterface>
		,public PatternMatcherInstanceInterface
		,public PatternMatcherInstanceConst
{
public:
	PatternMatcherInstanceImpl( PatternMatcherInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternMatcherInstanceInterface>(obj_,ctx_){}
	PatternMatcherInstanceImpl( const PatternMatcherInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternMatcherInstanceInterface>(obj_,ctx_){}

	virtual ~PatternMatcherInstanceImpl();
	virtual void defineOption(
			const std::string& p1, 
			double p2);
	virtual void defineTermFrequency(
			unsigned int p1, 
			double p2);
	virtual void pushTerm(
			unsigned int p1);
	virtual void pushExpression(
			JoinOperation p1, 
			std::size_t p2, 
			unsigned int p3, 
			unsigned int p4);
	virtual void pushPattern(
			const std::string& p1);
	virtual void attachVariable(
			const std::string& p1);
	virtual void definePattern(
			const std::string& p1, 
			const std::string& p2, 
			bool p3);
	virtual bool compile();
	virtual PatternMatcherContextInterface* createContext() const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class PatternMatcherImpl
		:public TraceObject<PatternMatcherInterface>
		,public PatternMatcherInterface
		,public PatternMatcherConst
{
public:
	PatternMatcherImpl( PatternMatcherInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternMatcherInterface>(obj_,ctx_){}
	PatternMatcherImpl( const PatternMatcherInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternMatcherInterface>(obj_,ctx_){}

	virtual ~PatternMatcherImpl();
	virtual std::vector<std::string> getCompileOptionNames() const;
	virtual PatternMatcherInstanceInterface* createInstance() const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class PatternTermFeederInstanceImpl
		:public TraceObject<PatternTermFeederInstanceInterface>
		,public PatternTermFeederInstanceInterface
		,public PatternTermFeederInstanceConst
{
public:
	PatternTermFeederInstanceImpl( PatternTermFeederInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternTermFeederInstanceInterface>(obj_,ctx_){}
	PatternTermFeederInstanceImpl( const PatternTermFeederInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternTermFeederInstanceInterface>(obj_,ctx_){}

	virtual ~PatternTermFeederInstanceImpl();
	virtual void defineLexem(
			unsigned int p1, 
			const std::string& p2);
	virtual void defineSymbol(
			unsigned int p1, 
			unsigned int p2, 
			const std::string& p3);
	virtual unsigned int getLexem(
			const std::string& p1) const;
	virtual std::vector<std::string> lexemTypes() const;
	virtual unsigned int getSymbol(
			unsigned int p1, 
			const std::string& p2) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class PatternTermFeederImpl
		:public TraceObject<PatternTermFeederInterface>
		,public PatternTermFeederInterface
		,public PatternTermFeederConst
{
public:
	PatternTermFeederImpl( PatternTermFeederInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternTermFeederInterface>(obj_,ctx_){}
	PatternTermFeederImpl( const PatternTermFeederInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PatternTermFeederInterface>(obj_,ctx_){}

	virtual ~PatternTermFeederImpl();
	virtual PatternTermFeederInstanceInterface* createInstance() const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class PosTaggerContextImpl
		:public TraceObject<PosTaggerContextInterface>
		,public PosTaggerContextInterface
		,public PosTaggerContextConst
{
public:
	PosTaggerContextImpl( PosTaggerContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PosTaggerContextInterface>(obj_,ctx_){}
	PosTaggerContextImpl( const PosTaggerContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PosTaggerContextInterface>(obj_,ctx_){}

	virtual ~PosTaggerContextImpl();
	virtual std::string markupDocument(
			int p1, 
			const analyzer::DocumentClass& p2, 
			const std::string& p3) const;
};

class PosTaggerDataImpl
		:public TraceObject<PosTaggerDataInterface>
		,public PosTaggerDataInterface
		,public PosTaggerDataConst
{
public:
	PosTaggerDataImpl( PosTaggerDataInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PosTaggerDataInterface>(obj_,ctx_){}
	PosTaggerDataImpl( const PosTaggerDataInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PosTaggerDataInterface>(obj_,ctx_){}

	virtual ~PosTaggerDataImpl();
	virtual void declareIgnoredToken(
			const std::string& p1);
	virtual void insert(
			int p1, 
			const std::vector<Element>& p2);
	virtual void markupSegment(
			TokenMarkupContextInterface* p1, 
			int p2, 
			int& p3, 
			const SegmenterPosition& p4, 
			const char* segmentptr, std::size_t p5) const;
};

class PosTaggerInstanceImpl
		:public TraceObject<PosTaggerInstanceInterface>
		,public PosTaggerInstanceInterface
		,public PosTaggerInstanceConst
{
public:
	PosTaggerInstanceImpl( PosTaggerInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PosTaggerInstanceInterface>(obj_,ctx_){}
	PosTaggerInstanceImpl( const PosTaggerInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PosTaggerInstanceInterface>(obj_,ctx_){}

	virtual ~PosTaggerInstanceImpl();
	virtual void addContentExpression(
			const std::string& p1);
	virtual void addPosTaggerInputPunctuation(
			const std::string& p1, 
			const std::string& p2, 
			int p3);
	virtual std::string getPosTaggerInput(
			const analyzer::DocumentClass& p1, 
			const std::string& p2) const;
	virtual std::string markupDocument(
			const PosTaggerDataInterface* p1, 
			int p2, 
			const analyzer::DocumentClass& p3, 
			const std::string& p4) const;
};

class PosTaggerImpl
		:public TraceObject<PosTaggerInterface>
		,public PosTaggerInterface
		,public PosTaggerConst
{
public:
	PosTaggerImpl( PosTaggerInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PosTaggerInterface>(obj_,ctx_){}
	PosTaggerImpl( const PosTaggerInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PosTaggerInterface>(obj_,ctx_){}

	virtual ~PosTaggerImpl();
	virtual PosTaggerInstanceInterface* createInstance(
			const SegmenterInterface* p1, 
			const analyzer::SegmenterOptions& p2) const;
};

class PostingIteratorImpl
		:public TraceObject<PostingIteratorInterface>
		,public PostingIteratorInterface
		,public PostingIteratorConst
{
public:
	PostingIteratorImpl( PostingIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PostingIteratorInterface>(obj_,ctx_){}
	PostingIteratorImpl( const PostingIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PostingIteratorInterface>(obj_,ctx_){}

	virtual ~PostingIteratorImpl();
	virtual Index skipDoc(
			const Index& p1);
	virtual Index skipDocCandidate(
			const Index& p1);
	virtual Index skipPos(
			const Index& p1);
	virtual const char* featureid() const;
	virtual GlobalCounter documentFrequency() const;
	virtual int frequency();
	virtual Index docno() const;
	virtual Index posno() const;
	virtual Index length() const;
};

class PostingJoinOperatorImpl
		:public TraceObject<PostingJoinOperatorInterface>
		,public PostingJoinOperatorInterface
		,public PostingJoinOperatorConst
{
public:
	PostingJoinOperatorImpl( PostingJoinOperatorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PostingJoinOperatorInterface>(obj_,ctx_){}
	PostingJoinOperatorImpl( const PostingJoinOperatorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<PostingJoinOperatorInterface>(obj_,ctx_){}

	virtual ~PostingJoinOperatorImpl();
	virtual PostingIteratorInterface* createResultIterator(
			const std::vector<Reference<PostingIteratorInterface> >& p1, 
			int p2, 
			unsigned int p3) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class QueryAnalyzerContextImpl
		:public TraceObject<QueryAnalyzerContextInterface>
		,public QueryAnalyzerContextInterface
		,public QueryAnalyzerContextConst
{
public:
	QueryAnalyzerContextImpl( QueryAnalyzerContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryAnalyzerContextInterface>(obj_,ctx_){}
	QueryAnalyzerContextImpl( const QueryAnalyzerContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryAnalyzerContextInterface>(obj_,ctx_){}

	virtual ~QueryAnalyzerContextImpl();
	virtual void putField(
			int p1, 
			const std::string& p2, 
			const std::string& p3);
	virtual void groupElements(
			int p1, 
			const std::vector<int>& p2, 
			const GroupBy& p3, 
			bool p4);
	virtual analyzer::QueryTermExpression analyze();
};

class QueryAnalyzerInstanceImpl
		:public TraceObject<QueryAnalyzerInstanceInterface>
		,public QueryAnalyzerInstanceInterface
		,public QueryAnalyzerInstanceConst
{
public:
	QueryAnalyzerInstanceImpl( QueryAnalyzerInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryAnalyzerInstanceInterface>(obj_,ctx_){}
	QueryAnalyzerInstanceImpl( const QueryAnalyzerInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryAnalyzerInstanceInterface>(obj_,ctx_){}

	virtual ~QueryAnalyzerInstanceImpl();
	virtual void addElement(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			int p5);
	virtual std::vector<std::string> queryTermTypes() const;
	virtual std::vector<std::string> queryFieldTypes() const;
	virtual QueryAnalyzerContextInterface* createContext() const;
	virtual StructView view() const;
};

class QueryEvalImpl
		:public TraceObject<QueryEvalInterface>
		,public QueryEvalInterface
		,public QueryEvalConst
{
public:
	QueryEvalImpl( QueryEvalInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryEvalInterface>(obj_,ctx_){}
	QueryEvalImpl( const QueryEvalInterface* obj_, TraceGlobalContext* ctx_)
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
	virtual std::vector<std::string> getWeightingFeatureSets() const;
	virtual std::vector<std::string> getSelectionFeatureSets() const;
	virtual std::vector<std::string> getRestrictionFeatureSets() const;
	virtual std::vector<std::string> getExclusionFeatureSets() const;
	virtual void addSummarizerFunction(
			const std::string& p1, 
			SummarizerFunctionInstanceInterface* p2, 
			const std::vector<FeatureParameter>& p3);
	virtual void addWeightingFunction(
			WeightingFunctionInstanceInterface* p1, 
			const std::vector<FeatureParameter>& p2);
	virtual void defineWeightingFormula(
			ScalarFunctionInterface* p1);
	virtual void usePositionInformation(
			const std::string& p1, 
			bool p2);
	virtual QueryInterface* createQuery(
			const StorageClientInterface* p1) const;
	virtual StructView view() const;
};

class QueryImpl
		:public TraceObject<QueryInterface>
		,public QueryInterface
		,public QueryConst
{
public:
	QueryImpl( QueryInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryInterface>(obj_,ctx_){}
	QueryImpl( const QueryInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryInterface>(obj_,ctx_){}

	virtual ~QueryImpl();
	virtual void defineTermStatistics(
			const std::string& p1, 
			const std::string& p2, 
			const TermStatistics& p3);
	virtual void defineGlobalStatistics(
			const GlobalStatistics& p1);
	virtual void pushTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3);
	virtual void pushExpression(
			const PostingJoinOperatorInterface* p1, 
			unsigned int p2, 
			int p3, 
			unsigned int p4);
	virtual void attachVariable(
			const std::string& p1);
	virtual void defineFeature(
			const std::string& p1, 
			double p2);
	virtual void addMetaDataRestrictionCondition(
			const MetaDataRestrictionInterface::CompareOperator& p1, 
			const std::string& p2, 
			const NumericVariant& p3, 
			bool p4);
	virtual void addDocumentEvaluationSet(
			const std::vector<Index>& p1);
	virtual void addAccess(
			const std::string& p1);
	virtual void setWeightingVariableValue(
			const std::string& p1, 
			double p2);
	virtual QueryResult evaluate(
			int p1, 
			int p2) const;
	virtual StructView view() const;
};

class QueryProcessorImpl
		:public TraceObject<QueryProcessorInterface>
		,public QueryProcessorInterface
		,public QueryProcessorConst
{
public:
	QueryProcessorImpl( QueryProcessorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryProcessorInterface>(obj_,ctx_){}
	QueryProcessorImpl( const QueryProcessorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<QueryProcessorInterface>(obj_,ctx_){}

	virtual ~QueryProcessorImpl();
	virtual std::string getResourceFilePath(
			const std::string& p1) const;
	virtual void definePostingJoinOperator(
			const std::string& p1, 
			PostingJoinOperatorInterface* p2);
	virtual const PostingJoinOperatorInterface* getPostingJoinOperator(
			const std::string& p1) const;
	virtual void defineWeightingFunction(
			const std::string& p1, 
			WeightingFunctionInterface* p2);
	virtual const WeightingFunctionInterface* getWeightingFunction(
			const std::string& p1) const;
	virtual void defineSummarizerFunction(
			const std::string& p1, 
			SummarizerFunctionInterface* p2);
	virtual const SummarizerFunctionInterface* getSummarizerFunction(
			const std::string& p1) const;
	virtual std::vector<std::string> getFunctionList(
			const FunctionType& p1) const;
	virtual void defineScalarFunctionParser(
			const std::string& p1, 
			ScalarFunctionParserInterface* p2);
	virtual const ScalarFunctionParserInterface* getScalarFunctionParser(
			const std::string& p1) const;
};

class ScalarFunctionInstanceImpl
		:public TraceObject<ScalarFunctionInstanceInterface>
		,public ScalarFunctionInstanceInterface
		,public ScalarFunctionInstanceConst
{
public:
	ScalarFunctionInstanceImpl( ScalarFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ScalarFunctionInstanceInterface>(obj_,ctx_){}
	ScalarFunctionInstanceImpl( const ScalarFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ScalarFunctionInstanceInterface>(obj_,ctx_){}

	virtual ~ScalarFunctionInstanceImpl();
	virtual void setVariableValue(
			const std::string& p1, 
			double p2);
	virtual double call(
			const double* args, unsigned int p1) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class ScalarFunctionImpl
		:public TraceObject<ScalarFunctionInterface>
		,public ScalarFunctionInterface
		,public ScalarFunctionConst
{
public:
	ScalarFunctionImpl( ScalarFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ScalarFunctionInterface>(obj_,ctx_){}
	ScalarFunctionImpl( const ScalarFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ScalarFunctionInterface>(obj_,ctx_){}

	virtual ~ScalarFunctionImpl();
	virtual std::vector<std::string> getVariables() const;
	virtual unsigned int getNofArguments() const;
	virtual void setDefaultVariableValue(
			const std::string& p1, 
			double p2);
	virtual ScalarFunctionInstanceInterface* createInstance() const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class ScalarFunctionParserImpl
		:public TraceObject<ScalarFunctionParserInterface>
		,public ScalarFunctionParserInterface
		,public ScalarFunctionParserConst
{
public:
	ScalarFunctionParserImpl( ScalarFunctionParserInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ScalarFunctionParserInterface>(obj_,ctx_){}
	ScalarFunctionParserImpl( const ScalarFunctionParserInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ScalarFunctionParserInterface>(obj_,ctx_){}

	virtual ~ScalarFunctionParserImpl();
	virtual ScalarFunctionInterface* createFunction(
			const std::string& p1, 
			const std::vector<std::string>& p2) const;
	virtual StructView view() const;
};

class SegmenterContextImpl
		:public TraceObject<SegmenterContextInterface>
		,public SegmenterContextInterface
		,public SegmenterContextConst
{
public:
	SegmenterContextImpl( SegmenterContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SegmenterContextInterface>(obj_,ctx_){}
	SegmenterContextImpl( const SegmenterContextInterface* obj_, TraceGlobalContext* ctx_)
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
		,public SegmenterInstanceConst
{
public:
	SegmenterInstanceImpl( SegmenterInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SegmenterInstanceInterface>(obj_,ctx_){}
	SegmenterInstanceImpl( const SegmenterInstanceInterface* obj_, TraceGlobalContext* ctx_)
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
			const analyzer::DocumentClass& p1) const;
	virtual SegmenterMarkupContextInterface* createMarkupContext(
			const analyzer::DocumentClass& p1, 
			const std::string& p2) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class SegmenterImpl
		:public TraceObject<SegmenterInterface>
		,public SegmenterInterface
		,public SegmenterConst
{
public:
	SegmenterImpl( SegmenterInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SegmenterInterface>(obj_,ctx_){}
	SegmenterImpl( const SegmenterInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SegmenterInterface>(obj_,ctx_){}

	virtual ~SegmenterImpl();
	virtual const char* mimeType() const;
	virtual SegmenterInstanceInterface* createInstance(
			const analyzer::SegmenterOptions& p1) const;
	virtual ContentIteratorInterface* createContentIterator(
			const char* content, std::size_t p1, 
			const std::vector<std::string>& p2, 
			const std::vector<std::string>& p3, 
			const analyzer::DocumentClass& p4, 
			const analyzer::SegmenterOptions& p5) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class SegmenterMarkupContextImpl
		:public TraceObject<SegmenterMarkupContextInterface>
		,public SegmenterMarkupContextInterface
		,public SegmenterMarkupContextConst
{
public:
	SegmenterMarkupContextImpl( SegmenterMarkupContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SegmenterMarkupContextInterface>(obj_,ctx_){}
	SegmenterMarkupContextImpl( const SegmenterMarkupContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SegmenterMarkupContextInterface>(obj_,ctx_){}

	virtual ~SegmenterMarkupContextImpl();
	virtual bool getNext(
			SegmenterPosition& p1, 
			const char*& segment, std::size_t& p2);
	virtual unsigned int segmentSize(
			const SegmenterPosition& p1);
	virtual std::string tagName(
			const SegmenterPosition& p1) const;
	virtual int tagLevel(
			const SegmenterPosition& p1) const;
	virtual void putOpenTag(
			const SegmenterPosition& p1, 
			std::size_t p2, 
			const std::string& p3);
	virtual void putAttribute(
			const SegmenterPosition& p1, 
			std::size_t p2, 
			const std::string& p3, 
			const std::string& p4);
	virtual void putCloseTag(
			const SegmenterPosition& p1, 
			std::size_t p2, 
			const std::string& p3);
	virtual std::string getContent() const;
};

class SentenceLexerInstanceImpl
		:public TraceObject<SentenceLexerInstanceInterface>
		,public SentenceLexerInstanceInterface
		,public SentenceLexerInstanceConst
{
public:
	SentenceLexerInstanceImpl( SentenceLexerInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SentenceLexerInstanceInterface>(obj_,ctx_){}
	SentenceLexerInstanceImpl( const SentenceLexerInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SentenceLexerInstanceInterface>(obj_,ctx_){}

	virtual ~SentenceLexerInstanceImpl();
	virtual std::vector<SentenceGuess> call(
			const std::vector<std::string>& p1, 
			int p2, 
			double p3) const;
	virtual std::vector<WeightedSentenceTerm> similarTerms(
			const std::string& p1, 
			const std::vector<WeightedSentenceTerm>& p2, 
			double p3, 
			int p4, 
			double p5) const;
};

class StatisticsBuilderImpl
		:public TraceObject<StatisticsBuilderInterface>
		,public StatisticsBuilderInterface
		,public StatisticsBuilderConst
{
public:
	StatisticsBuilderImpl( StatisticsBuilderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsBuilderInterface>(obj_,ctx_){}
	StatisticsBuilderImpl( const StatisticsBuilderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsBuilderInterface>(obj_,ctx_){}

	virtual ~StatisticsBuilderImpl();
	virtual void addNofDocumentsInsertedChange(
			int p1);
	virtual void addDfChange(
			const char* p1, 
			const char* p2, 
			int p3);
	virtual std::vector<StatisticsMessage> getMessages() const;
	virtual bool commit();
	virtual void rollback();
};

class StatisticsMapImpl
		:public TraceObject<StatisticsMapInterface>
		,public StatisticsMapInterface
		,public StatisticsMapConst
{
public:
	StatisticsMapImpl( StatisticsMapInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsMapInterface>(obj_,ctx_){}
	StatisticsMapImpl( const StatisticsMapInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsMapInterface>(obj_,ctx_){}

	virtual ~StatisticsMapImpl();
	virtual void addNofDocumentsInsertedChange(
			int p1);
	virtual void addDfChange(
			const char* p1, 
			const char* p2, 
			int p3);
	virtual bool processStatisticsMessage(
			const void* msgptr, std::size_t p1);
	virtual GlobalCounter nofDocuments() const;
	virtual GlobalCounter df(
			const std::string& p1, 
			const std::string& p2) const;
	virtual std::vector<std::string> types() const;
};

class StatisticsProcessorImpl
		:public TraceObject<StatisticsProcessorInterface>
		,public StatisticsProcessorInterface
		,public StatisticsProcessorConst
{
public:
	StatisticsProcessorImpl( StatisticsProcessorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsProcessorInterface>(obj_,ctx_){}
	StatisticsProcessorImpl( const StatisticsProcessorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsProcessorInterface>(obj_,ctx_){}

	virtual ~StatisticsProcessorImpl();
	virtual StatisticsViewerInterface* createViewer(
			const void* msgptr, std::size_t p1) const;
	virtual TimeStamp getUpperBoundTimeStamp(
			const std::string& p1, 
			TimeStamp p2) const;
	virtual StatisticsMessage loadChangeMessage(
			const std::string& p1, 
			TimeStamp p2) const;
	virtual StatisticsBuilderInterface* createBuilder(
			const std::string& p1) const;
	virtual StatisticsMapInterface* createMap(
			const std::string& p1) const;
	virtual void releaseStatistics(
			const std::string& p1, 
			TimeStamp p2) const;
};

class StatisticsStorageClientImpl
		:public TraceObject<StatisticsStorageClientInterface>
		,public StatisticsStorageClientInterface
		,public StatisticsStorageClientConst
{
public:
	StatisticsStorageClientImpl( StatisticsStorageClientInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsStorageClientInterface>(obj_,ctx_){}
	StatisticsStorageClientImpl( const StatisticsStorageClientInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsStorageClientInterface>(obj_,ctx_){}

	virtual ~StatisticsStorageClientImpl();
	virtual bool reload(
			const std::string& p1);
	virtual long diskUsage() const;
	virtual const char** getConfigParameters() const;
	virtual std::string config() const;
	virtual GlobalCounter nofDocuments() const;
	virtual GlobalCounter documentFrequency(
			const std::string& p1, 
			const std::string& p2) const;
	virtual TimeStamp storageTimeStamp(
			const std::string& p1) const;
	virtual bool putStatisticsMessage(
			const StatisticsMessage& p1, 
			const std::string& p2);
	virtual const StatisticsProcessorInterface* getStatisticsProcessor() const;
	virtual void close();
	virtual void compaction();
};

class StatisticsStorageImpl
		:public TraceObject<StatisticsStorageInterface>
		,public StatisticsStorageInterface
		,public StatisticsStorageConst
{
public:
	StatisticsStorageImpl( StatisticsStorageInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsStorageInterface>(obj_,ctx_){}
	StatisticsStorageImpl( const StatisticsStorageInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsStorageInterface>(obj_,ctx_){}

	virtual ~StatisticsStorageImpl();
	virtual StatisticsStorageClientInterface* createClient(
			const std::string& p1, 
			const DatabaseInterface* p2, 
			const StatisticsProcessorInterface* p3) const;
	virtual bool createStorage(
			const std::string& p1, 
			const DatabaseInterface* p2) const;
	virtual const char* getConfigDescription() const;
	virtual const char** getConfigParameters() const;
};

class StatisticsViewerImpl
		:public TraceObject<StatisticsViewerInterface>
		,public StatisticsViewerInterface
		,public StatisticsViewerConst
{
public:
	StatisticsViewerImpl( StatisticsViewerInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsViewerInterface>(obj_,ctx_){}
	StatisticsViewerImpl( const StatisticsViewerInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StatisticsViewerInterface>(obj_,ctx_){}

	virtual ~StatisticsViewerImpl();
	virtual int nofDocumentsInsertedChange();
	virtual bool nextDfChange(
			TermStatisticsChange& p1);
};

class StorageClientImpl
		:public TraceObject<StorageClientInterface>
		,public StorageClientInterface
		,public StorageClientConst
{
public:
	StorageClientImpl( StorageClientInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageClientInterface>(obj_,ctx_){}
	StorageClientImpl( const StorageClientInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageClientInterface>(obj_,ctx_){}

	virtual ~StorageClientImpl();
	virtual bool reload(
			const std::string& p1);
	virtual long diskUsage() const;
	virtual BlockStatistics blockStatistics() const;
	virtual std::string config() const;
	virtual PostingIteratorInterface* createTermPostingIterator(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3, 
			const TermStatistics& p4) const;
	virtual PostingIteratorInterface* createFrequencyPostingIterator(
			const std::string& p1, 
			const std::string& p2, 
			const TermStatistics& p3) const;
	virtual StructureIteratorInterface* createStructureIterator() const;
	virtual PostingIteratorInterface* createBrowsePostingIterator(
			const MetaDataRestrictionInterface* p1, 
			const Index& p2) const;
	virtual ForwardIteratorInterface* createForwardIterator(
			const std::string& p1) const;
	virtual DocumentTermIteratorInterface* createDocumentTermIterator(
			const std::string& p1) const;
	virtual InvAclIteratorInterface* createInvAclIterator(
			const std::string& p1) const;
	virtual AclReaderInterface* createAclReader() const;
	virtual Index nofDocumentsInserted() const;
	virtual Index documentFrequency(
			const std::string& p1, 
			const std::string& p2) const;
	virtual Index maxDocumentNumber() const;
	virtual Index documentNumber(
			const std::string& p1) const;
	virtual Index structTypeNumber(
			const std::string& p1) const;
	virtual Index termTypeNumber(
			const std::string& p1) const;
	virtual Index termValueNumber(
			const std::string& p1) const;
	virtual bool isForwardIndexTerm(
			const std::string& p1) const;
	virtual ValueIteratorInterface* createTermTypeIterator() const;
	virtual ValueIteratorInterface* createStructTypeIterator() const;
	virtual ValueIteratorInterface* createTermValueIterator() const;
	virtual ValueIteratorInterface* createDocIdIterator() const;
	virtual ValueIteratorInterface* createUserNameIterator() const;
	virtual Index documentStatistics(
			const Index& p1, 
			const DocumentStatisticsType& p2, 
			const std::string& p3) const;
	virtual MetaDataReaderInterface* createMetaDataReader() const;
	virtual MetaDataRestrictionInterface* createMetaDataRestriction() const;
	virtual AttributeReaderInterface* createAttributeReader() const;
	virtual StorageTransactionInterface* createTransaction();
	virtual TimeStamp getNextChangeStatisticsTimeStamp(
			TimeStamp p1) const;
	virtual StatisticsMessage loadChangeStatisticsMessage(
			TimeStamp p1) const;
	virtual std::vector<StatisticsMessage> loadInitStatisticsMessages() const;
	virtual const StatisticsProcessorInterface* getStatisticsProcessor() const;
	virtual StorageDocumentInterface* createDocumentChecker(
			const std::string& p1, 
			const std::string& p2) const;
	virtual StorageDumpInterface* createDump(
			const std::string& p1) const;
	virtual const char** getConfigParameters() const;
	virtual bool checkStorage(
			std::ostream& p1) const;
	virtual void close();
	virtual void compaction();
};

class StorageDocumentImpl
		:public TraceObject<StorageDocumentInterface>
		,public StorageDocumentInterface
		,public StorageDocumentConst
{
public:
	StorageDocumentImpl( StorageDocumentInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageDocumentInterface>(obj_,ctx_){}
	StorageDocumentImpl( const StorageDocumentInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageDocumentInterface>(obj_,ctx_){}

	virtual ~StorageDocumentImpl();
	virtual void addSearchIndexTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3);
	virtual void addSearchIndexStructure(
			const std::string& p1, 
			const IndexRange& p2, 
			const IndexRange& p3);
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
		,public StorageDocumentUpdateConst
{
public:
	StorageDocumentUpdateImpl( StorageDocumentUpdateInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageDocumentUpdateInterface>(obj_,ctx_){}
	StorageDocumentUpdateImpl( const StorageDocumentUpdateInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageDocumentUpdateInterface>(obj_,ctx_){}

	virtual ~StorageDocumentUpdateImpl();
	virtual void addSearchIndexTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3);
	virtual void addSearchIndexStructure(
			const std::string& p1, 
			const IndexRange& p2, 
			const IndexRange& p3);
	virtual void addForwardIndexTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3);
	virtual void clearSearchIndexTerm(
			const std::string& p1);
	virtual void clearSearchIndexStructures();
	virtual void clearForwardIndexTerm(
			const std::string& p1);
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
		,public StorageDumpConst
{
public:
	StorageDumpImpl( StorageDumpInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageDumpInterface>(obj_,ctx_){}
	StorageDumpImpl( const StorageDumpInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageDumpInterface>(obj_,ctx_){}

	virtual ~StorageDumpImpl();
	virtual bool nextChunk(
			const char*& chunk, std::size_t& p1);
};

class StorageImpl
		:public TraceObject<StorageInterface>
		,public StorageInterface
		,public StorageConst
{
public:
	StorageImpl( StorageInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageInterface>(obj_,ctx_){}
	StorageImpl( const StorageInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageInterface>(obj_,ctx_){}

	virtual ~StorageImpl();
	virtual StorageClientInterface* createClient(
			const std::string& p1, 
			const DatabaseInterface* p2, 
			const StatisticsProcessorInterface* p3) const;
	virtual bool createStorage(
			const std::string& p1, 
			const DatabaseInterface* p2) const;
	virtual const char* getConfigDescription() const;
	virtual const char** getConfigParameters() const;
};

class StorageMetaDataTableUpdateImpl
		:public TraceObject<StorageMetaDataTableUpdateInterface>
		,public StorageMetaDataTableUpdateInterface
		,public StorageMetaDataTableUpdateConst
{
public:
	StorageMetaDataTableUpdateImpl( StorageMetaDataTableUpdateInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageMetaDataTableUpdateInterface>(obj_,ctx_){}
	StorageMetaDataTableUpdateImpl( const StorageMetaDataTableUpdateInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageMetaDataTableUpdateInterface>(obj_,ctx_){}

	virtual ~StorageMetaDataTableUpdateImpl();
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
	virtual void deleteElements();
	virtual void clearElement(
			const std::string& p1);
	virtual bool done();
};

class StorageObjectBuilderImpl
		:public TraceObject<StorageObjectBuilderInterface>
		,public StorageObjectBuilderInterface
		,public StorageObjectBuilderConst
{
public:
	StorageObjectBuilderImpl( StorageObjectBuilderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageObjectBuilderInterface>(obj_,ctx_){}
	StorageObjectBuilderImpl( const StorageObjectBuilderInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageObjectBuilderInterface>(obj_,ctx_){}

	virtual ~StorageObjectBuilderImpl();
	virtual const StorageInterface* getStorage() const;
	virtual const DatabaseInterface* getDatabase(
			const std::string& p1) const;
	virtual const QueryProcessorInterface* getQueryProcessor() const;
	virtual const StatisticsProcessorInterface* getStatisticsProcessor(
			const std::string& p1) const;
	virtual const VectorStorageInterface* getVectorStorage(
			const std::string& p1) const;
	virtual QueryEvalInterface* createQueryEval() const;
};

class StorageTransactionImpl
		:public TraceObject<StorageTransactionInterface>
		,public StorageTransactionInterface
		,public StorageTransactionConst
{
public:
	StorageTransactionImpl( StorageTransactionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StorageTransactionInterface>(obj_,ctx_){}
	StorageTransactionImpl( const StorageTransactionInterface* obj_, TraceGlobalContext* ctx_)
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
	virtual void updateDocumentFrequency(
			const std::string& p1, 
			const std::string& p2, 
			int p3);
	virtual StorageMetaDataTableUpdateInterface* createMetaDataTableUpdate();
	virtual StorageCommitResult commit();
	virtual void rollback();
};

class StructureIteratorImpl
		:public TraceObject<StructureIteratorInterface>
		,public StructureIteratorInterface
		,public StructureIteratorConst
{
public:
	StructureIteratorImpl( StructureIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StructureIteratorInterface>(obj_,ctx_){}
	StructureIteratorImpl( const StructureIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<StructureIteratorInterface>(obj_,ctx_){}

	virtual ~StructureIteratorImpl();
	virtual void skipDoc(
			const Index& p1);
	virtual int levels() const;
	virtual Index docno() const;
	virtual IndexRange skipPos(
			int p1, 
			const Index& p2);
	virtual IndexRange field(
			int p1) const;
	virtual StructureLinkArray links(
			int p1) const;
	virtual StructureHeaderField headerField(
			int p1) const;
};

class SummarizerFunctionContextImpl
		:public TraceObject<SummarizerFunctionContextInterface>
		,public SummarizerFunctionContextInterface
		,public SummarizerFunctionContextConst
{
public:
	SummarizerFunctionContextImpl( SummarizerFunctionContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SummarizerFunctionContextInterface>(obj_,ctx_){}
	SummarizerFunctionContextImpl( const SummarizerFunctionContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SummarizerFunctionContextInterface>(obj_,ctx_){}

	virtual ~SummarizerFunctionContextImpl();
	virtual void addSummarizationFeature(
			const std::string& p1, 
			PostingIteratorInterface* p2, 
			const std::vector<SummarizationVariable>&  p3, 
			double p4);
	virtual void setVariableValue(
			const std::string& p1, 
			double p2);
	virtual std::vector<SummaryElement> getSummary(
			const WeightedDocument& p1);
};

class SummarizerFunctionInstanceImpl
		:public TraceObject<SummarizerFunctionInstanceInterface>
		,public SummarizerFunctionInstanceInterface
		,public SummarizerFunctionInstanceConst
{
public:
	SummarizerFunctionInstanceImpl( SummarizerFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SummarizerFunctionInstanceInterface>(obj_,ctx_){}
	SummarizerFunctionInstanceImpl( const SummarizerFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SummarizerFunctionInstanceInterface>(obj_,ctx_){}

	virtual ~SummarizerFunctionInstanceImpl();
	virtual void addStringParameter(
			const std::string& p1, 
			const std::string& p2);
	virtual void addNumericParameter(
			const std::string& p1, 
			const NumericVariant& p2);
	virtual std::vector<std::string> getVariables() const;
	virtual SummarizerFunctionContextInterface* createFunctionContext(
			const StorageClientInterface* p1, 
			const GlobalStatistics& p2) const;
	virtual bool doPopulate() const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class SummarizerFunctionImpl
		:public TraceObject<SummarizerFunctionInterface>
		,public SummarizerFunctionInterface
		,public SummarizerFunctionConst
{
public:
	SummarizerFunctionImpl( SummarizerFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SummarizerFunctionInterface>(obj_,ctx_){}
	SummarizerFunctionImpl( const SummarizerFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<SummarizerFunctionInterface>(obj_,ctx_){}

	virtual ~SummarizerFunctionImpl();
	virtual SummarizerFunctionInstanceInterface* createInstance(
			const QueryProcessorInterface* p1) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class TextProcessorImpl
		:public TraceObject<TextProcessorInterface>
		,public TextProcessorInterface
		,public TextProcessorConst
{
public:
	TextProcessorImpl( TextProcessorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TextProcessorInterface>(obj_,ctx_){}
	TextProcessorImpl( const TextProcessorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TextProcessorInterface>(obj_,ctx_){}

	virtual ~TextProcessorImpl();
	virtual std::string getResourceFilePath(
			const std::string& p1) const;
	virtual const SegmenterInterface* getSegmenterByName(
			const std::string& p1) const;
	virtual const SegmenterInterface* getSegmenterByMimeType(
			const std::string& p1) const;
	virtual analyzer::SegmenterOptions getSegmenterOptions(
			const std::string& p1) const;
	virtual const TokenizerFunctionInterface* getTokenizer(
			const std::string& p1) const;
	virtual const NormalizerFunctionInterface* getNormalizer(
			const std::string& p1) const;
	virtual const AggregatorFunctionInterface* getAggregator(
			const std::string& p1) const;
	virtual const PatternLexerInterface* getPatternLexer(
			const std::string& p1) const;
	virtual const PatternMatcherInterface* getPatternMatcher(
			const std::string& p1) const;
	virtual const PatternTermFeederInterface* getPatternTermFeeder() const;
	virtual PosTaggerDataInterface* createPosTaggerData(
			TokenizerFunctionInstanceInterface* p1) const;
	virtual const PosTaggerInterface* getPosTagger() const;
	virtual TokenMarkupInstanceInterface* createTokenMarkupInstance() const;
	virtual bool detectDocumentClass(
			analyzer::DocumentClass& p1, 
			const char* contentBegin, std::size_t p2, 
			bool p3) const;
	virtual void defineDocumentClassDetector(
			DocumentClassDetectorInterface* p1);
	virtual void defineSegmenter(
			const std::string& p1, 
			SegmenterInterface* p2);
	virtual void defineSegmenterOptions(
			const std::string& p1, 
			const analyzer::SegmenterOptions& p2);
	virtual void defineTokenizer(
			const std::string& p1, 
			TokenizerFunctionInterface* p2);
	virtual void defineNormalizer(
			const std::string& p1, 
			NormalizerFunctionInterface* p2);
	virtual void defineAggregator(
			const std::string& p1, 
			AggregatorFunctionInterface* p2);
	virtual void definePatternLexer(
			const std::string& p1, 
			PatternLexerInterface* p2);
	virtual void definePatternMatcher(
			const std::string& p1, 
			PatternMatcherInterface* p2);
	virtual std::vector<std::string> getFunctionList(
			const FunctionType& p1) const;
};

class TokenizerFunctionInstanceImpl
		:public TraceObject<TokenizerFunctionInstanceInterface>
		,public TokenizerFunctionInstanceInterface
		,public TokenizerFunctionInstanceConst
{
public:
	TokenizerFunctionInstanceImpl( TokenizerFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TokenizerFunctionInstanceInterface>(obj_,ctx_){}
	TokenizerFunctionInstanceImpl( const TokenizerFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TokenizerFunctionInstanceInterface>(obj_,ctx_){}

	virtual ~TokenizerFunctionInstanceImpl();
	virtual bool concatBeforeTokenize() const;
	virtual std::vector<analyzer::Token> tokenize(
			const char* src, std::size_t p1) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class TokenizerFunctionImpl
		:public TraceObject<TokenizerFunctionInterface>
		,public TokenizerFunctionInterface
		,public TokenizerFunctionConst
{
public:
	TokenizerFunctionImpl( TokenizerFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TokenizerFunctionInterface>(obj_,ctx_){}
	TokenizerFunctionImpl( const TokenizerFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TokenizerFunctionInterface>(obj_,ctx_){}

	virtual ~TokenizerFunctionImpl();
	virtual TokenizerFunctionInstanceInterface* createInstance(
			const std::vector<std::string>& p1, 
			const TextProcessorInterface* p2) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class TokenMarkupContextImpl
		:public TraceObject<TokenMarkupContextInterface>
		,public TokenMarkupContextInterface
		,public TokenMarkupContextConst
{
public:
	TokenMarkupContextImpl( TokenMarkupContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TokenMarkupContextInterface>(obj_,ctx_){}
	TokenMarkupContextImpl( const TokenMarkupContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TokenMarkupContextInterface>(obj_,ctx_){}

	virtual ~TokenMarkupContextImpl();
	virtual void putMarkup(
			const analyzer::Position& p1, 
			const analyzer::Position& p2, 
			const analyzer::TokenMarkup& p3, 
			unsigned int p4);
	virtual std::string markupDocument(
			const analyzer::DocumentClass& p1, 
			const std::string& p2) const;
};

class TokenMarkupInstanceImpl
		:public TraceObject<TokenMarkupInstanceInterface>
		,public TokenMarkupInstanceInterface
		,public TokenMarkupInstanceConst
{
public:
	TokenMarkupInstanceImpl( TokenMarkupInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TokenMarkupInstanceInterface>(obj_,ctx_){}
	TokenMarkupInstanceImpl( const TokenMarkupInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<TokenMarkupInstanceInterface>(obj_,ctx_){}

	virtual ~TokenMarkupInstanceImpl();
	virtual TokenMarkupContextInterface* createContext(
			const SegmenterInstanceInterface* p1) const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class ValueIteratorImpl
		:public TraceObject<ValueIteratorInterface>
		,public ValueIteratorInterface
		,public ValueIteratorConst
{
public:
	ValueIteratorImpl( ValueIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ValueIteratorInterface>(obj_,ctx_){}
	ValueIteratorImpl( const ValueIteratorInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<ValueIteratorInterface>(obj_,ctx_){}

	virtual ~ValueIteratorImpl();
	virtual void skip(
			const char* value, std::size_t p1);
	virtual void skipPrefix(
			const char* value, std::size_t p1);
	virtual std::vector<std::string> fetchValues(
			std::size_t p1);
};

class VectorStorageClientImpl
		:public TraceObject<VectorStorageClientInterface>
		,public VectorStorageClientInterface
		,public VectorStorageClientConst
{
public:
	VectorStorageClientImpl( VectorStorageClientInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<VectorStorageClientInterface>(obj_,ctx_){}
	VectorStorageClientImpl( const VectorStorageClientInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<VectorStorageClientInterface>(obj_,ctx_){}

	virtual ~VectorStorageClientImpl();
	virtual void prepareSearch(
			const std::string& p1) const;
	virtual std::vector<VectorQueryResult> findSimilar(
			const std::string& p1, 
			const WordVector& p2, 
			int p3, 
			double p4, 
			double p5, 
			bool p6) const;
	virtual VectorStorageTransactionInterface* createTransaction();
	virtual std::vector<std::string> types() const;
	virtual ValueIteratorInterface* createFeatureValueIterator() const;
	virtual std::vector<std::string> featureTypes(
			const std::string& p1) const;
	virtual int nofTypes() const;
	virtual int nofFeatures() const;
	virtual int nofVectors(
			const std::string& p1) const;
	virtual WordVector featureVector(
			const std::string& p1, 
			const std::string& p2) const;
	virtual double vectorSimilarity(
			const WordVector& p1, 
			const WordVector& p2) const;
	virtual WordVector normalize(
			const WordVector& p1) const;
	virtual SentenceLexerInstanceInterface* createSentenceLexer() const;
	virtual std::string config() const;
	virtual void close();
	virtual void compaction();
};

class VectorStorageDumpImpl
		:public TraceObject<VectorStorageDumpInterface>
		,public VectorStorageDumpInterface
		,public VectorStorageDumpConst
{
public:
	VectorStorageDumpImpl( VectorStorageDumpInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<VectorStorageDumpInterface>(obj_,ctx_){}
	VectorStorageDumpImpl( const VectorStorageDumpInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<VectorStorageDumpInterface>(obj_,ctx_){}

	virtual ~VectorStorageDumpImpl();
	virtual bool nextChunk(
			const char*& chunk, std::size_t& p1);
};

class VectorStorageImpl
		:public TraceObject<VectorStorageInterface>
		,public VectorStorageInterface
		,public VectorStorageConst
{
public:
	VectorStorageImpl( VectorStorageInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<VectorStorageInterface>(obj_,ctx_){}
	VectorStorageImpl( const VectorStorageInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<VectorStorageInterface>(obj_,ctx_){}

	virtual ~VectorStorageImpl();
	virtual bool createStorage(
			const std::string& p1, 
			const DatabaseInterface* p2) const;
	virtual VectorStorageClientInterface* createClient(
			const std::string& p1, 
			const DatabaseInterface* p2) const;
	virtual VectorStorageDumpInterface* createDump(
			const std::string& p1, 
			const DatabaseInterface* p2) const;
	virtual const char* getConfigDescription() const;
	virtual const char** getConfigParameters() const;
};

class VectorStorageTransactionImpl
		:public TraceObject<VectorStorageTransactionInterface>
		,public VectorStorageTransactionInterface
		,public VectorStorageTransactionConst
{
public:
	VectorStorageTransactionImpl( VectorStorageTransactionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<VectorStorageTransactionInterface>(obj_,ctx_){}
	VectorStorageTransactionImpl( const VectorStorageTransactionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<VectorStorageTransactionInterface>(obj_,ctx_){}

	virtual ~VectorStorageTransactionImpl();
	virtual void defineVector(
			const std::string& p1, 
			const std::string& p2, 
			const WordVector& p3);
	virtual void defineFeatureType(
			const std::string& p1);
	virtual void defineFeature(
			const std::string& p1, 
			const std::string& p2);
	virtual void clear();
	virtual bool commit();
	virtual void rollback();
};

class WeightingFunctionContextImpl
		:public TraceObject<WeightingFunctionContextInterface>
		,public WeightingFunctionContextInterface
		,public WeightingFunctionContextConst
{
public:
	WeightingFunctionContextImpl( WeightingFunctionContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<WeightingFunctionContextInterface>(obj_,ctx_){}
	WeightingFunctionContextImpl( const WeightingFunctionContextInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<WeightingFunctionContextInterface>(obj_,ctx_){}

	virtual ~WeightingFunctionContextImpl();
	virtual void addWeightingFeature(
			const std::string& p1, 
			PostingIteratorInterface* p2, 
			double p3);
	virtual void setVariableValue(
			const std::string& p1, 
			double p2);
	virtual const std::vector<WeightedField>& call(
			const Index& p1);
};

class WeightingFunctionInstanceImpl
		:public TraceObject<WeightingFunctionInstanceInterface>
		,public WeightingFunctionInstanceInterface
		,public WeightingFunctionInstanceConst
{
public:
	WeightingFunctionInstanceImpl( WeightingFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<WeightingFunctionInstanceInterface>(obj_,ctx_){}
	WeightingFunctionInstanceImpl( const WeightingFunctionInstanceInterface* obj_, TraceGlobalContext* ctx_)
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
			const GlobalStatistics& p2) const;
	virtual std::vector<std::string> getVariables() const;
	virtual const char* name() const;
	virtual StructView view() const;
};

class WeightingFunctionImpl
		:public TraceObject<WeightingFunctionInterface>
		,public WeightingFunctionInterface
		,public WeightingFunctionConst
{
public:
	WeightingFunctionImpl( WeightingFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<WeightingFunctionInterface>(obj_,ctx_){}
	WeightingFunctionImpl( const WeightingFunctionInterface* obj_, TraceGlobalContext* ctx_)
		:TraceObject<WeightingFunctionInterface>(obj_,ctx_){}

	virtual ~WeightingFunctionImpl();
	virtual WeightingFunctionInstanceInterface* createInstance(
			const QueryProcessorInterface* p1) const;
	virtual const char* name() const;
	virtual StructView view() const;
};


}}//namespace
#endif

