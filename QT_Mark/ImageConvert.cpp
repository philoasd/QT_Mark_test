#include "ImageConvert.h"

QImage ImageConvert::ConvertToQImage(const CGrabResultPtr& ptrGrabResult)
{
    QImage img((uchar*)ptrGrabResult->GetBuffer(), ptrGrabResult->GetWidth(), ptrGrabResult->GetHeight(), QImage::Format_Grayscale8);
    return img;
}
