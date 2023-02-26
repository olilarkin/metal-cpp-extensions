/*
 *
 * Copyright 2023 Mark Grimes. Most/all of the work is copied from Apple so copyright is theirs if they want it.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Vision/VNRequestHandler.hpp
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "VisionPrivate.hpp"
#include <Foundation/NSObject.hpp>


//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
	class Array;
	class Error;
} // end of namespace NS

namespace CM
{
	struct SampleBuffer;
	using SampleBufferRef = SampleBuffer*;
} // end of namespace CM

namespace VN
{
	class CoreMLModel;
	class Request;
} // end of namespace VN

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace VN
{
	class SequenceRequestHandler : public NS::Referencing<SequenceRequestHandler>
	{
	public:
		static SequenceRequestHandler* alloc();
		SequenceRequestHandler* init();

		bool performRequests( NS::Array* requests, CM::SampleBufferRef sampleBuffer, NS::Error** error );

	}; // end of class SequenceRequestHandler
} // end of namespace VN

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_VN_INLINE VN::SequenceRequestHandler* VN::SequenceRequestHandler::alloc()
{
	return NS::Object::alloc<VN::SequenceRequestHandler>( _VN_PRIVATE_CLS( VNSequenceRequestHandler ) );
}

_VN_INLINE VN::SequenceRequestHandler* VN::SequenceRequestHandler::init()
{
	return NS::Object::sendMessage<VN::SequenceRequestHandler*>( this, _VN_PRIVATE_SEL( init ) );
}

_VN_INLINE bool VN::SequenceRequestHandler::performRequests( NS::Array* requests, CM::SampleBufferRef sampleBuffer, NS::Error** error )
{
	return NS::Object::sendMessage<VN::SequenceRequestHandler*>( this, _VN_PRIVATE_SEL( performRequests_onCMSampleBuffer_error_ ), requests, sampleBuffer, error );
}
