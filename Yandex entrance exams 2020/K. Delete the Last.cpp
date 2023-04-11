#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> answer;
    for (auto &x : a)
    {
        cin >> x;
    }
    unordered_set<int> hash;
    for (int i = n - 1; i >= 0; i--)
    {
        if (hash.find(a[i]) != hash.end())
            answer.push_back(a[i]);
        else
            hash.insert(a[i]);

    }
            reverse(answer.begin(), answer.end());
        cout << answer.size() << '\n';
        for (const auto item : answer)
            cout << item << " ";
}