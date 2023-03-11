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
fscanf 对比与 scanf，都有格式化输入的意思(只不过scanf针对的是stdin)
int scanf(const char* format [,argument]...);
int fscanf(FILE* stream, const char* format [,argument]...);

- 格式化输出函数    fprintf     所有输出流 
fprintf 对比与 printf，都有格式化输出的意思(只不过printf只针对于stdout罢了)
int printf(const char* format [, argument]...);
int fprintf(FILE* stream, const char* format [, argument]...);

- 二进制输入        fread         文件
size_t fread(void* buffer, size_t size, size_t count, FILE* stream);
从流(stream)中读取 count 个 size 大小的元素到 buffer 中。

- 二进制输出        fwrite        文件
Writes data to a stream.
size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
buffer: 指针，指向要被写入的数据地址
size: 要写的数据元素多大，单位：字节
count: 多少个大小为size的元素

fread 和 fwrite 是一组函数，用于二进制的形式进行文件的读写。
返回值 size_t 表示实际 读/写 的 count 数。未读到或读到文件末尾则返回 0。
```

```c
文件读取结束的判定
fgetc   EOF
fgets   NULL
fread   判断返回值是否小于实际要读的个数
注意：在文件读取过程中，不能用 feof 函数的返回值直接判断文件是否结束
因为 feof 用于：当文件读取结束时，判断是读取失败结束还是读到文件尾结束。
int feof(FILE *stream)；
读到文件尾，返回非零值。否则返回0.
```


```c
一组函数对比
scanf       针对 stdin 的格式化输入语句
fscanf      针对 所有输入流 的格式化输入语句
sscanf      从字符串获取格式化数据

printf      针对 stdout 的格式化输出语句
fprintf     针对 所有输出流 的格式化输出语句
sprintf     将格式化数据转为字符串

- sscanf 从字符串中获取有格式的数据
Read formatted data from a string
int sscanf(const char* buffer, const char* format[, argument]...);
- sprintf 将有格式的数据转换成一个字符串
Write formatted data to a string
int sprintf(char* buffer, const char* format[, argument]...);
```

```c
//文件的随机读写 fseek ftell
- fseek 根据文件指针的位置和偏移量来定位文件指针
int fseek(FILE* stream, long offset, int origin);
offset:偏移量，值可以为正也可以为负值
origin:起始位置。取值有三：SEEK_CUR(当前指针位置)、SEEK_END(文件末尾)、SEEK_SET(文件开始)

- ftell 返回文件指针相对于起始位置的偏移量
long int ftell(FILE* stream);

- rewind 让文件指针的位置回到文件的起始位置
void rewind(FILE* stream);
```

# 关于二进制读写和文本读写的区别
计算机底层存储的都是二进制码，这一点毫无争议。
不同点在于比如一个数字 1，他如果按照 ASCII码 的形式存储那么该文件就是文本文件，如果将这个数字按其字节码来存那么该文件就是 二进制文件。

根据数据的组织形式，数据文件被称为 文本文件 或 二进制文件。
数据在内存中以 二进制的形式存储，如果不加转化的输出带外存，就是二进制文件。
如果要求在外存上以 ASCII码 的形式存储，则需要在存储前转换。以 ASCII码 字符的形式存储的文件就是 文本文件。

# 文件缓冲区
ANSIC 标准采用“缓冲文件系统”处理数据文件。所谓缓冲文件系统是指**系统自动地在内存中为程序中每一个正在使用的文件开辟一块“文件缓冲区”**。从内存向磁盘输出数据会先发送到内存中的缓冲区，装满缓冲区后才一起送到磁盘上。
如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区(充满缓冲区)，然后再从缓冲区逐个地将数据送到程序数据区(程序变量等)。
缓冲区的大小由编译器决定。
**使用fflush可以将缓冲区的数据立即进行读写**，以刷新缓冲区。
**fclose隐藏的就有刷新缓冲区操作**

## 缓冲系统的作用
**避免操作系统频繁读写文件的开销**