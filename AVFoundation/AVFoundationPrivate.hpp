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
	_AV_PRIVATE_DEF_CLS( AVAssetTrack );
	_AV_PRIVATE_DEF_CLS( AVAssetReaderOutput );
	_AV_PRIVATE_DEF_CLS( AVAssetReaderTrackOutput );

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

	_AV_PRIVATE_DEF_SEL( alwaysCopiesSampleData, "alwaysCopiesSampleData" );
	_AV_PRIVATE_DEF_SEL( assetReaderTrackOutput, "assetReaderTrackOutput" );
	_AV_PRIVATE_DEF_SEL( assetReaderTrackOutputWithTrackOutputSettings, "assetReaderTrackOutputWithTrackOutputSettings" );
	_AV_PRIVATE_DEF_SEL( formatDescriptions, "formatDescriptions" );
	_AV_PRIVATE_DEF_SEL( isPlayable, "isPlayable" );
	_AV_PRIVATE_DEF_SEL( isDecodable, "isDecodable" );
	_AV_PRIVATE_DEF_SEL( isEnabled, "isEnabled" );
	_AV_PRIVATE_DEF_SEL( isSelfContained, "isSelfContained" );
	_AV_PRIVATE_DEF_SEL( init, "init" );
	_AV_PRIVATE_DEF_SEL( initWithTrackOutputSettings, "initWithTrackOutputSettings" );
	_AV_PRIVATE_DEF_SEL( markConfigurationAsFinal, "markConfigurationAsFinal" );
	_AV_PRIVATE_DEF_SEL( resetForReadingTimeRanges_, "resetForReadingTimeRanges:" );
	_AV_PRIVATE_DEF_SEL( setAlwaysCopiesSampleData_, "setAlwaysCopiesSampleData:" );
	_AV_PRIVATE_DEF_SEL( setSupportsRandomAccess_, "setSupportsRandomAccess:" );
	_AV_PRIVATE_DEF_SEL( supportsRandomAccess, "supportsRandomAccess" );
	_AV_PRIVATE_DEF_SEL( track, "track" );
	_AV_PRIVATE_DEF_SEL( totalSampleDataLength, "totalSampleDataLength" );
	_AV_PRIVATE_DEF_SEL( estimatedDataRate, "estimatedDataRate" );
	_AV_PRIVATE_DEF_SEL( languageCode, "languageCode" );
	_AV_PRIVATE_DEF_SEL( extendedLanguageTag, "extendedLanguageTag" );
	_AV_PRIVATE_DEF_SEL( naturalSize, "naturalSize" );
	_AV_PRIVATE_DEF_SEL( outputSettings, "outputSettings" );
	_AV_PRIVATE_DEF_SEL( preferredTransform, "preferredTransform" );
	_AV_PRIVATE_DEF_SEL( preferredVolume, "preferredVolume" );
	_AV_PRIVATE_DEF_SEL( hasAudioSampleDependencies, "hasAudioSampleDependencies" );
	_AV_PRIVATE_DEF_SEL( nominalFrameRate, "nominalFrameRate" );
	_AV_PRIVATE_DEF_SEL( requiresFrameReordering, "requiresFrameReordering" );
	_AV_PRIVATE_DEF_SEL( segments, "segments" );
	_AV_PRIVATE_DEF_SEL( commonMetadata, "commonMetadata" );
	_AV_PRIVATE_DEF_SEL( metadata, "metadata" );
	_AV_PRIVATE_DEF_SEL( availableMetadataFormats, "availableMetadataFormats" );
	_AV_PRIVATE_DEF_SEL( availableTrackAssociationTypes, "availableTrackAssociationTypes" );
	_AV_PRIVATE_DEF_SEL( makeSampleCursorAtFirstSampleInDecodeOrder, "makeSampleCursorAtFirstSampleInDecodeOrder" );
	_AV_PRIVATE_DEF_SEL( makeSampleCursorAtLastSampleInDecodeOrder, "makeSampleCursorAtLastSampleInDecodeOrder" );
	_AV_PRIVATE_DEF_SEL( canProvideSampleCursors, "canProvideSampleCursors" );

}

//---------
