#include <stdio.h>

int main(void)
{
    float weight;
    float value;
    printf("Are you worth your weight in platinum?\n");
    printf("Let is check it out!\n");
    printf("Enter your weight in pounds: ");
    scanf("%f", &weight);
    value = 1700.0 * weight * 14.5833;
    printf("You are worth $%.2f in platinum.\n", value);
    printf("You are easily worth that! If platinum prices drop, \n");
    printf("eat more to maintain your weight.\n");
    return 0;
}