#include <iostream>
using namespace std;

// class-a
class CLASS_A {
   public:
    int CLASS_A_var1;
    int CLASS_A_var2;

   public:
    CLASS_A();
    ~CLASS_A();
    void dispaly();
};

CLASS_A::CLASS_A() { cout << "CLASS_A -- 构造函数" << endl; }
CLASS_A::~CLASS_A() { cout << "CLASS_A -- 析构函数" << endl; }
void CLASS_A::dispaly() { cout << "display" << endl; }

// class-b ; class-a
class CLASS_B : public CLASS_A {};

// class-c : class-a
class CLASS_C : public CLASS_A {};

// class-d : class-b, class-c
class CLASS_D : public CLASS_B, public CLASS_C {
private:
    int CLASS_D_var1;
    int CLASS_D_var2;

public:
    CLASS_D();
    ~CLASS_D();
};
CLASS_D::CLASS_D() { cout << "CLASS_D -- 构造函数" << endl; }
CLASS_D::~CLASS_D() { cout << "CLASS_D -- 析构函数" << endl; }


int main(int argc, char const *argv[]) {
    //对于一个对象，继承来的两个属性即使是同名的，不使用也没有影响
    //一旦使用了同名的成员名，就会出现二义性的情况
    //解决二义性的办法：1.使用虚函数解决成员方法问题   2.使用 类名::成员名进行显示访问

    CLASS_D cls;
    //cls.CLASS_A_var1 = 10;  
    //cout << cls.CLASS_A_var1 << endl;    //这是二义性最坑的地方，编译器无法检测出来，但是一旦编译运行就会报错

    //cls.CLASS_A::dispaly();
    //cout << cls.CLASS_A::CLASS_A_var1 << endl;

    return 0;
}
