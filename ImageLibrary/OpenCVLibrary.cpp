#include "pch.h"
#include "OpenCVLibrary.h"

OpenCVLibrary::OpenCVLibrary()
{
}

Mat OpenCVLibrary::Threshold(const Mat& src, int leftThreshold, int rightThreshold)
{
    Mat dst;
    threshold(src, dst, leftThreshold, rightThreshold, THRESH_BINARY);
    return dst;
}
