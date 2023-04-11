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
    ll n, m;
    cin >> n >> m;
    if (n % 2 == m % 2)
        cout << "Tonya\n";
    else
        cout << "Burenka\n";
}
int main() { test }
