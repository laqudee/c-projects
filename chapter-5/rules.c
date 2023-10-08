#include <stdio.h>

int sizeoffn(void);

int main(void)
{
    int top, score;
    top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
    printf("top = %d, score = %d\n", top, score);

    sizeoffn();

    return 0;
}

int sizeoffn(void)
{
    int n = 0;
    size_t intsize;
    intsize = sizeof(int);
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", n, sizeof n, intsize);

    return 0;
}