#include <iostream> //方法1,O(n^2)
using namespace std;
const int N = 1e6 + 10;
int n;
int a[N];
int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
    {
        int j = i + 1;
        while(j < n && a[i] > a[j]) j++;
        if(j == n) printf("%d ", a[i]);
    }
    return 0;
}
