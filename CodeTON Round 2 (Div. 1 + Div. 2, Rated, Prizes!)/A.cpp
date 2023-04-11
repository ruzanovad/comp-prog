#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string a, b;
        cin >> n >> m >> a >> b;
        if (m == 1)
        {
            if (a.find(b[0]) != -1)
                cout << "YES";
            else 
                cout << "NO";
        }
        else{
            string A = a.substr(n-m+1, m+1), B = b.substr(1, m-1), C = a.substr(0, n-m+1);
            if (A == B && C.find(b[0]) != -1) 
            {
                cout << "YES";
            }
            else cout << "NO";
        }
        cout << "\n";
    }
}