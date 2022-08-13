// linux环境
#include <unistd.h>
// window环境
//#include <windows.h>
#include <ctime>
#include <iostream>
int main(int argc, char const* argv[]) {
    using namespace std;
    // 获取滴答数--clock
    clock_t clt = clock();
    cout << clt << endl;

    // 获取当前时间与时间戳间的秒值
    time_t timt1;
    timt1 = time(&timt1);
    cout << timt1 << endl;

    // 比较两个时间之间的差值
    for (int i = 0; i < 10000; i++)
        usleep(100);
    time_t timt2;
    timt2 = time(&timt2);
    cout << difftime(timt2, timt1) << endl;

    // 转换函数专场
    tm* tm1 = gmtime(&timt1);
    cout << tm1->tm_year + 1900 << endl;
    tm1 = localtime(&timt1);
    cout << tm1->tm_year << endl;

    // time与string之间的转换
    char * dateStr1;
    dateStr1 = ctime(&timt1);
    cout << dateStr1;

    dateStr1 = asctime(tm1);
    cout << dateStr1;

    return 0;
}
