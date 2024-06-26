#include "stdafx.h"
#pragma once

void detectCornerHarris(Mat& src_gray, Mat& dst);
std::vector<Point2f> detectHarris(Mat& src_gray);
vector<KeyPoint> harrisDetectKeyPoints(Mat& image);