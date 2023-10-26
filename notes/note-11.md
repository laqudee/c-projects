> 字符串与字符串函数

- gets()
- gets_s()
- fgets()
- puts()
- fputs()
- strcat()
- strncat()
- strcmp()
- strncmp()
- strcpy()
- strncpy()
- strlen()
- strrev()
- strchr()
- strrchr()
- strspn()
- strcspn()
- strpbrk()
- strstr()
- strnlen()

- 字符串
- C库中的字符和字符串
- 命令行参数

- 读取、拷贝、比较、合并、查找

- 字符串时以空字符(`\0`)结尾的char类型数组

- 字符串字面量（字符串常量）

```c
char greeting[50] = "Hello, and"" how are" " you"
    " today!";
// 等价于
char greeting[50] = "Hello, and how are you today!";
```

- `\"`

- 字符串常量属于静态存储类型static storage class

- 字符串数组和初始化

- 数组和指针

- 字符串存储在静态存储区static memory

- 数组存储的位置即是地址
- 字符串字面量被视为const数据，所以指针也应为指向const的指针

- 初始化数组把静态存储区的字符串拷贝到数组中，初始化指针只把字符串的地址拷贝给指针

- 编译器可以把多次使用的相同字面量储存到一处或多处

- 如果不修改字符串，不要用指针指向字符串字面量

- 指针的值就是它存储的地址

- 分配空间

- gets()用于处理读取一行，puts

- gets()无法检查数组是否装得下一行

- 缓冲区溢出buffer overflow

- fgets()代替gets()
- gets_s()代替gets()

- 空字符，用于标记C字符串末尾的字符；整数类型；占一个字节
- 空指针，NULL，有一个值，该值不会与任何数据的有效地址对应；指针类型；地址占4个字节

- gets_s()没有fgets()方便

- scanf("%s", str)
- gets(str)
- fgets(str, sizeof(str), stdin)

- 字符串输出
  - puts
  - fputs
  - printf

- 自定义输入/输出函数
  - 利用getchar() 与 putchar()

++ 优先级高于*

- 字符串函数
  - strlen()，返回字符串长度
  - strcat()，连接字符串
  - strncat(bugs, addon, 13)
  - strcmp()
  - strncmp()
  - strcpy()
  - strncpy()
  - sprintf()