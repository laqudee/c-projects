> 字符串和格式化输入/输出

- strlen()，给出字符串中的字符串长度
- const
- 字符串
- 创建、存储字符串
- C预处理指令#define

- 数组array存储字符串character string
- 字符串是一个或多个字符的序列，双引号仅告知编译器括起来的是字符串
- C没有专门用于存储字符串的变量类型，字符串都被存储在char类型的数组中
- 数组由连续存储单元组成
- 空字符null character \o，标记字符串的结束
  - 所以字符串类型的字符数最少是1
- 为什么使用数组存储字符串
  - 数组是同类型数据元素的有序序列

- scanf()只会读取字符串中的一个单词而不是一句
- fgets()用于读取一般字符串

- 基本类型char
- 派生类型char[size]

- sizeof 是给出容器的大小
  - 对于字符串字面量，它给出的包含空字符在内的长度，通常比strlen()给出的长度+1

- sizeof的圆括号的使用时机取决于运算对象是类型还是特定定量
  - 对于特定量，可有可无
  - 其他必须有sizeof(char), sizeof(float)

- 编译时替代compile-time substiution

- c_或k_前缀来表示常量

- `#define NAME value`

- const 关键字，用于限定一个变量为只读
  - `const int NAME = value`

- 明示常量，C库中会提供的一些定义好的常量，直接使用

- C预处理器非常有用

- printf scanf，输入输出函数，简称I/O函数

- %d, %c, %s 等被称为转换说明conversion specification
  - %a 浮点数，十六进制
  - %A 浮点数，十六进制
  - %c char
  - %d 有符号十进制整数
  - %e 浮点数，e计数法
  - %E 浮点数，e计算法
  - %f 浮点数，十进制
  - %g 根据值的不同，自动选择
  - %G 根据值的不同，自动选择
  - %i 有符号十进制整数
  - %o 无符号八进制整数
  - %p 指针
  - %s 字符串
  - %u 无符号十进制整数
  - %x 无符号十六进制整数
  - %X 无符号十六进制整数
  - %% 打印一个%

- 在%和转换字符之间插入修饰符可修饰基本的转换说明

- 底层类型

- printf函数中的float类型参数会自动转换为double类型
- 标记
  - - 待打印项左对齐
  - + 有符号值若为正，则在值前面显示加号；负数，加减号
  - 空格，同上，只是为正数时不显示加号
  - `#`
  - 0

- 参数传递
  - 因实现而异
  - 程序把传入的值放入被称为stack的内存区域

- print函数也有返回值，返回打印字符的个数。
  - 如果输出有误，prinf返回一个负值
  - 包括空格和不可见的换行符\n

- 使用 `\`换行，在printf中使用

- scanf(),
  - 变量需要使用&
  - 字符数组，不需要使用&

- scanf转换符
  - %c
  - %d
  - %e %f %g %a
  - %i
  - %o
  - %p
  - %s
  - %u
  - %x

- printf和scanf中的修饰符*
  