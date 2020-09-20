#include <cmath>
#include <iostream>

using namespace std;

const int N = 55;

int n;
int x[N];

int main(void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &x[i]);
    int leftToright = 0, rightToleft = 0;
    for(int i = 0; i < n; i++)
    {
        if(abs(x[i]) < abs(x[0]) && x[i] > 0) leftToright++;
        if(abs(x[i]) > abs(x[0]) && x[i] < 0) rightToleft++;
    }
    if(x[0] > 0 && rightToleft == 0 || x[0] < 0 && leftToright == 0)
        puts("1");
    else
        printf("%d\n", leftToright + rightToleft + 1);
    return 0;
}
