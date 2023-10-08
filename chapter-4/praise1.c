#include <stdio.h>
#include <string.h>
#define PRAISE "You are an extraordinary being."

void praise2(void);

int main()
{
    char name[40];
    printf("What is your name?\n");
    scanf("%s", name);
    printf("%s, %s\n", name, PRAISE);

    praise2();

    return 0;
}

void praise2(void)
{
    char name[40];
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello %s, %s\n", name, PRAISE);
    printf("Your name of %zd letters occupies %zd memory cells. \n", strlen(name), sizeof name);
    printf("The phrase of praise2 has %zd letters.\n", strlen(PRAISE));
    printf("The phrase of praise2 occupies %zd memory cells.\n", sizeof PRAISE);
}