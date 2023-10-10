#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QT_Mark.h"
#include <BaslerCamera.h>
#include "ImageConvert.h"
#include <thread>
#include <chrono>

class QT_Mark : public QMainWindow
{
	Q_OBJECT

public:
	QT_Mark(QWidget* parent = nullptr);
	~QT_Mark();
private:
	void InitCameraDevices();
	void ShowImage(const CGrabResultPtr& ptrGrabResult);

private slots:
	void Test();
private:
	Ui::QT_MarkClass ui;
	BaslerCamera* m_Camera = nullptr;
	ImageEventHandler::ImageCallback callback;
	ImageEventHandler* m_ImageEventHandler = nullptr;
};
