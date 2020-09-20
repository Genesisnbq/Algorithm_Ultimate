#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], n;
int q;

int read()
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
//!  还是挺精妙 hh
int solve(int i, int m)
{
    if(m == 0) return 1; //! 已经找到 m 的组合
    if(i >= n) return 0; //! 已经穷举过 a F的所有组合了
    //! 分别穷举 选择 a[i] 的情况和不选择 a[i] 的情况

    int res = solve(i + 1, m) || solve(i + 1, m - a[i]); // todo  ......进入穷举(从最后一个开始,然后再进入递归)
    return res;
}

int main(void)
{
    n = read();
    for(int i = 0; i < n; i++) a[i] = read();
    q = read();
    while(q--)
    {
        int m = read();
        if(solve(0, m))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
