#pragma once

#include <QWidget>
#include "ui_ImageProcessInterface.h"
#include "QxtSpanSlider.h"
#include <pylon/PylonIncludes.h>
#include "ImageConvert.h"
#include <QMetaType>
#include <QVariant>

#include "Def.h"
#if DALSA
#include <DalsaLibrary.h>
#elif MATROX
#include <MatroxLibrary.h>
#elif OPENCV
#include <OpenCVLibrary.h>
#endif

Q_DECLARE_METATYPE(Pylon::CGrabResultPtr)

class ImageProcessInterface : public QWidget
{
	Q_OBJECT

public:
	ImageProcessInterface(QWidget* parent = nullptr);
	~ImageProcessInterface();
private:
	/// <summary>
	/// 初始化控件，一般是对控件的一些显示或者属性进行设置
	/// </summary>
	void InitControl();

	/// <summary>
	/// 初始化连接，一般是对信号和槽进行连接
	/// </summary>
	void InitConnect();

signals:
	void SendGetImageSignal(int flag);

public slots:
	void GetImageFromMainWindow(QVariant ptrGrabResult);

private:
	Ui::ImageProcessInterfaceClass ui;
	Pylon::CGrabResultPtr PtrGrabResult; // 用于接收主界面传递过来的图像,作为当前界面公用的图像

#if DALSA
	DalsaLibrary* ImageProcess = nullptr;
#elif MATROX
	MatroxLibrary* ImageProcess = nullptr;
#elif OPENCV
	OpenCVLibrary* ImageProcess = nullptr;
#endif
public:
	bool IsShowing = false; // 是否打开了界面
};