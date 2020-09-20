#include <iostream> //!  当 mod 为质数时, 可以用快速幂求逆元
using namespace std;

typedef long long ll;

int n;
int a, p;

ll quick_pow(int a, int k, int mod)
{
    ll res = 1 % p;
    while(k)
    {
        if(k & 1) res = res * a % mod;
        k >>= 1;
        a = ( ll )a * a % mod;
    }
    return res;
}

int main(void)
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d", &a, &p);
        if(a % p == 0) //! 如果 a 是 p的倍数, 那么此时没有逆元
            puts("impossible");
        else
            printf("%d\n", quick_pow(a, p - 2, p));
    }
    return 0;
}
//!  a / b ≡ a * x (mod n)
//! 两边同乘b可得 a ≡ a * b * x (mod n)
//! 即 1 ≡ b * x (mod n)
//! 同 b * x ≡ 1 (mod n)
//! 由费马小定理可知，当n为质数时
//!  b ^ (n - 1) ≡ 1 (mod n)
//! 拆一个b出来可得 b * b ^ (n - 2) ≡ 1 (mod n)
//! 故当n为质数时，b的乘法逆元 x = b ^ (n - 2)

//! 当n不是质数时，可以用扩展欧几里得算法求逆元：
//! 有逆元的充要条件是a与p互质，所以gcd(a, p) = 1
//! 假设a的逆元为x，那么有a * x ≡ 1 (mod p)
//! 等价：ax + py = 1
//! exgcd(a, p, x, y)
