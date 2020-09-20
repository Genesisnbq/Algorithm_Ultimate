#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int t;
int n, k1, k2;
vector<int> a;
vector<int> b;

int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        int c;
        a.clear();
        b.clear();
        scanf("%d%d%d", &n, &k1, &k2);
        for(int i = 0; i < k1; i++)
        {

            scanf("%d", &c);
            a.push_back(c);
        }
        for(int i = 0; i < k2; i++)
        {
            scanf("%d", &c);
            b.push_back(c);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a[k1 - 1] > b[k2 - 1])
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
