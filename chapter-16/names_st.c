#include <stdio.h>
#include "names_st.h"

void get_names(names * pn)
{
  printf("Please enter your first name.\n");
  s_gets(pn->first, SLEN);
  printf("Please enter your last name.\n");
  s_gets(pn->last, SLEN);
}

void show_names(const names * pn)
{
  printf("%s, %s\n", pn->last, pn->first);
}

char * s_gets(char * st, int n)
{
  char * ret_val;
  char * find;
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    find = strchr(st, '\n');
    if(find)
      *find = '\0';
    else
      while(getchar() != '\n')
        continue;
  }
  return ret_val;
}
