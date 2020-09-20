#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int v[N], w[N];
int f[N][N];

int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &w[i]); //读入第i个物品的体积和价值, 从第一件物品开始, 所以i从1开始

    //1. f[n,0~m] 枚举所有的状态
    //2. f[0,0~m] ----> 选 0 个物品, 体积从 0~m
    //3. 同理 f[1,0~m] ---> 选1个物品, 体积从 0~m

    // 初始化可以不写, 因为默认都是 0
    for (int i = 1; i <= n; i++)     //枚举所有物品
        for (int j = 1; j <= m; j++) //枚举所有体积
        {
            f[i][j] = f[i - 1][j]; // 子集左边--->不包含第 i 个物品,并且总体积<=j
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    //最后的答案就是 f[n][m]
    printf("%d\n", f[n][m]);
    return 0;
}
