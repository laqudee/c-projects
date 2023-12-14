#include <stdio.h>
#include <string.h>
#include "util.h"
#define MAXTITL 41
#define MAXAUTL 31

struct book
{
    char title[MAXTITL]; /* 书名的最大长度 +1*/
    char author[MAXAUTL]; /* 作者姓名的最大长度 +1*/
    float value;
};

int main(void)
{
    struct book library;
    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITL);
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library.value);
    printf("%s by %s: $%.2f\n", library.title,
        library.author, library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.author,
        library.title, library.value);
    printf("Done.\n");

    return 0;
}
