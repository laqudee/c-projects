# note 3
> data and c

- int short long unsigned char float double signed void _Bool _Complex _Imaginary
- sizeof()
- scanf()
- 整数类型与浮点数类型
- 常量与变量

- %.2f 种。.2用于精度控制，小数点后2位
- & 引用
- scanf

- signed 用于提供基本整数类型的变式，unsigned short int , long long int,
- char 字符，也可以表示较小的整数
- float、double、 long double
- _Bool表示布尔值true or false
- _Complex 表示复数
- _Imaginary 表示虚数

- 两大基本类型：
  - 整数类型
  - 浮点类型

- 存储单元：
  - bit 1
  - byte 8bit 256
  - word 8bit 16bit 32bit 64bit
    - 计算机的字长越大，其数据转移越快，允许的内存访问也更多

- 计算机把浮点数分为小数部分与指数部分，分开存储
- 浮点运算比整数运算慢

- int，有符号整型，最小是32位的
- 初始化变量
- 声明位变量创建和标记存储空间，并指定初始值

- 使用printf()函数时要确保转换说明的数量与待打印的数量相等
- oX 十六进制
- o 八进制
- 使用不同的进制是为了方便，并不影响存储方式
- %o 显式八进制 %#o
- &x 显式十六进制 %#x
  
- short int 类型 ，简写short 占用的存储空间比int类型小
- long int 或 long，占用空间比int多
- long long int 或 long long，至少占64位
- unsigned int 或 unsigned 只用于非负值的场合
  - 16位的允许的取值范围：0~65535
- unsigned long int
- unsigned int
- unsigned short
- unsigned long long

- 考虑unsigned类型。这种类型的数常用于计数，因为计数不用负数。而且，unsigned类型可以表示更大的正数
- 如果一个数超出了int类型的取值范围，且在long类型的取值范围内时，使用long类型
- 当需要32位的整数时，应当使用long类型， int
- 当需要64位的整数时，应当使用long long类型
- 当需要16位的整数时，应该使用short

- 32L后缀表示long类型
- LL 后缀表示 long long类型
- ull
- LLU

- 整数溢出

- %u 无符号类型输出
- %ld 打印long类型
- %lo
- %lx
- %hd 打印short类型
- %ho
- %hx
- %hl
- %hu
- %lu
- %lld
- %llu

- 使用printf()时，切记检查每个待打印值都有对应的转换说明，还要检查转换说明的类型是否与待打印的值的类型是否匹配

- char 类型从技术层面是整数类型，因为存储的是整数而非字符
  - 8位存储
  - 16位
  - 32wei

- 单引号是字符，双引号是字符串
- 16进制表示字符
  - `char beep = '\oo7'`
  - `char a = '\x10'`
- 打印字符
  - %c

- 有的C编译器将char表示为有符号类型，可表示范围-128~127
- 有的C编译器将char标识为无符号类型，0~255

- 可移植类型
  - stdint.h
  - inttypes.h

- 最小宽度类型
- 最快最小宽度类型

- float
- double
- long double

- %zd
- sizeof(type) // sizeof是C语言的内置运算符，以字节为单位给出指定类型的大小
  - sizeof(int) // 4bytes
  - sizeof(char) // 1byte
  - sizeof(long) // 4bytes
  - sizeof(long long) // 8bytes
  - sizeof(float) // 4bytes
  - sizeof(double) // 8bytes
  - sizeof(long double) // 16bytes
  - sizeof(_Bool) // 1byte

- 正确使用数据类型

- 注意参数陷阱