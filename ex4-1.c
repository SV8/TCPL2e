/*
问题：编写函数strindexrt(s, t)，其返回值是字符串t在s中最右侧出现的位置。例如：
s = "axyzaaxyzaaaxyz", t = "xyz"
strindex(s, t) = 12
算法描述：
1.将s做reverse操作得到s1
2.将t做reverse操作得到t1
3.用书上例子的strindex(s1, t1)得到t1出现在s1中最左侧的位置
4.s1的长度减去s2的长度即为所求
该算法的副作用是s和t都会被reverse
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int ngetline(char s[], int lim);
int strindex(char source[], char searchfor[]);
void reverse(char s[]);
int putline(char line[]);
char pattern[] = "xyz";

int main()
{
    char line[MAXLINE];
    int found = 0;
    int index;
    while (ngetline(line, MAXLINE) > 0)
    {
        if ((index = strindex(line, pattern)) >= 0)
        {
            printf("Found at index %d\n", index);
            found++;
        }
    }
    return found;
}

/* getline: get line into s, return length */
int ngetline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    // if (c == '\n')
    //     s[i++] = c;
    // s[i] = '\0';
    return i;
} 

/* strindex: return rightmost index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    reverse(s);
    reverse(t);
    // putline(s);
    // putline(t);
    int i, j, k;
    for (i = 0; s[i] != '\0' && i < strlen(s); i++)
    {
        for (j = i, k = 0; t[k] != '\0' && k < strlen(t) && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return strlen(s) + i - strlen(t);
    }
    return -1;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int putline(char line[]) {
    int c;
    int i;
    i = 0;
    while ((c = line[i]) != '\0')
    {
        putchar(c);
        ++i;
    }
    //printf(":%d\n", i);
    return i;
}