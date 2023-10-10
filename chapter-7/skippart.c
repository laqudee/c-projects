#include <stdio.h>

int main(void)
{
    const float MIN = 0.0f;
    const float MAX = 100.0f;
    float score, total = 0.0f;
    int n = 0;
    float min = MAX;
    float max = MIN;
    printf("Enter the first score (q to quit): ");
    while (scanf("%f", &score) == 1)
    {
        if (score < MIN || score > MAX)
        {
            printf("invalid value. Try again: ");
            continue; // 跳转至while循环的测试条件
        }
        printf("Accepting %0.1f: \n", score);
        min = (score < min) ? score : min;
        max = (score > max) ? score : max;
        total += score;
        n++;
        printf("Enter the next score (q to quit): ");
    }
    if (n > 0)
    {
        printf("Total = %d score, Average = %0.2f\n", n, total / n);
        printf("min = %0.1f, max = %0.1f\n", min, max);
    }
    else
    {
        printf("No scores were entered.\n");
    }
    return 0;
}