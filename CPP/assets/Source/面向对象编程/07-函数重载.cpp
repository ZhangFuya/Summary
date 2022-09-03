#include <iostream>
using namespace std;

class CLASS_A {
private:
    int CLASS_A_var1;

public:
    CLASS_A();
    CLASS_A(int var);
    CLASS_A(CLASS_A &cls);
    void display();
    void display(int i);
    CLASS_A operator+(CLASS_A cls);
    CLASS_A operator-(CLASS_A cls);
    CLASS_A operator++();
    CLASS_A operator++(int);
};

//函数重载举例
//构造函数也可以发生函数重载
CLASS_A::CLASS_A() { CLASS_A_var1 = 0; }

CLASS_A::CLASS_A(int var) { CLASS_A_var1 = var; }

//重载与参数列表中的参数类型有关，与形参名无关
CLASS_A::CLASS_A(CLASS_A &var) { this->CLASS_A_var1 = var.CLASS_A_var1; }

void CLASS_A::display() { cout << "CLASS_A_var1:>" << CLASS_A_var1 << endl; }

void CLASS_A::display(int i) {
    for (int fori = 0; fori < i; fori++) {
        cout << "CLASS_A_var1:>" << CLASS_A_var1 << endl;
    }
}

//双目运算符的重载需要加参数，而单目运算符(++)重载加参数表示后置++，不加参数表示前置++
CLASS_A CLASS_A::operator+(CLASS_A cls) {
    CLASS_A cla;
    cla.CLASS_A_var1 += cls.CLASS_A_var1;
    return cla;
}

//在使用重载运算符时一定要仔细
CLASS_A CLASS_A::operator-(CLASS_A cls) {
    this->CLASS_A_var1 -= cls.CLASS_A_var1;
    return *this;
}

//单目运算符中，带参数表示后置++
CLASS_A CLASS_A::operator++() {
    CLASS_A cla;
    cla.CLASS_A_var1 = this->CLASS_A_var1++;
    cout << "无参运算符" << endl;
    return cla;
}

CLASS_A CLASS_A::operator++(int) {
    CLASS_A cla;
    cla.CLASS_A_var1 = ++this->CLASS_A_var1;
    cout << "有参运算符" << endl;
    return cla;
}



int main(int argc, char const *argv[]) {
    //重载函数的应用
    CLASS_A cls1;
    CLASS_A cls2(10);
    cls1.display();
    cls2.display(1);

    //重载运算符的应用
    CLASS_A cls3;
    cls3 = cls1 + cls2;
    cls3.display();
    cls3++;
    cls3.display();
    ++cls3;
    cls3.display();

    return 0;
}
