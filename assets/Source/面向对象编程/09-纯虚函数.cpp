#include <iostream>
using namespace std;


class CLASS_A {
public:
    //纯虚函数的定义，注意声明为纯虚函数后不用给出函数的实现
    //只要还有一个纯虚函数，那这个类就是个抽象类，这里CLASS_A就是个抽象类
    virtual void display() = 0;
    virtual void display1() = 0;
};

class CLASS_B : public CLASS_A {
public:
    //子类对纯虚函数要么继续声明为纯虚函数
    virtual void display() = 0;
    //要么就实现纯虚函数
    virtual void display1(){
        cout << "要么再次声明为纯虚函数，要么实现纯虚函数" << endl;
    }
};


int main(int argc, char const *argv[]) { return 0; }
