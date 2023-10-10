#include <stdio.h>
#include <ctype.h>
#define SPACE ' '

void cypher2(void);

int main(void)
{
    char ch;
    ch = getchar(); // 读取一个字符
    while (ch != '\n')
    {
        if (ch == SPACE)
            putchar(ch);
        else
            putchar(ch + 1);
        ch = getchar(); // 获取下一个字符
    }
    putchar(ch); // 打印换行符

    cypher2();

    return 0;
}

// input:   CALL ME HAL
// output:  DBMM NF IBM

void cypher2(void)
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))     // 如果是一个字符
            putchar(ch + 1); // 显示该字符的下一个字符
        else
            putchar(ch);
    }
    putchar(ch); // 显示换行符
}