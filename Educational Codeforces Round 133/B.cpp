#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> numbers(n);
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            numbers[i] = i + 1;
            cout << i + 1 << " ";
        }
        cout << "\n";
        for (int i = 0; i < n-1; i++) {
            int temp = numbers[i];
            numbers[i] = numbers[i + 1];
            numbers[i + 1] = temp;
            for (int i = 0; i < n; i++) {cout << numbers[i]<< " ";}
            cout << "\n";
        }



    }
}