#include<iostream>

using namespace std;

int n;
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(i>1) printf(" ");
        printf("%d",i);
    }
    return 0;
}
