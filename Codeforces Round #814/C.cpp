#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <deque>

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
#define test                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);             \
    int t;                   \
    cin >> t;                \
    while (t--)              \
    {                        \
        solve();             \
    }

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

int a[MAXN];
int main() { test }
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
    int n, q;
    cin >> n >> q;
    vector<vi> an(n + 1);
    deque<int> cur;
    an.push_back(vi(1));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cur.push_back(i);
    }

    for (int i = 1; i <= n; i++) // 
    {
        int f = cur.front(); //index of first
        cur.pop_front();
        int s = cur.front(); //index of second
        cur.pop_front();

        if (a[s] > a[f])
        {
            cur.push_back(f);
            cur.push_front(s);
            an[s].push_back(i); // win++
        }
        else
        {
            cur.push_back(s);
            cur.push_front(f);
            an[f].push_back(i);
        }
    }

    while (q--)
    {
        int i, k;
        cin >> i >> k;
        int ans = upper_bound(all(an[i]), k) - an[i].begin(); // if case => 1 2 -> upper = 3, begin = 1
        // Алгоритм upper_bound(first, last, val) осуществляет двоичный поиск значения val
        // и возвращает итератор res на первый элемент, который строго больше, чем val, 
        // то есть *res>val, a *(res-1)<=val. Если же все элементы контейнера (начиная с first)
        // будут больше, чем val, то будет возвращено значение first. Если в контейнере 
        // все элементы меньше или равны  val, то возвращается значение last.
        cout << ans + (a[i] == n ? max(k - n, 0) : 0) << endl;
    }
}

