/*
问题：用conditional expression改写lower函数
*/
#include <stdio.h>

int lower(int c);
int nlower(int c);

int main() {
    int c;
    char s[7];
    s[0] = 'A';
    s[1] = 'a';
    s[2] = 'Z';
    s[3] = 'z';
    s[4] = '9';
    s[5] = '*';
    s[6] = '\0';
    for (int i = 0; (c = s[i]) != '\0'; i++)
        putchar(nlower(c));
    printf("\n");
}

int nlower(int c)
{
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}