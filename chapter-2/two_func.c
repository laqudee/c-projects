#include <stdio.h>

void butler(void); // ANSI/ISO C 函数原型
int main(void)
{
    printf("I will summon the butler function.\n");

    butler();

    printf("Yes. I did.\n");

    return 0;
}

void butler(void)
{
    printf("You rang, sir?\n");
}