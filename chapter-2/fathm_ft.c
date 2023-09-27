#include <stdio.h>

int main(void)
{
    int feet, fathoms;
    fathoms = 2;
    feet = 6 * fathoms;
    printf("The distance is %d feet and %d fathoms.\n", feet, fathoms);
    printf("Yes, I said %d feet!\n", 6 * fathoms);
    return 0;
}