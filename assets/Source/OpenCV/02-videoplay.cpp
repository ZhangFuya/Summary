#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
	using namespace cv;
	using namespace std;

	Mat capPic;
	int key;
	//如果 VideoCapture 的参数指定为0，则采用摄像头进行视频的采集
	//VideoCapture cap = VideoCapture(0);
    VideoCapture cap = VideoCapture("./test.mp4");
	namedWindow("Video", WINDOW_NORMAL);
	resizeWindow("Video", 500, 300);
	if (!cap.isOpened()) {
		cout << "capture open failed" << endl;
		return -1;
	}
	while (cap.read(capPic)) {
		imshow("Video", capPic);
		key = waitKey(40);
		if (key == 'q') {
			break;
		}
	}
	cap.release();
	destroyAllWindows();

	return 0;
}
