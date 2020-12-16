/*
问题：编写expand(s1, s2)函数，s1是类似于a-z的字母序列缩写，s2是此缩写的完整展开例如abc...xyz。
算法描述：
*/
#include <stdio.h>

#define MAXLINE 1000

int expand(char s1[], char s2[]);
int ngetline(char s[], int lim);
int putline(char line[]);
int lower(int c);
int isdigit(int c);

int main() {
    char s1[MAXLINE];
    char s2[MAXLINE];
    ngetline(s1, MAXLINE);
    expand(s1, s2);
    putline(s2);
}

int expand(char s1[], char s2[]) {
    int start;
    int end;
    int c;
    int j;
    j = 0;
    for (int i = 0; s1[i] != '\n'; i++)
    {
        s1[i] = lower(s1[i]);
        if (s1[i] == '-' && i > 0 && s1[i-1] != '-' && s1[i+1] != '-')
        {
            j--;
            start = s1[i-1], end = s1[i+1];
            for (c = start; c < end; c++)
            {
                s2[j] = c;
                j++;
            }
        }
        else
        {
            s2[j] = s1[i];
            j++;
        }
    }
    return j;
}

int ngetline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int putline(char line[]) {
    int c;
    int i;
    i = 0;
    while ((c = line[i]) != '\0' && c != '\n')
    {
        putchar(c);
        ++i;
    }
    printf("\n");
    return i;
}

int isdigit(int c) {
    return c >= '0' && c <= '9';
}

int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}