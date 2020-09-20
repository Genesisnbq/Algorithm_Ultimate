#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c) //!这一步起初是把 b[]数组变为差分数组，使得 a[i]=b[1]+b[2]+....+b[i]
{
    b[l] += c;
    b[r + 1] -= c;
}

int main(void)
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for(int i = 1; i <= n; i++) insert(i, i, a[i]); //!把 b数组变成差分数组

    while(m--)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c); //!现在只需要修改两个数 l后面的数都 + c 然后r+1后面的数都 - c  +c-C抵消了
    }

    for(int i = 1; i <= n; i++) b[i] += b[i - 1]; //!把b[i] 变成自己的前缀和  等于操作后的原数组

    for(int i = 1; i <= n; i++) printf("%d ", b[i]);

    return 0;
}
