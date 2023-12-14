#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book {
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
};

int main(void)
{
  struct book library[MAXBKS];
  int count = 0;
  int index, filecount;
  FILE * pbooks;
  int size = sizeof(struct book);

  if ((pbooks = fopen("book.dat", "a+b")) == NULL)
  {
    fputs("Can't open book.dat file.\n", stderr);
    exit(1);
  }

  rewind(pbooks); /*定位文件开始*/
  /* 把一个结构读到结构数组中，当数组已满或文件读完为止，filecount统计已读结构的数量 */
  while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
  {
    if (count == 0)
      puts("Current contents of book.dat:");
    printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
    count++;
  }
  filecount = count;
  if (count == MAXBKS)
  {
    fputs("The book.dat file is full.", stderr);
    exit(2);
  }

  puts("Please add new book title.");
  puts("Press [enter] at the start of a line to stop.");
  /* 提示用户进行输入，并接受用户输入 */
  while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
  {
    puts("Now enter the author.");
    s_gets(library[count].author, MAXAUTL);
    puts("Now enter the value.");
    scanf("%f", &library[count++].value);
    while(getchar() != '\n')
      continue;
    if (count < MAXBKS)
      puts("Enter the next title.");
  }

  if (count > 0)
  {
    puts("Here is the list of your books.");
    /* 打印文件和用户输入的数据 */
    for(index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
    fwrite(&library[filecount], size, count-filecount, pbooks);
  } else
    puts("No books? Too bad.\n");

  puts("Bye.\n");
  fclose(pbooks);

  return 0;
}

/**
 * @brief 
 * 首先以a+b模式打开文件，允许程序读取整个文件并在文件末尾添加内容，程序将使用二进制格式
 * fwrite和fread函数使用二进制文件
 * rewind函数确保指针位于文件开始出，为读文件做好准备
 * 
 */
