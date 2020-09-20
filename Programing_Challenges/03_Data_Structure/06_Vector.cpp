#include <iostream>
#include <vector>

using namespace std;

void print(vector<double> v)
{
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout<<endl;
}

int main(void)
{
    vector<double> v;
    v.push_back(0.1);
    v.push_back(0.2);
    v.push_back(0.3);
    v[2] = 0.4;
    print(v);

    v.insert(v.begin() + 2, 0.8);
    print(v);

    v.erase(v.begin() + 1);

    print(v);

    v.push_back(0.9);
    print(v);

    return 0;
}