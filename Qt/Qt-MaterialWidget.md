## MaterialWidgets 介绍
MaterialWidgets 是GitHub上的一套开源库，用于美化部分Qt组件。            

## MaterialWidgets 安装及使用
- git下载到本地           
- 打开Qt Creator，使用MinGW环境下Release编译(运行)          
如果是运行的话，程序启动后会对MaterialWidgets所支持的组件进行展示            
- 编译生成的文件夹中，components\release 下有一个 libcomponents.a(或者是.lib文件) 文件，将其复制到项目中去            
- 找到GitHub上下载的源代码目录(qt-material-widgets)，将components文件夹复制到项目中去              
- 在项目中的 pro 文件中添加如下配置信息         
```c++
我将 .a 文件和 components 放到了项目根目录下的SDK文件夹中
- 项目目录
    - SDK
        - static (存放 libcomponents.a 等库文件)
        - components (拷贝的components文件夹)
.pro文件添加如下内容：        
#SDK
LIBS += $$PWD/SDK/static/libcomponents.a #最后写的是文件名，如果是msvc编译的应该是 .lib 结尾
INCLUDEPATH += $$PWD/SDK/components
PRE_TARGETDEPS += $$PWD/SDK/static/libcomponents.a
```

- 引入头文件，并创建组件(和常见的QLabel、QPushButton一致)           
```c++
#include <qtmaterialtoggle.h>
QtMaterialToggle * m_toggle = new QtMaterialToggle(this);
m_toggle->setGeometry(0, 0, 200, 50);
```

## 注意事项
使用release编译的库文件，要正确使用则项目也必须使用release进行编译         