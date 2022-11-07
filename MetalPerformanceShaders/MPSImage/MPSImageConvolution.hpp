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
#include "MPSImageKernel.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace MPS
{

	class ImageGaussianBlur : public NS::Referencing< ImageGaussianBlur, UnaryImageKernel >
	{
		public:
			static ImageGaussianBlur*	alloc();
			ImageGaussianBlur*			init( const MTL::Device* pDevice, float sigma );

			void						setSigma( float sigma );
			float						sigma() const;
	};

	class ImagePyramid : public NS::Referencing< ImagePyramid, UnaryImageKernel >
	{
		public:
			NS::UInteger				kernelHeight() const;
			NS::UInteger				kernelWidth() const;
	};

	class ImageGaussianPyramid : public NS::Referencing< ImageGaussianPyramid, ImagePyramid >
	{
		public:
			static ImageGaussianPyramid* alloc();
			ImageGaussianPyramid*		init( const MTL::Device* pDevice, float centerWeight );
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

_NS_INLINE NS::UInteger MPS::ImagePyramid::kernelHeight() const
{
	return NS::Object::sendMessage< NS::UInteger >( this, _MPS_PRIVATE_SEL( kernelHeight ) );
}

_NS_INLINE NS::UInteger MPS::ImagePyramid::kernelWidth() const
{
	return NS::Object::sendMessage< NS::UInteger >( this, _MPS_PRIVATE_SEL( kernelWidth ) );
}

_NS_INLINE MPS::ImageGaussianPyramid* MPS::ImageGaussianPyramid::alloc()
{
	return NS::Object::alloc< ImageGaussianPyramid >( _MPS_PRIVATE_CLS( MPSImageGaussianPyramid ) );
}

_NS_INLINE MPS::ImageGaussianPyramid* MPS::ImageGaussianPyramid::init( const MTL::Device* pDevice, float centerWeight )
{
	return NS::Object::sendMessage< ImageGaussianPyramid* >( this, _MPS_PRIVATE_SEL( initWithDevice_centerWeight_ ), pDevice, centerWeight );
}
