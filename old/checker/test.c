#include<stdio.h>
#include<stdlib.h>

char *func()
{
    char *line;

    line = malloc(4);
    line[0] = 'a';
    line[1] = 'v';
    line[2] = '\0';
    return (line);
}
int main()
{
    char *str = func();
    printf("%c",str[1]);
}