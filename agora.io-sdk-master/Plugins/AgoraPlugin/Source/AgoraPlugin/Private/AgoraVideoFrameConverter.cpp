//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "AgoraVideoFrameConverter.h"


#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#endif
#include <libyuv/include/libyuv.h>
#include <libyuv/include/libyuv/convert_argb.h>
#if PLATFORM_WINDOWS
#include "Windows/HideWindowsPlatformTypes.h"
#endif

namespace agora
{
namespace media
{
namespace ue4
{

uint32_t AgoraVideoFrameConverter::getOutBufferSize(
	uint32_t width,
	uint32_t height)
{
	return height * width * 4;
}

int AgoraVideoFrameConverter::convertVideoFrameToARGB(
	uint8_t* srcY,
	uint8_t* srcU,
	uint8_t* srcV,
	uint32_t yStride,
	uint32_t uStride,
	uint32_t vStride,
	uint32_t width,
	uint32_t height,
	uint8_t* buffer)
{
	int dstStrideArgb = width * 4;
	int ret = libyuv::I420ToARGB(
		srcY,
		yStride,
		srcU,
		uStride,
		srcV,
		vStride,
		buffer,
		dstStrideArgb,
		width,
		height);
	return ret;
}

}
}
}