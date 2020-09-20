#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e2 + 10;

int q;
int a[N];
int res;

int main(void)
{
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);

        for(int i = 0; i < n - 1; i++)
        {
            if(a[i + 1] - a[i] == 1) res++;
        }
        if(res == 0)
            cout << "1" << endl;
        else
            cout << "2" << endl;
        res = 0;
    }
    return 0;
}
