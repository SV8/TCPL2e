#include <stdio.h>

int main() {
    // 实现 0 ~ 300（步长20）摄氏到华氏的转换
    float fahr, celcius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    printf("Celsius to Fahrenheit\n");
    while (celcius <= upper)
    {
        fahr = (9.0/5.0) * celcius + 32;
        printf("%3.0f %6.1f\n", celcius, fahr);
        celcius = celcius + step;
    }
}