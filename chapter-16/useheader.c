#include <stdio.h>
#include "names_st.h"

/** 需要链接names_st.c */

int main(void)
{
  names candidate;
  get_names(&candidate);
  printf("Let's welcome");
  show_names(&candidate);
  printf(" to this program!\n");

  return 0;
}

/**
 * @brief 
 * gcc useheader.c names_st.c
 */
