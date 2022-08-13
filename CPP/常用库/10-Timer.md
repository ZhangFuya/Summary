## C++中的ctime         

### 三种类型，两类函数       
- 常规C++中常见的三种时间类型分别为：time_t 和 tm 结构体，以及clock_t。         
其中 clock_t 最为精确，表示时钟滴答数。time_t和tm结构体最常用。time_t 表示与unix时间戳的差值，tm结构体封装了年月日时分秒的实现。         
- 两类函数指的是：获取时间的函数 以及 时间类型与其他类型的转换函数。         
获取时间的函数有：clock(获取时钟滴答数)、time(获取time_t的时间类型)、difftime(获取参数1(end)与参数2(begin)之间的差值)         
- 转换函数通常是将 time_t与tm结构体之间的转换，time和string类型之间的转换并且ctime提供了时间格式的修改。当然对于时间还涉及到国际时间与本地时间之间的转换。         

#### 转换函数         
1. time_t与tm结构体之间的转换函数         
- gmtime 将一个time_t的指针类型转为tm指针类型         
- localtime 将一个time_t的指针类型转为tm指针类型         
- mktime 将tm结构体转为time_t类型         
gmtime 与 localtime：两者都是将 time_t的指针类型 转为tm的指针类型。不同点在于，gmtime转换后是相较于时间戳的国际时间.要换算成北京时间，年数要加上 1900，月份加 1，小时数加 8。嵌入式设备在设计层面可能不支持localtime因此嵌入式设备推荐使用gmtime。         

2. time与string类型之间的转换         
- ctime 将time_t类型转为string类型         
- asctime 将tm结构体转为string类型         

3. 指定时间的格式         
- strftime 转为指定格式的string类型         
四个参数，第一个参数表示输出字符串，第二个参数表示转换的最大长度，第三个参数表示转换格式，第四个参数表示要转换的tm类型的指针。         

[源代码--C++中的Timer](../../assets/Source/Timer/01-ctime.cpp)       

## Boost中的time         

## Qt中的time——QDate与QTime         
Qt中的时间主要分为两大系列：Date系列与Time系列。QDate主要是负责年月日这种日期的处理，而QTime负责的主要就是时分秒这类时间的处理。         

### QDate之QCalendar         
- 日历对象，通过使用特定的规则，将年月日映射到一个特定的日期。可通过 availableCalendars()方法 获取其支持的日历系统。         
- 日历对象可以校验数据是否有效，某一年是否为闰年，某一天是该年(月、周)的第几天，以及月名、周几等信息。         

### QDate         
- QDate的构造函数只有两个无参或指定年月日进行构造         
- 通常QDate对象的创建使用QDate类中的静态方法 QDate::currentDate()(获取系统当前时间)。         
- QDate作为日期处理函数非常强劲。既可以通过 QCalendar 来进行构建，还可以通过 string 来进行转换。         
- QDate具有QCalendar相类似的功能外，还拓展了日期的加减(加一个负值即为减)和比较(\>、\<、\>= 、\<=、==、!=)         

### QTime         
QTimer对象包含一个时钟对象。可以表示自午夜以来的小时数，分钟数，秒数以及毫秒数。         
QTimer的使用也与QDate极为相似。         