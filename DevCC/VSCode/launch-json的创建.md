vscode中的运行和调试是基于配置文件launch.json的. launch的创建过程大体可以分为两步:
创建launch.json文件并根据自己的开发环境改写两处参数

1. 创建launch.json文件   
<img src=../../assets/images/vscode/vscode-launch-create.png  height = 400px/>

中间会让你选择环境,选择c++,g++就好(如果是c选择gcc就好)
<img src=../../assets/images/vscode/vscode-launch-create6.png weidth = 30% height = 280px/>



2. 改写launch.json
   
<img src=../../assets/images/vscode/vscode-launch-create2.png width = 600px height = 400px/>

<img src=../../assets/images/vscode/vscode-launch-create3.png width = 600px height = 400px/>

<img src=../../assets/images/vscode/vscode-launch-create4.png width = 600px height = 400px/>

<img src=../../assets/images/vscode/vscode-launch-create5.png width = 600px height = 400px/>

改写launch.json需要注意:
1. 参数 "program" 指向编译出来的程序名字,且编译一定要使用 -g 选项进行编译
    - 程序只有在编译之后才能进行调试,所以 program 后边的参数一定是指向编译后的程序
    - ***-g选项是调试选项.若不加会直接出运行结果,无法进行断点调试***
2. 参数 "miDebuggerPath" 指向的是你系统中 gdb.exe,而且要注意路径一定是俩斜线

-----------------------
当你完成上边的操作就可以调试了. 但是这还不够,这些只是一些最简单的操作,我们还要接着往下看

### launch.json的重要参数
1. program  编译后的程序名称
2. miDebuggerPath  gdb的路径
3. preLaunchTask    用于和task.json中的label匹配,其值必须和task.json中label值完全相同
注意一点: preLaunchTask 书写的位置  
<img src=../../assets/images/vscode/vscode-launch-create7.png width = 950px height = 400px/>
4. launch.json中的args表示的是程序运行时的参数.如 ./a.out file
你就要把 file 放到 launch.json 的args参数中
5. task.json中的args就是编译指令


### task.json的使用
task.json的作用就是用于调试之前的编译工作
因此,可以对task.json进行改造(实则没什么用的技巧)一个cmake tools插件就解决了