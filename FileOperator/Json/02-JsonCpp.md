# 使用JsonCpp解析Json文件
## JsonCpp环境的搭建
### 1.Windows下搭建JsonCPP环境
- 方式一：将.h和.cpp文件包含进工程
    - 确保电脑中有Python环境
    - 在.git文件夹所在的位置打开cmd窗口，输入`python amalgamate.py`
    - 将 dist 文件夹中的 json 文件夹，和 json.cpp 移动到工程中，并将json.h和json.cpp加入到项目中来。
    **此方法引入头文件最好使用"json/json.h"**

- 方式二：生成库文件
    - JsonCpp的构建工具是CMake，确保电脑中已安装CMake。
    - Github上Clone JsonCpp库。
    - 打开CMake Gui。Source处指到JsonCpp(.git所在的目录)。build指到构建目录(CMake的build目录)。
    - CMake Gui点击Config配置，根据自己的需求指定项目环境(一般根据自己的VS版本默认即可)，点击Finish。
    - CMake Gui点击Generate。
    - CMake Gui点击Open Project(构建目录找到.sln文件，双击打开。)。
    - 找到项目JsonCpp_lib，右键生成(注意是Debug版本还是Release版本)。根据编译信息找到构建出来的.dll和.lib文件位置。
    - 建议：将生成的.dll和.lib文件以及JsonCpp中include下的json文件夹放到单独的文件夹中。
    - 配置VS环境。VC++和链接器选项。注意VC++中include指定到json所在的文件夹即可，无需指定到json文件夹。

## JsonCpp的使用
json/json.h头文件中包含了json文件夹下的所有的头文件，使用JsonCpp时引入json.h即可。
JsonCpp中提供了三个类：
Value：对Json支持的数据类型进行封装/解析，得到/解析出Value类型。
Reader：将Json格式字符串转为Value对象
FastWriter：将Value对象中的数据格式化(转为字符串)，以便进行网络传输。
这三个类Reader类中记住一个函数`parse(解析)`，FastWriter类中记住一个函数`write`即可。

```c++
//Json格式化字符串->value对象
bool parse(const std::string &document, Value &root, bool collectComments = true);
- document: json字符串传入参数
- root：传出参数，转换完成之后的Value对象
- collectComments：是否收集注释

bool parse(const char* beginDoc, const char* endDoc, Value &root, bool collectComments = true)
- beginDoc：字符串起始地址
- endDoc：字符串结束地址
- root：传出参数，转换完成之后的Value对象

bool parse(std::istream &is, Value &root, bool collectComments = true)
- is：文件流对象，使用这个流对象打开一个磁盘文件
- root：传出参数，转换完成之后的Value对象

//FastWrite是Write类的一个子类。由于Write类是一个抽象类，不能被实例化因此写json文件要使用FastWrite
//FastWrite格式化的字符串是没有格式的(字符串中没有换行，所有的数据都放到一行中)。
std::string Json::FastWriter::write(const Value &root);


//Value负责将Json数据转为Value类型的数据
bool isXXX() const; 是什么类型吗
Type: Null, Bool, Int, Int64, UInt, UInt64, Integral, Double, Numeric(数字), String, Array, Object

Type asType() const; 转换为对应的类型

//对数组的操作
size数组元素个数、[]、get带有默认值的得到元素、append、迭代器;

//对Json对象的操作
[key]、get方法、getMemberNames得到所有的key值，返回值是一个vector;

//序列化,写配置文件的时候使用，将Value对象转为带有换行符的形式
std::string toStyledString() const;
```