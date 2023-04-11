#include <iostream>
#include <set>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, H, M;
        cin >> n >> H >> M;
        set<pair<int, int>> hm;
        for (int i = 0; i < n; i++)
        {
            int hi, mi;
            cin >> hi >> mi;
            hm.insert({hi, mi});
        }
        pair<int, int> minimum = {24, 24};
        for (set<pair<int, int>>::iterator it = hm.begin(); it != hm.end(); ++it)
        {
            int curr_hours, curr_minutes;
            if (*it <= make_pair(H, M))
            {
                curr_minutes = (24 - H + (*it).first) * 60 + -M + ((*it).second);
                curr_hours = curr_minutes / 60 % 24;
                curr_minutes = curr_minutes % 60;
            }
            else
            {
                curr_minutes = (-H + (*it).first) * 60 + (*it).second - M;
                curr_hours = curr_minutes / 60 % 24;
                curr_minutes = curr_minutes % 60;
            }
            if (make_pair(curr_hours, curr_minutes) < minimum)
                minimum = {curr_hours, curr_minutes};
        }

        cout << minimum.first << " " << minimum.second << "\n";
    }
}