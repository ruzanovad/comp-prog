#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
#define forn(i, n, f) for (int i = 0; i < n && f; i++)
#define ll long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c,d;
        cin >> a >> b >> c >> d;
        cout << (a < b) + (a < c) + (a < d) << "\n";
    }
}