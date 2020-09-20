#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

ll cnt;
int l, a[N], n;
vector<int> g;

void insertionsort(int a[], int n, int g) //* 间隔为 g 的插入排序
{
    for(int i = g; i < n; i++)
    {
        int v = a[i];
        int j = i - g;
        while(j >= 0 && a[j] > v)
        {
            a[j + g] = a[j]; //* j=i-g     j+g=i,i+1,i+2....
            j -= g;          //* 间隔为 g
            cnt++;
        }
        a[j + g] = v;
    }
}

void shellsort(int a[], int n)
{
    for(int h = 1;;) //! 生成 g 数组
    {
        if(h > n) break;
        g.push_back(h);
        h = 3 * h + 1;
    }

    for(int i = g.size() - 1; i >= 0; i--) insertionsort(a, n, g[i]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    shellsort(a, n);

    cout << g.size() << endl;

    for(int i = g.size() - 1; i >= 0; i--)
    {
        cout << g[i];
        if(i) cout << ' ';
    }
    cout << endl;

    cout << cnt << endl;

    for(int i = 0; i < n; i++) cout << a[i] << endl;

    return 0;
}
