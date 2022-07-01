## String
关于String的介绍不再赘述，无非就是一个字符数组嘛。主要还是看它具体有哪些方法吧。

### C++中String的常用方法
C++中将字符数组封装为 **String类** .String类中较为常用的方法有：
#### 重载运算符
- + \[ = \]
- > \[ = \]
- < \[ = \]
- = 
- ==  
- !=
- <<
- >> 
- \[ \]


#### 迭代器与位置函数
- begin    --    指向开始的迭代器
- end       --     指向结束的迭代器
- [c / r / cr]begin    --    c表常量(const)，r表示从后向前(reverse)
- [c / r / cr]end
- \[  \]    --    数组元素那样访问字符串元素
- at     --     指向某一个元素
- front    --    指向第一个元素
- back    --    指向最后一个元素



#### 容量与大小
- empty
- size
- max_size

- resize    --    指定字符串长度。原字符串，多余删除，不足使用第二个参数(默认值为0)补足
- capacity    --    重新分配内存
- reserve     --    自适应分配容量


#### 增删改查
- append    --    末尾追加
- push_back    --  末尾追加一个字符
- insert      --    指定位置添加

- pop_back    --    删除最后一个字符
- earse    --    删除指定位置的字符
- clear     --    清空字符串

- replace  --    替换指定位置的字符串
- assign    --    为字符串赋予一个新值。assing的形参形式与string对象的赋值相同。
- copy      --     复制字符串
- substr    --     截断字符串

###### 查找与比较
- find        --    指定序列第一次出现的位置。没找到返回 string::npos
- compare  --  可指定比较位置的比较函数
- find_first_of  --    参数中任意字符第一次出现的位置，未找到返回 string::npos
- find_first_not_of  --    第一次不匹配任意形参的位置
- find_last_of   --    从后往前找


#### 转换
- string::c_str    转为C类型的字符串(const char \*)
c_str方法常与strcpy函数连用,如：`strcmp(cstr, c_str(cxxstr))`




### Boost中String的常用方法
尽管C++中的string类，功能已经非常丰富了，但还不够完善。为此Boost封装了更多的操作。



### Qt中QString的常用方法
相比较而言，我觉着Qt中对string的封装是比较好的。
#### 重载运算符
- + \[ = \]
- > \[ = \]
- < \[ = \]
- = 
- ==  
- !=
- <<
- >> 
- \[ \]

#### 迭代器与位置函数
- begin    --    指向开始的迭代器
- end       --     指向结束的迭代器
- [c / r / cr]begin    --    c表常量(const)，r表示从后向前(reverse)
- [c / r / cr]end
- \[  \]    --    数组元素那样访问字符串元素
- at     --     指向某一个元素
- front    --    指向第一个元素
- back    --    指向最后一个元素
- data    --     使用 QChar * 来遍历整个字符串，以达到修改某个元素的效果

#### 拼接字符串
- QString::asprintf    --    采用C语言格式字符串拼接
- arg    --    使用arg的参数填补占位符

#### 子串
- **spilt**    --    **拆分字符串，并返回一个 QStringList 的子串序列**,拆分依据是spilt中的参数
- mid      --    返回指定位置，指定长度的字符串
- left      --     返回从开始到参数位置的字符串
- right    --     从后向前数指定个数的字符串
- index     --     是否包含某个子串，或正则表达式。未包含返回 -1
- contains     --    是否包含某个子串
- compare    --     比较两个字符串是否相同
- startsWith  --    是否以某一子串开始
- endsWith    --     是否以某一子串结束
- trimmed      --     删除两端的空白字符

#### 增删改查
- append    --    末尾追加
- insert       --    指定位置添加
- prepend   --    将参数中的字符串添加到原字符串前

- remove    --     移除指定位置的元素

- replace    --    用参数中的字符串替换原字符串中指定位置的元素

#### 类型转换
##### 基本类型-字符串
- QString::number    --    将任意数字(整型，浮点型)转为字符串
- setNum    --    将任意数字转为字符串
- toDouble、toShort、toInt、toUInt、toLong、toULong等
- toLatin1    --    转为拉丁字符，不支持中文，返回值为 QBetyArray 类型
- toUtf8      --    逐个返回 QString 中的字符，支持中文。返回值类型为 QByteArray 类型
- c_str         --    转为 const char \* 的类型
```c++
对类型转换进行补充说明
1. QByteArray 、 const char * 等类型想要转为 QString 类型，直接调用 QString 类型的 
   构造函数，QString(const char *)、QString(const QByteArray)
2. 当使用 c_str 进行类型转化的时候，想要去掉 const 修饰，可以使用
   const_cast<type_id>(expression)
3. 字符串，转为16进制的ASCII字符串，可以先将字符串转为 QByteArray 类型，然后调用 
   toHex 方法。如果是纯数字还可以使用 QString::Number 进行转换。
6. 将16进制字符串转为QString类型的字符串，可以使用 QByteArray::fromHex 方法。
```

```c++
QString、char * 以及 QByteArray 之间的转换
QString    -> QByteArray    使用 toUtf8()
QSTring    -> char *        使用 QChar * QString::data()
QByteArray -> QString       使用QString(QByteArray)构造函数
char *     -> QString       使用QString(char *)构造函数
```

##### 字符串-日期
- QDateTime::fromString    --    字符串转日期/时间
- QDateTime::toString        --    日期/时间转为字符串
```c++
字符串与日期转换的补充说明
1. 日期转换中一个非常重要的参数就是：format - 日期/时间格式(如，yyyy-MM-dd HH:mm:ss )。
2. 日期转字符串，需要明转换格式 QDateTime::toString(const QString &format)
3. 字符串转日期/时间，formString 有着format的默认值，可以不写format
   QDateTime QDateTime::fromString(const QString & string, Qt::DateFormat 
   format = Qt::TextDate)
```

#### 大小写转换
- toUpper、toLower、isUpper、isLower

### 参考资料
1. C++中的String [C++——std::String_zy2317878的博客-CSDN博客_std::string](https://blog.csdn.net/zy2317878/article/details/79056289)
2. QString中的类型转换[Qt的QString数据类型转换(整理)_焕小谢的博客-CSDN博客_qt 数字转换为qstring](https://blog.csdn.net/qq_38832450/article/details/103162756)