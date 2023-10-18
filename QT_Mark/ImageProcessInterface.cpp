#pragma execution_character_set("utf-8") // 显示中文

#include "ImageProcessInterface.h"

ImageProcessInterface::ImageProcessInterface(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	InitControl();
	InitConnect();
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
	ui.spinBox_leftThreshold->setValue(0);
	ui.spinBox_rightThreshold->setValue(255);
	ui.horizontalSlider_Threshold->setLowerValue((int)ui.spinBox_leftThreshold->value()); // 设置滑块左边值
	ui.horizontalSlider_Threshold->setUpperValue((int)ui.spinBox_rightThreshold->value()); // 设置滑块右边值
#pragma endregion
}

void ImageProcessInterface::InitConnect()
{
#pragma region 滑块控件
	// 滑块控件和spinbox控件的连接
	connect(ui.horizontalSlider_Threshold, &QxtSpanSlider::lowerValueChanged, this, [&]() {
		ui.spinBox_leftThreshold->setValue(ui.horizontalSlider_Threshold->lowerValue());
		});
	// 滑块控件和spinbox控件的连接
	connect(ui.horizontalSlider_Threshold, &QxtSpanSlider::upperValueChanged, this, [&]() {
		ui.spinBox_rightThreshold->setValue(ui.horizontalSlider_Threshold->upperValue());
		});
	// spinbox控件和滑块控件的连接
	connect(ui.spinBox_leftThreshold, QOverload<int>::of(&QSpinBox::valueChanged), this, [&]() {
		ui.horizontalSlider_Threshold->setLowerValue(ui.spinBox_leftThreshold->value());
		});
	// spinbox控件和滑块控件的连接
	connect(ui.spinBox_rightThreshold, QOverload<int>::of(&QSpinBox::valueChanged), this, [&]() {
		ui.horizontalSlider_Threshold->setUpperValue(ui.spinBox_rightThreshold->value());
		});
#pragma endregion
}
