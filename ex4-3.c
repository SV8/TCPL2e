/*
问题：以calculator的示例代码为框架，扩展其功能，支持取模%操作符，以及负数的输入。
说明：此题有一定的难度，关键要看懂getop(s)函数是如何从输入中获取操作数和操作符的。
测试输入：
1 2 - 4 5 + *
--------result: -9
1 -2 - 4 -5 + *
--------result: -3
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100   /* max size of operand or operator */ /* 操作符或者操作数的最大长度 */
#define MAXVAL 100  /* maximum depth of val stack */ /* 操作数堆栈的最大深度 */
#define NUMBER '0'  /* signal that a number was found */ /* '0'代表当前输入的是个数字(操作数)，而不是操作符 */
#define BUFSIZE 100 /* max size of input buffer */ /* 输入字符流堆栈的最大深度 */

double val[MAXVAL]; /* value stack */ /* 操作数堆栈 */
int sp = 0;         /* next free stack position */ /* 操作数堆栈的游标 */
char buf[BUFSIZE];  /* buffer for ungetch */ /* 输入字符流堆栈 */
int bufp = 0;       /* next free position in buf */ /* 输入字符流堆栈的游标 */

int getop(char s[]);    /* 将单个操作数或操作符(去掉空格)放入s，并返回输入类型（'+', '-', '*', '/', NUMBER）*/
void push(double);
double pop(void);
int getch(void);    /* 从输入缓冲中获取一个字符 */
void ungetch(int);  /* 回退一个多余字符到输入缓冲 */

void printstack();      /* 打印操作数堆栈，用于调试 */
void printbuffer();     /* 打印输入缓冲，用于调试 */

int main()
{
    int type;       /* 当前输入的类型：操作数（加减乘除）还是操作符 */
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)    /* getop每执行一次，就从输入获取一个完整操作数或操作符 */
    {
        // printf("type: %c\n", type);
        switch (type)
        {
        case NUMBER:    /* #define NUMBER '0' */
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            push((int)pop() % (int)op2);
            break;
        case '\n':
            printf("--------result: %.8g\n", pop());  /* 输出最后结果 */
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
        // printstack();   /* 调试 */      
        // printbuffer();  /* 调试 */
    }
    return 0;
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')    // 如果是空格或者制表符，直接略过
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')    // + - * /
    {
        if (c == '-') 
        {
            int nc;
            nc = getch();       // nc有可能是数字，空格，或者'\n'
            if (!isdigit(nc))   // nc不是数字，则c是操作符
                return c;
            ungetch(nc);        // nc是数字
        }
        else 
            return c;
    }

    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.' || c == '-') /* 小数点或者负号都作为操作数的一部分 */ 
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c); /* 回退一个多余字符到输入缓冲 */
    return NUMBER;  /* 返回操作数 */
}

/* push: push f onto value stack */
void push(double f)
{
    // printf("pushing: %g\n", f);
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* get a (possibly pushed-back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void printstack()
{
    double value;
    int i;
    i = 0;
    printf("stack: ");
    if (sp == 0)
    {
        printf("|empty, sp=%d\n", sp);
        return;
    }
    while (i < sp)
    {
        value = val[i++];
        printf("|%g", value);
    }
    printf(", sp=%d\n", sp);
}

void printbuffer()
{
    int c;
    int i;
    i = 0;
    printf("buffer: ");
    if (bufp == 0)
    {
        printf("|empty, sp=%d\n", sp);
        return;
    }
    while (i < bufp)
    {
        c = buf[i++];
        printf("|%c", c);
    }
    printf(", bufp=%d\n", bufp);
}