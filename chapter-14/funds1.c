#include <stdio.h>
#define FUNDLEN 50

struct funds {
  char bank[FUNDLEN];
  double bankfund;
  char save[FUNDLEN];
  double savefund;
};

double sum(const struct funds *); /*参数是一个指针*/

int main(void)
{
  struct funds stan = {
    .bank = "Garlic-Melon Bank",
    .bankfund = 4032.27,
    .save = "Lucky's Saving and Loan",
    .savefund = 8543.94
  };

  printf("Stan has a total of $%.2f.\n", sum(&stan));

  return 0;
}

double sum(const struct funds *money)
{
  return (money->bankfund + money->savefund);
}
