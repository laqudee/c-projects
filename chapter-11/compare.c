// 字符串比较
#include <stdio.h>
#include <string.h>
#include "s_gets.h"
#define ANSWER "GRANT"
#define SIZE 40

int main(void)
{
    char try[SIZE];
    puts("Who is buried in GRANT's tomb?");
    s_gets(try, SIZE);
    while (strcmp(try, ANSWER)) // 非零值都为真
    {
        puts("No, that's not it. Try again.");
        s_gets(try, SIZE);
    }
    puts("That's right!");
    return 0;
}