#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <deque>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define F first
#define S second
#define vi vector<int>
#define ll long long
#define vll vector<ll>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define fornf(i, n, f) for (int (i) = 0; ((i) < (n)) && (f); ++(i))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve();

// int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    vll s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<vll > pref(31, vll(n+1, 0));
    for (int i = 0; i < 31; ++i) {
        if (s[0] == i)
            pref[i][1] = s[0];
        for (int j = 2; j <= n; ++j) {
            pref[i][j] = pref[i][j - 1];
            if (s[j-1] == i) {
                pref[i][j] += i;
            }
        }
    }
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll sum = 0;
        ll L, R, M;
        cin >> L >> R >> M;
        set<int> ss;
        ll k = 1;
        for (int j = 0; j < 31; ++j) {
            if (M & k) {
                sum+= pref[j][R] - pref[j][L];
            }
            k *= 2;
        }
        cout << sum << endl;
    }
    return 0;
}

void solve() {

}