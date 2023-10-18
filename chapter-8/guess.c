#include <stdio.h>

int main(void)
{
    int guess = 1;
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("\n an n if it is wrong.\n");
    printf("Uh...is your number %d?\n", guess);
    while (getchar() != 'y')
    {
        printf("Well, then, is it %d?\n", ++guess);
        while (getchar() != '\n')
            continue;
    }
    printf("You guessed it!\n");
    return 0;
}