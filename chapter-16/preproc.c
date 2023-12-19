/** 简单的预处理实例 */
#include <stdio.h>
#define TWO 2 /** 可以使用注释 */
#define OW "One, two, three Five Wilde"
#define FOUR TWO * TWO
#define PX printf("X is %d.\n", x)
#define FMT "X is %d.\n"

int main(void)
{
  int x = TWO;
  PX;
  x = FOUR;
  printf(FMT, x);
  printf("%s\n", OW);
  printf("TWO:OW\n");
  return 0;
}
