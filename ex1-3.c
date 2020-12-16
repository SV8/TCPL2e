#include <stdio.h>

int main() {
    // 实现 0 ~ 300（步长20）华氏度到摄氏度的转换
    float fahr, celcius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    printf("Fahrenheit to Celsius\n");
    while (fahr <= upper)
    {
        celcius = (5.0/9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celcius);
        fahr = fahr + step;
    }
}