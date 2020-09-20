#include <iostream>
using namespace std;

int x;

int sum(int x)
{
    if(x == 0) return 0;
    return sum(x - 1) + x;
}

int main(void)
{
    scanf("%d", &x);
    printf("%d\n", sum(x));
    return 0;
}
