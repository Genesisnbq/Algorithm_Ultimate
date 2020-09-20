#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 4e5 + 10;

int n, m, p[N], K, D[N], vis[N], ans[N], num;
//!  num表示总联通块的个数，ans[]记住答案 ，vis[]给点标号 ，D[]被攻占的点
struct xcw
{
    int x, y, c; //! x,y表示这条边的两端点，c表示这条边的序号
    bool operator<(const xcw b) const
    {
        return c < b.c;
    } //!按序号从小到大排序
} a[N];

int read() //! 快速读入
{
    int ret = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = -f;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') ret = ret * 10 + ch - 48, ch = getchar();
    return ret * f;
}

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
void mer(int x, int y)
{
    int fx = find(x), fy = find(y);
    if(fx != fy) p[fx] = fy, num--; //!两联通块合并，总联通块num--
}
int main()
{
    n = read();
    m = read();

    num = n;

    for(int i = 0; i < n; i++) p[i] = i;

    for(int i = 1; i <= m; i++) a[i] = (xcw){read(), read(), 0};

    K = read();

    for(int i = 1; i <= K; i++) vis[D[i] = read()] = K - i + 1;         //! 给点标号，从大到小
    for(int i = 1; i <= m; i++) a[i].c = max(vis[a[i].x], vis[a[i].y]); //! 当前边的序号是两个点中最大的那个
    sort(a + 1, a + 1 + m);                                             //! 给点按序号大小排序，方便处理，优化效率

    for(int i = 0, j = 1; i <= K; i++) //!枚举被攻占的星球序号
    {
        while(a[j].c == i) //!将当前序号全部合并
        {
            mer(a[j].x, a[j].y);
            j++;
        }
        ans[i] = num - (K - i); //! K-i是帝国攻占的星球个数（因为是逆序处理的）
    }
    for(int i = K; i >= 0; i--) printf("%d\n", ans[i]); //! 逆序输出
    return 0;
}
