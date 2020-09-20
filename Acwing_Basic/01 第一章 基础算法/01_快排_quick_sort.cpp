#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, q[N];

void quick_sort(int q[], int l, int r)
{
    //*因为没有返回值（void） 所以直接用return 这是递归的结束条件
    if(l >= r) return;
    //!第二步 取x的值 随便取
    int x = q[(l + r) >> 1]; //!取中间

    int i = l - 1, j = r + 1; //!选择两个指针，取两侧

    while(i < j)
    {
        do
            i++;
        while(q[i] < x); //!只要q[i]<x 就说明已经站好位置了
        do
            j--;
        while(q[j] > x); //! i++和 j--一直在动 左边有数比x大 右边有数比x小
        //!只要两个指针没有相遇，就把他们交换
        if(i < j)
            swap(q[i], q[j]);
        else
            break;
    }
    //!运行完上面那个while循环 左边的数都是比x小的 右边的数都是比x大的
    quick_sort(q, l, j); //! 这里只能 j   i会发生错误
    quick_sort(q, j + 1, r);
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]); //!用scanf读入比用cin快
                            //!当读入多个数的时候 scanf快
    quick_sort(q, 0, n - 1);

    for(int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}
