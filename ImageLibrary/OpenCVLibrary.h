#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

class __declspec(dllexport) OpenCVLibrary
{
public:
	OpenCVLibrary();

#pragma region 图像预处理
	/// <summary>
	/// 二值化
	/// </summary>
	/// <param name="src"></param>
	/// <param name="leftThreshold"></param>
	/// <param name="rightThreshold"></param>
	/// <returns></returns>
	Mat Threshold(const Mat& src, int leftThreshold, int rightThreshold);
#pragma endregion
};

