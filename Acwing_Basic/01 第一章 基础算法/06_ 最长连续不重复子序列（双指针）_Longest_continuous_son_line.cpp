#include <iostream> //* 双指针算法的运用

using namespace std;

const int N = 1e5 + 10; //! 双指针算法的运用

int n;
int a[N]; //! 原来的数
int s[N]; //! 当前j——i这个区间内，每一个数出现的次数

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    int res = 0; //! 表示答案

    for(int i = 0, j = 0; i < n; i++)
    {
        s[a[i]]++;

        while(s[a[i]] > 1)
        {
            s[a[j]]--; //! 动态统计我们这个区间里有多少个数  因为往右边移动一位 所以当时 j 所指的数减少一次
            j++; //! j 往右边移动一位
        }
        res = max(res, i - j + 1); // todo 更新区间的长度
    }
    cout << res;

    return 0;
}
