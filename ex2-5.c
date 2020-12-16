/*
问题：给定两个字符串s1和s2，s2包含的所有字符中若有任何一个首次出现在s1中，记录并打印出这个位置，否则打印未找到。
算法描述：
1. 设置MIN，初始值为-1
2. 输入2个字符串，s1和s2
3. 遍历s2中所有字符
4. 如果当前字符存在于s1中，记录该位置
5. 将该位置与MIN比较。如果该位置比MIN更小，则将MIN设置为该位置。MIN即为所求
*/

#include <stdio.h>

#define MAXLINE 1000

int ngetline(char s[], int lim);
int contains(char s[], int c);  // 返回c在s中的首次出现位置，如果没找到则返回-1

int main() {
    int c;
    char s1[MAXLINE];
    char s2[MAXLINE];
    int pos, minpos;
    minpos = -1;

    ngetline(s1, MAXLINE);
    ngetline(s2, MAXLINE);
    for (int i = 0; (c = s2[i]) != '\n'; i++)
    {
        pos = contains(s1, c);
        printf("%c:%d\n", c, pos);
        if ((pos != -1 && minpos == -1) || minpos > pos)
            minpos = pos;
    }
    printf("%d\n", minpos);
}

// 返回c在s中的首次出现位置，如果没找到则返回-1
int contains(char s[], int c) {
    for (int i = 0; s[i] != '\n'; i++)
    {
        if (s[i] == c)
            return i;
    }
    return -1;
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