QObject 类是 Qt 中绝大多数类的祖先。
父类的指针(引用)可以指向不同的子类对象


## MOC
### moc 是什么

Moc 全称 Mete-Object-.Compiler 也就是“元对象编译器”。
Moc的位置：bin/moc.exe

### moc的作用

程序编译时调用Moc对工程源码进行解析，生成类的 moc_xxxx.cpp 文件(位于moc文件夹中)     

### moc分析源文件的依据

**在gcc进行标准编译之前先调用moc分析C++源文件**，如果发现"Q_OBJECT"在源文件前加上moc生成 moc_xxx.cpp 将这个新文件加入编泽系统，最终被链接到二进制代码中（预处理-编译-汇编链接）   
moc_xxx.cpp文件实现了O_OBJECT中的函数及数据（实现了元对像的特有功能），在编译时必须被加载，否则链接过程失数（编译moc.exe会检查moc_xxxx.cpp文件，没有则生成)   
这里有几个注意点：
1. **moc编译器是先于gcc标准编译器进行调用的。**
2. **moc检查到moc_xxxx.cpp文件不存在时，会重新生成对应的moc文件。**
3. 使用moc之后类对象对应的文件就变成了三个：.h、.cpp 以及 moc文件。


## Q_OBJECT 宏
###  Q_OBJCT 宏的作用
- Q_OBJECT 宏是moc分析源文件是否生成相应的 moc 文件的依据
- Q_OBJECT 宏为使用或继承 Q_OBJECT 宏的类、对象提供了singnal和slot(信号与槽)的机制，凡是 QObject 类(不管是直接子类还是间接子类) 都应该添加
- 在类(头文件)中添加 "Q_OBJECT" ，相当于在头文件中添加了宏定义中的所有：(数据、宏、函数)这些对应在 moc_xxx.cpp 中具体实现、填充
-  "singal" 只需要声明，不需要定义 ---> 类中使用 "Q_OBJECT" 会生成对应 moc_xxx.cpp 文件，这个文件会自动实现 "singal"
- 继承QObject是为了调用 connect 信号槽，加载 Q_OBJECT 是为了提取存储子类对象信息，构建子类元对象，从而实现信号槽的通信(实现了singal和slot的调用操作) 类似于 Lib-public接口(给到QMetaObject::active，槽函数偏移量)在moc_xxx.cpp 中去调用
我们来看 Q_OBJECT 的详细内容
```cpp
/* qmake ignore Q_OBJECT */
#define Q_OBJECT \
public: \
    QT_WARNING_PUSH \
    Q_OBJECT_NO_OVERRIDE_WARNING \
    static const QMetaObject staticMetaObject; \
    virtual const QMetaObject *metaObject() const; \
    virtual void *qt_metacast(const char *); \
    virtual int qt_metacall(QMetaObject::Call, int, void **); \
    QT_TR_FUNCTIONS \
private: \
    Q_OBJECT_NO_ATTRIBUTES_WARNING \
    Q_DECL_HIDDEN_STATIC_METACALL static void qt_static_metacall(QObject *, QMetaObject::Call, int, void **); \
    QT_WARNING_POP \
    struct QPrivateSignal {}; \
    QT_ANNOTATE_CLASS(qt_qobject, "")

```


```c++
1. QT_WARNING_PUSH   告诉编译器不要报 4793 的警告
2. staticMetaObject  静态元对象存储的是类中所有的数据。
3. metaObject        staticMetaObject的引用
4. qt_metacast       将子类转为Qobject对象
5. qt_metacall       虚函数化槽函数，以及对类的属性进行读取
6. QT_TR_FUNCTIONS   国际化处理
7. qt_static_metacall 调用槽函数
8. 重点：Qt的moc编译器会自动生成信号的实现(在moc_xxx.cpp文件中)，因此不需要手动实现信号的定义
```