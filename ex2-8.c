/*
问题：编写函数rightrot(x, n)，该函数返回值是x向右侧移出n位，移出的n位又依次从x的左侧移入。
Right rotation, the bits that fall off at right end are put back at left end.
例如：
n = 4
x =         ... 1111 1111 0001 0001
result =    0001 ... 1111 1111 0001

算法描述：
1. 用掩码截取x的最右侧n位得到y，掩码为：~(~0 << n) 或者 (1 << n) - 1
2. y左移 __SIZEOF_INT__ * 8 - n 位，得到z1
3. x右移 n 位，得到z2
4. z1 | z2 即为所求
*/

#include <stdio.h>

int rightrot(int x, int n);

int main() {
    int n;
    int x;
    int result;
    n = 4;
    x = 0xFF11;
    result = rightrot(x, n);
    printf("%d\n", result);
}

int rightrot(int x, int n) {
    return ((x & ((1 << n) - 1)) << (__SIZEOF_INT__ * 8 - n)) | (x >> n);
}