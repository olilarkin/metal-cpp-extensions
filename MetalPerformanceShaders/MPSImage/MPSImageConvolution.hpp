/*
 *
 * Copyright 2022 Mark Grimes. Most/all of the work is copied from Apple so copyright is theirs if they want it.
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
// MetalPerformanceShaders/MPSImage/MPSImageConvolution.hpp
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <Metal/Metal.hpp>
#include <MetalPerformanceShaders/MetalPerformanceShadersPrivate.hpp>

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace MPS
{

	class ImageGaussianBlur : public NS::Referencing< ImageGaussianBlur >
	{
		public:
			static ImageGaussianBlur*	alloc();
			ImageGaussianBlur*			init( const MTL::Device* pDevice, float sigma );

			void						setSigma( float sigma );
			float						sigma() const;

			void						encode( const MTL::CommandBuffer* pCommandBuffer, const MTL::Texture* pSourceTexture, MTL::Texture* pDestinationTexture ) const;
	};
}

_NS_INLINE MPS::ImageGaussianBlur* MPS::ImageGaussianBlur::alloc()
{
	return NS::Object::alloc< ImageGaussianBlur >( _MPS_PRIVATE_CLS( MPSImageGaussianBlur ) );
}

_NS_INLINE MPS::ImageGaussianBlur* MPS::ImageGaussianBlur::init( const MTL::Device* pDevice, float sigma )
{
	return NS::Object::sendMessage< ImageGaussianBlur* >( this, _MPS_PRIVATE_SEL( initWithDevice_sigma_ ), pDevice, sigma );
}

_NS_INLINE void MPS::ImageGaussianBlur::setSigma( float sigma )
{
	NS::Object::sendMessage< void >( this, _MPS_PRIVATE_SEL( setSigma_ ), sigma );
}

_NS_INLINE float MPS::ImageGaussianBlur::sigma() const
{
	return NS::Object::sendMessage< float >( this, _MPS_PRIVATE_SEL( sigma ) );
}

_NS_INLINE void MPS::ImageGaussianBlur::encode( const MTL::CommandBuffer* pCommandBuffer, const MTL::Texture* pSourceTexture, MTL::Texture* pDestinationTexture ) const
{
	return NS::Object::sendMessage< void >( this, _MPS_PRIVATE_SEL( encodeToCommandBuffer_sourceTexture_destinationTexture_ ), pCommandBuffer, pSourceTexture, pDestinationTexture );
}
