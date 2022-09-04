#include <stdio.h>

// 验证值传递和地址传递
int main(int argc, char const *argv[]) {
    int a = 10, b = 20;
    void swap01(int a, int b);  //直接传入两个值发生值传递，两数未交换
    swap01(a, b);
    printf("swap(int, int)函数指定后.a(10)、b(20)的值为:>%d  %d\n", a, b);

    void swap02(int *num1, int *num2);  //地址传递可以交换两个数
    swap02(&a, &b);
    printf("swap(int*, int*)函数指定后.a(10)、b(20)的值为:>%d  %d\n", a, b);
    swap02(&a, &b);

    void swap03(int *num1, int *num2);  //地址传递只交换形参地址，两数值未改变
    swap03(&a, &b);
    printf("swap(int*, int*)交换形参地址后.a(10)、b(20)的值为:>%d  %d\n", a, b);

    void swap04(int *num1, int *num2);
    swap04(&a, &b);
    printf("swap(int*, int*)函数指定后.a(10)、b(20)的值为:>%d  %d\n", a, b);
    return 0;
}

// 值传递，两数的值不会发生改变
void swap01(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap02(int *num1, int *num2) {
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// 将形参指向进行更改，实参的值不会发生更改
void swap03(int *num1, int *num2) {
    int *temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

// swap04中的运算比较灵性。这是因为对于temp未定义初始值。
// temp是一个指针，它可能指向程序内部，也可能指向程序外部
// 对于不同的编译器和IDE，因其处理方式不同，结果也无法保持一致
void swap04(int *num1, int *num2) {
    int *temp;
    *temp = *num1;
    *num1 = *num2;
    *num2 = *temp;
}
