#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int t;

inline int read()
{
    char c = getchar();
    int n = 0;
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9')
    {
        n = (n << 1) + (n << 3) + (c & 15);
        c = getchar();
    }
    return n;
}

//!  a 和 b 是竞争对手
//!  最多可以交换 x 次
//! 1-n

int main(void)
{
    t = read();
    while(t--)
    {

        int n = read(), x = read(), a = read(), b = read();
        if(a > b) swap(a, b);
        int pos = b - a;
        while(a != 1 && x)
        {
            pos += 1;
            a--;
            x--;
        }
        while(b != n && x)
        {
            pos += 1;
            b++;
            x--;
        }
        printf("%d\n", pos);
    }
    return 0;
}
