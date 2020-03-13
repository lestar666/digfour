// tunning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

string window_name = "binaryMat";

void threshod_Mat(int th, void*data)
{
	Mat src = *(Mat*)(data);
	
	Mat dst;

	threshold(src, dst, th, 255, 0);
	
	imshow(window_name, dst);
}
int main() {
	Mat srcMat;
	Mat gryMat;
	int lowTh = 30;
	int maxTh = 255;

	srcMat = imread("D:\\1.jpg");
	if (!srcMat.data) {
		cout << "fail to improt" << endl;
		return 0;
	}
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);
	imshow(window_name, gryMat);
	createTrackbar("threshold",
		window_name,
		&lowTh,
		maxTh,
		threshod_Mat,
		&gryMat);
	waitKey(0);
	return 0;
}