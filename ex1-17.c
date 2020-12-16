#include <stdio.h>

#define MAXLINE 1000
#define LONGLINE 80

int ngetline(char line[], int maxline);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = ngetline(line, MAXLINE)) > 0)
    {
        //printf(":%d\n", len);
        if (len > LONGLINE)
        {
            printf("%d:%s\n", len, line);
        }
    }
    return 0;
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