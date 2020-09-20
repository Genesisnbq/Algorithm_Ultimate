#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int heap[N], ih[N], hi[N];
int nsize;
int idx; //* 当前要插入的下标

//* 用两个数组映射堆和插入的相互下标
void heap_swap(int a, int b)
{
    swap(hi[a], hi[b]);
    swap(ih[hi[a]], ih[hi[b]]);
    swap(heap[a], heap[b]);
}

void down(int n)
{
    int min = n;
    int lson = 2 * n, rson = lson + 1;
    if(lson <= nsize && heap[lson] < heap[min]) min = lson;
    if(rson <= nsize && heap[rson] < heap[min]) min = rson;

    if(n != min)
    {
        heap_swap(n, min);
        down(min);
    }
}

void up(int u)
{
    while(u / 2 && heap[u] < heap[u / 2])
    {
        heap_swap(u / 2, u);
        u >>= 1;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    while(n--)
    {
        string op;
        cin >> op;
        if(op == "I")
        {
            int x;
            cin >> x;
            nsize++;
            idx++;
            heap[nsize] = x; //! 第size个插入的数
            ih[idx] = nsize, hi[nsize] = idx; //! 第size个插入的数在heap中的下标是 idx ，下标是idx的数是第size个插入的数
            up(nsize);
        }
        else if(op == "PM")
            cout << heap[1] << endl;
        else if(op == "DM")
        {
            heap_swap(1, nsize);
            nsize--;
            down(1);
        }
        else if(op == "D")
        {
            int k;
            cin >> k;
            //* 难受 如果不这样的话 直接下面用 ih[k]  按我的理解 可能会随着 heap_swap变化 所以固定住
            int now = ih[k];
            heap_swap(now, nsize);
            nsize--;
            down(now), up(now);
        }
        else
        {
            int k, x;
            cin >> k >> x;
            int now = ih[k];
            heap[now] = x;
            up(now), down(now);
        }
    }

    return 0;
}
