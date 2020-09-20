#include <cstring> //! memset在这个 lib 里面
#include <iostream>

using namespace std;

const int N = 1e5 + 3; //! 取大于1e5的第一个质数，取质数冲突的概率最小 可以百度

//* h[k] 存的是第一个链表的下标
int h[N]; //* 开一个槽
int e[N], ne[N], idx;
int n;

void insert(int x)
{
    int k = (x % N + N) % N; //! c++中如果是负数 那他取模也是负的 所以 加N 再 %N 就一定是一个正数

    e[idx] = x, ne[idx] = h[k], h[k] = idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N; // todo 用上面同样的 Hash函数 讲x映射到 从 0-1e5 之间的数

    for(int i = h[k]; i != -1; i = ne[i]) //! h[k] 不为空
    {
        if(e[i] == x) return true;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    // todo 对 h这个数组全部初始化为 -1 （空）
    memset(h, -1, sizeof h); // todo 将槽先清空 空指针一般用 -1 来表示

    while(n--)
    {
        string op;
        int x;
        cin >> op >> x;
        if(op == "I")
            insert(x);
        else
        {
            if(find(x))
                puts("Yes");
            else
                puts("No");
        }
    }

    return 0;
}
