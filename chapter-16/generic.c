/** 定义范型宏 */
#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG (180/(4*atan(1)))

/**  范型平方根函数 */
#define SQRT(X) _Generic((X), long double: sqrtl, default: sqrt, float: sqrtf)(X)

/** 范型正弦函数，角度的单位为度 */
#define SIN(X) _Generic((X), long double: sinl((X)/RAD_TO_DEG), default: sin((X)/RAD_TO_DEG), float: sinf((X)/RAD_TO_DEG))

int main(void)
{
  float x = 45.0f;
  double xx = 45.0;
  long double xxx = 45.0L;
  long double y = SQRT(x); // 匹配float
  long double yy = SQRT(xx); // 匹配default
  long double yyy = SQRT(xxx); // 匹配long double
  printf("%.17Lf %.17Lf %.17Lf\n", y, yy, yyy);

  int i = 45;
  yy = SQRT(i); // 匹配default
  printf("%.17Lf\n", yy);

  yyy = SIN(xxx); // 匹配 long double
  printf("%.17Lf\n", yyy);

  return 0;
}
