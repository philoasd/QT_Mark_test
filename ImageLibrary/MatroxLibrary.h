#pragma once
#include <Mil.h>

class __declspec(dllexport) MatroxLibrary
{
public:
	MatroxLibrary();
	~MatroxLibrary();

	/// <summary>
	/// 显示模式
	/// </summary>
	enum DispMode
	{
		GTK,
		TK,
		QT
	};

	/// <summary>
	/// 设置显示模式
	/// </summary>
	/// <param name="mode"></param>
	void SetDispMode(DispMode mode);

	/// <summary>
	/// 显示图片到指定的控件或窗口
	/// </summary>
	/// <param name="img">图像</param>
	/// <param name="handle">控件或窗口句柄</param>
	void ShowImage(MIL_ID& img, MIL_WINDOW_HANDLE handle);
	void ShowImage(MIL_ID& img);

	void SaveImage(std::string& path, MIL_ID img);
public:
	MIL_UNIQUE_APP_ID MilApplication; // Application identifier.
	MIL_UNIQUE_SYS_ID MilSystem; // System identifier.
	MIL_UNIQUE_DISP_ID MilDisplay;	// Display identifier.
};
