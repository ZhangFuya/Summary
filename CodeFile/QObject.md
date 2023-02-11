# 1. QObject介绍
1. QObject 是所有Qt对象的基类。换句话说所有的Qt类都是直接或间接继承自 QObject
1. QObject 属于 Qt 的核心类，被包含在 QtCore 模块中
1. 作为Qt对象模型的核心，QObject 为对象通信提供了信号与槽的机制。注意：**Q_OBJECT** 宏对于实现任何信号与槽机制都是**必须且强制**的，此外如果使用了信号与槽机制还需要通过 moc编译器(Meta Object Compiler) 来编译源文件
1. Qt维护了一个对象树（这一块现阶段还不熟悉）
1. QObject 可以接收和过滤事件
1. QObject 提供了计时器的支持
1. QObject 具有线程关联性
1. 每个对象都有一个 obectName(可以通过 QMetaObject::className() 获取)
1. 当一个对象被删除，它会发出一个 destroyed 信号
1. 所有的 Widget部件 继承自 QObject，并且可以通过 isWidgetType 来判断是否是一个Qt部件。
1. QObject 没有复制拷贝和赋值操作符
1. 元对象系统提供了自动连接 QOBject 子类及其子类之间信号与槽的机制
1. 所有的 QObject 子类都支持翻译特性。但必须调用 tr 函数。
1. 动态属性(不熟悉)

# 2. QObject的主要功能
## 2.1 信号