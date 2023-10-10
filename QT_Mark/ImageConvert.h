#pragma once
#include <QImage>
#include <BaslerCamera.h>

class ImageConvert
{
public:
	static QImage ConvertToQImage(const CGrabResultPtr& ptrGrabResult); //将图像转换为QImage
};

