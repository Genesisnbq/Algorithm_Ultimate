//! https://codeforces.com/contest/1200/problem/E
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std; //! 用到的时候在前面 添加 std::min 就行

const int N = 2e6 + 10;
const int m1 = 998244353;
const int m2 = 1000001011;
const int K = 131;

typedef long long ll;

int q, h1[N], h2[N];
int len, p1[N], p2[N];
char s[N];

void add(char s)
{
    h1[len + 1] = (( ll )h1[len] * K + s) % m1;
    h2[len + 1] = (( ll )h2[len] * K + s) % m2;
    len++;
}

//! 获取第一段哈希值
int get1(int l, int r)
{
    return (ll)(h1[r] - h1[l - 1] + m1) * p1[l - 1] % m1;
}
//! 获取第二段哈希值
int get2(int l, int r)
{
    return (ll)(h2[r] - h2[l - 1] + m2) * p2[l - 1] % m2;
}

//! 双重哈希判断是否相等
bool cmp(int l1, int r1, int l2, int r2)
{
    return get1(l1, r1) == get1(l2, r2) && get2(l1, r1) == get2(l2, r2);
}

ll quick_pow(int x, int y, int mod) //! 快速幂
{
    ll res = 1 % mod;
    while(y)
    {
        if(y & 1) res = res * x % mod;
        x = ( ll )x * x % mod;
        y >>= 1;
    }
    return res;
}

int main(void)
{
    p1[0] = p2[0] = 1;
    int k1 = quick_pow(K, m1 - 2, m1); //! 求第一段哈希的逆元 找出与 k互质的数
    int k2 = quick_pow(K, m2 - 2, m2); //! 求第二段哈希的逆元 找出与 k互质的数
    for(int i = 1; i < N; ++i)
    {
        // todo 从 1开始加入
        p1[i] = ( ll )p1[i - 1] * k1 % m1; //!  算一下各段的 base 的 n次方 O(N)
        p2[i] = ( ll )p2[i - 1] * k2 % m2;
    }
    scanf("%d", &q);

    while(q--)
    {
        //* scanf 读入空格就结束
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        for(int i = 1; i <= n; i++) add(s[i]);
        //! 先把当前串加到答案串的后面，可以方便地求哈希
        for(int i = min(n, len - n); i >= 0; i--)
        {
            if(cmp(len - n - i + 1, len - n, len - n + 1, len - n + i))
            {
                len -= n; //! 确定了要加多长再真正地加进去
                for(int j = i + 1; j <= n; j++) add(s[j]);
                printf("%s", s + i + 1);
                break;
            }
        }
    }
    return 0;
}
