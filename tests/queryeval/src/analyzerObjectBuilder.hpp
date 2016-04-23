/*
 * Copyright (c) 2014 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _STRUS_TRACE_TEST_ANALYZER_OBJECT_BUILDER_HPP_INCLUDED
#define _STRUS_TRACE_TEST_ANALYZER_OBJECT_BUILDER_HPP_INCLUDED
#include "strus/analyzerObjectBuilderInterface.hpp"
#include "strus/lib/textproc.hpp"
#include "strus/lib/segmenter_textwolf.hpp"
#include "strus/lib/analyzer.hpp"
#include "strus/reference.hpp"
#include "strus/errorBufferInterface.hpp"
#include "strus/segmenterInterface.hpp"
#include <string>
#include <stdexcept>
#include <memory>

/// \brief strus toplevel namespace
namespace strus {

class AnalyzerObjectBuilder
	:public strus::AnalyzerObjectBuilderInterface
{
public:
	AnalyzerObjectBuilder( ErrorBufferInterface* errorhnd_)
		:m_errorhnd(errorhnd_),m_tpi(strus::createTextProcessor( m_errorhnd))
	{
		if (!m_tpi.get()) throw std::runtime_error( std::string("failed to create text processor: ") + m_errorhnd->fetchError());
	}

	virtual ~AnalyzerObjectBuilder(){}

	virtual const strus::TextProcessorInterface* getTextProcessor() const
	{
		return m_tpi.get();
	}

	virtual strus::SegmenterInterface* createSegmenter( const std::string& segmenterName=std::string()) const
	{
		if (!segmenterName.empty())
		{
			m_errorhnd->report( "unknown document segmenter: %s", segmenterName.c_str());
			return 0;
		}
		strus::SegmenterInterface* rt = strus::createSegmenter_textwolf( m_errorhnd);
		if (!rt)
		{
			m_errorhnd->explain( "failed to create document segmenter: %s");
			return 0;
		}
		return rt;
	}

	virtual strus::DocumentAnalyzerInterface* createDocumentAnalyzer( const std::string& segmenterName=std::string()) const
	{
		strus::SegmenterInterface* segmenter = createSegmenter( segmenterName);
		if (!segmenter) 
		{
			m_errorhnd->explain( "failed to create segmenter: %s");
			return 0;
		}
		strus::DocumentAnalyzerInterface* rt = strus::createDocumentAnalyzer( segmenter, m_errorhnd);
		delete segmenter;
		if (!rt)
		{
			m_errorhnd->explain( "failed to create document analyzer: %s");
			return 0;
		}
		return rt;
	}

	virtual strus::QueryAnalyzerInterface* createQueryAnalyzer() const
	{
		strus::QueryAnalyzerInterface* rt = strus::createQueryAnalyzer( m_errorhnd);
		if (!rt) m_errorhnd->explain( "failed to create query analyzer: %s");
		return rt;
	}

private:
	ErrorBufferInterface* m_errorhnd;
	strus::Reference<strus::TextProcessorInterface> m_tpi;
};

}//namespace
#endif


