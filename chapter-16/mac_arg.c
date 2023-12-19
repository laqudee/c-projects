/** 带参数的宏 */
#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf("The result is %d\n", X)

int main(void)
{
  int x = 5;
  int z;
  z = SQUARE(x);
  printf("SQUARE(x): ");
  PR(z);
  z = SQUARE(2);
  PR(z);
  PR(SQUARE(x + 2));
  PR(100/SQUARE(2));
  /**PR(SQUARE(++x));*/
}
