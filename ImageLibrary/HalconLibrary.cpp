#include "pch.h"
#include "HalconLibrary.h"

void HalconLibrary::ShowImage(const HObject& image, Hlong winID, int width, int height)
{
	// 如果窗口句柄为空，则创建窗口
	if (windowHandle == NULL)
	{
		OpenWindow(0, 0, width, height, winID, "visible", "", &windowHandle);
		HDevWindowStack::Push(windowHandle);
	}
	if (HDevWindowStack::IsOpen()) {
		DispObj(image, HDevWindowStack::GetActive());
	}
	DispObj(image, windowHandle);
}
