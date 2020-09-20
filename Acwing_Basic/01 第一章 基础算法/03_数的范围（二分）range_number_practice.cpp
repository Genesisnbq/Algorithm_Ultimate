#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int q[N];

int main(void)
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    //! 有个询问，对于每个询问，m--
    while(m--)
    {
        int x;
        scanf("%d", &x);
        //!第一步二分，先二分一下起始坐标
        int l = 0, r = n - 1;
        while(l < r) //todo 这就是在一次一次地进行二分操作
        {
            int mid = (l + r) >> 1;
            if(q[mid] >= x)
                r = mid; //todo 第一个模板 >=x 是找第一个x  也就是说 是左边的第一个x
            else
                l = mid + 1;
        } //! 这个while循环结束之后  l 和 r 是相等的
          //! 如果x不存在，那么这个值就一定不等于x
        if(q[l] != x)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << ' ';
            //! 接下来做右边界
            int l = 0, r = n - 1;
            while(l < r)
            {
                int mid = (l + r + 1) >> 1; //! 第二个模板，所以要补上加1   <=x 画一个数轴   是找最右边的x
                if(q[mid] <= x)
                    l = mid; //! 第二个模板 在右边部分
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}
