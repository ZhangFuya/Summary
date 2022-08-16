#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
	using namespace cv;
	using namespace std;

	Mat src;
	int key;
	src = imread("./test.jpg", IMREAD_COLOR);
	if (src.empty()) {
		cout << "open failed" << endl;
		return -1;
	}
	namedWindow("PicShow", WINDOW_NORMAL);
	resizeWindow("PicShow", 500, 300);
	imshow("PicShow", src);
	while (true)
	{
		key = waitKey(0);
		if (key == 'q') {
			break;
		}
		else if (key == 's')
		{
			imwrite("./test.png", src);
		}
		else
		{
			cout << "key's Value is :> " << (char)key << endl;
		}
	}
	destroyAllWindows();

	return 0;
}
