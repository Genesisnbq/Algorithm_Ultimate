#include <cstring> //todo 普通情况下, 二分要比散列法快
#include <iostream>

using namespace std;

const int N = 2e5 + 3; // todo 大于2e5 的滴哦一个质数是 2e5+3
const int null = 0x3f3f3f; // todo 0x3f3f3f3f比 1e9大

int n;
int h[N];

//* 如果 x 存在 返回的是 x 存储的位置
//* 如果不存在，返回的是 x 应该存储的位置
int find(int x)
{
    int k = (x % N + N) % N;

    while(h[k] != null && h[k] != x)
    {
        k++;
        if(k == N) k = 0;
    }
    return k;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    memset(h, 0x3f, sizeof h); //! h这是数组是 int型  memset是按字节来分配 所以每一个字节是 0x3f

    while(n--)
    {
        string op;
        int x;
        cin >> op >> x;
        if(op == "I")
        {
            int k = find(x);
            h[k] = x;
        }
        else
        {
            int k = find(x);
            if(h[k] == x)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
