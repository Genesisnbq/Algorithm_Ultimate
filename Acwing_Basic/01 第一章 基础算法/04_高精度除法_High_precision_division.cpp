#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> div(vector<int>& A, int b, int& r) //!除了返回一个商，还会返回一个余数
{
    vector<int> C; //!除法是从  最高位  开始算的
    r = 0;
    for(int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end()); //!倒过来
    while(C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main(void)
{
    string a;
    int b;
    cin >> a >> b;

    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    int r; //!余数
    auto C = div(A, b, r);

    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    cout << endl << r << endl;

    return 0;
}
