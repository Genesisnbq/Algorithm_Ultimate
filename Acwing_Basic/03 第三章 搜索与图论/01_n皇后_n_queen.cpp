#include <iostream>

using namespace std;

const int N = 2e1;

int n;
bool col[N], dg[N], udg[N];
char g[N][N];

void dfs(int u)
{
    if(u == n)
    {
        for(int i = 0; i < n; i++) cout << g[i] << endl;
        cout << endl;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;

            dfs(u + 1); //! To the next level

            col[i] = dg[u + i] = udg[n - u + i] = false; //! recover site
            g[u][i] = '.';
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) g[i][j] = '.'; // todo  initialization gird  初始化格子

    dfs(0);

    return 0;
}
