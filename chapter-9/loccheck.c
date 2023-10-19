#include <stdio.h>

void mikado(int);

int main(void)
{
    int pooh = 2, bah = 5; /* main()的局部变量 */
    printf("In main(), pooh = %d and &pooh = %p\n", pooh, &pooh);
    printf("In main(), bah = %d and &bah = %p\n", bah, &bah);
    mikado(pooh);
    return 0;
}

void mikado(int bah)
{
    int pooh = 10;
    printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);
    printf("In mikado(), bah = %d and &bah = %p\n", bah, &bah);
}

/**
 * result:
 * 这四个地址均不同
*/