#include <iostream>

using namespace std;

struct student
{
    int id;
    char name[10];
    int chinese, match, english;
}; // 3位同学

student a[3];

int sum(int i)
{
    return a[i].chinese + a[i].match + a[i].english;
}

int main(void)
{
    for(int i = 0; i < 3; i++)
    {
        printf("请输入第 %d 位同学的信息\n", i + 1);
        printf("学号: ");
        scanf("%d", &a[i].id);
        printf("姓名: ");
        scanf("%s", a[i].name);
        printf("语文: ");
        scanf("%d", &a[i].chinese);
        printf("数学: ");
        scanf("%d", &a[i].match);
        printf("英语: ");
        scanf("%d", &a[i].english);
    }
    printf("三位同学的总成绩\n");
    for(int i = 0; i < 3; i++)
        printf("姓名: %s  总成绩: %d\n",a[i].name,sum(i));
    return 0;
}
