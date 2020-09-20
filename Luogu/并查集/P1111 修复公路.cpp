#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 10;

//! n个村庄,m条公路
int n, m;
int p[N];
vector<pair<pair<int, int>, int>> f;

void init()
{
    for(int i = 0; i < n; i++) p[i] = i;
}

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int getin()
{
    int x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}

int cmp(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b)
{
    return a.second < b.second;
}

int main(void)
{

    scanf("%d%d", &n, &m);
    if(n == 1) return !printf("0");

    for(int i = 0; i < m; i++)
    {
        int x = getin(), y = getin(), t = getin();
        f.push_back({{x, y}, t});
    }
    //! 按时间从小到大排序
    sort(f.begin(), f.end(), cmp);
    init(); //! 初始化 p 数组
    for(int i = 0; i < m; i++)
    {
        int fx = find(f[i].first.first), fy = find(f[i].first.second);
        if(fx != fy) p[fx] = fy, n--;
        if(n == 1) return !printf("%d\n", f[i].second);
    }
    return !printf("-1\n");
}
