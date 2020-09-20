#include <iostream>

using namespace std;

int sum;

int main(void)
{
    int i = 1;
    while(i <= 100) sum += i++;
    printf("%d\n", sum);
    return 0;
}
