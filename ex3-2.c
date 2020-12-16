/*
问题：编写escape函数(s, t)，将字符串t拷贝到s的同时，将t包含的不可见字符例如newline和tab替换成'\n'、'\t'。另外再编写一个反向转换的函数。
算法描述：用switch
*/

#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
void reverse_escape(char s[], char t[]);
int ngetline(char s[], int lim);
int putline(char line[]);

int main() {
    char from[MAXLINE];
    char to[MAXLINE];
    char backto[MAXLINE];
    ngetline(from, MAXLINE);
    escape(to, from);
    putline(to);
    reverse_escape(backto, to);
    putline(backto);
}

void escape(char s[], char t[]) {
    int i, j;
    i = 0;
    j = 0;
    while (t[i] != '\0')
    {
        switch (t[i])
        {
        case '\t':
            s[j] = '\\';
            ++j;
            s[j] = 't';
            ++j;
            break;
        case '\n':
            s[j] = '\\';
            ++j;
            s[j] = 'n';
            ++j;
            break;
        default:
            s[j] = t[i];
            ++j;
            break;
        }
        ++i;
    }
    s[j] = t[i];
}

void reverse_escape(char s[], char t[]) {
    int i, j;
    i = 0;
    j = 0;
    while (t[i] != '\0')
    {
        switch (t[i])
        {
        case '\\':
            ++i;
            switch (t[i])
            {
            case 't':
                s[j] = '\t';
                ++j;
                break;
            case 'n':
                s[j] = '\n';
                ++j;
                break;
            default:
                s[j] = t[i];
                ++j;
                break;
            }
            break;
        default:
            s[j] = t[i];
            ++j;
            break;
        }
        ++i;
    }
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