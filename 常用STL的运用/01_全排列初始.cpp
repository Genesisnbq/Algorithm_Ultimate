#include <algorithm>
#include <iostream>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};

int main(void)
{
    do
    {
        for(int i = 0; i < 5; i++)
        {
            if(i > 0) printf(" ");
            printf("%d", a[i]);
        }
        puts("");
    } while(next_permutation(a, a + 5));

    return 0;
}
