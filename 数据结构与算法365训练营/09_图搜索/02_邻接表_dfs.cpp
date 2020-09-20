#include <iostream>

using namespace std;

const int MaxVnum = 100; //顶点数最大值

bool visited[MaxVnum];

typedef char VexType; //顶点的数据类型为字符型

typedef struct AdjNode
{
    int index;
    struct AdjNode *next;
} AdjNode;

typedef struct VexNode
{
    VexType data;
    AdjNode *first;
} VexNode;

typedef struct
{
    VexNode Vex[MaxVnum];
    int vexnum, edgenum;
} ALGraph;

int locateVex(ALGraph G, VexType x)
{
    for (int i = 0; i < G.vexnum; i++)
        if (x == G.Vex[i].data)
            return i;
    return -1;
}

void insertEdge(ALGraph &G, int i, int j)
{
    AdjNode *s;
    s = new AdjNode;
    s->index = j;
    s->next = G.Vex[i].first;
    G.Vex[i].first = s;
}

void print(ALGraph G)
{
    puts("-------------邻接表如下: --------------");
    for (int i = 0; i < G.vexnum; i++)
    {
        AdjNode *t = G.Vex[i].first;
        cout << G.Vex[i].data << ": ";
        while (t != NULL)
        {
            cout << "[" << t->index << "]";
            t = t->next;
        }
        puts("");
    }
}

void createALGraph(ALGraph &G) //创建无向图邻接表
{
    int i, j;
    VexType u, v;
    puts("请输入顶点数和边数: ");
    cin >> G.vexnum >> G.edgenum;
    puts("请输入顶点信息: ");
    for (i = 0; i < G.vexnum; i++) //输入顶点信息, 存入顶点信息数组
        cin >> G.Vex[i].data;
    for (i = 0; i < G.vexnum; i++)
        G.Vex[i].first = NULL;
    puts("请以此输入每条边的两个顶点u,v");
    while (G.edgenum--)
    {
        cin >> u >> v;
        i = locateVex(G, u);
        j = locateVex(G, v);
        if (i != -1 && j != -1)
        {
            insertEdge(G, i, j);
            insertEdge(G, j, i);
        }
        else
        {
            puts("输入顶点信息有误! 请重新输入!");
            G.edgenum++;
        }
    }
}

void AL_dfs(ALGraph G, int v) //基于邻接表的深度优先遍历
{
    int w;
    AdjNode *p;
    cout << G.Vex[v].data << "\t";
    visited[v] = true;
    p = G.Vex[v].first;
    while (p)
    {
        w = p->index;
        if (!visited[w])
            AL_dfs(G, w);
        p = p->next;
    }
}

void AL_dfs(ALGraph G) //非连通图, 基于邻接表的深度优先遍历
{
    for (int i = 0; i < G.vexnum; i++)
        if (!visited[i])
            AL_dfs(G, i);
}

int main()
{
    ALGraph G;
    int v;
    VexType c;
    createALGraph(G);
    print(G);
    puts("请输入遍历连通图的起始点: ");
    cin >> c;
    v = locateVex(G, c);
    if (v != -1)
    {
        puts("深度有点搜索遍历连通图结果: ");
        AL_dfs(G, v);
    }
    else
        puts("输入顶点信息有误! 请重新 输入! ");
    return 0;
}