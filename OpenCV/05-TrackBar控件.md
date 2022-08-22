TrackBar滑块组件             
对于OpenCV来说，创建TrackBar只需要使用 createTrackBar( ) 就可以进行TrackBar的创建。         
getTrackBarPos 获得TrackBar当前的值。            

createTrackBar 参数剖析：            
- TrackBarName 滑块名            
- WinName 滑块所在窗口名            
- value 滑块初始值             
- count 滑块最大值            
- callback 设置回调函数         
- userdata 传递给回调函数的参数      
必须要注意的一点： TrackBar  的回调函数，其参数必须是(int, void *)类型。否则报错。 

getTrackBarPos 参数剖析：           
-  trackbarname 滑块名             
-  winname 滑块所在窗口名          
返回值为当前TrackBar所在位置对应的值。          