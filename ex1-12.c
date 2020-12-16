#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c;
    int state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT)
            state = IN;

        if (state == IN)
            putchar(c);
        else if (state == OUT)
            putchar('\n');
    }
}