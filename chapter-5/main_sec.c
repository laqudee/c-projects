// 将秒数转换为分和秒
#include <stdio.h>
#define SEC_PER_MIN 60

int main(void)
{
    int sec, min, left;
    printf("Convert seconds to minutes and seconds.\n");
    printf("Enter the number of seconds (<=0 to quit): \n");
    scanf("%d", &sec);
    while (sec > 0)
    {
        min = sec / SEC_PER_MIN;  // 截断分钟数
        left = sec % SEC_PER_MIN; // 计算剩余秒数
        printf("%d seconds is %d minutes and %d seconds.\n", sec, min, left);
        printf("Enter the number of seconds (<=0 to quit): \n");
        scanf("%d", &sec);
    }
    printf("Bye.\n");
    return 0;
}