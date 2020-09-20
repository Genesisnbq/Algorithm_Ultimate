#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n;
int d[N], f[N];
int p[N];

//! 第 i号元素开始时数值为 i
//! 第 i号元素可以和距离为 d[i]的元素交换

void init()
{
    for(int i = 1; i <= n; i++) p[i] = i;
}

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void add(int a, int b)
{
    int x = find(a), y = find(b);
    if(x == y)
        return;
    else
        p[x] = y;
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &f[i]); //! 指定的 排列
    for(int i = 1; i <= n; i++) scanf("%d", &d[i]);

    init(); //! 也可以在输入的过程中,顺便初始化一下

    for(int i = 1; i <= n; i++) // todo 将 可以交换的 数字放入一个集合
    {
        if(i - d[i] >= 1) add(i, i - d[i]);
        if(i + d[i] <= n) add(i, i + d[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        if(find(i) != find(f[i])) //! 如果和可交换的数字不在一个集合
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}

//! 只要两两可交换, 必然可以排列成指定集合
/*
!对于第ii个值，它可以与第i-d[i]i−d[i]个值交换，也能与第i+d[i]i+d[i]个值交换。

!那么i-d[i]i−d[i]也可以与两个值交换，i+d[i]i+d[i]也可以与两个值交换…………
!所以我们不妨将他们这串两两可以交换的值用并查集合并。

!所以最后只需检查ii与f[i]f[i]是否在同一个集合即可。
*/
