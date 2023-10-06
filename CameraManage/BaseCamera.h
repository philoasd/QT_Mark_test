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
	virtual	vector<string> GetCameraDevices() = 0;//获取相机设备
	virtual	void ConnectedCamera(int serialNumber) = 0;//连接相机
	virtual	void DisConnectedCamera() = 0;//断开相机
	virtual	void StartCapture(int flag) = 0;//开始采集
	virtual	void StopCapture() = 0;//停止采集
};