#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> ans(n), b(n);
        for (int i = 0; i < n; i++) { cin >> b[i];}
        vector<pair<int,int>> S(n);
        for (int i = 0; i < n; ++i)
            S[i] = {(i + 1) / (b[i] + 1) + 1, i};
        sort(S.begin(), S.end());
        set<pair<int,int>> s;
        int j = 0;
        for (int i = 1; i <= n; ++i) {
        while (j < n && S[j].first == i) {
            int id = S[j++].second;
            s.insert({b[id] ? (id + 1) / b[id] : n, id});
        }
        ans[s.begin()->second] = i;
        s.erase(s.begin());
        }
        for  (int i = 0; i < n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
}