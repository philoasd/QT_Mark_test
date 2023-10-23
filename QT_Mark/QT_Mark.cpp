#include "QT_Mark.h"

QT_Mark::QT_Mark(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	InitControl();
	InitConnect();
	m_ImageProcess = new MatroxLibrary();
}

QT_Mark::~QT_Mark()
{
	if(m_ImageProcess==nullptr)
		delete m_ImageProcess;
	if(imageProcessInterface == nullptr)
		delete imageProcessInterface;
}

void QT_Mark::InitCameraDevices()
{
	m_Camera = new BaslerCamera();
	m_Camera->GetCameraDevices();
}

void QT_Mark::InitControl()
{
	ui.stackedWidget->setCurrentIndex(0); // 设置当前显示的页面为第一个页面
	ui.actionMark->setVisible(false);	  // 隐藏Mark界面的菜单栏
	ui.toolBar_Vision->setVisible(false); // 隐藏图像界面的工具栏

#pragma region 状态栏的操作
	timer = new QTimer(this);
	// 添加右对齐的Label到状态栏
	QLabel* rightAlignedLabel = new QLabel(this);
	rightAlignedLabel->setAlignment(Qt::AlignRight); // 设置右对齐
	statusBar()->addPermanentWidget(rightAlignedLabel);
#pragma endregion

	ui.actionGrabStop->setEnabled(false); // 停止取图按钮不可用


}

void QT_Mark::InitConnect()
{
#pragma region mark界面和图像界面的切换
	connect(ui.actionMark, &QAction::triggered, this, [&]()
		{
			ui.stackedWidget->setCurrentIndex(0);	// 设置当前显示的页面为第一个页面
			ui.actionMark->setVisible(false);	  // 隐藏mark界面的菜单栏
			ui.actionVision->setVisible(true);	  // 显示图像界面的菜单栏
			ui.toolBar_Vision->setVisible(false); // 隐藏图像界面的工具栏
			ui.toolBar_Shape->setVisible(true);	  // 显示mark界面的工具栏

			DisconnectedCamera(); // 断开相机
			ui.actionGrabContinue->setEnabled(true); // 连续取图按钮可用
			ui.actionGrabOnce->setEnabled(true);	 // 单次取图按钮可用
			ui.actionGrabStop->setEnabled(false);	 // 停止取图按钮不可用
			ui.label_ShowImage->clear();			 // 清空图像显示
		});
	connect(ui.actionVision, &QAction::triggered, this, [&]()
		{
			ui.stackedWidget->setCurrentIndex(1);	// 设置当前显示的页面为第二个页面
			ui.actionVision->setVisible(false);// 隐藏图像界面的菜单栏
			ui.actionMark->setVisible(true);// 显示mark界面的菜单栏
			ui.toolBar_Vision->setVisible(true);// 显示图像界面的工具栏
			ui.toolBar_Shape->setVisible(false);// 隐藏mark界面的工具栏
			InitCameraDevices();
			ConnectedCamera(); // 连接相机
			ui.actionGrabOnce->triggered(); // 单次取图
		});
#pragma endregion

#pragma region 状态栏的操作
	connect(timer, &QTimer::timeout, this, [&]()
		{
			ui.statusBar->findChild<QLabel*>()->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd")); // 设置状态栏的时间
		});
	timer->start(1000);
#pragma endregion

#pragma region 图像界面的操作
	// 连续取图
	connect(ui.actionGrabContinue, &QAction::triggered, this, [&]()
		{
			m_Camera->StartCapture(1);
			ui.actionGrabContinue->setEnabled(false); // 连续取图按钮不可用
			ui.actionGrabOnce->setEnabled(false);	  // 单次取图按钮不可用
			ui.actionGrabStop->setEnabled(true);	  // 停止取图按钮可用
		});
	// 单次取图
	connect(ui.actionGrabOnce, &QAction::triggered, this, [&]()
		{
			m_Camera->StartCapture(0);
		});
	// 停止取图
	connect(ui.actionGrabStop, &QAction::triggered, this, [&]()
		{
			m_Camera->StopCapture();
			ui.actionGrabContinue->setEnabled(true); // 连续取图按钮可用
			ui.actionGrabOnce->setEnabled(true);	 // 单次取图按钮可用
			ui.actionGrabStop->setEnabled(false);	 // 停止取图按钮不可用
		});
	// 打开图像处理界面
	connect(ui.actionImageProcessInterface, &QAction::triggered, this, [&]()
		{
			imageProcessInterface = new ImageProcessInterface();
			imageProcessInterface->show(); // 显示图像处理界面
			imageProcessInterface->IsShowing = true; // 设置图像处理界面正在显示
			imageProcessInterface->ImageProcess = m_ImageProcess; // 将图像处理库传递给图像处理界面

			connect(imageProcessInterface, &ImageProcessInterface::SendGetImageSignal, this, &QT_Mark::GetImageSignalFromChildInterface);
			connect(this, &QT_Mark::SendImageToChildInterface, imageProcessInterface, &ImageProcessInterface::GetImageFromMainWindow); // 发送图像给子界面
		});
#pragma endregion
}

void QT_Mark::ShowImage(const CGrabResultPtr& ptrGrabResult)
{
	if (ptrGrabResult->GrabSucceeded())
	{
		QImage img = ImageConvert::ConvertToQImage(ptrGrabResult); // 将Basler图像原始数据转换为QImage
		ui.label_ShowImage->setPixmap(QPixmap::fromImage(img).scaled(ui.label_ShowImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
		if (imageProcessInterface != nullptr) {
			emit SendImageToChildInterface(QVariant::fromValue(ptrGrabResult)); // 发送图像给子界面
		}
	}
}

void QT_Mark::ConnectedCamera()
{
	m_Camera->ConnectedCamera(0);
	callback = [&](const CGrabResultPtr& ptrGrabResult)
		{
			ShowImage(ptrGrabResult);
		};
	m_ImageEventHandler = new ImageEventHandler(callback);
	m_Camera->RegisterImageEvent(m_ImageEventHandler);
}

void QT_Mark::DisconnectedCamera()
{
	m_Camera->DisConnectedCamera();
	if (m_ImageEventHandler != nullptr)
	{
		// callback = nullptr;
		m_Camera->DeregisterImageEvent(m_ImageEventHandler);
		m_ImageEventHandler = nullptr;
		delete m_ImageEventHandler;
	}
	delete m_Camera;
}

void QT_Mark::InitImageProcessLibrary()
{
	m_ImageProcess = new MatroxLibrary();
	m_ImageProcess->SetDispMode(MatroxLibrary::QT); // 设置显示模式为QT
}

void QT_Mark::GetImageSignalFromChildInterface(int flag)
{
	switch (flag)
	{
	case 0: {
		ui.actionGrabOnce->triggered();
		break;
	}
	case 1: {
		ui.actionGrabContinue->triggered();
		break;
	}
	default: {
		ui.actionGrabStop->triggered();
		break;
	}
	}
}
