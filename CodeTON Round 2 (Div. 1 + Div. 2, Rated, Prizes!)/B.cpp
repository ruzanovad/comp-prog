#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) { cin >> a[i]; }
        for (int i = 0; i < n - 1; ++i) { cout << abs(a[i] - a[i+1]) << " ";}
        cout << "|" << x << "|" << "\n";
    }
}