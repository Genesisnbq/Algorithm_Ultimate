#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int stack[N];
int n;
int tt = 0;

int main(void)
{
    printf("请输入要存入几个数: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &stack[tt++]);
    printf("初始化成功!\n");
    int judge = 1;
    while (tt != 0 && judge)
    {
        printf("请输入你要进行的操作: 1.压入新元素 2.取栈顶元素 3.弹出栈顶元素 4.查看当前栈中元素个数 5.查看栈中所有元素: ");
        int op = 0;
        int st = 0;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("请输入要压入的元素: ");
            int x;
            scanf("%d", &x);
            stack[tt++] = x;
            printf("成功压入元素%d\n", x);
            break;
        case 2:
            printf("栈顶元素是: %d\n", stack[tt - 1]);
            break;
        case 3:
            printf("栈顶元素弹出成功!\n");
            tt--;
            break;
        case 4:
            printf("当前栈中的元素个数为: %d\n", tt);
            break;
        case 5:
            for (int i = 0; i < tt; i++)
                printf("%d ", stack[i]);
            puts("");
            break;
        default:
            st = 1;
            printf("很抱歉没有这个选项, 请重新输入!\n");
        }
        if (st == 1)
            continue;
        printf("请问还继续操作吗? 1/0: ");
        scanf("%d", &judge);
    }
    if (tt == 0)
        printf("栈已空!\n");
    printf("Over by: 倪彬琪\n");
    return 0;
}
