/*
问题：编写reverse(s)函数的recursive版本。
 */

// /* reverse: reverse string s in place */ 
// void reverse(char s[])
// {
//     int c, i, j;
//     for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
//     {
//         c = s[i];
//         s[i] = s[j];
//         s[j] = c;
//     }
// }

#include <stdio.h>
#include <string.h>

#define MAXSIZE 1000

void reverse(char s[]);
int putline(char line[]);
int ngetline(char s[], int lim);

int main()
{
    //char s[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char s[MAXSIZE];
    ngetline(s, MAXSIZE);
    reverse(s);
    putline(s);
}

void reverse(char s[])
{
    void reverser(char s[], int i, int len);
    printf("%lu\n", strlen(s));
    reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len)
{
    int c, j;
    j = len - (i + 1);
    if (i < j)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}

/* getline: get line into s, return length */
int ngetline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
} 

int putline(char line[])
{
    int c;
    int i;
    i = 0;
    while (i < strlen(line))
    {
        c = line[i];
        putchar(c);
        ++i;
    }
    printf("\n");
    return i;
}