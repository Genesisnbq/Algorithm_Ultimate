//辗转相除法
#include <iostream>

using namespace std;

int gcd(int x, int y) //用辗转相除法求最大公约数
{
    while(x * y) //当其中一个为0时，终止循环
    {
        if(x > y) //将较大数模较小数的结果（余数）赋给较大的值，直到两个数相等
        { x %= y; }
        else if(x < y)
        {
            y %= x;
        }
    }
    return x > y ? x : y;
}

int main()
{
    int a = 0;
    int b = 0;
    int max_com_div = 0;
    int min_com_mult = 0;
    scanf("%d %d", &a, &b);
    max_com_div = gcd(a, b);
    printf("%d", max_com_div);
    return 0;
}
