#pragma once

#include <QWidget>
#include "ui_ImageProcessInterface.h"

#include <vector>

class ImageProcessInterface : public QWidget
{
	Q_OBJECT

public:
	ImageProcessInterface(QWidget *parent = nullptr);
	~ImageProcessInterface();
private:
	void InitControl();
private:
	Ui::ImageProcessInterfaceClass ui;
};
