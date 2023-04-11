#include <iostream>
#include <vector>

using namespace std;
// prefix sum 
// pref[0]=a[0]
// pref[i]=pref[i−1]+a[i]
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){ cin >> a[i];}
    vector<pair<long long, long long>> prefsum(n); prefsum[0] = {0LL, 0LL};
    
    for (int i = 0; i < n-1; i++) {
        prefsum[i+1].first = max(a[i] - a[i + 1], 0LL);
    }
    for (int i = 1; i < n; i++) {
        prefsum[i].second = max(a[i] - a[i - 1], 0LL);
    }
    for (int i = 0; i < n-1; i++){
        prefsum[i+1].first += prefsum[i].first;
        prefsum[i+1].second += prefsum[i].second;
    }

        for (int i = 0; i < m; i++){
            long s, t;
            cin >> s >> t;
            if (s > t) cout << prefsum[s - 1].second - prefsum[t - 1].second << "\n";
            else cout << prefsum[t - 1].first - prefsum[s - 1].first << "\n";
        }
}