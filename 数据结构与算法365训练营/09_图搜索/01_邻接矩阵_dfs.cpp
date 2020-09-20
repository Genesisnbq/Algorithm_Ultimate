#include <iostream>

using namespace std;

#define MaxVnum 100 //顶点数最大值

bool visited[MaxVnum]; // 访问标志数组, 其初值为"false"

typedef char VexType; //顶点的数据类型, 根据需要定义

typedef int EdgeType; //边上权值的数据类型, 若不带权值的图, 则为0或1

typedef struct
{
    VexType Vex[MaxVnum];
    EdgeType Edge[MaxVnum][MaxVnum];
    int vexnum, edgenum; // 顶点数, 边数
} AMGraph;

int locateVex(AMGraph G, VexType x)
{
    for (int i = 0; i < G.vexnum; i++) //查找顶点信息的下标
        if (x == G.Vex[i])
            return i;
    return -1;
}

void createAMGraph(AMGraph &G)
{
    int i, j;
    VexType u, v;
    puts("请输入顶点数: ");
    cin >> G.vexnum;
    puts("请输入边数: ");
    cin >> G.edgenum;
    puts("请输入顶点信息: ");
    for (int i = 0; i < G.vexnum; i++)
        cin >> G.Vex[i];
    for (int i = 0; i < G.vexnum; i++)
        for (int j = 0; j < G.vexnum; j++)
            G.Edge[i][j] = 0;
    puts("请输入每条边依附的两个顶点: ");
    while (G.edgenum--)
    {
        cin >> u >> v;
        i = locateVex(G, u);
        j = locateVex(G, v);
        if (i != -1 && j != -1)
            G.Edge[i][j] = G.Edge[j][i] = 1;
        else
        {
            puts("输入顶点信息有误! 请重新输入!");
            G.edgenum++; //本次输入不算
        }
    }
}

void print(AMGraph G) //输出邻接矩阵
{
    puts("图的邻接矩阵为: ");
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
            cout << G.Edge[i][j] << "\t";
        puts("");
    }
}

void AM_dfs(AMGraph G, int v) //基于邻接矩阵的深度优先遍历
{
    int w;
    cout << G.Vex[v] << "\t";
    visited[v] = true;
    for (w = 0; w < G.vexnum; w++)       //依次查看v 的所有邻接点
        if (G.Edge[v][w] && !visited[w]) //v,w邻接而且w未被访问过
            AM_dfs(G, w);                // 从w顶点开始递归深度优先遍历
}

int main()
{
    int v;
    VexType c;
    AMGraph G;
    createAMGraph(G);
    print(G);
    puts("请输入遍历连通图的起始点: ");
    cin >> c;
    v = locateVex(G, c); //查找顶点u的存储下标
    if (v != -1)
    {
        puts("深度优先搜索遍历连通图结果: ");
        AM_dfs(G, v);
    }
    else
        puts("输入顶点信息有误! 请重新输入! ");
    return 0;
}