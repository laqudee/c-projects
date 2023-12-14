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
