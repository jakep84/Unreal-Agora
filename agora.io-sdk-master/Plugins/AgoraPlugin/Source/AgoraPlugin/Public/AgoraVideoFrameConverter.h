//  Copyright (c) 2019 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#endif
#include <Agora/IAgoraMediaEngine.h>
#if PLATFORM_WINDOWS
#include "Windows/HideWindowsPlatformTypes.h"
#endif

namespace agora
{
namespace media
{
namespace ue4
{

/**
 * Helper class that can be used to convert agora::media::VideoFrame into ARGB buffer
 */
class AGORAPLUGIN_API AgoraVideoFrameConverter
{
public:
	AgoraVideoFrameConverter() = delete;

   /**
   * @brief          Retrieves buffer size for frame
   * @param          width
   *                 Frame width
   * @param          height
   *                 Frame height
   * @return         Buffer size
   */
	static uint32_t getOutBufferSize(
		uint32_t width,
		uint32_t height);

   /**
   * @brief          Converts a video frame to ARGB format
   * @param          srcY
   *                 Source frame Y-plane(luma component)
   * @param          srcU
   *                 Source frame U-plane(blue projection)
   * @param          srcV
   *                 Source frame V-plane(red projection)
   * @param          yStride
   *                 Stride parameter of Y-plane
   * @param          uStride
   *                 Stride parameter of U-plane
   * @param          vStride
   *                 Stride parameter of V-plane
   * @param          width
   *                 Frame width
   * @param          height
   *                 Frame height
   * @param          buffer
   *                 Buffer for conversion
   * @return
   *                 - 0: Success.
   *                 - < 0: Failure.
   */
	static int convertVideoFrameToARGB(
		uint8_t* srcY,
		uint8_t* srcU,
		uint8_t* srcV,
		uint32_t yStride,
		uint32_t uStride,
		uint32_t vStride,
		uint32_t width,
		uint32_t height,
		uint8_t* buffer);
};

}
}
}