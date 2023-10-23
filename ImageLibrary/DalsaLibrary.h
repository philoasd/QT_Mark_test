#pragma once
#include <CPro.h>
#include <CProSearch.h>
#include <string>

/// <summary>
/// Dalsa相机库
/// </summary>
class __declspec(dllexport) DalsaLibrary
{
public:
#pragma region Search edge
	/// <summary>
	/// 训练模板
	/// </summary>
	/// <param name="img"></param>
	/// <param name="rect"></param>
	/// <param name="modelName"></param>
	/// <param name="search"></param>
	void TrainModel(CProImage& img, CProRect& rect, std::string& modelName, CProSearchEdge& search);

	/// <summary>
	/// 设置最小旋转角度
	/// </summary>
	/// <param name="minRotation"></param>
	/// <param name="search"></param>
	void SetMinRotation(double minRotation, CProSearchEdge& search);
	/// <summary>
	/// 获取最小旋转角度
	/// </summary>
	/// <param name="search"></param>
	/// <returns></returns>
	double GetMinRotation(CProSearchEdge& search) const;

	/// <summary>
	/// 设置最大旋转角度
	/// </summary>
	/// <param name="maxRotation"></param>
	/// <param name="search"></param>
	void SetMaxRotation(double maxRotation, CProSearchEdge& search);
	/// <summary>
	/// 获取最大旋转角度
	/// </summary>
	/// <param name="search"></param>
	/// <returns></returns>
	double GetMaxRotation(CProSearchEdge& search) const;

	/// <summary>
	/// 设置最小尺度
	/// </summary>
	/// <param name="minScale"></param>
	/// <param name="search"></param>
	void SetMinScale(double minScale, CProSearchEdge& search);
	/// <summary>
	/// 获取最小尺度
	/// </summary>
	/// <param name="search"></param>
	/// <returns></returns>
	double GetMinScale(CProSearchEdge& search) const;

	/// <summary>
	/// 设置最大尺度
	/// </summary>
	/// <param name="maxScale"></param>
	/// <param name="search"></param>
	void SetMaxScale(double maxScale, CProSearchEdge& search);
	/// <summary>
	/// 获取最大尺度
	/// </summary>
	/// <param name="search"></param>
	/// <returns></returns>
	double GetMaxScale(CProSearchEdge& search) const;

	/// <summary>
	/// 设置最小得分
	/// </summary>
	/// <param name="minScore"></param>
	/// <param name="search"></param>
	void SetMinScore(double minScore, CProSearchEdge& search);
	/// <summary>
	/// 获取最小得分
	/// </summary>
	/// <param name="search"></param>
	/// <returns></returns>
	double GetMinScore(CProSearchEdge& search) const;

	/// <summary>
	/// 设置最小对比度
	/// </summary>
	/// <param name="minContrast"></param>
	/// <param name="search"></param>
	void SetMinContrast(double minContrast, CProSearchEdge& search);
	double GetMinContrast(CProSearchEdge& search) const;

	/// <summary>
	/// 执行搜索
	/// </summary>
	/// <param name="img"></param>
	/// <param name="search"></param>
	void Execute(CProImage& img, CProSearchEdge& search);
#pragma endregion

	/// <summary>
	/// 保存图像
	/// </summary>
	/// <param name="path"></param>
	/// <param name="img"></param>
	void SaveImage(std::string& path, CProImage& img);
};

