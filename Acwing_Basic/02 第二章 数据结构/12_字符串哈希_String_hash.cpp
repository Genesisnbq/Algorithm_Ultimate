#include <iostream>

using namespace std;

typedef unsigned long long ull;

const int N = 1e5 + 10;

int n, m;
char str[N];
ull h[N], p[N];
int P = 131; //! 或者13331

ull get(int l, int r) //! 获取区间哈希值的公式 就是一个进制问题
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> (str + 1);

    p[0] = 1; //*p的 0 次方为 1

    for(int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i]; //! 只要 str[i] 保证不是 0， 其他是多少否无所谓
    }

    while(m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if(get(l1, r1) == get(l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
