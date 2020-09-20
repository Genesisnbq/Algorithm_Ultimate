//! https://www.luogu.org/problem/P1496

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int l, r;
int res;
vector<pair<int, int>> alls;

void merge(vector<pair<int, int>>& alls)
{
    //! st 和 ed 是当前维护区间的左右端点
    int st = -1e9 - 10, ed = -1e9 - 10;
    vector<pair<int, int>> ans;
    for(auto item : alls)
    {
        if(ed < item.first)
        {
            if(st != -1e9 - 10) ans.push_back({st, ed});
            st = item.first, ed = item.second;
        }
        else
            ed = max(ed, item.second);
    }
    if(st != -1e9 - 10) ans.push_back({st, ed});
    alls = ans;
}

int main(void)
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d", &l, &r);
        alls.push_back({l, r});
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    merge(alls);
    for(auto item : alls) res += item.second - item.first;

    printf("%d\n", res);
    return 0;
}
