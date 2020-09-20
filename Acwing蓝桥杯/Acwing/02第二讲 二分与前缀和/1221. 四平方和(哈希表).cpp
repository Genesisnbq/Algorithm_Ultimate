#include <iostream>
#include <unordered_map>

using namespace std;
typedef pair<int, int> pii;

int n;
unordered_map<int, pii> S;

int main(void)
{
    scanf("%d", &n);
    for (int c = 0; c <= n; c++)
        for (int d = c; d * d + c * c <= n; d++)
        {
            int t = c * c + d * d;
            if (S.count(t) == 0)
                S[t] = {c, d};
        }
    for (int a = 0; a <= n; a++)
        for (int b = 0; a * a + b * b <= n; b++)
        {
            int t = n - a * a - b * b;
            if (S.count(t))
            {
                printf("%d %d %d %d", a, b, S[t].first, S[t].second);
                return 0;
            }
        }
    return 0;
}
