#include <iostream> //高精度乘法
#include <vector>

using namespace std;

vector<int> mul(vector<int>& A, int b)
{
    vector<int> C;

    int t = 0;
    for(int i = 0; i < A.size() || t != 0; i++)
    {
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10); //!我们只取个位
        t /= 10; //! t左移一位
    }

    return C;
}

int main(void)
{
    string a; //!乘数比较长 125645512145
    int b; //!被乘数比较短  12   23

    cin >> a >> b;

    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0'); //! 变成真正的数字

    auto C = mul(A, b);
    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}
