#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    long long c, d;
    long long cost = 0;
    cin >> n >> c >> d;
    vector<long long> a;
    set<long long> s;
    for (int i = 0; i < n; ++i){
        long x;
        cin >> x;
        int sz = s.size();
        s.insert(x);
        if (sz == s.size()){
            cost+=c;
        }
        else{a.push_back(x);}
    }
    if (*s.begin()!=1){
        s.insert(1);
        cost+=d;
    }
    auto x = s.begin(), y = --s.end();
    if (s.size() == *y)
        {
            cout << cost << endl;
            return;
        }
    long long g = LLONG_MAX;
    for (long long i = 0; i < s.size(); ++i){
        g = min(g,(long long)((*x - *s.begin()-i)*d + (s.size() - i-1)*c ));
        x++;
    }
    cout << cost+g << endl;


}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}