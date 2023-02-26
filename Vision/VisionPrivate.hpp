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
// Vision/VisionPrivate.hpp
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <objc/runtime.h>
#include "VisionDefines.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#define _VN_PRIVATE_CLS( symbol )    ( Private::Class::s_k ## symbol )
#define _VN_PRIVATE_SEL( accessor )  ( Private::Selector::s_k ## accessor )

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#if defined( VN_PRIVATE_IMPLEMENTATION )

#define _VN_PRIVATE_VISIBILITY       __attribute__( ( visibility( "default" ) ) )
#define _VN_PRIVATE_IMPORT           __attribute__( ( weak_import ) )

#if __OBJC__
#define  _VN_PRIVATE_OBJC_LOOKUP_CLASS( symbol  )   ( ( __bridge void* ) objc_lookUpClass( # symbol ) )
#else
#define  _VN_PRIVATE_OBJC_LOOKUP_CLASS( symbol  )   objc_lookUpClass( # symbol )
#endif // __OBJC__

#define _VN_PRIVATE_DEF_CLS( symbol )            void*           s_k ## symbol     _VN_PRIVATE_VISIBILITY = _VN_PRIVATE_OBJC_LOOKUP_CLASS( symbol );
#define _VN_PRIVATE_DEF_SEL( accessor, symbol )  SEL             s_k ## accessor   _VN_PRIVATE_VISIBILITY = sel_registerName( symbol );
#define _VN_PRIVATE_DEF_CONST( type, symbol )    _VN_EXTERN type const    kVN ## symbol   _VN_PRIVATE_IMPORT; \
                                                            type const    VN::symbol = ( nullptr != &kVN ## symbol ) ? kVN ## symbol : nullptr;

#else

#define _VN_PRIVATE_DEF_CLS( symbol )            extern void*     s_k ## symbol;
#define _VN_PRIVATE_DEF_SEL( accessor, symbol )  extern SEL       s_k ## accessor;
#define _VN_PRIVATE_DEF_CONST( type, symbol )


#endif // VN_PRIVATE_IMPLEMENTATION

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace VN::Private::Class
{
	_VN_PRIVATE_DEF_CLS( VNCoreMLModel );
	_VN_PRIVATE_DEF_CLS( VNCoreMLRequest );
	_VN_PRIVATE_DEF_CLS( VNRequest );
	_VN_PRIVATE_DEF_CLS( VNImageRequestHandler );
	_VN_PRIVATE_DEF_CLS( VNSequenceRequestHandler );
} // Class

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace VN::Private::Selector
{
	_VN_PRIVATE_DEF_SEL( cancel, "cancel" );
	_VN_PRIVATE_DEF_SEL( currentRevision, "currentRevision" );
	_VN_PRIVATE_DEF_SEL( defaultRevision, "defaultRevision" );
	_VN_PRIVATE_DEF_SEL( init, "init" );
	_VN_PRIVATE_DEF_SEL( initWithCMSampleBuffer_options_, "initWithCMSampleBuffer:options:" );
	_VN_PRIVATE_DEF_SEL( initWithCVPixelBuffer_options_, "initWithCVPixelBuffer:options:" );
	_VN_PRIVATE_DEF_SEL( initWithData_options_, "initWithData:options:" );
	_VN_PRIVATE_DEF_SEL( initWithModel_, "initWithModel:" );
	_VN_PRIVATE_DEF_SEL( initWithURL_options_, "initWithURL:options:" );
	_VN_PRIVATE_DEF_SEL( modelForMLModel_error_, "modelForMLModel:error:" );
	_VN_PRIVATE_DEF_SEL( performRequests_error_, "performRequests:error:" );
	_VN_PRIVATE_DEF_SEL( performRequests_onCMSampleBuffer_error_, "performRequests:onCMSampleBuffer:error:" );
	_VN_PRIVATE_DEF_SEL( performRequests_onCVPixelBuffer_error_, "performRequests:onCVPixelBuffer:error:" );
	_VN_PRIVATE_DEF_SEL( performRequests_onImageData_error_, "performRequests:onImageData:error:" );
	_VN_PRIVATE_DEF_SEL( performRequests_onImageURL_error_, "performRequests:onImageURL:error:" );
	_VN_PRIVATE_DEF_SEL( preferBackgroundProcessing, "preferBackgroundProcessing" );
	_VN_PRIVATE_DEF_SEL( regionOfInterest, "regionOfInterest" );
	_VN_PRIVATE_DEF_SEL( results, "results" );
	_VN_PRIVATE_DEF_SEL( revision, "revision" );
	_VN_PRIVATE_DEF_SEL( setPreferBackgroundProcessing_, "setPreferBackgroundProcessing:" );
	_VN_PRIVATE_DEF_SEL( setRegionOfInterest_, "setRegionOfInterest:" );
	_VN_PRIVATE_DEF_SEL( setRevision_, "setRevision:" );
	_VN_PRIVATE_DEF_SEL( setUsesCPUOnly_, "setUsesCPUOnly:" );
	_VN_PRIVATE_DEF_SEL( supportedRevisions, "supportedRevisions" );
	_VN_PRIVATE_DEF_SEL( usesCPUOnly, "usesCPUOnly" );
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
