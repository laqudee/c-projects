#include <stdio.h>

int main(void)
{
    int count, sum; // 声明
    count = sum = 0; // 表达式语句
    while (count++ < 20) // 迭代语句
    {
        sum += count;
        printf("count = %d, sum = %d\n", count, sum);
    }
    return 0; // 跳转语句
}