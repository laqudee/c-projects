#include <stdio.h>

void trystat(void);

int main(void)
{
    int count;
    for (count = 1; count <= 3; count++)
    {
        printf("Here comes iteration %d:\n", count);
        trystat();
    }
    return 0;
}

void trystat(void)
{
    int fade = 1;
    static int stay = 1; // stay只在编译一次
    printf("fade = %d; stay = %d\n", fade++, stay++);
}

/** result:
Here comes iteration 1:
fade = 1; stay = 1
Here comes iteration 2:
fade = 1; stay = 2
Here comes iteration 3:
fade = 1; stay = 3
*/