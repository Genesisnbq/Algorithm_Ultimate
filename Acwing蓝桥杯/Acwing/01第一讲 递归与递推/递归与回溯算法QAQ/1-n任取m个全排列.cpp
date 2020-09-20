#include <iostream>
using namespace std;

const int N = 1e2 + 10;

int n, m;
int x[N];

int jianzhi(int k)
{
    for(int i = 1; i < k; i++)
    {
        if(x[i] == x[k]) return 0;
    }
    return 1;
}

void f(int k)
{
    if(k == m + 1)
    {
        for(int i = 1; i <= m; i++)
        {
            if(i > 1) printf(" ");
            printf("%d", x[i]);
        }
        puts("");
        return;
    }
    for(x[k] = 1; x[k] <= n; x[k]++)
    {
        if(jianzhi(k)) f(k + 1);
    }
}

int main(void)
{
    scanf("%d%d", &n, &m);
    f(1);
    return 0;
}
