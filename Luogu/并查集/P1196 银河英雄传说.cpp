//! https://www.luogu.org/problem/P1196
#include <iostream>

using namespace std;

const int N = 3e4 + 10;

int t;
int d[N], num[N]; //! 用num记录个数
int p[N];

int find(int x)
{
    if(p[x] != x)
    {
        int root = find(p[x]);
        d[x] += d[p[x]]; //!当前这个点 到根的距离
        p[x] = root;     //!路径压缩
    }
    return p[x];
}

void add(int x, int y)
{
    int px = find(x), py = find(y);
    p[px] = py, d[px] = num[py]; //!连接了一条 rootx 到 rooty 的边   权值为 num[py]
    num[py] += num[px];
}

int main(void)
{
    scanf("%d", &t);
    for(int i = 1; i <= 30000; i++) p[i] = i, num[i] = 1;
    while(t--)
    {
        char op[2];
        int x, y;
        scanf("%s%d%d", op, &x, &y);
        if(op[0] == 'M')
            add(x, y);
        else
        {
            if(find(x) == find(y))
                printf("%d\n", abs(d[x] - d[y]) - 1);
            else
                puts("-1");
        }
    }
    return 0;
}
