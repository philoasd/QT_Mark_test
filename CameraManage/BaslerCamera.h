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

/// <summary>
/// Basler相机类
/// </summary>
class __declspec(dllexport) BaslerCamera : public BaseCmaera
{
public:
	BaslerCamera();
	vector<string> GetCameraDevices() override;
	void ConnectedCamera(int serialNumber) override;

	/// <summary>
	/// 注册相机回调函数
	/// </summary>
	/// <param name="imageEventHandler"></param>
	void RegisterImageEvent(ImageEventHandler* imageEventHandler);
	
	/// <summary>
	/// 注销相机回调函数
	/// </summary>
	/// <param name="imageEventHandler"></param>
	void DeregisterImageEvent(ImageEventHandler* imageEventHandler);

	void DisConnectedCamera() override;
	void StartCapture(int flag) override;
	void StopCapture() override;

	/// <summary>
	/// 保存图像
	/// </summary>
	/// <param name="path"></param>
	/// <param name="ptrGrabResult"></param>
	void SaveImage(const string& path, const CGrabResultPtr& ptrGrabResult);

public:

private:
	CInstantCamera Camera;//相机对象
	DeviceInfoList_t Devices;//相机设备列表
	bool IsInitCamera = false;//是否初始化相机
};