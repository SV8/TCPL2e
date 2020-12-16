#include <stdio.h>

#define MAXLINE 1000

int getlowerline(char line[], int maxline); // Input a line
int lower(int c);                       // Change a character to lower case
void deprefix(char to[], char from[]);   // Cut off the prefix "0x" in a hex string
int htoi(char s[]);                     // Hex string to integer

int main() {
    int result;
    char line[MAXLINE];
    char newline[MAXLINE];
    getlowerline(line, MAXLINE);
    deprefix(newline, line);
    result = htoi(newline);
    printf("%d\n", result);
}

int htoi(char s[]) {
    int i, n;
    n = 0;
    for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f'); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            n = 16 * n + (s[i] - '0');
        else if (s[i] >= 'a' && s[i] <= 'f')
            n = 16 * n + (s[i] - '0' - 39);
    }
    return n;
}

int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int getlowerline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
    {
        s[i] = lower(c);
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void deprefix(char to[], char from[]) {
    int i;
    i = 0;
    if (from[0] == '0' && from[1] == 'x')
    {
        while ((to[i] = from[i+2])!='\0')
        {
            ++i;
        }
    }
}

