#include <iostream>
using namespace std;

const int N = 1e6 + 10, M = 5e5 + 10;

//! idx表示新开的节点的下标
int son[M][26], idx, cnt[N];
int n, m;
char str[N];

void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int& s = son[p][str[i] - 'a'];
        if(!s) s = ++idx;
        p = s;
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0, res = 0;
    for(int i = 0; str[i]; i++)
    {
        int& s = son[p][str[i] - 'a'];
        if(!s) break;
        p = s;
        res += cnt[p];
    }
    return res;
}

int main(void)
{
    scanf("%d%d", &n, &m);
    while(n--)
    {
        scanf("%s", str);
        insert(str);
    }
    while(m--)
    {
        scanf("%s", str);
        printf("%d\n", query(str));
    }
    return 0;
}
