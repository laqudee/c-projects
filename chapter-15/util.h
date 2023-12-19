#include <stdio.h>
#include <limits.h>

char *itobs(int, char *);
void show_bstr(const char *);
int invert_end(int num, int bits);

/* 返回的地址与传入的地址相同*/
char *itobs(int n, char *ps)
{
  int i;
  const static int size = CHAR_BIT * sizeof(int);
  for(i = size -1; i >= 0; i--, n>>=1)
    ps[i] = (01 & n) + '0';
  ps[size] = '\0';
  return ps;
}

/** 以4位为一组，显示二进制字符串 */
void show_bstr(const char * str)
{
  int i = 0;
  while(str[i])
  {
    putchar(str[i]);
    if(++i % 4 == 0 && str[i])
      putchar(' ');
  }
}

/**
 * @brief
 * limits.h中的CHAR_BIT宏，该宏表示char中的位数
 * 
 */

int invert_end(int num, int bits)
{
  int mask = 0;
  int bitval = 1;
  while(bits-- > 0)
  {
    mask |= bitval;
    bitval <<= 1;
  }
  return num^mask;
}
