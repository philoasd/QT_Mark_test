#pragma once
#include <pylon/PylonIncludes.h>
#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include "BaseCamera.h"

using namespace Pylon;
using namespace std;

/// <summary>
/// 相机回调函数
/// </summary>
class ImageEventHandler : public CImageEventHandler
{
public:
	using ImageCallback = function<void(const CGrabResultPtr&)>;
	ImageEventHandler(ImageCallback callback) : imageCallback(callback) {}

	/*virtual*/ void OnImageGrabbed(CInstantCamera& camera, const CGrabResultPtr& ptrGrabResult) override
	{
		if (ptrGrabResult->GrabSucceeded())
		{
			imageCallback(ptrGrabResult);
		}
	}
private:
	ImageCallback imageCallback;
};

class __declspec(dllexport) BaslerCamera : public BaseCmaera
{
public:
	BaslerCamera();
	vector<string> GetCameraDevices() override;
	void ConnectedCamera(int serialNumber) override;
	void RegisterImageEvent(ImageEventHandler* imageEventHandler);// 注册相机回调函数
	void DeregisterImageEvent(ImageEventHandler* imageEventHandler);// 注销相机回调函数
	void DisConnectedCamera() override;
	void StartCapture(int flag) override;
	void StopCapture() override;
	void SaveImage(const string& path, const CGrabResultPtr& ptrGrabResult);// 保存图像

public:

private:
	CInstantCamera Camera;
	DeviceInfoList_t Devices;
	bool IsInitCamera = false;
};