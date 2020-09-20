#include <iostream>

using namespace std;

const int N = 1e6 + 10;

long long n, k;
int t;

int main(void)
{
    int m = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld%lld", &n, &k);
        long long cur = k * k;
        if(!((n - cur) % 2) && n >= cur) puts("YES");
        else
            puts("NO");
    }
    return 0;
}
