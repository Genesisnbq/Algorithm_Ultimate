#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N];

int quick_select(int q[], int l, int r, int k)
{
    if(l >= r) return q[l]; //!如果l =r 那么就只有一个数

    int x = q[(l + r) >> 1];
    int i = l - 1, j = r + 1;

    while(i < j) //做完这个 while 后 左半边的数 一定是 <=X的 而右半边的数一定是>= X 的
    {
        while(q[++i] < x)
            ;
        while(q[--j] > x)
            ;
        if(i < j) swap(q[i], q[j]);
    } //!递归结束后 有两种情况 ，一种是 i=j  另一种是 i=j+1

    int sl = j - l + 1;
    if(sl >= k)
        return quick_select(q, l, j, k); //!如果 左边数=的个数 >=k 就递归左边的
    else
        return quick_select(q, j + 1, r, k - sl); //!如果 左边的数< k 就递归右边的
}

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    printf("%d\n", quick_select(q, 0, n - 1, k));

    return 0;
}