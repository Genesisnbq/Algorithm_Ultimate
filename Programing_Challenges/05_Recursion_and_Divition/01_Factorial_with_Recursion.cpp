#include <iostream> //! 设计递归的时候需要留有一个终点
using namespace std;

int n;

long long solve(int n)
{
    if(n == 1) return 1;
    return n * solve(n - 1);
}

int main(void)
{
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
