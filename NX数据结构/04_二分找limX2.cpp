#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, x;
int a[N];

int main(void)
{
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]); // 输入的是一个升序的序列
    int l = 0, r = n - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    if(a[r] == x || r == 0)
        printf("%d\n", a[r]);
    else
        printf("%d\n", (a[r] - x) < (x - a[r - 1]) ? a[r] : a[r - 1]);
    return 0;
}
