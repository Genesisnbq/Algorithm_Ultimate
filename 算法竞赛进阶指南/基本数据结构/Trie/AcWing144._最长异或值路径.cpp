//! 学完邻接表和dfs再回来
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

//! 接下来是 n-1 行 因为根节点也算作一个节点
//! 定义路径上只有一个点的时候, 他的权值定义为 0
//! 我们要求这条路径上, 权值异或的最大值是多少
// todo a 到 b 上的所有边的异或和 ==a到root ^ b到root的异或和 ^ c到root的异或和 ^ c到root的异或和
// todo 异或运算中, 把东西加到这个集合和把东西从集合中去掉的符号都是一样的
//! 所以从 a到b的异或和 == a到root的异或和 ^ b到root的异或和

int main(void)
{

}
