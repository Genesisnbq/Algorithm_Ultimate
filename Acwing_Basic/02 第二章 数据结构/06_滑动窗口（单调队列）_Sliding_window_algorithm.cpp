#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, k;
int a[N], q[N];
int hh = 0, tt = -1; //* 定义一下队头和队尾

int main(void) //? 单调性
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        //! q[]中存的只是下标 such as 队头的下标  队尾的下标
        //! 判断队头是否已经滑出窗口
        if(hh <= tt && i - k + 1 > q[hh]) hh++; // todo i-k+1>队头 就说明已经滑出了

        while(hh <= tt && a[q[tt]] >= a[i]) tt--; //! 不空 并且队尾 >=a[i]

        q[++tt] = i; //! a[i] 也有可能是最小的 所以得先把 a[i] 放进去
        if(i >= k - 1) cout << a[q[hh]] << ' ';
    }
    cout << endl;
    // todo 下面那部分 找窗口最大值和上面的最小值原理一样
    hh = 0, tt = -1;
    for(int i = 0; i < n; i++)
    {
        //! 判断队头是否已经滑出窗口
        if(hh <= tt && i - k + 1 > q[hh]) hh++; // todo 终点是 i   起点是 i-k+1
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;

        q[++tt] = i;
        if(i >= k - 1) cout << a[q[hh]] << ' ';
    }
    cout << endl;
}
