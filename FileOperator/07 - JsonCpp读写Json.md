# 使用JsonCpp解析Json文件
## JsonCpp读写文件的注意事项
```
1. 写数据时对象使用\[ key \]，数组使用\[ index \]或append(value)
2. jsonValue["glossary"]["GlossDiv"] = jsonValueMidst1 一定是先把 jsonValueMidst1 里的数据写完了再写这句话
3. Reader解析出来的Json默认会按照 key值 进行排序
4. asString转换完成后 Value 类型所包含的引号会被消除
```

## JsonCpp环境的搭建
### 1.Windows下搭建JsonCPP环境
- 方式一(**推荐**)：将.h和.cpp文件包含进工程
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
```c
20230305补充    by::zfy
生成库文件按照步骤一步一步进行，我使用VS2022，程序会报错。将 jsoncpp.dll 文件移动到 .exe 所在目录问题解决。
基于该情况，我建议使用 方式一 以引入JsonCpp。
```

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

## 一个Json读写的实例。
```C++
void JsonZhCNWriteTest() {
	using namespace Json;
	using namespace std;
	Value jsonValue;
	jsonValue = objectValue;
	jsonValue["glossary"] = objectValue;
	jsonValue["glossary"]["title"] = "example glossary";

	Value jsonValueMidst1;
	jsonValueMidst1 = objectValue;
	jsonValueMidst1["title"] = "S";
	jsonValueMidst1["GlossList"] = objectValue;

	Value jsonValueMidst2;
	jsonValueMidst2 = objectValue;
	jsonValueMidst2["ID"] = "SGML";
	jsonValueMidst2["SortAs"] = "SGML";
	jsonValueMidst2["GlossTerm"] = "Standard Generalized Markup Language";
	jsonValueMidst2["Acronym"] = "SGML";
	jsonValueMidst2["Abbrev"] = "ISO 8879:1986";
	jsonValueMidst2["GlossDef"] = objectValue;
	jsonValueMidst2["GlossDef"]["para"] = "A meta-markup language, used to create markup languages such as DocBook";
	jsonValueMidst2["GlossDef"]["GlossSeeAlso"] = arrayValue;
	//jsonValueMidst2["GlossDef"]["GlossSeeAlso"].append("GML");
	jsonValueMidst2["GlossDef"]["GlossSeeAlso"][0] = "GML";
	jsonValueMidst2["GlossDef"]["GlossSeeAlso"].append("XML");
	jsonValueMidst2["GlossSee"] = "markup";

	jsonValueMidst1["GlossList"]["GlossEntry"] = jsonValueMidst2;
	jsonValue["glossary"]["GlossDiv"] = jsonValueMidst1;

#if	1
	string jsonStr = jsonValue.toStyledString();
#else
	FastWriter write;
	string jsonStr = write.write(jsonValue);
#endif
	ofstream ofs("MyJsonTest.json");
	ofs << jsonStr;
	ofs.close();
}
```

```C++
void JsonZhCNReadTest() {
	using namespace std;
	using namespace Json;
	Value JsonValue;
	Reader reader;
	ifstream ifs("MyJsonTest.json");
	//if (reader.parse(ifs, JsonValue)) {
	//	Value jsonValueMidst1 = JsonValue["glossary"]["GlossDiv"]["GlossEntry"];
	//	Value jsonValueMidst2 = jsonValueMidst1["GlossDef"];
	//	Value::Members name = JsonValue.getMemberNames();
	//	cout << "\"" << name[0] << "\": {" << endl;
	//	cout << "\t\"" << JsonValue[name[0]].getMemberNames()[1] 
	//		 << "\": " 
	//		 << JsonValue[name[0]][JsonValue[name[0]].getMemberNames().at(1)]
	//		 << ",";
	//}
	//打印输出会发现执行结果是OK的。但要是这样写程序估计是有点大病。所以我们默认Json格式已知。
	if (reader.parse(ifs, JsonValue)) {
		Value jsonValueMidst1 = JsonValue["glossary"]["GlossDiv"]["GlossList"]["GlossEntry"];
		Value jsonValueMidst2 = jsonValueMidst1["GlossDef"];
		cout << "\"" << JsonValue.getMemberNames()[0] << "\": {" << endl;
		cout << "\t\"" << JsonValue["glossary"].getMemberNames()[1] << "\": "
			 << JsonValue["glossary"]["title"] << "," << endl;
		cout << "\t\"" << JsonValue["glossary"].getMemberNames()[0] << "\": {" << endl;
		cout << "\t\t\"" << JsonValue["glossary"]["GlossDiv"].getMemberNames()[1] << "\": "
			 << JsonValue["glossary"]["GlossDiv"]["title"].asString() << "," << endl;
		//你会发现加上 asString 之后打印反而没了双引号。
		cout << "\t\t\"" << JsonValue["glossary"]["GlossDiv"].getMemberNames()[0] << "\": {" << endl;
		cout << "\t\t\t\"" << JsonValue["glossary"]["GlossDiv"]["GlossList"].getMemberNames()[0] << "\": {" << endl;
		cout << "\t\t\t\t\"" << jsonValueMidst1.getMemberNames()[5] << "\" :"
			 << jsonValueMidst1["ID"] << "," << endl;
		cout << "\t\t\t\t\"" << jsonValueMidst1.getMemberNames()[6] << "\" :"
			 << jsonValueMidst1["SortAs"] << "," << endl;
		cout << "\t\t\t\t\"" << jsonValueMidst1.getMemberNames()[4] << "\" :"
			 << jsonValueMidst1["GlossTerm"] << "," << endl;
		cout << "\t\t\t\t\"" << jsonValueMidst1.getMemberNames()[1] << "\" :"
			 << jsonValueMidst1["Acronym"] << "," << endl;
		cout << "\t\t\t\t\"" << jsonValueMidst1.getMemberNames()[0] << "\" :"
			 << jsonValueMidst1["Abbrev"] << "," << endl;
		cout << "\t\t\t\t\"" << jsonValueMidst1.getMemberNames()[2] << "\" :{" << endl;

		cout << "\t\t\t\t\t\"" << jsonValueMidst2.getMemberNames()[1] << "\" :"
			 << jsonValueMidst2["para"] << "," << endl;
		cout << "\t\t\t\t\t\"" << jsonValueMidst2.getMemberNames()[0] << "\" :[" << endl
			 << "\t\t\t\t\t\t" << jsonValueMidst2["GlossSeeAlso"][0] << "," << endl
			 << "\t\t\t\t\t\t" << jsonValueMidst2["GlossSeeAlso"][1] << endl
			 << "\t\t\t\t\t]" << endl
			 << "\t\t\t\t}," << endl;

		cout << "\t\t\t\t\"" << jsonValueMidst1.getMemberNames()[3] << "\" :"
			 << jsonValueMidst1["GlossSee"] << endl;
		cout << "\t\t\t}" << endl
			 << "\t\t}" << endl
			 << "\t}" << endl
			 << "}" << endl;
	}
}
```


## JsonCpp读写注意事项
- 写数据时对象使用\[ key \]，数组使用\[ index \]或append(value)
- `jsonValue["glossary"]["GlossDiv"] = jsonValueMidst1 一定是先把 jsonValueMidst1 里的数据写完了再写这句话`
- Reader解析出来的Json默认会按照 key值 进行排序
- asString转换完成后 Value 类型所包含的引号会被消除