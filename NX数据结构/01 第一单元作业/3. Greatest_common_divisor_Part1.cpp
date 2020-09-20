//用更相减损法求最大公约数
#include <iostream>
using namespace std;

int gcd(int x, int y) //用更相减损法求最大公约数
{
    while(1) //用大数减去小数并将结果保存起来
    {
        if(x > y) { x -= y; }
        else if(x < y)
        {
            y -= x;
        }
        else //如果两个数相等时，则这个数就是最大公约数
        {
            return x;
        }
    }
}

int main()
{
    int a = 0;
    int b = 0;
    int com_div = 0;
    scanf("%d %d", &a, &b);
    com_div = gcd(a, b);
    printf("%d\n", com_div);
    return 0;
}
