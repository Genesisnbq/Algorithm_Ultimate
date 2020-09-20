//! 滚动数组
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a = 0, b = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << a << ' ';
        int fn = a + b;
        a = b, b = fn;
    }

    return 0;
}
