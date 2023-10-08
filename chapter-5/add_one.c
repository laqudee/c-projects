#include <stdio.h>

void post_pre(void);

int main(void)
{
    int ultra = 0, super = 0;
    while (super < 5)
    {
        super++;
        ++ultra;
        printf("super = %d, ultra = %d\n", super, ultra);
    }

    post_pre();
    
    return 0;
}

void post_pre(void)
{
    int a = 1, b = 1;
    int a_post, pre_b;
    a_post = a++; // 后缀递增
    pre_b = ++b;  // 前缀递增
    printf("a = %d, b = %d\n", a, b);
    printf("a_post = %d, pre_b = %d\n", a_post, pre_b);
}