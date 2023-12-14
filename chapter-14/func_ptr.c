#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "util.h"
#define LEN 81

char showmenu(void);
void eatline(void);
void show(void(*fp)(char *), char * str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *); /* 大小写转换*/
void Dummy(char *); /* 不更改字符串*/

int main(void)
{
  char line[LEN];
  char copy[LEN];
  char choice;
  void (*pfun)(char *); /* 声明一个函数指针，被指向的函数接受char *类型的参数 */

  puts("Enter a string (EMPTY LINE TO QUIT):");
  while(s_gets(line, LEN) != NULL && line[0] != '\0')
  {
    while((choice = showmenu()) != 'n')
    {
      switch (choice)
      {
        case 'u': pfun = ToUpper; break;
        case 'l': pfun = ToLower; break;
        case 't': pfun = Transpose; break;
        case 'o': pfun = Dummy; break;
      }
      strcpy(copy, line); // 为show()拷贝一份
      show(pfun, copy); // 根据用户的选择，使用选定的函数
    }
    puts("Enter a string (EMPTY LINE TO QUIT):");
  }
  puts("Bye");

  return 0;
}

char showmenu(void)
{
  char ans;
  puts("Enter a choice:");
  puts("u) uppercase     l) lowercase");
  puts("t) transpose     o) original");
  ans = getchar(); // 获取用户输入
  ans = tolower(ans); // 转换为小写
  eatline(); // 清理输入行
  while (strchr("ulton", ans) == NULL)
  {
    puts("Please enter a u, l, t, or o:");
    ans = getchar();
    eatline();
  }
  return ans;
}

void eatline(void)
{
  while (getchar() != '\n')
    continue;
}

void ToUpper(char * str)
{
  while (*str)
  {
    *str = toupper(*str);
    str++;
  }
}

void ToLower(char *str)
{
  while (*str)
  {
    *str = tolower(*str);
    str++;
  }
}

void Transpose(char *str)
{
  while (*str)
  {
    if (islower(*str))
      *str = toupper(*str);
    else if (isupper(*str))
      *str = tolower(*str);
    str++;
  }
}

void Dummy(char * str)
{
  /* 不改变字符串 */
}

void show(void (* fp)(char *), char * str)
{
  (*fp)(str); /* 调用函数指针 */
  puts(str);
}

