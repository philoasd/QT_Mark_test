#pragma once
#include <QImage>
#include <pylon/PylonIncludes.h>
#include <CPro.h>

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
	static QImage ConvertToQImage(const Pylon::CGrabResultPtr& ptrGrabResult);

	/// <summary>
	/// 将图像转换为CProImage
	/// </summary>
	/// <param name="ptrGrabResult"></param>
	/// <returns></returns>
	static CProImage ConvertToCProImage(const Pylon::CGrabResultPtr& ptrGrabResult);
};
