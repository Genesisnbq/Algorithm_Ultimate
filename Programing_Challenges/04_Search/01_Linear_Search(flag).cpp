#include <iostream>
using namespace std;

const int N = 1e4 + 10;

int key, sum = 0;
int a[N];
int n, q;

int search(int a[], int n, int key)
{
    int i = 0;
    a[n] = key; //?  0-n-1   如果走到n了  就没有该值
    while(a[i] != key) i++;
    return i != n;
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &key);
        if(search(a, n, key)) sum++;
    }
    printf("%d\n", sum);
    return 0;
}
