#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define N ( int )5e3 + 10

int n, m;
int s[N][N];

int main(void)
{
    int cnt, R;
    scanf("%d%d", &cnt, &R);
    R = min(R, 5001);
    n = m = R; //扩展到和R一样大
    while(cnt--)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        n=max(n,++x),m=max(m,++y);
        s[x][y] += w; //不同目标可能在同一位置
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    int res = 0;
    // 枚举所有边长是R的矩形, 枚举(i,j) 为右下角
    for(int i = R; i <= n; i++)
        for(int j = R; j <= m; j++) res = max(res, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]);
    printf("%d\n", res);
    return 0;
}
