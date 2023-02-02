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
// AVFoundation/AVAsset.hpp
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "AVFoundationPrivate.hpp"
#include "Foundation/NSObject.hpp"

namespace NS
{
	class URL;
	class Array;
} // end of namespace NS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace AV
{
	class Asset : public NS::Copying<Asset>
	{
	public:
		static Asset* assetWithURL( const NS::URL* URL );

		NS::Array* tracks();
	}; // end of declaration of class Asset

} // end of namespace AV

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE AV::Asset* AV::Asset::assetWithURL( const NS::URL* URL )
{
	return NS::Object::sendMessage<Asset*>( _AV_PRIVATE_CLS( AVAsset ), _AV_PRIVATE_SEL( assetWithURL_ ), URL );
}

_NS_INLINE NS::Array* AV::Asset::tracks()
{
	return NS::Object::sendMessage<NS::Array*>( this, _AV_PRIVATE_SEL( tracks ) );
}
