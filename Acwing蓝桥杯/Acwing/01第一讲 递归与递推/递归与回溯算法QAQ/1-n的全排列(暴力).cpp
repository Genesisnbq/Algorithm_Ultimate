#include <iostream>
#define M 1000
using namespace std;

int n;

void f(int n)
{
    int x[M];
    for(x[1] = 1; x[1] <= n; x[1]++)
        for(x[2] = 1; x[2] <= n; x[2]++)
            for(x[3] = 1; x[3] <= n; x[3]++)
                for(x[4] = 1; x[4] <= n; x[4]++)
                {
                    //! 只要四个互不相同
                    if(x[1] != x[2] && x[1] != x[3] && x[1] != x[4] && x[2] != x[3] && x[2] != x[4] && x[3] != x[4]) printf("\n %d %d %d %d", x[1], x[2], x[3], x[4]);
                }
}

int main(void)

{
    scanf("%d", &n);
    f(n);
    return 0;
}
