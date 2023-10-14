#pragma once
#include <QImage>
#include "QT_Mark.h"

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

	/// <summary>
	/// 将图像转换为CProImage
	/// </summary>
	/// <param name="ptrGrabResult"></param>
	/// <returns></returns>
	static CProImage ConvertToCProImage(const CGrabResultPtr& ptrGrabResult);
};
