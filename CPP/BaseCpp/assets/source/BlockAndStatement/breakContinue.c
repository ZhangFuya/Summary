#include <stdio.h>

#define NUMBER 10

int main(int argc, char const *argv[]) {
    int i = 1;
    while (i < NUMBER) {
        if (i == 5) {
            break;
        }
        // 输出 i 的值
        i++;
    }

    i = 0;
    while (i < NUMBER) {
        if (i == 5) {
            continue;
        }
        // 输出 i 的值
        i++; 
    }

    return 0;
}

// 使用 break 最终输出的结果为 1 2 3 4
// 使用 continue 最终输出的结果为 1 2 3 4 6 7 8 9