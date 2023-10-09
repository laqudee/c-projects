#include <stdio.h>

int main(void)
{
    long num;
    long sum = 0L;
    _Bool input_is_good;
    printf("Please enter a number to be summed ");
    printf("(q to quit): ");
    input_is_good = scanf("%ld", &num) == 1;
    while (input_is_good)
    {
        sum += num;
        printf("Please enter next number (q to quit): ");
        input_is_good = scanf("%ld", &num) == 1;
    }
    printf("The sum is %ld.\n", sum);
    return 0;
}