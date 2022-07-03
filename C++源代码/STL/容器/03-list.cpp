#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[]) {
    // list容器的创建与初始化
    list<int> stl_list_1;
    stl_list_1.resize(10);

    int var = 97;
    list<char> stl_list_2(20);
    list<char> stl_list_2_1(20, var);  // num, value

    list<int> stl_list_3{1, 2, 3};
    list<int> stl_list_3_1 = {1, 2, 3, 4, 5, 6};

    list<char> stl_list_4(stl_list_2);
    list<char> stl_list_4_1 = stl_list_2;

    int array[] = {1, 2, 3, 4, 5, 6};
    list<int> stl_list_5(array, array + 3);
    list<char> stl_list_5_1(stl_list_2_1.begin(), stl_list_2_1.end());

    //增删改查
    stl_list_1.push_back(1);
    stl_list_1.push_back(2);
    stl_list_1.push_back(3);
    stl_list_1.push_front(4);
    stl_list_1.push_front(5);
    stl_list_1.push_front(6);
    stl_list_1.emplace_back(7);
    stl_list_1.emplace_back(8);
    stl_list_1.emplace_front(9);
    stl_list_1.emplace_front(10);

    //因为list没有 at函数，也没有重载[]，
    //所以对list遍历只能使用 迭代器 或 范围for 语句
    cout << "stl_list_1的遍历1:>";
    for (auto i : stl_list_1) {
        cout << i << " ";
    }
    cout << endl;

    //insert 可以加入一段元素，而 emplace 只能加入一个元素
    //emplace的效率要比inser高一些
    stl_list_1.emplace(stl_list_1.end(), 0);
    stl_list_1.insert(stl_list_1.begin(), 0);
    stl_list_1.insert(stl_list_1.begin(), 2, 1);
    stl_list_1.insert(stl_list_1.end(), array, array + 4);

    cout << "stl_list_1的遍历2:>";
    for (auto i = stl_list_1.begin(); i != stl_list_1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    //splice 可以将 一个list中的元素移动到另一个list中,并且可以指定要合并list的起止或终止地址
    //merge可以合并两个有序的list，并且合并之后仍是有序的
    //注意 splice 函数是移动list中的元素到原list，被移动的元素就要更换所属的list
    stl_list_1.splice(stl_list_1.begin(), stl_list_3); 
    //移动之后stl_list_3里的元素就都属于stl_list_1了，此时stl_list_3为空
    stl_list_1.splice(stl_list_1.begin(), stl_list_3, stl_list_3.begin(), stl_list_3.end());
    cout << "stl_list_1的遍历3:>";
    for (auto i : stl_list_1) {
        cout << i << " ";
    }
    cout << endl;
    if(stl_list_3.empty()){
        cout << "splice移动后原来的元素归属发生变化，此时stl_list_3为空" << endl;
    }

    stl_list_1.sort();
    stl_list_3_1.sort();
    stl_list_1.merge(stl_list_3_1);
    cout << "stl_list_1的遍历4:>";
    for (auto i : stl_list_1) {
        cout << i << " ";
    }
    cout << endl;

    //remove(i)用于删除list中所有等于i的元素
    stl_list_1.remove(0);
    //unique，如果相邻的两个元素相同，删除一个
    stl_list_1.unique();
    //remove_if() 删除指定元素
    //remove_if的使用可以参照
    //https://blog.csdn.net/louObaichu/article/details/49300675

    stl_list_1.pop_back();
    stl_list_1.pop_back();
    stl_list_1.pop_front();
    stl_list_1.pop_front();

    //erase既可以删除一个元素，也可以删除一段元素
    stl_list_1.erase(stl_list_1.begin());

    cout << "stl_list_1的遍历5:>";
    for (auto i : stl_list_1) {
        cout << i << " ";
    }
    cout << endl;
    
    //反转、排序、清空、修改 list
    stl_list_1.reverse();
    cout << "反转后stl_list_1的遍历:>";
    for (auto i : stl_list_1) {
        cout << i << " ";
    }
    cout << endl;

    stl_list_1.sort();
    cout << "排序后stl_list_1的遍历:>";
    for (auto i : stl_list_1) {
        cout << i << " ";
    }
    cout << endl;

    stl_list_1.clear();
    stl_list_1.assign(2,50);
    cout << "assign后stl_list_1的遍历:>";
    for (auto i : stl_list_1) {
        cout << i << " ";
    }
    cout << endl;

    //empty 为空判断
    //swap交换两个list中所以的元素
    //splice是将元素从另一个list移动到本list中

    return 0;
}
