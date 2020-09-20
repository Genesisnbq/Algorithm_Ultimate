#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int m;
int stk[N];
int tt = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m;
    while(m--)
    {
        string op;
        cin >> op;

        int x;

        if(op == "push")
        {
            cin >> x;
            stk[++tt] = x;
        }

        else if(op == "pop")
        {
            tt--;
        }
        else if(op == "empty")
        {
            if(tt == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            cout << stk[tt] << endl;
        }
    }
    return 0;
}
