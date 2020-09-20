#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, k;
ll s[N], cnt[N];
ll ans;

int main(void)
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }
    for(int r = 1; r <= n; r++)
    {
        int x = s[r] % k;
        if(!x) ans++;
        for(int l = 1; l < r; l++)
        {
            if(s[l] % k == x) ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
