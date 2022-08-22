"void (*)()" 类型的实参与 "cv::TrackbarCallback" 类型的形参不兼容             
解决方案：         
TrackbarCallback 回调函数必须为 void(int,void*)           