> 分支和跳转

- if else switch continue break case default goto
- && || ? :
- getchar() putchar() ctype.h
  - 字符分析头文件

- 即使if语句由符合语句构成，整个if语句仍被视为一条语句

- 字符输入/输出函数
  - getchar()，从输入队列中返回下一个字符
  - putchar()，打印它的参数
  - 预处理宏

- tolower(ch) // 返回小写字母
- toupper(ch) // 返回大写字母
- isalnum()
- isalpha()
- isblank()
- iscntrl()
- isdigit()
- isgraph()
- islower()
- isprint()
- ispunct()
- isspace()
- isupper()
- isxdigit()

- 如果没有花括号，else与离他最近的if匹配，除非最近的if被花括号括起来

- 逻辑运算符
  - &&
  - ||
  - !

- ios64.h头文件
  - and 替代 &&
  - or 替代 ||
  - not 替代 !

- C一直坚持试用版较少的关键字

- !运算符的优先级比乘法运算符高，与递增运算符相同，比括号运算符低
- &&运算符的优先级比||高，但都比关系运算符低，比赋值运算符高
  - `a>b && b>c || b>d`等同与
    - `((a>b) && (b>c)) || (b>d)`

- 除了两个运算符共享一个运算对象外，C不保证先对复杂表达式中哪部分求值

- 逻辑表达式的求值顺序是从左往右的
  - && ||都是序列点
  - 所以程序在从一个运算对象执行到下一个运算对象之前，所有的副作用都会生效

- && 可用于测试范围

- 条件运算符
  - ? :
  - `max = (a > b) ? a : b`

- continue语句
  - 执行到该语句时，会跳过本次迭代的省域部分，并开始下一轮迭代
  - 如果continue语句在嵌套循环内，则只会影响包含改语句的内层循环

- break语句
  - 终止当前递归，执行到下一个阶段

- 多重选择
  - switch & break

- switch 和 if else

- goto语句
  - goto
  - 标签名
  - 转跳到指定部分
  - 避免使用goto