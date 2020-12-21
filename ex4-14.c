/*
问题：编写macro，swap(t, x, y)，交换类型为t的x和y的值。
 */
#include <stdio.h>

#define swap(t, x, y) { t temp; temp = x; x = y; y = temp; }

int main() 
{
    int a, b;
    a = 1;
    b = 2;
    swap(int, a, b);
    printf("a:%d, b:%d\n", a, b);
}
