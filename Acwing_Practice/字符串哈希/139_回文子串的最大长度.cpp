#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

const int N = 2 * 1e6 + 10, base = 131;

char str[N];
ull hl[N], hr[N], p[N];

ull get(ull h[], int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main(void)
{
    int t = 1;
    p[0]=1;
    while(scanf("%s", str + 1), strcmp(str + 1, "END"))
    {
        int n = strlen(str + 1);
        n*=2;
        for(int i = n; i; i -= 2)
        {
            str[i] = str[i / 2];
            str[i - 1] = 'a' + 26; // todo 一个超过 'z' 的字母
        }
        for(int i = 1, j = n; i <= n; i++, j--)
        {
            hl[i] = hl[i - 1] * base + str[i] - 'a' + 1;
            hr[i] = hr[i - 1] * base + str[j] - 'a' + 1;
            p[i] = p[i - 1] * base;
        }
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            int l = 0, r = min(i - 1, n - i);
            while(l < r)
            {
                int mid = (l + r + 1) >> 1;
                // todo  hr 是倒过来的 所以要 交换位置
                if(get(hl, i - mid, i - 1) != get(hr, n - (i + mid) + 1, n - (i + 1) + 1))
                    r = mid - 1;
                else
                    l = mid;
            }
            // todo 二分结束后, l==r  并且 找到了最大的子序列长度
            if(str[i - l] <= 'z')
                res = max(res, l + 1);
            else
                res = max(res, l);
        }
        printf("Case %d: %d\n", t++, res);
    }
    return 0;
}
