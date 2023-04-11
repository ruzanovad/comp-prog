#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void solve(){
    unsigned long long n, k;
    cin >> n >> k;
    if (n % k == 0)
        {
            cout << "YES" << endl;
            return;
        }
    if (n % 2 == 0){
        cout << "YES" << endl;
        return;
    }
    if (k % 2 ==0  && n % 2 ){
        cout << "NO" << endl;
        return;
    }

    if (n % k % 2 == 0)
        cout << "YES" << endl;
    else if (n >= k && (n % k +k)% 2 == 0)
    cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    }

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}