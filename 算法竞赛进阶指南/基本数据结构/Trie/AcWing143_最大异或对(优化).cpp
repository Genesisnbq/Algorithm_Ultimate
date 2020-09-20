//! https://www.acwing.com/problem/content/145/
//! 每次固定一个数字
//! 最高位是0的话是最好,因为需要异或
//! 观察一个数, 是否存在一个数, 使得最高位是0
//! 一次类推,观察一下是否存在一些数字,是0最好
//! let's go
//! 把trie两大类, 把最高位是 1 的分成一类, 把最高位是 0 的分成一类
#include <iostream>
using namespace std;

// todo 10万个数, 每个数的长度是 31 所以是 1e5 * 31
const int N = 1e5 + 10, M = 31 * N;

int n;
int a[N];
int son[M][2], idx;

void insert(int x)
{
    int p = 0;
    for(int i = 30; ~i; i--) // todo ~i 相当于就是 i>=0的意思  以为 -1 表示 1111 1111(0xff)然后取反 就是0
    {
        int& s = son[p][x >> i & 1]; // todo 先从 x的最高位走起 1000110 -> bulid trie
        if(!s) s = ++idx; //! 创建新节点
        p = s;
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for(int i = 30; ~i; i--)
    {
        int s = x >> i & 1; //! 看一下x的二进制表示中, 第 k位是 0还是 1 >>30表示最高位是 0还是 1
        if(son[p][!s])
        {
            res += 1 << i; // todo res = res*2 + !s
            p = son[p][!s];
        }
        else
            p = son[p][s];
    }
    return res;
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int res = 0;
    for(int i = 0; i < n; i++) res = max(res, query(a[i]));
    printf("%d\n", res);
    return 0;
}
