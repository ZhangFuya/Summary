#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]){
    map<string, string> stl_map_1;
    
    map<string, string> stl_map_2  { 
        {"C", "C语言"}, {"Java", "Java语言"}
      };
    
    map<string, string> stl_map_3(stl_map_2);

    map<string, string> stl_map_4(stl_map_2.begin(), stl_map_2.end());

    //说几点
    //1. 所有的关联容器都会依据键值进行默认排序
    //2. map中元素是键值对，其中键的值不能重复
    //3. map在创建时可以指定元素的排列方式，map<keyType<T>, valueType<T>, compareType<T> >
    //排列类型可以是 std::less<keyType>（默认类型、升序排列）、std::greater<T>、还可以是自定义的类型


    //增删改查
    stl_map_1["1"] = "你好，陌生人";    //map中[],既可以访问某一个键值，又可以添加一个元素(当对应的键不存在时)
    
    stl_map_1.insert(stl_map_1.begin(), {"2", "你好"});
    stl_map_1.insert(stl_map_2.begin(), stl_map_2.end());
    stl_map_1.emplace("3", "message3");
    stl_map_1.emplace("4", "messgae4");
    stl_map_1.emplace_hint(stl_map_1.begin(),"5", "message5");
    //insert 可以加一个，也可以加一段，但无需指定加入位置。emplace只能加一个无需指定加入位置，emplace_hint加一个却要指定加入位置    
    cout << "stl_map_1遍历1:>" << endl;
    for(auto i : stl_map_1){
        cout << i.first << "-" << i.second << "   ";
    }
    cout << endl;


    stl_map_1.erase(stl_map_1.begin());
    stl_map_1.erase("2");
    stl_map_2.erase(stl_map_2.begin(), stl_map_2.end());
    cout << "stl_map_1遍历2:>" << endl;
    for(auto i = stl_map_1.begin(); i != stl_map_1.end(); i++){
        cout << (*i).first << "-" << (*i).second << "   ";
    }
    cout << endl;

    map<string, string> temp_map { {"JS", "JavaScrpt"}, {"GO", "Golang"} };
    stl_map_1.swap(temp_map);
    temp_map.clear();
    if(temp_map.empty()){
        cout << "temp_map 完成与 stl_map_1 的交换，并被清空" << endl;
    }

    stl_map_1.insert(stl_map_1.begin(), {"C", "C语言"});
    stl_map_1.emplace("3", "message3");
    stl_map_1.emplace("4", "messgae4");
    stl_map_1.emplace("5", "messgae5");
    stl_map_1.emplace_hint(stl_map_1.begin(),"Java", "Java语言");
    cout << "stl_map_1遍历 :>" << endl;
    for(auto i = stl_map_1.begin(); i != stl_map_1.end(); i++){
        cout << (*i).first << "-" << (*i).second << "   ";
    }
    cout << endl;


    int key_num = stl_map_1.count("C");
    cout << "count 方法查找键值的个数"
         << "又因为map中的键值不能重复,所以count方法返回0,则键不存在，否则键存在" << endl;

    auto find_ret = stl_map_1.find("C");
    cout << "find找到返回pair的双向迭代器,值为 " 
         << (*find_ret).first << "-" << (*find_ret).second 
         << " 如果没找到返回和 end()方法 一样的迭代器" <<endl;
    
    auto lower_bound_ret = stl_map_1.lower_bound("E");
    cout << "lower_bound 寻找大于或等于参数的第一个键值对 找到返回pair的双向迭代器,值为 " 
         << (*lower_bound_ret).first << "-" << (*lower_bound_ret).second 
         << " 如果没找到 first值为元素数量, second值为0" <<endl;

    auto upper_bound_ret = stl_map_1.upper_bound("Go");
    cout << "upper_bound 寻找大于参数(不包括等于)的第一个键值对 找到返回pair的双向迭代器,值为 " 
         << (*upper_bound_ret).first << "-" << (*upper_bound_ret).second 
         << " 如果没找到 first值为元素数量, second值为0" <<endl;

    //lower_bound是大于等于，upper_bound是大于

    return 0;
}
