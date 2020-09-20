#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    if(l >= r) return;

    int mid = (l + r) >> 1; //*第一步，确定分界点 mid
                            //!递归排左边和右边
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    //!难点:归并
    int k = 0, i = l, j = mid + 1; // !k表示当前tmp里面已经有多少个数了，两个序列合并的时候已经合并了几个数了
    //! i，j表示两个指针，i指向左半边的起点，j指向右半边的起点
    while(i <= mid && j <= r) //!当i比左半边的边界小（mid）的时候&并且 j比右半边的边界（r）小于等于的时候
        if(q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    //!循环之后，可能左半边没有循环完，也可能右半边没有循环完，就把剩下的移过来填入答案
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++]; //!因为不知道哪个没有循环完，所有就都判断一下

    //!最后我们需要把tmp里面的数，复制回我们的q里面去
    //!!!!  返回的是区间 因为递归的原因
    for(i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}

int main(void)
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    for(int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}
