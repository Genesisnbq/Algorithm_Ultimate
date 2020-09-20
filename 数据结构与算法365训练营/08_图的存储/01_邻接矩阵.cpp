#include <iostream>

using namespace std;

//邻接矩阵创建无向图
#define MaxVnum 100 //顶点数的最大值

typedef char VexType; //顶点的数据类型, 根据需要定义

typedef int EdgeType; //边上权值的数据类型, 若不带权值的图, 则为0或1

typedef struct
{
    VexType Vex[MaxVnum];
    EdgeType Edge[MaxVnum][MaxVnum];
    int vexnum, edgenum; //顶点数,边数
} AMGraph;

int locateVex(AMGraph G, VexType x)
{
    for (int i = 0; i < G.vexnum; i++) //查找顶点信息的下标
        if (x == G.Vex[i])
            return i;
    return -1; //没有找到
}

void createAMGraph(AMGraph &G)
{
    VexType u, v;
    int i, j;
    puts("请输入顶点数: ");
    cin >> G.vexnum;
    puts("请输入边数: ");
    cin >> G.edgenum;
    puts("请输入顶点信息: ");
    for (int i = 0; i < G.vexnum; i++) //输入顶点信息, 存入顶点信息数组
        cin >> G.Vex[i];
    for (int i = 0; i < G.vexnum; i++) //初始化邻接矩阵所有的值为0, 如果是网则0x3f3f3f3f
        for (int j = 0; j < G.vexnum; j++)
            G.Edge[i][j] = 0;
    puts("请输入每条边依附的两个顶点: ");
    while (G.edgenum--)
    {
        cin >> u >> v;
        i = locateVex(G, u); //查两个VexType的下标
        j = locateVex(G, v);
        if (i != -1 && j != -1)
            G.Edge[i][j] = G.Edge[j][i] = 1;
        else
        {
            puts("输入顶点信息有误! 请重新输入! ");
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

int main()
{
    AMGraph G;
    createAMGraph(G);
    print(G);
    return 0;
}