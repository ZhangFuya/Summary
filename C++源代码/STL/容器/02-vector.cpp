#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> stl_vector_1;  //此时只是创建了一个 vector 对象，并未分配任何内存
    stl_vector_1.reserve(20);  //为 stl_vector_1 分配至少可以存储20个元素的内存
    stl_vector_1.resize(20);   //注意区分reverse与resize。reverse是分配空间但不分配值
                               // resize是重新定义当前元素个数，原有容器元素个数不足时默认赋 0值

    int var = 97;
    vector<char> stl_vector_2(20);  //创建至少可以存储 20个元素，初始值为 0值 的stl_vector_2
    vector<char> stl_vector_2_1(20, var);  //第一个参数表示个数,第二个参数表示相同个数的值

    vector<int> stl_vector_3{1, 2, 3};  // vector的大小和元素的值取决于{}中的元素
    vector<int> stl_vector_3_1 = {1, 2, 3};

    vector<char> stl_vector_4(stl_vector_2);       //拷贝构造
    vector<char> stl_vector_4_1 = stl_vector_2_1;  //拷贝构造

    //使用指针构造一个vector
    vector<char> stl_vector_5(stl_vector_4.begin(), stl_vector_4.begin() + 4);
    int arr[] = {1, 2, 3, 4, 5, 6};
    vector<int> stl_vector_5_1(arr, arr + 4);  // 1,2,3,4
    vector<char> stl_vector_5_2(stl_vector_4.at(1), stl_vector_4.at(4));

    //增删改查
    for (auto i = 1; i < 5; i++) {
        stl_vector_1.at(i) = i;
    }

    stl_vector_1.push_back(11);  // push_back尾部添加一个元素

    stl_vector_1.insert(stl_vector_1.begin() + 3, 13);  // insert指定位置添加一个元素
    stl_vector_1.insert(stl_vector_1.begin() + 9, stl_vector_3.begin(), stl_vector_3.end());
    stl_vector_1.insert(stl_vector_1.begin(), 3, 100);

    stl_vector_1.emplace_back(14);  //尾部生成一个新元素
    stl_vector_1.emplace(stl_vector_1.begin() + 3, 15);  //指定位置生成一个新元素

    //使用迭代器遍历
    cout << "stl_vector_1的遍历1:>";
    for (auto i = stl_vector_1.begin(); i < stl_vector_1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    //范围for遍历
    cout << "stl_vector_1的遍历2:>";
    //必须注意一点:for (auto &i : stl_vector_1) 可以对i值进行修改
    for (auto i : stl_vector_1) {
        cout << i << " ";
    }
    cout << endl;

    //不建议的遍历方式
    cout << "stl_vector_1的遍历3:>";
    for (int i = 0; i < stl_vector_1.size(); i++) {
        cout << stl_vector_1.at(i) << " ";
    }
    cout << endl;

    stl_vector_1.pop_back();
    stl_vector_1.pop_back();

    stl_vector_1.erase(stl_vector_1.begin() + 3);

    cout << "stl_vector_1的遍历 :>";
    for (auto i = stl_vector_1.begin(); i != stl_vector_1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    cout << "stl_vector_3的遍历 :>";
    for (auto i = stl_vector_3.begin(); i != stl_vector_3.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    stl_vector_3.clear();
    cout << "clear后stl_vector_3的遍历:>";
    for (auto i = stl_vector_3.begin(); i != stl_vector_3.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    if(stl_vector_3.empty()){
        cout << "clear之后 stl_vector_3 为空" << endl;
    }

    stl_vector_1.assign(2, 100);
    cout << "assign之后 stl_vector_1 的遍历:>";
    for (auto i = stl_vector_1.begin(); i != stl_vector_1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    stl_vector_1.assign(2, 100);
    cout << "assign之后 stl_vector_1 的遍历:>";
    for (auto i = stl_vector_1.begin(); i != stl_vector_1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    stl_vector_1.assign(arr, arr + 4);
    cout << "assign之后 stl_vector_1 的遍历:>";
    for (auto i = stl_vector_1.begin(); i != stl_vector_1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    stl_vector_1.swap(stl_vector_5_1);
    cout << "swap之后 stl_vector_1 的遍历:>";
    for (auto i = stl_vector_1.begin(); i != stl_vector_1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    cout << "stl_vector_1的第一个元素是:>" << stl_vector_1.at(0) << endl;
    cout << "stl_vector_1的第一个元素是:>" << stl_vector_1[0] << endl;
    cout << "stl_vector_1的第一个元素是:>" << *stl_vector_1.data() << endl;
    cout << "stl_vector_1的第一个元素是:>" << stl_vector_1.front() << endl;

    cout << "stl_vector_1的最后一个元素是:>" << stl_vector_1.back() << endl;

    //empty 为空判断
    //insert既可以加一个元素又可以加多个元素
    //shrink_to_fit 分配当前元素实际大小的空间
    //data 与 front 函数的区别，front 与 back 函数返回的返回值是数据的引用，而data函数返回的是指向第一个元素的指针。
    //reserve与resize的区别：reserve分配空间但不赋予 0值，也就是说此时vector容器为空。resize改变元素个数，若元素个数不足时会赋 0值。


    return 0;
}
