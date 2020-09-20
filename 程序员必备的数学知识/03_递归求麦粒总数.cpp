#include <iostream>

using namespace std;

int n;
int ans = 1;

void get_wheat(int u, int cur)
{
    if (u == n + 1)
    {
        printf("%d\n", ans);
        return;
    }
    cur *= 2;
    ans += cur;
    get_wheat(u + 1, cur);
    return;
}

int main(void)
{
    scanf("%d", &n);
    get_wheat(2, 1);
    return 0;
}
