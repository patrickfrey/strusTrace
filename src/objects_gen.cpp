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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "evaluate", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packNumericVariant(p0);
		parambuf.packAnalyzerDocument(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_AggregatorFunctionInstance), objbase_p0->objid());
		parambuf.packStringVector(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* AggregatorFunctionImpl::getDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AggregatorFunction), AggregatorFunctionConst::methodName( Method_getDescription), objid());
	const char* p0 = obj()->getDescription();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getDescription", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getTextProcessor", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TextProcessor), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const SegmenterInterface* AnalyzerObjectBuilderImpl::getSegmenter(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_getSegmenter), objid());
	const SegmenterInterface* p0 = obj()->getSegmenter(p1);
	p0 = traceContext()->createInterfaceImpl_const<SegmenterInterface,SegmenterImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getSegmenter", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Segmenter), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const SegmenterInterface* AnalyzerObjectBuilderImpl::findMimeTypeSegmenter(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_findMimeTypeSegmenter), objid());
	const SegmenterInterface* p0 = obj()->findMimeTypeSegmenter(p1);
	p0 = traceContext()->createInterfaceImpl_const<SegmenterInterface,SegmenterImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "findMimeTypeSegmenter", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Segmenter), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentAnalyzerInterface* AnalyzerObjectBuilderImpl::createDocumentAnalyzer(
			const SegmenterInterface* p1, 
			const analyzer::SegmenterOptions& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_createDocumentAnalyzer), objid());
	DocumentAnalyzerInterface* p0 = obj()->createDocumentAnalyzer(p1, p2);
	p0 = traceContext()->createInterfaceImpl<DocumentAnalyzerInterface,DocumentAnalyzerImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createDocumentAnalyzer", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentAnalyzer), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Segmenter), objbase_p1->objid());
		parambuf.packAnalyzerSegmenterOptions(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

QueryAnalyzerInterface* AnalyzerObjectBuilderImpl::createQueryAnalyzer() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AnalyzerObjectBuilder), AnalyzerObjectBuilderConst::methodName( Method_createQueryAnalyzer), objid());
	QueryAnalyzerInterface* p0 = obj()->createQueryAnalyzer();
	p0 = traceContext()->createInterfaceImpl<QueryAnalyzerInterface,QueryAnalyzerImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createQueryAnalyzer", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_QueryAnalyzer), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
			const char* p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AttributeReader), AttributeReaderConst::methodName( Method_elementHandle), objid());
	Index p0 = obj()->elementHandle(p1);
	TraceSerializer parambuf;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "elementHandle", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packCharp(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> AttributeReaderImpl::getAttributeNames() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_AttributeReader), AttributeReaderConst::methodName( Method_getAttributeNames), objid());
	std::vector<std::string> p0 = obj()->getAttributeNames();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createTransaction", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DatabaseTransaction), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createCursor", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DatabaseCursor), objbase_p0->objid());
		parambuf.packDatabaseOptions(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createBackupCursor", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DatabaseBackupCursor), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseCursorImpl::~DatabaseCursorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

DatabaseCursorInterface::Slice DatabaseCursorImpl::seekUpperBound(
			const char* key, std::size_t p1, 
			std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_seekUpperBound), objid());
	DatabaseCursorInterface::Slice p0 = obj()->seekUpperBound(key, p1, p2);
	TraceSerializer parambuf;
	parambuf.packSlice(p0);
	parambuf.packBuffer( key, p1);
	parambuf.packSize( p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DatabaseCursorInterface::Slice DatabaseCursorImpl::seekUpperBoundRestricted(
			const char* key, std::size_t p1, 
			const char* upkey, std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DatabaseCursor), DatabaseCursorConst::methodName( Method_seekUpperBoundRestricted), objid());
	DatabaseCursorInterface::Slice p0 = obj()->seekUpperBoundRestricted(key, p1, upkey, p2);
	TraceSerializer parambuf;
	parambuf.packSlice(p0);
	parambuf.packBuffer( key, p1);
	parambuf.packBuffer( upkey, p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createClient", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DatabaseClient), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* DatabaseImpl::getConfigDescription(
			const ConfigType& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Database), DatabaseConst::methodName( Method_getConfigDescription), objid());
	const char* p0 = obj()->getConfigDescription(p1);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getConfigDescription", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharp(p0);
		parambuf.packDatabaseConfigType(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char** DatabaseImpl::getConfigParameters(
			const ConfigType& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Database), DatabaseConst::methodName( Method_getConfigParameters), objid());
	const char** p0 = obj()->getConfigParameters(p1);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getConfigParameters", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharpp(p0);
		parambuf.packDatabaseConfigType(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createCursor", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DatabaseCursor), objbase_p0->objid());
		parambuf.packDatabaseOptions(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentAnalyzerImpl::~DocumentAnalyzerImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void DocumentAnalyzerImpl::addSearchIndexFeature(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			const analyzer::FeatureOptions& p5)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_addSearchIndexFeature), objid());
	obj()->addSearchIndexFeature(p1, p2, p3, p4, p5);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	parambuf.packFeatureOptions(p5);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::addForwardIndexFeature(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			const analyzer::FeatureOptions& p5)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_addForwardIndexFeature), objid());
	obj()->addForwardIndexFeature(p1, p2, p3, p4, p5);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	parambuf.packFeatureOptions(p5);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::defineMetaData(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_defineMetaData), objid());
	obj()->defineMetaData(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::defineAggregatedMetaData(
			const std::string& p1, 
			AggregatorFunctionInstanceInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_defineAggregatedMetaData), objid());
	obj()->defineAggregatedMetaData(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_AggregatorFunctionInstance), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::defineAttribute(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_defineAttribute), objid());
	obj()->defineAttribute(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::defineSubDocument(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_defineSubDocument), objid());
	obj()->defineSubDocument(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::addPatternLexem(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_addPatternLexem), objid());
	obj()->addPatternLexem(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::definePatternMatcherPostProc(
			const std::string& p1, 
			PatternMatcherInstanceInterface* p2, 
			PatternTermFeederInstanceInterface* p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_definePatternMatcherPostProc), objid());
	obj()->definePatternMatcherPostProc(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternMatcherInstance), objbase_p2->objid());
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), objbase_p3->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		if (p3) {delete p3; p3 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::definePatternMatcherPreProc(
			const std::string& p1, 
			PatternMatcherInstanceInterface* p2, 
			PatternLexerInstanceInterface* p3, 
			const std::vector<std::string>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_definePatternMatcherPreProc), objid());
	obj()->definePatternMatcherPreProc(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternMatcherInstance), objbase_p2->objid());
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternLexerInstance), objbase_p3->objid());
	parambuf.packStringVector(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		if (p3) {delete p3; p3 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::addSearchIndexFeatureFromPatternMatch(
			const std::string& p1, 
			const std::string& p2, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p3, 
			const analyzer::FeatureOptions& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_addSearchIndexFeatureFromPatternMatch), objid());
	obj()->addSearchIndexFeatureFromPatternMatch(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p3 = p3.begin(), e_p3 = p3.end();
	for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
	{
		parambuf.openIndex( idx_p3); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p3);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	parambuf.packFeatureOptions(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p3 = p3.begin(), e_p3 = p3.end();
		for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
		{
			delete *i_p3;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::addForwardIndexFeatureFromPatternMatch(
			const std::string& p1, 
			const std::string& p2, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p3, 
			const analyzer::FeatureOptions& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_addForwardIndexFeatureFromPatternMatch), objid());
	obj()->addForwardIndexFeatureFromPatternMatch(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p3 = p3.begin(), e_p3 = p3.end();
	for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
	{
		parambuf.openIndex( idx_p3); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p3);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	parambuf.packFeatureOptions(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p3 = p3.begin(), e_p3 = p3.end();
		for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
		{
			delete *i_p3;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::defineMetaDataFromPatternMatch(
			const std::string& p1, 
			const std::string& p2, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_defineMetaDataFromPatternMatch), objid());
	obj()->defineMetaDataFromPatternMatch(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p3 = p3.begin(), e_p3 = p3.end();
	for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
	{
		parambuf.openIndex( idx_p3); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p3);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p3 = p3.begin(), e_p3 = p3.end();
		for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
		{
			delete *i_p3;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void DocumentAnalyzerImpl::defineAttributeFromPatternMatch(
			const std::string& p1, 
			const std::string& p2, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_defineAttributeFromPatternMatch), objid());
	obj()->defineAttributeFromPatternMatch(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p3 = p3.begin(), e_p3 = p3.end();
	for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
	{
		parambuf.openIndex( idx_p3); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p3);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p3 = p3.begin(), e_p3 = p3.end();
		for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
		{
			delete *i_p3;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

analyzer::Document DocumentAnalyzerImpl::analyze(
			const std::string& p1, 
			const analyzer::DocumentClass& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_analyze), objid());
	analyzer::Document p0 = obj()->analyze(p1, p2);
	TraceSerializer parambuf;
	parambuf.packAnalyzerDocument(p0);
	parambuf.packString(p1);
	parambuf.packAnalyzerDocumentClass(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

DocumentAnalyzerContextInterface* DocumentAnalyzerImpl::createContext(
			const analyzer::DocumentClass& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentAnalyzer), DocumentAnalyzerConst::methodName( Method_createContext), objid());
	DocumentAnalyzerContextInterface* p0 = obj()->createContext(p1);
	p0 = traceContext()->createInterfaceImpl<DocumentAnalyzerContextInterface,DocumentAnalyzerContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createContext", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentAnalyzerContext), objbase_p0->objid());
		parambuf.packAnalyzerDocumentClass(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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

bool DocumentClassDetectorImpl::detect(
			analyzer::DocumentClass& p1, 
			const char* contentBegin, std::size_t p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentClassDetector), DocumentClassDetectorConst::methodName( Method_detect), objid());
	bool p0 = obj()->detect(p1, contentBegin, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packAnalyzerDocumentClass(p1);
	parambuf.packBuffer( contentBegin, p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "skipDoc", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

unsigned int DocumentTermIteratorImpl::termDocumentFrequency(
			const Index& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_DocumentTermIterator), DocumentTermIteratorConst::methodName( Method_termDocumentFrequency), objid());
	unsigned int p0 = obj()->termDocumentFrequency(p1);
	TraceSerializer parambuf;
	parambuf.packUInt(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "skipPos", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "skipDoc", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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

bool MetaDataReaderImpl::hasElement(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataReader), MetaDataReaderConst::methodName( Method_hasElement), objid());
	bool p0 = obj()->hasElement(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index MetaDataReaderImpl::elementHandle(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_MetaDataReader), MetaDataReaderConst::methodName( Method_elementHandle), objid());
	Index p0 = obj()->elementHandle(p1);
	TraceSerializer parambuf;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "elementHandle", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "nofElements", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getValue", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packNumericVariant(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getType", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharp(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getName", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharp(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_MetaDataRestrictionInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

NormalizerFunctionContextImpl::~NormalizerFunctionContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunctionContext), NormalizerFunctionContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::string NormalizerFunctionContextImpl::normalize(
			const char* src, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunctionContext), NormalizerFunctionContextConst::methodName( Method_normalize), objid());
	std::string p0 = obj()->normalize(src, p1);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packBuffer( src, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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

NormalizerFunctionContextInterface* NormalizerFunctionInstanceImpl::createFunctionContext() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), NormalizerFunctionInstanceConst::methodName( Method_createFunctionContext), objid());
	NormalizerFunctionContextInterface* p0 = obj()->createFunctionContext();
	p0 = traceContext()->createInterfaceImpl<NormalizerFunctionContextInterface,NormalizerFunctionContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createFunctionContext", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionContext), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* NormalizerFunctionImpl::getDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_NormalizerFunction), NormalizerFunctionConst::methodName( Method_getDescription), objid());
	const char* p0 = obj()->getDescription();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getDescription", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternLexerInstanceImpl::~PatternLexerInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool PatternLexerInstanceImpl::compile(
			const analyzer::PatternLexerOptions& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexerInstance), PatternLexerInstanceConst::methodName( Method_compile), objid());
	bool p0 = obj()->compile(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packAnalyzerPatternLexerOptions(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createContext", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternLexerContext), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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

std::vector<std::string> PatternLexerImpl::getCompileOptions() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexer), PatternLexerConst::methodName( Method_getCompileOptions), objid());
	std::vector<std::string> p0 = obj()->getCompileOptions();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternLexerInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* PatternLexerImpl::getDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternLexer), PatternLexerConst::methodName( Method_getDescription), objid());
	const char* p0 = obj()->getDescription();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getDescription", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<analyzer::PatternMatcherResult> PatternMatcherContextImpl::fetchResults() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherContext), PatternMatcherContextConst::methodName( Method_fetchResults), objid());
	std::vector<analyzer::PatternMatcherResult> p0 = obj()->fetchResults();
	TraceSerializer parambuf;
	parambuf.packAnalyzerPatternMatcherResultVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PatternMatcherInstanceImpl::~PatternMatcherInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternMatcherInstanceImpl::attachVariable(
			const std::string& p1, 
			float p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_attachVariable), objid());
	obj()->attachVariable(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packFloat(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void PatternMatcherInstanceImpl::definePattern(
			const std::string& p1, 
			bool p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_definePattern), objid());
	obj()->definePattern(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packBool(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool PatternMatcherInstanceImpl::compile(
			const analyzer::PatternMatcherOptions& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcherInstance), PatternMatcherInstanceConst::methodName( Method_compile), objid());
	bool p0 = obj()->compile(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packAnalyzerPatternMatcherOptions(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createContext", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternMatcherContext), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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

std::vector<std::string> PatternMatcherImpl::getCompileOptions() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcher), PatternMatcherConst::methodName( Method_getCompileOptions), objid());
	std::vector<std::string> p0 = obj()->getCompileOptions();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternMatcherInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* PatternMatcherImpl::getDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PatternMatcher), PatternMatcherConst::methodName( Method_getDescription), objid());
	const char* p0 = obj()->getDescription();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getDescription", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "skipDoc", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "skipDocCandidate", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "skipPos", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "featureid", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index PostingIteratorImpl::documentFrequency() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_documentFrequency), objid());
	Index p0 = obj()->documentFrequency();
	TraceSerializer parambuf;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "documentFrequency", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

unsigned int PostingIteratorImpl::frequency()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingIterator), PostingIteratorConst::methodName( Method_frequency), objid());
	unsigned int p0 = obj()->frequency();
	TraceSerializer parambuf;
	parambuf.packUInt(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "docno", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "posno", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createResultIterator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase_p0->objid());
		std::vector<Reference<PostingIteratorInterface> >::const_iterator
			i_p1 = p1.begin(), e_p1 = p1.end();
		for (std::size_t idx_p1=0; i_p1 != e_p1; ++i_p1,++idx_p1)
		{
			parambuf.openIndex( idx_p1); 
			const TraceObjectBase* objbase = dynamic_cast<const TraceObjectBase*>( i_p1->get());
			if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase->objid());
			parambuf.close();
		}
		parambuf.packInt(p2);
		parambuf.packUInt(p3);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

PostingJoinOperatorInterface::Description PostingJoinOperatorImpl::getDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_PostingJoinOperator), PostingJoinOperatorConst::methodName( Method_getDescription), objid());
	PostingJoinOperatorInterface::Description p0 = obj()->getDescription();
	TraceSerializer parambuf;
	parambuf.packPostingJoinOperatorDescription(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
			unsigned int p1, 
			const std::string& p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerContext), QueryAnalyzerContextConst::methodName( Method_putField), objid());
	obj()->putField(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packUInt(p1);
	parambuf.packString(p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryAnalyzerContextImpl::groupElements(
			unsigned int p1, 
			const std::vector<unsigned int>& p2, 
			const GroupBy& p3, 
			bool p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerContext), QueryAnalyzerContextConst::methodName( Method_groupElements), objid());
	obj()->groupElements(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packUInt(p1);
	parambuf.packUintVector(p2);
	parambuf.packAnalyzerQueryGroupBy(p3);
	parambuf.packBool(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

analyzer::Query QueryAnalyzerContextImpl::analyze()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzerContext), QueryAnalyzerContextConst::methodName( Method_analyze), objid());
	analyzer::Query p0 = obj()->analyze();
	TraceSerializer parambuf;
	parambuf.packAnalyzerQuery(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

QueryAnalyzerImpl::~QueryAnalyzerImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzer), QueryAnalyzerConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void QueryAnalyzerImpl::addSearchIndexElement(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzer), QueryAnalyzerConst::methodName( Method_addSearchIndexElement), objid());
	obj()->addSearchIndexElement(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryAnalyzerImpl::addMetaDataElement(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzer), QueryAnalyzerConst::methodName( Method_addMetaDataElement), objid());
	obj()->addMetaDataElement(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryAnalyzerImpl::addPatternLexem(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzer), QueryAnalyzerConst::methodName( Method_addPatternLexem), objid());
	obj()->addPatternLexem(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), objbase_p3->objid());
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		parambuf.openIndex( idx_p4); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p4);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryAnalyzerImpl::definePatternMatcherPostProc(
			const std::string& p1, 
			PatternMatcherInstanceInterface* p2, 
			PatternTermFeederInstanceInterface* p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzer), QueryAnalyzerConst::methodName( Method_definePatternMatcherPostProc), objid());
	obj()->definePatternMatcherPostProc(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternMatcherInstance), objbase_p2->objid());
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternTermFeederInstance), objbase_p3->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		if (p3) {delete p3; p3 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryAnalyzerImpl::definePatternMatcherPreProc(
			const std::string& p1, 
			PatternMatcherInstanceInterface* p2, 
			PatternLexerInstanceInterface* p3, 
			const std::vector<std::string>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzer), QueryAnalyzerConst::methodName( Method_definePatternMatcherPreProc), objid());
	obj()->definePatternMatcherPreProc(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternMatcherInstance), objbase_p2->objid());
	TraceObjectBase* objbase_p3 = dynamic_cast<TraceObjectBase*>( p3);
	if (!objbase_p3) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternLexerInstance), objbase_p3->objid());
	parambuf.packStringVector(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		if (p3) {delete p3; p3 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryAnalyzerImpl::addSearchIndexFeatureFromPatternMatch(
			const std::string& p1, 
			const std::string& p2, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzer), QueryAnalyzerConst::methodName( Method_addSearchIndexFeatureFromPatternMatch), objid());
	obj()->addSearchIndexFeatureFromPatternMatch(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p3 = p3.begin(), e_p3 = p3.end();
	for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
	{
		parambuf.openIndex( idx_p3); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p3);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p3 = p3.begin(), e_p3 = p3.end();
		for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
		{
			delete *i_p3;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryAnalyzerImpl::defineMetaDataFromPatternMatch(
			const std::string& p1, 
			const std::string& p2, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzer), QueryAnalyzerConst::methodName( Method_defineMetaDataFromPatternMatch), objid());
	obj()->defineMetaDataFromPatternMatch(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p3 = p3.begin(), e_p3 = p3.end();
	for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
	{
		parambuf.openIndex( idx_p3); 
		TraceObjectBase* objbase = dynamic_cast<TraceObjectBase*>( *i_p3);
		if (!objbase) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunctionInstance), objbase->objid());
		parambuf.close();
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p3 = p3.begin(), e_p3 = p3.end();
		for (std::size_t idx_p3=0; i_p3 != e_p3; ++i_p3,++idx_p3)
		{
			delete *i_p3;
		}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

QueryAnalyzerContextInterface* QueryAnalyzerImpl::createContext() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryAnalyzer), QueryAnalyzerConst::methodName( Method_createContext), objid());
	QueryAnalyzerContextInterface* p0 = obj()->createContext();
	p0 = traceContext()->createInterfaceImpl<QueryAnalyzerContextInterface,QueryAnalyzerContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createContext", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_QueryAnalyzerContext), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryEvalImpl::addWeightingFunction(
			const std::string& p1, 
			WeightingFunctionInstanceInterface* p2, 
			const std::vector<FeatureParameter>& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_QueryEval), QueryEvalConst::methodName( Method_addWeightingFunction), objid());
	obj()->addWeightingFunction(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), objbase_p2->objid());
	parambuf.packFeatureParameterVector(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p1) {delete p1; p1 = 0;}
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createQuery", traceContext()->errorbuf()->fetchError());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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

void QueryImpl::pushTerm(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_pushTerm), objid());
	obj()->pushTerm(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::addMetaDataRestrictionCondition(
			MetaDataRestrictionInterface::CompareOperator p1, 
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::setMaxNofRanks(
			std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_setMaxNofRanks), objid());
	obj()->setMaxNofRanks(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packSize( p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::setMinRank(
			std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_setMinRank), objid());
	obj()->setMinRank(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packSize( p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void QueryImpl::addUserName(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_addUserName), objid());
	obj()->addUserName(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

QueryResult QueryImpl::evaluate()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_evaluate), objid());
	QueryResult p0 = obj()->evaluate();
	TraceSerializer parambuf;
	parambuf.packQueryResult(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string QueryImpl::tostring() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Query), QueryConst::methodName( Method_tostring), objid());
	std::string p0 = obj()->tostring();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getPostingJoinOperator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingJoinOperator), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getWeightingFunction", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_WeightingFunction), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getSummarizerFunction", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SummarizerFunction), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getScalarFunctionParser", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ScalarFunctionParser), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string ScalarFunctionInstanceImpl::tostring() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunctionInstance), ScalarFunctionInstanceConst::methodName( Method_tostring), objid());
	std::string p0 = obj()->tostring();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ScalarFunctionInstance), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string ScalarFunctionImpl::tostring() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_ScalarFunction), ScalarFunctionConst::methodName( Method_tostring), objid());
	std::string p0 = obj()->tostring();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createFunction", traceContext()->errorbuf()->fetchError());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createContext", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SegmenterContext), objbase_p0->objid());
		parambuf.packAnalyzerDocumentClass(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createMarkupContext", traceContext()->errorbuf()->fetchError());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "mimeType", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SegmenterInstance), objbase_p0->objid());
		parambuf.packAnalyzerSegmenterOptions(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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

void StatisticsBuilderImpl::setNofDocumentsInsertedChange(
			int p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsBuilder), StatisticsBuilderConst::methodName( Method_setNofDocumentsInsertedChange), objid());
	obj()->setNofDocumentsInsertedChange(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packInt(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StatisticsBuilderImpl::start()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsBuilder), StatisticsBuilderConst::methodName( Method_start), objid());
	obj()->start();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StatisticsBuilderImpl::rollback()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsBuilder), StatisticsBuilderConst::methodName( Method_rollback), objid());
	obj()->rollback();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool StatisticsBuilderImpl::fetchMessage(
			const char*& blk, std::size_t& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsBuilder), StatisticsBuilderConst::methodName( Method_fetchMessage), objid());
	bool p0 = obj()->fetchMessage(blk, p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packBuffer( blk, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StatisticsIteratorImpl::~StatisticsIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsIterator), StatisticsIteratorConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool StatisticsIteratorImpl::getNext(
			const char*& msg, std::size_t& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsIterator), StatisticsIteratorConst::methodName( Method_getNext), objid());
	bool p0 = obj()->getNext(msg, p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packBuffer( msg, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
			const char* msgptr, std::size_t p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsProcessor), StatisticsProcessorConst::methodName( Method_createViewer), objid());
	StatisticsViewerInterface* p0 = obj()->createViewer(msgptr, p1);
	p0 = traceContext()->createInterfaceImpl<StatisticsViewerInterface,StatisticsViewerImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createViewer", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsViewer), objbase_p0->objid());
		parambuf.packBuffer( msgptr, p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StatisticsBuilderInterface* StatisticsProcessorImpl::createBuilder(
			const BuilderOptions& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsProcessor), StatisticsProcessorConst::methodName( Method_createBuilder), objid());
	StatisticsBuilderInterface* p0 = obj()->createBuilder(p1);
	p0 = traceContext()->createInterfaceImpl<StatisticsBuilderInterface,StatisticsBuilderImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createBuilder", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsBuilder), objbase_p0->objid());
		parambuf.packStatisticsProcessorBuilderOptions(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool StatisticsViewerImpl::nextDfChange(
			DocumentFrequencyChange& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StatisticsViewer), StatisticsViewerConst::methodName( Method_nextDfChange), objid());
	bool p0 = obj()->nextDfChange(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packStatisticsViewerDocumentFrequencyChange(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageAlterMetaDataTableImpl::~StorageAlterMetaDataTableImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageAlterMetaDataTable), StorageAlterMetaDataTableConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void StorageAlterMetaDataTableImpl::addElement(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageAlterMetaDataTable), StorageAlterMetaDataTableConst::methodName( Method_addElement), objid());
	obj()->addElement(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageAlterMetaDataTableImpl::alterElement(
			const std::string& p1, 
			const std::string& p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageAlterMetaDataTable), StorageAlterMetaDataTableConst::methodName( Method_alterElement), objid());
	obj()->alterElement(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageAlterMetaDataTableImpl::renameElement(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageAlterMetaDataTable), StorageAlterMetaDataTableConst::methodName( Method_renameElement), objid());
	obj()->renameElement(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packString(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageAlterMetaDataTableImpl::deleteElement(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageAlterMetaDataTable), StorageAlterMetaDataTableConst::methodName( Method_deleteElement), objid());
	obj()->deleteElement(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

void StorageAlterMetaDataTableImpl::clearElement(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageAlterMetaDataTable), StorageAlterMetaDataTableConst::methodName( Method_clearElement), objid());
	obj()->clearElement(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool StorageAlterMetaDataTableImpl::commit()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageAlterMetaDataTable), StorageAlterMetaDataTableConst::methodName( Method_commit), objid());
	bool p0 = obj()->commit();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

void StorageAlterMetaDataTableImpl::rollback()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageAlterMetaDataTable), StorageAlterMetaDataTableConst::methodName( Method_rollback), objid());
	obj()->rollback();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

StorageClientImpl::~StorageClientImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::string StorageClientImpl::config() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_config), objid());
	std::string p0 = obj()->config();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
			const std::string& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createTermPostingIterator), objid());
	PostingIteratorInterface* p0 = obj()->createTermPostingIterator(p1, p2);
	p0 = traceContext()->createInterfaceImpl<PostingIteratorInterface,PostingIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createTermPostingIterator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase_p0->objid());
		parambuf.packString(p1);
		parambuf.packString(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createBrowsePostingIterator", traceContext()->errorbuf()->fetchError());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createForwardIterator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ForwardIterator), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createDocumentTermIterator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_DocumentTermIterator), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInvAclIterator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_InvAclIterator), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "nofDocumentsInserted", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "documentFrequency", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packString(p1);
		parambuf.packString(p2);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "maxDocumentNumber", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "documentNumber", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createTermTypeIterator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ValueIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createTermValueIterator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ValueIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createDocIdIterator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ValueIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createUserNameIterator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_ValueIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "documentStatistics", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packIndex(p1);
		parambuf.packDocumentStatisticsType(p2);
		parambuf.packString(p3);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createMetaDataReader", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_MetaDataReader), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createMetaDataRestriction", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_MetaDataRestriction), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createAttributeReader", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_AttributeReader), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createTransaction", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageTransaction), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StatisticsIteratorInterface* StorageClientImpl::createInitStatisticsIterator(
			bool p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createInitStatisticsIterator), objid());
	StatisticsIteratorInterface* p0 = obj()->createInitStatisticsIterator(p1);
	p0 = traceContext()->createInterfaceImpl<StatisticsIteratorInterface,StatisticsIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInitStatisticsIterator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsIterator), objbase_p0->objid());
		parambuf.packBool(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StatisticsIteratorInterface* StorageClientImpl::createUpdateStatisticsIterator()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageClient), StorageClientConst::methodName( Method_createUpdateStatisticsIterator), objid());
	StatisticsIteratorInterface* p0 = obj()->createUpdateStatisticsIterator();
	p0 = traceContext()->createInterfaceImpl<StatisticsIteratorInterface,StatisticsIteratorImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createUpdateStatisticsIterator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsIterator), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getStatisticsProcessor", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsProcessor), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createDocumentChecker", traceContext()->errorbuf()->fetchError());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createClient", traceContext()->errorbuf()->fetchError());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageAlterMetaDataTableInterface* StorageImpl::createAlterMetaDataTable(
			const std::string& p1, 
			const DatabaseInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Storage), StorageConst::methodName( Method_createAlterMetaDataTable), objid());
	StorageAlterMetaDataTableInterface* p0 = obj()->createAlterMetaDataTable(p1, p2);
	p0 = traceContext()->createInterfaceImpl<StorageAlterMetaDataTableInterface,StorageAlterMetaDataTableImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createAlterMetaDataTable", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageAlterMetaDataTable), objbase_p0->objid());
		parambuf.packString(p1);
		const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* StorageImpl::getConfigDescription(
			const ConfigType& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Storage), StorageConst::methodName( Method_getConfigDescription), objid());
	const char* p0 = obj()->getConfigDescription(p1);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getConfigDescription", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharp(p0);
		parambuf.packStorageConfigType(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char** StorageImpl::getConfigParameters(
			const ConfigType& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Storage), StorageConst::methodName( Method_getConfigParameters), objid());
	const char** p0 = obj()->getConfigParameters(p1);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getConfigParameters", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharpp(p0);
		parambuf.packStorageConfigType(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

StorageDumpInterface* StorageImpl::createDump(
			const std::string& p1, 
			const DatabaseInterface* p2, 
			const std::string& p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_Storage), StorageConst::methodName( Method_createDump), objid());
	StorageDumpInterface* p0 = obj()->createDump(p1, p2, p3);
	p0 = traceContext()->createInterfaceImpl<StorageDumpInterface,StorageDumpImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createDump", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageDump), objbase_p0->objid());
		parambuf.packString(p1);
		const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
		parambuf.packString(p3);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getStorage", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Storage), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getDatabase", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getQueryProcessor", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_QueryProcessor), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getStatisticsProcessor", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StatisticsProcessor), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const VectorSpaceModelInterface* StorageObjectBuilderImpl::getVectorSpaceModel(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageObjectBuilder), StorageObjectBuilderConst::methodName( Method_getVectorSpaceModel), objid());
	const VectorSpaceModelInterface* p0 = obj()->getVectorSpaceModel(p1);
	p0 = traceContext()->createInterfaceImpl_const<VectorSpaceModelInterface,VectorSpaceModelImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getVectorSpaceModel", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_VectorSpaceModel), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createQueryEval", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_QueryEval), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createDocument", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageDocument), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createDocumentUpdate", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageDocumentUpdate), objbase_p0->objid());
		parambuf.packIndex(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool StorageTransactionImpl::commit()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_commit), objid());
	bool p0 = obj()->commit();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

unsigned int StorageTransactionImpl::nofDocumentsAffected() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_StorageTransaction), StorageTransactionConst::methodName( Method_nofDocumentsAffected), objid());
	unsigned int p0 = obj()->nofDocumentsAffected();
	TraceSerializer parambuf;
	parambuf.packUInt(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
			double p4, 
			const TermStatistics& p5)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionContext), SummarizerFunctionContextConst::methodName( Method_addSummarizationFeature), objid());
	obj()->addSummarizationFeature(p1, p2, p3, p4, p5);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase_p2->objid());
	parambuf.packSummarizationVariableVector(p3);
	parambuf.packDouble(p4);
	parambuf.packTermStatistics(p5);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<SummaryElement> SummarizerFunctionContextImpl::getSummary(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionContext), SummarizerFunctionContextConst::methodName( Method_getSummary), objid());
	std::vector<SummaryElement> p0 = obj()->getSummary(p1);
	TraceSerializer parambuf;
	parambuf.packSummaryElementVector(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

SummarizerFunctionContextInterface* SummarizerFunctionInstanceImpl::createFunctionContext(
			const StorageClientInterface* p1, 
			MetaDataReaderInterface* p2, 
			const GlobalStatistics& p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), SummarizerFunctionInstanceConst::methodName( Method_createFunctionContext), objid());
	SummarizerFunctionContextInterface* p0 = obj()->createFunctionContext(p1, p2, p3);
	p0 = traceContext()->createInterfaceImpl<SummarizerFunctionContextInterface,SummarizerFunctionContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createFunctionContext", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SummarizerFunctionContext), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageClient), objbase_p1->objid());
		TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_MetaDataReader), objbase_p2->objid());
		parambuf.packGlobalStatistics(p3);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string SummarizerFunctionInstanceImpl::tostring() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunctionInstance), SummarizerFunctionInstanceConst::methodName( Method_tostring), objid());
	std::string p0 = obj()->tostring();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

FunctionDescription SummarizerFunctionImpl::getDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_SummarizerFunction), SummarizerFunctionConst::methodName( Method_getDescription), objid());
	FunctionDescription p0 = obj()->getDescription();
	TraceSerializer parambuf;
	parambuf.packFunctionDescription(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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

void TextProcessorImpl::addResourcePath(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_addResourcePath), objid());
	obj()->addResourcePath(p1);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::string TextProcessorImpl::getResourcePath(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_getResourcePath), objid());
	std::string p0 = obj()->getResourcePath(p1);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getTokenizer", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunction), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getNormalizer", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_NormalizerFunction), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getAggregator", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_AggregatorFunction), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getPatternLexer", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternLexer), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getPatternMatcher", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternMatcher), objbase_p0->objid());
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getPatternTermFeeder", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		const TraceObjectBase* objbase_p0 = dynamic_cast<const TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PatternTermFeeder), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
			const char* contentBegin, std::size_t p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TextProcessor), TextProcessorConst::methodName( Method_detectDocumentClass), objid());
	bool p0 = obj()->detectDocumentClass(p1, contentBegin, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packAnalyzerDocumentClass(p1);
	parambuf.packBuffer( contentBegin, p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p1) {delete p1; p1 = 0;}
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

TokenizerFunctionContextImpl::~TokenizerFunctionContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunctionContext), TokenizerFunctionContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

std::vector<analyzer::Token> TokenizerFunctionContextImpl::tokenize(
			const char* src, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunctionContext), TokenizerFunctionContextConst::methodName( Method_tokenize), objid());
	std::vector<analyzer::Token> p0 = obj()->tokenize(src, p1);
	TraceSerializer parambuf;
	parambuf.packAnalyzerTokenVector(p0);
	parambuf.packBuffer( src, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

TokenizerFunctionContextInterface* TokenizerFunctionInstanceImpl::createFunctionContext() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunctionInstance), TokenizerFunctionInstanceConst::methodName( Method_createFunctionContext), objid());
	TokenizerFunctionContextInterface* p0 = obj()->createFunctionContext();
	p0 = traceContext()->createInterfaceImpl<TokenizerFunctionContextInterface,TokenizerFunctionContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createFunctionContext", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenizerFunctionContext), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

const char* TokenizerFunctionImpl::getDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenizerFunction), TokenizerFunctionConst::methodName( Method_getDescription), objid());
	const char* p0 = obj()->getDescription();
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "getDescription", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packCharp(p0);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
			const SegmenterPosition& p1, 
			std::size_t p2, 
			const SegmenterPosition& p3, 
			std::size_t p4, 
			const analyzer::TokenMarkup& p5, 
			unsigned int p6)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenMarkupContext), TokenMarkupContextConst::methodName( Method_putMarkup), objid());
	obj()->putMarkup(p1, p2, p3, p4, p5, p6);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packGlobalCounter(p1);
	parambuf.packSize( p2);
	parambuf.packGlobalCounter(p3);
	parambuf.packSize( p4);
	parambuf.packAnalyzerTokenMarkup(p5);
	parambuf.packUInt(p6);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::string TokenMarkupContextImpl::markupDocument(
			const SegmenterInstanceInterface* p1, 
			const analyzer::DocumentClass& p2, 
			const std::string& p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenMarkupContext), TokenMarkupContextConst::methodName( Method_markupDocument), objid());
	std::string p0 = obj()->markupDocument(p1, p2, p3);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
	if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_SegmenterInstance), objbase_p1->objid());
	parambuf.packAnalyzerDocumentClass(p2);
	parambuf.packString(p3);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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

TokenMarkupContextInterface* TokenMarkupInstanceImpl::createContext() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_TokenMarkupInstance), TokenMarkupInstanceConst::methodName( Method_createContext), objid());
	TokenMarkupContextInterface* p0 = obj()->createContext();
	p0 = traceContext()->createInterfaceImpl<TokenMarkupContextInterface,TokenMarkupContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createContext", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_TokenMarkupContext), objbase_p0->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorSpaceModelBuilderImpl::~VectorSpaceModelBuilderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelBuilder), VectorSpaceModelBuilderConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void VectorSpaceModelBuilderImpl::addFeature(
			const std::string& p1, 
			const std::vector<double>& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelBuilder), VectorSpaceModelBuilderConst::methodName( Method_addFeature), objid());
	obj()->addFeature(p1, p2);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	parambuf.packFloatVector(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

bool VectorSpaceModelBuilderImpl::done()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelBuilder), VectorSpaceModelBuilderConst::methodName( Method_done), objid());
	bool p0 = obj()->done();
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool VectorSpaceModelBuilderImpl::run(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelBuilder), VectorSpaceModelBuilderConst::methodName( Method_run), objid());
	bool p0 = obj()->run(p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorSpaceModelDumpImpl::~VectorSpaceModelDumpImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelDump), VectorSpaceModelDumpConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool VectorSpaceModelDumpImpl::nextChunk(
			const char*& chunk, std::size_t& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelDump), VectorSpaceModelDumpConst::methodName( Method_nextChunk), objid());
	bool p0 = obj()->nextChunk(chunk, p1);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packBuffer( chunk, p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorSpaceModelInstanceImpl::~VectorSpaceModelInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void VectorSpaceModelInstanceImpl::preload()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_preload), objid());
	obj()->preload();
	TraceSerializer parambuf;
	parambuf.packVoid();
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

std::vector<std::string> VectorSpaceModelInstanceImpl::conceptClassNames() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_conceptClassNames), objid());
	std::vector<std::string> p0 = obj()->conceptClassNames();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<Index> VectorSpaceModelInstanceImpl::conceptFeatures(
			const std::string& p1, 
			const Index& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_conceptFeatures), objid());
	std::vector<Index> p0 = obj()->conceptFeatures(p1, p2);
	TraceSerializer parambuf;
	parambuf.packIndexVector(p0);
	parambuf.packString(p1);
	parambuf.packIndex(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

unsigned int VectorSpaceModelInstanceImpl::nofConcepts(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_nofConcepts), objid());
	unsigned int p0 = obj()->nofConcepts(p1);
	TraceSerializer parambuf;
	parambuf.packUInt(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<Index> VectorSpaceModelInstanceImpl::findSimilarFeatures(
			const std::vector<double>& p1, 
			unsigned int p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_findSimilarFeatures), objid());
	std::vector<Index> p0 = obj()->findSimilarFeatures(p1, p2);
	TraceSerializer parambuf;
	parambuf.packIndexVector(p0);
	parambuf.packFloatVector(p1);
	parambuf.packUInt(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<Index> VectorSpaceModelInstanceImpl::featureConcepts(
			const std::string& p1, 
			const Index& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_featureConcepts), objid());
	std::vector<Index> p0 = obj()->featureConcepts(p1, p2);
	TraceSerializer parambuf;
	parambuf.packIndexVector(p0);
	parambuf.packString(p1);
	parambuf.packIndex(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<double> VectorSpaceModelInstanceImpl::featureVector(
			const Index& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_featureVector), objid());
	std::vector<double> p0 = obj()->featureVector(p1);
	TraceSerializer parambuf;
	parambuf.packFloatVector(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string VectorSpaceModelInstanceImpl::featureName(
			const Index& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_featureName), objid());
	std::string p0 = obj()->featureName(p1);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

Index VectorSpaceModelInstanceImpl::featureIndex(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_featureIndex), objid());
	Index p0 = obj()->featureIndex(p1);
	TraceSerializer parambuf;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "featureIndex", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		parambuf.packIndex(p0);
		parambuf.packString(p1);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> VectorSpaceModelInstanceImpl::featureAttributes(
			const std::string& p1, 
			const Index& p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_featureAttributes), objid());
	std::vector<std::string> p0 = obj()->featureAttributes(p1, p2);
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	parambuf.packString(p1);
	parambuf.packIndex(p2);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> VectorSpaceModelInstanceImpl::featureAttributeNames() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_featureAttributeNames), objid());
	std::vector<std::string> p0 = obj()->featureAttributeNames();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

unsigned int VectorSpaceModelInstanceImpl::nofFeatures() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_nofFeatures), objid());
	unsigned int p0 = obj()->nofFeatures();
	TraceSerializer parambuf;
	parambuf.packUInt(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string VectorSpaceModelInstanceImpl::config() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), VectorSpaceModelInstanceConst::methodName( Method_config), objid());
	std::string p0 = obj()->config();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorSpaceModelImpl::~VectorSpaceModelImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModel), VectorSpaceModelConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

bool VectorSpaceModelImpl::createRepository(
			const std::string& p1, 
			const DatabaseInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModel), VectorSpaceModelConst::methodName( Method_createRepository), objid());
	bool p0 = obj()->createRepository(p1, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

bool VectorSpaceModelImpl::resetRepository(
			const std::string& p1, 
			const DatabaseInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModel), VectorSpaceModelConst::methodName( Method_resetRepository), objid());
	bool p0 = obj()->resetRepository(p1, p2);
	TraceSerializer parambuf;
	parambuf.packBool(p0);
	parambuf.packString(p1);
	const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorSpaceModelInstanceInterface* VectorSpaceModelImpl::createInstance(
			const std::string& p1, 
			const DatabaseInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModel), VectorSpaceModelConst::methodName( Method_createInstance), objid());
	VectorSpaceModelInstanceInterface* p0 = obj()->createInstance(p1, p2);
	p0 = traceContext()->createInterfaceImpl<VectorSpaceModelInstanceInterface,VectorSpaceModelInstanceImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_VectorSpaceModelInstance), objbase_p0->objid());
		parambuf.packString(p1);
		const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorSpaceModelBuilderInterface* VectorSpaceModelImpl::createBuilder(
			const std::string& p1, 
			const DatabaseInterface* p2) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModel), VectorSpaceModelConst::methodName( Method_createBuilder), objid());
	VectorSpaceModelBuilderInterface* p0 = obj()->createBuilder(p1, p2);
	p0 = traceContext()->createInterfaceImpl<VectorSpaceModelBuilderInterface,VectorSpaceModelBuilderImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createBuilder", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_VectorSpaceModelBuilder), objbase_p0->objid());
		parambuf.packString(p1);
		const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::vector<std::string> VectorSpaceModelImpl::builderCommands() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModel), VectorSpaceModelConst::methodName( Method_builderCommands), objid());
	std::vector<std::string> p0 = obj()->builderCommands();
	TraceSerializer parambuf;
	parambuf.packStringVector(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string VectorSpaceModelImpl::builderCommandDescription(
			const std::string& p1) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModel), VectorSpaceModelConst::methodName( Method_builderCommandDescription), objid());
	std::string p0 = obj()->builderCommandDescription(p1);
	TraceSerializer parambuf;
	parambuf.packString(p0);
	parambuf.packString(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

VectorSpaceModelDumpInterface* VectorSpaceModelImpl::createDump(
			const std::string& p1, 
			const DatabaseInterface* p2, 
			const std::string& p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_VectorSpaceModel), VectorSpaceModelConst::methodName( Method_createDump), objid());
	VectorSpaceModelDumpInterface* p0 = obj()->createDump(p1, p2, p3);
	p0 = traceContext()->createInterfaceImpl<VectorSpaceModelDumpInterface,VectorSpaceModelDumpImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createDump", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_VectorSpaceModelDump), objbase_p0->objid());
		parambuf.packString(p1);
		const TraceObjectBase* objbase_p2 = dynamic_cast<const TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_Database), objbase_p2->objid());
		parambuf.packString(p3);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

WeightingFunctionContextImpl::~WeightingFunctionContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionContext), WeightingFunctionContextConst::methodName( Method_Destructor), objid());
	traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
}

void WeightingFunctionContextImpl::addWeightingFeature(
			const std::string& p1, 
			PostingIteratorInterface* p2, 
			double p3, 
			const TermStatistics& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionContext), WeightingFunctionContextConst::methodName( Method_addWeightingFeature), objid());
	obj()->addWeightingFeature(p1, p2, p3, p4);
	TraceSerializer parambuf;
	parambuf.packVoid();
	parambuf.packString(p1);
	TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
	if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_PostingIterator), objbase_p2->objid());
	parambuf.packDouble(p3);
	parambuf.packTermStatistics(p4);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

double WeightingFunctionContextImpl::call(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionContext), WeightingFunctionContextConst::methodName( Method_call), objid());
	double p0 = obj()->call(p1);
	TraceSerializer parambuf;
	parambuf.packDouble(p0);
	parambuf.packIndex(p1);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
}

WeightingFunctionContextInterface* WeightingFunctionInstanceImpl::createFunctionContext(
			const StorageClientInterface* p1, 
			MetaDataReaderInterface* p2, 
			const GlobalStatistics& p3) const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), WeightingFunctionInstanceConst::methodName( Method_createFunctionContext), objid());
	WeightingFunctionContextInterface* p0 = obj()->createFunctionContext(p1, p2, p3);
	p0 = traceContext()->createInterfaceImpl<WeightingFunctionContextInterface,WeightingFunctionContextImpl>( p0);
	TraceSerializer parambuf;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createFunctionContext", traceContext()->errorbuf()->fetchError());
	}
	else
	{
		TraceObjectBase* objbase_p0 = dynamic_cast<TraceObjectBase*>( p0);
		if (!objbase_p0) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_WeightingFunctionContext), objbase_p0->objid());
		const TraceObjectBase* objbase_p1 = dynamic_cast<const TraceObjectBase*>( p1);
		if (!objbase_p1) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_StorageClient), objbase_p1->objid());
		TraceObjectBase* objbase_p2 = dynamic_cast<TraceObjectBase*>( p2);
		if (!objbase_p2) parambuf.packVoid(); else parambuf.packObject( TraceClassNameMap::className( ClassId_MetaDataReader), objbase_p2->objid());
		parambuf.packGlobalStatistics(p3);
	}
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

std::string WeightingFunctionInstanceImpl::tostring() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunctionInstance), WeightingFunctionInstanceConst::methodName( Method_tostring), objid());
	std::string p0 = obj()->tostring();
	TraceSerializer parambuf;
	parambuf.packString(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
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
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), "createInstance", traceContext()->errorbuf()->fetchError());
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
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}

FunctionDescription WeightingFunctionImpl::getDescription() const
{
	TraceLogRecordHandle callhnd = traceContext()->logger()->logMethodCall( TraceClassNameMap::className( ClassId_WeightingFunction), WeightingFunctionConst::methodName( Method_getDescription), objid());
	FunctionDescription p0 = obj()->getDescription();
	TraceSerializer parambuf;
	parambuf.packFunctionDescription(p0);
	if (parambuf.hasError())
	{
		traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger()->logMethodTermination( callhnd, std::vector<TraceElement>());
	}
	else
	{
		traceContext()->logger()->logMethodTermination( callhnd, parambuf.content());
	}
	return p0;
}


