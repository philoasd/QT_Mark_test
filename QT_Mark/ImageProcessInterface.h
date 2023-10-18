#pragma once

#include <QWidget>
#include "ui_ImageProcessInterface.h"
#include "QxtSpanSlider.h"

#include <vector>

class ImageProcessInterface : public QWidget
{
	Q_OBJECT

public:
	ImageProcessInterface(QWidget *parent = nullptr);
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
private:
	Ui::ImageProcessInterfaceClass ui;
};
