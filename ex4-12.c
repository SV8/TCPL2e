/*
问题：改写itoa函数为recursive版本。
*/

// /* itoa: convert n to characters in s */
// void itoa(int n, char s[])
// {
//     int i, sign;
//     if ((sign = n) < 0) /* record sign */
//         n = -n; /* make n positive */
//     i = 0;
//     do  /* generate digits in reverse order */
//     {
//         s[i++] = n % 10 + '0'; /* get next digit */
//     } while ((n /= 10) > 0);    /* delete it */
//     if (sign < 0)
//         s[i++] = '-';
//     s[i] = '\0';
//     reverse(s);
// }

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXSIZE 1000

void itoa(int n, char s[]);
int putline(char line[]);

int main()
{
    char s[MAXSIZE];
    int n = -20201220;
    itoa(n, s);
    putline(s);
}

void itoa(int n, char s[])
{
    static int i;
    if (n / 10)
        itoa(n / 10, s);
    else 
    {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    } 
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

int putline(char line[])
{
    int c;
    int i;
    i = 0;
    while ((c = line[i]) != '\0')
    {
        putchar(c);
        ++i;
    }
    printf("\n");
    return i;
}