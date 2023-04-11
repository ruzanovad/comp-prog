#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<char> a(25, '.');
int counter = 0;

void out(int idx)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << "\n";
}

void rec(int idx, int k)
{
    if (k == m )
    {
        counter++;
        if (counter == 24008)
            out(idx); // 2+3+3+4+4+6+13

        return;
    }
    if (k<m && idx >= n) return;
    if (idx == 0 || a[idx - 1] == '.')
    {
        a[idx] = '*';
        rec(idx+1, k+1);
    }
    a[idx] = '.';
    rec(idx+1, k);
}

signed main()
{
    n = 25, m = 8;
    rec(0, 0);
}