#include <stdio.h>
long fact(int n);
long rfact(int n);

int main(void)
{
    int num;
    printf("This program calculates factorials.\n");
    printf("Enter a value in the range 0-12 (q to quit):\n");
    while (scanf("%d", &num) == 1)
    {
        if (num < 0)
        {
            printf("The factorial of a negative number is not defined.\n");
        }
        else if (num > 12)
        {
            printf("The factorial of a number larger than 12 is not defined.\n");
        }
        else
        {
            printf("loop: %d factorial = %ld\n", num, fact(num));
            printf("recursive: %d factorial = %ld\n", num, rfact(num));
        }
        printf("Enter a value in the range 0-12 (q to quit):\n");
    }
    printf("Bye.\n");
    return 0;
}

long fact(int n)
{
    long ans;
    for (ans = 1; n > 1; n--)
        ans *= n;
    return ans;
}

long rfact(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * rfact(n - 1);
}