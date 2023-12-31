> 存储类别、链接、内存管理

- 变量的作用域（可见范围）、生命周期
- 更复杂的程序
- 合理使用内存存储的数据

- auto、extern、static、const、register、volatile
- restricted、_Thread_local、_Atomic

- 多种不同的模型或存储类别storage class在内存中存储数据

- 对象即内存，可以存储一个或多个值

- 面向对象编程中的对象指的是类对象，其定义包括数据和允许对数据进行的操作，C不是面向对象的

- 标识符

- 可以用存储期storage duration描述对象，所谓存储期是指对象在内存中保留了多长时间

- 作用域scope
- linkage 链接

- 标识符的作用域和链接表明了程序的哪些部分可以使用它。不同的存储类别具有不同的存储期、作用域和链接

- 对象可存在于程序的执行期，也可以仅存在于它所在函数的执行期。对于并发编程，对象可以在特定线程的执行期存在。可以通过函数调用的方式显式分配和释放内存

- 作用域描述程序中可访问标识符的区域
  - 块作用域
  - 函数作用域，function scope仅用于goto语句的标签
  - 函数原型作用域， 用于函数原型中的形参名；作用范围从定义形参到原型声明结束
  - 文件作用域（全局变量globa variable），变量的定义在函数的外面

- C99放宽了块作用域变量都必须声明在块的开头的规定，可以放在块中的任何位置声明变量

编译器源代码文件和所有的头文件都看成是一个包含信息的单独文件。这个文件被称为翻译单元（translation unit）

- 翻译单元translation unit
  - 描述一个具有文件作用域的变量时，它的实际可见范围是整个翻译单元。如果程序由多个源代码文件组成，那么该程序也将由多个翻译单元组成。每个翻译单元均对应一个源代码文件和它所包含的文件

- 链接
  - 外部链接
  - 内部链接
  - 无链接，具有块作用域、函数作用域或函数原型作用域的变量都是无链接变量

- 具有文件作用域的变量可以是外部链接或内部链接

- 外部链接变量可以在多个文件程序中使用
- 内部链接变量只能在一个翻译单元中使用

- 文件作用域
- 全局作用域（程序作用域）

```c
int giants = 5; // 文件作用域，外部链接
static int dodgers = 3; // 文件作用域, 内部链接

int main(void) {}
```

- 作用域和链接描述了标识符的可见性
- 存储期描述了通过这些标识符访问的对象的生存期（生命周期）

- 存储期
  - 静态存储期，程序的执行期间一直存在；文件作用域具有静态存储期；
  - 线程存储期，_Thread_local
  - 自动存储期，块作用域变量具有自动存储期，局部变量都是自动存储期
  - 动态分配存储期

- static表明了其链接属性，而非存储期

- 变成数组的存储期从声明处到块的末尾，而不是从块的开始到块的末尾

- 自动
- 寄存器，register
- 静态块作用域
- 静态外部链接
- 静态内部链接

|   存储类型   | 存储期 | scope | linkage |           声明方式           |
| :----------: | :----: | :---: | :-----: | :--------------------------: |
|     自动     |  auto  |  块   |   无    |             块内             |
|    寄存器    |  auto  |  块   |   无    |   块内，使用关键字register   |
|  静态无链接  | static |  块   |   无    |    块内，使用关键字static    |
| 静态外部链接 | static | 文件  |  外部   |          所有函数外          |
| 静态内部链接 | static | 文件  |  内部   | 所有函数外，使用关键字static |

- auto variable
  - 属于自动存储类别的变量具有自动存储期、块作用域且无链接
  - 声明在块或函数头中的任何变量都属于自动存储类型

- 存储类别说明符

```c
int main(void)
{
    auto int plox; //C++/C不兼容，不用使用
}
```

- 变量具有自动存储期，说明程序在进入该变量声明所在的块时变量存在，程序退出该块时，变量消失

- 内层块会隐藏外层块的定义

- 循环体是整个循环块的子块

- 非常量表达式non-constant expression

- 寄存器变量储存在寄存器中而非内存中，所以无法获取寄存器变量的地址

```c
void macho(register int n) // 形参为寄存器变量

int main(void)
{
    register int quick;
}
```

- 静态的意思是该变量在内存中原地不动，并不是说他的值不变

- 这是因为静态变量和外部变量在程序被载入内存时已执行完毕

- 函数形参不允许使用static修饰

- 外部链接的静态变量具有文件作用域、外部链接、静态存储期

- 外部存储类别
- 外部变量

- extern声明

```c
int Errupt; // 外部定义的变量
double Up[100]; // 外部定义的数组
extern char Coal; // 如果Coal被定义在另一个文件，则必须这样声明

int main(void)
{
    extern int Errupt; // 可选的声明
    extern double Up[100]; // 可选的声明
}
```

- 初始化外部变量

- 不要用extern创建外部定义，只用它引用现有的外部定义

- 内部链接的静态变量：存储类别的变量具有静态存储期、文件作用域和内部链接

- 只有当程序由多个翻译单元组成时，才体现区别内部链接和外部链接的重要性

- 如果外部变量定义在一个文件中，那么其他文件在使用该变量之前必须先声明它（用 extern关键字）

- 关键字static和extern的含义取决于上下文
  - auto，变量自动存储期，只能用于块作用域的变量生命中
  - register，只用于块作用域的变量，它把变量归为寄存器存储类别，请求最快速度访问该变量。同时，还保护了该变量的地址不被获取
  - static，具有静态存储期
  - extern，表明声明的变量定义在别处
  - _Thread_local
  - typedef，与任何内存存储无关

- 绝大多数情况下，不能在声明中使用多个存储类别说明符
- 唯一例外的是_Thread_local，它可以和static或extern一起使用。

- 函数的存储类别
  - 外部函数
  - 静态函数， 只能用于其定义所在的文件
  - 内联函数，用 extern 关键字声明定义在其他文件中的函数

```c
double gamma(double); // 默认为外部函数
static double beta(int,int); // 静态函数
extern double delate(double, int); 
```

- 保护性程序设计的黄金法则：按需知道原则。
  - 尽量在函数内部解决该函数的任务，只共享那些需要共享的变量。除自动存储类别外，其他存储类别也很有用。

- 随机数函数与静态变量

- time()

- malloc()
- free()

- 库函数分配和管理内存
- 所有程序都必须预留足够的内存来存储程序使用的数据，内存中有些是自动分配。

- malloc(int byte)函数，可以在程序运行时分配更多的内存

- malloc()分配内存但不会为其赋名，返回动态分配内存块的首字节地址；char

- 指向void的指针，相当于通用指针

- malloc()可用于返回数组的指针、指向结构的指针；分配内存失败，将返回空指针

```c
double *ptd;
ptd = (double *) malloc(30 * sizeof(double));
// 30个double型的内存块，并设置ptd指向该位置

double item[n];
ptd = (double *) malloc(n * sizeof(double));
```

- malloc()与free()配合使用；

- free()函数的参数是之前malloc()返回的地址，该函数释放之前malloc()分配的内存

- 动态分配内存的存储期从调用malloc()开始到free()结束

- exit()函数，用于退出程序，stdlib.h

- EXIT_FAILURE()的值也在stdlib.h中

- C中不一定要使用强制类型转换(double *)，但是在C++中必须使用

- free()位于程序的末尾，释放malloc()分配的内存

- 静态内存的数量在编译时是固定的，在程序运行期间也不会改变
- 自动变量使用的内存数量在程序执行期间自动增加或减少
- 动态分配的内存数量只会增加，除非用free()释放

- 忘记free，会造成内存泄露memory leak

- calloc(size, sizeof (type))
  - 返回指向char，指向void指针

- calloc()把块中的所有位都设置为0

- free()释放

```c
long * newmem;
newmem = (long *) calloc(100, sizeof (long));
```

- 动态内存分配
- 变长数组VLC，自动存储类型

- VLC和调用malloc()在功能上有些重合

```c
int vlamal()
{
  int n;
  int * pi;
  scanf("%d", &n);
  pi = (int *) malloc(n * sizeof(int));
  int ar[n]; // 变长数组
  pi[2] = ar[2] = -5;

  free(pi);
}
```

```c
int n = 5;
int m = 6;

int ar2[n][m]; // 变长数组
int (* p2)[6];
int (* p3)[m];

p2 = (int (*)[6]) malloc(n * 6 * sizeof(int)); // n x 6数组
p3 = (int (*)[m]) malloc(n * m * sizeof(int)); // n x m数组

ar[1][2] = p2[1][2] = 12;
```

- 存储类别与动态内存分配
  - 静态存储类别所用内存编译时确定，程序结束时被销毁
  - 自动存储类别，程序离开块时销毁，栈内存；
  - 动态分配的内存调用malloc()分配，调用free()释放，由程序员管理。这部分内存比较破碎

- 使用动态内存通常比栈内存慢

- 程序将静态对象、自动对象、动态分配的对象储存在不同的区域

- 静态数据占用一个区域
- 自动数据占用另一个区域
- 动态分配的数据占用自由内存

- 恒常性constancy，const
- 易变性volatility，volatile

- 限定类型

- restrict

- _Atomic

- stdatomic.h

- 幂等性idempotent
  - 多次使用同一限定符，多余的限定符将被忽略

- 在指针和形参声明中使用const
  - 限定指针本身还是限定指针指向的值为const

```c
const float *pf; // 创建了pf指向的值不能被改变，pf本身的值可以改变
// 等同于上面
float const *pf;
float * const pt; // *pt是一个const指针，pt指向的值可以被改变 

const float * const ptf; // 都不可以改变

const int array [];
// 等同于
const int * array;
```

- 在一个文件中定义，在其他文件中使用extern 引用
- 头文件中使用static const

- volatile限定符，代理可以改变变量的值，通常用于硬件地址以及在其他程序或同时运行的线程中共享数据

```c
volatile int loc1; // 定义一个易变的位置
volatile int *ploc; // *ploc是一个指向易变的位置的指针
```

- 编译器优化

- 高速缓存

- restrict允许编译器优化某部分代码以更好的支持计算
  - 只能用于指针

```c
int ar[10];
int *restrict restar = (int *) malloc(10 * sizeof(int));
int *par = ar;
```

- 指针restar是访问由malloc()所分配内存的唯一且初始的方式

- restrict限定符还可用于函数形参中的指针

```c
void *memcpy(void *restrict s1, const void *restrict s2, size_t n);
void *memmove(void *s1, const void *s2, size_t n);
```

- _Atomic类型
- 原子类型
- 一个线程对一个原子类型的对象执行原子操作时，其他线程不能访问该对象

```c
_Atomic int hogs; // 定义一个原子类型的变量
atomic_store(&hogs, 0); // 原子操作
```

- 旧关键字的新位置

```c
// c99之前
void ofmouth(int *const a1, int * restrict a2, int n);

// c99
void ofmouth(int a1[const], int a2[restrict], int n);
// 根据新标准，在声明函数形参时，指针表示法和数组表示法都可以使用这两个限定符
```

- 内存用于存储程序中的数据，由存储期、作用域、链接表征

- 存储期可以是静态的、自动的或动态分配的

- malloc()、free()

- 作用域决定程序在哪些部分可以访问的数据
  - 函数之外定义的，文件作用域
  - 函数之内、块之内的，块作用域

- 链接描述定义在程序某翻译单元中的变量可被链接的程度。

- 具有块作用域的变量是局部变量，无链接。
- 具有文件作用域的变量可以是内部链接或外部链接。
- 内部链接意味着只有其定义所在的文件才能使用该变量。
- 外部链接意味着其他文件使用也可以使用该变量。

- 存储类别
  - 自动
  - 寄存器
  - 静态、无链接
  - 静态、外部链接
  - 静态、内部链接
  - 动态分配