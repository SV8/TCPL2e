
/*
问题：编写strcat(s, t)的指针版本，数组版本见第二章。
*/

#include <stdio.h>

void strcata(char s[], char t[]);
void strcatp(char *s, char *t);

int main() 
{
    char s[] = "abcde";
    char t[] = "fghij";
    strcatp(s, t);
    printf("%s\n", s);
}

/* strcat: concatenate t to end of s; s must be big enough */
void strcata(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0') /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}

void strcatp(char *s, char *t)
{
    while (*s++ != '\0')    /* find end of s */
        ;
    s--;
    while ((*s++ = *t++) != '\0')    /* copy t */
        ;
}
