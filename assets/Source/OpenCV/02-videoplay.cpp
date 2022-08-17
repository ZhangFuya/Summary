#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
	using namespace cv;
	using namespace std;

	Mat capPic;
	int key;
	// 如果 VideoCapture 的参数指定为0，则采用摄像头进行视频的采集
	// VideoCapture cap = VideoCapture(0);
    VideoCapture cap = VideoCapture("./test.mp4");
	// VideoWrite 必须注意
	// 1.FOUR_CC的写法   2.帧率必须大于24   3.默认情况下帧的大小Size要与原视频保持一致
	VideoWriter writer("./1.mp4", CAP_PROP_FOURCC, 25, Size(1920, 1080));
	namedWindow("Video", WINDOW_NORMAL);
	resizeWindow("Video", 500, 300);

	while (cap.isOpened())
	{
		cap.read(capPic);
		imshow("Video", capPic);
		writer.write(capPic);
		key = waitKey(40);
		if (key == 'q') {
			break;
		}
	}
	cap.release();
	writer.release();
	destroyAllWindows();

	return 0;
}
