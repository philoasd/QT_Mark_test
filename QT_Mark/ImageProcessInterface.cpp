#pragma execution_character_set("utf-8") // 显示中文

#include "ImageProcessInterface.h"

ImageProcessInterface::ImageProcessInterface(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	InitControl();
}

ImageProcessInterface::~ImageProcessInterface()
{}

void ImageProcessInterface::InitControl()
{
#pragma region table widge控件
	QString tableHeader[4] = { "图像预处理", "标定", "边缘查找", "blob分析" };
	for (int i = 0; i < tableHeader->size(); i++)
	{
		ui.tabWidget->setTabText(i, tableHeader[i]);
	}
#pragma endregion

#pragma region 滑块控件
	ui.horizontalSlider_Threshold->setHandleMovementMode(QxtSpanSlider::NoOverlapping); // 设置滑块不重叠
	ui.horizontalSlider_Threshold->setMaximum(255); // 设置滑块最大值
	ui.horizontalSlider_Threshold->setMinimum(0); // 设置滑块最小值
#pragma endregion
}
