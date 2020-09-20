#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, q[N];

int findMaximum(int q[], int l, int r)
{
    int mid = (l + r) >> 1;
    if(r - l == 1) return q[l];
    int u = findMaximum(q, l, mid);
    int v = findMaximum(q, mid, r);
    return max(u, v);
}

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> q[i];
    cout << findMaximum(q, 0, n - 1) << endl;
    return 0;
}
