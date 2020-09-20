#include<iostream>

using namespace std;

int sum;

int main(void)
{
    int i=1;
    do{
        sum+=i++;
    }while(i<=100);
    printf("%d\n",sum);
    return 0;
}
