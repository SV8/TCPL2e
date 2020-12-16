// 用for循环实现华氏到摄氏的转换，倒序输出

#include <stdio.h>

int main() {
    int fahr;
    for (fahr = 300; fahr >= 0; fahr -= 20)
    {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}