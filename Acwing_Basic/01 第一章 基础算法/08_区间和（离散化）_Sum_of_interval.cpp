#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 3e5 + 10;

int n, m;
int a[N], s[N]; //! a数组是用来存数的 s数组是前缀和

vector<int> alls; //! 存的所有要离散化的值
vector<PII> add, quary; //* 加上   求区间和

//! 可以写成 lower_bound(alls.begin(),alls.end(),x)-alls.begin()+1
int find(int x) //! 找x的从1开始的下标位置
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(alls[mid] >= x)
            r = mid; //*要找到 最小的那个 >=X 的
        else
            l = mid + 1;
    }
    return r + 1; //* 因为要前缀和 所以下标要从1开始
}

int main(void)
{
    ios::sync_with_stdio(false);

    cin >> n >> m;

    while(n--)
    {
        int x, c;
        cin >> x >> c;

        add.push_back({x, c}); // todo 在下标x的位置加上c

        alls.push_back(x); //*把x放入我们的离散化数组
    }

    while(m--)
    {
        int l, r;
        cin >> l >> r;

        quary.push_back({l, r});

        alls.push_back(l); // todo 把左右区间都加入带离散化的数组里面
        alls.push_back(r); // todo 此时我们把所有需要用到的下标放到 alls里面
    }

    //! 去重
    sort(alls.begin(), alls.end()); //! 要去重 先排序    因为是位置 所以只要出现一次就好
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for(int i = 0; i < add.size(); i++) //!从1开始映射
    {
        int x = find(add[i].first);
        a[x] += add[i].second;
    }

    //!预处理前缀和
    for(int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    for(auto item : quary)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}
