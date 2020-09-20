// 创建有向图的邻接表
#include <iostream>
using namespace std;

const int MaxVnum = 100; //顶点数的最大值

typedef char VexType; //顶点的数据类型为字符型

typedef struct AdjNode //定义邻接点类型
{
    int index;            //邻接点下标
    struct AdjNode *next; //指向下一个邻接点
} AdjNode;

typedef struct VexNode
{                   //定义顶点类型
    VexType data;   //VexType为顶点的数据类型, 根据需要定义
    AdjNode *first; //指向第一个邻接点
} VexNode;

typedef struct //定义邻接表类型
{
    VexNode Vex[MaxVnum];
    int vexnum, edgenum; // 顶点数, 边数
} ALGraph;

int locatevex(ALGraph G, VexType x)
{
    for (int i = 0; i < G.vexnum; i++) //查找顶点信息的下标
        if (x == G.Vex[i].data)
            return i;
    return -1;
}

void insertEdge(ALGraph &G, int i, int j) //插入一条边
{
    AdjNode *s;
    s = new AdjNode;
    s->index = j;
    s->next = G.Vex[i].first;
    G.Vex[i].first = s;
}

void printGraph(ALGraph G)
{
    puts("------------邻接表如下: -----------");
    for (int i = 0; i < G.vexnum; i++)
    {
        AdjNode *t = G.Vex[i].first;
        cout << G.Vex[i].data << ": ";
        while (t != NULL)
        {
            cout << "[" << t->index << "] ";
            t = t->next;
        }
        puts("");
    }
}

void createALGraph(ALGraph &G) //创建有向图邻接表
{
    int i, j;
    VexType u, v;
    puts("请输入顶点数和边数: ");
    cin >> G.vexnum >> G.edgenum;
    puts("请输入顶点信息: ");
    for (i = 0; i < G.vexnum; i++) //输入顶点信息, 存入顶点信息数组
        cin >> G.Vex[i].data;
    for (i = 0; i < G.vexnum; i++) //初始化所有顶点
        G.Vex[i].first = NULL;
    puts("请依次输入每条边的两个顶点u,v");
    while (G.edgenum--)
    {
        cin >> u >> v;
        i = locatevex(G, u);
        j = locatevex(G, v);
        if (i != -1 && j != -1)
            insertEdge(G, i, j);
        else
        {
            puts("输入信息有误, 请重新输入!");
            G.edgenum++;
        }
    }
}

int main()
{
    ALGraph G;
    createALGraph(G);
    printGraph(G);
    return 0;
}