#include <iostream>
using namespace std;

int a, b;

int main(void)
{
    scanf("%d%d", &a, &b);
    if(a == b || a + 1 == b || (a == 9 && b == 1))
    {
        if(a + 1 == b)
            return !printf("%d %d\n", a, b);
        else if(a == b)
            return !printf("%d %d\n", a * 10, a * 10 + 1);
        else
            return !printf("%d %d", a, b * 10);
    }
    else
        puts("-1");
    return 0;
}
