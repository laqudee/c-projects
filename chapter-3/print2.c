#include <stdio.h>

void print_format(void);
int print_char(void);

int main(void)
{
    print_format();
    print_char();
    return 0;
}

void print_format(void)
{
    unsigned int un = 3000000000; /* int为32位和short为16位的系统 */
    short end = 200;
    long big = 65537;
    long long verbig = 12345678908642;
    printf("un = %u and not %d\n", un, un);
    printf("end = %hd and %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    printf("verbig = %lld and not %ld\n", verbig, verbig);
}

int print_char(void)
{
    char ch;
    printf("Please enter a character.\n");
    scanf("%c", &ch);
    printf("The code for %c is %d.\n", ch, ch);
    return 0;
}