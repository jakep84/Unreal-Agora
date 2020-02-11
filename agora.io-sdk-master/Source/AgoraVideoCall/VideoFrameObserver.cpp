//  Copyright (c) 2019 Agora.io. All rights reserved.

#include "VideoFrameObserver.h"

#include "AgoraVideoFrameConverter.h"

VideoFrameObserver::~VideoFrameObserver()
{
	if (CaptureBuffer)
	{
		delete[] CaptureBuffer;
	}
	if (RenderBuffer)
	{
		delete[] RenderBuffer;
	}
}

bool VideoFrameObserver::onCaptureVideoFrame(VideoFrame& Frame)
{
	//VideoFrame data format is YUV420. To render it we need to convert it to ARGB

	const auto BufferSize = agora::media::ue4::AgoraVideoFrameConverter::getOutBufferSize(
		Frame.width,
		Frame.height);
	if (BufferSize != CaptureBufferSize)
	{
		if (CaptureBuffer)
		{
			delete[] CaptureBuffer;
		}
		CaptureBufferSize = BufferSize;
		CaptureBuffer = new uint8_t[CaptureBufferSize];
	}
	if (!CaptureBuffer)
	{
		CaptureBuffer = new uint8_t[CaptureBufferSize];
	}
	uint8_t* SrcY = static_cast<uint8_t*>(Frame.yBuffer);
	uint8_t* SrcU = static_cast<uint8_t*>(Frame.uBuffer);
	uint8_t* SrcV = static_cast<uint8_t*>(Frame.vBuffer);
	agora::media::ue4::AgoraVideoFrameConverter::convertVideoFrameToARGB(
		SrcY,
		SrcU,
		SrcV,
		Frame.yStride,
		Frame.uStride,
		Frame.vStride,
		Frame.width,
		Frame.height,
		CaptureBuffer);

	if (OnCaptureVideoFrame)
	{
		OnCaptureVideoFrame(CaptureBuffer, Frame.width, Frame.height, CaptureBufferSize);
	}



	return true;
}

bool VideoFrameObserver::onRenderVideoFrame(unsigned int uid, VideoFrame& Frame)
{
	const auto BufferSize = agora::media::ue4::AgoraVideoFrameConverter::getOutBufferSize(
		Frame.width,
		Frame.height);
	if (BufferSize != RenderBufferSize)
	{
		if (RenderBuffer)
		{
			delete[] RenderBuffer;
		}
		RenderBufferSize = BufferSize;
		RenderBuffer = new uint8_t[RenderBufferSize];
	}
	if (!RenderBuffer)
	{
		RenderBuffer = new uint8_t[RenderBufferSize];
	}
	uint8_t* SrcY = static_cast<uint8_t*>(Frame.yBuffer);
	uint8_t* SrcU = static_cast<uint8_t*>(Frame.uBuffer);
	uint8_t* SrcV = static_cast<uint8_t*>(Frame.vBuffer);
	agora::media::ue4::AgoraVideoFrameConverter::convertVideoFrameToARGB(
		SrcY,
		SrcU,
		SrcV,
		Frame.yStride,
		Frame.uStride,
		Frame.vStride,
		Frame.width,
		Frame.height,
		RenderBuffer);

	if (OnRenderVideoFrame)
	{
		OnRenderVideoFrame(RenderBuffer, Frame.width, Frame.height, RenderBufferSize);
	}

	return true;
}

void VideoFrameObserver::setOnCaptureVideoFrameCallback(
	std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> Callback)
{
	OnCaptureVideoFrame = Callback;
}

void VideoFrameObserver::setOnRenderVideoFrameCallback(
	std::function<void(std::uint8_t*, std::uint32_t, std::uint32_t, std::uint32_t)> Callback)
{
	OnRenderVideoFrame = Callback;
}

