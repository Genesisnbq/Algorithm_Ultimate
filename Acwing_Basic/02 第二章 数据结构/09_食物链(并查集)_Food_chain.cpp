#include <iostream>

using namespace std;

const int N = 5e4 + 10;

int n, m;
int p[N], d[N];

int find(int x)
{
    if(p[x] != x)
    {
        int t = find(p[x]); //! 因为要一步一步来（d[x]） 所以要 存一下 最后的祖宗节点
        d[x] += d[p[x]]; //* d[x] 到其父亲节点的距离+....+根节点
        p[x] = t; //! 路径压缩
    }
    return p[x]; //!返回祖宗
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) p[i] = i;

    int res = 0;

    while(m--)
    {
        int t, x, y;
        cin >> t >> x >> y;

        if(x > n || y > n)
            res++;
        else
        {
            int px = find(x), py = find(y);
            if(t == 1)
            {
                if(px == py && (d[x] - d[y]) % 3)
                    res++;
                else if(px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if(px == py && (d[x] - d[y] - 1) % 3) //* 最好写成这样
                    res++; //* 在一个集合并且关系不对
                else if(px != py) //! 如果不在一个集合
                {
                    p[px] = py; // todo 把x的父节点 指向 y的祖先 反过来也一样
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}
