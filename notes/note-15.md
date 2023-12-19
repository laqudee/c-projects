> 位操作

- ~ & | ^
- << >>
- ~ 逐位取反
- & 逐位与，都为1时才为1；其它都是0
- | 逐位或，都为0时才是0；其它都是1
- ^ 逐位异或，相同为0，不同为1

- << 左移
- `>>` 右移
- 位运算符，位字段

- 二进制数、位、字节

- 1字节8位
- 1字节中，编号为7的位被称为高阶位
- 编号为0的被称为低阶位

- 有符号整数，sign-magnitude，最高位表示正负符号1为负，0为正数

- 二进制补码，得到一个二进制补码的相反数  
- 正数的二进制补码和其原码相同，负数的二进制补码是其原码的反码加1

- 二进制反码，通过反转位组合中的每一位形成负数

- 二进制浮点数
  - 二进制小数
  - 二进制指数

- 八进制、十六进制

- 八进制，8为基数
- 十六进制，16为基数

- 4个按位逻辑都用于整型数据包括char，与逻辑运算符&&、 ｜｜ ！不同

- 掩码mask
  - 按位与运算常用于掩码，即指的是一些设置为开1或关0的位组合

- 打开位
- 关闭位
- 切换位
- 检查位的值

- 移位运算符
  - 左移 << 将其左侧运算符对象每一位的值都向左移动其右侧对象指定的位数
  - 右移 >> 将其左侧运算符对象每一位的值都向右移动其右侧对象指定的位数

- 位字段 bit field
  - 位字段是一个signed int 或 unsigned int类型变量中的一组相邻的位
  - 通过一个结构声明来建立，该结构声明为每个字段提供标签，并确定该字段的宽度

```c
struct {
  unsigned int autfd: 1;
  unsigned int bldfc: 1;
  unsigned int undln: 1;
  unsigned int itals: 1;
} prnt;

struct {
  unsigned int code1: 2;
  unsigned int code2: 2;
  unsigned int code3: 8;
} prcode;

prcode.code1 = 0;
prcode.code2 = 3;
prcode.code3 = 102;
```

- 要确保所赋的值不超过字段可容纳的范围

- 把字段作为一种更紧凑储存数据的方式

- 可以使用单独的变量或全长full-size结构成员来表示每个属性，但浪费位

- 一种方案是：一个字节储存方框内部（透明和填充色）的属性，一个字节储存方框边框的属性，每个字节中的空隙用未命名字段填充

```c
struct box_props {
  bool opaque: 1;
  unsigned int fill_color: 3;
  unsigned int: 4;
  bool show_border: 1;
  unsigned int border_color: 3;
  unsigned int border_style: 2;
  unsigned int: 2;
};
```

- 对齐特性
  - C11的对齐特性比用位填充字节更自然，还代表C在处理硬件相关问题的能力

- 对齐指的是如何安排对象在内存中的位置
- 位了效率最大化，系统可能要把一个double类型的值存储在4字节内存地址上，但char却可以存储在任意位置地址。

```c
size_t d_align = _Alignof(float);
```

- 对齐值都应该是2的非负整数次幂
- 较大的对齐值称为stricter或stronger
- 较小的对齐值称为weaker

```c
_Alignas(double) char c1;
_Alignas(8) char c2;
unsigned char _Alignas(long double) c_arr[sizeof(long double)];
```

- `<stdalign.h>`

- `stdlib.h`添加了一个新的内存分配函数，用于对齐动态分配的内存

```c
void *aligned_alloc(size_t alignment, size_t size);
```

- 访问整数中单独位的能力
  - 一种方法是通过按位运算符
  - 一种方法是在结构中创建位字段
