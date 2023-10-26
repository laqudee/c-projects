#include <stdio.h>
#include <string.h>

void stsrt(char *string[], int num); // 字符串排序

// 字符串-指针-排序函数
void stsrt(char *string[], int num)
{
    char *temp;
    int top, seek;
    for (top = 0; top < num - 1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(string[top], string[seek]) > 0)
            {
                temp = string[top];
                string[top] = string[seek];
                string[seek] = temp;
            }
}