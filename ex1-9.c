#include <stdio.h>

int main() {
    int c;
    int nb = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++nb;
        else
            nb = 0;
        if (nb <= 1)
            putchar(c); 
    }
}