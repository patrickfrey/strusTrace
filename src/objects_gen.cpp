/*
* Copyright (c) 2016 Patrick P. Frey
*
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
/// \brief Identifiers for objects and methods for serialization
/// \note PROGRAM (strusTraceCodeGen) GENERATED FILE! DO NOT MODIFY!!!
/// \file objects_gen.cpp
#include "objects_gen.hpp"
#include "traceGlobalContext.hpp"
#include "traceSerializer.hpp"

using namespace strus;
using namespace strus::trace;
AclReaderImpl::~AclReaderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AclReader), AclReaderConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void AclReaderImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AclReader), AclReaderConst::methodName( Method_skipDoc), objid());
	obj()->skipDoc(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<std::string> AclReaderImpl::getReadAccessList() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AclReader), AclReaderConst::methodName( Method_getReadAccessList), objid());
	std::vector<std::string> p0 = obj()->getReadAccessList();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

AggregatorFunctionInstanceImpl::~AggregatorFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AggregatorFunctionInstance), AggregatorFunctionInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

NumericVariant AggregatorFunctionInstanceImpl::evaluate(
			const analyzer::Document& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AggregatorFunctionInstance), AggregatorFunctionInstanceConst::methodName( Method_evaluate), objid());
	NumericVariant p0 = obj()->evaluate(p1);
	TraceSerializer parambuf;
	if (!p0.defined())
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "evaluate");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packNumericVariant(p0);
		parambuf.packAnalyzerDocument(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* AggregatorFunctionInstanceImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AggregatorFunctionInstance), AggregatorFunctionInstanceConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView AggregatorFunctionInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AggregatorFunctionInstance), AggregatorFunctionInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

AggregatorFunctionImpl::~AggregatorFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AggregatorFunction), AggregatorFunctionConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

AggregatorFunctionInstanceInterface* AggregatorFunctionImpl::createInstance(
			const std::vector<std::string>& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AggregatorFunction), AggregatorFunctionConst::methodName( Method_createInstance), objid());
	AggregatorFunctionInstanceInterface* p0 = obj()->createInstance(p1);
	p0 = traceContext()->createInterfaceImpl<AggregatorFunctionInstanceInterface,AggregatorFunctionInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_AggregatorFunctionInstance), objbase_p0->objid());
		parambuf.packStringVector(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* AggregatorFunctionImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AggregatorFunction), AggregatorFunctionConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView AggregatorFunctionImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AggregatorFunction), AggregatorFunctionConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

AnalyzerObjectBuilderImpl::~AnalyzerObjectBuilderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

const TextProcessorInterface* AnalyzerObjectBuilderImpl::getTextProcessor() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_getTextProcessor), objid());
	const TextProcessorInterface* p0 = obj()->getTextProcessor();
	p0 = traceContext()->createInterfaceImpl_const<TextProcessorInterface,TextProcessorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getTextProcessor");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TextProcessor), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentAnalyzerInstanceInterface* AnalyzerObjectBuilderImpl::createDocumentAnalyzer(
			const SegmenterInterface* p1, 
			const analyzer::SegmenterOptions& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_createDocumentAnalyzer), objid());
	DocumentAnalyzerInstanceInterface* p0 = obj()->createDocumentAnalyzer(p1, p2);
	p0 = traceContext()->createInterfaceImpl<DocumentAnalyzerInstanceInterface,DocumentAnalyzerInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createDocumentAnalyzer");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Segmenter), objbase_p1->objid());
		parambuf.packAnalyzerSegmenterOptions(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PosTaggerInstanceInterface* AnalyzerObjectBuilderImpl::createPosTaggerInstance(
			const SegmenterInterface* p1, 
			const analyzer::SegmenterOptions& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_createPosTaggerInstance), objid());
	PosTaggerInstanceInterface* p0 = obj()->createPosTaggerInstance(p1, p2);
	p0 = traceContext()->createInterfaceImpl<PosTaggerInstanceInterface,PosTaggerInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createPosTaggerInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PosTaggerInstance), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Segmenter), objbase_p1->objid());
		parambuf.packAnalyzerSegmenterOptions(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

QueryAnalyzerInstanceInterface* AnalyzerObjectBuilderImpl::createQueryAnalyzer() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_createQueryAnalyzer), objid());
	QueryAnalyzerInstanceInterface* p0 = obj()->createQueryAnalyzer();
	p0 = traceContext()->createInterfaceImpl<QueryAnalyzerInstanceInterface,QueryAnalyzerInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createQueryAnalyzer");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_QueryAnalyzerInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentAnalyzerMapInterface* AnalyzerObjectBuilderImpl::createDocumentAnalyzerMap() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_createDocumentAnalyzerMap), objid());
	DocumentAnalyzerMapInterface* p0 = obj()->createDocumentAnalyzerMap();
	p0 = traceContext()->createInterfaceImpl<DocumentAnalyzerMapInterface,DocumentAnalyzerMapImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createDocumentAnalyzerMap");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentAnalyzerMap), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentClassDetectorInterface* AnalyzerObjectBuilderImpl::createDocumentClassDetector() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_createDocumentClassDetector), objid());
	DocumentClassDetectorInterface* p0 = obj()->createDocumentClassDetector();
	p0 = traceContext()->createInterfaceImpl<DocumentClassDetectorInterface,DocumentClassDetectorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createDocumentClassDetector");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentClassDetector), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ContentStatisticsInterface* AnalyzerObjectBuilderImpl::createContentStatistics() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_createContentStatistics), objid());
	ContentStatisticsInterface* p0 = obj()->createContentStatistics();
	p0 = traceContext()->createInterfaceImpl<ContentStatisticsInterface,ContentStatisticsImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createContentStatistics");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ContentStatistics), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

AttributeReaderImpl::~AttributeReaderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AttributeReader), AttributeReaderConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

Index AttributeReaderImpl::elementHandle(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AttributeReader), AttributeReaderConst::methodName( Method_elementHandle), objid());
	Index p0 = obj()->elementHandle(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void AttributeReaderImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AttributeReader), AttributeReaderConst::methodName( Method_skipDoc), objid());
	obj()->skipDoc(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::string AttributeReaderImpl::getValue(
			const Index& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AttributeReader), AttributeReaderConst::methodName( Method_getValue), objid());
	std::string p0 = obj()->getValue(p1);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> AttributeReaderImpl::getNames() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AttributeReader), AttributeReaderConst::methodName( Method_getNames), objid());
	std::vector<std::string> p0 = obj()->getNames();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ContentIteratorImpl::~ContentIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentIterator), ContentIteratorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool ContentIteratorImpl::getNext(
			const char*& expression, std::size_t& p1, 
			const char*& segment, std::size_t& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentIterator), ContentIteratorConst::methodName( Method_getNext), objid());
	bool p0 = obj()->getNext(expression, p1, segment, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packBuffer( expression, p1);
	parambuf.packBuffer( segment, p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ContentStatisticsContextImpl::~ContentStatisticsContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentStatisticsContext), ContentStatisticsContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void ContentStatisticsContextImpl::putContent(
			const std::string& p1, 
			const std::string& p2, 
			const analyzer::DocumentClass& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentStatisticsContext), ContentStatisticsContextConst::methodName( Method_putContent), objid());
	obj()->putContent(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packAnalyzerDocumentClass(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

analyzer::ContentStatisticsResult ContentStatisticsContextImpl::statistics()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentStatisticsContext), ContentStatisticsContextConst::methodName( Method_statistics), objid());
	analyzer::ContentStatisticsResult p0 = obj()->statistics();
	TraceSerializer parambuf;
	parambuf.packAnalyzerContentStatisticsResult(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

int ContentStatisticsContextImpl::nofDocuments() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentStatisticsContext), ContentStatisticsContextConst::methodName( Method_nofDocuments), objid());
	int p0 = obj()->nofDocuments();
	TraceSerializer parambuf;
	parambuf.packInt(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ContentStatisticsImpl::~ContentStatisticsImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentStatistics), ContentStatisticsConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void ContentStatisticsImpl::addLibraryElement(
			const std::string& p1, 
			const std::string& p2, 
			int p3, 
			int p4, 
			int p5, 
			TokenizerFunctionInstanceInterface* p6, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p7)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentStatistics), ContentStatisticsConst::methodName( Method_addLibraryElement), objid());
	obj()->addLibraryElement(p1, p2, p3, p4, p5, p6, p7);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packInt(p3);
	parambuf.packInt(p4);
	parambuf.packInt(p5);
	TraceObjectBase* objbase_p6 = dynamic_cast<TraceObjectBase*>( p6);
	if (!objbase_p6) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p6->objid());
	{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p7 = p7.begin(), e_p7 = p7.end();
	for (std::size_t idx_p7=0; i_p7 != e_p7; ++i_p7,++idx_p7)
	{
		parambuf.openIndex( idx_p7); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p7);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p6) {delete p6; p6 = 0;}
		{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p7 = p7.begin(), e_p7 = p7.end();
		for (std::size_t idx_p7=0; i_p7 != e_p7; ++i_p7,++idx_p7)
		{
			delete *i_p7;
		}}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void ContentStatisticsImpl::addVisibleAttribute(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentStatistics), ContentStatisticsConst::methodName( Method_addVisibleAttribute), objid());
	obj()->addVisibleAttribute(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void ContentStatisticsImpl::addSelectorExpression(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentStatistics), ContentStatisticsConst::methodName( Method_addSelectorExpression), objid());
	obj()->addSelectorExpression(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

ContentStatisticsContextInterface* ContentStatisticsImpl::createContext() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentStatistics), ContentStatisticsConst::methodName( Method_createContext), objid());
	ContentStatisticsContextInterface* p0 = obj()->createContext();
	p0 = traceContext()->createInterfaceImpl<ContentStatisticsContextInterface,ContentStatisticsContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createContext");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ContentStatisticsContext), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView ContentStatisticsImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ContentStatistics), ContentStatisticsConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseBackupCursorImpl::~DatabaseBackupCursorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseBackupCursor), DatabaseBackupCursorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool DatabaseBackupCursorImpl::fetch(
			const char*& key, std::size_t& p1, 
			const char*& blk, std::size_t& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseBackupCursor), DatabaseBackupCursorConst::methodName( Method_fetch), objid());
	bool p0 = obj()->fetch(key, p1, blk, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packBuffer( key, p1);
	parambuf.packBuffer( blk, p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseClientImpl::~DatabaseClientImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseClient), DatabaseClientConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

DatabaseTransactionInterface* DatabaseClientImpl::createTransaction()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseClient), DatabaseClientConst::methodName( Method_createTransaction), objid());
	DatabaseTransactionInterface* p0 = obj()->createTransaction();
	p0 = traceContext()->createInterfaceImpl<DatabaseTransactionInterface,DatabaseTransactionImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createTransaction");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DatabaseTransaction), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseCursorInterface* DatabaseClientImpl::createCursor(
			const DatabaseOptions& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseClient), DatabaseClientConst::methodName( Method_createCursor), objid());
	DatabaseCursorInterface* p0 = obj()->createCursor(p1);
	p0 = traceContext()->createInterfaceImpl<DatabaseCursorInterface,DatabaseCursorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createCursor");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DatabaseCursor), objbase_p0->objid());
		parambuf.packDatabaseOptions(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseBackupCursorInterface* DatabaseClientImpl::createBackupCursor() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseClient), DatabaseClientConst::methodName( Method_createBackupCursor), objid());
	DatabaseBackupCursorInterface* p0 = obj()->createBackupCursor();
	p0 = traceContext()->createInterfaceImpl<DatabaseBackupCursorInterface,DatabaseBackupCursorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createBackupCursor");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DatabaseBackupCursor), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void DatabaseClientImpl::writeImm(
			const char* key, std::size_t p1, 
			const char* value, std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseClient), DatabaseClientConst::methodName( Method_writeImm), objid());
	obj()->writeImm(key, p1, value, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packBuffer( key, p1);
	parambuf.packBuffer( value, p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DatabaseClientImpl::removeImm(
			const char* key, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseClient), DatabaseClientConst::methodName( Method_removeImm), objid());
	obj()->removeImm(key, p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packBuffer( key, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool DatabaseClientImpl::readValue(
			const char* key, std::size_t p1, 
			std::string& p2, 
			const DatabaseOptions& p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseClient), DatabaseClientConst::methodName( Method_readValue), objid());
	bool p0 = obj()->readValue(key, p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packBuffer( key, p1);
	parambuf.packString(p2);
	parambuf.packDatabaseOptions(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

long DatabaseClientImpl::diskUsage() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseClient), DatabaseClientConst::methodName( Method_diskUsage), objid());
	long p0 = obj()->diskUsage();
	TraceSerializer parambuf;
	parambuf.packInt64(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string DatabaseClientImpl::config() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseClient), DatabaseClientConst::methodName( Method_config), objid());
	std::string p0 = obj()->config();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool DatabaseClientImpl::compactDatabase()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseClient), DatabaseClientConst::methodName( Method_compactDatabase), objid());
	bool p0 = obj()->compactDatabase();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void DatabaseClientImpl::close()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseClient), DatabaseClientConst::methodName( Method_close), objid());
	obj()->close();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

DatabaseCursorImpl::~DatabaseCursorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

DatabaseCursorInterface::Slice DatabaseCursorImpl::seekUpperBound(
			const char* keystr, std::size_t p1, 
			std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_seekUpperBound), objid());
	DatabaseCursorInterface::Slice p0 = obj()->seekUpperBound(keystr, p1, p2);
	TraceSerializer parambuf;
	parambuf.packSlice(p0);
	parambuf.packBuffer( keystr, p1);
	parambuf.packSize( p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseCursorInterface::Slice DatabaseCursorImpl::seekUpperBoundRestricted(
			const char* keystr, std::size_t p1, 
			const char* upkey, std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_seekUpperBoundRestricted), objid());
	DatabaseCursorInterface::Slice p0 = obj()->seekUpperBoundRestricted(keystr, p1, upkey, p2);
	TraceSerializer parambuf;
	parambuf.packSlice(p0);
	parambuf.packBuffer( keystr, p1);
	parambuf.packBuffer( upkey, p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseCursorInterface::Slice DatabaseCursorImpl::seekFirst(
			const char* domainkey, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_seekFirst), objid());
	DatabaseCursorInterface::Slice p0 = obj()->seekFirst(domainkey, p1);
	TraceSerializer parambuf;
	parambuf.packSlice(p0);
	parambuf.packBuffer( domainkey, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseCursorInterface::Slice DatabaseCursorImpl::seekLast(
			const char* domainkey, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_seekLast), objid());
	DatabaseCursorInterface::Slice p0 = obj()->seekLast(domainkey, p1);
	TraceSerializer parambuf;
	parambuf.packSlice(p0);
	parambuf.packBuffer( domainkey, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseCursorInterface::Slice DatabaseCursorImpl::seekNext()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_seekNext), objid());
	DatabaseCursorInterface::Slice p0 = obj()->seekNext();
	TraceSerializer parambuf;
	parambuf.packSlice(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseCursorInterface::Slice DatabaseCursorImpl::seekPrev()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_seekPrev), objid());
	DatabaseCursorInterface::Slice p0 = obj()->seekPrev();
	TraceSerializer parambuf;
	parambuf.packSlice(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseCursorInterface::Slice DatabaseCursorImpl::key() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_key), objid());
	DatabaseCursorInterface::Slice p0 = obj()->key();
	TraceSerializer parambuf;
	parambuf.packSlice(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseCursorInterface::Slice DatabaseCursorImpl::value() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_value), objid());
	DatabaseCursorInterface::Slice p0 = obj()->value();
	TraceSerializer parambuf;
	parambuf.packSlice(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseImpl::~DatabaseImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Database), DatabaseConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool DatabaseImpl::exists(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Database), DatabaseConst::methodName( Method_exists), objid());
	bool p0 = obj()->exists(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseClientInterface* DatabaseImpl::createClient(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Database), DatabaseConst::methodName( Method_createClient), objid());
	DatabaseClientInterface* p0 = obj()->createClient(p1);
	p0 = traceContext()->createInterfaceImpl<DatabaseClientInterface,DatabaseClientImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createClient");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DatabaseClient), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool DatabaseImpl::createDatabase(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Database), DatabaseConst::methodName( Method_createDatabase), objid());
	bool p0 = obj()->createDatabase(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool DatabaseImpl::restoreDatabase(
			const std::string& p1, 
			DatabaseBackupCursorInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Database), DatabaseConst::methodName( Method_restoreDatabase), objid());
	bool p0 = obj()->restoreDatabase(p1, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DatabaseBackupCursor), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool DatabaseImpl::destroyDatabase(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Database), DatabaseConst::methodName( Method_destroyDatabase), objid());
	bool p0 = obj()->destroyDatabase(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* DatabaseImpl::getConfigDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Database), DatabaseConst::methodName( Method_getConfigDescription), objid());
	const char* p0 = obj()->getConfigDescription();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getConfigDescription");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char** DatabaseImpl::getConfigParameters() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Database), DatabaseConst::methodName( Method_getConfigParameters), objid());
	const char** p0 = obj()->getConfigParameters();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getConfigParameters");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharpp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseTransactionImpl::~DatabaseTransactionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseTransaction), DatabaseTransactionConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

DatabaseCursorInterface* DatabaseTransactionImpl::createCursor(
			const DatabaseOptions& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseTransaction), DatabaseTransactionConst::methodName( Method_createCursor), objid());
	DatabaseCursorInterface* p0 = obj()->createCursor(p1);
	p0 = traceContext()->createInterfaceImpl<DatabaseCursorInterface,DatabaseCursorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createCursor");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DatabaseCursor), objbase_p0->objid());
		parambuf.packDatabaseOptions(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void DatabaseTransactionImpl::write(
			const char* key, std::size_t p1, 
			const char* value, std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseTransaction), DatabaseTransactionConst::methodName( Method_write), objid());
	obj()->write(key, p1, value, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packBuffer( key, p1);
	parambuf.packBuffer( value, p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DatabaseTransactionImpl::remove(
			const char* key, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseTransaction), DatabaseTransactionConst::methodName( Method_remove), objid());
	obj()->remove(key, p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packBuffer( key, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DatabaseTransactionImpl::removeSubTree(
			const char* domainkey, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseTransaction), DatabaseTransactionConst::methodName( Method_removeSubTree), objid());
	obj()->removeSubTree(domainkey, p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packBuffer( domainkey, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool DatabaseTransactionImpl::commit()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseTransaction), DatabaseTransactionConst::methodName( Method_commit), objid());
	bool p0 = obj()->commit();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void DatabaseTransactionImpl::rollback()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseTransaction), DatabaseTransactionConst::methodName( Method_rollback), objid());
	obj()->rollback();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

DocumentAnalyzerContextImpl::~DocumentAnalyzerContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerContext), DocumentAnalyzerContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void DocumentAnalyzerContextImpl::putInput(
			const char* chunk, std::size_t p1, 
			bool p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerContext), DocumentAnalyzerContextConst::methodName( Method_putInput), objid());
	obj()->putInput(chunk, p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packBuffer( chunk, p1);
	parambuf.packBool(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool DocumentAnalyzerContextImpl::analyzeNext(
			analyzer::Document& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerContext), DocumentAnalyzerContextConst::methodName( Method_analyzeNext), objid());
	bool p0 = obj()->analyzeNext(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packAnalyzerDocument(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentAnalyzerInstanceImpl::~DocumentAnalyzerInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void DocumentAnalyzerInstanceImpl::addSearchIndexFeature(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			int p5, 
			const analyzer::FeatureOptions& p6)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_addSearchIndexFeature), objid());
	obj()->addSearchIndexFeature(p1, p2, p3, p4, p5, p6);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}}
	parambuf.packInt(p5);
	parambuf.packFeatureOptions(p6);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerInstanceImpl::addForwardIndexFeature(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			int p5, 
			const analyzer::FeatureOptions& p6)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_addForwardIndexFeature), objid());
	obj()->addForwardIndexFeature(p1, p2, p3, p4, p5, p6);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}}
	parambuf.packInt(p5);
	parambuf.packFeatureOptions(p6);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerInstanceImpl::addSearchIndexField(
			const std::string& p1, 
			const std::string& p2, 
			const std::string& p3, 
			const std::string& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_addSearchIndexField), objid());
	obj()->addSearchIndexField(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packString(p3);
	parambuf.packString(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerInstanceImpl::addSearchIndexStructure(
			const std::string& p1, 
			const std::string& p2, 
			const std::string& p3, 
			const StructureType& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_addSearchIndexStructure), objid());
	obj()->addSearchIndexStructure(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packString(p3);
	parambuf.packDocumentAnalyzerStructureType(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerInstanceImpl::defineMetaData(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_defineMetaData), objid());
	obj()->defineMetaData(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerInstanceImpl::defineAggregatedMetaData(
			const std::string& p1, 
			AggregatorFunctionInstanceInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_defineAggregatedMetaData), objid());
	obj()->defineAggregatedMetaData(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_AggregatorFunctionInstance), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerInstanceImpl::defineAttribute(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_defineAttribute), objid());
	obj()->defineAttribute(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerInstanceImpl::defineSubDocument(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_defineSubDocument), objid());
	obj()->defineSubDocument(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerInstanceImpl::defineSubContent(
			const std::string& p1, 
			const analyzer::DocumentClass& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_defineSubContent), objid());
	obj()->defineSubContent(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packAnalyzerDocumentClass(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

analyzer::Document DocumentAnalyzerInstanceImpl::analyze(
			const std::string& p1, 
			const analyzer::DocumentClass& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_analyze), objid());
	analyzer::Document p0 = obj()->analyze(p1, p2);
	TraceSerializer parambuf;
	parambuf.packAnalyzerDocument(p0);
	parambuf.packString(p1);
	parambuf.packAnalyzerDocumentClass(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentAnalyzerContextInterface* DocumentAnalyzerInstanceImpl::createContext(
			const analyzer::DocumentClass& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_createContext), objid());
	DocumentAnalyzerContextInterface* p0 = obj()->createContext(p1);
	p0 = traceContext()->createInterfaceImpl<DocumentAnalyzerContextInterface,DocumentAnalyzerContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createContext");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentAnalyzerContext), objbase_p0->objid());
		parambuf.packAnalyzerDocumentClass(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView DocumentAnalyzerInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), DocumentAnalyzerInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentAnalyzerMapImpl::~DocumentAnalyzerMapImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerMap), DocumentAnalyzerMapConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

DocumentAnalyzerInstanceInterface* DocumentAnalyzerMapImpl::createAnalyzer(
			const std::string& p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerMap), DocumentAnalyzerMapConst::methodName( Method_createAnalyzer), objid());
	DocumentAnalyzerInstanceInterface* p0 = obj()->createAnalyzer(p1, p2);
	p0 = traceContext()->createInterfaceImpl<DocumentAnalyzerInstanceInterface,DocumentAnalyzerInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createAnalyzer");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), objbase_p0->objid());
		parambuf.packString(p1);
		parambuf.packString(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void DocumentAnalyzerMapImpl::addAnalyzer(
			const std::string& p1, 
			const std::string& p2, 
			DocumentAnalyzerInstanceInterface* p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerMap), DocumentAnalyzerMapConst::methodName( Method_addAnalyzer), objid());
	obj()->addAnalyzer(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), objbase_p3->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

const DocumentAnalyzerInstanceInterface* DocumentAnalyzerMapImpl::getAnalyzer(
			const std::string& p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerMap), DocumentAnalyzerMapConst::methodName( Method_getAnalyzer), objid());
	const DocumentAnalyzerInstanceInterface* p0 = obj()->getAnalyzer(p1, p2);
	p0 = traceContext()->createInterfaceImpl_const<DocumentAnalyzerInstanceInterface,DocumentAnalyzerInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getAnalyzer");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentAnalyzerInstance), objbase_p0->objid());
		parambuf.packString(p1);
		parambuf.packString(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

analyzer::Document DocumentAnalyzerMapImpl::analyze(
			const std::string& p1, 
			const analyzer::DocumentClass& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerMap), DocumentAnalyzerMapConst::methodName( Method_analyze), objid());
	analyzer::Document p0 = obj()->analyze(p1, p2);
	TraceSerializer parambuf;
	parambuf.packAnalyzerDocument(p0);
	parambuf.packString(p1);
	parambuf.packAnalyzerDocumentClass(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentAnalyzerContextInterface* DocumentAnalyzerMapImpl::createContext(
			const analyzer::DocumentClass& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerMap), DocumentAnalyzerMapConst::methodName( Method_createContext), objid());
	DocumentAnalyzerContextInterface* p0 = obj()->createContext(p1);
	p0 = traceContext()->createInterfaceImpl<DocumentAnalyzerContextInterface,DocumentAnalyzerContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createContext");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentAnalyzerContext), objbase_p0->objid());
		parambuf.packAnalyzerDocumentClass(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView DocumentAnalyzerMapImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzerMap), DocumentAnalyzerMapConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentClassDetectorImpl::~DocumentClassDetectorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentClassDetector), DocumentClassDetectorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void DocumentClassDetectorImpl::defineDocumentSchemaDetector(
			const std::string& p1, 
			const std::string& p2, 
			const std::vector<std::string>& p3, 
			const std::vector<std::string>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentClassDetector), DocumentClassDetectorConst::methodName( Method_defineDocumentSchemaDetector), objid());
	obj()->defineDocumentSchemaDetector(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packStringVector(p3);
	parambuf.packStringVector(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool DocumentClassDetectorImpl::detect(
			analyzer::DocumentClass& p1, 
			const char* contentBegin, std::size_t p2, 
			bool p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentClassDetector), DocumentClassDetectorConst::methodName( Method_detect), objid());
	bool p0 = obj()->detect(p1, contentBegin, p2, p3);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packAnalyzerDocumentClass(p1);
	parambuf.packBuffer( contentBegin, p2);
	parambuf.packBool(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView DocumentClassDetectorImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentClassDetector), DocumentClassDetectorConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentTermIteratorImpl::~DocumentTermIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentTermIterator), DocumentTermIteratorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

Index DocumentTermIteratorImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentTermIterator), DocumentTermIteratorConst::methodName( Method_skipDoc), objid());
	Index p0 = obj()->skipDoc(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool DocumentTermIteratorImpl::nextTerm(
			Term& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentTermIterator), DocumentTermIteratorConst::methodName( Method_nextTerm), objid());
	bool p0 = obj()->nextTerm(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packDocumentTermIteratorTerm(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

int DocumentTermIteratorImpl::termDocumentFrequency(
			const Index& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentTermIterator), DocumentTermIteratorConst::methodName( Method_termDocumentFrequency), objid());
	int p0 = obj()->termDocumentFrequency(p1);
	TraceSerializer parambuf;
	parambuf.packInt(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string DocumentTermIteratorImpl::termValue(
			const Index& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentTermIterator), DocumentTermIteratorConst::methodName( Method_termValue), objid());
	std::string p0 = obj()->termValue(p1);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

FileLocatorImpl::~FileLocatorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_FileLocator), FileLocatorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void FileLocatorImpl::addResourcePath(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_FileLocator), FileLocatorConst::methodName( Method_addResourcePath), objid());
	obj()->addResourcePath(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::string FileLocatorImpl::getResourceFilePath(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_FileLocator), FileLocatorConst::methodName( Method_getResourceFilePath), objid());
	std::string p0 = obj()->getResourceFilePath(p1);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void FileLocatorImpl::defineWorkingDirectory(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_FileLocator), FileLocatorConst::methodName( Method_defineWorkingDirectory), objid());
	obj()->defineWorkingDirectory(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::string FileLocatorImpl::getWorkingDirectory() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_FileLocator), FileLocatorConst::methodName( Method_getWorkingDirectory), objid());
	std::string p0 = obj()->getWorkingDirectory();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> FileLocatorImpl::getResourcePaths() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_FileLocator), FileLocatorConst::methodName( Method_getResourcePaths), objid());
	std::vector<std::string> p0 = obj()->getResourcePaths();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ForwardIteratorImpl::~ForwardIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ForwardIterator), ForwardIteratorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void ForwardIteratorImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ForwardIterator), ForwardIteratorConst::methodName( Method_skipDoc), objid());
	obj()->skipDoc(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

Index ForwardIteratorImpl::skipPos(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ForwardIterator), ForwardIteratorConst::methodName( Method_skipPos), objid());
	Index p0 = obj()->skipPos(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string ForwardIteratorImpl::fetch()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ForwardIterator), ForwardIteratorConst::methodName( Method_fetch), objid());
	std::string p0 = obj()->fetch();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

InvAclIteratorImpl::~InvAclIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_InvAclIterator), InvAclIteratorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

Index InvAclIteratorImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_InvAclIterator), InvAclIteratorConst::methodName( Method_skipDoc), objid());
	Index p0 = obj()->skipDoc(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

MetaDataReaderImpl::~MetaDataReaderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataReader), MetaDataReaderConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

Index MetaDataReaderImpl::elementHandle(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataReader), MetaDataReaderConst::methodName( Method_elementHandle), objid());
	Index p0 = obj()->elementHandle(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index MetaDataReaderImpl::nofElements() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataReader), MetaDataReaderConst::methodName( Method_nofElements), objid());
	Index p0 = obj()->nofElements();
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void MetaDataReaderImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataReader), MetaDataReaderConst::methodName( Method_skipDoc), objid());
	obj()->skipDoc(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

NumericVariant MetaDataReaderImpl::getValue(
			const Index& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataReader), MetaDataReaderConst::methodName( Method_getValue), objid());
	NumericVariant p0 = obj()->getValue(p1);
	TraceSerializer parambuf;
	if (!p0.defined())
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getValue");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packNumericVariant(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* MetaDataReaderImpl::getType(
			const Index& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataReader), MetaDataReaderConst::methodName( Method_getType), objid());
	const char* p0 = obj()->getType(p1);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getType");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* MetaDataReaderImpl::getName(
			const Index& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataReader), MetaDataReaderConst::methodName( Method_getName), objid());
	const char* p0 = obj()->getName(p1);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getName");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> MetaDataReaderImpl::getNames() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataReader), MetaDataReaderConst::methodName( Method_getNames), objid());
	std::vector<std::string> p0 = obj()->getNames();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

MetaDataRestrictionInstanceImpl::~MetaDataRestrictionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataRestrictionInstance), MetaDataRestrictionInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool MetaDataRestrictionInstanceImpl::match(
			const Index& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataRestrictionInstance), MetaDataRestrictionInstanceConst::methodName( Method_match), objid());
	bool p0 = obj()->match(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

MetaDataRestrictionImpl::~MetaDataRestrictionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataRestriction), MetaDataRestrictionConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void MetaDataRestrictionImpl::addCondition(
			const CompareOperator& p1, 
			const std::string& p2, 
			const NumericVariant& p3, 
			bool p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataRestriction), MetaDataRestrictionConst::methodName( Method_addCondition), objid());
	obj()->addCondition(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packMetaDataRestrictionCompareOperator(p1);
	parambuf.packString(p2);
	parambuf.packNumericVariant(p3);
	parambuf.packBool(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

MetaDataRestrictionInstanceInterface* MetaDataRestrictionImpl::createInstance() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataRestriction), MetaDataRestrictionConst::methodName( Method_createInstance), objid());
	MetaDataRestrictionInstanceInterface* p0 = obj()->createInstance();
	p0 = traceContext()->createInterfaceImpl<MetaDataRestrictionInstanceInterface,MetaDataRestrictionInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_MetaDataRestrictionInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string MetaDataRestrictionImpl::tostring() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataRestriction), MetaDataRestrictionConst::methodName( Method_tostring), objid());
	std::string p0 = obj()->tostring();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

NormalizerFunctionInstanceImpl::~NormalizerFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), NormalizerFunctionInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::string NormalizerFunctionInstanceImpl::normalize(
			const char* src, std::size_t p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), NormalizerFunctionInstanceConst::methodName( Method_normalize), objid());
	std::string p0 = obj()->normalize(src, p1);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packBuffer( src, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* NormalizerFunctionInstanceImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), NormalizerFunctionInstanceConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView NormalizerFunctionInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), NormalizerFunctionInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

NormalizerFunctionImpl::~NormalizerFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunction), NormalizerFunctionConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

NormalizerFunctionInstanceInterface* NormalizerFunctionImpl::createInstance(
			const std::vector<std::string>& p1, 
			const TextProcessorInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunction), NormalizerFunctionConst::methodName( Method_createInstance), objid());
	NormalizerFunctionInstanceInterface* p0 = obj()->createInstance(p1, p2);
	p0 = traceContext()->createInterfaceImpl<NormalizerFunctionInstanceInterface,NormalizerFunctionInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase_p0->objid());
		parambuf.packStringVector(p1);
		const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TextProcessor), objbase_p2->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* NormalizerFunctionImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunction), NormalizerFunctionConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView NormalizerFunctionImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunction), NormalizerFunctionConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternLexerContextImpl::~PatternLexerContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerContext), PatternLexerContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::vector<analyzer::PatternLexem> PatternLexerContextImpl::match(
			const char* src, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerContext), PatternLexerContextConst::methodName( Method_match), objid());
	std::vector<analyzer::PatternLexem> p0 = obj()->match(src, p1);
	TraceSerializer parambuf;
	parambuf.packAnalyzerPatternLexemVector(p0);
	parambuf.packBuffer( src, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void PatternLexerContextImpl::reset()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerContext), PatternLexerContextConst::methodName( Method_reset), objid());
	obj()->reset();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

PatternLexerInstanceImpl::~PatternLexerInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void PatternLexerInstanceImpl::defineOption(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_defineOption), objid());
	obj()->defineOption(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packDouble(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternLexerInstanceImpl::defineLexemName(
			unsigned int p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_defineLexemName), objid());
	obj()->defineLexemName(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packUInt(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternLexerInstanceImpl::defineLexem(
			unsigned int p1, 
			const std::string& p2, 
			unsigned int p3, 
			unsigned int p4, 
			analyzer::PositionBind p5)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_defineLexem), objid());
	obj()->defineLexem(p1, p2, p3, p4, p5);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packUInt(p1);
	parambuf.packString(p2);
	parambuf.packUInt(p3);
	parambuf.packUInt(p4);
	parambuf.packAnalyzerPositionBind(p5);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternLexerInstanceImpl::defineSymbol(
			unsigned int p1, 
			unsigned int p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_defineSymbol), objid());
	obj()->defineSymbol(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packUInt(p1);
	parambuf.packUInt(p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

unsigned int PatternLexerInstanceImpl::getSymbol(
			unsigned int p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_getSymbol), objid());
	unsigned int p0 = obj()->getSymbol(p1, p2);
	TraceSerializer parambuf;
	parambuf.packUInt(p0);
	parambuf.packUInt(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* PatternLexerInstanceImpl::getLexemName(
			unsigned int p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_getLexemName), objid());
	const char* p0 = obj()->getLexemName(p1);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getLexemName");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
		parambuf.packUInt(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool PatternLexerInstanceImpl::compile()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_compile), objid());
	bool p0 = obj()->compile();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternLexerContextInterface* PatternLexerInstanceImpl::createContext() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_createContext), objid());
	PatternLexerContextInterface* p0 = obj()->createContext();
	p0 = traceContext()->createInterfaceImpl<PatternLexerContextInterface,PatternLexerContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createContext");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternLexerContext), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* PatternLexerInstanceImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView PatternLexerInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternLexerImpl::~PatternLexerImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexer), PatternLexerConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::vector<std::string> PatternLexerImpl::getCompileOptionNames() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexer), PatternLexerConst::methodName( Method_getCompileOptionNames), objid());
	std::vector<std::string> p0 = obj()->getCompileOptionNames();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternLexerInstanceInterface* PatternLexerImpl::createInstance() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexer), PatternLexerConst::methodName( Method_createInstance), objid());
	PatternLexerInstanceInterface* p0 = obj()->createInstance();
	p0 = traceContext()->createInterfaceImpl<PatternLexerInstanceInterface,PatternLexerInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternLexerInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* PatternLexerImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexer), PatternLexerConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView PatternLexerImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexer), PatternLexerConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternMatcherContextImpl::~PatternMatcherContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherContext), PatternMatcherContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void PatternMatcherContextImpl::putInput(
			const analyzer::PatternLexem& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherContext), PatternMatcherContextConst::methodName( Method_putInput), objid());
	obj()->putInput(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packAnalyzerPatternLexem(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<analyzer::PatternMatcherResult> PatternMatcherContextImpl::fetchResults()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherContext), PatternMatcherContextConst::methodName( Method_fetchResults), objid());
	std::vector<analyzer::PatternMatcherResult> p0 = obj()->fetchResults();
	TraceSerializer parambuf;
	parambuf.packAnalyzerPatternMatcherResultVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

analyzer::PatternMatcherStatistics PatternMatcherContextImpl::getStatistics() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherContext), PatternMatcherContextConst::methodName( Method_getStatistics), objid());
	analyzer::PatternMatcherStatistics p0 = obj()->getStatistics();
	TraceSerializer parambuf;
	parambuf.packAnalyzerPatternMatcherStatistics(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void PatternMatcherContextImpl::reset()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherContext), PatternMatcherContextConst::methodName( Method_reset), objid());
	obj()->reset();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

PatternMatcherInstanceImpl::~PatternMatcherInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void PatternMatcherInstanceImpl::defineOption(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_defineOption), objid());
	obj()->defineOption(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packDouble(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternMatcherInstanceImpl::defineTermFrequency(
			unsigned int p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_defineTermFrequency), objid());
	obj()->defineTermFrequency(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packUInt(p1);
	parambuf.packDouble(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternMatcherInstanceImpl::pushTerm(
			unsigned int p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_pushTerm), objid());
	obj()->pushTerm(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packUInt(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternMatcherInstanceImpl::pushExpression(
			JoinOperation p1, 
			std::size_t p2, 
			unsigned int p3, 
			unsigned int p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_pushExpression), objid());
	obj()->pushExpression(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packPatternMatcherJoinOperation(p1);
	parambuf.packSize( p2);
	parambuf.packUInt(p3);
	parambuf.packUInt(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternMatcherInstanceImpl::pushPattern(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_pushPattern), objid());
	obj()->pushPattern(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternMatcherInstanceImpl::attachVariable(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_attachVariable), objid());
	obj()->attachVariable(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternMatcherInstanceImpl::definePattern(
			const std::string& p1, 
			const std::string& p2, 
			bool p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_definePattern), objid());
	obj()->definePattern(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packBool(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool PatternMatcherInstanceImpl::compile()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_compile), objid());
	bool p0 = obj()->compile();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternMatcherContextInterface* PatternMatcherInstanceImpl::createContext() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_createContext), objid());
	PatternMatcherContextInterface* p0 = obj()->createContext();
	p0 = traceContext()->createInterfaceImpl<PatternMatcherContextInterface,PatternMatcherContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createContext");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternMatcherContext), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* PatternMatcherInstanceImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView PatternMatcherInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternMatcherImpl::~PatternMatcherImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcher), PatternMatcherConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::vector<std::string> PatternMatcherImpl::getCompileOptionNames() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcher), PatternMatcherConst::methodName( Method_getCompileOptionNames), objid());
	std::vector<std::string> p0 = obj()->getCompileOptionNames();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternMatcherInstanceInterface* PatternMatcherImpl::createInstance() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcher), PatternMatcherConst::methodName( Method_createInstance), objid());
	PatternMatcherInstanceInterface* p0 = obj()->createInstance();
	p0 = traceContext()->createInterfaceImpl<PatternMatcherInstanceInterface,PatternMatcherInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternMatcherInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* PatternMatcherImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcher), PatternMatcherConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView PatternMatcherImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcher), PatternMatcherConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternTermFeederInstanceImpl::~PatternTermFeederInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), PatternTermFeederInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void PatternTermFeederInstanceImpl::defineLexem(
			unsigned int p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), PatternTermFeederInstanceConst::methodName( Method_defineLexem), objid());
	obj()->defineLexem(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packUInt(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternTermFeederInstanceImpl::defineSymbol(
			unsigned int p1, 
			unsigned int p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), PatternTermFeederInstanceConst::methodName( Method_defineSymbol), objid());
	obj()->defineSymbol(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packUInt(p1);
	parambuf.packUInt(p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

unsigned int PatternTermFeederInstanceImpl::getLexem(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), PatternTermFeederInstanceConst::methodName( Method_getLexem), objid());
	unsigned int p0 = obj()->getLexem(p1);
	TraceSerializer parambuf;
	parambuf.packUInt(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> PatternTermFeederInstanceImpl::lexemTypes() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), PatternTermFeederInstanceConst::methodName( Method_lexemTypes), objid());
	std::vector<std::string> p0 = obj()->lexemTypes();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

unsigned int PatternTermFeederInstanceImpl::getSymbol(
			unsigned int p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), PatternTermFeederInstanceConst::methodName( Method_getSymbol), objid());
	unsigned int p0 = obj()->getSymbol(p1, p2);
	TraceSerializer parambuf;
	parambuf.packUInt(p0);
	parambuf.packUInt(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* PatternTermFeederInstanceImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), PatternTermFeederInstanceConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView PatternTermFeederInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), PatternTermFeederInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternTermFeederImpl::~PatternTermFeederImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeeder), PatternTermFeederConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

PatternTermFeederInstanceInterface* PatternTermFeederImpl::createInstance() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeeder), PatternTermFeederConst::methodName( Method_createInstance), objid());
	PatternTermFeederInstanceInterface* p0 = obj()->createInstance();
	p0 = traceContext()->createInterfaceImpl<PatternTermFeederInstanceInterface,PatternTermFeederInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* PatternTermFeederImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeeder), PatternTermFeederConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView PatternTermFeederImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternTermFeeder), PatternTermFeederConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PosTaggerContextImpl::~PosTaggerContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTaggerContext), PosTaggerContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::string PosTaggerContextImpl::markupDocument(
			int p1, 
			const analyzer::DocumentClass& p2, 
			const std::string& p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTaggerContext), PosTaggerContextConst::methodName( Method_markupDocument), objid());
	std::string p0 = obj()->markupDocument(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packInt(p1);
	parambuf.packAnalyzerDocumentClass(p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PosTaggerDataImpl::~PosTaggerDataImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTaggerData), PosTaggerDataConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void PosTaggerDataImpl::declareIgnoredToken(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTaggerData), PosTaggerDataConst::methodName( Method_declareIgnoredToken), objid());
	obj()->declareIgnoredToken(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PosTaggerDataImpl::insert(
			int p1, 
			const std::vector<Element>& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTaggerData), PosTaggerDataConst::methodName( Method_insert), objid());
	obj()->insert(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packInt(p1);
	parambuf.packPosTaggerDataElementVector(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PosTaggerDataImpl::markupSegment(
			TokenMarkupContextInterface* p1, 
			int p2, 
			int& p3, 
			const SegmenterPosition& p4, 
			const char* segmentptr, std::size_t p5) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTaggerData), PosTaggerDataConst::methodName( Method_markupSegment), objid());
	obj()->markupSegment(p1, p2, p3, p4, segmentptr, p5);
	TraceSerializer parambuf;
	parambuf.packVoid();
	TraceObjectBase* objbase_p1 = dynamic_cast<TraceObjectBase*>( p1);
	if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenMarkupContext), objbase_p1->objid());
	parambuf.packInt(p2);
	parambuf.packInt(p3);
	parambuf.packGlobalCounter(p4);
	parambuf.packBuffer( segmentptr, p5);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p1) {delete p1; p1 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

PosTaggerInstanceImpl::~PosTaggerInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTaggerInstance), PosTaggerInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void PosTaggerInstanceImpl::addContentExpression(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTaggerInstance), PosTaggerInstanceConst::methodName( Method_addContentExpression), objid());
	obj()->addContentExpression(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PosTaggerInstanceImpl::addPosTaggerInputPunctuation(
			const std::string& p1, 
			const std::string& p2, 
			int p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTaggerInstance), PosTaggerInstanceConst::methodName( Method_addPosTaggerInputPunctuation), objid());
	obj()->addPosTaggerInputPunctuation(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packInt(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::string PosTaggerInstanceImpl::getPosTaggerInput(
			const analyzer::DocumentClass& p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTaggerInstance), PosTaggerInstanceConst::methodName( Method_getPosTaggerInput), objid());
	std::string p0 = obj()->getPosTaggerInput(p1, p2);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packAnalyzerDocumentClass(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string PosTaggerInstanceImpl::markupDocument(
			const PosTaggerDataInterface* p1, 
			int p2, 
			const analyzer::DocumentClass& p3, 
			const std::string& p4) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTaggerInstance), PosTaggerInstanceConst::methodName( Method_markupDocument), objid());
	std::string p0 = obj()->markupDocument(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
	if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PosTaggerData), objbase_p1->objid());
	parambuf.packInt(p2);
	parambuf.packAnalyzerDocumentClass(p3);
	parambuf.packString(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PosTaggerImpl::~PosTaggerImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTagger), PosTaggerConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

PosTaggerInstanceInterface* PosTaggerImpl::createInstance(
			const SegmenterInterface* p1, 
			const analyzer::SegmenterOptions& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PosTagger), PosTaggerConst::methodName( Method_createInstance), objid());
	PosTaggerInstanceInterface* p0 = obj()->createInstance(p1, p2);
	p0 = traceContext()->createInterfaceImpl<PosTaggerInstanceInterface,PosTaggerInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PosTaggerInstance), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Segmenter), objbase_p1->objid());
		parambuf.packAnalyzerSegmenterOptions(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PostingIteratorImpl::~PostingIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

Index PostingIteratorImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_skipDoc), objid());
	Index p0 = obj()->skipDoc(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index PostingIteratorImpl::skipDocCandidate(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_skipDocCandidate), objid());
	Index p0 = obj()->skipDocCandidate(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index PostingIteratorImpl::skipPos(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_skipPos), objid());
	Index p0 = obj()->skipPos(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* PostingIteratorImpl::featureid() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_featureid), objid());
	const char* p0 = obj()->featureid();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "featureid");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

GlobalCounter PostingIteratorImpl::documentFrequency() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_documentFrequency), objid());
	GlobalCounter p0 = obj()->documentFrequency();
	TraceSerializer parambuf;
	parambuf.packGlobalCounter(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

int PostingIteratorImpl::frequency()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_frequency), objid());
	int p0 = obj()->frequency();
	TraceSerializer parambuf;
	parambuf.packInt(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index PostingIteratorImpl::docno() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_docno), objid());
	Index p0 = obj()->docno();
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index PostingIteratorImpl::posno() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_posno), objid());
	Index p0 = obj()->posno();
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index PostingIteratorImpl::length() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_length), objid());
	Index p0 = obj()->length();
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PostingJoinOperatorImpl::~PostingJoinOperatorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingJoinOperator), PostingJoinOperatorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

PostingIteratorInterface* PostingJoinOperatorImpl::createResultIterator(
			const std::vector<Reference<PostingIteratorInterface> >& p1, 
			int p2, 
			unsigned int p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingJoinOperator), PostingJoinOperatorConst::methodName( Method_createResultIterator), objid());
	PostingIteratorInterface* p0 = obj()->createResultIterator(p1, p2, p3);
	p0 = traceContext()->createInterfaceImpl<PostingIteratorInterface,PostingIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createResultIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase_p0->objid());
		{std::vector<Reference<PostingIteratorInterface> >::const_iterator
			i_p1 = p1.begin(), e_p1 = p1.end();
		for (std::size_t idx_p1=0; i_p1 != e_p1; ++i_p1,++idx_p1)
		{
			parambuf.openIndex( idx_p1); 
			const TraceObjectBase* objbase = dynamic_cast<const TraceObjectBase*>( i_p1->get());
			if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase->objid());
			parambuf.close();
		}}
		parambuf.packInt(p2);
		parambuf.packUInt(p3);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* PostingJoinOperatorImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingJoinOperator), PostingJoinOperatorConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView PostingJoinOperatorImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingJoinOperator), PostingJoinOperatorConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

QueryAnalyzerContextImpl::~QueryAnalyzerContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerContext), QueryAnalyzerContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void QueryAnalyzerContextImpl::putField(
			int p1, 
			const std::string& p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerContext), QueryAnalyzerContextConst::methodName( Method_putField), objid());
	obj()->putField(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packInt(p1);
	parambuf.packString(p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryAnalyzerContextImpl::groupElements(
			int p1, 
			const std::vector<int>& p2, 
			const GroupBy& p3, 
			bool p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerContext), QueryAnalyzerContextConst::methodName( Method_groupElements), objid());
	obj()->groupElements(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packInt(p1);
	parambuf.packIntVector(p2);
	parambuf.packAnalyzerQueryGroupBy(p3);
	parambuf.packBool(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

analyzer::QueryTermExpression QueryAnalyzerContextImpl::analyze()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerContext), QueryAnalyzerContextConst::methodName( Method_analyze), objid());
	analyzer::QueryTermExpression p0 = obj()->analyze();
	TraceSerializer parambuf;
	parambuf.packAnalyzerQueryTermExpression(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

QueryAnalyzerInstanceImpl::~QueryAnalyzerInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerInstance), QueryAnalyzerInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void QueryAnalyzerInstanceImpl::addElement(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			int p5)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerInstance), QueryAnalyzerInstanceConst::methodName( Method_addElement), objid());
	obj()->addElement(p1, p2, p3, p4, p5);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}}
	parambuf.packInt(p5);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		{std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<std::string> QueryAnalyzerInstanceImpl::queryTermTypes() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerInstance), QueryAnalyzerInstanceConst::methodName( Method_queryTermTypes), objid());
	std::vector<std::string> p0 = obj()->queryTermTypes();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> QueryAnalyzerInstanceImpl::queryFieldTypes() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerInstance), QueryAnalyzerInstanceConst::methodName( Method_queryFieldTypes), objid());
	std::vector<std::string> p0 = obj()->queryFieldTypes();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

QueryAnalyzerContextInterface* QueryAnalyzerInstanceImpl::createContext() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerInstance), QueryAnalyzerInstanceConst::methodName( Method_createContext), objid());
	QueryAnalyzerContextInterface* p0 = obj()->createContext();
	p0 = traceContext()->createInterfaceImpl<QueryAnalyzerContextInterface,QueryAnalyzerContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createContext");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_QueryAnalyzerContext), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView QueryAnalyzerInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerInstance), QueryAnalyzerInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

QueryEvalImpl::~QueryEvalImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void QueryEvalImpl::addTerm(
			const std::string& p1, 
			const std::string& p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_addTerm), objid());
	obj()->addTerm(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryEvalImpl::addSelectionFeature(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_addSelectionFeature), objid());
	obj()->addSelectionFeature(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryEvalImpl::addRestrictionFeature(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_addRestrictionFeature), objid());
	obj()->addRestrictionFeature(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryEvalImpl::addExclusionFeature(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_addExclusionFeature), objid());
	obj()->addExclusionFeature(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<std::string> QueryEvalImpl::getWeightingFeatureSets() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_getWeightingFeatureSets), objid());
	std::vector<std::string> p0 = obj()->getWeightingFeatureSets();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> QueryEvalImpl::getSelectionFeatureSets() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_getSelectionFeatureSets), objid());
	std::vector<std::string> p0 = obj()->getSelectionFeatureSets();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> QueryEvalImpl::getRestrictionFeatureSets() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_getRestrictionFeatureSets), objid());
	std::vector<std::string> p0 = obj()->getRestrictionFeatureSets();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> QueryEvalImpl::getExclusionFeatureSets() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_getExclusionFeatureSets), objid());
	std::vector<std::string> p0 = obj()->getExclusionFeatureSets();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void QueryEvalImpl::addSummarizerFunction(
			const std::string& p1, 
			SummarizerFunctionInstanceInterface* p2, 
			const std::vector<FeatureParameter>& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_addSummarizerFunction), objid());
	obj()->addSummarizerFunction(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), objbase_p2->objid());
	parambuf.packFeatureParameterVector(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryEvalImpl::addWeightingFunction(
			WeightingFunctionInstanceInterface* p1, 
			const std::vector<FeatureParameter>& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_addWeightingFunction), objid());
	obj()->addWeightingFunction(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	TraceObjectBase* objbase_p1 = dynamic_cast<TraceObjectBase*>( p1);
	if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), objbase_p1->objid());
	parambuf.packFeatureParameterVector(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p1) {delete p1; p1 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryEvalImpl::defineWeightingFormula(
			ScalarFunctionInterface* p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_defineWeightingFormula), objid());
	obj()->defineWeightingFormula(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	TraceObjectBase* objbase_p1 = dynamic_cast<TraceObjectBase*>( p1);
	if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ScalarFunction), objbase_p1->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p1) {delete p1; p1 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryEvalImpl::usePositionInformation(
			const std::string& p1, 
			bool p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_usePositionInformation), objid());
	obj()->usePositionInformation(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packBool(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

QueryInterface* QueryEvalImpl::createQuery(
			const StorageClientInterface* p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_createQuery), objid());
	QueryInterface* p0 = obj()->createQuery(p1);
	p0 = traceContext()->createInterfaceImpl<QueryInterface,QueryImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createQuery");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Query), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageClient), objbase_p1->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView QueryEvalImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

QueryImpl::~QueryImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void QueryImpl::defineTermStatistics(
			const std::string& p1, 
			const std::string& p2, 
			const TermStatistics& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_defineTermStatistics), objid());
	obj()->defineTermStatistics(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packTermStatistics(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::defineGlobalStatistics(
			const GlobalStatistics& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_defineGlobalStatistics), objid());
	obj()->defineGlobalStatistics(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packGlobalStatistics(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::pushTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_pushTerm), objid());
	obj()->pushTerm(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packIndex(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::pushExpression(
			const PostingJoinOperatorInterface* p1, 
			unsigned int p2, 
			int p3, 
			unsigned int p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_pushExpression), objid());
	obj()->pushExpression(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
	if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingJoinOperator), objbase_p1->objid());
	parambuf.packUInt(p2);
	parambuf.packInt(p3);
	parambuf.packUInt(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::attachVariable(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_attachVariable), objid());
	obj()->attachVariable(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::defineFeature(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_defineFeature), objid());
	obj()->defineFeature(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packDouble(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::addMetaDataRestrictionCondition(
			const MetaDataRestrictionInterface::CompareOperator& p1, 
			const std::string& p2, 
			const NumericVariant& p3, 
			bool p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_addMetaDataRestrictionCondition), objid());
	obj()->addMetaDataRestrictionCondition(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packMetaDataRestrictionCompareOperator(p1);
	parambuf.packString(p2);
	parambuf.packNumericVariant(p3);
	parambuf.packBool(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::addDocumentEvaluationSet(
			const std::vector<Index>& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_addDocumentEvaluationSet), objid());
	obj()->addDocumentEvaluationSet(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packIndexVector(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::addAccess(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_addAccess), objid());
	obj()->addAccess(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::setWeightingVariableValue(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_setWeightingVariableValue), objid());
	obj()->setWeightingVariableValue(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packDouble(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

QueryResult QueryImpl::evaluate(
			int p1, 
			int p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_evaluate), objid());
	QueryResult p0 = obj()->evaluate(p1, p2);
	TraceSerializer parambuf;
	parambuf.packQueryResult(p0);
	parambuf.packInt(p1);
	parambuf.packInt(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView QueryImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

QueryProcessorImpl::~QueryProcessorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryProcessor), QueryProcessorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::string QueryProcessorImpl::getResourceFilePath(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryProcessor), QueryProcessorConst::methodName( Method_getResourceFilePath), objid());
	std::string p0 = obj()->getResourceFilePath(p1);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void QueryProcessorImpl::definePostingJoinOperator(
			const std::string& p1, 
			PostingJoinOperatorInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryProcessor), QueryProcessorConst::methodName( Method_definePostingJoinOperator), objid());
	obj()->definePostingJoinOperator(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingJoinOperator), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

const PostingJoinOperatorInterface* QueryProcessorImpl::getPostingJoinOperator(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryProcessor), QueryProcessorConst::methodName( Method_getPostingJoinOperator), objid());
	const PostingJoinOperatorInterface* p0 = obj()->getPostingJoinOperator(p1);
	p0 = traceContext()->createInterfaceImpl_const<PostingJoinOperatorInterface,PostingJoinOperatorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getPostingJoinOperator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingJoinOperator), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void QueryProcessorImpl::defineWeightingFunction(
			const std::string& p1, 
			WeightingFunctionInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryProcessor), QueryProcessorConst::methodName( Method_defineWeightingFunction), objid());
	obj()->defineWeightingFunction(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_WeightingFunction), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

const WeightingFunctionInterface* QueryProcessorImpl::getWeightingFunction(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryProcessor), QueryProcessorConst::methodName( Method_getWeightingFunction), objid());
	const WeightingFunctionInterface* p0 = obj()->getWeightingFunction(p1);
	p0 = traceContext()->createInterfaceImpl_const<WeightingFunctionInterface,WeightingFunctionImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getWeightingFunction");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_WeightingFunction), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void QueryProcessorImpl::defineSummarizerFunction(
			const std::string& p1, 
			SummarizerFunctionInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryProcessor), QueryProcessorConst::methodName( Method_defineSummarizerFunction), objid());
	obj()->defineSummarizerFunction(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SummarizerFunction), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

const SummarizerFunctionInterface* QueryProcessorImpl::getSummarizerFunction(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryProcessor), QueryProcessorConst::methodName( Method_getSummarizerFunction), objid());
	const SummarizerFunctionInterface* p0 = obj()->getSummarizerFunction(p1);
	p0 = traceContext()->createInterfaceImpl_const<SummarizerFunctionInterface,SummarizerFunctionImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getSummarizerFunction");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SummarizerFunction), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> QueryProcessorImpl::getFunctionList(
			const FunctionType& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryProcessor), QueryProcessorConst::methodName( Method_getFunctionList), objid());
	std::vector<std::string> p0 = obj()->getFunctionList(p1);
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	parambuf.packQueryProcessorFunctionType(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void QueryProcessorImpl::defineScalarFunctionParser(
			const std::string& p1, 
			ScalarFunctionParserInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryProcessor), QueryProcessorConst::methodName( Method_defineScalarFunctionParser), objid());
	obj()->defineScalarFunctionParser(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ScalarFunctionParser), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

const ScalarFunctionParserInterface* QueryProcessorImpl::getScalarFunctionParser(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryProcessor), QueryProcessorConst::methodName( Method_getScalarFunctionParser), objid());
	const ScalarFunctionParserInterface* p0 = obj()->getScalarFunctionParser(p1);
	p0 = traceContext()->createInterfaceImpl_const<ScalarFunctionParserInterface,ScalarFunctionParserImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getScalarFunctionParser");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ScalarFunctionParser), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ScalarFunctionInstanceImpl::~ScalarFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunctionInstance), ScalarFunctionInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void ScalarFunctionInstanceImpl::setVariableValue(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunctionInstance), ScalarFunctionInstanceConst::methodName( Method_setVariableValue), objid());
	obj()->setVariableValue(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packDouble(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

double ScalarFunctionInstanceImpl::call(
			const double* args, unsigned int p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunctionInstance), ScalarFunctionInstanceConst::methodName( Method_call), objid());
	double p0 = obj()->call(args, p1);
	TraceSerializer parambuf;
	parambuf.packDouble(p0);
	parambuf.packBufferFloat( args, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* ScalarFunctionInstanceImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunctionInstance), ScalarFunctionInstanceConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView ScalarFunctionInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunctionInstance), ScalarFunctionInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ScalarFunctionImpl::~ScalarFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunction), ScalarFunctionConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::vector<std::string> ScalarFunctionImpl::getVariables() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunction), ScalarFunctionConst::methodName( Method_getVariables), objid());
	std::vector<std::string> p0 = obj()->getVariables();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

unsigned int ScalarFunctionImpl::getNofArguments() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunction), ScalarFunctionConst::methodName( Method_getNofArguments), objid());
	unsigned int p0 = obj()->getNofArguments();
	TraceSerializer parambuf;
	parambuf.packUInt(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void ScalarFunctionImpl::setDefaultVariableValue(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunction), ScalarFunctionConst::methodName( Method_setDefaultVariableValue), objid());
	obj()->setDefaultVariableValue(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packDouble(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

ScalarFunctionInstanceInterface* ScalarFunctionImpl::createInstance() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunction), ScalarFunctionConst::methodName( Method_createInstance), objid());
	ScalarFunctionInstanceInterface* p0 = obj()->createInstance();
	p0 = traceContext()->createInterfaceImpl<ScalarFunctionInstanceInterface,ScalarFunctionInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ScalarFunctionInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* ScalarFunctionImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunction), ScalarFunctionConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView ScalarFunctionImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunction), ScalarFunctionConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ScalarFunctionParserImpl::~ScalarFunctionParserImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunctionParser), ScalarFunctionParserConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

ScalarFunctionInterface* ScalarFunctionParserImpl::createFunction(
			const std::string& p1, 
			const std::vector<std::string>& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunctionParser), ScalarFunctionParserConst::methodName( Method_createFunction), objid());
	ScalarFunctionInterface* p0 = obj()->createFunction(p1, p2);
	p0 = traceContext()->createInterfaceImpl<ScalarFunctionInterface,ScalarFunctionImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createFunction");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ScalarFunction), objbase_p0->objid());
		parambuf.packString(p1);
		parambuf.packStringVector(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView ScalarFunctionParserImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunctionParser), ScalarFunctionParserConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SegmenterContextImpl::~SegmenterContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterContext), SegmenterContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void SegmenterContextImpl::putInput(
			const char* chunk, std::size_t p1, 
			bool p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterContext), SegmenterContextConst::methodName( Method_putInput), objid());
	obj()->putInput(chunk, p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packBuffer( chunk, p1);
	parambuf.packBool(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool SegmenterContextImpl::getNext(
			int& p1, 
			SegmenterPosition& p2, 
			const char*& segment, std::size_t& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterContext), SegmenterContextConst::methodName( Method_getNext), objid());
	bool p0 = obj()->getNext(p1, p2, segment, p3);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packInt(p1);
	parambuf.packGlobalCounter(p2);
	parambuf.packBuffer( segment, p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SegmenterInstanceImpl::~SegmenterInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterInstance), SegmenterInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void SegmenterInstanceImpl::defineSelectorExpression(
			int p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterInstance), SegmenterInstanceConst::methodName( Method_defineSelectorExpression), objid());
	obj()->defineSelectorExpression(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packInt(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void SegmenterInstanceImpl::defineSubSection(
			int p1, 
			int p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterInstance), SegmenterInstanceConst::methodName( Method_defineSubSection), objid());
	obj()->defineSubSection(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packInt(p1);
	parambuf.packInt(p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

SegmenterContextInterface* SegmenterInstanceImpl::createContext(
			const analyzer::DocumentClass& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterInstance), SegmenterInstanceConst::methodName( Method_createContext), objid());
	SegmenterContextInterface* p0 = obj()->createContext(p1);
	p0 = traceContext()->createInterfaceImpl<SegmenterContextInterface,SegmenterContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createContext");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SegmenterContext), objbase_p0->objid());
		parambuf.packAnalyzerDocumentClass(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SegmenterMarkupContextInterface* SegmenterInstanceImpl::createMarkupContext(
			const analyzer::DocumentClass& p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterInstance), SegmenterInstanceConst::methodName( Method_createMarkupContext), objid());
	SegmenterMarkupContextInterface* p0 = obj()->createMarkupContext(p1, p2);
	p0 = traceContext()->createInterfaceImpl<SegmenterMarkupContextInterface,SegmenterMarkupContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createMarkupContext");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SegmenterMarkupContext), objbase_p0->objid());
		parambuf.packAnalyzerDocumentClass(p1);
		parambuf.packString(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* SegmenterInstanceImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterInstance), SegmenterInstanceConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView SegmenterInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterInstance), SegmenterInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SegmenterImpl::~SegmenterImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Segmenter), SegmenterConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

const char* SegmenterImpl::mimeType() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Segmenter), SegmenterConst::methodName( Method_mimeType), objid());
	const char* p0 = obj()->mimeType();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "mimeType");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SegmenterInstanceInterface* SegmenterImpl::createInstance(
			const analyzer::SegmenterOptions& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Segmenter), SegmenterConst::methodName( Method_createInstance), objid());
	SegmenterInstanceInterface* p0 = obj()->createInstance(p1);
	p0 = traceContext()->createInterfaceImpl<SegmenterInstanceInterface,SegmenterInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SegmenterInstance), objbase_p0->objid());
		parambuf.packAnalyzerSegmenterOptions(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ContentIteratorInterface* SegmenterImpl::createContentIterator(
			const char* content, std::size_t p1, 
			const std::vector<std::string>& p2, 
			const std::vector<std::string>& p3, 
			const analyzer::DocumentClass& p4, 
			const analyzer::SegmenterOptions& p5) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Segmenter), SegmenterConst::methodName( Method_createContentIterator), objid());
	ContentIteratorInterface* p0 = obj()->createContentIterator(content, p1, p2, p3, p4, p5);
	p0 = traceContext()->createInterfaceImpl<ContentIteratorInterface,ContentIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createContentIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ContentIterator), objbase_p0->objid());
		parambuf.packBuffer( content, p1);
		parambuf.packStringVector(p2);
		parambuf.packStringVector(p3);
		parambuf.packAnalyzerDocumentClass(p4);
		parambuf.packAnalyzerSegmenterOptions(p5);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* SegmenterImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Segmenter), SegmenterConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView SegmenterImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Segmenter), SegmenterConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SegmenterMarkupContextImpl::~SegmenterMarkupContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterMarkupContext), SegmenterMarkupContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool SegmenterMarkupContextImpl::getNext(
			SegmenterPosition& p1, 
			const char*& segment, std::size_t& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterMarkupContext), SegmenterMarkupContextConst::methodName( Method_getNext), objid());
	bool p0 = obj()->getNext(p1, segment, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packGlobalCounter(p1);
	parambuf.packBuffer( segment, p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

unsigned int SegmenterMarkupContextImpl::segmentSize(
			const SegmenterPosition& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterMarkupContext), SegmenterMarkupContextConst::methodName( Method_segmentSize), objid());
	unsigned int p0 = obj()->segmentSize(p1);
	TraceSerializer parambuf;
	parambuf.packUInt(p0);
	parambuf.packGlobalCounter(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string SegmenterMarkupContextImpl::tagName(
			const SegmenterPosition& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterMarkupContext), SegmenterMarkupContextConst::methodName( Method_tagName), objid());
	std::string p0 = obj()->tagName(p1);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packGlobalCounter(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

int SegmenterMarkupContextImpl::tagLevel(
			const SegmenterPosition& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterMarkupContext), SegmenterMarkupContextConst::methodName( Method_tagLevel), objid());
	int p0 = obj()->tagLevel(p1);
	TraceSerializer parambuf;
	parambuf.packInt(p0);
	parambuf.packGlobalCounter(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void SegmenterMarkupContextImpl::putOpenTag(
			const SegmenterPosition& p1, 
			std::size_t p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterMarkupContext), SegmenterMarkupContextConst::methodName( Method_putOpenTag), objid());
	obj()->putOpenTag(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packGlobalCounter(p1);
	parambuf.packSize( p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void SegmenterMarkupContextImpl::putAttribute(
			const SegmenterPosition& p1, 
			std::size_t p2, 
			const std::string& p3, 
			const std::string& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterMarkupContext), SegmenterMarkupContextConst::methodName( Method_putAttribute), objid());
	obj()->putAttribute(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packGlobalCounter(p1);
	parambuf.packSize( p2);
	parambuf.packString(p3);
	parambuf.packString(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void SegmenterMarkupContextImpl::putCloseTag(
			const SegmenterPosition& p1, 
			std::size_t p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterMarkupContext), SegmenterMarkupContextConst::methodName( Method_putCloseTag), objid());
	obj()->putCloseTag(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packGlobalCounter(p1);
	parambuf.packSize( p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::string SegmenterMarkupContextImpl::getContent() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SegmenterMarkupContext), SegmenterMarkupContextConst::methodName( Method_getContent), objid());
	std::string p0 = obj()->getContent();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SentenceLexerInstanceImpl::~SentenceLexerInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SentenceLexerInstance), SentenceLexerInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::vector<SentenceGuess> SentenceLexerInstanceImpl::call(
			const std::vector<std::string>& p1, 
			int p2, 
			double p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SentenceLexerInstance), SentenceLexerInstanceConst::methodName( Method_call), objid());
	std::vector<SentenceGuess> p0 = obj()->call(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packSentenceGuessVector(p0);
	parambuf.packStringVector(p1);
	parambuf.packInt(p2);
	parambuf.packDouble(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<WeightedSentenceTerm> SentenceLexerInstanceImpl::similarTerms(
			const std::string& p1, 
			const std::vector<WeightedSentenceTerm>& p2, 
			double p3, 
			int p4, 
			double p5) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SentenceLexerInstance), SentenceLexerInstanceConst::methodName( Method_similarTerms), objid());
	std::vector<WeightedSentenceTerm> p0 = obj()->similarTerms(p1, p2, p3, p4, p5);
	TraceSerializer parambuf;
	parambuf.packWeightedSentenceTermVector(p0);
	parambuf.packString(p1);
	parambuf.packWeightedSentenceTermVector(p2);
	parambuf.packDouble(p3);
	parambuf.packInt(p4);
	parambuf.packDouble(p5);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StatisticsBuilderImpl::~StatisticsBuilderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsBuilder), StatisticsBuilderConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void StatisticsBuilderImpl::addNofDocumentsInsertedChange(
			int p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsBuilder), StatisticsBuilderConst::methodName( Method_addNofDocumentsInsertedChange), objid());
	obj()->addNofDocumentsInsertedChange(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packInt(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StatisticsBuilderImpl::addDfChange(
			const char* p1, 
			const char* p2, 
			int p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsBuilder), StatisticsBuilderConst::methodName( Method_addDfChange), objid());
	obj()->addDfChange(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packCharp(p1);
	parambuf.packCharp(p2);
	parambuf.packInt(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<StatisticsMessage> StatisticsBuilderImpl::getMessages() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsBuilder), StatisticsBuilderConst::methodName( Method_getMessages), objid());
	std::vector<StatisticsMessage> p0 = obj()->getMessages();
	TraceSerializer parambuf;
	parambuf.packStatisticsMessageVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool StatisticsBuilderImpl::commit()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsBuilder), StatisticsBuilderConst::methodName( Method_commit), objid());
	bool p0 = obj()->commit();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void StatisticsBuilderImpl::rollback()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsBuilder), StatisticsBuilderConst::methodName( Method_rollback), objid());
	obj()->rollback();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

StatisticsMapImpl::~StatisticsMapImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsMap), StatisticsMapConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void StatisticsMapImpl::addNofDocumentsInsertedChange(
			int p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsMap), StatisticsMapConst::methodName( Method_addNofDocumentsInsertedChange), objid());
	obj()->addNofDocumentsInsertedChange(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packInt(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StatisticsMapImpl::addDfChange(
			const char* p1, 
			const char* p2, 
			int p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsMap), StatisticsMapConst::methodName( Method_addDfChange), objid());
	obj()->addDfChange(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packCharp(p1);
	parambuf.packCharp(p2);
	parambuf.packInt(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool StatisticsMapImpl::processStatisticsMessage(
			const void* msgptr, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsMap), StatisticsMapConst::methodName( Method_processStatisticsMessage), objid());
	bool p0 = obj()->processStatisticsMessage(msgptr, p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packBlob( msgptr, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

GlobalCounter StatisticsMapImpl::nofDocuments() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsMap), StatisticsMapConst::methodName( Method_nofDocuments), objid());
	GlobalCounter p0 = obj()->nofDocuments();
	TraceSerializer parambuf;
	parambuf.packGlobalCounter(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

GlobalCounter StatisticsMapImpl::df(
			const std::string& p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsMap), StatisticsMapConst::methodName( Method_df), objid());
	GlobalCounter p0 = obj()->df(p1, p2);
	TraceSerializer parambuf;
	parambuf.packGlobalCounter(p0);
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> StatisticsMapImpl::types() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsMap), StatisticsMapConst::methodName( Method_types), objid());
	std::vector<std::string> p0 = obj()->types();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StatisticsProcessorImpl::~StatisticsProcessorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsProcessor), StatisticsProcessorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

StatisticsViewerInterface* StatisticsProcessorImpl::createViewer(
			const void* msgptr, std::size_t p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsProcessor), StatisticsProcessorConst::methodName( Method_createViewer), objid());
	StatisticsViewerInterface* p0 = obj()->createViewer(msgptr, p1);
	p0 = traceContext()->createInterfaceImpl<StatisticsViewerInterface,StatisticsViewerImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createViewer");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsViewer), objbase_p0->objid());
		parambuf.packBlob( msgptr, p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

TimeStamp StatisticsProcessorImpl::getUpperBoundTimeStamp(
			const std::string& p1, 
			TimeStamp p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsProcessor), StatisticsProcessorConst::methodName( Method_getUpperBoundTimeStamp), objid());
	TimeStamp p0 = obj()->getUpperBoundTimeStamp(p1, p2);
	TraceSerializer parambuf;
	parambuf.packTimeStamp(p0);
	parambuf.packString(p1);
	parambuf.packTimeStamp(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StatisticsMessage StatisticsProcessorImpl::loadChangeMessage(
			const std::string& p1, 
			TimeStamp p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsProcessor), StatisticsProcessorConst::methodName( Method_loadChangeMessage), objid());
	StatisticsMessage p0 = obj()->loadChangeMessage(p1, p2);
	TraceSerializer parambuf;
	parambuf.packStatisticsMessage(p0);
	parambuf.packString(p1);
	parambuf.packTimeStamp(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StatisticsBuilderInterface* StatisticsProcessorImpl::createBuilder(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsProcessor), StatisticsProcessorConst::methodName( Method_createBuilder), objid());
	StatisticsBuilderInterface* p0 = obj()->createBuilder(p1);
	p0 = traceContext()->createInterfaceImpl<StatisticsBuilderInterface,StatisticsBuilderImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createBuilder");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsBuilder), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StatisticsMapInterface* StatisticsProcessorImpl::createMap(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsProcessor), StatisticsProcessorConst::methodName( Method_createMap), objid());
	StatisticsMapInterface* p0 = obj()->createMap(p1);
	p0 = traceContext()->createInterfaceImpl<StatisticsMapInterface,StatisticsMapImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createMap");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsMap), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void StatisticsProcessorImpl::releaseStatistics(
			const std::string& p1, 
			TimeStamp p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsProcessor), StatisticsProcessorConst::methodName( Method_releaseStatistics), objid());
	obj()->releaseStatistics(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packTimeStamp(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

StatisticsStorageClientImpl::~StatisticsStorageClientImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool StatisticsStorageClientImpl::reload(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_reload), objid());
	bool p0 = obj()->reload(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

long StatisticsStorageClientImpl::diskUsage() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_diskUsage), objid());
	long p0 = obj()->diskUsage();
	TraceSerializer parambuf;
	parambuf.packInt64(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char** StatisticsStorageClientImpl::getConfigParameters() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_getConfigParameters), objid());
	const char** p0 = obj()->getConfigParameters();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getConfigParameters");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharpp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string StatisticsStorageClientImpl::config() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_config), objid());
	std::string p0 = obj()->config();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

GlobalCounter StatisticsStorageClientImpl::nofDocuments() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_nofDocuments), objid());
	GlobalCounter p0 = obj()->nofDocuments();
	TraceSerializer parambuf;
	parambuf.packGlobalCounter(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

GlobalCounter StatisticsStorageClientImpl::documentFrequency(
			const std::string& p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_documentFrequency), objid());
	GlobalCounter p0 = obj()->documentFrequency(p1, p2);
	TraceSerializer parambuf;
	parambuf.packGlobalCounter(p0);
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

TimeStamp StatisticsStorageClientImpl::storageTimeStamp(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_storageTimeStamp), objid());
	TimeStamp p0 = obj()->storageTimeStamp(p1);
	TraceSerializer parambuf;
	parambuf.packTimeStamp(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool StatisticsStorageClientImpl::putStatisticsMessage(
			const StatisticsMessage& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_putStatisticsMessage), objid());
	bool p0 = obj()->putStatisticsMessage(p1, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packStatisticsMessage(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const StatisticsProcessorInterface* StatisticsStorageClientImpl::getStatisticsProcessor() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_getStatisticsProcessor), objid());
	const StatisticsProcessorInterface* p0 = obj()->getStatisticsProcessor();
	p0 = traceContext()->createInterfaceImpl_const<StatisticsProcessorInterface,StatisticsProcessorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getStatisticsProcessor");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsProcessor), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void StatisticsStorageClientImpl::close()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_close), objid());
	obj()->close();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StatisticsStorageClientImpl::compaction()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorageClient), StatisticsStorageClientConst::methodName( Method_compaction), objid());
	obj()->compaction();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

StatisticsStorageImpl::~StatisticsStorageImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorage), StatisticsStorageConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

StatisticsStorageClientInterface* StatisticsStorageImpl::createClient(
			const std::string& p1, 
			const DatabaseInterface* p2, 
			const StatisticsProcessorInterface* p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorage), StatisticsStorageConst::methodName( Method_createClient), objid());
	StatisticsStorageClientInterface* p0 = obj()->createClient(p1, p2, p3);
	p0 = traceContext()->createInterfaceImpl<StatisticsStorageClientInterface,StatisticsStorageClientImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createClient");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsStorageClient), objbase_p0->objid());
		parambuf.packString(p1);
		const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
		const TraceObjectBase* objbase_p3 = dynamic_cast<const TraceObjectBase*>( p3);
		if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsProcessor), objbase_p3->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool StatisticsStorageImpl::createStorage(
			const std::string& p1, 
			const DatabaseInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorage), StatisticsStorageConst::methodName( Method_createStorage), objid());
	bool p0 = obj()->createStorage(p1, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* StatisticsStorageImpl::getConfigDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorage), StatisticsStorageConst::methodName( Method_getConfigDescription), objid());
	const char* p0 = obj()->getConfigDescription();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getConfigDescription");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char** StatisticsStorageImpl::getConfigParameters() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsStorage), StatisticsStorageConst::methodName( Method_getConfigParameters), objid());
	const char** p0 = obj()->getConfigParameters();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getConfigParameters");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharpp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StatisticsViewerImpl::~StatisticsViewerImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsViewer), StatisticsViewerConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

int StatisticsViewerImpl::nofDocumentsInsertedChange()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsViewer), StatisticsViewerConst::methodName( Method_nofDocumentsInsertedChange), objid());
	int p0 = obj()->nofDocumentsInsertedChange();
	TraceSerializer parambuf;
	parambuf.packInt(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool StatisticsViewerImpl::nextDfChange(
			TermStatisticsChange& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsViewer), StatisticsViewerConst::methodName( Method_nextDfChange), objid());
	bool p0 = obj()->nextDfChange(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packTermStatisticsChange(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageClientImpl::~StorageClientImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool StorageClientImpl::reload(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_reload), objid());
	bool p0 = obj()->reload(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

long StorageClientImpl::diskUsage() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_diskUsage), objid());
	long p0 = obj()->diskUsage();
	TraceSerializer parambuf;
	parambuf.packInt64(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

BlockStatistics StorageClientImpl::blockStatistics() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_blockStatistics), objid());
	BlockStatistics p0 = obj()->blockStatistics();
	TraceSerializer parambuf;
	parambuf.packBlockStatistics(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string StorageClientImpl::config() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_config), objid());
	std::string p0 = obj()->config();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PostingIteratorInterface* StorageClientImpl::createTermPostingIterator(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3, 
			const TermStatistics& p4) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createTermPostingIterator), objid());
	PostingIteratorInterface* p0 = obj()->createTermPostingIterator(p1, p2, p3, p4);
	p0 = traceContext()->createInterfaceImpl<PostingIteratorInterface,PostingIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createTermPostingIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase_p0->objid());
		parambuf.packString(p1);
		parambuf.packString(p2);
		parambuf.packIndex(p3);
		parambuf.packTermStatistics(p4);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PostingIteratorInterface* StorageClientImpl::createFrequencyPostingIterator(
			const std::string& p1, 
			const std::string& p2, 
			const TermStatistics& p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createFrequencyPostingIterator), objid());
	PostingIteratorInterface* p0 = obj()->createFrequencyPostingIterator(p1, p2, p3);
	p0 = traceContext()->createInterfaceImpl<PostingIteratorInterface,PostingIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createFrequencyPostingIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase_p0->objid());
		parambuf.packString(p1);
		parambuf.packString(p2);
		parambuf.packTermStatistics(p3);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructureIteratorInterface* StorageClientImpl::createStructureIterator() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createStructureIterator), objid());
	StructureIteratorInterface* p0 = obj()->createStructureIterator();
	p0 = traceContext()->createInterfaceImpl<StructureIteratorInterface,StructureIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createStructureIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StructureIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PostingIteratorInterface* StorageClientImpl::createBrowsePostingIterator(
			const MetaDataRestrictionInterface* p1, 
			const Index& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createBrowsePostingIterator), objid());
	PostingIteratorInterface* p0 = obj()->createBrowsePostingIterator(p1, p2);
	p0 = traceContext()->createInterfaceImpl<PostingIteratorInterface,PostingIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createBrowsePostingIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_MetaDataRestriction), objbase_p1->objid());
		parambuf.packIndex(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ForwardIteratorInterface* StorageClientImpl::createForwardIterator(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createForwardIterator), objid());
	ForwardIteratorInterface* p0 = obj()->createForwardIterator(p1);
	p0 = traceContext()->createInterfaceImpl<ForwardIteratorInterface,ForwardIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createForwardIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ForwardIterator), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentTermIteratorInterface* StorageClientImpl::createDocumentTermIterator(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createDocumentTermIterator), objid());
	DocumentTermIteratorInterface* p0 = obj()->createDocumentTermIterator(p1);
	p0 = traceContext()->createInterfaceImpl<DocumentTermIteratorInterface,DocumentTermIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createDocumentTermIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentTermIterator), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

InvAclIteratorInterface* StorageClientImpl::createInvAclIterator(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createInvAclIterator), objid());
	InvAclIteratorInterface* p0 = obj()->createInvAclIterator(p1);
	p0 = traceContext()->createInterfaceImpl<InvAclIteratorInterface,InvAclIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInvAclIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_InvAclIterator), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

AclReaderInterface* StorageClientImpl::createAclReader() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createAclReader), objid());
	AclReaderInterface* p0 = obj()->createAclReader();
	p0 = traceContext()->createInterfaceImpl<AclReaderInterface,AclReaderImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createAclReader");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_AclReader), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index StorageClientImpl::nofDocumentsInserted() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_nofDocumentsInserted), objid());
	Index p0 = obj()->nofDocumentsInserted();
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index StorageClientImpl::documentFrequency(
			const std::string& p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_documentFrequency), objid());
	Index p0 = obj()->documentFrequency(p1, p2);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index StorageClientImpl::maxDocumentNumber() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_maxDocumentNumber), objid());
	Index p0 = obj()->maxDocumentNumber();
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index StorageClientImpl::documentNumber(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_documentNumber), objid());
	Index p0 = obj()->documentNumber(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index StorageClientImpl::structTypeNumber(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_structTypeNumber), objid());
	Index p0 = obj()->structTypeNumber(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index StorageClientImpl::termTypeNumber(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_termTypeNumber), objid());
	Index p0 = obj()->termTypeNumber(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index StorageClientImpl::termValueNumber(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_termValueNumber), objid());
	Index p0 = obj()->termValueNumber(p1);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool StorageClientImpl::isForwardIndexTerm(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_isForwardIndexTerm), objid());
	bool p0 = obj()->isForwardIndexTerm(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ValueIteratorInterface* StorageClientImpl::createTermTypeIterator() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createTermTypeIterator), objid());
	ValueIteratorInterface* p0 = obj()->createTermTypeIterator();
	p0 = traceContext()->createInterfaceImpl<ValueIteratorInterface,ValueIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createTermTypeIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ValueIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ValueIteratorInterface* StorageClientImpl::createStructTypeIterator() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createStructTypeIterator), objid());
	ValueIteratorInterface* p0 = obj()->createStructTypeIterator();
	p0 = traceContext()->createInterfaceImpl<ValueIteratorInterface,ValueIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createStructTypeIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ValueIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ValueIteratorInterface* StorageClientImpl::createTermValueIterator() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createTermValueIterator), objid());
	ValueIteratorInterface* p0 = obj()->createTermValueIterator();
	p0 = traceContext()->createInterfaceImpl<ValueIteratorInterface,ValueIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createTermValueIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ValueIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ValueIteratorInterface* StorageClientImpl::createDocIdIterator() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createDocIdIterator), objid());
	ValueIteratorInterface* p0 = obj()->createDocIdIterator();
	p0 = traceContext()->createInterfaceImpl<ValueIteratorInterface,ValueIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createDocIdIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ValueIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ValueIteratorInterface* StorageClientImpl::createUserNameIterator() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createUserNameIterator), objid());
	ValueIteratorInterface* p0 = obj()->createUserNameIterator();
	p0 = traceContext()->createInterfaceImpl<ValueIteratorInterface,ValueIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createUserNameIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ValueIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index StorageClientImpl::documentStatistics(
			const Index& p1, 
			const DocumentStatisticsType& p2, 
			const std::string& p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_documentStatistics), objid());
	Index p0 = obj()->documentStatistics(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	parambuf.packIndex(p1);
	parambuf.packDocumentStatisticsType(p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

MetaDataReaderInterface* StorageClientImpl::createMetaDataReader() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createMetaDataReader), objid());
	MetaDataReaderInterface* p0 = obj()->createMetaDataReader();
	p0 = traceContext()->createInterfaceImpl<MetaDataReaderInterface,MetaDataReaderImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createMetaDataReader");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_MetaDataReader), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

MetaDataRestrictionInterface* StorageClientImpl::createMetaDataRestriction() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createMetaDataRestriction), objid());
	MetaDataRestrictionInterface* p0 = obj()->createMetaDataRestriction();
	p0 = traceContext()->createInterfaceImpl<MetaDataRestrictionInterface,MetaDataRestrictionImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createMetaDataRestriction");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_MetaDataRestriction), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

AttributeReaderInterface* StorageClientImpl::createAttributeReader() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createAttributeReader), objid());
	AttributeReaderInterface* p0 = obj()->createAttributeReader();
	p0 = traceContext()->createInterfaceImpl<AttributeReaderInterface,AttributeReaderImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createAttributeReader");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_AttributeReader), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageTransactionInterface* StorageClientImpl::createTransaction()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createTransaction), objid());
	StorageTransactionInterface* p0 = obj()->createTransaction();
	p0 = traceContext()->createInterfaceImpl<StorageTransactionInterface,StorageTransactionImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createTransaction");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageTransaction), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

TimeStamp StorageClientImpl::getNextChangeStatisticsTimeStamp(
			TimeStamp p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_getNextChangeStatisticsTimeStamp), objid());
	TimeStamp p0 = obj()->getNextChangeStatisticsTimeStamp(p1);
	TraceSerializer parambuf;
	parambuf.packTimeStamp(p0);
	parambuf.packTimeStamp(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StatisticsMessage StorageClientImpl::loadChangeStatisticsMessage(
			TimeStamp p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_loadChangeStatisticsMessage), objid());
	StatisticsMessage p0 = obj()->loadChangeStatisticsMessage(p1);
	TraceSerializer parambuf;
	parambuf.packStatisticsMessage(p0);
	parambuf.packTimeStamp(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<StatisticsMessage> StorageClientImpl::loadInitStatisticsMessages() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_loadInitStatisticsMessages), objid());
	std::vector<StatisticsMessage> p0 = obj()->loadInitStatisticsMessages();
	TraceSerializer parambuf;
	parambuf.packStatisticsMessageVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const StatisticsProcessorInterface* StorageClientImpl::getStatisticsProcessor() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_getStatisticsProcessor), objid());
	const StatisticsProcessorInterface* p0 = obj()->getStatisticsProcessor();
	p0 = traceContext()->createInterfaceImpl_const<StatisticsProcessorInterface,StatisticsProcessorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getStatisticsProcessor");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsProcessor), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageDocumentInterface* StorageClientImpl::createDocumentChecker(
			const std::string& p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createDocumentChecker), objid());
	StorageDocumentInterface* p0 = obj()->createDocumentChecker(p1, p2);
	p0 = traceContext()->createInterfaceImpl<StorageDocumentInterface,StorageDocumentImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createDocumentChecker");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageDocument), objbase_p0->objid());
		parambuf.packString(p1);
		parambuf.packString(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageDumpInterface* StorageClientImpl::createDump(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createDump), objid());
	StorageDumpInterface* p0 = obj()->createDump(p1);
	p0 = traceContext()->createInterfaceImpl<StorageDumpInterface,StorageDumpImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createDump");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageDump), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char** StorageClientImpl::getConfigParameters() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_getConfigParameters), objid());
	const char** p0 = obj()->getConfigParameters();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getConfigParameters");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharpp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool StorageClientImpl::checkStorage(
			std::ostream& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_checkStorage), objid());
	bool p0 = obj()->checkStorage(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void StorageClientImpl::close()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_close), objid());
	obj()->close();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageClientImpl::compaction()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_compaction), objid());
	obj()->compaction();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

StorageDocumentImpl::~StorageDocumentImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocument), StorageDocumentConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void StorageDocumentImpl::addSearchIndexTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocument), StorageDocumentConst::methodName( Method_addSearchIndexTerm), objid());
	obj()->addSearchIndexTerm(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packIndex(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentImpl::addSearchIndexStructure(
			const std::string& p1, 
			const IndexRange& p2, 
			const IndexRange& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocument), StorageDocumentConst::methodName( Method_addSearchIndexStructure), objid());
	obj()->addSearchIndexStructure(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packIndexRange(p2);
	parambuf.packIndexRange(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentImpl::addForwardIndexTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocument), StorageDocumentConst::methodName( Method_addForwardIndexTerm), objid());
	obj()->addForwardIndexTerm(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packIndex(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentImpl::setMetaData(
			const std::string& p1, 
			const NumericVariant& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocument), StorageDocumentConst::methodName( Method_setMetaData), objid());
	obj()->setMetaData(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packNumericVariant(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentImpl::setAttribute(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocument), StorageDocumentConst::methodName( Method_setAttribute), objid());
	obj()->setAttribute(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentImpl::setUserAccessRight(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocument), StorageDocumentConst::methodName( Method_setUserAccessRight), objid());
	obj()->setUserAccessRight(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentImpl::done()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocument), StorageDocumentConst::methodName( Method_done), objid());
	obj()->done();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

StorageDocumentUpdateImpl::~StorageDocumentUpdateImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void StorageDocumentUpdateImpl::addSearchIndexTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_addSearchIndexTerm), objid());
	obj()->addSearchIndexTerm(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packIndex(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::addSearchIndexStructure(
			const std::string& p1, 
			const IndexRange& p2, 
			const IndexRange& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_addSearchIndexStructure), objid());
	obj()->addSearchIndexStructure(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packIndexRange(p2);
	parambuf.packIndexRange(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::addForwardIndexTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_addForwardIndexTerm), objid());
	obj()->addForwardIndexTerm(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packIndex(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::clearSearchIndexTerm(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_clearSearchIndexTerm), objid());
	obj()->clearSearchIndexTerm(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::clearSearchIndexStructures()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_clearSearchIndexStructures), objid());
	obj()->clearSearchIndexStructures();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::clearForwardIndexTerm(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_clearForwardIndexTerm), objid());
	obj()->clearForwardIndexTerm(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::setMetaData(
			const std::string& p1, 
			const NumericVariant& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_setMetaData), objid());
	obj()->setMetaData(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packNumericVariant(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::setAttribute(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_setAttribute), objid());
	obj()->setAttribute(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::clearAttribute(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_clearAttribute), objid());
	obj()->clearAttribute(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::setUserAccessRight(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_setUserAccessRight), objid());
	obj()->setUserAccessRight(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::clearUserAccessRight(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_clearUserAccessRight), objid());
	obj()->clearUserAccessRight(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::clearUserAccessRights()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_clearUserAccessRights), objid());
	obj()->clearUserAccessRights();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageDocumentUpdateImpl::done()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), StorageDocumentUpdateConst::methodName( Method_done), objid());
	obj()->done();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

StorageDumpImpl::~StorageDumpImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDump), StorageDumpConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool StorageDumpImpl::nextChunk(
			const char*& chunk, std::size_t& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageDump), StorageDumpConst::methodName( Method_nextChunk), objid());
	bool p0 = obj()->nextChunk(chunk, p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packBuffer( chunk, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageImpl::~StorageImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Storage), StorageConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

StorageClientInterface* StorageImpl::createClient(
			const std::string& p1, 
			const DatabaseInterface* p2, 
			const StatisticsProcessorInterface* p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Storage), StorageConst::methodName( Method_createClient), objid());
	StorageClientInterface* p0 = obj()->createClient(p1, p2, p3);
	p0 = traceContext()->createInterfaceImpl<StorageClientInterface,StorageClientImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createClient");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageClient), objbase_p0->objid());
		parambuf.packString(p1);
		const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
		const TraceObjectBase* objbase_p3 = dynamic_cast<const TraceObjectBase*>( p3);
		if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsProcessor), objbase_p3->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool StorageImpl::createStorage(
			const std::string& p1, 
			const DatabaseInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Storage), StorageConst::methodName( Method_createStorage), objid());
	bool p0 = obj()->createStorage(p1, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* StorageImpl::getConfigDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Storage), StorageConst::methodName( Method_getConfigDescription), objid());
	const char* p0 = obj()->getConfigDescription();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getConfigDescription");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char** StorageImpl::getConfigParameters() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Storage), StorageConst::methodName( Method_getConfigParameters), objid());
	const char** p0 = obj()->getConfigParameters();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getConfigParameters");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharpp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageMetaDataTableUpdateImpl::~StorageMetaDataTableUpdateImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageMetaDataTableUpdate), StorageMetaDataTableUpdateConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void StorageMetaDataTableUpdateImpl::addElement(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageMetaDataTableUpdate), StorageMetaDataTableUpdateConst::methodName( Method_addElement), objid());
	obj()->addElement(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageMetaDataTableUpdateImpl::alterElement(
			const std::string& p1, 
			const std::string& p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageMetaDataTableUpdate), StorageMetaDataTableUpdateConst::methodName( Method_alterElement), objid());
	obj()->alterElement(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageMetaDataTableUpdateImpl::renameElement(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageMetaDataTableUpdate), StorageMetaDataTableUpdateConst::methodName( Method_renameElement), objid());
	obj()->renameElement(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageMetaDataTableUpdateImpl::deleteElement(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageMetaDataTableUpdate), StorageMetaDataTableUpdateConst::methodName( Method_deleteElement), objid());
	obj()->deleteElement(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageMetaDataTableUpdateImpl::deleteElements()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageMetaDataTableUpdate), StorageMetaDataTableUpdateConst::methodName( Method_deleteElements), objid());
	obj()->deleteElements();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageMetaDataTableUpdateImpl::clearElement(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageMetaDataTableUpdate), StorageMetaDataTableUpdateConst::methodName( Method_clearElement), objid());
	obj()->clearElement(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool StorageMetaDataTableUpdateImpl::done()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageMetaDataTableUpdate), StorageMetaDataTableUpdateConst::methodName( Method_done), objid());
	bool p0 = obj()->done();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageObjectBuilderImpl::~StorageObjectBuilderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageObjectBuilder), StorageObjectBuilderConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

const StorageInterface* StorageObjectBuilderImpl::getStorage() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageObjectBuilder), StorageObjectBuilderConst::methodName( Method_getStorage), objid());
	const StorageInterface* p0 = obj()->getStorage();
	p0 = traceContext()->createInterfaceImpl_const<StorageInterface,StorageImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getStorage");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Storage), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const DatabaseInterface* StorageObjectBuilderImpl::getDatabase(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageObjectBuilder), StorageObjectBuilderConst::methodName( Method_getDatabase), objid());
	const DatabaseInterface* p0 = obj()->getDatabase(p1);
	p0 = traceContext()->createInterfaceImpl_const<DatabaseInterface,DatabaseImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getDatabase");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const QueryProcessorInterface* StorageObjectBuilderImpl::getQueryProcessor() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageObjectBuilder), StorageObjectBuilderConst::methodName( Method_getQueryProcessor), objid());
	const QueryProcessorInterface* p0 = obj()->getQueryProcessor();
	p0 = traceContext()->createInterfaceImpl_const<QueryProcessorInterface,QueryProcessorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getQueryProcessor");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_QueryProcessor), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const StatisticsProcessorInterface* StorageObjectBuilderImpl::getStatisticsProcessor(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageObjectBuilder), StorageObjectBuilderConst::methodName( Method_getStatisticsProcessor), objid());
	const StatisticsProcessorInterface* p0 = obj()->getStatisticsProcessor(p1);
	p0 = traceContext()->createInterfaceImpl_const<StatisticsProcessorInterface,StatisticsProcessorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getStatisticsProcessor");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsProcessor), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const VectorStorageInterface* StorageObjectBuilderImpl::getVectorStorage(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageObjectBuilder), StorageObjectBuilderConst::methodName( Method_getVectorStorage), objid());
	const VectorStorageInterface* p0 = obj()->getVectorStorage(p1);
	p0 = traceContext()->createInterfaceImpl_const<VectorStorageInterface,VectorStorageImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getVectorStorage");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_VectorStorage), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

QueryEvalInterface* StorageObjectBuilderImpl::createQueryEval() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageObjectBuilder), StorageObjectBuilderConst::methodName( Method_createQueryEval), objid());
	QueryEvalInterface* p0 = obj()->createQueryEval();
	p0 = traceContext()->createInterfaceImpl<QueryEvalInterface,QueryEvalImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createQueryEval");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_QueryEval), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageTransactionImpl::~StorageTransactionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

StorageDocumentInterface* StorageTransactionImpl::createDocument(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_createDocument), objid());
	StorageDocumentInterface* p0 = obj()->createDocument(p1);
	p0 = traceContext()->createInterfaceImpl<StorageDocumentInterface,StorageDocumentImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createDocument");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageDocument), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageDocumentUpdateInterface* StorageTransactionImpl::createDocumentUpdate(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_createDocumentUpdate), objid());
	StorageDocumentUpdateInterface* p0 = obj()->createDocumentUpdate(p1);
	p0 = traceContext()->createInterfaceImpl<StorageDocumentUpdateInterface,StorageDocumentUpdateImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createDocumentUpdate");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), objbase_p0->objid());
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void StorageTransactionImpl::deleteDocument(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_deleteDocument), objid());
	obj()->deleteDocument(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageTransactionImpl::deleteUserAccessRights(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_deleteUserAccessRights), objid());
	obj()->deleteUserAccessRights(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageTransactionImpl::updateMetaData(
			const Index& p1, 
			const std::string& p2, 
			const NumericVariant& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_updateMetaData), objid());
	obj()->updateMetaData(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packIndex(p1);
	parambuf.packString(p2);
	parambuf.packNumericVariant(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageTransactionImpl::updateDocumentFrequency(
			const std::string& p1, 
			const std::string& p2, 
			int p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_updateDocumentFrequency), objid());
	obj()->updateDocumentFrequency(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packInt(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

StorageMetaDataTableUpdateInterface* StorageTransactionImpl::createMetaDataTableUpdate()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_createMetaDataTableUpdate), objid());
	StorageMetaDataTableUpdateInterface* p0 = obj()->createMetaDataTableUpdate();
	p0 = traceContext()->createInterfaceImpl<StorageMetaDataTableUpdateInterface,StorageMetaDataTableUpdateImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createMetaDataTableUpdate");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageMetaDataTableUpdate), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageCommitResult StorageTransactionImpl::commit()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_commit), objid());
	StorageCommitResult p0 = obj()->commit();
	TraceSerializer parambuf;
	parambuf.packStorageCommitResult(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void StorageTransactionImpl::rollback()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_rollback), objid());
	obj()->rollback();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

StructureIteratorImpl::~StructureIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StructureIterator), StructureIteratorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void StructureIteratorImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StructureIterator), StructureIteratorConst::methodName( Method_skipDoc), objid());
	obj()->skipDoc(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

int StructureIteratorImpl::levels() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StructureIterator), StructureIteratorConst::methodName( Method_levels), objid());
	int p0 = obj()->levels();
	TraceSerializer parambuf;
	parambuf.packInt(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index StructureIteratorImpl::docno() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StructureIterator), StructureIteratorConst::methodName( Method_docno), objid());
	Index p0 = obj()->docno();
	TraceSerializer parambuf;
	parambuf.packIndex(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

IndexRange StructureIteratorImpl::skipPos(
			int p1, 
			const Index& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StructureIterator), StructureIteratorConst::methodName( Method_skipPos), objid());
	IndexRange p0 = obj()->skipPos(p1, p2);
	TraceSerializer parambuf;
	parambuf.packIndexRange(p0);
	parambuf.packInt(p1);
	parambuf.packIndex(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

IndexRange StructureIteratorImpl::field(
			int p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StructureIterator), StructureIteratorConst::methodName( Method_field), objid());
	IndexRange p0 = obj()->field(p1);
	TraceSerializer parambuf;
	parambuf.packIndexRange(p0);
	parambuf.packInt(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructureLinkArray StructureIteratorImpl::links(
			int p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StructureIterator), StructureIteratorConst::methodName( Method_links), objid());
	StructureLinkArray p0 = obj()->links(p1);
	TraceSerializer parambuf;
	parambuf.packStructureLinkArray(p0);
	parambuf.packInt(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructureHeaderField StructureIteratorImpl::headerField(
			int p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StructureIterator), StructureIteratorConst::methodName( Method_headerField), objid());
	StructureHeaderField p0 = obj()->headerField(p1);
	TraceSerializer parambuf;
	parambuf.packStructureHeaderField(p0);
	parambuf.packInt(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SummarizerFunctionContextImpl::~SummarizerFunctionContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionContext), SummarizerFunctionContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void SummarizerFunctionContextImpl::addSummarizationFeature(
			const std::string& p1, 
			PostingIteratorInterface* p2, 
			const std::vector<SummarizationVariable>&  p3, 
			double p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionContext), SummarizerFunctionContextConst::methodName( Method_addSummarizationFeature), objid());
	obj()->addSummarizationFeature(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase_p2->objid());
	parambuf.packSummarizationVariableVector(p3);
	parambuf.packDouble(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void SummarizerFunctionContextImpl::setVariableValue(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionContext), SummarizerFunctionContextConst::methodName( Method_setVariableValue), objid());
	obj()->setVariableValue(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packDouble(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<SummaryElement> SummarizerFunctionContextImpl::getSummary(
			const WeightedDocument& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionContext), SummarizerFunctionContextConst::methodName( Method_getSummary), objid());
	std::vector<SummaryElement> p0 = obj()->getSummary(p1);
	TraceSerializer parambuf;
	parambuf.packSummaryElementVector(p0);
	parambuf.packWeightedDocument(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SummarizerFunctionInstanceImpl::~SummarizerFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), SummarizerFunctionInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void SummarizerFunctionInstanceImpl::addStringParameter(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), SummarizerFunctionInstanceConst::methodName( Method_addStringParameter), objid());
	obj()->addStringParameter(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void SummarizerFunctionInstanceImpl::addNumericParameter(
			const std::string& p1, 
			const NumericVariant& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), SummarizerFunctionInstanceConst::methodName( Method_addNumericParameter), objid());
	obj()->addNumericParameter(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packNumericVariant(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<std::string> SummarizerFunctionInstanceImpl::getVariables() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), SummarizerFunctionInstanceConst::methodName( Method_getVariables), objid());
	std::vector<std::string> p0 = obj()->getVariables();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SummarizerFunctionContextInterface* SummarizerFunctionInstanceImpl::createFunctionContext(
			const StorageClientInterface* p1, 
			const GlobalStatistics& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), SummarizerFunctionInstanceConst::methodName( Method_createFunctionContext), objid());
	SummarizerFunctionContextInterface* p0 = obj()->createFunctionContext(p1, p2);
	p0 = traceContext()->createInterfaceImpl<SummarizerFunctionContextInterface,SummarizerFunctionContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createFunctionContext");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SummarizerFunctionContext), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageClient), objbase_p1->objid());
		parambuf.packGlobalStatistics(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool SummarizerFunctionInstanceImpl::doPopulate() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), SummarizerFunctionInstanceConst::methodName( Method_doPopulate), objid());
	bool p0 = obj()->doPopulate();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* SummarizerFunctionInstanceImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), SummarizerFunctionInstanceConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView SummarizerFunctionInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), SummarizerFunctionInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SummarizerFunctionImpl::~SummarizerFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunction), SummarizerFunctionConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

SummarizerFunctionInstanceInterface* SummarizerFunctionImpl::createInstance(
			const QueryProcessorInterface* p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunction), SummarizerFunctionConst::methodName( Method_createInstance), objid());
	SummarizerFunctionInstanceInterface* p0 = obj()->createInstance(p1);
	p0 = traceContext()->createInterfaceImpl<SummarizerFunctionInstanceInterface,SummarizerFunctionInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_QueryProcessor), objbase_p1->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* SummarizerFunctionImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunction), SummarizerFunctionConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView SummarizerFunctionImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunction), SummarizerFunctionConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

TextProcessorImpl::~TextProcessorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::string TextProcessorImpl::getResourceFilePath(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getResourceFilePath), objid());
	std::string p0 = obj()->getResourceFilePath(p1);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const SegmenterInterface* TextProcessorImpl::getSegmenterByName(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getSegmenterByName), objid());
	const SegmenterInterface* p0 = obj()->getSegmenterByName(p1);
	p0 = traceContext()->createInterfaceImpl_const<SegmenterInterface,SegmenterImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getSegmenterByName");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Segmenter), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const SegmenterInterface* TextProcessorImpl::getSegmenterByMimeType(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getSegmenterByMimeType), objid());
	const SegmenterInterface* p0 = obj()->getSegmenterByMimeType(p1);
	p0 = traceContext()->createInterfaceImpl_const<SegmenterInterface,SegmenterImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getSegmenterByMimeType");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Segmenter), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

analyzer::SegmenterOptions TextProcessorImpl::getSegmenterOptions(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getSegmenterOptions), objid());
	analyzer::SegmenterOptions p0 = obj()->getSegmenterOptions(p1);
	TraceSerializer parambuf;
	parambuf.packAnalyzerSegmenterOptions(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const TokenizerFunctionInterface* TextProcessorImpl::getTokenizer(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getTokenizer), objid());
	const TokenizerFunctionInterface* p0 = obj()->getTokenizer(p1);
	p0 = traceContext()->createInterfaceImpl_const<TokenizerFunctionInterface,TokenizerFunctionImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getTokenizer");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunction), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const NormalizerFunctionInterface* TextProcessorImpl::getNormalizer(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getNormalizer), objid());
	const NormalizerFunctionInterface* p0 = obj()->getNormalizer(p1);
	p0 = traceContext()->createInterfaceImpl_const<NormalizerFunctionInterface,NormalizerFunctionImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getNormalizer");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunction), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const AggregatorFunctionInterface* TextProcessorImpl::getAggregator(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getAggregator), objid());
	const AggregatorFunctionInterface* p0 = obj()->getAggregator(p1);
	p0 = traceContext()->createInterfaceImpl_const<AggregatorFunctionInterface,AggregatorFunctionImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getAggregator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_AggregatorFunction), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const PatternLexerInterface* TextProcessorImpl::getPatternLexer(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getPatternLexer), objid());
	const PatternLexerInterface* p0 = obj()->getPatternLexer(p1);
	p0 = traceContext()->createInterfaceImpl_const<PatternLexerInterface,PatternLexerImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getPatternLexer");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternLexer), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const PatternMatcherInterface* TextProcessorImpl::getPatternMatcher(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getPatternMatcher), objid());
	const PatternMatcherInterface* p0 = obj()->getPatternMatcher(p1);
	p0 = traceContext()->createInterfaceImpl_const<PatternMatcherInterface,PatternMatcherImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getPatternMatcher");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternMatcher), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const PatternTermFeederInterface* TextProcessorImpl::getPatternTermFeeder() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getPatternTermFeeder), objid());
	const PatternTermFeederInterface* p0 = obj()->getPatternTermFeeder();
	p0 = traceContext()->createInterfaceImpl_const<PatternTermFeederInterface,PatternTermFeederImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getPatternTermFeeder");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternTermFeeder), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PosTaggerDataInterface* TextProcessorImpl::createPosTaggerData(
			TokenizerFunctionInstanceInterface* p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_createPosTaggerData), objid());
	PosTaggerDataInterface* p0 = obj()->createPosTaggerData(p1);
	p0 = traceContext()->createInterfaceImpl<PosTaggerDataInterface,PosTaggerDataImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createPosTaggerData");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PosTaggerData), objbase_p0->objid());
		TraceObjectBase* objbase_p1 = dynamic_cast<TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p1->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		if (p1) {delete p1; p1 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const PosTaggerInterface* TextProcessorImpl::getPosTagger() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getPosTagger), objid());
	const PosTaggerInterface* p0 = obj()->getPosTagger();
	p0 = traceContext()->createInterfaceImpl_const<PosTaggerInterface,PosTaggerImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getPosTagger");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PosTagger), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

TokenMarkupInstanceInterface* TextProcessorImpl::createTokenMarkupInstance() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_createTokenMarkupInstance), objid());
	TokenMarkupInstanceInterface* p0 = obj()->createTokenMarkupInstance();
	p0 = traceContext()->createInterfaceImpl<TokenMarkupInstanceInterface,TokenMarkupInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createTokenMarkupInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenMarkupInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool TextProcessorImpl::detectDocumentClass(
			analyzer::DocumentClass& p1, 
			const char* contentBegin, std::size_t p2, 
			bool p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_detectDocumentClass), objid());
	bool p0 = obj()->detectDocumentClass(p1, contentBegin, p2, p3);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packAnalyzerDocumentClass(p1);
	parambuf.packBuffer( contentBegin, p2);
	parambuf.packBool(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void TextProcessorImpl::defineDocumentClassDetector(
			DocumentClassDetectorInterface* p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_defineDocumentClassDetector), objid());
	obj()->defineDocumentClassDetector(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	TraceObjectBase* objbase_p1 = dynamic_cast<TraceObjectBase*>( p1);
	if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentClassDetector), objbase_p1->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p1) {delete p1; p1 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void TextProcessorImpl::defineSegmenter(
			const std::string& p1, 
			SegmenterInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_defineSegmenter), objid());
	obj()->defineSegmenter(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Segmenter), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void TextProcessorImpl::defineSegmenterOptions(
			const std::string& p1, 
			const analyzer::SegmenterOptions& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_defineSegmenterOptions), objid());
	obj()->defineSegmenterOptions(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packAnalyzerSegmenterOptions(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void TextProcessorImpl::defineTokenizer(
			const std::string& p1, 
			TokenizerFunctionInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_defineTokenizer), objid());
	obj()->defineTokenizer(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunction), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void TextProcessorImpl::defineNormalizer(
			const std::string& p1, 
			NormalizerFunctionInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_defineNormalizer), objid());
	obj()->defineNormalizer(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunction), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void TextProcessorImpl::defineAggregator(
			const std::string& p1, 
			AggregatorFunctionInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_defineAggregator), objid());
	obj()->defineAggregator(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_AggregatorFunction), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void TextProcessorImpl::definePatternLexer(
			const std::string& p1, 
			PatternLexerInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_definePatternLexer), objid());
	obj()->definePatternLexer(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternLexer), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void TextProcessorImpl::definePatternMatcher(
			const std::string& p1, 
			PatternMatcherInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_definePatternMatcher), objid());
	obj()->definePatternMatcher(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternMatcher), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<std::string> TextProcessorImpl::getFunctionList(
			const FunctionType& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getFunctionList), objid());
	std::vector<std::string> p0 = obj()->getFunctionList(p1);
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	parambuf.packTextProcessorFunctionType(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

TokenizerFunctionInstanceImpl::~TokenizerFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), TokenizerFunctionInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool TokenizerFunctionInstanceImpl::concatBeforeTokenize() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), TokenizerFunctionInstanceConst::methodName( Method_concatBeforeTokenize), objid());
	bool p0 = obj()->concatBeforeTokenize();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<analyzer::Token> TokenizerFunctionInstanceImpl::tokenize(
			const char* src, std::size_t p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), TokenizerFunctionInstanceConst::methodName( Method_tokenize), objid());
	std::vector<analyzer::Token> p0 = obj()->tokenize(src, p1);
	TraceSerializer parambuf;
	parambuf.packAnalyzerTokenVector(p0);
	parambuf.packBuffer( src, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* TokenizerFunctionInstanceImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), TokenizerFunctionInstanceConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView TokenizerFunctionInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), TokenizerFunctionInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

TokenizerFunctionImpl::~TokenizerFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunction), TokenizerFunctionConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

TokenizerFunctionInstanceInterface* TokenizerFunctionImpl::createInstance(
			const std::vector<std::string>& p1, 
			const TextProcessorInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunction), TokenizerFunctionConst::methodName( Method_createInstance), objid());
	TokenizerFunctionInstanceInterface* p0 = obj()->createInstance(p1, p2);
	p0 = traceContext()->createInterfaceImpl<TokenizerFunctionInstanceInterface,TokenizerFunctionInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p0->objid());
		parambuf.packStringVector(p1);
		const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TextProcessor), objbase_p2->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* TokenizerFunctionImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunction), TokenizerFunctionConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView TokenizerFunctionImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunction), TokenizerFunctionConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

TokenMarkupContextImpl::~TokenMarkupContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenMarkupContext), TokenMarkupContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void TokenMarkupContextImpl::putMarkup(
			const analyzer::Position& p1, 
			const analyzer::Position& p2, 
			const analyzer::TokenMarkup& p3, 
			unsigned int p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenMarkupContext), TokenMarkupContextConst::methodName( Method_putMarkup), objid());
	obj()->putMarkup(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packAnalyzerPosition(p1);
	parambuf.packAnalyzerPosition(p2);
	parambuf.packAnalyzerTokenMarkup(p3);
	parambuf.packUInt(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::string TokenMarkupContextImpl::markupDocument(
			const analyzer::DocumentClass& p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenMarkupContext), TokenMarkupContextConst::methodName( Method_markupDocument), objid());
	std::string p0 = obj()->markupDocument(p1, p2);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packAnalyzerDocumentClass(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

TokenMarkupInstanceImpl::~TokenMarkupInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenMarkupInstance), TokenMarkupInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

TokenMarkupContextInterface* TokenMarkupInstanceImpl::createContext(
			const SegmenterInstanceInterface* p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenMarkupInstance), TokenMarkupInstanceConst::methodName( Method_createContext), objid());
	TokenMarkupContextInterface* p0 = obj()->createContext(p1);
	p0 = traceContext()->createInterfaceImpl<TokenMarkupContextInterface,TokenMarkupContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createContext");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenMarkupContext), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SegmenterInstance), objbase_p1->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* TokenMarkupInstanceImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenMarkupInstance), TokenMarkupInstanceConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView TokenMarkupInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenMarkupInstance), TokenMarkupInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ValueIteratorImpl::~ValueIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ValueIterator), ValueIteratorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void ValueIteratorImpl::skip(
			const char* value, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ValueIterator), ValueIteratorConst::methodName( Method_skip), objid());
	obj()->skip(value, p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packBuffer( value, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void ValueIteratorImpl::skipPrefix(
			const char* value, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ValueIterator), ValueIteratorConst::methodName( Method_skipPrefix), objid());
	obj()->skipPrefix(value, p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packBuffer( value, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<std::string> ValueIteratorImpl::fetchValues(
			std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ValueIterator), ValueIteratorConst::methodName( Method_fetchValues), objid());
	std::vector<std::string> p0 = obj()->fetchValues(p1);
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	parambuf.packSize( p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorStorageClientImpl::~VectorStorageClientImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void VectorStorageClientImpl::prepareSearch(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_prepareSearch), objid());
	obj()->prepareSearch(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<VectorQueryResult> VectorStorageClientImpl::findSimilar(
			const std::string& p1, 
			const WordVector& p2, 
			int p3, 
			double p4, 
			double p5, 
			bool p6) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_findSimilar), objid());
	std::vector<VectorQueryResult> p0 = obj()->findSimilar(p1, p2, p3, p4, p5, p6);
	TraceSerializer parambuf;
	parambuf.packVectorQueryResult(p0);
	parambuf.packString(p1);
	parambuf.packFloatVector(p2);
	parambuf.packInt(p3);
	parambuf.packDouble(p4);
	parambuf.packDouble(p5);
	parambuf.packBool(p6);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorStorageTransactionInterface* VectorStorageClientImpl::createTransaction()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_createTransaction), objid());
	VectorStorageTransactionInterface* p0 = obj()->createTransaction();
	p0 = traceContext()->createInterfaceImpl<VectorStorageTransactionInterface,VectorStorageTransactionImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createTransaction");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_VectorStorageTransaction), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> VectorStorageClientImpl::types() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_types), objid());
	std::vector<std::string> p0 = obj()->types();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

ValueIteratorInterface* VectorStorageClientImpl::createFeatureValueIterator() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_createFeatureValueIterator), objid());
	ValueIteratorInterface* p0 = obj()->createFeatureValueIterator();
	p0 = traceContext()->createInterfaceImpl<ValueIteratorInterface,ValueIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createFeatureValueIterator");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ValueIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> VectorStorageClientImpl::featureTypes(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_featureTypes), objid());
	std::vector<std::string> p0 = obj()->featureTypes(p1);
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

int VectorStorageClientImpl::nofTypes() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_nofTypes), objid());
	int p0 = obj()->nofTypes();
	TraceSerializer parambuf;
	parambuf.packInt(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

int VectorStorageClientImpl::nofFeatures() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_nofFeatures), objid());
	int p0 = obj()->nofFeatures();
	TraceSerializer parambuf;
	parambuf.packInt(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

int VectorStorageClientImpl::nofVectors(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_nofVectors), objid());
	int p0 = obj()->nofVectors(p1);
	TraceSerializer parambuf;
	parambuf.packInt(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

WordVector VectorStorageClientImpl::featureVector(
			const std::string& p1, 
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_featureVector), objid());
	WordVector p0 = obj()->featureVector(p1, p2);
	TraceSerializer parambuf;
	parambuf.packFloatVector(p0);
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

double VectorStorageClientImpl::vectorSimilarity(
			const WordVector& p1, 
			const WordVector& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_vectorSimilarity), objid());
	double p0 = obj()->vectorSimilarity(p1, p2);
	TraceSerializer parambuf;
	parambuf.packDouble(p0);
	parambuf.packFloatVector(p1);
	parambuf.packFloatVector(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

WordVector VectorStorageClientImpl::normalize(
			const WordVector& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_normalize), objid());
	WordVector p0 = obj()->normalize(p1);
	TraceSerializer parambuf;
	parambuf.packFloatVector(p0);
	parambuf.packFloatVector(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

SentenceLexerInstanceInterface* VectorStorageClientImpl::createSentenceLexer() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_createSentenceLexer), objid());
	SentenceLexerInstanceInterface* p0 = obj()->createSentenceLexer();
	p0 = traceContext()->createInterfaceImpl<SentenceLexerInstanceInterface,SentenceLexerInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createSentenceLexer");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SentenceLexerInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string VectorStorageClientImpl::config() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_config), objid());
	std::string p0 = obj()->config();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void VectorStorageClientImpl::close()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_close), objid());
	obj()->close();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void VectorStorageClientImpl::compaction()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageClient), VectorStorageClientConst::methodName( Method_compaction), objid());
	obj()->compaction();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

VectorStorageDumpImpl::~VectorStorageDumpImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageDump), VectorStorageDumpConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool VectorStorageDumpImpl::nextChunk(
			const char*& chunk, std::size_t& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageDump), VectorStorageDumpConst::methodName( Method_nextChunk), objid());
	bool p0 = obj()->nextChunk(chunk, p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packBuffer( chunk, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorStorageImpl::~VectorStorageImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorage), VectorStorageConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool VectorStorageImpl::createStorage(
			const std::string& p1, 
			const DatabaseInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorage), VectorStorageConst::methodName( Method_createStorage), objid());
	bool p0 = obj()->createStorage(p1, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorStorageClientInterface* VectorStorageImpl::createClient(
			const std::string& p1, 
			const DatabaseInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorage), VectorStorageConst::methodName( Method_createClient), objid());
	VectorStorageClientInterface* p0 = obj()->createClient(p1, p2);
	p0 = traceContext()->createInterfaceImpl<VectorStorageClientInterface,VectorStorageClientImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createClient");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_VectorStorageClient), objbase_p0->objid());
		parambuf.packString(p1);
		const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorStorageDumpInterface* VectorStorageImpl::createDump(
			const std::string& p1, 
			const DatabaseInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorage), VectorStorageConst::methodName( Method_createDump), objid());
	VectorStorageDumpInterface* p0 = obj()->createDump(p1, p2);
	p0 = traceContext()->createInterfaceImpl<VectorStorageDumpInterface,VectorStorageDumpImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createDump");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_VectorStorageDump), objbase_p0->objid());
		parambuf.packString(p1);
		const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* VectorStorageImpl::getConfigDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorage), VectorStorageConst::methodName( Method_getConfigDescription), objid());
	const char* p0 = obj()->getConfigDescription();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getConfigDescription");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char** VectorStorageImpl::getConfigParameters() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorage), VectorStorageConst::methodName( Method_getConfigParameters), objid());
	const char** p0 = obj()->getConfigParameters();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "getConfigParameters");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharpp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorStorageTransactionImpl::~VectorStorageTransactionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageTransaction), VectorStorageTransactionConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void VectorStorageTransactionImpl::defineVector(
			const std::string& p1, 
			const std::string& p2, 
			const WordVector& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageTransaction), VectorStorageTransactionConst::methodName( Method_defineVector), objid());
	obj()->defineVector(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packFloatVector(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void VectorStorageTransactionImpl::defineFeatureType(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageTransaction), VectorStorageTransactionConst::methodName( Method_defineFeatureType), objid());
	obj()->defineFeatureType(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void VectorStorageTransactionImpl::defineFeature(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageTransaction), VectorStorageTransactionConst::methodName( Method_defineFeature), objid());
	obj()->defineFeature(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void VectorStorageTransactionImpl::clear()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageTransaction), VectorStorageTransactionConst::methodName( Method_clear), objid());
	obj()->clear();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool VectorStorageTransactionImpl::commit()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageTransaction), VectorStorageTransactionConst::methodName( Method_commit), objid());
	bool p0 = obj()->commit();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void VectorStorageTransactionImpl::rollback()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorStorageTransaction), VectorStorageTransactionConst::methodName( Method_rollback), objid());
	obj()->rollback();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

WeightingFunctionContextImpl::~WeightingFunctionContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionContext), WeightingFunctionContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void WeightingFunctionContextImpl::addWeightingFeature(
			const std::string& p1, 
			PostingIteratorInterface* p2, 
			double p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionContext), WeightingFunctionContextConst::methodName( Method_addWeightingFeature), objid());
	obj()->addWeightingFeature(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase_p2->objid());
	parambuf.packDouble(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void WeightingFunctionContextImpl::setVariableValue(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionContext), WeightingFunctionContextConst::methodName( Method_setVariableValue), objid());
	obj()->setVariableValue(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packDouble(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

const std::vector<WeightedField>& WeightingFunctionContextImpl::call(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionContext), WeightingFunctionContextConst::methodName( Method_call), objid());
	const std::vector<WeightedField>& p0 = obj()->call(p1);
	TraceSerializer parambuf;
	parambuf.packWeightedFieldArray(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

WeightingFunctionInstanceImpl::~WeightingFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), WeightingFunctionInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void WeightingFunctionInstanceImpl::addStringParameter(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), WeightingFunctionInstanceConst::methodName( Method_addStringParameter), objid());
	obj()->addStringParameter(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void WeightingFunctionInstanceImpl::addNumericParameter(
			const std::string& p1, 
			const NumericVariant& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), WeightingFunctionInstanceConst::methodName( Method_addNumericParameter), objid());
	obj()->addNumericParameter(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packNumericVariant(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

WeightingFunctionContextInterface* WeightingFunctionInstanceImpl::createFunctionContext(
			const StorageClientInterface* p1, 
			const GlobalStatistics& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), WeightingFunctionInstanceConst::methodName( Method_createFunctionContext), objid());
	WeightingFunctionContextInterface* p0 = obj()->createFunctionContext(p1, p2);
	p0 = traceContext()->createInterfaceImpl<WeightingFunctionContextInterface,WeightingFunctionContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createFunctionContext");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_WeightingFunctionContext), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageClient), objbase_p1->objid());
		parambuf.packGlobalStatistics(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> WeightingFunctionInstanceImpl::getVariables() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), WeightingFunctionInstanceConst::methodName( Method_getVariables), objid());
	std::vector<std::string> p0 = obj()->getVariables();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* WeightingFunctionInstanceImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), WeightingFunctionInstanceConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView WeightingFunctionInstanceImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), WeightingFunctionInstanceConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

WeightingFunctionImpl::~WeightingFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunction), WeightingFunctionConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

WeightingFunctionInstanceInterface* WeightingFunctionImpl::createInstance(
			const QueryProcessorInterface* p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunction), WeightingFunctionConst::methodName( Method_createInstance), objid());
	WeightingFunctionInstanceInterface* p0 = obj()->createInstance(p1);
	p0 = traceContext()->createInterfaceImpl<WeightingFunctionInstanceInterface,WeightingFunctionInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "createInstance");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_QueryProcessor), objbase_p1->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* WeightingFunctionImpl::name() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunction), WeightingFunctionConst::methodName( Method_name), objid());
	const char* p0 = obj()->name();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		char fmtbuf[ 1024];
		std::snprintf( fmtbuf, sizeof(fmtbuf), _TXT("method call '%s' failed: %%s"), "name");
		traceContext()->errorbuf()->explain( fmtbuf);
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StructView WeightingFunctionImpl::view() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunction), WeightingFunctionConst::methodName( Method_view), objid());
	StructView p0 = obj()->view();
	TraceSerializer parambuf;
	parambuf.packStructView(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( ErrorCodeOutOfMem, _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}


