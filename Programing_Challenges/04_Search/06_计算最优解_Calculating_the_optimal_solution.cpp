#include <iostream>

using namespace std;
typedef long long ll;

const int N = 1e5;

int n, k;
ll t[N];

//! k辆最大运载量为p的卡车能装多少货物
int check(ll p)
{
    int i = 0;
    for(int j = 0; j < k; j++) //! k辆卡车
    {
        ll s = 0;
        while(s + t[i] <= p)
        {
            s += t[i++];
            if(i == n) return n;
        }
    }
    return i;
}

int solve(void)
{
    ll l = 0, r = 1e5 * 1e4; //! 货物数 * 1件货物的最大重量
    ll mid;
    while(r - l > 1)
    {
        mid = (l + r) >> 1;
        int v = check(mid); //! mid== 检查 mid==p时能装多少货物  返回
        if(v >= n)
            r = mid; //! 判定到左区间
        else
            l = mid; //! 判定到右区间
    }
    return r; //!  l和r 都可以
}

int main(void)
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &t[i]);
    ll ans = solve();
    printf("%lld\n", ans);
    return 0;
}
