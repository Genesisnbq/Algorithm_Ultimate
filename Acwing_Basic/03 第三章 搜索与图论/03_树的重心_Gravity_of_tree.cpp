#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = N * 2;

//* h 存的是 n 个链表的链表头
//* e 存每一个节点的值是多少
//* ne 存每一个节点的next指针是多少
int h[N], e[M], ne[M], idx;
bool st[N]; //! 存哪些点已经被遍历过了
int n;

int ans = N; //! 记录一个全局的答案 最小的最大值所以刚开始定义 ans为 N

void insert(int a, int b) //! 插入一条 a 指向 b 的边
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

//* 以 u 为根的子树中点的数量
int dfs(int u)
{
    st[u] = true; //* 标记当前这个点已经被搜索过了

    //*res是把这个点删除之后，每一个连通块大小的最大值
    int sum = 1, res = 0;

    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        //* 用 s 来表示当前子树的大小
        if(!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    memset(h, -1, sizeof h); //! 让每个头节点都指向-1 初始化为-1

    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        insert(a, b), insert(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}
