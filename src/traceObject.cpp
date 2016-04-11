/*
 * Copyright (c) 2016 Patrick P. Frey
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include "traceObject.hpp"
#include "traceGlobalContext.hpp"

using namespace strus;

TraceObjectBase::TraceObjectBase( void* obj_, Deleter deleter_, TraceGlobalContext* ctx_)
	:m_ctx(ctx_),m_obj(obj_),m_deleter(deleter_),m_id(ctx_->createId())
{}

TraceObjectBase::TraceObjectBase( const void* obj_, const TraceGlobalContext* ctx_)
	:m_deleter(0)
{
	m_ctx = const_cast<TraceGlobalContext*>(ctx_);
	m_obj = const_cast<void*>(obj_);
	m_id = m_ctx->createId();
}

