#ifndef __PEOPLE_HPP
#define __PEOPLE_HPP
#include <string>
using namespace std;
#endif /*__PEOPLE_HPP*/

//类的定义
class People {
//成员属性
private:
    string name;
    int age;
    int height;   //cm
    double weight;

//成员方法
//成员方法中看不到参数，并不代表没有参数。指向本类的 this 指针作为第一个参数是隐藏的
public:
    //构造函数
    People();

    //析构函数
    ~People();

    void sleep();
};

//构造函数，参数this
People::People() {}

//析构函数，参数this
People::~People() {}
