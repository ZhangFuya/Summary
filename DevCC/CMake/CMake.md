### 什么是CMake
CMake，一个高级编译配置工具。

CMake是一个跨平台的安装编辑工具，可以使用简单的语句来完描述所有平台的编译过程。

**make需要makefile，而CMake需要的是CMakeLists.txt文件**

注意：cmake是为了生成MakeFile文件，CMake生成MakeFile之后仍需要执行 make 命令进行编译  

</br>

### CMake语法介绍
#### 语法格式
- 基本语法格式： 指令(参数1  参数2...)
  - 参数要使用小括号括起来
  - 参数之间使用空格或分号分隔。建议使用空格
- 指令是大小写无关的，参数和变量是大小写相关的。
- 使用 ${} 的方式获取变量的值，但是在IF控制语句中是直接使用变量名

#### CMakde的一些重要指令
- cmake_minimum_required ***指定CMake的最小版本要求***   
   - 语法：cmake_minimum_required(VERSION versionNumber [FATAL_ERROR])
    ```cmake {.line-numbers }
    #CMake最小版本要求为2.8.3
    cmake_minimum_required(VERSION  2.8.3)
    ```

- project  ***定义工程名称***，并可指定工程支持的语言
   - 语法： project(projectname  [codelanguage])
    不推荐指定编程语言
    ```cmake{.line-numbers }
    #指定工程名称为HELLOWORLD
    project(HELLOWORLD)
    ```
- set   显式的定义变量
    - 语法：set(VAR [Value])
    ```cmake{.line-numbers }
    #定义SRC变量， 其值为main.cpp  hello.cpp
    set(SRC main.cpp hello,cpp)
    ```
- include_directories   向工程添加多个特定的头文件搜索路径(相当于g++中的 -i 参数)
    - 语法： include_directories([AFTER | BEFORE][SYSTEM] dir1 dir2...)
    ```cmake{.line-numbers }
    #将/usr/include/myincludefolder 和 ./include 添加到头文件搜索路径
    include_directories(/usr/include/myincludefolder  ./include)
    ```


- link_directories   向工程添加多个特定的库文件搜索路径(相当于g++中的 -L 参数)
    - 语法：：link_directories(dir1 dir2)
    ```cmake{.line-numbers }
    #将/usr/lib/mylibfolder 和 ./lib 添加到库文件搜索路径
    link_directories(/usr/lib/mylibfolder   ./lib) 
    ```

- add_library   ***生成库文件***
    - 语法：add_library(libname[SHARED | STATIC | MODULE][EXCLUDE_FROM_ALL] source1 source2 ... sourceN)
    ```cmake{.line-numbers }
    #通过变量 SRC 生成 hello.so 共享库
    add_library(hello SHARED ${SRC})
    ```

- add_compile_options   添加编译参数
    - 语法： add_compile_options(<option>...)
    ```cmake{.line-numbers }
    #添加编译参数 -wall  -std=c++11
    add_compile_options(-wall -std=c++11)
    ```

- add_executable   ***生成可执行文件***
    - 语法：add_executable(exe_name source1 source2 ...)
    ```cmake{.line-numbers }
    #编译main.cpp生成可执行文件
    add_executable(main main.cpp)
    ```

  
- target_link_libraries   为target ***添加需要链接的共享库*** (相当于g++中的 ***-l*** 参数)
    - 语法：target_link_libraies(target library1<debug|optimized> library2...)
    ```cmake{.line-numbers }
    #将hello动态库文件链接到可执行文件main
    target_link_libraies(main hello)
    ```

- add_subdirectory   向当前工程添加存放源文件的子目录，并可以指定中间二进制文件和目标二进制文件存放的位置
    - 语法：add_subdirectory(source_dir [binary_dir][EXCLUDE_FROM_ALL])
    ```cmake{.line-numbers }
    #添加src子目录，src中需要有一个CMakeLists.txt
    add_subdirectory(src)
    ```

-  aux_soruce_directory   发现一个目录下所有的源代码文件并将列表存储在一个变量中
      -  语法：aux_source_directory(. src)
    ```cmake{.line-numbers }
    #定义SRC变量，其值为当前目录下所有的源代码文件
    aux_source_directory(.  SRC)
    #编译SRC变量所代表的源代码文件，生成main可执行文件
    add_executable(main ${SRC})  
    ```
</br>

### CMake编译工程
CMake目录结构,项目目录存在一个CMakeLists.txt文件
两种方式设置编译规则:
1. 包含源文件的子文件夹包含CMakeLists.txt文件.主目录的CMakeLists.txt通过add_subdirectory添加子目录即可
2. 包含源文件的子文件夹未包含CMakeLists.txt文件,子目录编译规则体现在主目录的CMakeLists.txt中

#### 编译流程
1. 手动编写CMakeLists.txt
2. 执行命令 cmake PATH (PATH是顶层CmakeLists.txt所在的目录)生成MakeFile
3. 执行make命令进行编译

#### 构建方式
1. 内部构建
- 在当前目录下,编译本目录的CMakeLists.txt,生成MakeFile和其他文件
- 不推荐内部构建,因为内部构建会在同级目录下产生一大堆中间文件,这些文件不是我们所需要的,和工程源文件放在一起会显得杂乱

2. 外部构建
- 在当前目录下创建build,将产生的中间文件统一放到build文件夹中
- 推荐使用外部构建,因为外部构建将编译输出的文件与源文件放到不同目录下.
注意一点,外部构建指的是: **在根目录下创建CMakeLists.txt文件,但是要在build文件夹中执行cmake命令**
</br>

### CMake应用举例
1. 简单应用
   CMakeLists.txt的编写
```cmake{.line-numbers }
    #先在跟根目录下创建CMakeLists.txt文件
    #指定cmake最小版本
    cmake_minimum_required(VERSION 2.8)

    #指定项目名称
    project(Hello)

    #指定编译后的文件名,以及要编译的 源文件
    add_executable(a.out hello.c)
```
推荐使用外部构建的方式进行cmake的构建.这样就需要手动创建build文件,并在build文件下使用 `cmake ..` 命令
注意:这里一定是`cmake ..`,因为,CMakeLists.txt和build是同级目录

2. 多目录下的应用
```cmake{ .line-numbers }
    #指定cmake最小版本
    cmake_minimum_required(VERSION 2.8)

    #指定项目名称
    project(Hello)

    #将头文件所在的文件夹添加到搜索路径
    include_directories(head)

    #指定编译后的文件名,以及要编译的 源文件
    add_executable(a.out hello.c src/add.c)
```