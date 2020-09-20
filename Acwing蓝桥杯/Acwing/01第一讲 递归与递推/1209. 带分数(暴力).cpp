//! 数字 1-9 分别出现且只出现一次
/*

do
{}whie(next_permutation(start,end))

*/
//! ①枚举全排列
//! ②建设按照 a,b,c的顺序进行枚举  a|b|c
//! ③判断等式是否成立
#include <algorithm>
#include <iostream>

using namespace std;
const int N = 1e1;

int n;
int num[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int a, b, c;
int ans;

int getNum(int l, int r)
{
    int res = 0;
    for(int i = l; i <= r; i++) res = res * 10 + num[i];
    return res;
}

bool check(int a, int b, int c)
{
    if(b % c != 0 || a + b / c != n) return false;
    return true;
}

int main(void)
{
    scanf("%d", &n);
    do
    {
        for(int i = 0; i < 6; i++) // todo 数据范围 n < 1e6(7位) a,b,c是在1-6位之间的
        {
            for(int j = i + 1; j < 8; j++) //! 给c留了一位, c不能为 0
            {
                a = getNum(0, i);
                b = getNum(i + 1, j);
                c = getNum(j + 1, 8);
                if(check(a, b, c)) ans++;
            }
        }
    } while(next_permutation(num, num + 9));

    printf("%d\n", ans);
    return 0;
}
