#include <stdio.h>
#define SIZE 10
#define PAR 72

int main(void)
{
    int index, score[SIZE];
    int sum = 0;
    float average;
    printf("Enter %d golf scores: \n", SIZE);
    for (index = 0; index < SIZE; index++)
    {
        scanf("%d \n", &score[index]);          // 读取分数
        printf("score = %5d \n", score[index]); // 打印分数
        sum += score[index];
    }
    average = (float)sum / SIZE;
    printf("The average score is %.2f.\n", average);
    printf("The par is %d.\n", PAR);
    return 0;
}