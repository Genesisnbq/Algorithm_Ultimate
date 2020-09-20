#include <iostream>

using namespace std;

int sum;

int main(void)
{
    for(int i = 1; i <= 100; i++) sum += i;
    printf("%d\n", sum);
    return 0;
}
