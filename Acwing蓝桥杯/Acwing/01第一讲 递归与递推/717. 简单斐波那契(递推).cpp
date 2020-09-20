#include <iostream>
using namespace std;

const int N = 5e1;

int n;
int fibonacci[N];

int main(void)
{
    scanf("%d", &n);
    fibonacci[1] = 0; //! init
    fibonacci[2] = 1;
    for (int i = 3; i <= n; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]; //! 递推
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            printf(" ");
        printf("%d", fibonacci[i]);
    }
    return 0;
}
