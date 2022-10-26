#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    int j = 0;
    for( ; i < 3; i++){
        for( ; j < 3; j++){
            // 内层循环只执行3次，因为 j 在进入循环时未初始化，其作用域为 main 函数，
            // 因此 j 加到 3 后，并不会进行 等于 0 的初始化，从而内层 for 循环无法进入。
        }
    }
    return 0;
}
