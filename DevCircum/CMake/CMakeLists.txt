#指定cmake最小版本
cmake_minimum_required(VERSION 2.8)

#指定项目名称
project(Hello)

#将头文件所在的文件夹添加到搜索路径
include_directories(head)

#指定编译后的文件名,以及要编译的 源文件
#一定注意要把所有需要编译的源文件添加到这里
add_executable(a.out hello.c src/add.c)