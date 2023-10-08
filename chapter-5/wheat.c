#include <stdio.h>
#define SQUARES 64 // 棋盘中的方格数

int main(void)
{
    const double CROP = 2E16; // 世界小麦年产谷粒数
    double current, total;
    int count = 1;
    printf("square   current   total    n");
    printf("fraction  of    \n");
    printf("        added       grains  ");
    printf("world total \n");
    total = current = 1.0;
    printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    while (count < SQUARES)
    {
        count += 1;
        current = 2.0 * current;
        total += current;
        printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    }
    printf("That's all.\n");
    return 0;
}