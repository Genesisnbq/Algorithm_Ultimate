#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int a[N], n;

int selectionSort(int a[], int n)
{
    int sw = 0;
    for(int i = 0; i < n; i++)
    {
        int minj = i;
        for(int j = i; j < n; j++)
        {
            if(a[j] < a[minj]) minj = j;
        }
        swap(a[minj], a[i]);
        if(i != minj) sw++;
    }
    return sw; //* 输出交换的次数
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    int sw = selectionSort(a, n);

    cout << sw << endl;

    return 0;
}