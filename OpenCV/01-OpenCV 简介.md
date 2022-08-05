## OpenCV是什么           
OpenCV是计算机视觉开源库，主要算法涉及图像处理和机器学习相关方法。        

## OpenCV的核心模块          
-  HighGUI部分              
-  **Image Process**          
-  2D Feature           
-  Camera Calibration and 3D reconstruction        
-  Video Analysis            
-  Object Detection            
-  Machine Learning       
-  GPU加速         

## OpenCV的下载以及VS下的配置         
- 搜索OpenCV在官网页面下 -> Library -> Release找到想要的版本进行下载         
- 将 opencv/build/x64/vc14/bin 的完整路径添加到环境变量中         
- VS中项目右键 -> 属性 -> VC++目录 -> 包含目录，将 opencv/build/include         
opencv/build/include/opencv(高版本不包含该目录) 以及 opencv/build/include/opencv2 添加进来         
- 在上一步的基础上(同一页面)添加依赖库。         
库目录 -> 将 opencv/build/x64/vc14/lib 添加到项目中         
- 添加链接库。VS中项目右键 -> 属性 -> 链接器 -> 附加依赖项 -> 手动输入 opencv/build/x64/vc14/lib里库的名称。         
注意：这里输入的是 .lib 库文件的全名(包含后缀名)。如果是debug模式编译输入带d的库全名。如果是release模式编译不需要带d的库全名。注意要使用64位的编译环境(vs调试器旁边必须选中x64的环境)         

## OpenCV的简单应用         
```c++
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main(int argc, char** argv) {
	Mat img = imread("D:/DevFile/assert/522278.jpg");
	if (img.empty()) {
		std::cout << "无法加载图片" << std::endl;
	}
	imshow("nilTitle", img);
	waitKey(0);
	return 0;
}
```



