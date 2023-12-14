#include <stdio.h>
#define FUNDLEN 50

struct funds {
  char bank[FUNDLEN];
  double bankfund;
  char save[FUNDLEN];
  double savefund;
};

double sum(struct funds moolah); /*参数是一个struct*/

int main(void)
{
  struct funds stan = {
    .bank = "Garlic-Melon Bank",
    .bankfund = 4032.27,
    .save = "Lucky's Saving and Loan",
    .savefund = 8543.94
  };

  printf("Stan has a total of $%.2f.\n", sum(stan));

  return 0;
}

double sum(const struct funds moolah)
{
  return (moolah.bankfund + moolah.savefund);
}

/**
 * @brief 
 * 调用sum函数时，编译器根据funds模板创建一个名为moolah的自动结构变量，
 * 然后该变量的各个成员被初始化为stan结构变量相应的值的副本
 * 因此程序使用原来结构的副本进行计算
 */
