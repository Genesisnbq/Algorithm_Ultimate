#include <iostream>

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

ll s[N], cnt[N];
int n, k;
ll ans;

int main(void)
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }
    cnt[0] = 1;
    for(int r = 1; r <= n; r++)
    {
        ans += cnt[s[r] % k];
        cnt[s[r] % k]++;
    }
    printf("%lld\n", ans);
    return 0;
}
