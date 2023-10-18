#include "pch.h"
#include "MatroxLibrary.h"

MatroxLibrary::MatroxLibrary()
{
	MilApplication = MappAlloc(M_NULL, M_DEFAULT, M_UNIQUE_ID);
	MilSystem = MsysAlloc(MilApplication, MIL_TEXT("M_SYSTEM_HOST"), M_DEFAULT, M_DEFAULT, M_UNIQUE_ID);
	MilDisplay = MdispAlloc(MilSystem, M_DEFAULT, MIL_TEXT("M_DEFAULT"), M_DEFAULT, M_UNIQUE_ID);
}

MatroxLibrary::~MatroxLibrary()
{
	MosGetch();
}
