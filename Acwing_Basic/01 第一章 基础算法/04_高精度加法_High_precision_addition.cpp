#include <iostream> //!高精度加法
#include <vector>

using namespace std;

vector<int> add(vector<int>& A, vector<int>& B)
{
    vector<int> C;

    int t = 0; //!代表进位
    for(int i = 0; i < A.size() || i < B.size(); i++)
    {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(1); //! 最后只会进一位 所以for循环结束之后 压入一个1在 前面
    return C;
}

int main(void) //!高精度加法
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0'); //!倒着存，这样进位直接加在后面 而不用整个数组往后面移动一位
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    auto C = add(A, B);

    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}
