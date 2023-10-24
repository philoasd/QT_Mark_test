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
{
	IsShowing = false;
	//delete ImageProcess;
}

void ImageProcessInterface::InitControl()
{
#pragma region 固定窗口大小
	int width = this->width();
	int height = this->height();
	this->setFixedSize(width, height);
#pragma endregion

#pragma region table widge控件
	QList<QString>tableHeader = { "图像预处理", "标定", "边缘查找", "blob分析" };
	for (int i = 0; i < tableHeader.size(); i++)
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

#pragma region 取图按钮控件
	ui.pushButton_GrabStop->setVisible(false);
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

#pragma region 获取图像按钮控件
	connect(ui.pushButton_GetOneImage, &QPushButton::clicked, this, [&]() {
		emit SendGetImageSignal(0); // 发送获取图像信号给主界面
		});
	connect(ui.pushButton_GetContinueImage, &QPushButton::clicked, this, [&]() {
		ui.pushButton_GrabStop->setVisible(true);
		ui.pushButton_GetContinueImage->setVisible(false);
		emit SendGetImageSignal(1); // 发送获取图像信号给主界面
		});
	connect(ui.pushButton_GrabStop, &QPushButton::clicked, this, [&]() {
		ui.pushButton_GrabStop->setVisible(false);
		ui.pushButton_GetContinueImage->setVisible(true);
		emit SendGetImageSignal(2); // 发送停止图像信号给主界面
		});
#pragma endregion

#pragma region 是否使用自动阈值按钮控件
	connect(ui.checkBox_AutoThreshold, &QCheckBox::clicked, this, [&]() {
		ui.spinBox_leftThreshold->setEnabled(!ui.checkBox_AutoThreshold->isChecked());
		ui.spinBox_rightThreshold->setEnabled(!ui.checkBox_AutoThreshold->isChecked());
		ui.horizontalSlider_Threshold->setEnabled(!ui.checkBox_AutoThreshold->isChecked());
		});
	connect(ui.checkBox_ManualThreshold, &QCheckBox::clicked, this, [&]() {
		ui.spinBox_leftThreshold->setEnabled(ui.checkBox_ManualThreshold->isChecked());
		ui.spinBox_rightThreshold->setEnabled(ui.checkBox_ManualThreshold->isChecked());
		ui.horizontalSlider_Threshold->setEnabled(ui.checkBox_ManualThreshold->isChecked());
		});
#pragma endregion
}

void ImageProcessInterface::GetImageFromMainWindow(QVariant _PtrGrabResult)
{
	Pylon::CGrabResultPtr ptrGrabResult = _PtrGrabResult.value<Pylon::CGrabResultPtr>();
	//PtrGrabResult = ptrGrabResult;
	//QImage img = ImageConvert::ConvertToQImage(ptrGrabResult); // 将Basler图像原始数据转换为QImage
	//ui.label_ImageProcess->setPixmap(QPixmap::fromImage(img).scaled(ui.label_ImageProcess->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

	/*auto img = ImageConvert::ConvertToMilImage(ptrGrabResult, ImageProcess->MilSystem);
	if (IsShowing) {
		ImageProcess->ShowImage(img, (MIL_WINDOW_HANDLE)ui.frame->winId());

		std::string path = "test.bmp";
		ImageProcess->SaveImage(path, img);
	}*/

	auto img = ImageConvert::ConvertToHalconImage(ptrGrabResult);
	if (IsShowing) {
		int width = ui.label_ImageProcess->width();
		int height = ui.label_ImageProcess->height();
		ImageProcess->ShowImage(img, (Hlong)(ui.label_ImageProcess->winId()), width, height);
	}
}
