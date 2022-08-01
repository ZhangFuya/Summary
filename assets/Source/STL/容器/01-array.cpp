#include <iostream>
#include <array>
using namespace std;

int main(int argc, char const *argv[])
{
    array<int, 10> stl_arr_1;  //array不会进行默认的初始化，此时str_arr_1里面的值是不确定的
    array<int, 10> stl_arr_2 {}; //该语句会对str_arr_2中的元素进行 0值 初始化
    array<int, 10> stl_arr_3 = {1,2}; //不完全初始化
    array<int, 10> stl_arr_4(stl_arr_3); //拷贝构造
    array<int, 10> stl_arr_5 = stl_arr_3; //值拷贝
    //array不能使用迭代器进行构造，下边的语句报错
    //array<int, 10> str_arr_6(stl_arr_1.begin(), stl_arr_1.end() - 1);


    //增删改查.array无删除、无查询，添加，修改靠遍历
    for(int i = 0; i < stl_arr_1.end() - stl_arr_1.begin(); i++){
        //cout << i <<endl;   //校验i值
        stl_arr_1[i] = i;
        stl_arr_1.at(i) += 1;   //at函数要比直接使用下标访问更加安全,因为它会检查越界
        stl_arr_2.at(i) += i;
    }

    for(auto &i : stl_arr_2){
        i *= 2;
    }

    for (int i = 0; i < stl_arr_1.max_size(); i++)
    {
        cout << stl_arr_1.at(i) << " ";
    }
    cout << endl;

    for(auto i = stl_arr_2.begin(); i != stl_arr_2.end(); i++){
        cout << *i << " ";
    }
    cout <<  endl;


    //常用函数
    //填充整个数组
    stl_arr_3.fill(100);
    
    //交换两个array数组
    stl_arr_4.swap(stl_arr_3);
    
    //判断一个 array 序列是否为空
    if(stl_arr_1.empty()){
        cout << "stl_arra_1为空" << endl;
    }else{
        cout << "stl_arra_1不为空" << endl;
    }
    
    //求一个array队列中元素的个数
    cout << "stl_arr_5中元素个数为:>" << stl_arr_5.size() <<endl;
    //size也可以判断一个容器是否为空，但相对效率没 empty 高
    //max_size ,因为array中元素个数是确定的，所以 array 一旦确定其max_size 也就确定了
    for (int i = 0; i < stl_arr_3.max_size(); i++)
    {
        cout << stl_arr_3.at(i) << " ";
    }
    cout << endl;   

    cout << "stl_arr_1的第一个元素是:>" << stl_arr_1.at(0);
    cout << "stl_arr_1的第一个元素是:>" << stl_arr_1.front();
    cout << "stl_arr_1的第一个元素是:>" << stl_arr_1.data();
  
    cout << "stl_arr_1的最后一个元素是:>" << stl_arr_1.back();


    return 0;
}
