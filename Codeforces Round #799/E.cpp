#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n); // ai
    vector<int> p(n); // prefix sum
    forn(i, n)
    {
        cin >> a[i];
        p[i] = a[i];
        if (i)
            p[i] += p[i - 1];
    }
    int ans = INT_MAX;
    forn(i, n)
    {
        int l = i, r = n - 1, pos = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((p[mid] - (i ? p[i - 1] : 0)) <= s)
            {
                pos = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (pos == -1 || (p[pos] - (i ? p[i - 1] : 0)) != s)
            continue;
        ans = min(ans, n - (pos - i + 1));
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}