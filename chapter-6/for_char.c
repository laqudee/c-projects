#include <stdio.h>

int main(void)
{
    char ch;
    for (ch = 'a'; ch <= 'z'; ch++)
        printf("The ASCII value for %c id %d.\n", ch, ch);
    return 0;
}