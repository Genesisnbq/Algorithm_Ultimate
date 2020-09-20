//! https://www.luogu.org/problem/P3370
// todo 单哈希
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
typedef unsigned long long ull;
const int N = 1e5 + 10;

int base = 131;
char str[N];
ull a[N];
int n;
int ans = 1;

ull gethash(char str[])
{
    ull hash = 0;
    //? strlen (str+1) 表示 下标从1开始的长度
    for(int i = 1; i <= strlen(str); i++) hash = hash * base + ( ull )str[i]; // todo (ull)str[i] 更稳定
    return hash;
}

int main(void)
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%s", str + 1);
        a[i] = gethash(str + 1);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i < n; i++)
    {
        if(a[i] != a[i + 1]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
