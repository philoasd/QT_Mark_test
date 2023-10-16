#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QT_Mark.h"

#include <BaslerCamera.h>
#include <DalsaLibrary.h>

#include "ImageConvert.h"
#include "ImageProcessInterface.h"
#include <thread>
#include <chrono>
#include <qtimer.h>
#include <qdatetime.h>

class QT_Mark : public QMainWindow
{
	Q_OBJECT

public:
	QT_Mark(QWidget *parent = nullptr);
	~QT_Mark();

private:
	/// <summary>
	/// 获取相机设备
	/// </summary>
	void InitCameraDevices();

	/// <summary>
	/// 初始化控件，一般是对控件的一些显示或者属性进行设置
	/// </summary>
	void InitControl();

	/// <summary>
	/// 初始化连接，一般是对信号和槽进行连接
	/// </summary>
	void InitConnect();

	/// <summary>
	/// 显示图像
	/// </summary>
	/// <param name="ptrGrabResult">Basler图像原始数据</param>
	void ShowImage(const CGrabResultPtr &ptrGrabResult);

	/// <summary>
	/// 连接相机
	/// </summary>
	void ConnectedCamera();

	/// <summary>
	/// 断开相机连接
	/// </summary>
	void DisconnectedCamera();

private slots:

private:
	Ui::QT_MarkClass ui;
	BaslerCamera *m_Camera = nullptr;				  // 相机对象
	ImageEventHandler::ImageCallback callback;		  // 图像回调函数
	ImageEventHandler *m_ImageEventHandler = nullptr; // 图像回调对象
	QTimer *timer;									  // 系统时间
};