#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    long n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
// n, x1, y1, x2, y2 = [int(i) for i in input().split()]

    long g1 = 0;
    long g2 = 0;
    long g3 = 0;
    long g4 = 0;

    if (x1 <= n/2)
        g1=x1;
    else
       g1= n+1 -x1;
    if( y1 <= n/2)
        g2 =  y1;
    else
        g2 = n+1 -y1;
    if (x2 <= n/2)
        g3=x2;
    else
       g3= n+1 -x2;
    if( y2 <= n/2)
        g4 =  y2;
    else
        g4 = n+1 -y2;

    long getcycle = min(g1, g2);
    long getcycle2 = min(g3, g4);
    
    cout << abs(getcycle2-getcycle) << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}