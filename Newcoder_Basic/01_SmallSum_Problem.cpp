#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N], tmp[N];
int n;

int Merge(int q[], int l, int r)
{
    int mid = l + ((r - l) >> 1);
    int i = l, j = mid + 1, k = 0;
    int res = 0;
    while(i <= mid && j <= r)
    {
        if(q[i] < q[j])
        {
            res += (r - j + 1) * q[i];
            tmp[k++] = q[i++];
        }
        else
            tmp[k++] = q[j++];
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    for(int i = 0, j = l; i <= r; i++, j++) q[j] = tmp[i];
    return res;
}

int merge_sort(int q[], int l, int r)
{
    if(l == r) return 0;
    int mid = l + ((r - l) >> 1);
    return merge_sort(q, l, mid) + merge_sort(q, mid + 1, r) + Merge(q, l, r);
}

int main(void)
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> q[i];
    cout << merge_sort(q, 0, n - 1) << endl;
    return 0;
}
