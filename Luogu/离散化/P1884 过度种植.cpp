#include <algorithm>
#include <cstdio>
#include <iostream>

#define int long long

using namespace std;

const int gz = 10086;

inline void in(int& x)
{
    int f = 1;
    x = 0;
    char s = getchar();
    while(!isdigit(s))
    {
        if(s == '-') f = -1;
        s = getchar();
    }
    while(isdigit(s))
    {
        x = x * 10 + s - '0';
        s = getchar();
    }
    x *= f;
}

struct cod
{
    int l, r, h;
    int f;
    bool operator<(const cod& a) const
    {
        return h < a.h;
    }
} edge[gz];

struct tre
{
    int l, r, s;
    int len;
} tr[gz];

#define ls o << 1
#define rs o << 1 | 1

int x[gz], n, tot;

void build(int o, int l, int r)
{
    tr[o].l = l;
    tr[o].r = r;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
}

inline void up(int o)
{
    if(tr[o].s)
        tr[o].len = x[tr[o].r + 1] - x[tr[o].l];
    else if(tr[o].l == tr[o].r)
        tr[o].len = 0;
    else
        tr[o].len = tr[ls].len + tr[rs].len;
}

void change(int o, int l, int r, int del)
{
    if(tr[o].l == l and tr[o].r == r)
    {
        tr[o].s += del;
        up(o);
        return;
    }
    int mid = (tr[o].l + tr[o].r) >> 1;
    if(r <= mid)
        change(ls, l, r, del);
    else if(l > mid)
        change(rs, l, r, del);
    else
        change(ls, l, mid, del), change(rs, mid + 1, r, del);
    up(o);
}

signed main()
{
    in(n);
    for(int i = 1; i <= n; i++)
    {
        int x1, x2, y1, y2;
        in(x1), in(y1), in(x2), in(y2);
        edge[++tot].l = x1;
        edge[tot].r = x2;
        edge[tot].f = -1;
        edge[tot].h = y1;
        x[tot] = x1;
        edge[++tot].l = x1;
        edge[tot].r = x2;
        edge[tot].f = 1;
        edge[tot].h = y2;
        x[tot] = x2;
    }
    sort(edge + 1, edge + tot + 1);
    sort(x + 1, x + tot + 1);
    int new_n = 1;
    for(int i = 2; i <= tot; i++)
        if(x[new_n] != x[i]) x[++new_n] = x[i];
    build(1, 1, new_n);
    int ans = 0;
    for(int i = 1; i <= tot; i++)
    {
        int l = lower_bound(x + 1, x + new_n + 1, edge[i].l) - x;
        int r = lower_bound(x + 1, x + new_n + 1, edge[i].r) - x - 1;
        change(1, l, r, edge[i].f);
        ans += (edge[i + 1].h - edge[i].h) * tr[1].len;
    }
    printf("%lld", ans);
}
