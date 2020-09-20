#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

typedef struct pp //* 存名字和时间
{
    char name[100];
    int t;
} p;

p Q[N];
int head, tail;
int n, q;

void enqueue(p x) //* 插入队列中
{
    Q[tail] = x;
    tail = (tail + 1) % N;
}

p dequeue() //*  从队列中取出
{
    p x = Q[head];
    head = (head + 1) % N;
    return x;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int elaps = 0, c; // todo elaps 是累计已经过的时间
    p u;

    cin >> n >> q; //! 输入 数量和 一次的处理时间（速度）

    for(int i = 1; i <= n; i++) cin >> Q[i].name >> Q[i].t; //! 下标从 1 开始读入

    head = 1; //* head 指向 队列首元素
    tail = n + 1;

    while(head != tail) //* 只要 head 不等与 tail（不空）
    {
        u = dequeue(); //*从队头中取出元素
        c = min(q, u.t);
        u.t -= c;
        elaps += c;
        if(u.t > 0)
            enqueue(u);
        else
            cout << u.name << " " << elaps << endl; //! 最后输出完成的时间
    }
    return 0;
}