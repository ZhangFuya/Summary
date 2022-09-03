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

## 保存图像 cv::imwrite         
- 保存图像文件到指定目录路径         
- 只有8位、16位的PNG、JPG、Tiff文件格式而且是单通道或者三通道的BGR的图像才可以通过这种方式保存         
- 保存PNG格式的时候可以保存透明通道的图片         
- 可以指定压缩参数         

[源代码--图像的显示与保存](./assets/Source/01-open-image.cpp)           

## 色彩空间
图片离不开颜色的支撑。OpenCV中对于图片的管理使用色彩空间(一种颜色写法就是一个色彩空间)这一名词。                 
最常见的色彩空间就是RGB(人眼的色彩空间，通过红、绿、蓝三种颜色的光源混合成想要的颜色)。        
OpenCV默认使用的色彩空间是 BGR。此外OpenCV中常用的色彩空间还有 HSV/HSB(色相、饱和度、明亮度)、HSL 以及 YUV(主要用于视频)。
BGR与RGB的差别：排列顺序的不同。
HSV/HSB(本质一样，翻译导致的区别)。H(Hue)色相，如红绿蓝等等。S(Saturation)饱和度，百分比的值越大饱和度越高。
V(Value)明亮度。黑色的部分占多少，百分比的值越大黑色占比越少。    
**OpenCV倾向于HSV色彩空间。主要是因为可以对颜色的色相进行判断。**        
HSV与HSL的主要区别：当明亮度到达100%，HSL为纯白但HSV并不是纯白。所以OpenCV中HSL基本不用。     

YUV一般用在视频中，主要包含三种类型 YUV4:2:0  YUV4:2:2  YUV4:4:4。其中的比例是对像素的描述。      
其中YUV4:2:0是一个标准，其存储数据所需要的空间要比YUV4:4:4减少一半。         
YUV4:4:4，表示4个Y数据(灰色的图像)、UV表示颜色，且一个Y只能匹配一个U或者V。因此YUV4:4:4，要匹配所有的UV所需要的Y是8个。
UV表颜色，是一个整体，不必加以区分。如YUV4:2:0中两个Y匹配一个UV。匹配到的颜色既可以是U也可以是V。     

## 修改图像的颜色空间 cv::cvtColor         
cvtColor的功能是把图像从一个色彩空间转换到另一个色彩空间。有三个参数，第一个参数表示源图像，第二个参数表示色彩空间转换之后的图像，第三个参数表示源和目标色彩空间，如：COLOR_BGR2HLS、COLOR_BGR2GRAY等         
举例：cvtColor( image, gray_image, COLOR_BGR2HLS )  

注意：**使用 COLOR_GRAY2xxx 图片一定是一张三通道图片(否则会报错并中止)。**        

[源代码--色彩空间的使用](./assets/Source/04-colorspace.cpp)                     