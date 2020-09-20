#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n, m;
int f[N], v[N], w[N];

int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &w[i]);

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
        {
            // 1. 删除一维之后, 发现 f[i][j] = f[i-1][j] 变为了 f[j] = f[j] 这是一个恒等式, 因此可以直接删除
            // 2. j<v[i] 没有意义, 所以j可以从v[i] 开始遍历, 因此可以删除if
            // ① f[j] = max(f[j], f[j - v[i]] + w[i]);              //①不等价
            // ② f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);     //②直接删去一维后的结果等价于这个
            // ③ f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]); //③实际上需要的
            // ①和②等价, 我们的状态转移方程是③
            //! 因为 j-v[i] 是严格<=j 的(j从v[i]开始枚举),所以 j<=(j-v[i]), 因此 f[j-v[i]]比 f[j]先算
            //! 综上: 他其实是第 i 层的 j-v[i], 而不是 i-1层的, 改成从大到小枚举就可以了
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    printf("%d\n", f[m]);
    return 0;
}
