//! https://www.acwing.com/problem/content/145/
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int a[N];
int n;
int res = 0;

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) res = max(res, a[i] ^ a[j]);
    printf("%d\n", res);
    return 0;
}
