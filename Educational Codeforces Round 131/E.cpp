#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int>& zf(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0,
        r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m;
        string s, t;
        cin >> n >> m >> s >> t;
    }
}