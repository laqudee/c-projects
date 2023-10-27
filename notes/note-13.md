> 文件输入、输出

- fopen()/getc()/putc()/exit()/fclose()
- fprint()/fscanf()/fgets()/fputs()
- rewind()/fseek()/ftell()/fflush()
- fgetpos()/fsetpos()/feof()/ferror()
- ungetc()/setvbuf()/fread()/fwrite()

- I/O
- 文件模式、二进制模式
- 文本、二进制格式
- 缓冲与无缓冲I/O
- 顺序访问、随机访问

- 文件重定向

- file 文件是在磁盘或硬盘上的一段已经命名的存储区
- C把文件看作一系列连续的字节，每个字节都可以单独读取
  - 文本模型
  - 二进制模型

- 文本内容
- 二进制内容
- 文本文件格式
- 二进制文件格式

- 所有文件的内容都以二进制形式存储

- 如果文件中的二进制值代表机器语言代码或数值数据（使用相同的内部表示，假设，用于long或double类型的值）或图片或音乐编码，该文件就是二进制文件，其中包含二进制内容。

- \n 换行符
- \r 回车符

- 访问文件的途经：
  - 二进制模式，可以访问文件的每一个字节
  - 文本模式，程序所见的内容和文件的实际内容不同

- 以二进制模式读写文本文件

- I/O的两个级别
  - 底层I/O，使用操作系统提供的基本I/O
  - 标准高级I/O，使用C库提供的stdio.h头文件，可移植性；专门的函数；输入输出都是缓冲

- 标准文件
  - 标准输入
  - 标准输出
  - 标准错误输出

- 一次转移一大块信息而不是一字节信息

- `fopen(filename, mode) return *FILE`
  - 指针fp并不指向实际的文件，指向一个包含文件信息的数据对象，其中包含操作文件的I/O函数所用的缓冲区信息

| 模式字符串                   | 含义                                                                    |
| ---------------------------- | ----------------------------------------------------------------------- |
| "r"                          | 以读模式打开文件                                                        |
| "w"                          | 以写模式打开文件，把现有文件的长度截为0，若文件不存在，则创建一个新文件 |
| "a"                          | 以写模式打开文件，追加内容                                              |
| "r+"                         | 以更新模式打开文件，读写文件                                            |
| "w+"                         | 以更新模式打开文件，读写文件                                            |
| "a+"                         | 以更新模式打开文件，追加内容                                            |
| "rb", "wb", "ab", "ab+", ... | 二进制模式打开文件                                                      |
| "wx", "wbx", ...             | 独占模式                                                                |

- 如果使用任何一种"w"模式（不带x字母）打开一个现有文件，该文件的内容会被删除，以便程序在一个空白文件中开始操作。然而，如果使用带x字母的任何一种模式，将无法打开一个现有文件

- ch = getc(fp)，从fp指向的文件中获取一个字符
- putc(ch, fpout)
- EOF标记文件结尾

- fclose(fp)关闭fp指定的文件，必要时刷新缓冲区buffer
  - fclose(fp) return 0 or EOF

| 标准文件 | 文件指针 | 设备   |
| -------- | -------- | ------ |
| 标准输入 | stdin    | 键盘   |
| 标准输出 | stdout   | 显示器 |
| 标准错误 | stderr   | 显示器 |

- 用 指向FILE的指针指定一个文件或使用fopen的返回值
  - fprintf()
  - fscanf()
  - fgets()
  - fputs()


- 随机访问
  - fseek(*FILE, offset, mode) return int，将文件看作是数组
    - *FILE 文件指针
    - offset 从起点要偏移的距离
    - mode 模式 SEEK_SET SEEK_CUR SEEK_END
  - ftell() return long。返回当前的位置

- 处理较大文件的新定位函数
  - fgetpos(FILE * restrict stream, fpos_t * restrict pos)
  - fsetpos(FILE * stream, const fpos_t *pos)
  - fsetpos()
  - fpos_t文件定位类型

- I/O的工作原理
  1. 调用fopen()打开文件，并创建一个缓冲区以及一个包含文件和缓冲区数据的结构，返回该结构的指针；以文本模式打开就是一个文本流；以二进制模式打开就是二进制流
  - 结构包含
    - 一个指定流中当前位置的文件位置指示器
    - 包含错误和文件结尾的指示器
    - 一个指向缓冲区开始处的指针
    - 一个文件标识符
    - 一个计数
  2. 调用定义在stdio中的输入函数，fscanf() getc() fgets()；调用这些函数，文件中的数据库就被拷贝到缓冲区

- int ungetc(int c, FILE *fp)，把c指定的字符放回输入流中
- int fflush(FILE *fp)，刷新缓冲区
- int setvbuf(FILE * restrict fp, char * restrict buf, int mode, size_t size)，创建一个供标准I/O函数替代使用的缓冲区

- 二进制I/O
  - fread()
  - fwrite()

- 实际上，所有数据都是以二进制形式存储的，甚至连字符都是以字符码的二进制表示进行存储的

- 用二进制模式在二进制格式文件中存储二进制数据
- 以文本格式打开文本文件的文本数据

- size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE *restrict fp)

- size_t fread(void * restrict ptr, size_t size, size_t nmemb, FILE *restrict fp)

```c
char buffer[256];
fwrite(buffer, 256, 1, fp);

double earnings[10];
fwrite(earnings, sizeof(double), 10, fp);

// 该调用把10个double大小的值拷贝进earnings数组中
fread(earnings, sizeof(double), 10 ,fp);
```

- int feof(FILE *fp)
- int ferror(FILE *fp)

- 二进制I/O随机访问

