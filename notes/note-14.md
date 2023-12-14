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
