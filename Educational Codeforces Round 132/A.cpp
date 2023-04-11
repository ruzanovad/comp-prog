#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int x;
        cin >> x;
        int arr[3];
        for (int i = 0; i < 3; i++){
            cin >> arr[i];
        }
        int curr = x - 1;
        bool f = true;
        for (int i = 0; i < 3 && f; i++){
            if (i != 2 && arr[curr] == 0)
                f = false;
            else
                curr = arr[curr] - 1;
        }
        if (f)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}