#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int n;
int q[N], tmp[N];

LL merge_sort(int q[], int l, int r)
{
    if(l >= r) return 0;

    int mid = (l + r) >> 1;
    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j]) // todo 平时merge_sort可以<   但是求逆序对 必须<=  等于的数不是逆序对
            tmp[k++] = q[i++];
        else
        {
            tmp[k++] = q[j++]; //!如果q[i] >q[j] 那么   从i到mid 的数 都是大于q[j]的
            res += mid - i + 1; //!所以,逆序对的数量为 mid-i+1
        }
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    //!物归原主
    for(int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j]; //! i 表示 原数组  j表示 替换数组

    return res;
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    printf("%lld\n", merge_sort(q, 0, n - 1));

    return 0;
}
