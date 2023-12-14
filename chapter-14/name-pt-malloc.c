/**
 * 使用指针与malloc
 */

#include <stdio.h>
#include <string.h> /* strlen() strcpy()*/
#include <stdlib.h> /* malloc() free()*/
#include "util.h"
#define SLEN 81

struct namect {
  char * fname;
  char * lname;
  int letters;
};

void getinfo(struct namect *); /* malloc */
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *); /* free*/

int main(void)
{
  struct namect person;

  getinfo(&person);
  makeinfo(&person);
  showinfo(&person);
  cleanup(&person);

  return 0;
}

void getinfo(struct namect * pst)
{
  char temp[SLEN];
  printf("Please enter your first name.\n");
  s_gets(temp, SLEN);
  /* malloc，分配内存以存储名 */
  pst->fname = (char *) malloc(strlen(temp) + 1);
  /* copy，把名拷贝到动态分配的内存中 */
  strcpy(pst->fname, temp);
  printf("Please enter your last name.\n");
  s_gets(temp, SLEN);
  pst->lname = (char *) malloc(strlen(temp) + 1);
  strcpy(pst->lname, temp);
}

void makeinfo(struct namect * pst)
{
  pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect * pst)
{
  printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect *pst)
{
  free(pst->fname);
  free(pst->lname);
}
