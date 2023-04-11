#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornf(i, n, f) for (int i = 0; (i < n) && f; i++)
#define ll long long
#define all(x) (x).begin(), (x).end()
#define test                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);             \
    int t;                   \
    cin >> t;                \
    while (t--)              \
    {                        \
        solve();             \
    }
void solve()
{
    ll n, k;
    cin >> n >> k;
    if (k % 4 == 0)
        cout << "NO"
             << "\n";
    else
    {
        cout << "YES"
             << "\n";
        if (k % 2)
            for (int i = 1; i <= n; i += 2)
                cout << i << " " << i + 1 << "\n";
        else
        {
            for (int i = 2; i <= n; i += 4)
                cout << i << " " << i - 1 << "\n";

            for (int i = 3; i <= n; i += 4)
                cout << i << " " << i + 1 << "\n";
        }
    }
}
int main() { test }
