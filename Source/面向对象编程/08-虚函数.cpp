#include <iostream>
using namespace std;


class CLASS_A {
public:
     void display() { cout << "CLASS_A diaplay" << endl; }
};

class CLASS_B : public CLASS_A {
public:
    //多态，同名函数自动为虚函数
   virtual void display() { cout << "CLASS_B diaplay" << endl; }
};


class CLASS_C : public CLASS_B {
public:
    void display() { cout << "CLASS_C diaplay" << endl; }

};


int main(int argc, char const *argv[]) { 
    
    CLASS_A cla;
    CLASS_B clb;
    CLASS_C clc;

    CLASS_A * p = &cla;
    p->display();

    //子类地址可以赋值给基类指针(类型兼容)
    p = &clb;
    //使用虚函数，子类重写父类方法后，基类指针访问到的就是子类的方法。
    //这里没有使用虚函数，因此基类类型的变量只能访问基类中的方法。
    p->display();

    CLASS_B * q = &clc;
    //使用虚函数后，基类可以访问子类中的方法
    q->display();
    
    
    return 0; }
