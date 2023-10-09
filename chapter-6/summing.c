#include <stdio.h>

int main(void)
{
    long num;
    long sum = 0L;
    printf("Please enter a number to be summed ");
    printf("(q to quit): ");
    while (scanf("%ld", &num) == 1)
    {
        sum += num;
        printf("Please enter next number (q to quit): ");
    }
    printf("The sum is %ld.\n", sum);
    return 0;
}