#include <iostream>
#include <vector>
using namespace std;

const int N = 4;
int coins[N] = {1, 2, 5, 10};
int n;
vector<int> chosen;
int count;

void dfs(int u)
{
    if(u > n) return;
    if(u == n)
    {
        for(int i = 0; i < chosen.size(); i++)
        {
            if(i > 0) printf(" ");
            printf("%d", chosen[i]);
        }
        puts("");
        count++;
        return;
    }
    for(int i = 0; i < N; i++)
    {
        chosen.push_back(coins[i]);
        u += coins[i];
        dfs(u);
        chosen.pop_back();
        u -= coins[i];
    }
    return;
}

int main(void)
{
    scanf("%d", &n);
    dfs(0);
    printf("一共有: %d 种方案\n", count);
    return 0;
}
