#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int top, S[N];

void push(int x)
{
    S[++top] = x;
}

int pop()
{
    top--;
    return S[top + 1];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    char s[100];
    top = 0;

    while(cin >> s) //! 使用 ctrl+z 停止输入
    {
        if(s[0] == '+')
        {
            a = pop();
            b = pop();
            push(a + b);
        }
        else if(s[0] == '-')
        {
            b = pop();
            a = pop();
            push(a - b);
        }
        else if(s[0] == '*')
        {
            a = pop();
            b = pop();
            push(a * b);
        }
        else
            push(atoi(s)); //! 将字符串形式的数字转化为 整型
    }
    cout << pop() << endl;

    return 0;
}