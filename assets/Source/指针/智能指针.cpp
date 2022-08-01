#include <iostream>
#include <tr1/memory>
using namespace std;

void func(int * p){
    cout << "智能指针的删除器函数" << endl;
    delete p;
}

int main(int argc, char const *argv[])
{
    shared_ptr<int> p1 = make_shared<int>(10);
    shared_ptr<int> p2 (make_shared<int>(10));
    shared_ptr<int> p3(new int(10), func);
    shared_ptr<int> p4 = p1;


    cout << p1 << endl;
    cout << p1.get() << endl;
    cout << "指向p1的指针个数:>" << p1.use_count() << endl;
    cout << "p2是独占指针吗:>" << p2.unique() << endl;
    p1.reset();
    cout << "p1为空吗:>" << (p1 == nullptr) << endl;
    cout << "p4是否是独占指针:>" << p4.unique() << endl;

    // unique_ptr是独占指针，其删除器必须加上删除器类型,
    // unique_ptr 可以作为右值给 shared_ptr 赋值
    typedef void (*pf)(int *);
    unique_ptr<int, pf> p5(new int(10), func);

    shared_ptr<int> p6 = move(p5);
    shared_ptr<int> p7 = make_unique<int>(10);

    return 0;
}
