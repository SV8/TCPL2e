
/*
问题：编写一个程序，该程度将输入流中的小写字母转换为大写字母，或者将大写字母转换为小写字母，具体行为用参数argv[0]决定。
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //printf("argc:%d, argv[0]:%s, strcmp(argv[0], \"./upper\"):%d\n", argc, argv[0], strcmp(argv[0], "./upper"));
    int c;
    while ((c = getchar()) != EOF)
    {
        if (strcmp(argv[0], "./lower") == 0)
            putchar(tolower(c));
        else if (strcmp(argv[0], "./upper") == 0)
            putchar(toupper(c));
    }
    return 0;
}

