#include <stdio.h>

void pound(int n);

int main(void)
{
    int times = 5;
    char ch = '!';
    float f = 6.0f;
    pound(times); // int类型
    pound(ch);    // 与pound((int)ch)等价
    pound(f);     // 与pound((int)f)等价

    return 0;
}

void pound(int n)
{
    while (n-- > 0)
    {
        printf("#");
    }
    printf("\n");
}