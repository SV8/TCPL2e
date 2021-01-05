/*
问题：编写strend(s, t)函数，如果t出现在了s的末尾，则返回1，否则返回0。
*/

#include <stdio.h>


int strend(char *s, char *t);

int main()
{
    char s[] = "hello, world!";
    char t[] = "world!";
    printf("%d\n", strend(s, t));
}

int strend(char *s, char *t)
{
    char *ts = t;
    while (*s++ != '\0')
        // printf("*s:%c\n", *(s-1));
        ;
    while (*t++ != '\0')
        // printf("*t:%c\n", *(t-1));
        ;
    s--; t--;
    while (t >= ts)
    {
        if (*s-- != *t--)
            return 0;
    }
    return 1;
}