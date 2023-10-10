// 统计字符数、单词数、行数
#include <stdio.h>
#include <ctype.h>   // 为isspace函数提供原型
#include <stdbool.h> // 为bool、true、false提供定义
#define STOP '|'

int main(void)
{
    char c;    // 读入字符
    char prev; // 上一个字符
    long n_chars = 0L;
    int n_lines = 0;
    int n_words = 0;
    int p_lines = 0;
    bool inword = false; // 如果字符char在单词中，inword等于true
    printf("Enter text to be analyzed(| to terminate):\n");
    prev = '\n'; // 用于识别完整的行
    while ((c = getchar()) != STOP)
    {
        n_chars++;
        if (c == '\n')
            n_lines++;
        if (!isspace(c) && !inword)
        {
            inword = true;
            n_words++;
        }
        if (isspace(c) && inword)
            inword = false;
        prev = c;
    }
    if (prev != '\n')
        p_lines = 1;
    printf("characters = %ld, words = %d, lines = %d, paragraphs = %d\n", n_chars, n_words, n_lines, p_lines);
    return 0;
}
