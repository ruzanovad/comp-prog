#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <deque>
#include <fstream>

// #include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define F first
#define S second
#define vi vector<int>
#define ll long long
#define vll vector<ll>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define fornf(i, n, f) for (int i = 0; (i < n) && f; ++i)
#define all(x) (x).begin(), (x).end()

const string all = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string numbers = "0123456789";
const string upperalpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string loweralpha = "abcdefghijklmnopqrstuvwxyz";
const int MAXN = 2e5 + 5;
ll binpow(ll, ll);
void solve();
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(ll x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned ll x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

// int a[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    ll n , k, b, s;
    cin >> n >> k >> b >> s;
    // if (k == 1)
    // {
    //     if (s >= n && b == s){
    //         ll sum = 0;
    //         forn(i, n-1){
    //             cout << i+1 << " ";
    //             s+=i+1;
    //         }
    //         cout << s - sum << endl;
    //     }

    //     else cout << -1 << endl;
    // }
    // else {
        ll sum_of_remainders = s%k + k*(s/k-b);
        if (sum_of_remainders < 0 || sum_of_remainders > n*(k-1))
            cout << -1 << endl;
        else {
            vll answer(n);
            answer[0] = k*b;
            int i = 0;
            while(sum_of_remainders>0){
                ll portion = k-1;
                if (sum_of_remainders - portion >=0){
                    answer[i]+=portion;
                    sum_of_remainders-=portion;
                }
                else{
                    answer[i]+=sum_of_remainders;
                    sum_of_remainders = 0;
                }
                i++;

            }
            forn(j,n)
            cout << answer[j] << " ";
            cout << endl;
        }
    // }
}