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
void rec(int idx, int &c, vector<int>&a,vector<bool> &b, int n)
{
    if (idx == n)
    {
        c++;
        if (c == 4468)
            out(n, a);
        return;
    }
        for (int i = 1; i <= n; i++) {
            if (b[i])
            continue;
            a[idx] = i;
            b[i] = true;
            rec(idx + 1, c, a,b, n);
            b[i] = false;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int c = 0;
    vector<int> a(n);
    vector<bool> used(n + 1, false);
    rec(0, c, a, used, n);

}