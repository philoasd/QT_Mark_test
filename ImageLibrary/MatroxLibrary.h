#pragma once
#include <Mil.h>

class __declspec(dllexport) MatroxLibrary
{
public:
	MatroxLibrary();
	~MatroxLibrary();
private:
	MIL_UNIQUE_APP_ID MilApplication; // Application identifier.
	MIL_UNIQUE_SYS_ID MilSystem; // System identifier.
	MIL_UNIQUE_DISP_ID MilDisplay;	// Display identifier.
};
