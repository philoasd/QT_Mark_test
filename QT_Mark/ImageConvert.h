#pragma once
#include <QImage>
#include <BaslerCamera.h>

/// <summary>
/// 图像转换类
/// </summary>
class ImageConvert
{
public:
	/// <summary>
	/// 将图像转换为QImage
	/// </summary>
	/// <param name="ptrGrabResult"></param>
	/// <returns></returns>
	static QImage ConvertToQImage(const CGrabResultPtr& ptrGrabResult);
};

