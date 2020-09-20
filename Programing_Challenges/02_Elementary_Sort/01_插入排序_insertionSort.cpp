#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int a[N];
int n;

void trace(int a[], int n) //! 追踪每一个插排
{
    for(int i = 0; i < n; i++)
    {
        if(i > 0) cout << ' ';
        cout << a[i];
    }
    cout << endl;
}

void insertionSort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        int v = a[i];
        while(j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        trace(a, n);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    insertionSort(a, n);

    return 0;
}