#include <iostream>
#define sentinel 2000000000
using namespace std;
const int N = 5e5 + 10;

int l[N / 2], r[N / 2];
int cnt;
int a[N], n;

void merge(int a[], int n, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++) l[i] = a[left + i];
    for(int i = 0; i < n2; i++) r[i] = a[mid + i];
    l[n1] = r[n2] = sentinel;
    int i = 0, j = 0;
    for(int k = left; k < right; k++)
    {
        cnt++;
        if(l[i] <= r[j])
            a[k] = l[i++];
        else
            a[k] = r[j++];
    }
}

void merge_sort(int a[], int n, int left, int right)
{
    if(left + 1 < right)
    {
        int mid = (left + right) / 2;
        merge_sort(a, n, left, mid);
        merge_sort(a, n, mid, right);
        merge(a, n, left, mid, right);
    }
}

int read()
{
    char c = getchar();
    int n = 0;
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9')
    {
        n = (n << 1) + (n << 3) + (c & 15);
        c = getchar();
    }
    return n;
}

int main(void)
{
    n = read();
    for(int i = 0; i < n; i++) a[i] = read();
    merge_sort(a, n, 0, n);
    for(int i = 0; i < n; i++)
    {
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
