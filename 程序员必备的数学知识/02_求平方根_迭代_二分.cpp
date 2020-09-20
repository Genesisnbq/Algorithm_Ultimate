#include <iostream>

using namespace std;

int n;

int main(void)
{
    scanf("%d", &n);
    double l = 1, r = n;
    while(r - l > 1e-8)
    {
        double mid = l / 2 + r / 2;
        if(mid * mid >= n)
            r = mid;
        else
            l = mid;
    }
    printf("%lf\n", r);
    return 0;
}
