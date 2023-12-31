> C 预处理器和C库

- 预处理器
  - `#define`
  - `#include`
  - `#ifdef`
  - `#else`
  - `#endif`
  - `#ifndef`
  - `#if`
  - `#elif`
  - `#line`
  - `#line`
  - `#error`
  - `#pragma`

- 关键字
  - _Generic
  - _Noreturn
  - _static_assert

- 函数/宏
  - sqrt()
  - atan()
  - atan2()
  - exit()
  - atexit()
  - assert()
  - memcpy()
  - memmove()
  - va_start()
  - va_arg()
  - va_copy()
  - va_end()

- 通用选择表达式
- 内联函数
- 方便函数

- C语言建立在适当的关键字、表达式、语句以及使用它们的规则上
- C语言不仅描述C语言，还描述如何执行C预处理器、C标准有哪些函数，以及函数的工作原理

- C预处理器在程序执行之前查看程序（故称为预处理器）
- 基本上的工作就是把一些文本转为另外一些文本

- 在预处理之前，编译器必须对该程序进行一些翻译处理，编译器把源代码中出现的字符映射到源字符集

- 编译器定位每个反斜杠后面跟着换行符的实例，并删除它们。
- 编译器把文本划分成预处理记号序列、空白序列、注释序列

- `#define`明示常量

- `#define`指令 + 选定的缩写（宏）+ 替换体

- 类对象宏（object-like macro）

- 类函数宏（function-like macro）

- 一旦预处理器在程序中找到宏的实例后，就会用替换体代替该宏。
  - 从宏变成最终替换文本的过程为宏展开

- 宏常量可用于指定标准数组的大小和const变量的初始值

- 记号token
- token型字符串

- 字符型字符串和记号型字符串的处理方式不同

- 重定义常量，不同的实现采用不同的重定义方案

- `#undef`

- 在`#define`中使用参数
  - 但和函数调用完全不同

- 宏参数与函数参数不完全相同
  - 预处理器不做计算、不求值，只替换字符序列
  - 函数调用在程序运行时把参数的值传递给函数。宏调用在编译之前把参数记号传递给程序。这两个过程发生在不同时期。

- 可以使用足够多的括号来确保运算和结合的正确顺序

- 用宏参数创建字符串：`#`运算符

- `#define PSOR(X) printf("The square of X is %d.\n", ((X)*(X)));`

- `##运算符` ，可用于类函数宏的替换部分

- 变参宏
  - `...`
  - `__VA_ARGS__`

- `stdvar.h`

- 如何使用宏还是函数？
  - 使用宏比使用普通函数复杂一些，使用不当就会产生奇怪的副作用
  - 要在时间和空间上权衡
    - 宏生成内联代码，即在程序中生成语句。如果调用20次宏，即程序中插入20行代码。
    - 如果调用函数20次，程序中只有一份函数语句的副本，所以节省空间。
    - 但调用函数会花费更多时间

- 宏的一个优点是，不用担心变量类型（这是因为宏处理的是字符串，而不是实际的值）

- 宏名中不允许有空格，但替换体中可以有空格

- 当预处理器发现`#include`指令时，会查看后面的文件名并把文件的内容包含到当前文件中，即替换源文件中的`#include`指令。

```c
#include <stdio.h> // 在预处理器的标准系统目录中查找该文件
#include "mystuff.h" // 预处理器首先在当前目录中（或文件名中指定的其他目录）查找该文件，如果未找到再查找标准系统目录

#include "/usr/biff/p.h" // 查找/usr/biff目录
```

- 头文件
  - 明示常量
  - 宏函数
  - 函数声明
  - 结构模板定义，标准I/O函数使用FILE结构
  - 类型定义，指向FILE结构的指针作为参数

- 程序可以通过修改`#define`指令的值即可生成可移植的代码
- `#undef`指令取消之前的`#define`定义

```c
#define LIMIT 400

#undef LIMIT // 取消LIMIT宏
```

- 条件编译
  - 告诉编译器根据编译时的条件执行或忽略信息块

```c
#ifdef MAVIS
  #include "horse"
  #define STABLES 5
#else
  #include "cow.h"
  #define STABLES 15
#endif
```

- `#ifdef #else`与if else的区别：
  - 预处理器不识别用于标识块的花括号（{}）

- `#ifndef`指令
  - 判断后面的标识符是否是未定义的，常用于定义之前未定义的常量

```h
#ifndef SIZE
  #define SIZE 100
#endif
```

- `#if`与`#elif`的区别：
  - `#if`后面跟整型常量表达式，如果表达式为非零，则表达式为真

- 预定义宏
  - `__DATE__`
  - `__FILE__`
  - `__LINE__`
  - `__TIME__`
  - `__STDC__`
  - `__STDC_HOSTED__`
  - `__STDC_VERSION__`

- `#line`指令重置__LINE__和__FILE__宏报告的行号和文件名

```c
#line 1000 // 把当前行号重置为1000
#line 10 "cool.c" // 把行号重置为10， 把文件名重置为cool.c
```

- `#error`指令让预处理器发出一条错误消息

```c
#if __STDC_VERSION__ != 201112L
#error Not C11
#endif
```

- `#pragma`指令把编译器指令放入源代码中

```c
#pragma c9x on
```

- 范型选择，指那些没有特定类型，但是一旦指定一种类型，就可以转换成指定类型的代码。

- 内联函数
  - inline function
  - 把函数变成内联函数建议尽可能快的调用该函数

- 使用函数说明符inline和存储类别说明符static

```c
#include <stdio.h>
inline static void eatline() // 内联函数定义/原型
{
  while(getchar() != '\n')
    continue;
}

int main(void)
{
  eatline();
}
```

- 编译器查看内联函数的定义（也是原型），可能会用函数体中的代码替换eatline()函数调用。
- inline
- extern
- _Noreturn，函数说明符

- 访问C库
  - 自动访问
  - 文件包含
  - 库包含

- 数学库


- 类型变体
  - sqrtf()是sqrt()的float版本
  - sqrtl()是sqrt()的long double版本

- C11新增了范型选择表达式定义一个范型宏，根据参数类型选择最适合的数学函数版本
  - _Generic表达式是实现tgmath.h最简单的方式

- tgmath.h头文件中定义了范型类型宏

- 通用工具库
  - `stdlib.h`

- exit()
- atexit(Fn *)，通过退出时注册被调用的函数提供


- qsort()函数，快排，对于大型数组而言，快速排序方法是最有效的排序算法之一
  - 首先将数组分为两部分，一部分的值小于另一部分的值，循环这个过程

```c
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
```

- 函数名作为参数时即是指向该函数的指针

- C与C++都可以将任何类型的指针赋给void类型的指针。但是C++要求在把void*指针赋给任何类型的指针时必须进行强制类型转换，而C不需要这样的要求

- 断言库
  - assert()

- _Static_assert声明，可以在编译时检查assert()表达式

- string.h库中的memcpy()和memmove()
  - 不能把一个数组赋给另一个数组，所以要通过循环把数组中的每个元素赋给另一个数组相应的元素
  - strcpy()
  - strncpy()

- 可变参数：stdarg.h
  - 提供一个使用省略号的函数原型
  - 在函数定义中创建一个va_list类型的变量
  - 用宏把该变量初始化为一个参数列表
  - 用宏访问参数列表
  - 用宏完成清理工作

```c
void f1(int n, ...); // 有效
int f2(const char * s, int k, ...); // 有效
char f3(char c1, ..., char c2); // 无效，省略号不在最后
double f3(...);// 无效，没有形参
```

