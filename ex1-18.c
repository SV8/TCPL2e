#include <stdio.h>

#define MAXLINE 1000

int ngetline(char line[], int maxline);
void ncopy(char to[], char from[]);

int main() {
    int len, newlen;
    char line[MAXLINE];
    char newline[MAXLINE];

    while ((len = ngetline(line, MAXLINE)) > 0)
    {
        ncopy(newline, line);
        printf("%s\n", newline);
    }
    return 0;
}

int ngetline(char s[], int lim) {
    int c, i;
    // for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
    // {
    //     s[i] = c;
    // }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void ncopy(char to[], char from[]) {
    int i, j;
    i = 0;
    j = 0;
    while (from[i]!='\0')
    {
        if (from[i]!=' ' && from[i]!='\t')
        {
            to[j] = from[i];
            ++i;
            ++j;
        }
        else
        {
            ++i;
        }
    }
    to[j] = '\0';
}