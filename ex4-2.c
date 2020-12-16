/*
问题：对本章例子中的atof函数进行扩展，使其支持科学计数法表示的数，例如123.45e-6，e可以大写或小写，指数可以为正或负。
算法描述：
*/

#include <stdio.h>
#include <ctype.h>  // isdigit(c)
#include <math.h>   // pow(x, n)

#define MAXLINE 100

/* rudimentary calculator */
int main()
{
    double sum, atof(char[]);   // 注意这种声明方式
    char line[MAXLINE];
    int ngetline(char line[], int max); // 注意这种声明方式
    sum = 0;
    while (ngetline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
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
/* atof: convert string s to double */
double atof(char s[])
{
    double val, power, significant;
    int i, sign, psign, p;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    significant = sign * val / power;
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    psign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (p = 0.0; isdigit(s[i]); i++)
        p = 10.0 * p + (s[i] - '0');
    printf("%g * pow(%d, %d)\n", significant, psign, p);    // 注意^是异或，不是幂运算
    return significant * pow(10.0, psign*p);
}
