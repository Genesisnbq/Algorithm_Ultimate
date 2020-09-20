#include <iostream>

using namespace std;

const int N = 1e1;

int path[N], n;
bool st[N]; //! The bool type initiallization is false

void dfs(int u)
{
    if(u == n) //! Go to the end
    {
        for(int i = 0; i < n; i++) cout << path[i] << ' ';
        cout << endl;
        return;
    }
    //! At the beginning u=0
    for(int i = 1; i <= n; i++)
    {
        if(!st[i]) //! If it has not been used
        {
            path[u] = i;
            st[i] = true; //! i has been used

            dfs(u + 1);
            st[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dfs(0);

    return 0;
}
