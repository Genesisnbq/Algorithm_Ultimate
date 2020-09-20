#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], s[N];

int main(void)
{
    ios::sync_with_stdio(false); //! 这句话 是提高 cin 的读取速度 副作用是 不能再使用 scanf了
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++) scanf("%d", &a[i]); //! 下标要从 1 开始

    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i]; //! 前缀和的初始化

    while(m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]); //! 区间和的计算
    }

    return 0;
}
