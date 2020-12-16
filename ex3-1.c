/*
问题：重写binsearch函数，使得循环内部只做一次判断而不是两次。然后比较两个binsearch函数的性能。
算法描述：改用for循环，将判断放到循环外面的条件测试中。
*/
#include <stdio.h>

int binsearch(int x, int v[], int n);
int nbinsearch(int x, int v[], int n);

int main() {
    int x;
    int result;
    int v[10];
    for (int i = 0; i < 10; i++)
        v[i] = i;
    x = 7;
    result = nbinsearch(x, v, 10);
    printf("%d\n", result);
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */ 
            return mid;
    }
    return -1;  /* no match */
}

int nbinsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    for (high = n - 1; (low <= high) && (x != v[mid]); mid = (low + high) / 2)
    {
        if (x < v[mid]) {
            high = mid + 1;
        }
        else {
            low = mid + 1;
        }
    }
    if (x == v[mid])
        return x;
    else
        return -1; 
}