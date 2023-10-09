#include <stdio.h>

int main(void)
{
    int x;
    int y = 55;
    for (x = 1; y < 75; y = (++x * 5) + 50)
        printf("x = %d, y = %d\n", x, y);
    return 0;
}