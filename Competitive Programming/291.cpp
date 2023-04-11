#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void out(int n, vector<int>&a)
{
    for (int i = 0; i < n; i++)
         cout << a[i] << " ";
    cout << "\n";
}
void rec(int idx, int &c, vector<int>&a, int n, int m)
{
    if (idx == n)
    {
        c++;
        if (c == 6659)
            out(n, a);
        return;
    }
        for (int i = 1; i <= m; i++) {
            a[idx] = i;

            rec(idx + 1, c, a, n, m);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int c = 0;
    vector<int> a(n);
    rec(0, c, a, n, m);

}