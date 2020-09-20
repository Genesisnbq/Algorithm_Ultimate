#include <iostream>
using namespace std;

typedef long long ll;

int t, temp;
int a, b;

int main(void)
{
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d%d", &a, &b);
        int ans = 0;
        temp = abs(a - b);
        ans += temp / 5;
        temp %= 5;
        if(temp == 1 || temp == 2) ans++;
        if(temp == 3 || temp == 4) ans += 2;
        printf("%d\n", ans);
    }
    return 0;
}
