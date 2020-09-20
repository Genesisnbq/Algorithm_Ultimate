#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int n;

int main(void)
{
    scanf("%d", &n);
    for(int a = 0; a <= n; a++)
        for(int b = a; b * b + a * a <= n; b++)
            for(int c = b; b * b + c * c + a * a <= n; c++)
            {
                int t = n - a * a - b * b - c * c;
                int d = sqrt(t);
                if(d * d == t)
                {
                    printf("%d %d %d %d\n", a, b, c, d);
                    return 0;
                }
            }
}
