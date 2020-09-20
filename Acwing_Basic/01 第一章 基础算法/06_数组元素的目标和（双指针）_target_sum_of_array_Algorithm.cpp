#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

int main(void)
{
    ios::sync_with_stdio(false); //! 取消cin和 scanf 的同步  提高cin速度

    cin >> n >> m >> x;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    for(int i = 0, j = m - 1; i < n; i++)
    {
        while(j >= 0 && a[i] + b[j] > x) // todo 都是单调性  i从最左 j从最右
            j--;

        if(a[i] + b[j] == x)
        {
            cout << i << ' ' << j << endl;
            break;
        }
    }

    return 0;
}
