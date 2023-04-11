#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;

        if (n % 3 == 0) cout << n / 3;
        else if (n % 3 == 1) 
        {
            if (n == 1) cout << 2;
            else cout << 2 + (n-4) / 3;
        }
        else cout << n / 3 + 1, n / 2;
        cout << "\n";
    }
}