//! int son[N][26]; // 其中存放的是：儿子节点对应的idx。其中son数组的第一是：父节点对应的idx，第二个数是：其直接子节点('str[i]' - 'a')的值为二维下标。
//! int cnt [N];    // 以“abc”字符串为例，最后一个字符‘c’对应的idx作为cnt数组的下标。数组的值是该idx对应的个数。
//! int idx;        // 将该字符串分配的一个树结构中，以下标来记录每一个字符的位置。方便之后的插入和查找。
#include <iostream>

using namespace std;

const int N = 1e5 + 10; //! 可能单词会很长 有很多个 “维度“

//* idx 的值表示第几个节点 第一个 idx=1
//* son开 N 是因为 可能会有很长的字符串（单词）
int son[N][26], cnt[N], idx; //! 下标是 0 的点，既是根节点又是空节点

//*插入
void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a'; //*把 a-z 映射成 0-25
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u]; //* 走到下一个点
    }
    cnt[p]++; //* 以这个点结尾的单词数量多了一个
}

//* 查询
int query(char str[]) //*返回字符串出现多少次
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u]; //! 否则的话 走过去
    }

    return cnt[p]; //! 返回以 p 结尾的单词数量就可以了
}

int n;
char str[N];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while(n--)
    {
        string op; //! 因为字符串数组 要有一位是 '\0' 所以开两个  或者直接用 string string不读入空格
        cin >> op >> str;

        if(op == "I")
            insert(str);
        else
            cout << query(str) << endl;
    }

    return 0;
}
