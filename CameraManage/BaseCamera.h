#pragma once
#include <vector>
#include <string>

using namespace std;

/// <summary>
/// 相机类的抽象类
/// </summary>
class BaseCmaera
{
public:
	/// <summary>
	/// 获取相机设备
	/// </summary>
	/// <returns></returns>
	virtual vector<string> GetCameraDevices() = 0;

	/// <summary>
	/// 连接相机
	/// </summary>
	/// <param name="serialNumber"></param>
	virtual void ConnectedCamera(int serialNumber) = 0;

	/// <summary>
	/// 断开相机
	/// </summary>
	virtual void DisConnectedCamera() = 0;

	/// <summary>
	/// 开始采集
	/// </summary>
	/// <param name="flag">0：单次；1：连续</param>
	virtual void StartCapture(int flag) = 0;

	/// <summary>
	/// 停止采集
	/// </summary>
	virtual void StopCapture() = 0;
};