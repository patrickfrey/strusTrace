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
#include "objectIds_gen.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/traceLoggerInterface.hpp"
#include <cstring>

using namespace strus;
#undef STRUS_LOWLEVEL_DEBUG

#define CATCH_ERROR catch (const std::bad_alloc&){m_error=true;}

void TraceSerializer::packVoid()
{
	try{
	m_elembuf.push_back( TraceElement());
	}CATCH_ERROR
}

void TraceSerializer::packInt( const int& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::IntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packInt8( const int8_t& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::IntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packInt16( const int16_t& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::IntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packInt32( const int32_t& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::IntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packInt64( const int64_t& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::IntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packUInt( const unsigned int& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::UIntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packUInt8( const uint8_t& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::UIntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packUInt16( const uint16_t& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::UIntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packUInt32( const uint32_t& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::UIntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packUInt64( const uint64_t& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::UIntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packSize( const std::size_t& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::IntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packIndex( const Index& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::IntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packGlobalCounter( const GlobalCounter& value)
{
	try{
	m_elembuf.push_back( TraceElement( (TraceElement::IntType)value));
	}CATCH_ERROR
}

void TraceSerializer::packFloat( const float& value)
{
	try{
	m_elembuf.push_back( TraceElement( (double)value));
	}CATCH_ERROR
}

void TraceSerializer::packDouble( const double& value)
{
	try{
	m_elembuf.push_back( TraceElement( value));
	}CATCH_ERROR
}

void TraceSerializer::packBool( const bool& value)
{
	try{
	m_elembuf.push_back( TraceElement( TraceElement::TypeBool, value));
	}CATCH_ERROR
}

void TraceSerializer::packString( const std::string& value)
{
	try{
	m_elembuf.push_back( TraceElement( TraceElement::TypeString, value.c_str(), value.size()));
	}CATCH_ERROR
}

void TraceSerializer::packStringVector( const std::vector<std::string>& ar)
{
	try{
	std::vector<std::string>::const_iterator ai = ar.begin(), ae = ar.end();
	for (std::size_t aidx=0; ai != ae; ++ai,++aidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex,aidx));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, ai->c_str(), ai->size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packIndexVector( const std::vector<Index>& ar)
{
	try{
	std::vector<Index>::const_iterator ai = ar.begin(), ae = ar.end();
	for (std::size_t aidx=0; ai != ae; ++ai,++aidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex,aidx));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)*ai));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packCharp( const char* buf)
{
	try{
	m_elembuf.push_back( TraceElement( TraceElement::TypeString, buf));
	}CATCH_ERROR
}

void TraceSerializer::packCharpp( const char** buf)
{
	try{
	std::size_t ii=0;
	for (; buf[ii]; ++ii)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ii));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, buf[ii]));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::openIndex( const std::size_t& value)
{
	try{
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, (TraceElement::IntType)value));
	}CATCH_ERROR
}

void TraceSerializer::openTag( const std::string& name)
{
	try{
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, name.c_str(), name.size()));
	}CATCH_ERROR
}

void TraceSerializer::close()
{
	try{
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packObject( const char* className, const TraceObjectId& objId)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeObject, objId, className));
	}CATCH_ERROR
}

void TraceSerializer::packBuffer( const char* buf, std::size_t size)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, buf, size));
	}CATCH_ERROR
}

void TraceSerializer::packBufferFloat( const double* buf, std::size_t size)
{
	try{
	std::size_t ii=0;
	for (ii=0; ii<size; ++ii)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ii));
		m_elembuf.push_back( TraceElement( TraceElement::TypeDouble, buf[ii]));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packNumericVariant( const NumericVariant& val)
{
	try{
	switch (val.type)
	{
		case NumericVariant::Null: m_elembuf.push_back( TraceElement()); break;
		case NumericVariant::Int: m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.variant.Int)); break;
		case NumericVariant::UInt: m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.variant.UInt)); break;
		case NumericVariant::Float: m_elembuf.push_back( TraceElement( val.variant.Float)); break;
	}
	}CATCH_ERROR
}

void TraceSerializer::packDocumentClass( const DocumentClass& dclass)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, dclass.mimeType().c_str(), dclass.mimeType().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, dclass.scheme().c_str(), dclass.scheme().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, dclass.encoding().c_str(), dclass.encoding().size()));
	}CATCH_ERROR
}

void TraceSerializer::packTermStatistics( const TermStatistics& stats)
{
	try{
		if (stats.documentFrequency() >= 0)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "df"));
			m_elembuf.push_back( TraceElement( (TraceElement::IntType)stats.documentFrequency()));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		else
		{
			m_elembuf.push_back( TraceElement());
		}
	}CATCH_ERROR
}

void TraceSerializer::packGlobalStatistics( const GlobalStatistics& stats)
{
	try{
		if (stats.nofDocumentsInserted() >= 0)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "nofdocs"));
			m_elembuf.push_back( TraceElement( (TraceElement::IntType)stats.nofDocumentsInserted()));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		else
		{
			m_elembuf.push_back( TraceElement());
		}
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
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, compareOperatorName( val)));
	}CATCH_ERROR
}

void TraceSerializer::packDatabaseOptions( const DatabaseOptions& val)
{
	try{
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.opt()));
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
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, databaseConfigTypeName( val)));
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
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, storageConfigTypeName( val)));
	}CATCH_ERROR
}

void TraceSerializer::packFeatureOptions( const DocumentAnalyzerInterface::FeatureOptions& val)
{
	try{
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.opt()));
	}CATCH_ERROR
}

void TraceSerializer::packSummaryElement( const SummaryElement& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.name().c_str(), val.name().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.value().c_str(), val.value().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "weight"));
		m_elembuf.push_back( TraceElement( val.weight()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		if (val.index() >= 0)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "index"));
			m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.index()));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
	}CATCH_ERROR
}

void TraceSerializer::packSummaryElementVector( const std::vector<SummaryElement>& ar)
{
	try{
	std::vector<SummaryElement>::const_iterator si = ar.begin(), se = ar.end();
	for (std::size_t sidx=0; si != se; ++si,++sidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, sidx));
		packSummaryElement( *si);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packSummarizationVariable( const SummarizationVariable& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.name().c_str(), val.name().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "itr"));
		const TraceObjectBase* so = dynamic_cast<const TraceObjectBase*>( val.itr());
		if (so)
		{
			const char* className = TraceClassNameMap::className( ClassId_PostingIterator);
			m_elembuf.push_back( TraceElement( TraceElement::TypeObject, so->objid(), className));
		}
		else
		{
			m_elembuf.push_back( TraceElement());
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packSummarizationVariableVector( const std::vector<SummarizationVariable>& ar)
{
	try{
	std::vector<SummarizationVariable>::const_iterator vi = ar.begin(), ve = ar.end();
	for (std::size_t vidx=0; vi != ve; ++vi,++vidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, vidx));
		packSummarizationVariable( *vi);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packDocumentTermIteratorTerm( const DocumentTermIteratorInterface::Term& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "tf"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.tf));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "firstpos"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.firstpos));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "termno"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.termno));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packSlice( DatabaseCursorInterface::Slice& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.ptr(), val.size()));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerDocument( const analyzer::Document& val)
{
	try{
	if (val.subDocumentTypeName().size())
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "doc"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.subDocumentTypeName().c_str(), val.subDocumentTypeName().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	std::vector<analyzer::Attribute>::const_iterator ai = val.attributes().begin(), ae = val.attributes().end();
	if (ai != ae)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "attributes"));
		for (; ai != ae; ++ai)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ai-val.attributes().begin()));
			packAnalyzerAttribute( *ai);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	std::vector<analyzer::MetaData>::const_iterator mi = val.metadata().begin(), me = val.metadata().end();
	if (mi != me)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "metadata"));
		for (; mi != me; ++mi)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, mi-val.metadata().begin()));
			packAnalyzerMetaData( *mi);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	std::vector<analyzer::Term>::const_iterator si = val.searchIndexTerms().begin(), se = val.searchIndexTerms().end();
	if (si != se)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "searchindex"));
		for (; si != se; ++si)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, si-val.searchIndexTerms().begin()));
			packAnalyzerTerm( *si);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	std::vector<analyzer::Term>::const_iterator fi = val.forwardIndexTerms().begin(), fe = val.forwardIndexTerms().end();
	if (fi != fe)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "forwardindex"));
		for (; fi != fe; ++fi)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, fi-val.forwardIndexTerms().begin()));
			packAnalyzerTerm( *fi);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerAttribute( const analyzer::Attribute& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.name().c_str(), val.name().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.value().c_str(), val.value().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerMetaData( const analyzer::MetaData& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.name().c_str(), val.name().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		packNumericVariant( val.value());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerTerm( const analyzer::Term& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type().c_str(), val.type().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.value().c_str(), val.value().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.pos()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerTermVector( const analyzer::TermVector& val)
{
	try{
	analyzer::TermVector::const_iterator ti = val.begin(), te = val.end();
	for (; ti != te; ++ti)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ti-val.begin()));
		packAnalyzerTerm( *ti);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerTermVectorVector( const std::vector<analyzer::TermVector>& val)
{
	try{
	std::vector<analyzer::TermVector>::const_iterator ti = val.begin(), te = val.end();
	for (; ti != te; ++ti)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ti-val.begin()));
		packAnalyzerTermVector( *ti);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerToken( const analyzer::Token& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "docpos"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.docpos));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "strpos"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.strpos));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "strsize"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.strsize));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerTokenVector( const std::vector<analyzer::Token>& ar)
{
	try{
	std::vector<analyzer::Token>::const_iterator ti = ar.begin(), te = ar.end();
	for (; ti != te; ++ti)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ti-ar.begin()));
		packAnalyzerToken( *ti);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packWeightedDocument( const WeightedDocument& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "weight"));
		m_elembuf.push_back( TraceElement( val.weight()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "docno"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.docno()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packResultDocument( const ResultDocument& val)
{
	try{
	packWeightedDocument( val);
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "summary"));
	std::vector<SummaryElement>::const_iterator
		ai = val.summaryElements().begin(), ae = val.summaryElements().end();
	for (; ai != ae; ++ai)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ai-val.summaryElements().begin()));
		packSummaryElement( *ai);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packQueryResult( const QueryResult& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "pass"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.evaluationPass()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "nofranked"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.nofDocumentsRanked()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "nofvisited"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.nofDocumentsVisited()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "ranks"));
		std::vector<ResultDocument>::const_iterator
			ri = val.ranks().begin(), re = val.ranks().end();
		for (; ri != re; ++ri)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ri-val.ranks().begin()));
			packResultDocument( *ri);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packFeatureParameter( const QueryEvalInterface::FeatureParameter& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.parameterName().c_str(), val.parameterName().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "featset"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.featureSet().c_str(), val.featureSet().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packFeatureParameterVector( const std::vector<QueryEvalInterface::FeatureParameter>& ar)
{
	try{
	std::vector<QueryEvalInterface::FeatureParameter>::const_iterator ai = ar.begin(), ae = ar.end();
	for (std::size_t aidx=0; ai != ae; ++ai,++aidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, aidx));
		packFeatureParameter( *ai);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packPhrase( const QueryAnalyzerInterface::Phrase& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type().c_str(), val.type().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "content"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.content().c_str(), val.content().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packPhraseVector( const std::vector<QueryAnalyzerInterface::Phrase>& ar)
{
	try{
	std::vector<QueryAnalyzerInterface::Phrase>::const_iterator pi = ar.begin(), pe = ar.end();
	for (std::size_t pidx=0; pi != pe; ++pi,++pidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, pidx));
		packPhrase( *pi);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
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
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, documentStatisticsTypeName( val)));
	}CATCH_ERROR
}

void TraceSerializer::packStatisticsProcessorBuilderOptions( const StatisticsProcessorInterface::BuilderOptions& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "blksize"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.maxBlockSize));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "options"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.set));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packStatisticsViewerDocumentFrequencyChange( const StatisticsViewerInterface::DocumentFrequencyChange& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.value));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "increment"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.increment));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
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
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, queryProcessorFunctionTypeName(val)));
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
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, textProcessorFunctionTypeName(val)));
	}CATCH_ERROR
}

void TraceSerializer::packPostingJoinOperatorDescription( const PostingJoinOperatorInterface::Description& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.text().c_str(), val.text().size()));
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
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "text"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.text().c_str(), val.text().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "size"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.parameter().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "param"));
		std::vector<FunctionDescription::Parameter>::const_iterator vi = val.parameter().begin(), ve = val.parameter().end();
		for (; vi != ve; ++vi)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, vi-val.parameter().begin()));

			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
			m_elembuf.push_back( TraceElement( TraceElement::TypeString, functionDescriptionTypeName(vi->type())));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
			
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
			m_elembuf.push_back( TraceElement( TraceElement::TypeString, vi->name().c_str(), vi->name().size()));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
			
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "text"));
			m_elembuf.push_back( TraceElement( TraceElement::TypeString, vi->text().c_str(), vi->text().size()));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "domain"));
			m_elembuf.push_back( TraceElement( TraceElement::TypeString, vi->domain().c_str(), vi->domain().size()));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}


