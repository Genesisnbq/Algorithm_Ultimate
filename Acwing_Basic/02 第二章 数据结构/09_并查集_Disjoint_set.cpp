//! 启发式合并(按秩合并)
//! 通过 size 合并

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int p[N];
int n, m;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]); //! 递归 路径压缩
    return p[x];                     //! 最后返回的是 x的祖宗节点
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) p[i] = i; //* n个数 分别从 1-n 初始化下标

    while(m--)
    {
        string op;
        int a, b;
        cin >> op >> a >> b;

        if(op == "M")
            p[find(a)] = find(b); // todo 让 a 的父亲节点变成 b的祖宗节点
        else
        {
            if(find(a) == find(b))
                puts("Yes"); //! puts 自带换行
            else
                puts("No");
        }
    }
    return 0;
}
