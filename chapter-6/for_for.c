#include <stdio.h>
#define ROWS 6
#define CHARS 6

void rows2(void);

int main(void)
{
    int row;
    char ch;
    for (row = 0; row < ROWS; row++)
    {
        for (ch = 'A'; ch < ('A' + CHARS); ch++)
            printf("%c", ch);
        printf("\n");
    }

    printf("####################\n");
    rows2();

    return 0;
}

void rows2(void)
{
    int row;
    char ch;
    for (row = 0; row < ROWS; row++)
    {
        for (ch = ('A' + row); ch < ('A' + CHARS); ch++)
            printf("%c", ch);
        printf("\n");
    }
}