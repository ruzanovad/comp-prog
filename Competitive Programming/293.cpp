#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a(35);
int counter = 0;

void out(int idx)
{
    for (int i = 0; i < idx; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void rec(int idx, int sum, int last)
{
    if (sum == n)
    {
        counter++;
        if (counter == 13672)
            out(idx); // 2+3+3+4+4+6+13

        return;
    }
    for (int i = last; i <= n - sum; i++)
    {
        a[idx] = i;
        rec(idx + 1, sum + i, i);
    }
}

signed main()
{
    n = 35;
    int s;
    rec(0, s, 1);
}