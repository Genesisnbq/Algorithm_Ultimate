#include <iostream>
using namespace std;

const int N = 21;

long long f[N];

int main(void)
{
    f[1] = 2;
    for(int i = 2; i <= N + 1; i++) f[i] = f[i - 1] * 2;
    printf("%lld\n", f[20]);
    return 0;
}
