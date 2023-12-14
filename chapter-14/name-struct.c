#include <stdio.h>
#include <string.h>
#include "util.h"
#define NLEN 30

struct namect {
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);

int main(void) {
    struct namect person;

    person = getinfo();
    person = makeinfo(person);
    showinfo(person);

    return 0;
}

struct namect getinfo(void)
{
  struct namect temp;
  printf("Enter first name: ");
  s_gets(temp.fname, NLEN);
  printf("Enter last name: ");
  s_gets(temp.lname, NLEN);

  return temp;
}

struct namect makeinfo(struct namect info)
{
  info.letters = strlen(info.fname) + strlen(info.lname);

  return info;
}

void showinfo(struct namect info)
{
  printf("%s, %s ", info.lname, info.fname);
  printf("Number of letters: %d\n", info.letters);
}
