#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int q[N], hh = 0, tt = -1;
int m;

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
            q[++tt] = x;
        }
        else if(op == "empty")
        {
            if(hh <= tt)
                cout << "NO" << endl; //! 队头<=队尾 非空  else 空
            else
                cout << "YES" << endl;
        }
        else if(op == "pop")
        {
            hh++;
        }
        else
        {
            cout << q[hh] << endl;
        }
    }

    return 0;
}
