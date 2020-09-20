#include <algorithm>
#include <iostream>

using namespace std;

int t;
int a[3];

int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        for(int i = 0; i < 3; i++) scanf("%d", &a[i]);
        sort(a, a + 3);
        if(a[0] + a[1] + 1 >= a[2]) //! 隔板原理, 鸽笼原理  最大的 n, 有 n-1个格子
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
