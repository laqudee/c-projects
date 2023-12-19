/* 使用位操作显示二进制 */
#include <stdio.h>
#include <limits.h>
#include "util.h"

int main(void)
{
  char bin_str[CHAR_BIT * sizeof(int) + 1];
  int number;
  puts("enter integers and see them in bin");
  puts("Non-numeric input terminates program.");
  while(scanf("%d", &number) == 1)
  {
    itobs(number, bin_str);
    printf("%d is ", number);
    show_bstr(bin_str);
    putchar('\n');
  }
  puts("Done.");

  return 0;
}

