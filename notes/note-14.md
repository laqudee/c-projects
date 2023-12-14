> struct、union 及其他类型

- `.`
- `->`
- - typedef

- 设计程序时，最重要的步骤就是选择表示数据的方法
- structure variable 
  - member or field
  - 声明一个适合该样式的变量
  - 访问结构变量的各个部分

```c
struct book {
    char title[50];
    char author[50];
    float value;
}
```

- 该声明只是描述了该对象由什么组成，并不创建实际的数据对象
- 模板

- 创建结构变量
  `struct book library;`
  - 编译器使用book模板为该变量分配空间

```c
struct book doyle, panshin, *ptbook; // ptbook是指向book类型的指针

struct book {
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
} library;
```

```c
int count = 0;
int fibo[7] = {0,1,1,2,3,5,8};

struct book library {
  "The Art of Computer Programming, Vol. 1",
  "Donald E. Knuth",
  1.95,
}
```

- 初始化结构
- 类别储存期的变量，必须使用常量值，结构也是如此。

- `.` 访问结构变量的各个部分
- `.`比`&`优先级高

- 结构的初始化访问期，designated initializer
  - 与数组类似，在指定初始化器后面的普通初始化器，为指定成员后面的成员提供初始值

```c
struct book suprise = { .value = 10.99 };
struct book gift = {
  .value = 25.99,
  .author = "Jane Doe",
  .title = "Gift",
};

struct book cgift = {
  .value = 25.99,
  .author = "Jane Doe",
  0.25
}; // 0.25将替代25.99
```

```c
struct book library;
library // 一个book结构的数组
library[2] // 一个数组元素，该元素是book结构
library[2].value // 访问数组元素
```

- 嵌套结构

- 指向结构的指针
  - 指向数组的指针比数组本身更容易操作，指向结构的指针比结构本身更容易操作
  - 早期的C实现中，结构不能作为参数传递给函数，但是可以传递指向机构的指针
  - 传递指针更高效
  - 一些用于表示数据的结构中也包含指向其它结构的指针

```c
struct book {};

struct book library = {};

struct book *ptlibrary;
ptlibrary = &library;
```

- 结构变量名不是结构的地址，因此要在结构变量名前加上&符号

- 访问成员
- `ptlibrary->author`
- `(*ptlibrary).author`

- &与*是一对互逆运算符
  - `fellow[0].income == *him.income == him->income`

- 向函数传递结构的信息

- 现在已经允许将结构作为参数传递给函数
- 传递结构成员，也可以将结构作为返回值返回

- C允许把一个结构赋值给另一个结构，但数组不能这样做

- 结构喝结构指针的选择
  - 指针作为参数的优点：执行起来很快，只需要传递一个地址；缺点：无法保护数据。在被调用的函数中其它操作可能会影响原来结构中的数据
  - 新增的const限定符解决了这个缺点
  - 结构作为参数传递的优点：函数处理的是原始数据的副本，保护了原始数据，代码风格更清晰；缺点：较老的版本无法处理，传递结构会浪费时间喝存储空间。尤其是大型结构传递给函数

- 结构中的字符数组和字符指针
- 如果要用结构体存储字符串，用字符串组作为成员比较简单。用指向char的指针也行，但是误用会导致比较严重的问题

- 结构、指针、malloc()
  - 使用malloc分配内存并示意哦那个指针存储该地址，那么在结构中使用指针处理字符串就比较合理
  - 优点：可以请求malloc为字符串分配合适的存储空间

```c
void getinfo(struct namect *pst)
{
  char temp[SLEN];
  printf("Please enter your first name. \n");
  s_gets(temp, SLEN);
  // 分配内存
  pst-fname = (char *) malloc(strlen(temp) + 1);
  // 复制
  strcpy(pst->fname, temp);
}
```

- 该字符串都未存储在结构中，存储在malloc分配的内存块中

- malloc() 与 free()配合使用

- 复合字面量和结构
- 复合字面量特性可用于结构和数组，如果只需要一个临时结构值，复合字面量很合适

```c
(struct book) {"The title", " The author", 6.99}
```

- 复合字面量在所有函数的外部，具有静态存储期；如果复合字面量在块中，则具有自动存储期。

- 伸缩型数组成员flexible array member
  - 该数组不会立即存在
  - 这个伸缩型数组成员可以编写合适的代码

- 伸缩型数组成员有如下规则：
  - 必须是结构的最后一个成员；
  - 结构中至少有一个成员；
  - 伸缩数组的声明类似普通数组，只是它的方括号中是空的

```c
struct flex {
  int count;
  double average;
  double scores[]; // 伸缩数组成员
}
```

- 伸缩型数组成员，不能用结构进行赋值或者拷贝，确实要拷贝，使用memcpy()函数
- 不能以按值方式把这种结构传递给结构
- 不要使用带伸缩型数组成员的结构作为作为数组成员或另一个结构的成员

- 匿名结构
  - 是一个没有名称的结构成员

```c
struct person {
  int id;
  struct {char first[20]; char last[20;]}; // 匿名结构
};

// 初始化
struct person joe = {123, {"Joe", "Smith"}};
```

- 使用结构数组的函数

- 把结构内容保存到文件中
  - fread()
  - fwrite(&primer, sizeof(struct book), 1, pbook);


- 链式结构
  - 每个结构都包含一两个数据项和一两个指向其它同类结构的指针

- 联合union
  - 是一种数据类型，能在同一个内存空间中存储不同的数据类型
  - 存储一些无规律，不知道顺序的混合类型

```c
union hold {
  int digit;
  float bigfl;
  char letter;;
};

// use
union hold fit;
union hold save[10];
union hold * pu;
```

- 可以初始化联合，但联合只能存储一个值，这与结构不同。初始化方法：
  - 把一个联合初始化为另一个同类型的联合；
  - 初始化联合的第一个元素
  - 使用指定初始化器

```c
union hold valA;
valA.letter = 'a';

union hold valB = valA; // 用另一个联合来初始化
union hold valC = {88}; // 初始化union的digit成员
union hold valD = {.bigfl = 118.2}; // 指定初始化器

// use
fit.letter = 'a';
fit.bigfl = 2.0;
```

- 用指针访问联合也要使用->运算符

- 匿名联合
  - 工作原理与匿名结构一样，是一个结构或联合的无名联合成员

- 枚举类型enum
  - 声明符号名称来表示整型常量

```c
enum day {SUN, MON, TUE, WED, THU, FRI, SAT};
```

- C枚举的一些特性并不适用于C++

- 枚举底层就是常量，在switch中可以把枚举常量作为标签
- 枚举的默认值是0，1，2，3...
- 枚举可以赋值

```c
enum levels = {low = 100, medium = 500, high = 2000};

enum feline = { cat, lynx = 10, puma, tiger}
// out: 0, 10, 11, 12
```

- enum的目的是为了提供程序的可读性和可维护性
