#include <iostream>

using namespace std;

const int N = 1e3 + 10, M = 2.5e3 + 10;

int numStack[N];
char charStack[N];
int ttn = 0;
int ttc = 0;
char expression[2500];

bool isChar(char c)
{
    if (c == '*' || c == '/' || c == '+' || c == '-')
        return true;
    return false;
}

int main(void)
{
    printf("请输入表达式: \n");
    scanf("%s", expression);
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isChar(expression[i]))
            charStack[ttc++] = expression[i];
        else numStack[ttn++] = expression[i]-'0';
    }

}
