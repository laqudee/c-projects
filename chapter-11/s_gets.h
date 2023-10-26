#include <stdio.h>

char *s_gets(char *st, int n);

void put1(const char *string);

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val) // ret_val != NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void put1(const char *string)
// 打印字符串，不添加\n
{
    while (*string != '\0')
        putchar(*string++);
}