#include <iostream>

using namespace std;

int n;
int ans;

int solve(int n)
{
    int surplus = 0;
    while(n)
    {
        ans += n / 3;
        surplus += n % 3;
        n /= 3;
    }
    return surplus;
}

int main(void)
{
    scanf("%d", &n);
    ans += n;
    while(n >= 3) n = solve(n);
    printf("%d\n", ans);
    return 0;
}
