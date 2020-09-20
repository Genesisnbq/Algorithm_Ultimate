// 切出的形状是正方形, 边长是整数, 大小相同
// 巧克力只能切不能拼接
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int h[N], w[N];

bool check(int mid)
{
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        res += (h[i] / mid) * (w[i] / mid);
        if(res >= k) return true;
    }
    return false;
}

int main(void)
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d%d", &h[i], &w[i]);
    int l = 1, r = 1e5;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid)) // 如果true, 那么所有<=mid边长都是可以满足要求的
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", r);
    return 0;
}
