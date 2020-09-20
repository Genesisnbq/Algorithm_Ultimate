//! 在 路径压缩 和 合并 时, 这些权值具有一定的属性
//! 意味着,权值代表着当前 节点 和 父节点 的某种关系
//! 通过这些,也可以将同一棵树下 两个节点的关系表示出来
//! 食物链属于加权并查集的分支, 种类并查集

// todo d[] 表示编号 i 与父亲节点的权值关系
// todo 0->同种动物 1->捕食关系 2->被捕食关系
// todo 记录一下每个点和根节点之间的关系 d[]

#include <iostream>
using namespace std;

const int N = 5e4 + 10;

int d[N], p[N];
int n, k;
int ans;

void init()
{
    for(int i = 1; i <= n; i++) p[i] = i;
}

int find(int x)
{
    int t = p[x];
    if(t != x)
    {
        p[x] = find(t);
        d[x] = (d[x] + d[t]) % 3;
        return p[x];
    }
    else
        return t;
}

int main(void)
{
    scanf("%d%d", &n, &k);
    init();
    while(k--)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if((x > n || y > n) || (op == 2 && x == y)) // todo 白痴情况,超过数字编号或者自己吃自己
        {
            ans++;
            continue;
        }
        int fx = find(x), fy = find(y);
        if(op == 1)
        {
            if(fx == fy && d[x] != d[y])
            {
                ans++;
                continue;
            }
            else if(fx != fy)
            {
                p[fx] = fy;
                d[fx] = (3 - d[x] + d[y]) % 3; //! 合并
            }
        }
        if(op == 2)
        {
            if(fx == fy)
            {
                int derivation = (d[x] - d[y] + 3) % 3;
                if(derivation != 1)
                {
                    ans++;
                    continue;
                }
            }
            else
            {
                p[fx] = fy;
                d[fx] = (3 - d[x] + d[y] + 1) % 3;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
