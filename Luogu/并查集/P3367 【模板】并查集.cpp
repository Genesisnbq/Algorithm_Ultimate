//! https://www.luogu.org/problem/P3367
//! 并查集可以维护连通性 传递性
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e4 + 10;

int n, m;
int z, x, y;
int p[N];

void init()
{
    for(int i = 0; i < n; i++) p[i] = i;
}

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(void)
{
    scanf("%d%d", &n, &m);
    init();
    while(m--)
    {
        scanf("%d%d%d", &z, &x, &y);
        if(z == 1)
        {
            if(find(x) != find(y)) p[find(x)] = find(y);
        }
        else
        {
            if(find(x) == find(y))
                puts("Y");
            else
                puts("N");
        }
    }
    return 0;
}
