#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 31 * N;

int a[N], son[M][2];
int n, idx;

void insert(int x)
{
    int p = 0;
    for(int i = 30; i >= 0; i--)
    {
        //*从右往左 0-30位下标的二进制
        int u = x >> i & 1; // todo 求 n 的第 i 位数字(二进制)
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x)
{
    int p = 0;
    int res = 0;
    for(int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if(son[p][!u])
        {
            //! res+=res*2+u
            res += 1 << i;
            p = son[p][!u];
        }
        else
        {
            p = son[p][u];
            //! res+=res*2  类似于 10进制
        }
    }
    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    int res = 0;

    for(int i = 0; i < n; i++)
    {
        insert(a[i]); //* 先插入 省了一步特判是否为空
        int t = query(a[i]); //* 返回和 a[i] XOR最大的数  或者值   （两种 query的方法）
        res = max(res, t); // todo 如果是  注释的那种方法的话 就要 去掉 a[i]
    }

    cout << res << endl;

    return 0;
}
