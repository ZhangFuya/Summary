## 加载图片 cv::imread         
imread功能是加载图像文件成为一个Mat对象，         
其中第一个参数表示图像文件名称；         
第二个参数表示加载图像的类型。第二个参数常见的值有： IMREAD_UNCHANGED(加载原图不做任何修改)，IMREAD_GRAYSCALE(表示把原图作为灰度图像加载进来)，IMREAD_COLOR(表示把原图作为RGB图像加载进来)         
第二个参数可以使用宏值所表示原值：-1（IMREAD_UNCHANGED）、0（IMREAD_GRAYSCALE）、1（IMREAD_COLOR）         
注意一点：OpenCV支持JPG、PNG、TIFF等常见格式图像文件加载         

## 显示图像 cv::namedWindow 与 cv::imshow          
- namedWindow功能是创建一个OpenCV窗口，它是由OpenCV自动创建与释放，无需手动销毁         
- namedWindow("Window Title", WINDOW_AUTOSIZE)         
- WINDOW_AUTOSIZE 会自动根据图像大小，显示窗口大小。不能人为改变窗口的大小         
- WINDOW_NORMAL，允许修改窗口大小         
- imshow( )根据窗口名称显示图像到指定的窗口上去，第一个参数是窗口名称，第二个参数是Mat对象         
- **当namedWindow( )与imshow( )所表示的窗口名相同时只会创建一个窗口，若不同则会创建两个。此外可以定义多个namedWindow与imshow**     
- 一个视频是由很多的帧组成的，将所有的帧放在一个窗口中进行显示，就形成了视频播放。        
- destoryAllWindows 释放所有窗口              
- resizeWindow 设置窗口的大小     

## 修改图像的颜色空间 cv::cvtColor         
cvtColor的功能是把图像从一个色彩空间转换到另一个色彩空间。有三个参数，第一个参数表示源图像，第二个参数表示色彩空间转换之后的图像，第三个参数表示源和目标色彩空间，如：COLOR_BGR2HLS、COLOR_BGR2GRAY等         
举例：cvtColor( image, gray_image, COLOR_BGR2HLS )        

## 保存图像 cv::imwrite         
- 保存图像文件到指定目录路径         
- 只有8位、16位的PNG、JPG、Tiff文件格式而且是单通道或者三通道的BGR的图像才可以通过这种方式保存         
- 保存PNG格式的时候可以保存透明通道的图片         
- 可以指定压缩参数         

[源代码--图像的显示与保存](../assets/Source/OpenCV/01-open-image.cpp)           

