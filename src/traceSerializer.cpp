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

void TraceSerializer::packIndexRange( const IndexRange& value)
{
	try{
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)value.start()));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)value.end()));
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

void TraceSerializer::packUintVector( const std::vector<unsigned int>& ar)
{
	try{
	std::vector<unsigned int>::const_iterator ai = ar.begin(), ae = ar.end();
	for (std::size_t aidx=0; ai != ae; ++ai,++aidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex,aidx));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)*ai));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packIntVector( const std::vector<int>& ar)
{
	try{
	std::vector<int>::const_iterator ai = ar.begin(), ae = ar.end();
	for (std::size_t aidx=0; ai != ae; ++ai,++aidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex,aidx));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)*ai));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packFloatVector( const std::vector<float>& ar)
{
	try{
	std::vector<float>::const_iterator ai = ar.begin(), ae = ar.end();
	for (std::size_t aidx=0; ai != ae; ++ai,++aidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex,aidx));
		m_elembuf.push_back( TraceElement( *ai));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packDoubleVector( const std::vector<double>& ar)
{
	try{
	std::vector<double>::const_iterator ai = ar.begin(), ae = ar.end();
	for (std::size_t aidx=0; ai != ae; ++ai,++aidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex,aidx));
		m_elembuf.push_back( TraceElement( *ai));
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

void TraceSerializer::packBlob( const void* buf, std::size_t size)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, (const char*)buf, size));
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

void TraceSerializer::packAnalyzerSegmenterOptions( const analyzer::SegmenterOptions& val)
{
	try{
	std::vector<analyzer::SegmenterOptions::Item>::const_iterator oi = val.items().begin(), oe = val.items().end();
	for (std::size_t oidx=0; oi != oe; ++oi,++oidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, oidx));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, oi->first.c_str(), oi->first.size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, oi->second.c_str(), oi->second.size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerDocumentClass( const analyzer::DocumentClass& dclass)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, dclass.mimeType().c_str(), dclass.mimeType().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, dclass.schema().c_str(), dclass.schema().size()));
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

static const char* vectorStorageConfigTypeName( VectorStorageInterface::ConfigType tp)
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

void TraceSerializer::packVectorStorageConfigType( const VectorStorageInterface::ConfigType& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, vectorStorageConfigTypeName( val)));
	}CATCH_ERROR
}

void TraceSerializer::packFeatureOptions( const analyzer::FeatureOptions& val)
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

void TraceSerializer::packSlice( const DatabaseCursorInterface::Slice& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.ptr(), val.size()));
	}CATCH_ERROR
}

void TraceSerializer::packTimeStamp( const TimeStamp& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "unixtime"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.unixtime()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "counter"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.counter()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packTimeStampVector( const std::vector<TimeStamp>& val)
{
	try{
	std::vector<TimeStamp>::const_iterator ti = val.begin(), te = val.end();
	for (; ti != te; ++ti)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ti-val.begin()));
		packTimeStamp( *ti);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packStatisticsMessage( const StatisticsMessage& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "timestamp"));
		packTimeStamp( val.timestamp());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "size"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	} CATCH_ERROR
}

void TraceSerializer::packAnalyzerQueryTerm( const analyzer::QueryTerm& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type().c_str(), val.type().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.value().c_str(), val.value().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "len"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.len()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerQueryTermExpression( const analyzer::QueryTermExpression& val)
{
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "termexpr"));
	std::vector<analyzer::QueryTermExpression::Instruction>::const_iterator
		ii = val.instructions().begin(), ie = val.instructions().end();
	for (; ii != ie; ++ii)
	{
		switch (ii->opCode())
		{
			case analyzer::QueryTermExpression::Instruction::Term:
			{
				const analyzer::QueryTerm& term = val.term( ii->idx());
				m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "term"));
				packAnalyzerQueryTerm( term);
				m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
				break;
			}
			case analyzer::QueryTermExpression::Instruction::Operator:
				m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "op"));
				m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "id"));
				m_elembuf.push_back( TraceElement( (TraceElement::UIntType) ii->idx())); 
				m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
				m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "nofargs"));
				m_elembuf.push_back( TraceElement( (TraceElement::UIntType) ii->nofOperands())); 
				m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
				break;
		}
	}
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
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
	std::vector<analyzer::DocumentAttribute>::const_iterator ai = val.attributes().begin(), ae = val.attributes().end();
	if (ai != ae)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "attributes"));
		for (; ai != ae; ++ai)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ai-val.attributes().begin()));
			packAnalyzerDocumentAttribute( *ai);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	std::vector<analyzer::DocumentMetaData>::const_iterator mi = val.metadata().begin(), me = val.metadata().end();
	if (mi != me)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "metadata"));
		for (; mi != me; ++mi)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, mi-val.metadata().begin()));
			packAnalyzerDocumentMetaData( *mi);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	std::vector<analyzer::DocumentTerm>::const_iterator si = val.searchIndexTerms().begin(), se = val.searchIndexTerms().end();
	if (si != se)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "searchindex"));
		for (; si != se; ++si)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, si-val.searchIndexTerms().begin()));
			packAnalyzerDocumentTerm( *si);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	std::vector<analyzer::DocumentTerm>::const_iterator fi = val.forwardIndexTerms().begin(), fe = val.forwardIndexTerms().end();
	if (fi != fe)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "forwardindex"));
		for (; fi != fe; ++fi)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, fi-val.forwardIndexTerms().begin()));
			packAnalyzerDocumentTerm( *fi);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerDocumentAttribute( const analyzer::DocumentAttribute& val)
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

void TraceSerializer::packAnalyzerDocumentMetaData( const analyzer::DocumentMetaData& val)
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

void TraceSerializer::packAnalyzerDocumentTerm( const analyzer::DocumentTerm& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type().c_str(), val.type().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.value().c_str(), val.value().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "pos"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.pos()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerDocumentTermArray( const std::vector<analyzer::DocumentTerm>& val)
{
	try{
	std::vector<analyzer::DocumentTerm>::const_iterator ti = val.begin(), te = val.end();
	for (; ti != te; ++ti)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ti-val.begin()));
		packAnalyzerDocumentTerm( *ti);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerPosition( const analyzer::Position& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "seg"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.seg()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "ofs"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.ofs()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerToken( const analyzer::Token& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "ordpos"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.ordpos()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "origpos"));
		packAnalyzerPosition( val.origpos());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "origsize"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.origsize()));
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

void TraceSerializer::packAnalyzerQueryGroupBy( const QueryAnalyzerContextInterface::GroupBy& groupBy)
{
	try{
	const char* valstr = "";
	switch (groupBy)
	{
		case QueryAnalyzerContextInterface::GroupByPosition:
			valstr = "position";
		break;
		case QueryAnalyzerContextInterface::GroupEvery:
			valstr = "every";
		break;
		case QueryAnalyzerContextInterface::GroupAll:
			valstr = "all";
		break;
		case QueryAnalyzerContextInterface::GroupUnique:
			valstr = "unique";
		break;
	}
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "groupby"));
	m_elembuf.push_back( TraceElement( TraceElement::TypeString, valstr));
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerPatternLexem( const analyzer::PatternLexem& val)
{
	packAnalyzerToken( val);
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "id"));
	m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.id()));
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
}

void TraceSerializer::packAnalyzerPatternLexemVector( const std::vector<analyzer::PatternLexem>& val)
{
	try{
	std::vector<analyzer::PatternLexem>::const_iterator ti = val.begin(), te = val.end();
	for (; ti != te; ++ti)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ti-val.begin()));
		packAnalyzerPatternLexem( *ti);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerPositionBind( const analyzer::PositionBind& val)
{
	try{
	const char* valstr = "";
	switch (val)
	{
		case analyzer::BindContent:	valstr = "content"; break;
		case analyzer::BindSuccessor:	valstr = "succ"; break;
		case analyzer::BindPredecessor:	valstr = "pred"; break;
		case analyzer::BindUnique:	valstr = "unique"; break;
	}
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "firstpos"));
	m_elembuf.push_back( TraceElement( TraceElement::TypeString, valstr));
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerTokenMarkup( const analyzer::TokenMarkup& val)
{
	try{
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
	m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.name().c_str()));
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	std::vector<analyzer::TokenMarkup::Attribute>::const_iterator ai = val.attributes().begin(), ae = val.attributes().end();
	for (; ai != ae; ++ai)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "attr"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, ai->name().c_str()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, ai->value().c_str()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerPatternMatcherResultItem( const analyzer::PatternMatcherResultItem& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.name()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.value()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "ordpos"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.ordpos()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "ordend"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.ordend()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "origpos"));
		packAnalyzerPosition( val.origpos());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "origend"));
		packAnalyzerPosition( val.origend());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerPatternMatcherResult( const analyzer::PatternMatcherResult& val)
{
	try{
	packAnalyzerPatternMatcherResultItem( val);
	std::vector<analyzer::PatternMatcherResult::Item>::const_iterator ti = val.items().begin(), te = val.items().end();
	for (; ti != te; ++ti)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "item"));
		packAnalyzerPatternMatcherResultItem( *ti);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerPatternMatcherResultVector( const std::vector<analyzer::PatternMatcherResult>& val)
{
	std::vector<analyzer::PatternMatcherResult>::const_iterator ri = val.begin(), re = val.end();
	for (; ri != re; ++ri)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "result"));
		packAnalyzerPatternMatcherResult( *ri);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
}

void TraceSerializer::packAnalyzerPatternMatcherStatistics( const analyzer::PatternMatcherStatistics& val)
{
	std::vector<analyzer::PatternMatcherStatistics::Item>::const_iterator ti = val.items().begin(), te = val.items().end();
	for (; ti != te; ++ti)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, ti->name()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeDouble, ti->value()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
}

void TraceSerializer::packPatternMatcherJoinOperation( const PatternMatcherInstanceInterface::JoinOperation& val)
{
	const char* valstr = "";
	switch (val)
	{
		case PatternMatcherInstanceInterface::OpSequence: valstr = "sequence"; break;
		case PatternMatcherInstanceInterface::OpSequenceImm: valstr = "sequence_imm"; break;
		case PatternMatcherInstanceInterface::OpSequenceStruct: valstr = "sequence_struct"; break;
		case PatternMatcherInstanceInterface::OpWithin: valstr = "within"; break;
		case PatternMatcherInstanceInterface::OpWithinStruct: valstr = "within_struct"; break;
		case PatternMatcherInstanceInterface::OpAny: valstr = "any"; break;
		case PatternMatcherInstanceInterface::OpAnd: valstr = "and"; break;
	}
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "joinop"));
	m_elembuf.push_back( TraceElement( TraceElement::TypeString, valstr));
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
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
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.nofRanked()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "nofvisited"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.nofVisited()));
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

void TraceSerializer::packTermStatisticsChange( const TermStatisticsChange& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.value()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));

		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "increment"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.increment()));
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
	static const char* ar[] = {"Segmenter","Tokenizer", "Normalizer","Aggregator","PatternLexer","PatternMatcher"};
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
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.name().c_str(), val.name().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "description"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.text().c_str(), val.text().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
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

void TraceSerializer::packStructView( const StructView& val)
{
	try{
		switch (val.type())
		{
			case StructView::Null: 
				break;
			case StructView::String:
			{
				m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "string"));
				packString( val.asstring());
				m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
				break;
			}
			case StructView::Numeric:
			{
				m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "number"));
				packNumericVariant( val.asnumeric());
				m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
				break;
			}
			case StructView::Structure:
			{
				if (val.isArray())
				{
					m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "array"));
					std::size_t ai = 0, ae = val.arraySize();
					for (; ai != ae; ++ai)
					{
						packStructView( *val.get( ai));
					}
					m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
				}
				else
				{
					m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "dict"));
					StructView::dict_iterator di =  val.dict_begin(), de =  val.dict_end();
					for (; di != de; ++di)
					{
						m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, di->first.c_str()));
						packStructView( di->second);
						m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
					}
					m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
				}
				break;
			}
		}
	}CATCH_ERROR
}

void TraceSerializer::packVectorQueryResult( const std::vector<VectorQueryResult>& val)
{
	try{
	std::vector<VectorQueryResult>::const_iterator ri = val.begin(), re = val.end();
	for (std::size_t ridx=0; ri != re; ++ri,++ridx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, ridx));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( (TraceElement::TypeString), ri->value().c_str(), ri->value().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "weight"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeDouble, ri->weight()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	}CATCH_ERROR
}

void TraceSerializer::packSentenceTerm( const SentenceTerm& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type().c_str(), val.type().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.value().c_str(), val.value().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packSentenceTermVector( const SentenceTermList& val)
{
	std::vector<SentenceTerm>::const_iterator ti = val.begin(), te = val.end();
	for (std::size_t tidx=0; ti != te; ++ti,++tidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, tidx));
		packSentenceTerm( *ti);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
}

void TraceSerializer::packSentenceTermListVector( const std::vector<SentenceTermList>& val)
{
	std::vector<SentenceTermList>::const_iterator ti = val.begin(), te = val.end();
	for (std::size_t tidx=0; ti != te; ++ti,++tidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, tidx));
		packSentenceTermVector( *ti);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
}

void TraceSerializer::packSentenceGuess( const SentenceGuess& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "classname"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.classname().c_str(), val.classname().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "terms"));
		packSentenceTermVector( val.terms());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "weight"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeDouble, val.weight()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packSentenceGuessVector( const std::vector<SentenceGuess>& val)
{
	std::vector<SentenceGuess>::const_iterator gi = val.begin(), ge = val.end();
	for (std::size_t gidx=0; gi != ge; ++gi,++gidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, gidx));
		packSentenceGuess( *gi);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
}

void TraceSerializer::packAnalyzerFunctionView( const analyzer::FunctionView& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.name().c_str(), val.name().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "parameter"));
		std::vector<analyzer::FunctionView::NamedParameter>::const_iterator vi = val.parameter().begin(), ve = val.parameter().end();
		for (std::size_t vidx=0; vi != ve; ++vi,++vidx)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, vidx));
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
			m_elembuf.push_back( TraceElement( (TraceElement::TypeString), vi->first.c_str(), vi->first.size()));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
			m_elembuf.push_back( TraceElement( (TraceElement::TypeString), vi->second.c_str(), vi->second.size()));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}
void TraceSerializer::packAnalyzerFeatureView( const analyzer::FeatureView& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type().c_str(), val.type().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "select"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.selectexpr().c_str(), val.selectexpr().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "tokenizer"));
		packAnalyzerFunctionView( val.tokenizer());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "normalizer"));
		std::vector<analyzer::FunctionView>::const_iterator vi = val.normalizer().begin(), ve = val.normalizer().end();
		for (std::size_t vidx=0; vi != ve; ++vi,++vidx)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, vidx));
			packAnalyzerFunctionView( *vi);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "priority"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.priority()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "opt"));
		m_elembuf.push_back( TraceElement( (TraceElement::UIntType)val.options().opt()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerFeatureViewList( const char* name, const std::vector<analyzer::FeatureView>& val)
{
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, name));
	std::vector<analyzer::FeatureView>::const_iterator vi = val.begin(), ve = val.end();
	for (std::size_t vidx=0; vi != ve; ++vi,++vidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, vidx));
		packAnalyzerFeatureView( *vi);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
}

void TraceSerializer::packAnalyzerAggregatorView( const analyzer::AggregatorView& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type().c_str(), val.type().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "function"));
		packAnalyzerFunctionView( val.function());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerSubDocumentDefinitionView( const analyzer::SubDocumentDefinitionView& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "select"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.selection().c_str(), val.selection().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "name"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.subDocumentTypeName().c_str(), val.subDocumentTypeName().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerSubContentDefinitionView( const analyzer::SubContentDefinitionView& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "select"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.selection().c_str(), val.selection().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "doctype"));
		packAnalyzerDocumentClass( val.documentClass());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerDocumentAnalyzerView( const analyzer::DocumentAnalyzerView& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "analyzer"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "segmenter"));
		packAnalyzerFunctionView( val.segmenter());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "subcontent"));
			std::vector<analyzer::SubContentDefinitionView>::const_iterator vi = val.subcontents().begin(), ve = val.subcontents().end();
			for (std::size_t vidx=0; vi != ve; ++vi,++vidx)
			{
				m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, vidx));
				packAnalyzerSubContentDefinitionView( *vi);
				m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
			}
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "subdocument"));
			std::vector<analyzer::SubDocumentDefinitionView>::const_iterator vi = val.subdocuments().begin(), ve = val.subdocuments().end();
			for (std::size_t vidx=0; vi != ve; ++vi,++vidx)
			{
				m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, vidx));
				packAnalyzerSubDocumentDefinitionView( *vi);
				m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
			}
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}{
			packAnalyzerFeatureViewList( "attribute", val.attributes());
			packAnalyzerFeatureViewList( "metadata", val.metadata());
			packAnalyzerFeatureViewList( "forwardindex", val.forwardindex());
			packAnalyzerFeatureViewList( "searchindex", val.searchindex());
		}{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "aggregator"));
			std::vector<analyzer::AggregatorView>::const_iterator vi = val.aggregators().begin(), ve = val.aggregators().end();
			for (std::size_t vidx=0; vi != ve; ++vi,++vidx)
			{
				m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, vidx));
				packAnalyzerAggregatorView( *vi);
				m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
			}
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerDocumentAnalyzerMapView( const analyzer::DocumentAnalyzerMapView& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "analyzermap"));
		std::vector<analyzer::DocumentAnalyzerMapElementView>::const_iterator di = val.definitions().begin(), de = val.definitions().end();
		for (std::size_t didx=0; di != de; ++di,++didx)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, didx));
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "mimetype"));
			m_elembuf.push_back( TraceElement( TraceElement::TypeString, di->mimeType().c_str(), di->mimeType().size()));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "schema"));
			m_elembuf.push_back( TraceElement( TraceElement::TypeString, di->schema().c_str(), di->schema().size()));
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
			packAnalyzerDocumentAnalyzerView( di->analyzer());
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerQueryElementView( const analyzer::QueryElementView& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type().c_str(), val.type().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "field"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.field().c_str(), val.field().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "tokenizer"));
		packAnalyzerFunctionView( val.tokenizer());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "normalizer"));
		std::vector<analyzer::FunctionView>::const_iterator vi = val.normalizer().begin(), ve = val.normalizer().end();
		for (std::size_t vidx=0; vi != ve; ++vi,++vidx)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, vidx));
			packAnalyzerFunctionView( *vi);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "priority"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.priority()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerQueryAnalyzerView( const analyzer::QueryAnalyzerView& val)
{
	try
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "analyzer"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "elements"));
		std::vector<analyzer::QueryElementView>::const_iterator ei = val.elements().begin(), ee = val.elements().end();
		for (std::size_t eidx=0; ei != ee; ++ei,++eidx)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, eidx));
			packAnalyzerQueryElementView( *ei);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "lexems"));
		ei = val.patternLexems().begin(), ee = val.patternLexems().end();
		for (std::size_t eidx=0; ei != ee; ++ei,++eidx)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, eidx));
			packAnalyzerQueryElementView( *ei);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerContentStatisticsElementView( const analyzer::ContentStatisticsElementView& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type().c_str(), val.type().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "regex"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.regex().c_str(), val.regex().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "priority"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.priority()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "minlen"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.minLen()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "maxlen"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.maxLen()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "tokenizer"));
		packAnalyzerFunctionView( val.tokenizer());
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "normalizer"));
		std::vector<analyzer::FunctionView>::const_iterator vi = val.normalizer().begin(), ve = val.normalizer().end();
		for (std::size_t vidx=0; vi != ve; ++vi,++vidx)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, vidx));
			packAnalyzerFunctionView( *vi);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerContentStatisticsView( const analyzer::ContentStatisticsView& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "contentstats"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "elements"));
		std::vector<analyzer::ContentStatisticsElementView>::const_iterator ei = val.elements().begin(), ee = val.elements().end();
		for (std::size_t eidx=0; ei != ee; ++ei,++eidx)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, eidx));
			packAnalyzerContentStatisticsElementView( *ei);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerContentStatisticsItem( const analyzer::ContentStatisticsItem& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "item"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "select"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.select().c_str(), val.select().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.type().c_str(), val.type().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "example"));
		m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.example().c_str(), val.example().size()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "df"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.df()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "tf"));
		m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.tf()));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerContentStatisticsItemVector( const std::vector<analyzer::ContentStatisticsItem>& val)
{
	try{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "items"));
		std::vector<analyzer::ContentStatisticsItem>::const_iterator ei = val.begin(), ee = val.end();
		for (std::size_t eidx=0; ei != ee; ++ei,++eidx)
		{
			m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, eidx));
			packAnalyzerContentStatisticsItem( *ei);
			m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
		}
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}CATCH_ERROR
}

void TraceSerializer::packAnalyzerContentStatisticsResult( const analyzer::ContentStatisticsResult& val)
{
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "stats"));
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "nofdocs"));
	m_elembuf.push_back( TraceElement( (TraceElement::IntType)val.nofDocuments()));
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	packAnalyzerContentStatisticsItemVector( val.items());
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
}

void TraceSerializer::packPosTaggerDataElement( const PosTaggerDataInterface::Element& val)
{
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "type"));
	m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.typeName( val.type())));
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "tag"));
	m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.tag().c_str(), val.tag().size()));
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "value"));
	m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.value().c_str(), val.value().size()));
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "ref"));
	m_elembuf.push_back( TraceElement( TraceElement::TypeString, val.ref().c_str(), val.ref().size()));
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
}

void TraceSerializer::packPosTaggerDataElementVector( const std::vector<PosTaggerDataInterface::Element>& val)
{
	m_elembuf.push_back( TraceElement( TraceElement::TypeOpenTag, "stats"));
	std::vector<PosTaggerDataInterface::Element>::const_iterator ei = val.begin(), ee = val.end();
	for (std::size_t eidx=0; ei != ee; ++ei,++eidx)
	{
		m_elembuf.push_back( TraceElement( TraceElement::TypeOpenIndex, eidx));
		packPosTaggerDataElement( *ei);
		m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
	}
	m_elembuf.push_back( TraceElement( TraceElement::TypeClose));
}

