#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, k;
ll cnt[N], s[N];

int main(void)
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }
    ll ans = 0;
    cnt[0] = 1; // 我们默认第一个位置(s[0]) 有数(0%k==0), 所以初始化cnt[0]=1;
    for(int r = 1; r <= n; r++)
    {
        ans += cnt[s[r] % k];
        cnt[s[r] % k]++;
    }
    printf("%lld\n", ans);
    return 0;
}
