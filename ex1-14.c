#include <stdio.h>

#define NCHAR 26

int main() {
    int c;
    int nc[NCHAR];
    for (int i = 0; i < NCHAR; i++)
        nc[i] = 0;
    while ((c = getchar()) != '\n')
    {
        int index = c-'a';
        if (index >= 0 && index < 26)
        {
            ++nc[index];
        }
    }
    for (int i = 0; i < NCHAR; i++)
        printf("%d\n", nc[i]);
}