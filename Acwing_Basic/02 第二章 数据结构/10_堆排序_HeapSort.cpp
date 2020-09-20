#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int heap[N], nsize;

void down(int n)
{
    int min = n; // todo 让 要 down的数 赋给 min
    int lson = 2 * n, rson = 2 * n + 1;

    if(lson <= nsize && heap[lson] < heap[min]) min = lson;
    if(rson <= nsize && heap[rson] < heap[min]) min = rson;

    if(n != min)
    {
        swap(heap[min], heap[n]);
        down(min); //! 交换了之后 可能比较大 所以试着往下面down
    }
}

void up(int u) // todo up操作
{
    while(u / 2 && heap[u / 2] > heap[u])
    {
        swap(heap[u / 2], heap[u]);
        u /= 2;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    nsize = n; // todo 有n个数 所以令长度等于 n

    for(int i = 1; i <= n; i++) cin >> heap[i]; //*读入

    for(int i = n / 2; i > 0; i--) down(i); //! 构建 堆数组

    while(m--)
    {
        cout << heap[1] << ' '; //! 输出堆顶（最小值）
        heap[1] = heap[nsize--]; //! 删除堆顶（用最后一个数覆盖第一个数） 并且长度 减1
        down(1); //!让覆盖好的数往下面走
    }

    return 0;
}
