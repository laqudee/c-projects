// 修改字符串中的字符
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81

void ToUpper(char *);
int PunctCount(const char *);

int main(void)
{
    char line[LIMIT];
    char *find;
    puts("Please enter a line:");
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n'); // 查找换行符
    if (find)
        *find = '\0';
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n", PunctCount(line));
    return 0;
}

void ToUpper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

int PunctCount(const char *str)
{
    int punct = 0;
    while (*str)
    {
        if (ispunct(*str))
            punct++;
        str++;
    }
    return punct;
}