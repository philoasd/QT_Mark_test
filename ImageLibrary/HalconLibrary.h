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
	/// <param name="width">图像宽度</param>
	/// <param name="height">图像高度</param>
	void ShowImage(const HObject& image, Hlong winID, int imgWidth, int imgHeight);

private:
	HTuple windowHandle;// 显示窗口句柄
};

