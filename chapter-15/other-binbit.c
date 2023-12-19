/** 用于切换一个值中的后n位，待处理值和n都是函数的参数 */
/** ～运算符切换一个字节的所有位，而不是选定的少数位 */
/** ^运算符可用于切换单个位 */
#include <limits.h>
#include <stdio.h>
#include "util.h"

int main(void)
{
  char bin_str[CHAR_BIT * sizeof(int) + 1];
  int number;
  puts("Enter integers and see them in binary.");
  puts("Non-numberic input terminates program.");
  while(scanf("%d", &number) == 1)
  {
    itobs(number, bin_str);
    printf("%d is \n", number);
    show_bstr(bin_str);
    putchar('\n');
    number = invert_end(number, 4);
    printf("Inverting the last 4 bits gives\n");
    show_bstr(itobs(number, bin_str));
    putchar('\n');
  }
  puts("Bye!");
  return 0;
}

