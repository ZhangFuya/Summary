stdio.h 主要针对控制台的输入、输出以及针对文件读写的一些函数
而微软和Linux虽然提供了针对于目录等接口，但使用繁琐且跨平台性不强
C++ iostream 由名字可以看到主要是针对于文件流进行的操作

由上不难看出：C++缺乏对操作系统中的文件进行进行查询和操作能额力
而，boost::filesystem 库提供了一个可移植的文件操作库，使用POSIX标准表示的文件系统路径，接口类似标准库的容器和迭代器，一跨平台操作目录，文件。


库 `Boost.Filesystem` 简化了处理文件和目录的工作。 它提供了一个名为 `boost::filesystem::path` 的类，可以对路径进行处理。 另外，还有多个函数用于创建目录或验证某个给定文件的有效性。

boost::filesystem 库中代表路径的类 —— path 类
（路径分隔符常量 posix  /   ;   windows  \\ ,并支持posix下的  /）
path();          //构建一个空路径

path(const  path& p);   //拷贝构造函数

template <class Source>
path(Source const& source, const codecvt_type& cvt=codecvt());  //从字符串构造一个路径，必要时进行内码转换

template <class InputIterator>
path(InputIterator begin, InputIterator end,const codecvt_type& cvt=codecvt());  //从一个字串构造路径

~path();  //析构函数

每个系统对字符串的编码是不同的，
windows通过在cmd中输入chcp查看到(936(GB2312)),linux下通过locale命令查看(UTF-8)
所以path提供了codecvt函数用以编码
因为UTF8在表示字符时不具有CPU相关性(同一字符CPU解析出来的结果相同)，所以UTF8是特别适合网络传输的。

### path的赋值操作
```cpp
path&  operator = (const path&  p);

template  <class Source>
path&  operator = (Source const& source);

template <class Source>
path&  assign(Source const& source,const codecvt_type&  cvt)

template <class InputIterator>
path&  assign(InputIterator begin, InputIterator end, const  codecvt_type& cvt=codecvt() );
```

### path的追加
```cpp
path&  operator /= (const path& p);

template <class Source>
path&  operator /= (Source const& source);

template <class Source>
path&  append(Source const& source, const codecvt_type& cvt);

template <class Inputlterator>
path&  append(InputIterator begin, InputIterator end, const codecvt_type& 
 cvt=codecvt() );
 
inline path operator / (const path& Ihs,const path& rhs){return path(Ihs) /= rhs;}
对于追加的分隔符，windows下是 \\,而posix下是 / ,在书写时一定要注意
```

### path的连接
```cpp
path&  operator += (const path& x);
path&  operator += (const string_type& x);
path&  operator += (const value_type* x);
path&  operator += (value_type x);

template <class Source>
path&  operator += (Source const& x);

template <class CharT>
path&  operator += (CharT  x);

template <class Source>
path&  concat(Source const& x , const codecvt_type& cvt);

template <class Inputlterator>
path&  concat(InputIterator begin, InputIterator end);

template <class Inputlterator>
path&  concat(InputIterator begin, InputIterator end, const codecvt_type& cvt);
```

### path的修改
```cpp
void clear();

path&  make_preferred();   
//make_preferred 函数很重要，该函数是进行路径转换的，window下会将 / 转为 \\
//ISO/IEC 9945:no effect.Windows:convert slashes to backslashes

path&  remove_filename();

path&  replace_extension(const path&  new_extension = path() );

void swap(path&  rhs);
```

### path的字符串表示
```cpp
const  string_type&  native()  const noexcept;   //native format, encoding

const  value_type*  c_str() const noexcept;   //native().c_str()

const string  string(const codecvt_type&  cvt=codecvt() )  const;

const wstring  wstring(const codecvt_type&  cvt=codecvt()) const;

const string   generic_string(const codecvt_type&  cvt=codecvt() )  const;

const wstring  generic_wstring(const codecvt_type&  cvt=codecvt())  const;
```

### path的比较操作
```
int  compare(const path&  p) const noexcept;

int  compare(const std::string&  s) const;

int  compare(const value_type*  s) const;
```


### 关于路径(path类)的知识点速览
- `boost::filesystem::path` 是 Boost.Filesystem 中的核心类，它表示路径的信息，并提供了处理路径的方法。
- 可以通过传入一个字符串 到 boost::filesystem::path 类来构建一个路径。如`boost::filesystem::path pth("c:\\");`
- boost::file::path 未提供路径的校验(路径只是字符)。因此，在path类构造时甚至可以提供无意义的路径
- path类只是处理字符，文件系统没有被访问
- 
