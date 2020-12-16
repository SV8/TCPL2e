#include <stdio.h>

#define MAXLINE 1000

int ngetline(char line[], int maxline);
void reverse(char to[], char from[]);

int main() {
    int len, newlen;
    char line[MAXLINE];
    char reversedline[MAXLINE];

    while ((len = ngetline(line, MAXLINE)) > 0)
    {
        reverse(reversedline, line);
        printf("%s\n", reversedline);
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

void reverse(char to[], char from[]) {
    int n, i;
    n = 0;

    while (from[n]!='\0')
        ++n;
    i = n - 1;
    while (i >= 0)
    {
        to[n-i-1] = from[i];
        --i;
    }
    to[n] = '\0';
}