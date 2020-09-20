#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int n;

struct List
{
    int* e; //定义一个动态数组(指针可以动态分配)
    int count; // List中元素的数量;
    int len; //表长
};

void list_init(List* list)
{
    list->e = ( int* )malloc(n * sizeof(int));
    list->count = 0;
    list->len = n;
}

bool list_insert(List* list, int pos, int x) // List *list 如果是数组, 就相当于 List list[]
{
    int *base, *insert, *p;
    if(list == NULL || pos < 0 || pos > list->len - 1)
    {
        printf("输入错误,请重新输入!\n");
        return false;
    }
    if(list->count > list->len)
    {
        base = ( int* )realloc(list->e, (list->len + n) * sizeof(int));
        list->e = base;
        list->len += n;
    }
    insert = &(list->e[pos]);
    for(p = list->e + list->count - 1; p >= insert; p--) *(p + 1) = *p;
    *insert = x;
    list->count++;
    return true;
}

void show_list(List* list)
{
    for(int i = 0; i < list->count; i++) printf("%-5d ", i);
    puts("");
    for(int i = 0; i < list->count; i++) printf("%-5d ", list->e[i]);
    puts("");
}

void list_delete(List* list, int pos)
{
    for(int* i = &(list->e[pos]) + 1; i <= (list->e + list->count); i++) *(i - 1) = *i;
    list->count--;
}

void list_select(List* list, int x)
{
    int mark = 0;
    for(int* i = list->e; i <= list->e + list->count - 1; i++)
    {
        if(*i == x)
        {
            printf("位置: %d 找到了x\n", i - list->e);
            mark++;
        }
    }
    if(!mark) printf("该顺序表中不存在%d!\n", x);
}

int main(void)
{
    List list;
    printf("输入List初始元素数量: ");
    scanf("%d", &n);
    printf("输入%d个元素\n", n);
    list_init(&list);
    bool st = false;
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        list_insert(&list, i, x); // 在位置i插入x,和数组一样, 要传进去数组首元素的地址(数组名)
    }
    printf("当前顺序表:\n");
    show_list(&list);
    while(true)
    {
        printf("请输入要进行的操作: (insert, delete, select, show):\n");
        string op;
        cin >> op;
        if(op == "insert")
        {
            int pos, x;
            printf("请输入要插入的位置和值:");
            scanf("%d%d", &pos, &x);
            if(pos > list.count - 1 || pos < 0)
            {
                printf("输入位置过界, 请重新输入!\n");
                continue;
            }
            list_insert(&list, pos, x);
            printf("insert之后的结果为: \n");
            show_list(&list);
        }
        else if(op == "delete")
        {
            printf("请输入要删除的位置: ");
            int pos;
            scanf("%d", &pos);
            if(pos < 0 || pos > list.count - 1)
            {
                printf("输入位置过界, 请重新输入!\n");
                continue;
            }
            list_delete(&list, pos);
            printf("delete之后的结果为: \n");
            show_list(&list);
        }
        else if(op == "show")
        {
            show_list(&list);
        }
        else if(op == "select")
        {
            printf("请输入要查找的值: ");
            int x;
            scanf("%d", &x);
            list_select(&list, x);
        }
        else
        {
            printf("输入错误, 请重新输入!\n");
            continue;
        }
        int cur = 0;
        printf("是否继续进行操作? (1/0): ");
        scanf("%d", &cur);
        if(cur == 0) break;
    }
    printf("Over!\n");
    return 0;
}
