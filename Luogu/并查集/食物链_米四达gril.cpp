//! 本题关系的方向是有向的  a 和 b是敌对关系,那么 b 和 a 就不是敌对关系
//! 设 d[x] 表示 x 与 p[x] 的关系
// todo 关系传递的本质实际上是向量的运算
//! 0 表示同类, 1 表示 x 吃 p[x] , 2自然就表示 x 被 p[x] 吃
// todo a=(a,x) b=(b,y) 则 ab= a-b;
// todo 将关系 res 设为 res=ab
// todo  要想知道 ab, 因为 ab=a-b (a向量在b方向的投影,也就是第三条边)

#include <iostream>
using namespace std;

const int N = 5e4 + 10;

int n, k;
int d[N], p[N];
int ans, res;

int find(int x)
{
    if(p[x] != x)
    {
        int t = find(p[x]); //! 要先记录一下,不然这个值就改变了
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main(void)
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) p[i] = i;

    while(k--)
    {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if(a > n || b > n)
        {
            ans++;
            continue;
        }
        else if(op == 2 && a == b)
        {
            ans++;
            continue;
        }
        else
        {
            if(op == 1)
                res = 0;
            else
                res = 1;
            int x = find(a), y = find(b);
            if(x == y)
            {
                if(((d[a] - d[b]) % 3 + 3) % 3 != res)
                {
                    ans++;
                    continue;
                }
            }
            else
            {
                p[x] = y;
                d[x] = d[b] - (d[a] - res);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
