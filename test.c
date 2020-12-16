#include <stdio.h>

int main() {
    char c = 'a';
    int i = 0;
    short int s = 0;
    long int l = 0;
    printf("char: %lu byte(s)\n", sizeof(c));
    printf("int: %lu byte(s)\n", sizeof(i));
    printf("short: %lu byte(s)\n", sizeof(s));
    printf("long: %lu byte(s)\n", sizeof(l));
}