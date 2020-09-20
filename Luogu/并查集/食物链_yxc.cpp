#include <iostream>
using namespace std;

const int N = 5e4 + 10;

int p[N], d[N];
int n, k;
int ans;

int find(int x)
{
    if(p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main(void)
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) p[i] = i;

    while(k--)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if(x > n || y > n)
        {
            ans++;
            continue;
        }
        int px = find(x), py = find(y);
        if(op == 1)
        {
            if(px == py && (d[x] - d[y]) % 3 != 0)
                ans++;
            else if(px != py)
            {
                p[px] = py;
                d[px] = d[y] - d[x]; //! 要求 ? 的权值
            }
        }
        else
        {
            if(px == py && (d[x] - d[y] - 1) % 3 != 0)
                ans++;
            else if(px != py)
            {
                p[px] = py;
                d[px] = d[y] + 1 - d[x];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
