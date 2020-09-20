#include <cstring>
#include <iostream>
//! #include<queue>队列可以自己实现

using namespace std;

typedef pair<int, int> PII;

const int N = 1e2 + 10;

//* g存地图 d存每一个点到起点的距离
int n, m;
int g[N][N], d[N][N];
PII q[N * N]; //! 自己定义一个队列 存坐标  开大一点
//! PII Prev[N][N]; //! 存路径 取消注释即可

int bfs(void)
{
    int hh = 0, tt = -1;
    q[++tt] = {0, 0};

    memset(d, -1, sizeof d); //! 把所有距离初始化为 -1 表示这个点还没有走过
    d[0][0] = 0; //! 表示已经走过了

    while(hh <= tt) //! 队列不空
    {
        auto t = q[hh++]; //!  每一次取出队头，尝试往上下左右四个方向拓展（可以使用向量来做）

        //! 上右下左
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        // todo 每一次枚举一下四个方向
        for(int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) // todo 如果这个点还没有走过 并且是通的
            {
                d[x][y] = d[t.first][t.second] + 1; // todo 让 d 队头的值+1 赋给慢走条件的 x和 y
                q[++tt] = {x, y}; // todo 然后把队头的坐压入 队列中
                // Prev[x][y] = t;
            }
        }
    }
    return d[n - 1][m - 1];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> g[i][j];

    cout << bfs() << endl;

    // int x=n-1,y=m-1;
    // while(x||y)
    // {
    //     cout<<x<<' '<<y<<endl;
    //     auto t=Prev[x][y];
    //     x=t.first,y=t.second;
    // }

    return 0;
}
