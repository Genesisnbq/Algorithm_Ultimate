#include <cmath>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int t, n;
int a[N];

int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        long long sum = 0;
        long long sum_x = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i], sum_x ^= a[i];
        if(sum == sum_x * 2)
            puts("0\n");
        else
        {
            puts("2");
            printf("%lld %lld\n", sum_x, sum + sum_x);
        }
    }
    return 0;
}
