// function.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("1.jpg");
	Mat op1, op2, op3;

	cvtColor(src, op1, CV_RGB2GRAY);//HUIDUTU

	threshold(op1, op2, 100, 255, THRESH_BINARY);
	imshow("op1 is", op2);
	adaptiveThreshold(op1, op3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 15, 10);
	imshow("op2 is", op3);

	waitKey(0);
	return 0;


}