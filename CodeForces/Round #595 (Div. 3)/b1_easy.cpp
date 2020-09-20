#include <iostream>
#include <vector>

using namespace std;

int n, q;

int main(void)
{
    cin >> q;
    while(q--)
    {
        cin >> n;
        vector<int> p(n + 1);
        for(int i = 1; i <= n; i++) cin >> p[i];

        for(int i = 1; i <= n; i++)
        {
            int count = 1;
            int pos = p[i]; //! 初始化第一次的时候

            while(pos != i) pos = p[pos], count++;
            cout << count << " ";
        }
        cout << endl;
    }
    return 0;
}
