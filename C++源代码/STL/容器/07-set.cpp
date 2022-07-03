//关于set 、 multimap 、 multiset就不列举了，使用时只需要注意一下几点即可
//1. set要求键值对必须保持一致，所以在声明时只需要指定键的类型，值的类型也就确定了
    set<string> stl_set_1;

    set<string> stl_set_2 {"C", "Java"};

    set<string> stl_set_3 (stl_set_2);

    set<string> stl_set_4 (stl_set_2.begin(), stl_set_2.end());
// set中的方法与map中的方法基本一致

//2. multixxx 被定义在对应的类里，因此 multixxx 在引头文件时需要引入对应的类
// multixxx 的使用和对应的类基本一致