#include "pch.h"
#include "HalconLibrary.h"

void HalconLibrary::ShowImage(const HObject& image, Hlong winID, int imgWidth, int imgHeight)
{
	//清除缓存
	if (!HDevWindowStack::IsOpen())
	{
		//CloseWindow(HDevWindowStack::Pop()); //这段话很重要,否则无法连续打开图像显示,仅仅固定显示第一次打开的图
		OpenWindow(0, 0, imgWidth, imgHeight, winID, "visible", "", &windowHandle);
		HDevWindowStack::Push(windowHandle);
	}
	DetachBackgroundFromWindow(windowHandle);//清除窗口缓存
	SetPart(windowHandle, 0, 0, imgHeight, imgWidth); // 自适应
	DispObj(image, windowHandle);
}
