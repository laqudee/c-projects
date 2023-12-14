#include <stdio.h>
#define LEN 20

const char *msgs[5] = {
  "Thanks you",
  "You certa",
  "is a special",
  "over a delicious",
  "and have a few laughs"
};

struct names {
  char first[LEN];
  char last[LEN];
};

struct guy {
  struct names handle;
  char favfood[LEN];
  char job[LEN];
  float income;
};

int main(void) {
  struct guy fellow = {
    .handle = {
      "Ewen",
      "Villard"
    },
    .favfood = "pizza",
    .job = "driver",
    .income = 5000.00
  };

  printf("Dear %s,\n \n", fellow.handle.first);
  printf("%s%s. \n", msgs[0], fellow.handle.first);
  printf("%s%s \n", msgs[1], fellow.job);
  if (fellow.income > 3000.0)
    puts("!!");
  else if (fellow.income > 1000)
    puts("!");
  else
    puts(".");

  return 0;
}
