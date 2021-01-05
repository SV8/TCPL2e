/*
问题：编写strncpy(s, t, n), strncat(s, t, n), 和 strncmp(s, t, n)函数，最多操作n个字符。例如：strncpy(s, t, n)从t到s拷贝最多n个字符。
*/

#include <stdio.h>

#define MAXSIZE 1000

int mystrncpy(char *s, char *t, int n);
int mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);

int main()
{
    char s[MAXSIZE];
    char t[] = "flowers";
    int result = mystrncpy(s, t, 6);
    printf("s:%s, t:%s, return:%d\n", s, t, result);

    char s1[] = "beautiful ";
    char t1[] = "flowers";
    int result1 = mystrncat(s1, t1, 4);
    printf("s1:%s, t1:%s, return:%d\n", s1, t1, result1);

    char s2[] = "beautiful";
    char t2[] = "beauty";
    int result2 = mystrncmp(s2, t2, 6);
    printf("s2:%s, t2:%s, return:%d\n", s2, t2, result2);
}

int mystrncpy(char *s, char *t, int n)
{
    int i = 0;
    while ((*s++ = *t++) != '\0')
    {
        if (i++ >= n - 1)
            return n;
    }
    return i;
}

int mystrncat(char *s, char *t, int n)
{
    int i = 0;
    while (*s++ != '\0') /* find end of s */
        ;
    s--;
    while ((*s++ = *t++) != '\0') /* copy t */
    {
        if (i++ > n - 2)
        {
            *s = '\0';
            return n;
        }
    }
    return i;
}

int mystrncmp(char *s, char *t, int n)
{
    for (int i = 0; (*s == *t) && (i < n-1); s++, t++, i++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}