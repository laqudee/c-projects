#include <stdio.h>
#define PERIOD '.'

int main(void)
{
    char ch;
    int charcount = 0;
    while ((ch = getchar()) != PERIOD)
    {
        if (ch != ' ' && ch != '\n')
            charcount++;
    }
    printf("There are %d characters in the input.\n", charcount);
    return 0;
}