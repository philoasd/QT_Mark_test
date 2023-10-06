#include "QT_Mark.h"

QT_Mark::QT_Mark(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//连接信号和槽
	{
		//connect(ui.pushButton, &QPushButton::clicked, this, &QT_Mark::Test);
	}

	m_Camera = new BaslerCamera();
}

QT_Mark::~QT_Mark()
{
	delete m_Camera;
}

void QT_Mark::InitCameraDevices()
{

}

void QT_Mark::ShowImage(const CGrabResultPtr& ptrGrabResult)
{
	if (ptrGrabResult->GrabSucceeded())
	{

	}
}

void QT_Mark::Test()
{
	auto devicesInfo = m_Camera->GetCameraDevices();
	m_Camera->ConnectedCamera(0);
	callback = [&](const CGrabResultPtr& ptrGrabResult) {
		ShowImage(ptrGrabResult);
		};
	m_ImageEventHandler = new ImageEventHandler(callback);
	m_Camera->RegisterImageEvent(m_ImageEventHandler);
	m_Camera->StartCapture(0);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	m_Camera->StopCapture();
	if (m_ImageEventHandler != nullptr) {
		//callback = nullptr;
		m_Camera->DeregisterImageEvent(m_ImageEventHandler);
		if (m_ImageEventHandler != nullptr)

			m_ImageEventHandler = nullptr;
			delete m_ImageEventHandler;
	}

	m_Camera->DisConnectedCamera();

}
