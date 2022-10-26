// 已知使用 getchar 可以获取来自键盘的一个输入 int ch = getchar()；
// 编写程序，当输入 EOF 时，程序退出，否则等待下次输入。
// EOF：文件结束标志。其值为 -1， 按下 Ctrl + Z 向控制台输入一个 EOF

#include <stdio.h>
int main(int argc, char const *argv[]) {
    int ch = 0;
    // 使用 while 语句
    while ((ch = getchar()) != EOF){
    printf("%c", ch);
    }

    // for 语句
    for (; ch != EOF;) {
        ch = getchar();
        printf("%c", ch);
    }

    return 0;
}