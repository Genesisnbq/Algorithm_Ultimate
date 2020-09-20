#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int t, n;
int a[N];
int main(void)

{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int st = 0;
        int al = 0, ar = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if(i > 1 && abs(a[i] - a[i - 1]) >= 2)
            {
                st = 1;
                al = i - 1;
                ar = i;
                break;
            }
        }
        if(st)
            printf("YES\n%d %d\n", al, ar);
        else
            printf("NO\n");
    }
    return 0;
}
