#include <iostream>

using namespace std;

int comfirm(int a, int b, int c)
{
    if ((a + b > c) && (b + c > a) && (a + c) > b)
    {
        if ((a == b) && (b == c))
            return 3;
        if ((a == b) || (b == c) || (a == c))
            return 2;
        else
            return 1;
    }
    else
        return 0;
}

int main(void)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (comfirm(a, b, c) == 0)
        puts("不是三角形");
    else if (comfirm(a, b, c) == 1)
        puts("普通三角形");
    else if (comfirm(a, b, c) == 2)
        puts("等腰三角形");
    else
        puts("等边三角形");
    return 0;
}
