#include <iostream> //* 只有第三个操作和模板不同 其他都差不多

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];
int cnt[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]); // todo 路径压缩
    return p[x];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) p[i] = i, cnt[i] = 1; //!初始化

    while(m--)
    {
        string op;
        int a, b;

        cin >> op;

        if(op == "C")
        {
            cin >> a >> b;
            if(find(a) != find(b))
            {
                cnt[find(b)] += cnt[find(a)];
                p[find(a)] = find(b);
            }
        }
        else if(op == "Q1")
        {
            cin >> a >> b;
            if(find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
    return 0;
}
