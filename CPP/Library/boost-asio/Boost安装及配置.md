### Boost的下载以及安装
- 我是按照网站 [CSDN-Alivev888-boost](https://blog.csdn.net/Aliven888/article/details/111153535) 中的内容进行安装的
- 教程中VS版本较老，我用的是vs2022和他的就不大一样(文章最后附加了我在VS中的配置图)。


### Ubuntu下Boost的安装
1. 解压boost.tar.gz
2. 进入到解压缩的文件夹
3. 执行可执行文件 bootstrap.sh
    `sudo ./bootstrap.sh`
4. 待 3 执行完成后会生成 b2 可执行文件
    `sudo ./b2 install`
- 注意：b2 文件的执行最好是使用 sudo 进行


## VScode配置Boost
1. 正常安装boost
2. 将 (解压缩目录/)stage/lib 下的所有库文件全部复制到 MinGW[/x86_64-w64-mingw32]/lib中-> 
   将 (解压缩目录/)boost 下的所有文件复制到 MinGW[/x86_64-w64-mingw32]/include中
- 这里注意一点：
    如果你的MinGW包含 x86_64-w64-mingw32 文件夹
    那么两个文件夹就是复制到 x86_64-w64-mingw32 下的iclude和lib文件夹中，
    如果没有就是MinGW下的include和lib文件夹中
- 如图：
    ![boost文件夹及库文件复制](../../assets/images/Boost/Boost-MinGW.png)
3. 编辑配置文件 c_cpp_properties.json
    Ctrl + Shift + P 输入 C/C++后，选择编辑配置json
    然后在 "includePath" 后加上 boost 根目录所在的路径。
- 如图:
    ![vscode为boost编辑json文件](../../assets/images/Boost/Boost-Vscode-jsonfile.png)

### VS配置Boost
VS使用MSVC进行编译，因此在MinGW中的配置对于VS不生效
建议：一个VS一套配置，能不修改原库文件就不修改
对VS项目配置建议使用项目属性(项目名上右键->属性)进行配置
- 如图:
    ![VS配置boost](../../assets/images/Boost/Boost-Vs.png)
