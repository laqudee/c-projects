#include <stdio.h>

void print_name(void);
int years_to_days(int);
void jolly(int);
void deny(void);

int main(void)
{
    // 打印姓名
    print_name();

    // 返回天数并打印
    int days = years_to_days(20);
    printf("I am %d days old.\n", days);

    jolly(3);
    deny();
}

void print_name(void)
{
    printf("I name is %s.\n", "laqudee");
}

int years_to_days(int year)
{
    return year * 365;
}

void jolly(int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("For he's a jolly good fellow!\n");
    }
}

void deny(void)
{
    printf("Which nobody can deny!\n");
}