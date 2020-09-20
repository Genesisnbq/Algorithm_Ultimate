// 选哪个模板取决于问题要求的是左区间右端点还是右区间左端点
// |-----|-------|
#include <iostream>

using namespace std;

// 浮点数二分任意模板都可以

int main(void)
{
    int x;
    cin >> x;

    double l = 1, r = x;

    while(r - l > 1e-8) //!小数点后保留6位 -8   5位 -7
    {
        double mid = (l + r) / 2;
        if(mid * mid <= x)
            l = mid;
        else
            r = mid;
    }

    printf("%lf", l); //!这里输出l或者是r都是一样的

    return 0;
}
