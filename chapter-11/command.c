// 命令行参数
#include <stdio.h>

int main(int argc, char *argv[])
{
    int count;
    printf("The command line has %d arguments.\n", argc - 1);
    for (count = 1; count < argc; count++)
        printf("argv[%d] = %s\n", count, argv[count]);
    printf("\n");

    int i, times;
    if (argc < 2 || (times = atoi(argv[1])) < 1)
        printf("Usage: %s positive-number\n", argv[0]);
    else
        for (i = 0; i < times; i++)
            puts("Hello, world!");
    return 0;
}