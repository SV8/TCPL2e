/*
问题：编写函数setbits(x, p, n, y)，该函数返回值是在x的基础上，从p开始的n位被改为为y的最右边的n位，其余位不变。
例如，x = 0111110011, p = 3, n = 4, y = 0001111100
011 1110 011 & 111 0000 111 = 011 0000 011
000 111 1100 => 000 1100 000
011 0000 011 OR 000 1100 000 = 011 1100 011

算法描述：
1. 用掩码将x从p开始的n位全部变为0，其余位不变，得到x1。可以利用 ~(((1 << n) - 1) << p) 得到掩码
2. 将y的最右边n位保留，其余全部变成0，然后左移p位，得到y1
3. x1 | y1 即为所求
*/

#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {
    int x = 0x1F1F; //0001 1111 0001 1111
    int y = 0xAA11; //1010 1010 0001 0001
    int p = 3;
    int n = 4;
    int result;
    result = setbits(x, p, n, y);   //0001 1111 0000 1111, 0x1F0F, 7951
    printf("x=%d\ny=%d\np=%d\nn=%d\nresult=%d\n", x, y, p, n, result);
}

int setbits(int x, int p, int n, int y) {
    return (x & ~(((1 << n) - 1) << p)) | ((y & ~(~0 << n)) << p);
}

