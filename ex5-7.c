/*
问题：重写readlines函数，让读取到的行保存到main函数提供的一个数组中，而不是另外分配内存。
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000    /* max #lines to be sorted */
#define MAXLEN 1000      /* max length of any input line */
#define ALLOCSIZE 10000 /* size of available space */
#define MAXSTOR 5000    /* max storage size */

char *lineptr[MAXLINES]; /* pointers to text lines */

char *alloc(int);
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

// int readlines(char *lineptr[], int nlines); /* 将读取的各行拷贝到lineptr[]指向的位置，并返回读取到的行数 */
int readlines(char *lineptr[], char *linstor, int nlines);   /* 新版本的redlines */
void writelines(char *lineptr[], int nlines);   /* 按顺序打印数组中指针指向的内容 */
int ngetline(char *s, int lim); /* 读取一行，包含换行符和\0 */
void qsort(char *lineptr[], int left, int right);   /* 用quicksort算法排序，只需操作指针，无需移动字符串 */

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */
    char linestor[MAXSTOR]; // main函数提供数组
    if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);  
        writelines(lineptr, nlines);    
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    char *linestop = linestor + MAXSTOR;

    nlines = 0;
    p = linestor;
    while ((len = ngetline(line, MAXLEN)) > 0)  /* 每次读取一行 */
        if (nlines >= maxlines || p + len > linestop) /* 分配内存，p为初始地址 */
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline 删掉换行符 */
            strcpy(p, line);    /* 拷贝 */
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

// /* readlines: read input lines */
// int readlines(char *lineptr[], int maxlines)
// {
//     int len, nlines;
//     char *p, line[MAXLEN];

//     nlines = 0;
//     while ((len = ngetline(line, MAXLEN)) > 0)  /* 每次读取一行 */
//         if (nlines >= maxlines || (p = alloc(len)) == NULL) /* 分配内存，p为初始地址 */
//             return -1;
//         else
//         {
//             line[len - 1] = '\0'; /* delete newline 删掉换行符 */
//             strcpy(p, line);    /* 拷贝 */
//             lineptr[nlines++] = p;
//         }
//     return nlines;
// }

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* getline: read a line into s, return length */
int ngetline(char *s, int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    }
    else /* not enough room */
        return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}