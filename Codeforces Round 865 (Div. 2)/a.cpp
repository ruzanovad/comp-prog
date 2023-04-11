#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void solve(){
    long a, b;
    cin >> a >> b;
    if (a == 1 && b == 1){
        cout << 2 << endl;
        return;
    }

    if (a <= 1 || b <= 1){
        long h = 1, n = max(a, b), res = n;
        for (int i = 2; i*i <= n; i++){
            if (n % i == 0){
                res = min(n, i + n / i);
            }
        }
        cout << res << endl;
        return;
    }
    long v = min(a, b), n = max(a, b);
    cout << v + n / v + n % v << endl;

}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}