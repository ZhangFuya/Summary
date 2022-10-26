#include <stdbool.h>
#include <stdio.h>

bool isLeapYear(int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    return false;
}

int main(int argc, char const *argv[]) {
    unsigned int year = 2022;
    unsigned int month = 10;
    unsigned int day = 24;
    unsigned int total = 0;  //用于天数的累加，建议是赋其初始值

    switch (month) {
        case 12:
            total += 30;
        case 11:
            total += 31;
        case 10:
            total += 30;
        case 9:
            total += 31;
        case 8:
            total += 31;
        case 7:
            total += 30;
        case 6:
            total += 31;
        case 5:
            total += 30;
        case 4:
            total += 31;
        case 3:
            if(isLeapYear(year))
                total += 29;
             else
                total += 28;   
        case 2:
            total += 31;
        case 1:
            total += day;
    }

    printf("%d\n", total);

    return 0;
}
