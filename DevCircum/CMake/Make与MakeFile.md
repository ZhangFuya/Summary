### 什么是make？？

make就是一个编译工具(编译工具就是辅助编译的工具，其底层仍是调用gcc或者g++编译器)

 为什么要有make，因为C语言等语言是解释性的语言。即从源代码到可执行文件之间要经过

源代码 -->  编译 -->  链接 --> 可执行程序 的过程，虽然gcc可以直接完成编译工作，但是当

项目中文件过多时，只使用gcc就会浪费我们大量的时间。因此有了make工具来帮助我们

自动完成编译工作。

关于make有两点注意事项：

1. make会检查哪些文件发生了更改，进而之编译被修改的文件，**避免不必要的重复编译**。

2. make通过一个称为makefile的文件来完成编译工作。

makefile说明了如何编译各个源文件并连接生成可执行的文件，并定义了源文件之间的依赖关系。

当修改了其中某个源文件时，如果其他的源文件依赖于该文件，则也要重新编译所有依赖于该文件的源文件。

3. makefile有其固定的格式

总之一句话：<font color= LightCoral>**make是自动完成编译工作的工具。**</font>





### makefile的格式：

**第一行**，顶格，写最终要生成的  **文件名** (文件名也可以是要执行的动作) 然后 加上  **冒号**  以及  依赖的文件( 目标文件:依赖 )

**第二行**，写依赖的由来，并且第二行**一定要以 TAB 为开头**

make是从makefile开头的位置开始寻找的，并把找到的第一个目标作为最终的目标文件。

因此，第一个目标一定要是最后的可执行文件。

具体代码举例：

```makefile
#目标文件名:依赖
target.out:demo01.o demo02.o
	gcc demo01.o demo02.o -o target.out
demo01.o:demo01.c
	gcc -c demo01.c -o demo01.o
demo02.o:demo02.c
	gcc -c demo02.c -o demo02.c
	
#清除所有的.o文件(需要使用 make clean 命令)
#这里的clean是一个伪目标(不生成目标文件，但具有目标的性质)
#常见的伪目标有 clean  install   all(生成多个目标文件)
.PHONY:clean  #声明clean是一个伪目标
clean:
	rm -rf *.o
```


### 对makefile的优化方案
不难看出，上边的makefile只是对编译过程进行了封装，如果项目文件很多时，上边的代码仍不能起到有效的解决工程编译的问题。

下边我们对其进行优化：

#### 优化1：使用%和*减少重复输入文件的次数

```makefile
#目标文件名:依赖
target.out:demo01.o demo02.o  (依赖不能改)
	gcc  *.o  -o  target.out	  (可以将多个文件使用 * 来表示)
%.o:%.c					
	gcc  -c  $<  -o  $@
	
#清除所有的.o文件
clean:
	rm  -rf  *.o
```

这里详细说一下上边符号的含义：

$@：规则的目标文件名

$<：规则的第一个依赖文件名

$^：规则的所有依赖文件列表

除了这些变量，makefile中也可以定义变量。

```makefile
ELF=main
object=main.o  stu.o  teach.o  file.o
$(ELF):$(object)  #变量使用$()引用
	gcc $^ -o $@
$(object):		#这里使用的是make的自动推导功能。make可以根据 .o 推导出.c文件和gcc -c的指令，
				#因此可以对.c文件和gcc -c指令进行省略
.PHONY:clean
clean:
	rm -rf $(object)
```
现在你就可以对多个文件进行编译了。但这还远远不够。我们接着往下看。   

#### 优化2：使用函数进行多层目录下的编译 {优化2}

##### makefile中常见的函数:  {makefile中常见的函数}
- wildcard函数   
  wildcard函数用于 *在当前目录下匹配文件*   
  如 src=$(wildcard  *.c) 就是在当前目录下寻找  .c  文件   


- notdir函数
  notdir函数用于 *去除路径*
  如 $(notdir $src)   


- patsubst函数   
  patsubst函数用于 *模式匹配替换*
  如 $(patsubst %.c,%.o,$src) 是将src中所包含的所有 .c 文件替换为 .o 文件
  **patsubst函数一般可以简写如 $(src: .c=.o)**   


- shell函数   
  shell函数主要就是用于 *执行shell命令*
  如 $(shell ls -d */)
  想执行shell命令加上shell就对了。

举例如下：
```makefile
ELF=main.out
src=$(wildcard *.c)
src2o=$(src:.c=.o)
$(ELF):src2o
	gcc $^ -o $@
$(src2o):

.PHONT:clean
clean:
	rm -rf $(src2o)
```



##### 多级目录下的makefile编写

其实也很简单就是一条 find  -name  ''*.c'，只需要使用函数$(shell find   -name  ''*.c')

```makefile
ELF=main.out
CC=gcc	 #指定编译器
src=$(shell find -name  '*.c')
src2o=$(patsubst%.c,%.o,$src)	#这里也可以使用src2o=$(src:.c=.o)
$(ELF):$(src2o)
$(src2o):				#这里使用的是make的自动寻找功能

.PHONT:clean
clean:
	rm -rf $(src2o)
```