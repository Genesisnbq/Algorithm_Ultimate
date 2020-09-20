#include <iostream> //这是我自己的思想做数的范围

using namespace std;

const int N = 1e5 + 10;

int n, m, q[N];

int main(void)
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    while(m--)
    {
        int x;
        scanf("%d", &x);
        int ans = 0, start[100000], k = 0;
        for(int i = 0; i < n; i++)
        {
            if(q[i] == x)
            {
                ans = i;
                start[k++] = i;
            }
        }
        if(ans == 0) { printf("-1 -1\n"); }
        else
        {
            printf("%d %d\n", start[0], ans);
        }
    }
    return 0;
}