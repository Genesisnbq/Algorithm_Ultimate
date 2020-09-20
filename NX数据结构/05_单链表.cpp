// 在第a节点之前insert x
// 删除第 i 个节点
// 在头部插入 x
// 在尾部插入 x
// 查找元素 x 并返回是 第几个节点
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n;
int idx;

typedef struct SingleLinkedList
{
    int value;
    int mark;
    SingleLinkedList *next;
} List;

List *head; //初始化指向NULL

void list_init() //初始化
{
    head = (List *)malloc(sizeof(List)); //给他一块内存空间
    head->next = NULL;
    head->mark = 0;
}

void AddToHead(int x) //尾插
{
    List *p = (List *)malloc(sizeof(List));
    p->value = x;
    p->next = head->next;
    head->next = p;
    p->mark = ++idx;
}

void AddToTail(int x)
{
    List *t = head;
    for (int i = 0; i < idx; i++)
        t = t->next; // 到达最后一个节点
    List *p = (List *)malloc(sizeof(List));
    p->value = x;
    p->next = t->next;
    p->mark = ++idx;
    t->next = p;
}

void list_insert(int k, int x) //在单链表的第 k 个位置插入 x
{
    List *p = head->next;
    List *pre = head->next;
    while (p != NULL && p->mark != k)
        p = p->next; //找到第k个位置的地址
    if (p == NULL)
    {
        printf("第%d个节点已经被删除了\n", k);
        return;
    }
    while (pre->next->mark != k)
        pre = pre->next;
    List *element = (List *)malloc(sizeof(List *));
    element->value = x;
    element->next = pre->next;
    element->mark = ++idx;
    pre->next = element; //插入完成
}

List *list_search(int value)
{
    List *p = head->next;
    while (p != NULL && p->value != value)
        p = p->next;
    return p;
}

List *list_search_node(int k)
{
    List *p = head->next;
    while (p != NULL && p->mark != k)
        p = p->next;
    return p;
}

void deleteNode(List *t)
{
    if (t == NULL)
        return; //不进行任何操作
    if (t->mark == 1)
        head->next = t->next;
    List *pre = head->next;
    while (pre->next != t)
        pre = pre->next;
    pre->next = t->next;
    free(t); // 释放内存
}

void deleteValue(int value)
{
    deleteNode(list_search(value));
}

void show_list()
{
    printf("节点编号: ");
    for (List *p = head->next; p != NULL; p = p->next)
        printf("%-5d ", p->mark);
    puts("");
    printf("值:       ");
    List *start = head->next;
    int count = 0;
    while (1)
    {
        if (start == NULL)
            break;
        if (count++ > 0)
            printf(" ");
        printf("%-5d", start->value);
        start = start->next;
    }
    puts("");
}

int main(void)
{
    list_init();
    printf("初始化单链表成功!\n");
    printf("请输入单链表的初始长度: ");
    scanf("%d", &n);
    if (n)
    {
        printf("请输入%d个数据(中间使用空格隔开):\n", n);
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            if (i == 0)
                AddToHead(x);
            else
            {
                List *p = head;
                while (p->next != NULL)
                    p = p->next;
                List *temp = (List *)malloc(sizeof(List));
                temp->value = x;
                temp->mark = ++idx;
                temp->next = p->next;
                p->next = temp;
            }
        }
    }
    while (true)
    {
        printf("请输入你要进行的操作(insert,select,delete):\n");
        string op;
        cin >> op;
        if (op == "insert")
        {
            int a;
            printf("请输入要插入的方式: 1.头插 2.尾插 3.中间插入\n");
            scanf("%d", &a);
            if (a == 3)
            {
                printf("请输入要插入的元素的位置和值: ");
                int x, pos;
                scanf("%d%d", &pos, &x); //在第pos个节点的位置插入x
                if (pos <= 1 || pos >= idx)
                {
                    printf("位置超界, 请重新输入!\n");
                    continue;
                }
                if (pos == 1)
                    AddToHead(x);
                else
                    list_insert(pos, x);
            }
            else if (a == 1)
            {
                printf("请输入要插入的值: ");
                int x;
                scanf("%d", &x);
                AddToHead(x);
            }
            else if (a == 2)
            {
                printf("请输入要插入的值: ");
                int x;
                scanf("%d", &x);
                AddToTail(x);
            }
            else
            {
                printf("输入不规范, 请重新输入!\n");
                continue;
            }
            printf("完成!\n");
            printf("操作后的结果为:\n");
            show_list();
        }
        else if (op == "select")
        {
            printf("请输入你要查找的值: ");
            int x;
            scanf("%d", &x);
            List *judge = list_search(x);
            if (judge == NULL)
                printf("很抱歉, %d不存在!\n", x);
            else
                printf("找到了! 在位置%d\n", judge->mark);
        }
        else if (op == "delete")
        {
            printf("1.删除节点K  2.删除值为k的节点\n");
            int temp;
            scanf("%d", &temp);
            if (temp == 1)
            {
                printf("请输入节点编号: ");
                int id;
                scanf("%d", &id);
                if (id < 1 || id > idx)
                {
                    printf("没有该编号, 请重新输入!\n");
                    continue;
                }
                deleteNode(list_search_node(id));
                printf("删除成功!\n");
                printf("删除后的结果为: \n");
                show_list();
            }
            else if (temp == 2)
            {
                printf("请输入要删除的值: ");
                int k;
                scanf("%d", &k);
                List *p = list_search(k);
                if (p == NULL)
                {
                    printf("值为%d的节点不存在!\n", k);
                    printf("当前结果: \n");
                }
                else
                {
                    deleteValue(k);
                    printf("值为%d的节点已经删除!\n", k);
                    printf("删除后的结果为: \n");
                }
                show_list();
            }
            else
            {
                printf("没有这个选项! 请重新输入!\n");
                continue;
            }
        }
        else
        {
            printf("输入不规范! 请重新输入!\n");
            continue;
        }
        int judge;
        printf("是否继续(1/0): ");
        scanf("%d", &judge);
        if (!judge)
            break;
    }
    printf("Over QAQ  by:倪彬琪\n");
    return 0;
}
