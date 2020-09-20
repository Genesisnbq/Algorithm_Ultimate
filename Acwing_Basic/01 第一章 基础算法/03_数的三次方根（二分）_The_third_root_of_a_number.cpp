#include <iostream>

using namespace std;

int main(void)
{
    double x;
    scanf("%lf", &x); // ! double   在使用printf的时候  是 lf

    double l = -1e4, r = 1e4;

    while(r - l > 1e-8) //!小数点后保留6位 -8   5位 -7
    {
        double mid = (l + r) / 2;
        if(mid * mid * mid >= x)
            r = mid;
        else
            l = mid; //! 因为是浮点数 所以我们没有必要加一
    }

    printf("%lf\n", l);

    return 0;
}
