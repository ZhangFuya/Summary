#include <iostream>
#include <opencv2/opencv.hpp>

void mouse_callback(int event, int x, int y, int flags, void* param) {
	if (event == cv::EVENT_MOUSEMOVE)
		std::cout << "鼠标位置，x=" << x << ". y=" << y << std::endl;
}

int main(int argc, char** argv) {
	using namespace cv;
	using namespace std;

	Mat pic = imread("./test.jpg", IMREAD_COLOR);
	namedWindow("MouseCallBack", WINDOW_NORMAL);
	resizeWindow("MouseCallBack", 500, 300);
	imshow("MouseCallBack", pic);
	setMouseCallback("MouseCallBack", mouse_callback);
	waitKey(0);
	return 0;
}
