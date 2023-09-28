#include <stdio.h>

void number_format(void);
void toobig(void);

int main(void)
{
    number_format();
    toobig();

    return 0;
}

void number_format(void)
{
    int x = 100;
    printf("dex = %d; octal = %o; hex = %x\n", x, x, x);
    printf(" dec = %d; ocatal = %#o; hex = %#x\n", x, x, x);
}

void toobig(void)
// 整数溢出
{
    int i = 2147483647;
    unsigned int j = 4294967295;
    printf("%d %d %d\n", i, i + 1, i + 2);
    printf("%u %u %u\n", j, j + 1, j + 2);
}