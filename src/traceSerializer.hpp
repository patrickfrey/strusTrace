/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
/// \brief Implementation of serialization methods of more complec objects
/// \file traceSerializer.hpp
#ifndef _STRUS_TRACE_SERIALIZER_HPP_INCLUDED
#define _STRUS_TRACE_SERIALIZER_HPP_INCLUDED
#include "strus/traceElement.hpp"
#include "strus/traceLoggerInterface.hpp"
#include "strus/numericVariant.hpp"
#include "strus/termStatistics.hpp"
#include "strus/globalStatistics.hpp"
#include "strus/blockStatistics.hpp"
#include "strus/statisticsMessage.hpp"
#include "strus/metaDataRestrictionInterface.hpp"
#include "strus/databaseOptions.hpp"
#include "strus/databaseInterface.hpp"
#include "strus/databaseCursorInterface.hpp"
#include "strus/storageInterface.hpp"
#include "strus/storageClientInterface.hpp"
#include "strus/vectorStorageInterface.hpp"
#include "strus/summaryElement.hpp"
#include "strus/summarizationVariable.hpp"
#include "strus/documentTermIteratorInterface.hpp"
#include "strus/weightedField.hpp"
#include "strus/weightedDocument.hpp"
#include "strus/resultDocument.hpp"
#include "strus/queryResult.hpp"
#include "strus/structView.hpp"
#include "strus/structureIteratorInterface.hpp"
#include "strus/structureLink.hpp"
#include "strus/structureHeaderField.hpp"
#include "strus/storageCommitResult.hpp"
#include "strus/queryEvalInterface.hpp"
#include "strus/queryProcessorInterface.hpp"
#include "strus/textProcessorInterface.hpp"
#include "strus/segmenterInterface.hpp"
#include "strus/patternMatcherContextInterface.hpp"
#include "strus/patternMatcherInstanceInterface.hpp"
#include "strus/patternMatcherInterface.hpp"
#include "strus/patternLexerContextInterface.hpp"
#include "strus/patternLexerInstanceInterface.hpp"
#include "strus/patternLexerInterface.hpp"
#include "strus/documentAnalyzerInstanceInterface.hpp"
#include "strus/documentAnalyzerContextInterface.hpp"
#include "strus/queryAnalyzerInstanceInterface.hpp"
#include "strus/queryAnalyzerContextInterface.hpp"
#include "strus/vectorQueryResult.hpp"
#include "strus/sentenceTerm.hpp"
#include "strus/sentenceGuess.hpp"
#include "strus/analyzer/token.hpp"
#include "strus/analyzer/patternLexem.hpp"
#include "strus/analyzer/tokenMarkup.hpp"
#include "strus/analyzer/patternMatcherStatistics.hpp"
#include "strus/analyzer/positionBind.hpp"
#include "strus/analyzer/patternMatcherResult.hpp"
#include "strus/analyzer/document.hpp"
#include "strus/analyzer/documentClass.hpp"
#include "strus/analyzer/documentClass.hpp"
#include "strus/analyzer/contentStatisticsItem.hpp"
#include "strus/analyzer/contentStatisticsResult.hpp"
#include "strus/posTaggerDataInterface.hpp"
#include "strus/statisticsViewerInterface.hpp"
#include <string>
#include <vector>

namespace strus
{

/// \brief Forward declaration
class ErrorBufferInterface;

/// \brief Class for inspecting logged traces
class TraceSerializer
{
public:
	/// \brief Constructor
	explicit TraceSerializer()
		:m_error(false),m_elembuf(){}
	/// \brief Destructor
	~TraceSerializer(){}

	void packVoid();
	void packInt( const int& value);
	void packInt8( const int8_t& value);
	void packInt16( const int16_t& value);
	void packInt32( const int32_t& value);
	void packInt64( const int64_t& value);
	void packUInt( const unsigned int& value);
	void packUInt8( const uint8_t& value);
	void packUInt16( const uint16_t& value);
	void packUInt32( const uint32_t& value);
	void packUInt64( const uint64_t& value);
	void packSize( const std::size_t& value);
	void packIndex( const Index& value);
	void packIndexRange( const IndexRange& value);
	void packGlobalCounter( const GlobalCounter& value);
	void packFloat( const float& value);
	void packDouble( const double& value);
	void packBool( const bool& value);
	void packString( const std::string& value);
	void packStringVector( const std::vector<std::string>& ar);
	void packIndexVector( const std::vector<Index>& ar);
	void packUintVector( const std::vector<unsigned int>& ar);
	void packIntVector( const std::vector<int>& ar);
	void packDoubleVector( const std::vector<double>& ar);
	void packFloatVector( const std::vector<float>& ar);
	void packCharp( const char* buf);
	void packCharpp( const char** buf);
	void openIndex( const std::size_t& value);
	void openTag( const std::string& name);
	void close();

	void packObject( const char* classId, const TraceObjectId& objId);
	void packBlob( const void* buf, std::size_t size);
	void packBuffer( const char* buf, std::size_t size);
	void packBufferFloat( const double* buf, std::size_t size);
	void packNumericVariant( const NumericVariant& val);

	void packAnalyzerSegmenterOptions( const analyzer::SegmenterOptions& val);
	void packAnalyzerDocumentClass( const analyzer::DocumentClass& prop);
	void packTermStatistics( const TermStatistics& stats);
	void packGlobalStatistics( const GlobalStatistics& stats);
	void packBlockStatisticsElement( const BlockStatistics::Element& elem);
	void packBlockStatistics( const BlockStatistics& stats);
	void packMetaDataRestrictionCompareOperator( MetaDataRestrictionInterface::CompareOperator val);

	void packDatabaseOptions( const DatabaseOptions& val);
	void packDatabaseConfigType( const DatabaseInterface::ConfigType& val);
	void packStorageConfigType( const StorageInterface::ConfigType& val);
	void packVectorStorageConfigType( const VectorStorageInterface::ConfigType& val);
	void packFeatureOptions( const analyzer::FeatureOptions& val);
	void packSummaryElement( const SummaryElement& val);
	void packSummaryElementVector( const std::vector<SummaryElement>& val);
	void packSummarizationVariable( const SummarizationVariable& val);
	void packSummarizationVariableVector( const std::vector<SummarizationVariable>& val);
	void packDocumentTermIteratorTerm( const DocumentTermIteratorInterface::Term& term);
	void packSlice( const DatabaseCursorInterface::Slice& val);
	void packTimeStamp( const TimeStamp& val);
	void packTimeStampVector( const std::vector<TimeStamp>& val);
	void packStatisticsMessage( const StatisticsMessage& val);
	void packAnalyzerQueryTerm( const analyzer::QueryTerm& val);
	void packAnalyzerQueryTermExpression( const analyzer::QueryTermExpression& val);
	void packAnalyzerDocumentStructure( const analyzer::DocumentStructure& val);
	void packAnalyzerDocument( const analyzer::Document& val);
	void packAnalyzerDocumentAttribute( const analyzer::DocumentAttribute& val);
	void packAnalyzerDocumentMetaData( const analyzer::DocumentMetaData& val);
	void packAnalyzerDocumentTerm( const analyzer::DocumentTerm& val);
	void packAnalyzerDocumentTermArray( const std::vector<analyzer::DocumentTerm>& val);
	void packAnalyzerPosition( const analyzer::Position& val);
	void packAnalyzerToken( const analyzer::Token& val);
	void packAnalyzerTokenVector( const std::vector<analyzer::Token>& val);
	void packDocumentAnalyzerStructureType( const DocumentAnalyzerInstanceInterface::StructureType& val);
	void packAnalyzerQueryGroupBy( const QueryAnalyzerContextInterface::GroupBy& groupBy);
	void packAnalyzerPatternLexem( const analyzer::PatternLexem& val);
	void packAnalyzerPatternLexemVector( const std::vector<analyzer::PatternLexem>& val);
	void packAnalyzerPositionBind( const analyzer::PositionBind& posbind);
	void packAnalyzerTokenMarkup( const analyzer::TokenMarkup& val);
	void packAnalyzerPatternMatcherResultItem( const analyzer::PatternMatcherResultItem& val);
	void packAnalyzerPatternMatcherResult( const analyzer::PatternMatcherResult& val);
	void packAnalyzerPatternMatcherResultVector( const std::vector<analyzer::PatternMatcherResult>& val);
	void packAnalyzerPatternMatcherStatistics( const analyzer::PatternMatcherStatistics& val);
	void packPatternMatcherJoinOperation( const PatternMatcherInstanceInterface::JoinOperation& val);
	void packWeightedField( const WeightedField& val);
	void packWeightedFieldArray( const std::vector<WeightedField>& val);
	void packWeightedDocument( const WeightedDocument& val);
	void packResultDocument( const ResultDocument& val);
	void packQueryResult( const QueryResult& val);
	void packFeatureParameter( const QueryEvalInterface::FeatureParameter& val);
	void packFeatureParameterVector( const std::vector<QueryEvalInterface::FeatureParameter>& ar);
	void packDocumentStatisticsType( const StorageClientInterface::DocumentStatisticsType& val);
	void packTermStatisticsChange( const TermStatisticsChange& val);
	void packQueryProcessorFunctionType( const QueryProcessorInterface::FunctionType& val);
	void packTextProcessorFunctionType( const TextProcessorInterface::FunctionType& val);
	void packStructView( const StructView& val);
	void packVectorQueryResult( const std::vector<VectorQueryResult>& val);
	void packSentenceTerm( const SentenceTerm& val);
	void packSentenceTermVector( const SentenceTermList& val);
	void packSentenceTermListVector( const std::vector<SentenceTermList>& val);
	void packSentenceGuess( const SentenceGuess& val);
	void packSentenceGuessVector( const std::vector<SentenceGuess>& val);
	void packAnalyzerContentStatisticsItem( const analyzer::ContentStatisticsItem& val);
	void packAnalyzerContentStatisticsItemVector( const std::vector<analyzer::ContentStatisticsItem>& val);
	void packAnalyzerContentStatisticsResult( const analyzer::ContentStatisticsResult& val);
	void packPosTaggerDataElement( const PosTaggerDataInterface::Element& val);
	void packPosTaggerDataElementVector( const std::vector<PosTaggerDataInterface::Element>& val);
	void packStorageCommitResult( const StorageCommitResult& res);
	void packStructureLinkArray( const StructureLinkArray& lar);
	void packStructureHeaderField( const StructureHeaderField& val);

	bool hasError() const
	{
		return m_error;
	}

	const std::vector<TraceElement>& content() const
	{
		return m_elembuf;
	}

private:
private:
	bool m_error;
	std::vector<TraceElement> m_elembuf;
};

}//namespace
#endif


