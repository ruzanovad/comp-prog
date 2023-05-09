#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int miss_time(vector<int>& v, int& value){
    int res = INT_MAX;
    for (auto& x: v){
        res = min(res, abs(value-x));
    }
    return res;
}

// https://vjudge.net/problem/UVA-234
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int p = -1;
    int number = 1;
    while (cin >> p && p != 0){
        vector<int> l(p);
        for (int i = 0; i < p; ++i){
            cin >> l[i];
        }
        int a;
        cin >> a;
        vector<pair<int, int>> pa(a);
        for (int i = 0; i < a; ++i){
            cin >> pa[i].first >> pa[i].second;
        }

        vector<int> importance(5, INT_MAX);
        vector<int> order(p, INT_MAX);
        sort(l.begin(), l.end());
        do
        {   
            vector<int> current(5, 0);
            vector<int> pref(p, 0);
            partial_sum(l.begin(), l.end(), pref.begin());

            for (int i = 1; i <= a; ++ i){
                current[pa[i-1].first-1]+=miss_time(pref, pa[i-1].second);
            }

            if (!lexicographical_compare(importance.begin(), importance.end(), current.begin(), current.end())){
                importance = current;
                order = l;
            }
        } while (next_permutation(l.begin(), l.end()));
        cout << "Data set " << number << endl;
        number++;
        cout << "Order: ";
        for(int i = 0; i < p; ++i){
            cout << order[i] << " ";
        }
        cout << endl;
        cout << "Error: " << accumulate(importance.begin(), importance.end(), 0) << endl;
    }
    return 0;
}
