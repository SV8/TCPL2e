/*
问题：编写函数invert(x, p, n)，该函数返回值是在x的基础上，从p开始的n位被反置（0变1，1变0），其余位不变。
例如：
p = 3
n = 4
x = 1010 1010 0001 0001
a = 0000 0000 0111 1000 
x ^ a = 1010 1010 0110 1001

算法描述：
1. ((1 << n) - 1) << p 得到 a
2. x ^ a 即为所求
*/

#include <stdio.h>

int inverts(int x, int p, int n);

int main() {
    int x = 0xAA11; //1010 1010 0001 0001
    int p = 3;
    int n = 4;
    int result;
    result = inverts(x, p, n);   //1010 1010 0110 1001, 0xAA69, 43625
    printf("x=%d\np=%d\nn=%d\nresult=%d\n", x, p, n, result);
}

int inverts(int x, int p, int n) {
    return x ^ (((1 << n) - 1) << p);
}