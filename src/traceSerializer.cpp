/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of serialization methods of more complec objects
/// \file traceSerializer.cpp
#include "traceSerializer.hpp"
#include "traceObject.hpp"
#include "internationalization.hpp"
#include "errorUtils.hpp"
#include "serialize.hpp"
#include "objectIds_gen.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/traceLoggerInterface.hpp"
#include <cstring>

using namespace strus;
#undef STRUS_LOWLEVEL_DEBUG

#define DEFINE_PACK_CALL_NOARG( FUNC)\
void TraceSerializer::FUNC()\
{\
	try {\
		Serializer::FUNC();\
	}\
	catch (const std::bad_alloc&)\
	{\
		m_error=true;\
	}\
}
#define DEFINE_PACK_CALL( FUNC, TYPE)\
void TraceSerializer::FUNC( const TYPE& value)\
{\
	try {\
		Serializer::FUNC( value);\
	}\
	catch (const std::bad_alloc&)\
	{\
		m_error=true;\
	}\
}
#define DEFINE_PACK_CALL_PTR( FUNC, TYPE)\
void TraceSerializer::FUNC( const TYPE value)\
{\
	try {\
		Serializer::FUNC( value);\
	}\
	catch (const std::bad_alloc&)\
	{\
		m_error=true;\
	}\
}
DEFINE_PACK_CALL_NOARG( packVoid)
DEFINE_PACK_CALL( packScalar, int8_t)
DEFINE_PACK_CALL( packScalar, int16_t)
DEFINE_PACK_CALL( packScalar, int32_t)
DEFINE_PACK_CALL( packScalar, int64_t)
DEFINE_PACK_CALL( packScalar, uint8_t)
DEFINE_PACK_CALL( packScalar, uint16_t)
DEFINE_PACK_CALL( packScalar, uint32_t)
DEFINE_PACK_CALL( packScalar, uint64_t)
DEFINE_PACK_CALL( packScalar, float)
DEFINE_PACK_CALL( packScalar, double)
DEFINE_PACK_CALL( packBool, bool)
DEFINE_PACK_CALL( packString, std::string)
DEFINE_PACK_CALL_PTR( packCharp, char*)
DEFINE_PACK_CALL_PTR( packCharpp, char**)
DEFINE_PACK_CALL( openIndex, std::size_t)
DEFINE_PACK_CALL( openTag, std::string)
DEFINE_PACK_CALL_NOARG( close)

#define CATCH_ERROR catch (const std::bad_alloc&){m_error=true;}


void TraceSerializer::packObject( const TraceClassId& classId, const TraceObjectId& objId)
{
	try{
#ifdef STRUS_LOWLEVEL_DEBUG
	std::cerr << "packObject (" << (unsigned int)classId_ << ", " << objId_ << ")" << std::endl;
#endif
	if (objId > std::numeric_limits<uint32_t>::max()) throw strus::runtime_error( _TXT("object id out of range"));
	packScalar( classId);
	packScalar( objId);
	}CATCH_ERROR
}

void TraceSerializer::packBuffer( const char* buf, std::size_t size)
{
	try{
#ifdef STRUS_LOWLEVEL_DEBUG
	std::cerr << "packBuffer('" << std::string(buf,size) << "')" << std::endl;
#endif
	Serializer::packBuffer( buf, size);
	}CATCH_ERROR
}

void TraceSerializer::packBufferFloat( const double* buf, std::size_t size)
{
	try{
#ifdef STRUS_LOWLEVEL_DEBUG
	std::cerr << "packBufferFloat(...)" << std::endl;
#endif
	std::size_t ii=0;
	for (ii=0; ii<size; ++ii)
	{
		Serializer::openIndex( ii);
		Serializer::packScalar( buf[ii]);
		Serializer::close();
	}
	}CATCH_ERROR
}

void TraceSerializer::packStringVector( const std::vector<std::string>& ar)
{
	try{
#ifdef STRUS_LOWLEVEL_DEBUG
	std::cerr << "packStringVector(...)" << std::endl;
#endif
	std::vector<std::string>::const_iterator ai = ar.begin(), ae = ar.end();
	for (std::size_t aidx=0; ai != ae; ++ai,++aidx)
	{
		Serializer::openIndex( aidx);
		Serializer::packString( *ai);
		Serializer::close();
	}
	}CATCH_ERROR
}

void TraceSerializer::packIndexVector( const std::vector<Index>& ar)
{
	try{
#ifdef STRUS_LOWLEVEL_DEBUG
	std::cerr << "packIndexVector(...)" << std::endl;
#endif
	std::vector<Index>::const_iterator ai = ar.begin(), ae = ar.end();
	for (std::size_t aidx=0; ai != ae; ++ai,++aidx)
	{
		Serializer::openIndex( aidx);
		Serializer::packScalar( *ai);
		Serializer::close();
	}
	}CATCH_ERROR
}

void TraceSerializer::packNumericVariant( const NumericVariant& val)
{
	try{
	switch (val.type)
	{
		case NumericVariant::Null: Serializer::packVoid();
		case NumericVariant::Int: Serializer::packScalar( val.variant.Int); break;
		case NumericVariant::UInt: Serializer::packScalar( val.variant.UInt); break;
		case NumericVariant::Float: Serializer::packScalar( val.variant.Float); break;
	}
	}CATCH_ERROR
}

void TraceSerializer::packDocumentClass( const DocumentClass& dclass)
{
	try{
	Serializer::packString( dclass.mimeType());
	Serializer::packString( dclass.scheme());
	Serializer::packString( dclass.encoding());
	}CATCH_ERROR
}

void TraceSerializer::packTermStatistics( const TermStatistics& stats)
{
	try{
	Serializer::packScalar( stats.documentFrequency());
	}CATCH_ERROR
}

void TraceSerializer::packGlobalStatistics( const GlobalStatistics& stats)
{
	try{
	Serializer::packScalar( stats.nofDocumentsInserted());
	}CATCH_ERROR
}

static const char* compareOperatorName( MetaDataRestrictionInterface::CompareOperator op)
{
	static const char* ar[] = {"<", "<=", "==", "!=", ">", ">="};
	return ar[op];
}

void TraceSerializer::packMetaDataRestrictionCompareOperator( MetaDataRestrictionInterface::CompareOperator val)
{
	try{
	Serializer::packCharp( compareOperatorName( val));
	}CATCH_ERROR
}

void TraceSerializer::packDatabaseOptions( const DatabaseOptions& val)
{
	try{
	Serializer::packScalar( val.opt());
	}CATCH_ERROR
}

static const char* databaseConfigTypeName( DatabaseInterface::ConfigType tp)
{
	static const char* ar[] = {"CreateClient", "CmdCreate", "CmdDestroy"};
	return ar[ tp];
}

void TraceSerializer::packDatabaseConfigType( const DatabaseInterface::ConfigType& val)
{
	try{
	Serializer::packCharp( databaseConfigTypeName(val));
	}CATCH_ERROR
}

static const char* storageConfigTypeName( StorageInterface::ConfigType tp)
{
	static const char* ar[] = {"CreateClient", "CmdCreate"};
	return ar[ tp];
}

void TraceSerializer::packStorageConfigType( const StorageInterface::ConfigType& val)
{
	try{
	Serializer::packCharp( storageConfigTypeName(val));
	}CATCH_ERROR
}

void TraceSerializer::packFeatureOptions( const DocumentAnalyzerInterface::FeatureOptions& val)
{
	try{
	Serializer::packScalar( val.opt());
	}CATCH_ERROR
}

void TraceSerializer::packSummaryElement( const SummaryElement& val)
{
	try{
	Serializer::openTag( "name");
	Serializer::packString( val.name());
	Serializer::close();
	Serializer::openTag( "value");
	Serializer::packString( val.value());
	Serializer::close();
	Serializer::openTag( "weight");
	Serializer::packScalar( val.weight());
	Serializer::close();
	Serializer::openTag( "index");
	Serializer::packScalar( val.index());
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packSummaryElementVector( const std::vector<SummaryElement>& ar)
{
	try{
#ifdef STRUS_LOWLEVEL_DEBUG
	std::cerr << "packSummaryElementVector(...)" << std::endl;
#endif
	std::vector<SummaryElement>::const_iterator si = ar.begin(), se = ar.end();
	for (std::size_t sidx=0; si != se; ++si,++sidx)
	{
		Serializer::openIndex( sidx);
		packSummaryElement( *si);
		Serializer::close();
	}
	}CATCH_ERROR
}

void TraceSerializer::packSummarizationVariable( const SummarizationVariable& val)
{
	try{
	Serializer::openTag( "name");
	Serializer::packString( val.name());
	Serializer::close();
	Serializer::openTag( "itr");
	const TraceObjectBase* so = dynamic_cast<const TraceObjectBase*>( val.itr());
	if (!so) throw strus::runtime_error( _TXT("passing non trace interface object in trace call (summarization variable)"));
	packObject( (TraceClassId) ClassId_PostingIterator, so->objid());
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packSummarizationVariableVector( const std::vector<SummarizationVariable>& ar)
{
	try{
#ifdef STRUS_LOWLEVEL_DEBUG
	std::cerr << "packSummarizationVariableVector(...)" << std::endl;
#endif
	std::vector<SummarizationVariable>::const_iterator vi = ar.begin(), ve = ar.end();
	for (std::size_t vidx=0; vi != ve; ++vi,++vidx)
	{
		Serializer::openIndex( vidx);
		packSummarizationVariable( *vi);
		Serializer::close();
	}
	}CATCH_ERROR
}

void TraceSerializer::packDocumentTermIteratorTerm( const DocumentTermIteratorInterface::Term& val)
{
	try{
	Serializer::openTag( "tf");
	Serializer::packScalar( (Index)val.tf);
	Serializer::close();
	Serializer::openTag( "firstpos");
	Serializer::packScalar( (Index)val.firstpos);
	Serializer::close();
	Serializer::openTag( "termno");
	Serializer::packScalar( val.termno);
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packSlice( DatabaseCursorInterface::Slice& val)
{
	try{
	Serializer::packBuffer( val.ptr(), val.size());
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerDocument( const analyzer::Document& val)
{
	try{
	if (val.subDocumentTypeName().size())
	{
		Serializer::openTag("doc");
		Serializer::packString( val.subDocumentTypeName());
		Serializer::close();
	}
	std::vector<analyzer::Attribute>::const_iterator ai = val.attributes().begin(), ae = val.attributes().end();
	if (ai != ae)
	{
		Serializer::openTag("attributes");
		for (; ai != ae; ++ai)
		{
			Serializer::openIndex( ai-val.attributes().begin());
			packAnalyzerAttribute( *ai);
			Serializer::close();
		}
		Serializer::close();
	}
	std::vector<analyzer::MetaData>::const_iterator mi = val.metadata().begin(), me = val.metadata().end();
	if (mi != me)
	{
		Serializer::openTag("metadata");
		for (; mi != me; ++mi)
		{
			Serializer::openIndex( mi-val.metadata().begin());
			packAnalyzerMetaData( *mi);
			Serializer::close();
		}
		Serializer::close();
	}
	std::vector<analyzer::Term>::const_iterator si = val.searchIndexTerms().begin(), se = val.searchIndexTerms().end();
	if (si != se)
	{
		Serializer::openTag("searchindex");
		for (; si != se; ++si)
		{
			Serializer::openIndex( si-val.searchIndexTerms().begin());
			packAnalyzerTerm( *si);
			Serializer::close();
		}
		Serializer::close();
	}
	std::vector<analyzer::Term>::const_iterator fi = val.forwardIndexTerms().begin(), fe = val.forwardIndexTerms().end();
	if (fi != fe)
	{
		Serializer::openTag("forwardindex");
		for (; fi != fe; ++fi)
		{
			Serializer::openIndex( fi-val.forwardIndexTerms().begin());
			packAnalyzerTerm( *fi);
			Serializer::close();
		}
		Serializer::close();
	}
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerAttribute( const analyzer::Attribute& val)
{
	try{
	Serializer::openTag("name");
	Serializer::packString( val.name());
	Serializer::close();
	Serializer::openTag("value");
	Serializer::packString( val.value());
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerMetaData( const analyzer::MetaData& val)
{
	try{
	Serializer::openTag("name");
	Serializer::packString( val.name());
	Serializer::close();
	Serializer::openTag("value");
	Serializer::packScalar( val.value());
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerTerm( const analyzer::Term& val)
{
	try{
	Serializer::openTag("type");
	Serializer::packString( val.type());
	Serializer::close();
	Serializer::openTag("value");
	Serializer::packString( val.value());
	Serializer::close();
	Serializer::openTag("pos");
	Serializer::packScalar( val.pos());
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerTermVector( const analyzer::TermVector& val)
{
	try{
	analyzer::TermVector::const_iterator ti = val.begin(), te = val.end();
	for (; ti != te; ++ti)
	{
		Serializer::openIndex( ti-val.begin());
		packAnalyzerTerm( *ti);
		Serializer::close();
	}
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerToken( const analyzer::Token& val)
{
	try{
	Serializer::openTag("docpos");
	Serializer::packScalar( val.docpos);
	Serializer::close();
	Serializer::openTag("strpos");
	Serializer::packScalar( val.strpos);
	Serializer::close();
	Serializer::openTag("strsize");
	Serializer::packScalar( val.strsize);
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packWeightedDocument( const WeightedDocument& val)
{
	try{
	Serializer::openTag("docno");
	Serializer::packScalar( val.docno());
	Serializer::close();
	Serializer::openTag("weight");
	Serializer::packScalar( val.weight());
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packResultDocument( const ResultDocument& val)
{
	try{
	packWeightedDocument( val);
	Serializer::openTag("summary");
	std::vector<SummaryElement>::const_iterator
		ai = val.summaryElements().begin(), ae = val.summaryElements().end();
	for (; ai != ae; ++ai)
	{
		Serializer::openIndex( ai-val.summaryElements().begin());
		packSummaryElement( *ai);
		Serializer::close();
	}
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packQueryResult( const QueryResult& val)
{
	try{
	Serializer::openTag("pass");
	Serializer::packScalar( val.evaluationPass());
	Serializer::close();
	Serializer::openTag("nofranked");
	Serializer::packScalar( val.nofDocumentsRanked());
	Serializer::close();
	Serializer::openTag("nofvisited");
	Serializer::packScalar( val.nofDocumentsVisited());
	Serializer::close();

	std::vector<ResultDocument>::const_iterator
		ri = val.ranks().begin(), re = val.ranks().end();
	Serializer::openTag("ranks");
	for (; ri != re; ++ri)
	{
		Serializer::openIndex( ri-val.ranks().begin());
		packResultDocument( *ri);
		Serializer::close();
	}
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packFeatureParameter( const QueryEvalInterface::FeatureParameter& val)
{
	try{
	Serializer::openTag("name");
	Serializer::packString( val.parameterName());
	Serializer::close();
	Serializer::openTag("featset");
	Serializer::packString( val.featureSet());
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packFeatureParameterVector( const std::vector<QueryEvalInterface::FeatureParameter>& ar)
{
	try{
#ifdef STRUS_LOWLEVEL_DEBUG
	std::cerr << "packFeatureParameterVector(...)" << std::endl;
#endif
	std::vector<QueryEvalInterface::FeatureParameter>::const_iterator ai = ar.begin(), ae = ar.end();
	for (std::size_t aidx=0; ai != ae; ++ai,++aidx)
	{
		Serializer::openIndex( aidx);
		packFeatureParameter( *ai);
		Serializer::close();
	}
	}CATCH_ERROR
}

void TraceSerializer::packPhrase( const QueryAnalyzerInterface::Phrase& val)
{
	try{
	Serializer::openTag("type");
	Serializer::packString( val.type());
	Serializer::close();
	Serializer::openTag("content");
	Serializer::packString( val.content());
	Serializer::close();
	}CATCH_ERROR
}

static const char* documentStatisticsTypeName( const StorageClientInterface::DocumentStatisticsType& val)
{
	static const char* ar[] = {"NofTerms", "NofTermOccurrencies"};
	return ar[val];
}

void TraceSerializer::packDocumentStatisticsType( const StorageClientInterface::DocumentStatisticsType& val)
{
	try{
	Serializer::packCharp( documentStatisticsTypeName( val));
	}CATCH_ERROR
}

void TraceSerializer::packStatisticsProcessorBuilderOptions( const StatisticsProcessorInterface::BuilderOptions& val)
{
	try{
	Serializer::openTag("blksize");
	Serializer::packScalar( val.maxBlockSize);
	Serializer::close();
	Serializer::openTag("options");
	Serializer::packScalar( val.set);
	Serializer::close();
	}CATCH_ERROR
}

void TraceSerializer::packStatisticsViewerDocumentFrequencyChange( const StatisticsViewerInterface::DocumentFrequencyChange& val)
{
	try{
	Serializer::openTag("type");
	Serializer::packCharp( val.type);
	Serializer::close();
	Serializer::openTag("value");
	Serializer::packCharp( val.value);
	Serializer::close();
	Serializer::openTag("incr");
	Serializer::packScalar( val.increment);
	Serializer::close();
	}CATCH_ERROR
}

const char* queryProcessorFunctionTypeName( const QueryProcessorInterface::FunctionType& val)
{
	static const char* ar[] = {"PostingJoinOperator", "WeightingFunction","SummarizerFunction"};
	return ar[val];
}

void TraceSerializer::packQueryProcessorFunctionType( const QueryProcessorInterface::FunctionType& val)
{
	try{
	Serializer::packCharp( queryProcessorFunctionTypeName(val));
	}CATCH_ERROR
}

const char* textProcessorFunctionTypeName( const TextProcessorInterface::FunctionType& val)
{
	static const char* ar[] = {"Tokenizer", "Normalizer","Aggregator"};
	return ar[val];
}

void TraceSerializer::packTextProcessorFunctionType( const TextProcessorInterface::FunctionType& val)
{
	try{
	Serializer::packCharp( textProcessorFunctionTypeName( val));
	}CATCH_ERROR
}

void TraceSerializer::packPostingJoinOperatorDescription( const PostingJoinOperatorInterface::Description& val)
{
	try{
	Serializer::packString( val.text());
	}CATCH_ERROR
}

static const char* functionDescriptionTypeName( const FunctionDescription::Parameter::Type& val)
{
	static const char* ar[] = {"Feature", "Attribute","Metadata","Numeric","String"};
	return ar[val];
}

void TraceSerializer::packFunctionDescription( const FunctionDescription& val)
{
	try{
	Serializer::openTag("text");
	Serializer::packString( val.text());
	Serializer::close();
	Serializer::openTag("size");
	Serializer::packScalar( val.parameter().size());
	Serializer::close();
	Serializer::openTag("param");
	std::vector<FunctionDescription::Parameter>::const_iterator vi = val.parameter().begin(), ve = val.parameter().end();
	for (; vi != ve; ++vi)
	{
		Serializer::openIndex( vi-val.parameter().begin());
		Serializer::openTag("type");
		Serializer::packCharp( functionDescriptionTypeName( vi->type()));
		Serializer::close();
		Serializer::openTag("name");
		Serializer::packString( vi->name());
		Serializer::close();
		Serializer::openTag("text");
		Serializer::packString( vi->text());
		Serializer::close();
		Serializer::openTag("domain");
		Serializer::packString( vi->domain());
		Serializer::close();
		Serializer::close();
	}
	Serializer::close();
	}CATCH_ERROR
}

