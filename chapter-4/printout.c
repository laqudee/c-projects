#include <stdio.h>
#define PI 3.141593

void width(void);

int main(void)
{
    int number = 7;
    float pies = 12.75;
    int cost = 7800;
    printf("The %d contestant ate %f berry pies.\n", number, pies);
    printf("The value of pi is %f.\n", PI);
    printf("Tarewell! thou art too dear for my possessing, \n");
    printf("%c%d\n", '$', 2 * cost);

    width();

    return 0;
}

void width(void)
{
    const int PAGES = 959;
    printf("*%d*\n", PAGES);
    printf("*%2d*\n", PAGES);
    printf("*%10d*\n", PAGES);
    printf("*%-10d*\n", PAGES);
}