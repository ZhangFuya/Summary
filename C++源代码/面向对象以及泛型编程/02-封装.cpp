#include <iostream>
#include <string>
using namespace std;

// 定义 classA 及其成员
class CLASS_A {
private:
    string CLASS_A_var1;
    string CLASS_A_var2;
};



//定义 classB 及其成员
class CLASS_B {
private:
    string CLASS_B_var1;
    string CLASS_B_var2;

public:
    //静态变量，必须在类外初始化
    static string CLASS_B_static_var;
    static void CLASS_B_static_fun();
    friend void CLASS_B_friend_fun(CLASS_B cls);
    friend class CLASS_A;
    void show_classA_var();
};

//  -------------  静态成员  ---------------
//类外初始化 classB中的 静态成员属性
string CLASS_B::CLASS_B_static_var = "初始化";

void CLASS_B::CLASS_B_static_fun(){
    //静态成员不能通过 this 访问类内成员，报错
    //this->CLASS_B_var1 = 100;
    //静态方法只能调用 静态属性 或 静态方法，否则报错
    //CLASS_B_var1 = "Common Variable unvaild";
    cout << "CLASS_B_static_var的值为:> " << CLASS_B_static_var << endl;
}

//  -------------  友元  ---------------
//友元函数在定义时不必指明作用域(::)
//友元函数必须指定参数
void CLASS_B_friend_fun(CLASS_B cls){
    cout << "CLASS_B_var1的值" << cls.CLASS_B_var1;
    cout << "\tCLASS_B_var2的值" << cls.CLASS_B_var2 << endl;
}

//友元类可以直接访问另一个类的所有成员
void CLASS_B::show_classA_var(){
    cout << "在classB输出CLASS_B_var1" << CLASS_B_var1 << endl;
    cout << "在classB输出CLASS_B_var2" << CLASS_B_var2 << endl;
}


int main(int argc, char const *argv[])
{
    //静态成员可以通过 对象名.静态成员 或 类名::静态成员 的方式访问
    CLASS_B cls_B1;
    CLASS_B cls_B2;
    cls_B1.CLASS_B_static_var = "第一次赋值";
    cls_B1.CLASS_B_static_fun();
    CLASS_B::CLASS_B_static_var = "第二次赋值";
    CLASS_B::CLASS_B_static_fun();
    //同一个类构建的所有对象，共用静态成员
    cls_B2.CLASS_B_static_var = "静态成员共用";
    CLASS_B::CLASS_B_static_fun();

    //因为友元函数不是本类中的成员，也就没有了this指针，所以必须为其指定参数
    CLASS_B_friend_fun(cls_B1);
    //通过友元类可以访问另一个类中的成员
    cls_B1.show_classA_var();
    cls_B2.show_classA_var();


    return 0;
}
