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
#include "enumIdentifiers.hpp"
#include "objectIds_gen.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/traceLoggerInterface.hpp"
#include <cstring>

using namespace strus;
#undef STRUS_LOWLEVEL_DEBUG

void TraceSerializer::packObject( const TraceClassId& classId, const TraceObjectId& objId)
{
#ifdef STRUS_LOWLEVEL_DEBUG
	std::cerr << "packObject (" << (unsigned int)classId_ << ", " << objId_ << ")" << std::endl;
#endif
	if (objId > std::numeric_limits<uint32_t>::max()) throw strus::runtime_error( _TXT("object id out of range"));
	packScalar( classId);
	packScalar( objId);
}

void TraceSerializer::packBuffer( const char* buf, std::size_t size)
{
#ifdef STRUS_LOWLEVEL_DEBUG
	std::cerr << "packBuffer('" << std::string(buf,size) << "')" << std::endl;
#endif
	packString( std::string( buf, size));
}

void TraceSerializer::packBufferFloat( const double* buf, std::size_t size)
{
#ifdef STRUS_LOWLEVEL_DEBUG
	std::cerr << "packBuffer('" << std::string(buf,size) << "')" << std::endl;
#endif
	std::size_t ii=0;
	for (ii=0; ii<size; ++ii)
	{
		openIndex( ii);
		packScalar( buf[ii]);
		close();
	}
}

void TraceSerializer::packNumericVariant( const NumericVariant& val)
{
	switch (val.type)
	{
		case NumericVariant::Null: packVoid();
		case NumericVariant::Int: packScalar( val.variant.Int); break;
		case NumericVariant::UInt: packScalar( val.variant.UInt); break;
		case NumericVariant::Float: packScalar( val.variant.Float); break;
	}
}

void TraceSerializer::packDocumentClass( const DocumentClass& dclass)
{
	packString( dclass.mimeType());
	packString( dclass.scheme());
	packString( dclass.encoding());
}

void TraceSerializer::packTermStatistics( const TermStatistics& stats)
{
	packScalar( stats.documentFrequency());
}

void TraceSerializer::packGlobalStatistics( const GlobalStatistics& stats)
{
	packScalar( stats.nofDocumentsInserted());
}

void TraceSerializer::packMetaDataRestrictionCompareOperator( MetaDataRestrictionInterface::CompareOperator val)
{
	packEnum( (TraceEnumTypeId)MetaDataRestriction_CompareOperator, (TraceEnumValueId)val);
}

void TraceSerializer::packDatabaseOptions( const DatabaseOptions& val)
{
	packScalar( val.opt());
}

void TraceSerializer::packDatabaseConfigType( const DatabaseInterface::ConfigType& val)
{
	packEnum( (TraceEnumTypeId)Database_ConfigType, (TraceEnumValueId)val);
}

void TraceSerializer::packStorageConfigType( const StorageInterface::ConfigType& val)
{
	packEnum( (TraceEnumTypeId)Storage_ConfigType, (TraceEnumValueId)val);
}

void TraceSerializer::packFeatureOptions( const DocumentAnalyzerInterface::FeatureOptions& val)
{
	packScalar( val.opt());
}

void TraceSerializer::packSummaryElement( const SummaryElement& val)
{
	openTag( "name");
	packString( val.name());
	close();
	openTag( "value");
	packString( val.value());
	close();
	openTag( "weight");
	packScalar( val.weight());
	close();
	openTag( "index");
	packScalar( val.index());
	close();
}

void TraceSerializer::packSummarizationVariable( const SummarizationVariable& val)
{
	openTag( "name");
	packString( val.name());
	close();
	openTag( "itr");
	const TraceObjectBase* so = dynamic_cast<const TraceObjectBase*>( val.itr());
	if (!so) throw strus::runtime_error( _TXT("passing non trace interface object in trace call (summarization variable)"));
	packObject( (TraceClassId) ClassId_PostingIterator, so->id());
	close();
}

void TraceSerializer::packDocumentTermIteratorTerm( const DocumentTermIteratorInterface::Term& val)
{
	openTag( "tf");
	packScalar( (Index)val.tf);
	close();
	openTag( "firstpos");
	packScalar( (Index)val.firstpos);
	close();
	openTag( "termno");
	packScalar( val.termno);
	close();
}

void TraceSerializer::packSlice( DatabaseCursorInterface::Slice& val)
{
	packBuffer( val.ptr(), val.size());
}

void TraceSerializer::packAnalyzerDocument( const analyzer::Document& val)
{
	if (val.subDocumentTypeName().size())
	{
		openTag("doc");
		packString( val.subDocumentTypeName());
		close();
	}
	std::vector<analyzer::Attribute>::const_iterator ai = val.attributes().begin(), ae = val.attributes().end();
	if (ai != ae)
	{
		openTag("attributes");
		for (; ai != ae; ++ai)
		{
			openIndex( ai-val.attributes().begin());
			packAnalyzerAttribute( *ai);
			close();
		}
		close();
	}
	std::vector<analyzer::MetaData>::const_iterator mi = val.metadata().begin(), me = val.metadata().end();
	if (mi != me)
	{
		openTag("metadata");
		for (; mi != me; ++mi)
		{
			openIndex( mi-val.metadata().begin());
			packAnalyzerMetaData( *mi);
			close();
		}
		close();
	}
	std::vector<analyzer::Term>::const_iterator si = val.searchIndexTerms().begin(), se = val.searchIndexTerms().end();
	if (si != se)
	{
		openTag("searchindex");
		for (; si != se; ++si)
		{
			openIndex( si-val.searchIndexTerms().begin());
			packAnalyzerTerm( *si);
			close();
		}
		close();
	}
	std::vector<analyzer::Term>::const_iterator fi = val.forwardIndexTerms().begin(), fe = val.forwardIndexTerms().end();
	if (fi != fe)
	{
		openTag("forwardindex");
		for (; fi != fe; ++fi)
		{
			openIndex( fi-val.forwardIndexTerms().begin());
			packAnalyzerTerm( *fi);
			close();
		}
		close();
	}
}

void TraceSerializer::packAnalyzerAttribute( const analyzer::Attribute& val)
{
	openTag("name");
	packString( val.name());
	close();
	openTag("value");
	packString( val.value());
	close();
}

void TraceSerializer::packAnalyzerMetaData( const analyzer::MetaData& val)
{
	openTag("name");
	packString( val.name());
	close();
	openTag("value");
	packScalar( val.value());
	close();
}

void TraceSerializer::packAnalyzerTerm( const analyzer::Term& val)
{
	openTag("type");
	packString( val.type());
	close();
	openTag("value");
	packString( val.value());
	close();
	openTag("pos");
	packScalar( val.pos());
	close();
}

void TraceSerializer::packAnalyzerTermVector( const analyzer::TermVector& val)
{
	analyzer::TermVector::const_iterator ti = val.begin(), te = val.end();
	for (; ti != te; ++ti)
	{
		openIndex( ti-val.begin());
		packAnalyzerTerm( *ti);
		close();
	}
}

void TraceSerializer::packAnalyzerToken( const analyzer::Token& val)
{
	openTag("docpos");
	packScalar( val.docpos);
	close();
	openTag("strpos");
	packScalar( val.strpos);
	close();
	openTag("strsize");
	packScalar( val.strsize);
	close();
}

void TraceSerializer::packWeightedDocument( const WeightedDocument& val)
{
	openTag("docno");
	packScalar( val.docno());
	close();
	openTag("weight");
	packScalar( val.weight());
	close();
}

void TraceSerializer::packResultDocument( const ResultDocument& val)
{
	packWeightedDocument( val);
	openTag("summary");
	std::vector<SummaryElement>::const_iterator
		ai = val.summaryElements().begin(), ae = val.summaryElements().end();
	for (; ai != ae; ++ai)
	{
		openIndex( ai-val.summaryElements().begin());
		packSummaryElement( *ai);
		close();
	}
	close();
}

void TraceSerializer::packQueryResult( const QueryResult& val)
{
	openTag("pass");
	packScalar( val.evaluationPass());
	close();
	openTag("nofranked");
	packScalar( val.nofDocumentsRanked());
	close();
	openTag("nofvisited");
	packScalar( val.nofDocumentsVisited());
	close();

	std::vector<ResultDocument>::const_iterator
		ri = val.ranks().begin(), re = val.ranks().end();
	openTag("ranks");
	for (; ri != re; ++ri)
	{
		openIndex( ri-val.ranks().begin());
		packResultDocument( *ri);
		close();
	}
	close();
}

void TraceSerializer::packFeatureParameter( const QueryEvalInterface::FeatureParameter& val)
{
	openTag("name");
	packString( val.parameterName());
	close();
	openTag("featset");
	packString( val.featureSet());
	close();
}

void TraceSerializer::packPhrase( const QueryAnalyzerInterface::Phrase& val)
{
	openTag("type");
	packString( val.type());
	close();
	openTag("content");
	packString( val.content());
	close();
}

void TraceSerializer::packDocumentStatisticsType( const StorageClientInterface::DocumentStatisticsType& val)
{
	packEnum( (TraceEnumTypeId)StorageClient_DocumentStatisticsType, (TraceEnumValueId)val);
}

void TraceSerializer::packStatisticsProcessorBuilderOptions( const StatisticsProcessorInterface::BuilderOptions& val)
{
	openTag("blksize");
	packScalar( val.maxBlockSize);
	close();
	openTag("options");
	packScalar( val.set);
	close();
}

void TraceSerializer::packStatisticsViewerDocumentFrequencyChange( const StatisticsViewerInterface::DocumentFrequencyChange& val)
{
	openTag("type");
	packCharp( val.type);
	close();
	openTag("value");
	packCharp( val.value);
	close();
	openTag("incr");
	packScalar( val.increment);
	close();
}


void TraceSerializer::packQueryProcessorFunctionType( const QueryProcessorInterface::FunctionType& val)
{
	packEnum((TraceEnumTypeId)QueryProcessor_FunctionType, (TraceEnumValueId)val);
}

void TraceSerializer::packTextProcessorFunctionType( const TextProcessorInterface::FunctionType& val)
{
	packEnum((TraceEnumTypeId)TextProcessor_FunctionType, (TraceEnumValueId)val);
}

void TraceSerializer::packPostingJoinOperatorDescription( const PostingJoinOperatorInterface::Description& val)
{
	packString( val.text());
}

void TraceSerializer::packFunctionDescription( const FunctionDescription& val)
{
	openTag("text");
	packString( val.text());
	close();
	openTag("size");
	packScalar( val.parameter().size());
	close();
	openTag("param");
	std::vector<FunctionDescription::Parameter>::const_iterator vi = val.parameter().begin(), ve = val.parameter().end();
	for (; vi != ve; ++vi)
	{
		openIndex( vi-val.parameter().begin());
		openTag("type");
		packEnum( (TraceEnumTypeId)FunctionDescription_Parameter_Type, (TraceEnumValueId)vi->type());
		close();
		openTag("name");
		packString( vi->name());
		close();
		openTag("text");
		packString( vi->text());
		close();
		openTag("domain");
		packString( vi->domain());
		close();
		close();
	}
	close();
}

