> 字符输入/输出
> 输入验证

- I/O函数 printf, scanf, getchar(), putchar()

- getchar()和putchar()每次只处理一个字符

- buffer缓冲区
  - 八若干字符作为一个块进行传输比逐个发送这些字符节约时间

- 完全缓冲I/O
  - 指的是当缓冲区被填满时才刷新缓冲区（文件输入）
- 行缓冲I/O
  - 出现换行符时刷新缓冲区（键盘输入）

- buffer大小取决于系统
  - 512字节
  - 4096字节

- 文件file是存储器中存储信息的区域

- 打开、读取、写入和关闭文件的库函数

- 底层I/O low-level I/O
- 标准I/O standard I/O

- C处理的是流而不是直接处理文件
- 流stram是一个实际输入或输出映射的理想化数据流

- stdin 键盘输入
- stdout 键盘输出
- stderr 错误输出

- getchar()
- putchar()
- printf()
- scanf()

- EOF 文件结尾符

- UNIX 文件结尾 Ctrl+d
- Windows 文件结尾 Ctrl+z

- 默认情况下，C使用标准I/O包查找标准输入

- 重定向的一个主要问题与操作系统相关与C无关

```shell
.\echo_eof > mywords.txt
[enter you words]
[ctrl+d or ctrl+z]
```

- `>`重定向符号，将标准输出重定向到文件
- `<`重定向符号，将标准输入重定向到文件
- `>>`重定向符号，将标准输出重定向到文件，将标准输入重定向到文件