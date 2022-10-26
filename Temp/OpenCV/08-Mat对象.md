## Mat是什么
Mat就是一个矩阵。这个矩阵可能含有多个通道，如果只有一个通道的话它就是灰色的。       
全真色的图片是三通道(b、g、r)的。       

## Mat的组成
每一个Mat都有两大组成部分：Header 和 Data
对于Header来说存放的是一些Mat中的属性，包括
```c++
int  dims;   //维数
int  rows, cols;    //行列数
depth;     //像素的位深
channels；  //通道数RGB是3
size；  //矩阵大小
type；  //dep + dt + chs CV_8UC3
uchar* data;    //存放数据的指针
int* refcount;  //引用计数
```
对于 refcount ，图像所占用的内存空间是很大的。每次操作都要拷贝图像就会造成时间和空间的大量开销。         
因此Mat使用一个引用计数，对于浅拷贝的对象均指向一块内存空间，即避免了内存浪费又避免了内存泄漏。         


## Mat的深拷贝与浅拷贝
深拷贝与浅拷贝的区别点就在于：是否对Mat对象的Data部分进行拷贝。        
浅拷贝只将Mat对象的Header部分进行拷贝。     
使用 Mat 对象的 copyTo 以及 clone 方法进行的是深拷贝，其余的都是浅拷贝。            

## 访问 Mat的多种属性(图像的属性)
```c++
Mat::shape  //高度、长度 和 通道数
Mat::size   //图像的大小(高度 * 长度 * 通道数)
Mat::dtype  //图像的位深
```

## Mat中的图像属性
- shape
获取图像的高、宽、通道数
- size
获取图像大小(高 * 宽 * 通道数)
- dtype
- 图像中每个元素的位深


### 通道的分离与合并
- split(mat) 
- merge(ch1,ch2)