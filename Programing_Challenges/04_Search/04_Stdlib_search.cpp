#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v)
{
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++) cout << *it;
    cout << endl;
}

int main(void)
{
    int N = 4;
    vector<int> v;
    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    print(v);

    vector<int>::iterator it = v.begin();
    *it = 3; //! 将3赋给开头元素 v[0]
    it++;    //! 前移一个位置
    (*it)++; // todo v[1]的元素加1
    print(v);
    return 0;
}
