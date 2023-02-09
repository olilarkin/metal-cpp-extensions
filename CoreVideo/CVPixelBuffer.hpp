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
// CoreVideo/CVPixelBuffer.hpp
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "CoreVideoPrivate.hpp"
#include "CVImageBuffer.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace CV
{
	_CV_CONST( CFStringRef, PixelBufferPixelFormatTypeKey );
	_CV_CONST( CFStringRef, PixelBufferMemoryAllocatorKey );
	_CV_CONST( CFStringRef, PixelBufferWidthKey );
	_CV_CONST( CFStringRef, PixelBufferHeightKey );
	_CV_CONST( CFStringRef, PixelBufferExtendedPixelsLeftKey );
	_CV_CONST( CFStringRef, PixelBufferExtendedPixelsTopKey );
	_CV_CONST( CFStringRef, PixelBufferExtendedPixelsRightKey );
	_CV_CONST( CFStringRef, PixelBufferExtendedPixelsBottomKey );
	_CV_CONST( CFStringRef, PixelBufferBytesPerRowAlignmentKey );
	_CV_CONST( CFStringRef, PixelBufferCGBitmapContextCompatibilityKey );
	_CV_CONST( CFStringRef, PixelBufferCGImageCompatibilityKey );
	_CV_CONST( CFStringRef, PixelBufferOpenGLCompatibilityKey );
	_CV_CONST( CFStringRef, PixelBufferPlaneAlignmentKey );
	_CV_CONST( CFStringRef, PixelBufferIOSurfacePropertiesKey );
	_CV_CONST( CFStringRef, PixelBufferOpenGLESCompatibilityKey );
	_CV_CONST( CFStringRef, PixelBufferMetalCompatibilityKey );
	_CV_CONST( CFStringRef, PixelBufferOpenGLTextureCacheCompatibilityKey );
	_CV_CONST( CFStringRef, PixelBufferOpenGLESTextureCacheCompatibilityKey );

	using PixelBufferRef = ImageBufferRef;

	_CV_EXPORT size_t pixelBufferGetWidth( PixelBufferRef pixelBuffer );
	_CV_EXPORT size_t pixelBufferGetHeight( PixelBufferRef pixelBuffer );
	_CV_EXPORT NS::UInteger pixelBufferGetPixelFormatType( PixelBufferRef pixelBuffer );
	_CV_EXPORT bool pixelBufferIsPlanar( PixelBufferRef pixelBuffer );
	_CV_EXPORT size_t pixelBufferGetWidthOfPlane( PixelBufferRef pixelBuffer, size_t planeIndex );
	_CV_EXPORT size_t pixelBufferGetHeightOfPlane( PixelBufferRef pixelBuffer, size_t planeIndex );
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferPixelFormatTypeKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferMemoryAllocatorKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferWidthKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferHeightKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferExtendedPixelsLeftKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferExtendedPixelsTopKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferExtendedPixelsRightKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferExtendedPixelsBottomKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferBytesPerRowAlignmentKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferCGBitmapContextCompatibilityKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferCGImageCompatibilityKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferOpenGLCompatibilityKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferPlaneAlignmentKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferIOSurfacePropertiesKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferOpenGLESCompatibilityKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferMetalCompatibilityKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferOpenGLTextureCacheCompatibilityKey );
_CV_PRIVATE_DEF_CONST( CFStringRef, PixelBufferOpenGLESTextureCacheCompatibilityKey );

#if defined(CV_PRIVATE_IMPLEMENTATION)

_CV_EXTERN size_t CVPixelBufferGetWidth( CV::PixelBufferRef pixelBuffer );
_CV_EXTERN size_t CVPixelBufferGetHeight( CV::PixelBufferRef pixelBuffer );
_CV_EXTERN NS::UInteger CVPixelBufferGetPixelFormatType( CV::PixelBufferRef pixelBuffer );
_CV_EXTERN size_t CVPixelBufferIsPlanar( CV::PixelBufferRef pixelBuffer );
_CV_EXTERN size_t CVPixelBufferGetWidthOfPlane( CV::PixelBufferRef pixelBuffer, size_t planeIndex );
_CV_EXTERN size_t CVPixelBufferGetHeightOfPlane( CV::PixelBufferRef pixelBuffer, size_t planeIndex );

size_t CV::pixelBufferGetWidth( PixelBufferRef pixelBuffer )
{
	return ::CVPixelBufferGetWidth( pixelBuffer );
}

size_t CV::pixelBufferGetHeight( PixelBufferRef pixelBuffer )
{
	return ::CVPixelBufferGetHeight( pixelBuffer );
}

NS::UInteger CV::pixelBufferGetPixelFormatType( PixelBufferRef pixelBuffer )
{
	return ::CVPixelBufferGetPixelFormatType( pixelBuffer );
}

bool CV::pixelBufferIsPlanar( PixelBufferRef pixelBuffer )
{
	return ::CVPixelBufferIsPlanar( pixelBuffer );
}

size_t CV::pixelBufferGetWidthOfPlane( PixelBufferRef pixelBuffer, size_t planeIndex )
{
	return ::CVPixelBufferGetWidthOfPlane( pixelBuffer, planeIndex );
}

size_t CV::pixelBufferGetHeightOfPlane( PixelBufferRef pixelBuffer, size_t planeIndex )
{
	return ::CVPixelBufferGetHeightOfPlane( pixelBuffer, planeIndex );
}

#endif // CV_PRIVATE_IMPLEMENTATION
