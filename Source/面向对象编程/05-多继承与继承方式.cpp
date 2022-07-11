#include <iostream>

using namespace std;

// class-a
class CLASS_A {
public:
    int CLASS_A_var1;
private:
    int CLASS_A_var2;
protected:
    int CLASS_A_var3;

   public:
    CLASS_A();
    ~CLASS_A();
};
CLASS_A::CLASS_A() { cout << "CLASS_A -- 构造函数" << endl; }
CLASS_A::~CLASS_A() { cout << "CLASS_A -- 析构函数" << endl; }

// class-b
class CLASS_B {
public:
    int CLASS_B_var1;
private:
    int CLASS_B_var2;
protected:
    int CLASS_B_var3;

   public:
    CLASS_B();
    ~CLASS_B();
};
CLASS_B::CLASS_B() { cout << "CLASS_B -- 构造函数" << endl; }
CLASS_B::~CLASS_B() { cout << "CLASS_B -- 析构函数" << endl; }

// class-c
class CLASS_C {
public:
    int CLASS_C_var1;
private:
    int CLASS_C_var2;
protected:
    int CLASS_C_var3;

   public:
    CLASS_C();
    ~CLASS_C();
};
CLASS_C::CLASS_C() { cout << "CLASS_C -- 构造函数" << endl; }
CLASS_C::~CLASS_C() { cout << "CLASS_C -- 析构函数" << endl; }

// class-d : public classA, private classB, protected classC
class CLASS_D : public CLASS_A, private CLASS_B, protected CLASS_C {
public:
    int CLASS_D_var1;
private:
    int CLASS_D_var2;
protected:
    int CLASS_D_var3;

   public:
    CLASS_D();
    ~CLASS_D();
};
CLASS_D::CLASS_D() { cout << "CLASS_D -- 构造函数" << endl; }
CLASS_D::~CLASS_D() { cout << "CLASS_D -- 析构函数" << endl; }

int main(int argc, char const *argv[]) {

    //1.只有公有继承的公有属性才可以在访问到
    CLASS_D cls;
    cls.CLASS_D_var1 = 10;  //类的公有属性可以被访问到
    //cls.CLASS_B_var1 = 10; //私有继承无权访问
    //cls.CLASS_C_var1 = 10; //保护继承无法访问
    cls.CLASS_A_var1 = 10;  //只有公有继承的公有成员才能被访问到


    // 2.



    return 0;
}
