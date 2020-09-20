#include <climits>
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

bool st[N];
int n;
int Min = INT_MAX, Max = INT_MIN;

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if(Min > x) Min = x;
        if(Max < x) Max = x;
        st[x] = true;
    }
    for(int i = 0; i <= 1000; i++)
    {
        if(!st[i]) return !printf("%d\n", i);
    }
    puts("0");
    return 0;
}
