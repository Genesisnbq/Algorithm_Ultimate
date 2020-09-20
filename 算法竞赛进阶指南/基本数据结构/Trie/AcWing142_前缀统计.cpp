#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n, m, idx;
char str[N];
int son[N][26];
int cnt[N];

void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    int ans = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return ans;
        p = son[p][u];
        if(cnt[p]) ans += cnt[p];
    }
    return ans;
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
