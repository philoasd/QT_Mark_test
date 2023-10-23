#pragma once

#include <halconcpp/HalconCpp.h>

using namespace HalconCpp;

class __declspec(dllexport) HalconLibrary
{
public:
	/// <summary>
	/// 显示图像
	/// </summary>
	/// <param name="image">图像</param>
	/// <param name="winID">窗口控件</param>
	void ShowImage(const HObject& image, Hlong winID, int width, int height);

private:
	HTuple windowHandle;// 显示窗口句柄
};

