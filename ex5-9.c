/*
问题：改写month_day函数和day_of_year函数，使用指针数组，不使用二维数组。
*/


#include <stdio.h>

// static char daytab[2][13] = {
//     {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
//     {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

static char d1[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char d2[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char *pdaytab[] = {d1, d2};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int m, d;
    printf("day_of_year(2020, 12, 22): %d\n", day_of_year(2020, 12, 22));
    month_day(2020, 357, &m, &d);
    printf("month_day(2020, 357, m, d): %d, %d\n", m, d);
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    if (year < 0 || day > 31 || day < 1)
        return -1;
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += *(pdaytab[leap]+i);
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (year < 0)
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (leap)
    {
        if (yearday < 0 || yearday > 366)
        {
            *pmonth = -1;
            *pday = -1;
            return;
        }
    }
    else
    {
        if (yearday < 0 || yearday > 365)
        {
            *pmonth = -1;
            *pday = -1;
            return;
        }
    }
    for (i = 1; yearday > *(pdaytab[leap]+i); i++)
        yearday -= *(pdaytab[leap]+i);
    *pmonth = i;
    *pday = yearday;
}