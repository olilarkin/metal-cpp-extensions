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
// AVFoundation/AVFoundationPrivate.hpp
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <objc/runtime.h>

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#define _AV_PRIVATE_CLS( symbol )				 ( Private::Class::s_k ## symbol )
#define _AV_PRIVATE_SEL( accessor )				 ( Private::Selector::s_k ## accessor )

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#if defined( AV_PRIVATE_IMPLEMENTATION )

#define _AV_PRIVATE_VISIBILITY                    __attribute__( ( visibility( "default" ) ) )
#define _AV_PRIVATE_IMPORT                        __attribute__( ( weak_import ) )

#if __OBJC__
#define  _AV_PRIVATE_OBJC_LOOKUP_CLASS( symbol  )   ( ( __bridge void* ) objc_lookUpClass( # symbol ) )
#else
#define  _AV_PRIVATE_OBJC_LOOKUP_CLASS( symbol  )   objc_lookUpClass( # symbol )
#endif // __OBJC__

#define _AV_PRIVATE_DEF_CLS( symbol )             void*                  s_k ## symbol    _AV_PRIVATE_VISIBILITY = _AV_PRIVATE_OBJC_LOOKUP_CLASS( symbol );
#define _AV_PRIVATE_DEF_SEL( accessor, symbol )   SEL                    s_k ## accessor  _AV_PRIVATE_VISIBILITY = sel_registerName( symbol );
#define _AV_PRIVATE_DEF_CONST( type, symbol )     _NS_EXTERN type const  AV  ## symbol    _AV_PRIVATE_IMPORT; \
												             type const  AV::symbol = ( nullptr != &AV ## symbol ) ? AV ## symbol : nullptr;

#else

#define _AV_PRIVATE_DEF_CLS( symbol )            extern void*         s_k ## symbol;
#define _AV_PRIVATE_DEF_SEL( accessor, symbol )  extern SEL           s_k ## accessor;
#define _AV_PRIVATE_DEF_CONST( type, symbol )


#endif // AV_PRIVATE_IMPLEMENTATION

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace AV::Private::Class
{

	_AV_PRIVATE_DEF_CLS( AVAsset );

} // Class

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace AV::Private::Selector
{

	_AV_PRIVATE_DEF_SEL( assetWithURL_,
						 "assetWithURL:" );

	_AV_PRIVATE_DEF_SEL( mediaType,
						 "mediaType" );

	_AV_PRIVATE_DEF_SEL( tracks,
						 "tracks" );

}

//---------
