#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int stk[N], tt; //! 顶层 默认初始化为 0

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        while(tt != 0 && stk[tt] >= x) tt--; //! tt不等于0 并且 stk[tt]>=x 就让 tt--

        if(tt != 0)
            printf("%d ", stk[tt]); //! 等价于 如果 tt 不等于0 就输出
        else
            printf("-1 "); //! tt  等于 0 就 输出 -1

        stk[++tt] = x; //! 把 x 压入栈中
    }

    return 0;
}
