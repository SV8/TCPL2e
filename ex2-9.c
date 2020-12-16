/*
问题：利用 “x &= (x - 1) 会去掉x右侧的1”这一特性，改写bitcount函数，比书上的版本更有效率。
关于x &= (x - 1)的特性的解释：
https://www.quora.com/What-is-an-intuitive-explanation-for-why-x-x-1-always-equals-x-with-the-lowest-bit-erased
算法描述：x &= (x - 1) 每次会将x的最右侧的1去掉，循环执行直到x变成0。
*/
#include <stdio.h>

int bitcount(unsigned x);
int nbitcount(unsigned x);

int main() {
    unsigned int a = 0x11FF;
    printf("bitcount(0x%x): %d\n", a, bitcount(a));
    printf("nbitcount(0x%x): %d\n", a, nbitcount(a));
}

/* 改进版本 nbitcount: count 1 bits in x */
int nbitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; b++)
        x &= (x - 1);
    return b;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}