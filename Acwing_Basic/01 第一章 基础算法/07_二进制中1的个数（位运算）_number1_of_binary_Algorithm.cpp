#include <iostream>

using namespace std;

int lowbit(int x)
{
    return x & -x; // todo 等价于 x&~x+1
}

int n;

int main(void)
{
    ios::sync_with_stdio(false);

    cin >> n;

    while(n--)
    {
        int x;
        cin >> x;

        int res = 0;
        while(x != 0) x -= lowbit(x), res++;

        cout << res << ' '; //*返回二进制是1的最后一位数
    }

    return 0;
}
