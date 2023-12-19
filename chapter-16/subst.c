#include <stdio.h>
#include <math.h>
#define PSQR(x) printf("The square of "#x" is %d.\n", ((x)*(x)))
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x"#n "= %d\n", x##n);

/** 变参宏 */
#define PR(X,...) printf("Message" #X ":" __VA_ARGS__)

int main(void)
{
  int y = 5;
  PSQR(y);
  PSQR(2+4);

  int XNAME(1) = 14; /** 变成int x1 = 14; */
  int XNAME(2) = 20; /** 变成int x2 = 20; */
  int x3 = 30;

  PRINT_XN(1); /** 变成printf("x1 = %d\n", x1); */
  PRINT_XN(2);
  PRINT_XN(3);

  double x = 48;
  double y1;
  y = sqrt(x);
  PR(1, "x = %g\n", x);
  PR(2, "x = %.2f, y1 = .4f\n", x, y1);

  return 0;
}

/**
 * @brief output
 * x1= 14
 * x2= 20
 * x3= 30
 */
