/*
问题：在字符串s1中剔除掉s2包含的所有字符
算法描述：
1. 从输入获取两个字符串s1和s2
2. 遍历s2中的所有字符
3. 如果当前字符出现在s1中，将之从s1剔除。（利用squeeze函数）
*/

#include <stdio.h>

#define MAXLINE 1000

int ngetline(char s[], int lim);
void squeeze(char s[], int c);

int main() {
    int c;
    char s1[MAXLINE];
    char s2[MAXLINE];
    ngetline(s1, MAXLINE);
    ngetline(s2, MAXLINE);
    for (int i = 0; (c = s2[i]) != '\n' ; i++)
        squeeze(s1, c);
    printf("%s", s1);
}

// 此函数的特点是只用了1份字符数组
void squeeze(char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0'; //字符串末尾加上结束符
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
