#include <stdio.h>

void up_and_down(int);

int main(void)
{
    up_and_down(1);
    return 0;
}

void up_and_down(int n)
{
    // %p 打印地址
    printf("Level %d: n location %p\n", n, &n);
    if (n < 4)
    {
        up_and_down(n + 1);
    }
    printf("LEVEL %d: n location %p\n", n, &n);
}

/**
 * result:
Level 1: n location 000000dd50fff9b0
Level 2: n location 000000dd50fff980
Level 3: n location 000000dd50fff950
Level 4: n location 000000dd50fff920
LEVEL 4: n location 000000dd50fff920
LEVEL 3: n location 000000dd50fff950
LEVEL 2: n location 000000dd50fff980
LEVEL 1: n location 000000dd50fff9b0

函数调用链：
    fn1() -> fn2() -> fn3() -> fn4()
当fn4()结束，控制转给fn3() ->fn2() ->fn1
*/