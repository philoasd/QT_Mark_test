#include "pch.h"
#include "MatroxLibrary.h"

MatroxLibrary::MatroxLibrary()
{
	MilApplication = MappAlloc(M_NULL, M_DEFAULT, M_UNIQUE_ID);
	MilSystem = MsysAlloc(MilApplication, MIL_TEXT("M_SYSTEM_HOST"), M_DEFAULT, M_DEFAULT, M_UNIQUE_ID);
	MilDisplay = MdispAlloc(MilSystem, M_DEFAULT, MIL_TEXT("M_DEFAULT"), M_WINDOWED, M_UNIQUE_ID);
}

MatroxLibrary::~MatroxLibrary()
{

}

void MatroxLibrary::SetDispMode(DispMode mode)
{
	MdispControl(MilDisplay, M_CENTER_DISPLAY, M_DEFAULT); // Center the display.
	switch (mode)
	{
	case MatroxLibrary::GTK: {
		MdispControl(MilDisplay, M_GTK_MODE, M_ENABLE);
		break;
	}
	case MatroxLibrary::TK: {
		MdispControl(MilDisplay, M_TK_MODE, M_ENABLE);
		break;
	}
	case MatroxLibrary::QT: {
		MdispControl(MilDisplay, M_QT_MODE, M_ENABLE);
		break;
	}
	default:
		break;
	}
}

void MatroxLibrary::ShowImage(MIL_ID& img, MIL_WINDOW_HANDLE handle)
{
	MdispSelectWindow(MilDisplay, img, handle);
}

void MatroxLibrary::ShowImage(MIL_ID& img)
{
	MdispSelect(MilDisplay, img);
}

void MatroxLibrary::SaveImage(std::string& path, MIL_ID img)
{
	//MbufSave(path.c_str(), img); //todo: bug
}
