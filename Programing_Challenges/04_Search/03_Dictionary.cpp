#include <cstdio>
#include <cstring>
#include <iostream>

#define M 1046527
#define NIL (-1)
#define L 14

char H[M][L];

//! 将字符转化为数值
int getChar(char ch)
{
    if(ch == 'A')
        return 1;
    else if(ch == 'C')
        return 2;
    else if(ch == 'G')
        return 3;
    else if(ch == 'T')
        return 4;
    else
        return 0;
}

//! 将字符串转化为数值并生成 key
long long getKey(char str[])
{
    long long sum = 0, p = 1, i;
    for(i = 0; i < strlen(str); i++)
    {
        sum += p * (getChar(str[i]));
        p *= 5;
    }
    return sum;
}

int h1(int key)
{
    return key % M;
}

int h2(int key)
{
    return 1 + (key % (M - 1));
}

int find(char str[])
{
    long long key, i, h;
    key = getKey(str); //! 将字符串转化为数值
    for(i = 0;; i++)
    {
        h = (h1(key) + i * h2(key)) % M;
        if(strcmp(H[h], str) == 0)
            return 1;
        else if(strlen(H[h]) == 0)
            return 0;
    }
    return 0;
}

int insert(char str[])
{
    long long key, i, h;
    key = getKey(str); // todo 将字符串转化为数值
    for(i = 0;; i++)
    {
        h = (h1(key) + i * h2(key)) % M;
        if(strcmp(H[h], str) == 0)
            return 1;
        else if(strlen(H[h]) == 0)
        {
            strcpy(H[h], str);
            return 0;
        }
    }
}
int main(void)
{
    int i, n;
    char str[L], com[9];
    for(i = 0; i < M; i++) H[i][10] = '\0';
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s %s", com, str); // todo 使用输入更快的函数 scanf
        if(com[0] == 'i')
            insert(str);
        else
        {
            if(find(str))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
