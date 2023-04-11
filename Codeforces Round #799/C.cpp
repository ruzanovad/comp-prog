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
    vector<pair<int, int>> chessboard;
    vector<int> special;
    for (int i = 0; i < 8; ++i)
    {
        string temp;
        cin >> temp;
        if (count(temp.begin(), temp.end(), '#') == 1)
        {
            chessboard.push_back({i, temp.find('#')});
            special.push_back(1);
        }
        else if (count(temp.begin(), temp.end(), '#') == 2)
        {
            chessboard.push_back({i, temp.find('#')});
            chessboard.push_back({i, temp.rfind('#')});
            special.push_back(2);
            if (i > 1 && special[i] == special[i - 2] && special[i - 1] == 1)
            {
                cout << (*prev(chessboard.end(), 3)).first + 1 << " " << (*prev(chessboard.end(), 3)).second + 1 << "\n";
            }
        }
        else special.push_back(0);
    }
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