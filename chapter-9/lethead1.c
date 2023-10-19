#include <stdio.h>
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Main Street, Anytown, USA"
#define PLACE "New York"
#define WIDTH 40

void starbar(void); // 函数原型

int main(void)
{
    starbar();
    printf("%s\n", NAME);
    printf("%s\n", ADDRESS);
    printf("%s\n", PLACE);
    starbar();
    return 0;
}

void starbar(void)
{
    int i;
    for (i = 0; i < WIDTH; i++)
        printf("*");
    printf("\n");
}