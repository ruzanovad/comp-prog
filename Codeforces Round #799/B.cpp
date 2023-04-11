#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
/* Note that the size of the array doesn't change parity, since it always decreases by 2. 
Let's count the number of distinct elements, call it x.

If x is the same parity as n (the length of the array), 
then we can make sure all of these x distinct elements stay in the array by removing two elements at a time.

Otherwise, x isn't the same parity as n. Then x−1 is the same parity as n, 
and we can make sure x−1 distinct elements stay in the array by removing two elements at a time. 
So the answer is x if x and n have the same parity, and x−1 otherwise.
 */
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ai;
        cin >> n;
        set<int> a;
        for (int i = 0; i < n; i++)
        {
            cin >> ai;
            a.insert(ai);
        }
        if ((n - a.size()) % 2 == 0)
            cout << a.size() << "\n";
        else
            cout << a.size() - 1 << "\n";
    }
}