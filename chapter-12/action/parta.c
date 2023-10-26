// 不同的存储类别
// 与partb.c一起编译
#include <stdio.h>

void report_count();
void accumulate(int k);

int count = 0; // 文件作用域，外部链接

int main(void)
{
    int value;      // auto variable
    register int i; // register variable
    printf("Enter a positive integer (0 to quit): ");
    while (scanf("%d", &value) == 1 && value > 0)
    {
        ++count; // use file scope variable
        for (i = value; i >= 0; i--)
            accumulate(i);
        printf("Enter a positive integer (0 to quit): ");
    }
    report_count();
    return 0;
}

void report_count()
{
    printf("Loop executed %d times\n", count);
}

/**
 => gcc parta.c partb.c
 => .\a.exe
*/