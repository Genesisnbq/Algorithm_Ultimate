#include <climits>
#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int n;
int a[N];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int maxv = INT_MIN;
    int minv = a[0];

    for(int i = 1; i < n; i++)
    {
        maxv = max(maxv, a[i] - minv);
        minv = min(minv, a[i]);
    }

    cout << maxv << endl;

    return 0;
}