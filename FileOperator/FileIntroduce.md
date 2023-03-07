# 文件基础
## 使用文件的原因
**数据的持久化、网络传输**。比如保存数据、配置文件等等。

## 什么是文件
万物皆文件。
但是在程序设计中，我们一般谈的文件有两种：**程序文件和数据文件**。
- 程序文件
一切与源代码，目标代码，可执行程序相关的文件。
- 数据文件
程序运行时进行读写的文件。

## 文件名
一个文件需要有一个唯一的文件标识，以便用户识别和引用。
Windows系统中文件名包含三部分：文件路径 + 文件名主干 + 文件后缀
通常，我们也将 文件名主干 称之为文件名。

## 文件指针
每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息(如文件名、文件状态及文件位置等)。这些信息保存在一个结构体变量中。该结构体类型由系统声明，取名为FILE。
- 文件信息区和文件是强绑定的，只要文件发生变化，文件信息区一定是随着发生变化的(这是文件系统实现的基础)。
- 打开文件时，系统就会根据文件的情况自动创建一个 FILE结构的变量，并填充数据。开发人员无需为文件信息区进行任何操作。
- 文件信息区是一个结构体(FILE)类型的。
- 不同的编译器 FILE 类型的细节可能不完全相同，但无关紧要。作为开发人员不可深究三方库的实现。
```C
//VS2013中的FILE类型
struct _iobuf {
    char    *_ptr;
    int     _cnt;
    char    *_base;
    int     _flag;
    int     _file;
    int     _charbuf;
    int     _bufsiz;
    char    *_tmpfname;
};
typedef struct _iobuf FILE;
```
**打开文件时，其实就是创建一个文件信息区，并与文件关联起来。**
**一般通过一个 FILE指针 来维护FILE结构的变量。**
`FILE* fp; //文件指针变量`
pf 是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息区。通过该文件信息区中的信息能够访问该文件。也就是说，**通过文件指针变量能够找到与它关联的文件**。

# 文件的操作
文件在读写之前应该先打开文件，在使用结束之后应该关闭文件。
**文件是一种资源，一个程序能打开的文件是有限的。建议不使用文件时进行文件的关闭。**
C语言打开、关闭、操作 文件的方法列举：
```c
FILE* fopen(const char* filename, const cahr* mode);
- fopen::文件打开失败或打开错误的时候，会返回 NULL
- fopen::r打开没有则报错，a、w打开没有则创建。
- fopen::w打开文件会将文件中所有的内容清空以写入

int fclose(FILE* stream);
- fclose::关闭文件时记得将文件指针置空
```

```c
//文件的顺序读写    
- 字符串输入函数    fgetc       所有输入流
Write a character to a stream or to stdout
int fputc(int c, FILE* stream);

- 字符串输出函数    fputc       所有输出流
Read a character from a stream or stdin
注意：如果读取失败或者读到文件结尾 fgetc 会返回 EOF(-1，End OF File)
int fgetc(FILE* stream);

- 文本行输入函数    fgets       所有输入流
char* fgets(char* string, int n, FILE* stream);
fgets 从流中读取数据并放到string中，参数n表示一次最多读取多少个元素。
注意三点： 1. 如果一行中元素个数小于 n，那么n无效
          2. n表示最多读多少个元素，但是真正读取的元素个数是 n - 1,最后一个空间是\0
          3. 一行未读完，fgets不会到下一行去读
//文件内容为 abcdefg\nhijklmn
fgets(arr, 4, pf);
printf("%s\n", arr);
fgets(arr, 4, pf);
printf("%s\n", arr);
打印输出：
abc
def
n是最大读取位数，但实际读的字符数为 n-1， 一行未读完 fgets 不会到下一行去读。

- 文本行输出函数    fputs       所有输出流
Write a string to a stream.
int fputs(const char* string, FILE* stream);

- 格式化输入函数    fscanf      所有输入流
- 格式化输出函数    fprintf     所有输出流 
- 二进制输入        fread         文件  
- 二进制输出        fwrite        文件
```


# 流的辨析
流是一个高度抽象的概念。用于程序和硬件之间数据的读写。
作为程序开发人员，无需关心流的实现。只需要知道将要写的内容转为一个流的形式，数据就可以成功写进文件中。
所以读写文件的核心就是，如何得到一个流数据。
C语言程序只要运行起来，默认打开了三个流(类型都是FILE*)：stdin、stdout、stderr
- stdin     标准输入流 - 键盘
- stdout    标准输出流 - 屏幕
- stderr    标准出错流 - 屏幕