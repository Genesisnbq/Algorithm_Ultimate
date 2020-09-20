#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int t;
int n, k;

int main(void)
{
    scanf("%d", &t);
    int girl = 0;
    while(t--)
    {
        bool st[N] = {false}; //标记已经配对的国家
        vector<int> list;
        scanf("%d", &n);
        if(n == 0)
        {
            int x = 0;
            scanf("%d", &x);
            continue;
        }
        bool married[N] = {false}; //标记已婚公主
        int cnt = 1;
        while(n--)
        {
            scanf("%d", &k);
            for(int i = 0; i < k; i++)
            {
                int x = 0;
                scanf("%d", &x);
                list.push_back(x);
            } //都是升序的
            bool judge = false;
            for(int i = 0; i < list.size(); i++)
            {
                if(!st[list[i]])
                {
                    st[list[i]] = true;
                    married[cnt] = true;
                    judge = true;
                    break;
                }
            }
            if(!judge) girl = cnt;
            cnt++;
        }
        if(girl == 0)
            puts("OPTIMAL");
        else
        {
            puts("IMPROVE");
            printf("%d ", girl);
            for(int i = 1; i < n; i++)
            {
                if(!st[i])
                {
                    printf("%d", i);
                    break;
                }
            }
        }
    }
    return 0;
}
