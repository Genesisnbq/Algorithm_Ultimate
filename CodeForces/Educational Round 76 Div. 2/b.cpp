#include <iostream>
using namespace std;

typedef long long ll;

//! 开long long 防止爆 int

int t;
ll x, y;

//! 3*a/2
//! a--

ll op(ll x)
{
    return x * 3 / 2;
}

int main(void)
{
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> x >> y;
        if(x >= y)
        {
            puts("YES");
            continue;
        }
        else if(y != 1 && x == 1)
        {
            puts("NO");
            continue;
        }
        else
        {
            if(!(x & 1))
            {
                if(op(x) == y)
                {
                    puts("YES");
                    continue;
                }
                else
                {
                    if(op(x) != x + 1)
                    {
                        puts("YES");
                        continue;
                    }
                    else
                    {
                        puts("NO");
                        continue;
                    }
                }
            }
        }
        if(x & 1)
        {
            x--;
            if(x == y)
            {
                puts("YES");
                continue;
            }
            else if(op(x) == y)
            {
                puts("YES");
                continue;
            }

            else
            {
                if(op(x) != x + 1)
                {
                    puts("YES");
                    continue;
                }
                else
                {
                    puts("NO");
                    continue;
                }
            }
        }
    }
    return 0;
}
