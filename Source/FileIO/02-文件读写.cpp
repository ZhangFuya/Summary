#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

class Student {
public:
    char stu_name[20];
    int age;
};

int main(int argc, char const *argv[]) {
    Student stu;
    int L = 0;
    int R = 0;
    int Mid = 0;
    fstream iofs("student.dat", ios::binary | ios::out | ios::in);
    if (!iofs) {
        cout << "student.dat打开错误" << endl;
        return -1;
    }

    cout << "输入学生姓名和学号，当输入姓名是exit时停止输入" << endl;
    while (cin >> stu.stu_name >> stu.age) {
        if (strncmp(stu.stu_name, "exit", 4) == 0) break;
        iofs.write((char *)&stu, sizeof(stu));
    }

    iofs.seekp(0, ios::end);
    R = iofs.tellp() / sizeof(stu) - 1;
    //二分查找
    while (L <= R) {
        Mid = (L + R) / 2;
        iofs.seekp(Mid * sizeof(Student), ios::beg);
        iofs.read((char *)&stu, sizeof(stu));
        int str_ret = strcmp(stu.stu_name, "Jack");
        if (str_ret == 0) {
            cout << "找到了，位置是:>" << Mid + 1 << endl;
            break;
        } else if (str_ret > 0) {
            R = Mid - 1;
        } else if (str_ret < 0) {
            L = Mid + 1;
        }
    }

    iofs.close();
    return 0;
}
