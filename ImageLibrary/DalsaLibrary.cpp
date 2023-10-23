#include "pch.h"
#include "DalsaLibrary.h"

#pragma region Search edge
void DalsaLibrary::TrainModel(CProImage& img, CProRect& rect, std::string& modelName, CProSearchEdge& search)
{
	// 复制一份，避免修改原图
	CProImage tmpImage;
	img.Copy(tmpImage);

	tmpImage.SetRoi(rect);
	search.AddModel(modelName.c_str(), tmpImage);
}

void DalsaLibrary::SetMinRotation(double minRotation, CProSearchEdge& search)
{
	search.SetMinRotation(minRotation);
}

double DalsaLibrary::GetMinRotation(CProSearchEdge& search) const
{
	return search.GetMinRotation();
}

void DalsaLibrary::SetMaxRotation(double maxRotation, CProSearchEdge& search)
{
	search.SetMaxRotation(maxRotation);
}

double DalsaLibrary::GetMaxRotation(CProSearchEdge& search) const
{
	return search.GetMaxRotation();
}

void DalsaLibrary::SetMinScale(double minScale, CProSearchEdge& search)
{
	search.SetMinScale(minScale);
}

double DalsaLibrary::GetMinScale(CProSearchEdge& search) const
{
	return search.GetMinScale();
}

void DalsaLibrary::SetMaxScale(double maxScale, CProSearchEdge& search)
{
	search.SetMaxScale(maxScale);
}

double DalsaLibrary::GetMaxScale(CProSearchEdge& search) const
{
	return search.GetMaxScale();
}

void DalsaLibrary::SetMinScore(double minScore, CProSearchEdge& search)
{
	search.SetMinScore(minScore);
}

double DalsaLibrary::GetMinScore(CProSearchEdge& search) const
{
	return search.GetMinScore();
}

void DalsaLibrary::SetMinContrast(double minContrast, CProSearchEdge& search)
{

}

double DalsaLibrary::GetMinContrast(CProSearchEdge& search) const
{
	return 0.0;
}

void DalsaLibrary::Execute(CProImage& img, CProSearchEdge& search)
{
	search.Execute(img);
}

#pragma endregion

void DalsaLibrary::SaveImage(std::string& path, CProImage& img)
{
	img.Save(path.c_str(), CProImage::FileBmp);
}