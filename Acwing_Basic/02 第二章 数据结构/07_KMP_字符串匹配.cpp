#include <iostream>

using namespace std;

const int N = 1e4 + 10, M = 1e5 + 10;

int n, m;
char p[N], s[M];
int kmp_next[N]; //* 避免直接命名为 next[N] 报错

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> (p + 1) >> m >> (s + 1); //!往后读一位

    //! 求 Next 过程
    for(int i = 2, j = 0; i <= n; i++)
    {
        while(j != 0 && p[i] != p[j + 1]) j = kmp_next[j];

        if(p[i] == p[j + 1]) j++;

        kmp_next[i] = j;
    }

    //! KMP 匹配过程
    for(int i = 1, j = 0; i <= m; i++) //!错一位
    {
        //! 这个while结束的条件是 j=0 或者 是 s[i]=p[j+1];
        while(j != 0 && s[i] != p[j + 1]) j = kmp_next[j];

        if(s[i] == p[j + 1]) j++; // todo 如果是等于这种情况 就把 j 往后移动一位

        if(j == n) //! 匹配成功  n是字符串的长度
        {
            cout << i - n << ' '; //!返回 完全匹配的第一个下标 输出的是从 0开始的下标
            j = kmp_next[j];
        }
    }
    return 0;
}
