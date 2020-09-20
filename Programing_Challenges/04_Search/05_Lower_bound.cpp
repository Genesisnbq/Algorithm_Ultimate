#include <algorithm> //! 返回>=x 的 第一个数
#include <iostream>
#include <iterator>

using namespace std;

int main(void)
{
    int a[14] = {1, 1, 2, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    int* pos;
    int idx;
    pos = lower_bound(a, a + 14, 3); // todo return the address of the first >=x
                                     // todo reference to the address equal to the pos-a
    idx = distance(a, pos); // todo The distance of a to the pos

    cout << "A[" << idx << "]=" << *pos << endl;

    pos = lower_bound(a, a + 14, 2);
    idx = distance(a, pos); //todo  Equivalent to the  last return of subscript 最后返回的是下标
    cout << "A[" << idx << "]=" << *pos << endl;
    return 0;
}
