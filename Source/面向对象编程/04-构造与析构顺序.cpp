#include <iostream>

using namespace std;

// class-a
class CLASS_A {
   private:
    int CLASS_A_var1;
    int CLASS_A_var2;

   public:
    CLASS_A();
    ~CLASS_A();
};

CLASS_A::CLASS_A() { cout << "CLASS_A -- 构造函数" << endl; }
CLASS_A::~CLASS_A() { cout << "CLASS_A -- 析构函数" << endl; }

// class-b
class CLASS_B {
   private:
    int CLASS_B_var1;
    int CLASS_B_var2;

   public:
    CLASS_B();
    ~CLASS_B();
};
CLASS_B::CLASS_B() { cout << "CLASS_B -- 构造函数" << endl; }
CLASS_B::~CLASS_B() { cout << "CLASS_B -- 析构函数" << endl; }

// class-c : classA
class CLASS_C : public CLASS_A {
   private:
    int CLASS_C_var1;
    int CLASS_C_var2;

   public:
    CLASS_C();
    ~CLASS_C();
};

CLASS_C::CLASS_C() { cout << "CLASS_C -- 构造函数" << endl; }
CLASS_C::~CLASS_C() { cout << "CLASS_C -- 析构函数" << endl; }

// class-d : classA, classB
class CLASS_D : public CLASS_A, public CLASS_B {
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
    //当创建多个对象时，先创建的后销毁
    CLASS_A cls_a_1;
    CLASS_B cls_b_1;
    cout << endl;

    //子类与父类，构造与析构顺序
    //父类先构造后析构
    CLASS_C cls_c_1;
    cout << endl;

    //多继承中的构造与析构
    CLASS_D cls_d_1;
    cout << endl;

    cout << "\n\n\n";
    return 0;
}
