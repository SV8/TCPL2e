#include <stdio.h>

int main() {
    int c;
    long nb = 0, nt = 0, nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }
    printf("number of blanks:%ld\nnumber of tabs:%ld\nnumber of newlines:%ld\n", nb, nt, nl);
}