#include "shift_FeatureDetection.h"
#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;
using namespace cv;

Mat detectShif(Mat& src_gray)
{
	//Creare SIFT
	Ptr<SIFT> detector = SIFT::create();
	//Detectare si descriptor
	vector<KeyPoint> keypoints;
	Mat descriptors;
	detector->detectAndCompute(src_gray, noArray(), keypoints, descriptors);

	sort(keypoints.begin(), keypoints.end(), [](const KeyPoint& a, const KeyPoint& b) {
		return a.response > b.response;
		});
	int maxKeypoints = 100; // Set the maximum number of keypoints you want
	if (keypoints.size() > maxKeypoints) {
		keypoints.resize(maxKeypoints);
	}

	//Desenare keypoints
	Mat img_keypoints;
	drawKeypoints(src_gray, keypoints, img_keypoints, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

	return img_keypoints;
}
