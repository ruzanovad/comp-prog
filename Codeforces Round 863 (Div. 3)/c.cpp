#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    long n;
    cin >> n;
    vector<long> a(n-1);
    for (auto&x:a){
        cin >> x;
    }
    vector<long> b;
    b.push_back(a[0]);
    cout << a[0] << " ";
    for (int i = 0; i < n-1; ++i){
        if (i < n-2)
        {
            if (a[i]> a[i+1])
                cout << a[i+1] << " ";
            else 
            cout << a[i] << " ";
        }
        else
        cout << a[i] << " ";

    }
    cout << "\n";
    
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}