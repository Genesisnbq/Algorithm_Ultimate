#include <cstdio> //! aoj中 c++ 要加 cstdio
#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int n, q;
int a[N], key;
int sum;

int binary_search(int key)
{
    int l = 0, r = n;
    int mid;
    while(l < r)
    {
        mid = (l + r) >> 1;
        if(key == a[mid]) return 1;
        if(key < a[mid])
            r = mid;
        else if(key > a[mid])
            l = mid + 1;
    }
    return 0;
}

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &key);
        if(binary_search(key)) sum++;
    }

    printf("%d\n", sum);
    return 0;
}
