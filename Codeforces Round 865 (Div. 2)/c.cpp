#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<long> a(n);
    for (auto& x: a){
        cin >> x;
    }
    if (n == 2 && a[0]>a[1])
        {
                    cout << "NO" << endl;
        return;
        }
    if (n % 2){
        cout << "YES" << endl;
        return;
    }  
    bool flag =true;
    for (int i = 1; i < n && flag; ++i){
        flag = a[i-1] <= a[i];
    }
    if (flag){
        cout << "YES" << endl;
        return;
        }
    
     

}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}