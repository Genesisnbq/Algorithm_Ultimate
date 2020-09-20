// 插入, 有序插入-> 进行查找运算, 确定位置
// 删除(头,尾,i)
// 查找, 找到返回index, else return -1

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int List[N];

int main(void)
{
    printf("请输入List中有几个Number: ");
    scanf("%d", &n);
    int len = n;
    printf("请依次输入 %d 个数(中间用空格隔开)\n", n);
    for(int i = 0; i < n; i++) scanf("%d", &List[i]);
    int st = 1;
    while(st)
    {
        string op;
        printf("请输入要进行的操作(插入,删除, 查找): ");
        cin >> op;
        int pos;
        if(op == "插入")
        {
            printf("请输入要插入的位置[0,%d]和数字: ", len - 1);
            int index, x;
            scanf("%d%d", &index, &x);
            for(int i = len - 1; i >= index; i--) List[i + 1] = List[i];
            List[index] = x;
            len++;
            printf("插入完成!\n");
            printf("插入后的结果为:\n");
            for(int i = 0; i < len; i++) printf("%d ", List[i]);
            puts("");
        }
        else if(op == "删除")
        {
            printf("请输入要删除选项(位置, 特定值): ");
            string cur;
            cin >> cur;
            if(cur == "位置")
            {
                printf("请输入要删除的位置:[0,%d]: ", len - 1);
                scanf("%d", &pos);
                for(int i = pos; i < len; i++) List[i] = List[i + 1];
                len--;
                printf("删除后的结果:\n");
                for(int i = 0; i < len; i++) printf("%d ", List[i]);
                puts("");
            }
            else if(cur == "特定值")
            {
                printf("请输入要删除的特定值: ");
                scanf("%d", &pos);
                for(int i = 0; i < len; i++)
                {
                    if(List[i] == pos)
                    {
                        for(int j = i; j < len; j++) List[j] = List[j + 1];
                        len--;
                        i--;
                    }
                }
                printf("删除后的结果:\n");
                for(int i = 0; i < len; i++) printf("%d ", List[i]);
                puts("");
            }
            else
            {
                printf("输入不规范! 请重新输入!\n");
                continue;
            }
        }
        else if(op == "查找")
        {
            bool judge = false;
            printf("请输入要查找的值: ");
            scanf("%d", &pos);
            for(int i = 0; i < len; i++)
            {
                if(List[i] == pos)
                {
                    printf("%d ", i);
                    judge = true;
                }
            }
            puts("");
            if(!judge) { printf("该元素不存在!!!\n"); }
        }
        else
        {
            printf("输入不规范, 请重新输入!\n");
            continue;
        }
        printf("是否继续进行操作? (1/0): ");
        int c;
        scanf("%d", &c);
        if(c == '0') st = 0;
    }
    printf("最终结果为: \n");
    for(int i = 0; i < len; i++) printf("%d ", List[i]);
    puts("");
    return 0;
}
