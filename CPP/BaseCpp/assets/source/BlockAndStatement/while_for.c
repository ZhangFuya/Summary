#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i = 0;
    for (; i < 10; i++) {
        if (i == 5) 
            continue;
        // 打印 i 的值
    }

    while (i < 10) {
        if (i == 5) 
            continue;
        // 打印 i 的值
        i++;
    }

    return 0;
}

// 使用 for 循环，continue执行之后，步进语句会被执行 i 值变为 6
// 使用 while 循环，continue执行之后，步进语句不会被执行 i 值仍然为 5
// 最终导致 for 循环能正常执行，而 while 循环进入死循环(i = 5, < 10 且i值得不到修改导致循环条件始终成立)