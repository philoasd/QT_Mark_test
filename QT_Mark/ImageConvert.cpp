#include "ImageConvert.h"

QImage ImageConvert::ConvertToQImage(const Pylon::CGrabResultPtr& ptrGrabResult)
{
	QImage img((uchar*)ptrGrabResult->GetBuffer(), ptrGrabResult->GetWidth(), ptrGrabResult->GetHeight(), QImage::Format_Grayscale8);
	return img;
}

CProImage ImageConvert::ConvertToCProImage(const Pylon::CGrabResultPtr& ptrGrabResult)
{
	CProImage img;
	img.Set(ptrGrabResult->GetWidth(), ptrGrabResult->GetHeight(), CProData::FormatUByte, ptrGrabResult->GetBuffer());
	return img;
}

QImage ImageConvert::ConvertMatToQImage(const cv::Mat& mat)
{
	if (mat.type() == CV_8UC1) // 单通道
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		uchar* pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar* pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	else if (mat.type() == CV_8UC3) // 3通道
	{
		cv::Mat dst;
		cv::cvtColor(mat, dst, cv::COLOR_BGR2RGB);
		const uchar* pSrc = (const uchar*)dst.data;
		QImage image(pSrc, dst.cols, dst.rows, dst.step, QImage::Format_RGB888);
		return image.copy();
	}
	else if (mat.type() == CV_8UC4) // 4通道
	{
		const uchar* pSrc = (const uchar*)mat.data;
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		return QImage();
	}
}
