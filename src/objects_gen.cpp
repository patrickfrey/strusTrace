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
#include "traceSerializer.hpp"

using namespace strus;
AggregatorFunctionInstanceImpl::~AggregatorFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AggregatorFunctionInstance, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

double AggregatorFunctionInstanceImpl::evaluate(
			const analyzer::Document& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AggregatorFunctionInstance, Method_evaluate, objid());
	double p0 = obj()->evaluate(p1);
	TraceSerializer msg;
	msg.packScalar(p0);
	msg.packAnalyzerDocument(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

AggregatorFunctionImpl::~AggregatorFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AggregatorFunction, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

AggregatorFunctionInstanceInterface* AggregatorFunctionImpl::createInstance(
			const std::vector<std::string>& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AggregatorFunction, Method_createInstance, objid());
	AggregatorFunctionInstanceInterface* p0 = obj()->createInstance(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packStringVector(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const char* AggregatorFunctionImpl::getDescription()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AggregatorFunction, Method_getDescription, objid());
	const char* p0 = obj()->getDescription();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packCharp(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

AnalyzerObjectBuilderImpl::~AnalyzerObjectBuilderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AnalyzerObjectBuilder, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

const TextProcessorInterface* AnalyzerObjectBuilderImpl::getTextProcessor()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AnalyzerObjectBuilder, Method_getTextProcessor, objid());
	const TextProcessorInterface* p0 = obj()->getTextProcessor();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

SegmenterInterface* AnalyzerObjectBuilderImpl::createSegmenter(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AnalyzerObjectBuilder, Method_createSegmenter, objid());
	SegmenterInterface* p0 = obj()->createSegmenter(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DocumentAnalyzerInterface* AnalyzerObjectBuilderImpl::createDocumentAnalyzer(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AnalyzerObjectBuilder, Method_createDocumentAnalyzer, objid());
	DocumentAnalyzerInterface* p0 = obj()->createDocumentAnalyzer(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

QueryAnalyzerInterface* AnalyzerObjectBuilderImpl::createQueryAnalyzer()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AnalyzerObjectBuilder, Method_createQueryAnalyzer, objid());
	QueryAnalyzerInterface* p0 = obj()->createQueryAnalyzer();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

AttributeReaderImpl::~AttributeReaderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AttributeReader, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

Index AttributeReaderImpl::elementHandle(
			const char* p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AttributeReader, Method_elementHandle, objid());
	Index p0 = obj()->elementHandle(p1);
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
		msg.packCharp(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void AttributeReaderImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AttributeReader, Method_skipDoc, objid());
	obj()->skipDoc(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

std::string AttributeReaderImpl::getValue(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AttributeReader, Method_getValue, objid());
	std::string p0 = obj()->getValue(p1);
	TraceSerializer msg;
	msg.packString(p0);
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

std::vector<std::string> AttributeReaderImpl::getAttributeNames()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_AttributeReader, Method_getAttributeNames, objid());
	std::vector<std::string> p0 = obj()->getAttributeNames();
	TraceSerializer msg;
	msg.packStringVector(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DatabaseBackupCursorImpl::~DatabaseBackupCursorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseBackupCursor, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

bool DatabaseBackupCursorImpl::fetch(
			const char*& key, std::size_t& p1, 
			const char*& blk, std::size_t& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseBackupCursor, Method_fetch, objid());
	bool p0 = obj()->fetch(key, p1, blk, p2);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packBuffer( key, p1);
	msg.packBuffer( blk, p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DatabaseClientImpl::~DatabaseClientImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseClient, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

DatabaseTransactionInterface* DatabaseClientImpl::createTransaction()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseClient, Method_createTransaction, objid());
	DatabaseTransactionInterface* p0 = obj()->createTransaction();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DatabaseCursorInterface* DatabaseClientImpl::createCursor(
			const DatabaseOptions& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseClient, Method_createCursor, objid());
	DatabaseCursorInterface* p0 = obj()->createCursor(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packDatabaseOptions(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DatabaseBackupCursorInterface* DatabaseClientImpl::createBackupCursor()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseClient, Method_createBackupCursor, objid());
	DatabaseBackupCursorInterface* p0 = obj()->createBackupCursor();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void DatabaseClientImpl::writeImm(
			const char* key, std::size_t p1, 
			const char* value, std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseClient, Method_writeImm, objid());
	obj()->writeImm(key, p1, value, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packBuffer( key, p1);
	msg.packBuffer( value, p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void DatabaseClientImpl::removeImm(
			const char* key, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseClient, Method_removeImm, objid());
	obj()->removeImm(key, p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packBuffer( key, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

bool DatabaseClientImpl::readValue(
			const char* key, std::size_t p1, 
			std::string& p2, 
			const DatabaseOptions& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseClient, Method_readValue, objid());
	bool p0 = obj()->readValue(key, p1, p2, p3);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packBuffer( key, p1);
	msg.packString(p2);
	msg.packDatabaseOptions(p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DatabaseCursorImpl::~DatabaseCursorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseCursor, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

Slice DatabaseCursorImpl::seekUpperBound(
			const char* key, std::size_t p1, 
			std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseCursor, Method_seekUpperBound, objid());
	Slice p0 = obj()->seekUpperBound(key, p1, p2);
	TraceSerializer msg;
	msg.packSlice(p0);
	msg.packBuffer( key, p1);
	msg.packScalar(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Slice DatabaseCursorImpl::seekUpperBoundRestricted(
			const char* key, std::size_t p1, 
			const char* upkey, std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseCursor, Method_seekUpperBoundRestricted, objid());
	Slice p0 = obj()->seekUpperBoundRestricted(key, p1, upkey, p2);
	TraceSerializer msg;
	msg.packSlice(p0);
	msg.packBuffer( key, p1);
	msg.packBuffer( upkey, p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Slice DatabaseCursorImpl::seekFirst(
			const char* domainkey, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseCursor, Method_seekFirst, objid());
	Slice p0 = obj()->seekFirst(domainkey, p1);
	TraceSerializer msg;
	msg.packSlice(p0);
	msg.packBuffer( domainkey, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Slice DatabaseCursorImpl::seekLast(
			const char* domainkey, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseCursor, Method_seekLast, objid());
	Slice p0 = obj()->seekLast(domainkey, p1);
	TraceSerializer msg;
	msg.packSlice(p0);
	msg.packBuffer( domainkey, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Slice DatabaseCursorImpl::seekNext()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseCursor, Method_seekNext, objid());
	Slice p0 = obj()->seekNext();
	TraceSerializer msg;
	msg.packSlice(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Slice DatabaseCursorImpl::seekPrev()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseCursor, Method_seekPrev, objid());
	Slice p0 = obj()->seekPrev();
	TraceSerializer msg;
	msg.packSlice(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Slice DatabaseCursorImpl::key()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseCursor, Method_key, objid());
	Slice p0 = obj()->key();
	TraceSerializer msg;
	msg.packSlice(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Slice DatabaseCursorImpl::value()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseCursor, Method_value, objid());
	Slice p0 = obj()->value();
	TraceSerializer msg;
	msg.packSlice(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DatabaseImpl::~DatabaseImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Database, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

bool DatabaseImpl::exists(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Database, Method_exists, objid());
	bool p0 = obj()->exists(p1);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DatabaseClientInterface* DatabaseImpl::createClient(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Database, Method_createClient, objid());
	DatabaseClientInterface* p0 = obj()->createClient(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

bool DatabaseImpl::createDatabase(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Database, Method_createDatabase, objid());
	bool p0 = obj()->createDatabase(p1);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

bool DatabaseImpl::restoreDatabase(
			const std::string& p1, 
			DatabaseBackupCursorInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Database, Method_restoreDatabase, objid());
	bool p0 = obj()->restoreDatabase(p1, p2);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packString(p1);
	msg.packObject(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

bool DatabaseImpl::destroyDatabase(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Database, Method_destroyDatabase, objid());
	bool p0 = obj()->destroyDatabase(p1);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const char* DatabaseImpl::getConfigDescription(
			const ConfigType& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Database, Method_getConfigDescription, objid());
	const char* p0 = obj()->getConfigDescription(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packCharp(p0);
		msg.packDatabaseConfigType(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const char** DatabaseImpl::getConfigParameters(
			const ConfigType& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Database, Method_getConfigParameters, objid());
	const char** p0 = obj()->getConfigParameters(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packCharpp(p0);
		msg.packDatabaseConfigType(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DatabaseTransactionImpl::~DatabaseTransactionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseTransaction, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

DatabaseCursorInterface* DatabaseTransactionImpl::createCursor(
			const DatabaseOptions& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseTransaction, Method_createCursor, objid());
	DatabaseCursorInterface* p0 = obj()->createCursor(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packDatabaseOptions(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void DatabaseTransactionImpl::write(
			const char* key, std::size_t p1, 
			const char* value, std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseTransaction, Method_write, objid());
	obj()->write(key, p1, value, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packBuffer( key, p1);
	msg.packBuffer( value, p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void DatabaseTransactionImpl::remove(
			const char* key, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseTransaction, Method_remove, objid());
	obj()->remove(key, p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packBuffer( key, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void DatabaseTransactionImpl::removeSubTree(
			const char* domainkey, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseTransaction, Method_removeSubTree, objid());
	obj()->removeSubTree(domainkey, p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packBuffer( domainkey, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

bool DatabaseTransactionImpl::commit()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseTransaction, Method_commit, objid());
	bool p0 = obj()->commit();
	TraceSerializer msg;
	msg.packBool(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void DatabaseTransactionImpl::rollback()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DatabaseTransaction, Method_rollback, objid());
	obj()->rollback();
	TraceSerializer msg;
	msg.packVoid();
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

DocumentAnalyzerContextImpl::~DocumentAnalyzerContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzerContext, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void DocumentAnalyzerContextImpl::putInput(
			const char* chunk, std::size_t p1, 
			bool p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzerContext, Method_putInput, objid());
	obj()->putInput(chunk, p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packBuffer( chunk, p1);
	msg.packBool(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

bool DocumentAnalyzerContextImpl::analyzeNext(
			analyzer::Document& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzerContext, Method_analyzeNext, objid());
	bool p0 = obj()->analyzeNext(p1);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packAnalyzerDocument(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DocumentAnalyzerImpl::~DocumentAnalyzerImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzer, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void DocumentAnalyzerImpl::addSearchIndexFeature(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			const FeatureOptions& p5)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzer, Method_addSearchIndexFeature, objid());
	obj()->addSearchIndexFeature(p1, p2, p3, p4, p5);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	msg.packObject(p3);
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		msg.openIndex( idx_p4);
		msg.packObject(**i_p4);
		msg.close();
	}
	msg.packFeatureOptions(p5);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		p4.clear();
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void DocumentAnalyzerImpl::addForwardIndexFeature(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4, 
			const FeatureOptions& p5)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzer, Method_addForwardIndexFeature, objid());
	obj()->addForwardIndexFeature(p1, p2, p3, p4, p5);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	msg.packObject(p3);
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		msg.openIndex( idx_p4);
		msg.packObject(**i_p4);
		msg.close();
	}
	msg.packFeatureOptions(p5);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		p4.clear();
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void DocumentAnalyzerImpl::defineMetaData(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzer, Method_defineMetaData, objid());
	obj()->defineMetaData(p1, p2, p3, p4);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	msg.packObject(p3);
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		msg.openIndex( idx_p4);
		msg.packObject(**i_p4);
		msg.close();
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		p4.clear();
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void DocumentAnalyzerImpl::defineAggregatedMetaData(
			const std::string& p1, 
			AggregatorFunctionInstanceInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzer, Method_defineAggregatedMetaData, objid());
	obj()->defineAggregatedMetaData(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void DocumentAnalyzerImpl::defineAttribute(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzer, Method_defineAttribute, objid());
	obj()->defineAttribute(p1, p2, p3, p4);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	msg.packObject(p3);
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		msg.openIndex( idx_p4);
		msg.packObject(**i_p4);
		msg.close();
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		p4.clear();
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void DocumentAnalyzerImpl::defineSubDocument(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzer, Method_defineSubDocument, objid());
	obj()->defineSubDocument(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

analyzer::Document DocumentAnalyzerImpl::analyze(
			const std::string& p1, 
			const DocumentClass& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzer, Method_analyze, objid());
	analyzer::Document p0 = obj()->analyze(p1, p2);
	TraceSerializer msg;
	msg.packAnalyzerDocument(p0);
	msg.packString(p1);
	msg.packDocumentClass(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DocumentAnalyzerContextInterface* DocumentAnalyzerImpl::createContext(
			const DocumentClass& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentAnalyzer, Method_createContext, objid());
	DocumentAnalyzerContextInterface* p0 = obj()->createContext(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packDocumentClass(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DocumentClassDetectorImpl::~DocumentClassDetectorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentClassDetector, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

bool DocumentClassDetectorImpl::detect(
			DocumentClass& p1, 
			const char* contentBegin, std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentClassDetector, Method_detect, objid());
	bool p0 = obj()->detect(p1, contentBegin, p2);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packDocumentClass(p1);
	msg.packBuffer( contentBegin, p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DocumentTermIteratorImpl::~DocumentTermIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentTermIterator, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

Index DocumentTermIteratorImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentTermIterator, Method_skipDoc, objid());
	Index p0 = obj()->skipDoc(p1);
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
		msg.packScalar(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

bool DocumentTermIteratorImpl::nextTerm(
			Term& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentTermIterator, Method_nextTerm, objid());
	bool p0 = obj()->nextTerm(p1);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packDocumentTermIteratorTerm(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

unsigned int DocumentTermIteratorImpl::termDocumentFrequency(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentTermIterator, Method_termDocumentFrequency, objid());
	unsigned int p0 = obj()->termDocumentFrequency(p1);
	TraceSerializer msg;
	msg.packScalar(p0);
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

std::string DocumentTermIteratorImpl::termValue(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_DocumentTermIterator, Method_termValue, objid());
	std::string p0 = obj()->termValue(p1);
	TraceSerializer msg;
	msg.packString(p0);
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

ForwardIteratorImpl::~ForwardIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ForwardIterator, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void ForwardIteratorImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ForwardIterator, Method_skipDoc, objid());
	obj()->skipDoc(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

Index ForwardIteratorImpl::skipPos(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ForwardIterator, Method_skipPos, objid());
	Index p0 = obj()->skipPos(p1);
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
		msg.packScalar(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

std::string ForwardIteratorImpl::fetch()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ForwardIterator, Method_fetch, objid());
	std::string p0 = obj()->fetch();
	TraceSerializer msg;
	msg.packString(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

InvAclIteratorImpl::~InvAclIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_InvAclIterator, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

Index InvAclIteratorImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_InvAclIterator, Method_skipDoc, objid());
	Index p0 = obj()->skipDoc(p1);
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
		msg.packScalar(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

MetaDataReaderImpl::~MetaDataReaderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataReader, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

bool MetaDataReaderImpl::hasElement(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataReader, Method_hasElement, objid());
	bool p0 = obj()->hasElement(p1);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index MetaDataReaderImpl::elementHandle(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataReader, Method_elementHandle, objid());
	Index p0 = obj()->elementHandle(p1);
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index MetaDataReaderImpl::nofElements()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataReader, Method_nofElements, objid());
	Index p0 = obj()->nofElements();
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void MetaDataReaderImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataReader, Method_skipDoc, objid());
	obj()->skipDoc(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

NumericVariant MetaDataReaderImpl::getValue(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataReader, Method_getValue, objid());
	NumericVariant p0 = obj()->getValue(p1);
	TraceSerializer msg;
	if (!p0.defined())
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packNumericVariant(p0);
		msg.packScalar(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const char* MetaDataReaderImpl::getType(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataReader, Method_getType, objid());
	const char* p0 = obj()->getType(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packCharp(p0);
		msg.packScalar(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const char* MetaDataReaderImpl::getName(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataReader, Method_getName, objid());
	const char* p0 = obj()->getName(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packCharp(p0);
		msg.packScalar(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

MetaDataRestrictionInstanceImpl::~MetaDataRestrictionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataRestrictionInstance, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

bool MetaDataRestrictionInstanceImpl::match(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataRestrictionInstance, Method_match, objid());
	bool p0 = obj()->match(p1);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

MetaDataRestrictionImpl::~MetaDataRestrictionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataRestriction, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void MetaDataRestrictionImpl::addCondition(
			const CompareOperator& p1, 
			const std::string& p2, 
			const NumericVariant& p3, 
			bool p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataRestriction, Method_addCondition, objid());
	obj()->addCondition(p1, p2, p3, p4);
	TraceSerializer msg;
	msg.packVoid();
	msg.packMetaDataRestrictionCompareOperator(p1);
	msg.packString(p2);
	msg.packNumericVariant(p3);
	msg.packBool(p4);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

MetaDataRestrictionInstanceInterface* MetaDataRestrictionImpl::createInstance()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataRestriction, Method_createInstance, objid());
	MetaDataRestrictionInstanceInterface* p0 = obj()->createInstance();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

std::string MetaDataRestrictionImpl::tostring()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_MetaDataRestriction, Method_tostring, objid());
	std::string p0 = obj()->tostring();
	TraceSerializer msg;
	msg.packString(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

NormalizerFunctionContextImpl::~NormalizerFunctionContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_NormalizerFunctionContext, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

std::string NormalizerFunctionContextImpl::normalize(
			const char* src, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_NormalizerFunctionContext, Method_normalize, objid());
	std::string p0 = obj()->normalize(src, p1);
	TraceSerializer msg;
	msg.packString(p0);
	msg.packBuffer( src, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

NormalizerFunctionInstanceImpl::~NormalizerFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_NormalizerFunctionInstance, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

NormalizerFunctionContextInterface* NormalizerFunctionInstanceImpl::createFunctionContext()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_NormalizerFunctionInstance, Method_createFunctionContext, objid());
	NormalizerFunctionContextInterface* p0 = obj()->createFunctionContext();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

NormalizerFunctionImpl::~NormalizerFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_NormalizerFunction, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

NormalizerFunctionInstanceInterface* NormalizerFunctionImpl::createInstance(
			const std::vector<std::string>& p1, 
			const TextProcessorInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_NormalizerFunction, Method_createInstance, objid());
	NormalizerFunctionInstanceInterface* p0 = obj()->createInstance(p1, p2);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packStringVector(p1);
		msg.packObject(p2);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const char* NormalizerFunctionImpl::getDescription()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_NormalizerFunction, Method_getDescription, objid());
	const char* p0 = obj()->getDescription();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packCharp(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

PostingIteratorImpl::~PostingIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingIterator, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

Index PostingIteratorImpl::skipDoc(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingIterator, Method_skipDoc, objid());
	Index p0 = obj()->skipDoc(p1);
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
		msg.packScalar(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index PostingIteratorImpl::skipDocCandidate(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingIterator, Method_skipDocCandidate, objid());
	Index p0 = obj()->skipDocCandidate(p1);
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
		msg.packScalar(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index PostingIteratorImpl::skipPos(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingIterator, Method_skipPos, objid());
	Index p0 = obj()->skipPos(p1);
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
		msg.packScalar(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const char* PostingIteratorImpl::featureid()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingIterator, Method_featureid, objid());
	const char* p0 = obj()->featureid();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packCharp(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index PostingIteratorImpl::documentFrequency()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingIterator, Method_documentFrequency, objid());
	Index p0 = obj()->documentFrequency();
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

unsigned int PostingIteratorImpl::frequency()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingIterator, Method_frequency, objid());
	unsigned int p0 = obj()->frequency();
	TraceSerializer msg;
	msg.packScalar(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index PostingIteratorImpl::docno()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingIterator, Method_docno, objid());
	Index p0 = obj()->docno();
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index PostingIteratorImpl::posno()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingIterator, Method_posno, objid());
	Index p0 = obj()->posno();
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

PostingJoinOperatorImpl::~PostingJoinOperatorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingJoinOperator, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

PostingIteratorInterface* PostingJoinOperatorImpl::createResultIterator(
			const std::vector<Reference<PostingIteratorInterface> >& p1, 
			int p2, 
			unsigned int p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingJoinOperator, Method_createResultIterator, objid());
	PostingIteratorInterface* p0 = obj()->createResultIterator(p1, p2, p3);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		const std::vector<Reference<PostingIteratorInterface> >::const_iterator
			i_p1 = p1.begin(), e_p1 = p1.end();
		for (std::size_t idx_p1=0; i_p1 != e_p1; ++i_p1,++idx_p1)
		{
			msg.openIndex( idx_p1); 
			msg.packObject(**i_p1);
			msg.close();
		}
		msg.packScalar(p2);
		msg.packScalar(p3);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Description PostingJoinOperatorImpl::getDescription()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_PostingJoinOperator, Method_getDescription, objid());
	Description p0 = obj()->getDescription();
	TraceSerializer msg;
	msg.packPostingJoinOperatorDescription(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

QueryAnalyzerImpl::~QueryAnalyzerImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryAnalyzer, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void QueryAnalyzerImpl::definePhraseType(
			const std::string& p1, 
			const std::string& p2, 
			TokenizerFunctionInstanceInterface* p3, 
			const std::vector<NormalizerFunctionInstanceInterface*>& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryAnalyzer, Method_definePhraseType, objid());
	obj()->definePhraseType(p1, p2, p3, p4);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	msg.packObject(p3);
	std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
		i_p4 = p4.begin(), e_p4 = p4.end();
	for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
	{
		msg.openIndex( idx_p4);
		msg.packObject(**i_p4);
		msg.close();
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p3) {delete p3; p3 = 0;}
		std::vector<NormalizerFunctionInstanceInterface*>::const_iterator
			i_p4 = p4.begin(), e_p4 = p4.end();
		for (std::size_t idx_p4=0; i_p4 != e_p4; ++i_p4,++idx_p4)
		{
			delete *i_p4;
		}
		p4.clear();
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

std::vector<analyzer::Term> QueryAnalyzerImpl::analyzePhrase(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryAnalyzer, Method_analyzePhrase, objid());
	std::vector<analyzer::Term> p0 = obj()->analyzePhrase(p1, p2);
	TraceSerializer msg;
	msg.packAnalyzerTermVector(p0);
	msg.packString(p1);
	msg.packString(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

std::vector<analyzer::TermVector> QueryAnalyzerImpl::analyzePhraseBulk(
			const std::vector<Phrase>& phraseBulk p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryAnalyzer, Method_analyzePhraseBulk, objid());
	std::vector<analyzer::TermVector> p0 = obj()->analyzePhraseBulk(p1);
	TraceSerializer msg;
	msg.packAnalyzerTermVectorVector(p0);
	msg.packPhraseVector(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

QueryEvalImpl::~QueryEvalImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryEval, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void QueryEvalImpl::addTerm(
			const std::string& p1, 
			const std::string& p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryEval, Method_addTerm, objid());
	obj()->addTerm(p1, p2, p3);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	msg.packString(p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryEvalImpl::addSelectionFeature(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryEval, Method_addSelectionFeature, objid());
	obj()->addSelectionFeature(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryEvalImpl::addRestrictionFeature(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryEval, Method_addRestrictionFeature, objid());
	obj()->addRestrictionFeature(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryEvalImpl::addExclusionFeature(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryEval, Method_addExclusionFeature, objid());
	obj()->addExclusionFeature(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryEvalImpl::addSummarizerFunction(
			const std::string& p1, 
			SummarizerFunctionInstanceInterface* p2, 
			const std::vector<FeatureParameter>& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryEval, Method_addSummarizerFunction, objid());
	obj()->addSummarizerFunction(p1, p2, p3);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	msg.packFeatureParameterVector(p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryEvalImpl::addWeightingFunction(
			const std::string& p1, 
			WeightingFunctionInstanceInterface* p2, 
			const std::vector<FeatureParameter>& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryEval, Method_addWeightingFunction, objid());
	obj()->addWeightingFunction(p1, p2, p3);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	msg.packFeatureParameterVector(p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryEvalImpl::defineWeightingFormula(
			ScalarFunctionInterface* p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryEval, Method_defineWeightingFormula, objid());
	obj()->defineWeightingFormula(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packObject(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p1) {delete p1; p1 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

QueryInterface* QueryEvalImpl::createQuery(
			const StorageClientInterface* p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryEval, Method_createQuery, objid());
	QueryInterface* p0 = obj()->createQuery(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packObject(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

QueryImpl::~QueryImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void QueryImpl::pushTerm(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_pushTerm, objid());
	obj()->pushTerm(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryImpl::pushExpression(
			const PostingJoinOperatorInterface* p1, 
			std::size_t p2, 
			int p3, 
			unsigned int p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_pushExpression, objid());
	obj()->pushExpression(p1, p2, p3, p4);
	TraceSerializer msg;
	msg.packVoid();
	msg.packObject(p1);
	msg.packScalar(p2);
	msg.packScalar(p3);
	msg.packScalar(p4);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryImpl::attachVariable(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_attachVariable, objid());
	obj()->attachVariable(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryImpl::defineFeature(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_defineFeature, objid());
	obj()->defineFeature(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packScalar(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryImpl::defineTermStatistics(
			const std::string& p1, 
			const std::string& p2, 
			const TermStatistics& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_defineTermStatistics, objid());
	obj()->defineTermStatistics(p1, p2, p3);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	msg.packTermStatistics(p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryImpl::defineGlobalStatistics(
			const GlobalStatistics& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_defineGlobalStatistics, objid());
	obj()->defineGlobalStatistics(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packGlobalStatistics(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryImpl::addMetaDataRestrictionCondition(
			MetaDataRestrictionInterface::CompareOperator p1, 
			const std::string& p2, 
			const NumericVariant& p3, 
			bool p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_addMetaDataRestrictionCondition, objid());
	obj()->addMetaDataRestrictionCondition(p1, p2, p3, p4);
	TraceSerializer msg;
	msg.packVoid();
	msg.packMetaDataRestrictionCompareOperator(p1);
	msg.packString(p2);
	msg.packNumericVariant(p3);
	msg.packBool(p4);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryImpl::addDocumentEvaluationSet(
			const std::vector<Index>& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_addDocumentEvaluationSet, objid());
	obj()->addDocumentEvaluationSet(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packIndexVector(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryImpl::setMaxNofRanks(
			std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_setMaxNofRanks, objid());
	obj()->setMaxNofRanks(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryImpl::setMinRank(
			std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_setMinRank, objid());
	obj()->setMinRank(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryImpl::addUserName(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_addUserName, objid());
	obj()->addUserName(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void QueryImpl::setWeightingVariableValue(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_setWeightingVariableValue, objid());
	obj()->setWeightingVariableValue(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packScalar(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

QueryResult QueryImpl::evaluate()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Query, Method_evaluate, objid());
	QueryResult p0 = obj()->evaluate();
	TraceSerializer msg;
	msg.packQueryResult(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

QueryProcessorImpl::~QueryProcessorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryProcessor, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void QueryProcessorImpl::definePostingJoinOperator(
			const std::string& p1, 
			PostingJoinOperatorInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryProcessor, Method_definePostingJoinOperator, objid());
	obj()->definePostingJoinOperator(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

const PostingJoinOperatorInterface* QueryProcessorImpl::getPostingJoinOperator(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryProcessor, Method_getPostingJoinOperator, objid());
	const PostingJoinOperatorInterface* p0 = obj()->getPostingJoinOperator(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void QueryProcessorImpl::defineWeightingFunction(
			const std::string& p1, 
			WeightingFunctionInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryProcessor, Method_defineWeightingFunction, objid());
	obj()->defineWeightingFunction(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

const WeightingFunctionInterface* QueryProcessorImpl::getWeightingFunction(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryProcessor, Method_getWeightingFunction, objid());
	const WeightingFunctionInterface* p0 = obj()->getWeightingFunction(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void QueryProcessorImpl::defineSummarizerFunction(
			const std::string& p1, 
			SummarizerFunctionInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryProcessor, Method_defineSummarizerFunction, objid());
	obj()->defineSummarizerFunction(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

const SummarizerFunctionInterface* QueryProcessorImpl::getSummarizerFunction(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryProcessor, Method_getSummarizerFunction, objid());
	const SummarizerFunctionInterface* p0 = obj()->getSummarizerFunction(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

std::vector<std::string> QueryProcessorImpl::getFunctionList(
			const FunctionType& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryProcessor, Method_getFunctionList, objid());
	std::vector<std::string> p0 = obj()->getFunctionList(p1);
	TraceSerializer msg;
	msg.packStringVector(p0);
	msg.packQueryProcessorFunctionType(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void QueryProcessorImpl::defineScalarFunctionParser(
			const std::string& p1, 
			ScalarFunctionParserInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryProcessor, Method_defineScalarFunctionParser, objid());
	obj()->defineScalarFunctionParser(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

const ScalarFunctionParserInterface* QueryProcessorImpl::getScalarFunctionParser(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_QueryProcessor, Method_getScalarFunctionParser, objid());
	const ScalarFunctionParserInterface* p0 = obj()->getScalarFunctionParser(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

ScalarFunctionInstanceImpl::~ScalarFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunctionInstance, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void ScalarFunctionInstanceImpl::setVariableValue(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunctionInstance, Method_setVariableValue, objid());
	obj()->setVariableValue(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packScalar(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

double ScalarFunctionInstanceImpl::call(
			const double* args, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunctionInstance, Method_call, objid());
	double p0 = obj()->call(args, p1);
	TraceSerializer msg;
	msg.packScalar(p0);
	msg.packBufferFloat( args, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

std::string ScalarFunctionInstanceImpl::tostring()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunctionInstance, Method_tostring, objid());
	std::string p0 = obj()->tostring();
	TraceSerializer msg;
	msg.packString(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

ScalarFunctionImpl::~ScalarFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunction, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

std::vector<std::string> ScalarFunctionImpl::getVariables()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunction, Method_getVariables, objid());
	std::vector<std::string> p0 = obj()->getVariables();
	TraceSerializer msg;
	msg.packStringVector(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

std::size_t ScalarFunctionImpl::getNofArguments()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunction, Method_getNofArguments, objid());
	std::size_t p0 = obj()->getNofArguments();
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void ScalarFunctionImpl::setDefaultVariableValue(
			const std::string& p1, 
			double p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunction, Method_setDefaultVariableValue, objid());
	obj()->setDefaultVariableValue(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packScalar(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

ScalarFunctionInstanceInterface* ScalarFunctionImpl::createInstance()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunction, Method_createInstance, objid());
	ScalarFunctionInstanceInterface* p0 = obj()->createInstance();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

std::string ScalarFunctionImpl::tostring()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunction, Method_tostring, objid());
	std::string p0 = obj()->tostring();
	TraceSerializer msg;
	msg.packString(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

ScalarFunctionParserImpl::~ScalarFunctionParserImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunctionParser, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

ScalarFunctionInterface* ScalarFunctionParserImpl::createFunction(
			const std::string& p1, 
			const std::vector<std::string>& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ScalarFunctionParser, Method_createFunction, objid());
	ScalarFunctionInterface* p0 = obj()->createFunction(p1, p2);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
		msg.packStringVector(p2);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

SegmenterContextImpl::~SegmenterContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SegmenterContext, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void SegmenterContextImpl::putInput(
			const char* chunk, std::size_t p1, 
			bool p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SegmenterContext, Method_putInput, objid());
	obj()->putInput(chunk, p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packBuffer( chunk, p1);
	msg.packBool(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

bool SegmenterContextImpl::getNext(
			int& p1, 
			SegmenterPosition& p2, 
			const char*& segment, std::size_t& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SegmenterContext, Method_getNext, objid());
	bool p0 = obj()->getNext(p1, p2, segment, p3);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packScalar(p1);
	msg.packScalar(p2);
	msg.packBuffer( segment, p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

SegmenterInstanceImpl::~SegmenterInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SegmenterInstance, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void SegmenterInstanceImpl::defineSelectorExpression(
			int p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SegmenterInstance, Method_defineSelectorExpression, objid());
	obj()->defineSelectorExpression(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packScalar(p1);
	msg.packString(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void SegmenterInstanceImpl::defineSubSection(
			int p1, 
			int p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SegmenterInstance, Method_defineSubSection, objid());
	obj()->defineSubSection(p1, p2, p3);
	TraceSerializer msg;
	msg.packVoid();
	msg.packScalar(p1);
	msg.packScalar(p2);
	msg.packString(p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

SegmenterContextInterface* SegmenterInstanceImpl::createContext(
			const DocumentClass& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SegmenterInstance, Method_createContext, objid());
	SegmenterContextInterface* p0 = obj()->createContext(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packDocumentClass(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

SegmenterImpl::~SegmenterImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Segmenter, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

const char* SegmenterImpl::mimeType()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Segmenter, Method_mimeType, objid());
	const char* p0 = obj()->mimeType();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packCharp(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

SegmenterInstanceInterface* SegmenterImpl::createInstance()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Segmenter, Method_createInstance, objid());
	SegmenterInstanceInterface* p0 = obj()->createInstance();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StatisticsBuilderImpl::~StatisticsBuilderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsBuilder, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void StatisticsBuilderImpl::setNofDocumentsInsertedChange(
			int p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsBuilder, Method_setNofDocumentsInsertedChange, objid());
	obj()->setNofDocumentsInsertedChange(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StatisticsBuilderImpl::addDfChange(
			const char* p1, 
			const char* p2, 
			int p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsBuilder, Method_addDfChange, objid());
	obj()->addDfChange(p1, p2, p3);
	TraceSerializer msg;
	msg.packVoid();
	msg.packCharp(p1);
	msg.packCharp(p2);
	msg.packScalar(p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StatisticsBuilderImpl::start()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsBuilder, Method_start, objid());
	obj()->start();
	TraceSerializer msg;
	msg.packVoid();
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StatisticsBuilderImpl::rollback()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsBuilder, Method_rollback, objid());
	obj()->rollback();
	TraceSerializer msg;
	msg.packVoid();
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

bool StatisticsBuilderImpl::fetchMessage(
			const char*& blk, std::size_t& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsBuilder, Method_fetchMessage, objid());
	bool p0 = obj()->fetchMessage(blk, p1);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packBuffer( blk, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StatisticsIteratorImpl::~StatisticsIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsIterator, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

bool StatisticsIteratorImpl::getNext(
			const char*& msg, std::size_t& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsIterator, Method_getNext, objid());
	bool p0 = obj()->getNext(msg, p1);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packBuffer( msg, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StatisticsProcessorImpl::~StatisticsProcessorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsProcessor, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

StatisticsViewerInterface* StatisticsProcessorImpl::createViewer(
			const char* msgptr, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsProcessor, Method_createViewer, objid());
	StatisticsViewerInterface* p0 = obj()->createViewer(msgptr, p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packBuffer( msgptr, p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StatisticsBuilderInterface* StatisticsProcessorImpl::createBuilder(
			const BuilderOptions& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsProcessor, Method_createBuilder, objid());
	StatisticsBuilderInterface* p0 = obj()->createBuilder(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packStatisticsProcessorBuilderOptions(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StatisticsViewerImpl::~StatisticsViewerImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsViewer, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

int StatisticsViewerImpl::nofDocumentsInsertedChange()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsViewer, Method_nofDocumentsInsertedChange, objid());
	int p0 = obj()->nofDocumentsInsertedChange();
	TraceSerializer msg;
	msg.packScalar(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

bool StatisticsViewerImpl::nextDfChange(
			DocumentFrequencyChange& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StatisticsViewer, Method_nextDfChange, objid());
	bool p0 = obj()->nextDfChange(p1);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packStatisticsViewerDocumentFrequencyChange(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageAlterMetaDataTableImpl::~StorageAlterMetaDataTableImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageAlterMetaDataTable, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void StorageAlterMetaDataTableImpl::addElement(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageAlterMetaDataTable, Method_addElement, objid());
	obj()->addElement(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageAlterMetaDataTableImpl::alterElement(
			const std::string& p1, 
			const std::string& p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageAlterMetaDataTable, Method_alterElement, objid());
	obj()->alterElement(p1, p2, p3);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	msg.packString(p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageAlterMetaDataTableImpl::renameElement(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageAlterMetaDataTable, Method_renameElement, objid());
	obj()->renameElement(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageAlterMetaDataTableImpl::deleteElement(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageAlterMetaDataTable, Method_deleteElement, objid());
	obj()->deleteElement(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageAlterMetaDataTableImpl::clearElement(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageAlterMetaDataTable, Method_clearElement, objid());
	obj()->clearElement(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

bool StorageAlterMetaDataTableImpl::commit()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageAlterMetaDataTable, Method_commit, objid());
	bool p0 = obj()->commit();
	TraceSerializer msg;
	msg.packBool(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void StorageAlterMetaDataTableImpl::rollback()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageAlterMetaDataTable, Method_rollback, objid());
	obj()->rollback();
	TraceSerializer msg;
	msg.packVoid();
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

StorageClientImpl::~StorageClientImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

PostingIteratorInterface* StorageClientImpl::createTermPostingIterator(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createTermPostingIterator, objid());
	PostingIteratorInterface* p0 = obj()->createTermPostingIterator(p1, p2);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
		msg.packString(p2);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

PostingIteratorInterface* StorageClientImpl::createBrowsePostingIterator(
			const MetaDataRestrictionInterface* p1, 
			const Index& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createBrowsePostingIterator, objid());
	PostingIteratorInterface* p0 = obj()->createBrowsePostingIterator(p1, p2);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packObject(p1);
		msg.packScalar(p2);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

ForwardIteratorInterface* StorageClientImpl::createForwardIterator(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createForwardIterator, objid());
	ForwardIteratorInterface* p0 = obj()->createForwardIterator(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

DocumentTermIteratorInterface* StorageClientImpl::createDocumentTermIterator(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createDocumentTermIterator, objid());
	DocumentTermIteratorInterface* p0 = obj()->createDocumentTermIterator(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

InvAclIteratorInterface* StorageClientImpl::createInvAclIterator(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createInvAclIterator, objid());
	InvAclIteratorInterface* p0 = obj()->createInvAclIterator(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index StorageClientImpl::nofDocumentsInserted()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_nofDocumentsInserted, objid());
	Index p0 = obj()->nofDocumentsInserted();
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index StorageClientImpl::documentFrequency(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_documentFrequency, objid());
	Index p0 = obj()->documentFrequency(p1, p2);
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
		msg.packString(p1);
		msg.packString(p2);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index StorageClientImpl::maxDocumentNumber()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_maxDocumentNumber, objid());
	Index p0 = obj()->maxDocumentNumber();
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index StorageClientImpl::documentNumber(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_documentNumber, objid());
	Index p0 = obj()->documentNumber(p1);
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

ValueIteratorInterface* StorageClientImpl::createTermTypeIterator()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createTermTypeIterator, objid());
	ValueIteratorInterface* p0 = obj()->createTermTypeIterator();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

ValueIteratorInterface* StorageClientImpl::createTermValueIterator()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createTermValueIterator, objid());
	ValueIteratorInterface* p0 = obj()->createTermValueIterator();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

ValueIteratorInterface* StorageClientImpl::createDocIdIterator()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createDocIdIterator, objid());
	ValueIteratorInterface* p0 = obj()->createDocIdIterator();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

ValueIteratorInterface* StorageClientImpl::createUserNameIterator()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createUserNameIterator, objid());
	ValueIteratorInterface* p0 = obj()->createUserNameIterator();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

Index StorageClientImpl::documentStatistics(
			const Index& p1, 
			const DocumentStatisticsType& p2, 
			const std::string& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_documentStatistics, objid());
	Index p0 = obj()->documentStatistics(p1, p2, p3);
	TraceSerializer msg;
	if (p0 < 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packScalar(p0);
		msg.packScalar(p1);
		msg.packDocumentStatisticsType(p2);
		msg.packString(p3);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

MetaDataReaderInterface* StorageClientImpl::createMetaDataReader()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createMetaDataReader, objid());
	MetaDataReaderInterface* p0 = obj()->createMetaDataReader();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

MetaDataRestrictionInterface* StorageClientImpl::createMetaDataRestriction()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createMetaDataRestriction, objid());
	MetaDataRestrictionInterface* p0 = obj()->createMetaDataRestriction();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

AttributeReaderInterface* StorageClientImpl::createAttributeReader()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createAttributeReader, objid());
	AttributeReaderInterface* p0 = obj()->createAttributeReader();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageTransactionInterface* StorageClientImpl::createTransaction()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createTransaction, objid());
	StorageTransactionInterface* p0 = obj()->createTransaction();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StatisticsIteratorInterface* StorageClientImpl::createInitStatisticsIterator(
			bool p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createInitStatisticsIterator, objid());
	StatisticsIteratorInterface* p0 = obj()->createInitStatisticsIterator(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packBool(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StatisticsIteratorInterface* StorageClientImpl::createUpdateStatisticsIterator()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createUpdateStatisticsIterator, objid());
	StatisticsIteratorInterface* p0 = obj()->createUpdateStatisticsIterator();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const StatisticsProcessorInterface* StorageClientImpl::getStatisticsProcessor()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_getStatisticsProcessor, objid());
	const StatisticsProcessorInterface* p0 = obj()->getStatisticsProcessor();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageDocumentInterface* StorageClientImpl::createDocumentChecker(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createDocumentChecker, objid());
	StorageDocumentInterface* p0 = obj()->createDocumentChecker(p1, p2);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
		msg.packString(p2);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

bool StorageClientImpl::checkStorage(
			std::ostream& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_checkStorage, objid());
	bool p0 = obj()->checkStorage(p1);
	TraceSerializer msg;
	msg.packBool(p0);
	
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageDumpInterface* StorageClientImpl::createDump(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageClient, Method_createDump, objid());
	StorageDumpInterface* p0 = obj()->createDump(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageDocumentImpl::~StorageDocumentImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocument, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void StorageDocumentImpl::addSearchIndexTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocument, Method_addSearchIndexTerm, objid());
	obj()->addSearchIndexTerm(p1, p2, p3);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	msg.packScalar(p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageDocumentImpl::addForwardIndexTerm(
			const std::string& p1, 
			const std::string& p2, 
			const Index& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocument, Method_addForwardIndexTerm, objid());
	obj()->addForwardIndexTerm(p1, p2, p3);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	msg.packScalar(p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageDocumentImpl::setMetaData(
			const std::string& p1, 
			const NumericVariant& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocument, Method_setMetaData, objid());
	obj()->setMetaData(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packNumericVariant(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageDocumentImpl::setAttribute(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocument, Method_setAttribute, objid());
	obj()->setAttribute(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageDocumentImpl::setUserAccessRight(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocument, Method_setUserAccessRight, objid());
	obj()->setUserAccessRight(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageDocumentImpl::done()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocument, Method_done, objid());
	obj()->done();
	TraceSerializer msg;
	msg.packVoid();
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

StorageDocumentUpdateImpl::~StorageDocumentUpdateImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocumentUpdate, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void StorageDocumentUpdateImpl::setMetaData(
			const std::string& p1, 
			const NumericVariant& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocumentUpdate, Method_setMetaData, objid());
	obj()->setMetaData(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packNumericVariant(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageDocumentUpdateImpl::setAttribute(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocumentUpdate, Method_setAttribute, objid());
	obj()->setAttribute(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageDocumentUpdateImpl::clearAttribute(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocumentUpdate, Method_clearAttribute, objid());
	obj()->clearAttribute(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageDocumentUpdateImpl::setUserAccessRight(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocumentUpdate, Method_setUserAccessRight, objid());
	obj()->setUserAccessRight(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageDocumentUpdateImpl::clearUserAccessRight(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocumentUpdate, Method_clearUserAccessRight, objid());
	obj()->clearUserAccessRight(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageDocumentUpdateImpl::clearUserAccessRights()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocumentUpdate, Method_clearUserAccessRights, objid());
	obj()->clearUserAccessRights();
	TraceSerializer msg;
	msg.packVoid();
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageDocumentUpdateImpl::done()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDocumentUpdate, Method_done, objid());
	obj()->done();
	TraceSerializer msg;
	msg.packVoid();
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

StorageDumpImpl::~StorageDumpImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDump, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

bool StorageDumpImpl::nextChunk(
			const char*& chunk, std::size_t& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageDump, Method_nextChunk, objid());
	bool p0 = obj()->nextChunk(chunk, p1);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packBuffer( chunk, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageImpl::~StorageImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Storage, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

StorageClientInterface* StorageImpl::createClient(
			const std::string& p1, 
			DatabaseClientInterface* p2, 
			const StatisticsProcessorInterface* p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Storage, Method_createClient, objid());
	StorageClientInterface* p0 = obj()->createClient(p1, p2, p3);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
		msg.packObject(p2);
		msg.packObject(p3);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

bool StorageImpl::createStorage(
			const std::string& p1, 
			DatabaseClientInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Storage, Method_createStorage, objid());
	bool p0 = obj()->createStorage(p1, p2);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packString(p1);
	msg.packObject(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageAlterMetaDataTableInterface* StorageImpl::createAlterMetaDataTable(
			DatabaseClientInterface* p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Storage, Method_createAlterMetaDataTable, objid());
	StorageAlterMetaDataTableInterface* p0 = obj()->createAlterMetaDataTable(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packObject(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		if (p1) {delete p1; p1 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const char* StorageImpl::getConfigDescription(
			const ConfigType& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Storage, Method_getConfigDescription, objid());
	const char* p0 = obj()->getConfigDescription(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packCharp(p0);
		msg.packStorageConfigType(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const char** StorageImpl::getConfigParameters(
			const ConfigType& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_Storage, Method_getConfigParameters, objid());
	const char** p0 = obj()->getConfigParameters(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packCharpp(p0);
		msg.packStorageConfigType(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageObjectBuilderImpl::~StorageObjectBuilderImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageObjectBuilder, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

const StorageInterface* StorageObjectBuilderImpl::getStorage()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageObjectBuilder, Method_getStorage, objid());
	const StorageInterface* p0 = obj()->getStorage();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const DatabaseInterface* StorageObjectBuilderImpl::getDatabase(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageObjectBuilder, Method_getDatabase, objid());
	const DatabaseInterface* p0 = obj()->getDatabase(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const QueryProcessorInterface* StorageObjectBuilderImpl::getQueryProcessor()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageObjectBuilder, Method_getQueryProcessor, objid());
	const QueryProcessorInterface* p0 = obj()->getQueryProcessor();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const StatisticsProcessorInterface* StorageObjectBuilderImpl::getStatisticsProcessor()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageObjectBuilder, Method_getStatisticsProcessor, objid());
	const StatisticsProcessorInterface* p0 = obj()->getStatisticsProcessor();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageClientInterface* StorageObjectBuilderImpl::createStorageClient(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageObjectBuilder, Method_createStorageClient, objid());
	StorageClientInterface* p0 = obj()->createStorageClient(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageAlterMetaDataTableInterface* StorageObjectBuilderImpl::createAlterMetaDataTable(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageObjectBuilder, Method_createAlterMetaDataTable, objid());
	StorageAlterMetaDataTableInterface* p0 = obj()->createAlterMetaDataTable(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

QueryEvalInterface* StorageObjectBuilderImpl::createQueryEval()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageObjectBuilder, Method_createQueryEval, objid());
	QueryEvalInterface* p0 = obj()->createQueryEval();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageTransactionImpl::~StorageTransactionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageTransaction, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

StorageDocumentInterface* StorageTransactionImpl::createDocument(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageTransaction, Method_createDocument, objid());
	StorageDocumentInterface* p0 = obj()->createDocument(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

StorageDocumentUpdateInterface* StorageTransactionImpl::createDocumentUpdate(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageTransaction, Method_createDocumentUpdate, objid());
	StorageDocumentUpdateInterface* p0 = obj()->createDocumentUpdate(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packScalar(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void StorageTransactionImpl::deleteDocument(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageTransaction, Method_deleteDocument, objid());
	obj()->deleteDocument(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageTransactionImpl::deleteUserAccessRights(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageTransaction, Method_deleteUserAccessRights, objid());
	obj()->deleteUserAccessRights(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void StorageTransactionImpl::updateMetaData(
			const Index& p1, 
			const std::string& p2, 
			const NumericVariant& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageTransaction, Method_updateMetaData, objid());
	obj()->updateMetaData(p1, p2, p3);
	TraceSerializer msg;
	msg.packVoid();
	msg.packScalar(p1);
	msg.packString(p2);
	msg.packNumericVariant(p3);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

bool StorageTransactionImpl::commit()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageTransaction, Method_commit, objid());
	bool p0 = obj()->commit();
	TraceSerializer msg;
	msg.packBool(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void StorageTransactionImpl::rollback()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_StorageTransaction, Method_rollback, objid());
	obj()->rollback();
	TraceSerializer msg;
	msg.packVoid();
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

SummarizerFunctionContextImpl::~SummarizerFunctionContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SummarizerFunctionContext, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void SummarizerFunctionContextImpl::addSummarizationFeature(
			const std::string& p1, 
			PostingIteratorInterface* p2, 
			const std::vector<SummarizationVariable>&  p3, 
			double p4, 
			const TermStatistics& p5)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SummarizerFunctionContext, Method_addSummarizationFeature, objid());
	obj()->addSummarizationFeature(p1, p2, p3, p4, p5);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	msg.packSummarizationVariableVector(p3);
	msg.packScalar(p4);
	msg.packTermStatistics(p5);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

std::vector<SummaryElement> SummarizerFunctionContextImpl::getSummary(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SummarizerFunctionContext, Method_getSummary, objid());
	std::vector<SummaryElement> p0 = obj()->getSummary(p1);
	TraceSerializer msg;
	msg.packSummaryElement(p0);
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

SummarizerFunctionInstanceImpl::~SummarizerFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SummarizerFunctionInstance, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void SummarizerFunctionInstanceImpl::addStringParameter(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SummarizerFunctionInstance, Method_addStringParameter, objid());
	obj()->addStringParameter(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void SummarizerFunctionInstanceImpl::addNumericParameter(
			const std::string& p1, 
			const NumericVariant& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SummarizerFunctionInstance, Method_addNumericParameter, objid());
	obj()->addNumericParameter(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packNumericVariant(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

SummarizerFunctionContextInterface* SummarizerFunctionInstanceImpl::createFunctionContext(
			const StorageClientInterface* p1, 
			MetaDataReaderInterface* p2, 
			const GlobalStatistics& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SummarizerFunctionInstance, Method_createFunctionContext, objid());
	SummarizerFunctionContextInterface* p0 = obj()->createFunctionContext(p1, p2, p3);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packObject(p1);
		msg.packObject(p2);
		msg.packGlobalStatistics(p3);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

std::string SummarizerFunctionInstanceImpl::tostring()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SummarizerFunctionInstance, Method_tostring, objid());
	std::string p0 = obj()->tostring();
	TraceSerializer msg;
	msg.packString(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

SummarizerFunctionImpl::~SummarizerFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SummarizerFunction, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

SummarizerFunctionInstanceInterface* SummarizerFunctionImpl::createInstance(
			const QueryProcessorInterface* p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SummarizerFunction, Method_createInstance, objid());
	SummarizerFunctionInstanceInterface* p0 = obj()->createInstance(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packObject(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

FunctionDescription SummarizerFunctionImpl::getDescription()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_SummarizerFunction, Method_getDescription, objid());
	FunctionDescription p0 = obj()->getDescription();
	TraceSerializer msg;
	msg.packFunctionDescription(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

TextProcessorImpl::~TextProcessorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void TextProcessorImpl::addResourcePath(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_addResourcePath, objid());
	obj()->addResourcePath(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

std::string TextProcessorImpl::getResourcePath(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_getResourcePath, objid());
	std::string p0 = obj()->getResourcePath(p1);
	TraceSerializer msg;
	msg.packString(p0);
	msg.packString(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const TokenizerFunctionInterface* TextProcessorImpl::getTokenizer(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_getTokenizer, objid());
	const TokenizerFunctionInterface* p0 = obj()->getTokenizer(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const NormalizerFunctionInterface* TextProcessorImpl::getNormalizer(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_getNormalizer, objid());
	const NormalizerFunctionInterface* p0 = obj()->getNormalizer(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const AggregatorFunctionInterface* TextProcessorImpl::getAggregator(
			const std::string& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_getAggregator, objid());
	const AggregatorFunctionInterface* p0 = obj()->getAggregator(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packString(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

bool TextProcessorImpl::detectDocumentClass(
			DocumentClass& p1, 
			const char* contentBegin, std::size_t p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_detectDocumentClass, objid());
	bool p0 = obj()->detectDocumentClass(p1, contentBegin, p2);
	TraceSerializer msg;
	msg.packBool(p0);
	msg.packDocumentClass(p1);
	msg.packBuffer( contentBegin, p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

void TextProcessorImpl::defineDocumentClassDetector(
			DocumentClassDetectorInterface* p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_defineDocumentClassDetector, objid());
	obj()->defineDocumentClassDetector(p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packObject(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p1) {delete p1; p1 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void TextProcessorImpl::defineTokenizer(
			const std::string& p1, 
			TokenizerFunctionInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_defineTokenizer, objid());
	obj()->defineTokenizer(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void TextProcessorImpl::defineNormalizer(
			const std::string& p1, 
			NormalizerFunctionInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_defineNormalizer, objid());
	obj()->defineNormalizer(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void TextProcessorImpl::defineAggregator(
			const std::string& p1, 
			AggregatorFunctionInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_defineAggregator, objid());
	obj()->defineAggregator(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p2) {delete p2; p2 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

std::vector<std::string> TextProcessorImpl::getFunctionList(
			const FunctionType& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TextProcessor, Method_getFunctionList, objid());
	std::vector<std::string> p0 = obj()->getFunctionList(p1);
	TraceSerializer msg;
	msg.packStringVector(p0);
	msg.packTextProcessorFunctionType(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

TokenizerFunctionContextImpl::~TokenizerFunctionContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TokenizerFunctionContext, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

std::vector<analyzer::Token> TokenizerFunctionContextImpl::tokenize(
			const char* src, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TokenizerFunctionContext, Method_tokenize, objid());
	std::vector<analyzer::Token> p0 = obj()->tokenize(src, p1);
	TraceSerializer msg;
	msg.packAnalyzerTokenVector(p0);
	msg.packBuffer( src, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

TokenizerFunctionInstanceImpl::~TokenizerFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TokenizerFunctionInstance, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

bool TokenizerFunctionInstanceImpl::concatBeforeTokenize()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TokenizerFunctionInstance, Method_concatBeforeTokenize, objid());
	bool p0 = obj()->concatBeforeTokenize();
	TraceSerializer msg;
	msg.packBool(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

TokenizerFunctionContextInterface* TokenizerFunctionInstanceImpl::createFunctionContext()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TokenizerFunctionInstance, Method_createFunctionContext, objid());
	TokenizerFunctionContextInterface* p0 = obj()->createFunctionContext();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

TokenizerFunctionImpl::~TokenizerFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TokenizerFunction, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

TokenizerFunctionInstanceInterface* TokenizerFunctionImpl::createInstance(
			const std::vector<std::string>& p1, 
			const TextProcessorInterface* p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TokenizerFunction, Method_createInstance, objid());
	TokenizerFunctionInstanceInterface* p0 = obj()->createInstance(p1, p2);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packStringVector(p1);
		msg.packObject(p2);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

const char* TokenizerFunctionImpl::getDescription()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_TokenizerFunction, Method_getDescription, objid());
	const char* p0 = obj()->getDescription();
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packCharp(p0);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

ValueIteratorImpl::~ValueIteratorImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ValueIterator, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void ValueIteratorImpl::skip(
			const char* value, std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ValueIterator, Method_skip, objid());
	obj()->skip(value, p1);
	TraceSerializer msg;
	msg.packVoid();
	msg.packBuffer( value, p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

std::vector<std::string> ValueIteratorImpl::fetchValues(
			std::size_t p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_ValueIterator, Method_fetchValues, objid());
	std::vector<std::string> p0 = obj()->fetchValues(p1);
	TraceSerializer msg;
	msg.packStringVector(p0);
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

WeightingFunctionContextImpl::~WeightingFunctionContextImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_WeightingFunctionContext, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void WeightingFunctionContextImpl::addWeightingFeature(
			const std::string& p1, 
			PostingIteratorInterface* p2, 
			double p3, 
			const TermStatistics& p4)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_WeightingFunctionContext, Method_addWeightingFeature, objid());
	obj()->addWeightingFeature(p1, p2, p3, p4);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packObject(p2);
	msg.packScalar(p3);
	msg.packTermStatistics(p4);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

double WeightingFunctionContextImpl::call(
			const Index& p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_WeightingFunctionContext, Method_call, objid());
	double p0 = obj()->call(p1);
	TraceSerializer msg;
	msg.packScalar(p0);
	msg.packScalar(p1);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

WeightingFunctionInstanceImpl::~WeightingFunctionInstanceImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_WeightingFunctionInstance, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

void WeightingFunctionInstanceImpl::addStringParameter(
			const std::string& p1, 
			const std::string& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_WeightingFunctionInstance, Method_addStringParameter, objid());
	obj()->addStringParameter(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packString(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

void WeightingFunctionInstanceImpl::addNumericParameter(
			const std::string& p1, 
			const NumericVariant& p2)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_WeightingFunctionInstance, Method_addNumericParameter, objid());
	obj()->addNumericParameter(p1, p2);
	TraceSerializer msg;
	msg.packVoid();
	msg.packString(p1);
	msg.packNumericVariant(p2);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
}

WeightingFunctionContextInterface* WeightingFunctionInstanceImpl::createFunctionContext(
			const StorageClientInterface* p1, 
			MetaDataReaderInterface* p2, 
			const GlobalStatistics& p3)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_WeightingFunctionInstance, Method_createFunctionContext, objid());
	WeightingFunctionContextInterface* p0 = obj()->createFunctionContext(p1, p2, p3);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packObject(p1);
		msg.packObject(p2);
		msg.packGlobalStatistics(p3);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

std::string WeightingFunctionInstanceImpl::tostring()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_WeightingFunctionInstance, Method_tostring, objid());
	std::string p0 = obj()->tostring();
	TraceSerializer msg;
	msg.packString(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

WeightingFunctionImpl::~WeightingFunctionImpl()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_WeightingFunction, Method_Destructor, objid());
	traceContext()->logger().logMethodTermination( callhnd, "");
}

WeightingFunctionInstanceInterface* WeightingFunctionImpl::createInstance(
			const QueryProcessorInterface* p1)
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_WeightingFunction, Method_createInstance, objid());
	WeightingFunctionInstanceInterface* p0 = obj()->createInstance(p1);
	TraceSerializer msg;
	if (p0 == 0)
	{
		traceContext()->errorbuf()->report(_TXT("method call '%s' failed: %s"), mi->name().c_str(), traceContext()->errorbuf()->fetchError());
	}
	else
	{
		msg.packObject(p0);
		msg.packObject(p1);
	}
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		if (p0) {delete p0; p0 = 0;}
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}

FunctionDescription WeightingFunctionImpl::getDescription()
{
	TraceLogRecordHandle callhnd = traceContext()->logger().logMethodCall( ClassId_WeightingFunction, Method_getDescription, objid());
	FunctionDescription p0 = obj()->getDescription();
	TraceSerializer msg;
	msg.packFunctionDescription(p0);
	if (msg.hasError() || traceContext()->errorbuf()->hasError())
	{
		if (msg.hasError()) traceContext()->errorbuf()->report( _TXT("memory allocation error when logging trace"));
		traceContext()->logger().logMethodTermination( callhnd, "");
	}
	else
	{
		traceContext()->logger().logMethodTermination( callhnd, msg.content());
	}
	return p0;
}


