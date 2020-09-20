#include <iostream>
using namespace std;

const int N = 1e2 + 10;

int n;

struct card
{
    char str, value;
} c1[N], c2[N];

void bubble(struct card a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j >= i + 1; j--)
        {
            if(a[j].value < a[j - 1].value) swap(a[j], a[j - 1]);
        }
    }
}

void selection(struct card a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int minj = i;
        for(int j = i; j < n; j++)
        {
            if(a[minj].value > a[j].value) minj = j;
        }
        swap(a[i], a[minj]);
    }
}

bool isStable(struct card c1[], struct card c2[], int n)
{
    for(int i = 0; i < N; i++)
    {
        if(c1[i].str != c2[i].str) return false;
    }
    return true;
}

void print(struct card a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i > 0) cout << " ";
        cout << a[i].str << a[i].value;
    }
    cout << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> c1[i].str >> c1[i].value;

    for(int i = 0; i < n; i++) c2[i] = c1[i];

    bubble(c1, n);
    selection(c2, n);

    print(c1, n);
    cout << "Stable" << endl;

    print(c2, n);
    if(isStable(c1, c2, n))
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;
    return 0;
}