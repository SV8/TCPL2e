/*
问题：假设需要回退的字符永远不会多于1个，请修改getch和ungetch函数。
*/


#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100   /* max size of operand or operator */ /* 操作符或者操作数的最大长度 */
#define MAXVAL 100  /* maximum depth of val stack */ /* 操作数堆栈的最大深度 */
#define NUMBER '0'  /* signal that a number was found */ /* '0'代表当前输入的是个数字(操作数)，而不是操作符 */
#define BUFSIZE 100 /* max size of input buffer */ /* 输入字符流堆栈的最大深度 */
#define MAXVAR 26  /* 最多支持26个变量 */

double val[MAXVAL]; /* value stack */ /* 操作数堆栈 */
int sp = 0;         /* next free stack position */ /* 操作数堆栈的游标 */
// char buf[BUFSIZE];  /* buffer for ungetch */ /* 输入字符流堆栈 */
// int bufp = 0;       /* next free position in buf */ /* 输入字符流堆栈的游标 */
char bufc = 0;         /* 初始为NULL */
double variables[MAXVAR];     /* 保存变量的数组，变量名对应A~Z */

int getop(char s[]);    /* 将单个操作数或操作符(去掉空格)放入s，并返回输入类型（'+', '-', '*', '/', NUMBER）*/
void push(double);
double pop(void);
int getch(void);    /* 从输入缓冲中获取一个字符 */
void ungetch(int);  /* 回退一个多余字符到输入缓冲 */

void top();          /* 打印出堆栈顶端的元素，不要pop */
void duplicate();    /* 复制堆栈顶端元素 */
void swap();         /* 交换堆栈顶部前两个元素 */
void clear();        /* 清空堆栈中的所有元素 */

double getvar(int c);               /* 通过变量名获取值 */
void setvar(int c, double value);   /* 保存值到变量 */

void printstack();      /* 打印操作数堆栈，用于调试 */
void printbuffer();     /* 打印输入缓冲，用于调试 */
void printvars();       /* 打印存放变脸的数组，用于调试 */

int main()
{
    int type;       /* 当前输入的类型：操作数（加减乘除）还是操作符 */
    int var;        /* 上一次输入的变量 */
    double v;          /* 变量v，保存最新的打印值 */
    double op2;
    char s[MAXOP];

    for (int i = 0; i < MAXVAR; i++)
        variables[i] = 0.0;
    
    while ((type = getop(s)) != EOF)    /* getop每执行一次，就从输入获取一个完整操作数或操作符 */
    {
        // printf("type: %c, setflag: %d\n", type);
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
        case 't':
            top();
            break;
        case 'd':
            duplicate();
            break;
        case 's':
            swap();
            break;
        case 'c':
            clear();
            break;
        case 'i':
            push(sin(pop()));
            break;
        case 'x':
            push(exp(pop()));
            break;
        case 'p':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '=':   /* 遇到等号时，进行变量赋值操作 */
            pop();  /* 先pop出最近的变量值 */
            if (var >= 'A' && var <= 'Z')   /* var是输入的上一个变量名 */
                setvar(var, pop());    /* pop获得新的值赋给变量 */
            else
                printf("Error! Illegal variable name.");
            break;
        case '\n':
            if (sp > 0)
                v = pop();
            printf("---------result: %g\n", v);  /* 输出最后结果 */
            break;
        default:
            if (type >= 'A' && type <= 'Z')
                push(getvar(type));
            else if (type == 'v')
                push(v);
            else
                printf("error: unknown command %s\n", s);
            break;
        }
        var = type; /* 记住当前变量 */

        // top();
        // printstack();   /* 调试 */
        // printvars();
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
            nc = getch();       /* nc有可能是数字，空格，或者'\n' */
            if (!isdigit(nc))   /* nc不是数字，则c是操作符- */
            {
                if (nc == '\n')
                    ungetch(nc);
                return c;
            }
            ungetch(nc);
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
    int c;
    if (bufc != 0)
        c = bufc;
    else
        c = getchar();
    bufc = 0;
    return c;
}

/* push character back on input */
void ungetch(int c)
{
    if (bufc != 0)
        printf("ungetch: too many characters\n");
    else
        bufc = c;
}

void top()
{
    if (sp > 0)
        printf("stack TOP: %g\n", val[sp-1]);
    else
        printf("stack TOP: None\n"); 
}

void duplicate()
{
    double value;
    if (sp > 0)
    {
        value = pop();
        push(value);
        push(value);
        printf("%g duplicated.\n", value);
    }
    else
        printf("No element to duplicate.\n");
}

void swap()
{
    double value1, value2;
    if (sp > 1)
    {
        value1 = pop();
        value2 = pop();
        push(value1);
        push(value2);
        printf("%g and %g swapped.\n", value1, value2);
    }
    else
        printf("Not enough elements to swap.\n");
}

void clear()
{
    if (sp > 0)
        sp = 0;
    else
        printf("No element to clear.\n");
}

double getvar(int c) 
{
    return variables[c - 'A'];
}

void setvar(int c, double value)
{
    printf("set: var %c to %g\n", c, value);
    variables[c - 'A'] = value;
}

// void printbuffer()
// {
//     int c;
//     int i;
//     i = 0;
//     printf("buffer: ");
//     if (bufp == 0)
//     {
//         printf("|empty, sp=%d\n", sp);
//         return;
//     }
//     while (i < bufp)
//     {
//         c = buf[i++];
//         printf("|%c", c);
//     }
//     printf(", bufp=%d\n", bufp);
// }

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

void printvars()
{
    double value;
    int i;
    i = 0;
    printf("vars: ");
    while (i < MAXVAR)
    {
        value = variables[i];
        printf("|%c:%g", 'A'+i, value);
        i++;
    }
    printf("\n");
}