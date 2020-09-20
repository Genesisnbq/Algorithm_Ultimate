#include <iostream>
#include <vector>
using namespace std;

int q, n;
int main(void)
{
    cin >> q;
    while(q--)
    {
        cin >> n;
        vector<int> p(n + 1);

        for(int i = 1; i <= n; i++) cin >> p[i];

        vector<int> used(n + 1);
        vector<int> ans(n + 1); //* 初始化应该都为0

        for(int pos = 1; pos <= n; pos++)
        {
            if(!used[pos])
            {
                vector<int> cur;
                while(!used[pos]) cur.push_back(pos), used[pos] = true, pos = p[pos];
                for(auto el : cur) ans[el] = cur.size();
            }
        }
        for(int i = 1; i <= n; i++) cout << ans[i] << " "; //? 因为cur中不可能有 0这个下标 所以我们从1开始
        cout << endl;
    }
    return 0;
}
