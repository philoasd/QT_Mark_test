#include "pch.h"
#include "HalconLibrary.h"

void HalconLibrary::ShowImage(const HObject& image, Hlong winID, int uiWidth, int uiHeight)
{
	//清除缓存
	if (!HDevWindowStack::IsOpen())
	{
		//CloseWindow(HDevWindowStack::Pop()); //这段话很重要,否则无法连续打开图像显示,仅仅固定显示第一次打开的图
		OpenWindow(0, 0, uiWidth, uiHeight, winID, "visible", "", &windowHandle);
		HDevWindowStack::Push(windowHandle);
	}

	DetachBackgroundFromWindow(windowHandle);//清除窗口缓存
	HTuple imgWidth, imgHeight;
	GetImageSize(image, &imgWidth, &imgHeight);

	SetPart(windowHandle, 0, 0, imgHeight - 1, imgWidth - 1); // 自适应
	DispObj(image, windowHandle);
}
