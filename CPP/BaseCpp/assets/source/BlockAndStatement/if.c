#include <stdio.h>

enum e_age { 
    AGE1 = 18, 
    AGE2 = 30, 
    AGE3 = 40, 
    AGE4 = 60 
};

int main(int argc, char const *argv[]) {
    int age = 10;
    if(age < 0){       
        return -1; //如果age < 0，成立，那么后面的代码就都不会执行
    }
    // 问：如果我这里写 age = 30 输出是多少
    if (age >= AGE1) {   
        printf("成年\n");
    } else if (age >= AGE2 && age < AGE3) {
        printf("而立之年\n");
    } else if (age >= AGE3 && age < AGE4) {
        printf("正值壮年\n");
    } else if (age >= AGE4) {
        printf("老年\n");
    }
    return 0;
}

