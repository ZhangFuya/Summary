#include <iostream>
#include <opencv2/opencv.hpp>

void Callback(int, void*) { }

int main(int argc, char** argv) {
	using namespace cv;
	using namespace std;

	Mat src = imread("./test.jpg", IMREAD_UNCHANGED);
	string winname = "TrackBar-ColorSpace";
	Mat des;
	int k;
	// 如果要加上 COLOR_GRAY2BGR 图片应该是三通道
	int arr[5] = { COLOR_BGR2HLS_FULL, COLOR_HLS2BGR, COLOR_BGR2GRAY,  COLOR_BGR2YUV };
	namedWindow(winname, WINDOW_NORMAL);
	resizeWindow(winname, 500, 300);
	createTrackbar("TrackBar", winname, 0, 4, Callback);
	while (true){
		k = getTrackbarPos("TrackBar", winname);
		cvtColor(src, des, arr[k]);
		imshow(winname, des);
		imwrite("./test.jpg", des);
		waitKey(10);
	}

	waitKey(0);
	return 0;
}
