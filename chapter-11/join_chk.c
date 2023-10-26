// 字符串拼接
#include <stdio.h>
#include <string.h>
#include "s_gets.h"
#define SIZE 30
#define BUGSIZE 13

char *s_gets(char *st, int n);

int main(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    char bug[BUGSIZE];
    int avaiable;
    puts("what is your favorite flower?");
    s_gets(flower, SIZE);
    if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
        strcat(flower, addon);
    puts(flower);
    puts("what is your favorite bug?");
    s_gets(bug, BUGSIZE);
    avaiable = BUGSIZE - strlen(bug) - 1;
    strncat(bug, addon, avaiable);
    puts(bug);
    return 0;
}