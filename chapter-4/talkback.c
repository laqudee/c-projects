#include <stdio.h>
#include <string.h>  // 提供strlen()函数的原型
#define DENSITY 62.4 // 人体密度

int main()
{
    float weight, volume;
    int size, letters;
    char name[40]; // 是一个可容纳40个字符的数组
    printf("What is your name?\n");
    scanf("%s", name);
    printf("%s, How much do you weigh?\n", name);
    scanf("%f", &weight);
    size = sizeof name;
    letters = strlen(name);
    volume = weight / DENSITY;
    printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
    printf("You are %d letters long.\n", letters);
    printf("You are %d bytes long.\n", size);
    return 0;
}