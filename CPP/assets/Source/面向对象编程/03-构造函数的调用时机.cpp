#include <iostream>

using namespace std;
class CLASS_A;
class CLASS_B;

class CLASS_A {
   private:
    int CLASS_A_var1;
    int CLASS_A_var2;

   public:
    CLASS_A();
    CLASS_A(CLASS_A &cls);
    ~CLASS_A();
};

CLASS_A::CLASS_A() { cout << "CLASS_A的  构造函数  被调用了" << endl; }
CLASS_A::CLASS_A(CLASS_A &cls) { cout << "CLASS_A的  拷贝构造  被调用了" << endl; }
CLASS_A::~CLASS_A() { cout << "CLASS_A的  析构函数  被调用了" << endl; }


class CLASS_B {
   private:
    int CLASS_B_var1;
    int CLASS_B_var2;

   public:
    CLASS_B();
    CLASS_B(CLASS_B &cls);
    ~CLASS_B();
    void class_a_as_para(CLASS_A cls);
    void class_a_as_para2(CLASS_A &cls);
    CLASS_A ret_class_a();
};

CLASS_B::CLASS_B() { cout << "CLASS_B的  构造函数  被调用了" << endl; }
CLASS_B::CLASS_B(CLASS_B &cls) { cout << "CLASS_B的  拷贝构造  被调用了" << endl; }
CLASS_B::~CLASS_B() { cout << "CLASS_B的  析构函数  被调用了" << endl; }
void CLASS_B::class_a_as_para(CLASS_A cls){};
void CLASS_B::class_a_as_para2(CLASS_A &cls){};
CLASS_A CLASS_B::ret_class_a(){
    cout << "-------------------------------\n";
    cout << "这里类类型作为返回值内部调用的构造函数" << endl;
    CLASS_A cls;
    cout << "类类型作为返回值，函数结束函数内创建的类会销毁" << endl;
    //返回一个类类型
    return cls;
}

int main(int argc, char const *argv[]) {
    //创建对象时构造函数被调用
    CLASS_A cls_a_1;
    CLASS_B cls_b_1;
    cout << endl;

    //当一个类类型作为参数时
    CLASS_A cls_a_2(cls_a_1);
    //当一个类类型作为成员函数的参数时候会调用拷贝构造，并在函数执行完成后销毁
    cls_b_1.class_a_as_para(cls_a_1);
    //引用传递未创建对象也就不会调用构造函数
    cls_b_1.class_a_as_para2(cls_a_1);
    cout << endl;

    //当作为返回值类型时
    //如果输出结果不正确，极有可能是编译器做了优化，建议使用vs，并关闭优化
    cls_a_1 = cls_b_1.ret_class_a();
    cout << endl;

    cout << "\n\n\n\n";
    return 0;
}
