// 3^13 == 3^(1101)2  == 3^8 * 3^4 * 3^1
#include <iostream>
using namespace std;

typedef long long ll;

int a, k, p;
int n;

ll quick_pow(int a, int k, int mod)
{
    ll res = 1 % mod; //! 当 p等于 1时答案应该是 0
    while(k)
    {
        if(k & 1) res = (res * a) % mod;
        a = ( ll )a * a % mod; //! 强制转化为 long long 防止溢出 可以进一步优化为快速乘法
        k >>= 1;
    }
    return res;
}

int main(void)
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d%d", &a, &k, &p);
        printf("%lld\n", quick_pow(a, k, p));
    }
    return 0;
}
