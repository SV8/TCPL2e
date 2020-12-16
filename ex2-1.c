#include <stdio.h>
#include <limits.h>

// long power(int base, int n);
// unsigned long power2(int base, int n);

int main()
{
    printf("LONG_MIN: %ld\n", LONG_MIN);
    printf("LONG_MAX: %ld\n", LONG_MAX);
    printf("ULONG_MIN: %lu\n", (long)0);
    printf("ULONG_MAX: %lu\n", ULONG_MAX);
    // signed char sc = 'a';
    // unsigned char uc = 'a';
    // signed int si = 0;
    // unsigned ui = 0;
    // signed short ss = 0;
    // unsigned short us = 0;
    // signed long sl = 0;
    // unsigned long ul = 0;

    // printf("signed char: %lu byte(s), [%ld ~ %ld]\n", sizeof(sc), -power(2, sizeof(sc)*8)/2, power(2, sizeof(sc)*8)/2-1);
    // printf("unsigned char: %lu byte(s), [%ld ~ %ld]\n", sizeof(uc), (long)0, power(2, sizeof(uc)*8)-1);
    // printf("signed short: %lu byte(s), [%ld ~ %ld]\n", sizeof(ss), -power(2, sizeof(ss)*8)/2, power(2, sizeof(ss)*8)/2-1);
    // printf("unsigned short: %lu byte(s), [%ld ~ %ld]\n", sizeof(us), (long)0, power(2, sizeof(us)*8)-1);
    // printf("signed int: %lu byte(s), [%ld ~ %ld]\n", sizeof(si), -power(2, sizeof(si)*8)/2, power(2, sizeof(si)*8)/2-1);
    // printf("unsigned int: %lu byte(s), [%ld ~ %ld]\n", sizeof(ui), (long)0, power(2, sizeof(ui)*8)-1);
    // printf("signed long: %lu byte(s), [%ld ~ %ld]\n", sizeof(sl), -power2(2, sizeof(sl)*8)/2, power2(2, sizeof(sl)*8)/2-1);
    // printf("unsigned long: %lu byte(s), [%ld ~ %lu]\n", sizeof(ul), (long)0, power2(2, sizeof(ul)*8)-1);
}

// long power(int base, int n)
// {
//     long p = 1;
//     int i;
//     for (i = 1; i <= n; ++i)
//         p = p * base;
//     return p;
// }

// unsigned long power2(int base, int n)
// {
//     unsigned long p = 1;
//     int i;
//     for (i = 1; i <= n; ++i)
//         p = p * base;
//     return p;
// }
