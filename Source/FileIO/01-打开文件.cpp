#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    ofstream ofs("test.txt", ios::app);  //打开文件一定不要忘了 close
    if(ofs){
        cout << "文件打开成功" << endl;
    }else {
        cout << "文件打开失败" << endl;
    }
    //还可以使用open函数
    ofs.open("test.txt", ios::app);
    if(ofs){
        cout << "文件打开成功" << endl;
    }else {
        cout << "文件打开失败" << endl;  //一个对象只能打开一个文件，所以这里会输出 打开失败
                                       //open之前对文件进行关闭后输出 打开成功
    }

    ifstream ifs("test.txt", ios::in | ios::ate);
    if(ifs){
        cout << "文件打开成功" << endl;
    }else{
        cout << "文件打开失败" << endl;
    }

    ifs.close();
    ofs.close();
    return 0;
}
