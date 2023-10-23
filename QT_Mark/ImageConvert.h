#pragma once
#include <QImage>
#include <pylon/PylonIncludes.h>
#include <CPro.h>
#include <opencv2/opencv.hpp>
#include <Mil.h>

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

	/// <summary>
	/// 将OpenCV图像转换为QImage
	/// </summary>
	/// <param name="mat"></param>
	/// <returns></returns>
	static QImage ConvertMatToQImage(const cv::Mat& mat);

	/// <summary>
	/// 将图像转换为MIL图像
	/// </summary>
	/// <param name="ptrGrabResult"></param>
	/// <returns></returns>
	static MIL_ID ConvertToMilImage(const Pylon::CGrabResultPtr& ptrGrabResult, MIL_ID MilSystem);

	/// <summary>
	/// 将OpenCV图像转换为MIL图像
	/// </summary>
	/// <param name="mat"></param>
	/// <returns></returns>
	static MIL_ID ConvertMatToMilImage(const cv::Mat& mat, MIL_ID MilSystem);
};
