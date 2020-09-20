#include <iostream>
using namespace std;

int a, b, fn;
int n;

int main(void)
{
    a = 0, b = 1;
    scanf("%d", &n);
    if(n == 1)
        printf("%d", a);
    else
    {
        printf("%d %d ", a, b);
        for(int i = 3; i <= n; i++)
        {
            fn = a + b;
            a = b, b = fn;
            printf("%d ", fn);
        }
    }
    puts("");
    return 0;
}
