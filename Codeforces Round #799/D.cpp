#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve()
{
    int x, h, m;
    string input; cin >> input >> x;
    h = stoi(input.substr(0, 2));
    m = stoi(input.substr(3, 2));
    set<pair<int, int>> times;
    pair<int, int> starttime = {h, m}, currenttime = starttime;
    do {
        if (currenttime.first%10 == currenttime.second/10 && currenttime.second%10 == currenttime.first/10)
            times.insert(currenttime);
        currenttime = {((currenttime.first*60+currenttime.second + x)/60)%24,(currenttime.second + x) % 60};

    } while (currenttime != starttime);
    cout << times.size() << "\n";

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}