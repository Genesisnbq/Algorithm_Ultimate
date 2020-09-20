#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map> //! 哈希表

using namespace std;

inline int bfs(string start) //! 用 bfs 求出来我们的最短距离
{
    string end = "12345678x"; //!  定义一下终点

    queue<string> q; //!宽搜需要定义一个队列
    unordered_map<string, int> dist; //! 距离数组

    q.push(start); //! 在队尾插入start
    dist[start] = 0; //!  表示最一开始 起点的距离是 0

    //* 上右下左
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while(!q.empty()) // todo 当队列不为空就执行
    {
        auto t = q.front(); //! 直到取完为止
        q.pop();

        int distance = dist[t];
        if(t == end) return distance; // todo 如果 t 是终点，就可以直接 return

        //!  状态转移
        int k = t.find('x'); //! 返回 x 的下标
        //* 将一维数组的下标,转化成二维数组的下标
        int x = k / 3, y = k % 3; //* 常用技巧 算 n*n 的格子里的坐标是多少

        for(int i = 0; i < 4; i++) //! 枚举一下 我们将哪个数放过来
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[k], t[a * 3 + b]); // todo 状态更新

                if(!dist.count(t))
                {
                    dist[t] = distance + 1;
                    q.push(t);
                } //! 等移动好了 push进去之后要 复位

                swap(t[k], t[a * 3 + b]); //! 格子复位
            }
        }
    }
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string start; //! 用 start 来存初始的状态
    for(int i = 0; i < 9; i++) //! 先把 9个字符读入
    {
        char c;
        cin >> c;
        start += c;
    }

    cout << bfs(start) << endl;

    return 0;
}
