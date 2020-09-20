#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5;

int n;
int a[N];

void init(int n)
{
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
}

int main(void)
{
    scanf("%d", &n);
    init(n);
    do
    {
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                printf(" ");
            printf("%d", a[i]);
        }
        puts("");
    } while (next_permutation(a, a + n));

    return 0;
}
