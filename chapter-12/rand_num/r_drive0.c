// 测试 rand0.c
#include <stdio.h>

extern unsigned int rand0(void);

int main(void)
{
    int count;
    for (count = 0; count < 5; count++)
        printf("rand0() = %d\n", rand0());
    return 0;
}

/**
 Usage:
 => gcc r_drive0.c rand0.c
 => ./a.exe
*/