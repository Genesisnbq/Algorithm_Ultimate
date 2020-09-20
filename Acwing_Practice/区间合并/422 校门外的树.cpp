#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int l, r;
int res;
vector<pair<int, int>> interval;

void merge(vector<pair<int, int>>& interval)
{
    int st = -1, ed = -1;
    vector<pair<int, int>> ans;
    for(auto item : interval)
    {
        if(ed < item.first)
        {
            if(st != -1) ans.push_back({st, ed});
            st = item.first, ed = item.second;
        }
        else
            ed = max(ed, item.second);
    }
    if(st != -1) ans.push_back({st, ed});
    interval = ans;
}

int main(void)
{
    scanf("%d%d", &n, &m);
    n++; //!  因为 0-n, 所以要加一
    while(m--)
    {
        scanf("%d%d", &l, &r);
        interval.push_back({l, r});
    }
    sort(interval.begin(), interval.end());
    merge(interval);
    for(auto item : interval) res += (item.second - item.first + 1);
    printf("%d\n", n - res);
    return 0;
}
