//! a 要有逆元就是 a与p 互质== gcd(a,p)==1
//! 假设 a 的逆元为 x , 那么有 a*x==1 (mod p)

#include <iostream>
using namespace std;
typedef long long ll;
int n;

int exgcd(int a, int p, int& x, int& y)
{
    if(!p)
    {
        x = 1, y = 0;
        return a;
    }
    int res = exgcd(p, a % p, y, x);
    y -= a / p * x;
    return res;
}

int main(void)
{
    scanf("%d", &n);
    while(n--)
    {
        int a, p, x, y;
        scanf("%d%d", &a, &p);
        int ans = exgcd(a, p, x, y);
        if(ans == 1)
            printf("%lld\n", (( ll )x + p) % p); //!保证x是正数
        else
            puts("impossible");
    }
    return 0;
}
