#include <cstdio>
#include <iostream>

using namespace std;

const int N = 5e3 + 10;

int n, m, q;
int p[N];

void init()
{
    for(int i = 0; i < n; i++) p[i] = i;
}

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]); // todo 路径压缩
    return p[x];
}

int main(void)
{
    scanf("%d%d%d", &n, &m, &q);

    init();

    int x, y;
    while(m--)
    {
        scanf("%d%d", &x, &y);
        if(find(x) != find(y)) p[find(x)] = find(y);
    }

    while(q--)
    {
        // todo 上面的 x y 继续使用
        scanf("%d%d", &x, &y);
        if(find(x) == find(y))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
