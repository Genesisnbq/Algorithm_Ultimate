#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n, x;
int a[N];
int main(void)
{
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    if(x <= a[0])
        printf("%d ", a[0]);
    else if(x >= a[n - 1])
        printf("%d ", a[n - 1]);
    else
    {
        int l = a[0], r = a[n - 1];
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(a[mid] - x < x - a[mid - 1])
                l = mid;
            else
                r = mid - 1;
        }
        printf("%d", a[l]);
    }
}
