//! 可以开 三倍大小的并查集,表示三个类群
//! 同类: 如果 a 不吃 b,并且 b 不吃 a 这就说明  a和 b 是同类
//! 种类并查集求的并非是种类,而是关系
//! 不要忘记特判 >n 的情况
#include <cstdio>
#include <iostream>

using namespace std;

inline int read()
{
    char c = getchar();
    int n = 0;
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9')
    {
        n = (n << 1) + (n << 3) + (c & 15);
        c = getchar();
    }
    return n;
}

const int N = 1e5 + 10;

int n, k, ans;
int p[N * 3];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]); //! 路径压缩
    return p[x];
}

void init()
{
    for(int i = 1; i <= n * 3; i++) p[i] = i;
}

int main(void)
{
    n = read(), k = read();
    init();
    while(k--)
    {
        int op = read(), x = read(), y = read();
        if(x > n || y > n)
        {
            ans++;
            continue;
        }
        if(op == 1) //! x 与 y是同类
        {
            if(find(x + n) == find(y) || find(x) == find(y + n))
                ans++;
            else
            {
                // todo 每一倍的并查集都要 合并
                p[find(x)] = find(y);
                p[find(x + n)] = find(y + n);
                p[find(x + n + n)] = find(y + n + n);
            }
        }
        else //! x 吃 y
        {
            if(find(x) == find(y) || find(x) == find(y + n))
                ans++;
            else
            {
                p[find(x)] = find(y + n + n);
                p[find(x + n)] = find(y);
                p[find(x + n + n)] = find(y + n);
            }
        }
    }
    return !printf("%d\n", ans);
}
