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
