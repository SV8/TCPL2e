#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c;
    int state = OUT;
    int nw = 0;
    int nwmax = 10;
    int len[nwmax]; // integer array storing lengths of input words.
    for (int i = 0; i < nwmax; ++i) 
        len[i] = 0;

    while ((c = getchar()) != '\n')
    {
        if (c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
            ++len[nw-1];
        }
        else
            ++len[nw-1];
    }
    
    for (int i = 0; i < nw; i++)
    {
        for (int j = 0; j < len[i]; j++)
            putchar('|');
        putchar('\n');
    }
}