// 数据被存储在何处
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char * pcg = "String Literal";

int main(void)
{
  int auto_store = 40;
  char auto_string [] = "Auto char Array";
  int *pi;
  char * pc1;

  pi = (int *) malloc(sizeof(int));
  *pi = 35;
  pc1 = (char *) malloc(strlen("Dynamic String") + 1);
  strcpy(pc1, "Dynamic String");

  printf("static_store = %d at %p\n", static_store, &static_store);
  printf("auto_store = %d at %p\n", auto_store, &auto_store);
  printf("*pi = %d at %p\n", *pi, pi);
  printf("pcg = %s at %p\n", pcg, &pcg);
  printf("pc1 = %s at %p\n", pc1, pc1);
  printf("auto_string = %s at %p\n", auto_string, &auto_string);

  free(pi);
  free(pc1);
  return 0;
}

/** result:
static_store = 30 at 0x1004a8000
auto_store = 40 at 0x16f95ef68
*pi = 35 at 0x138e06c80
pcg = String Literal at 0x1004a8008
pc1 = Dynamic String at 0x138e06bf0
auto_string = Auto char Array at 0x16f95ef70
 */
