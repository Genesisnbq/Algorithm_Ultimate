#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int t;
int n, k, d;
int a[N];

//! a[i] 是 第 i天播放的节目
//! 连续 d 天
//! 每天播放 k 个节目

int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &k, &d);
        for(int i = 0; i < n; i++) scanf("%d", a[i]);
    }
}
