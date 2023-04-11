#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <deque>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define F first
#define S second
#define vi vector<int>
#define ll long long
#define vll vector<ll>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define fornf(i, n, f) for (int (i) = 0; ((i) < (n)) && (f); ++(i))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const string all = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string numbers = "0123456789";
const string upperalpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string loweralpha = "abcdefghijklmnopqrstuvwxyz";
const int MAXN = 2e5 + 5;

unsigned ll gcd(unsigned ll a, unsigned ll b);

unsigned ll lcm(unsigned ll a, unsigned ll b);

ll binpow(ll, ll);

void solve();

void print() { cerr << "]\n"; }

void print(int x) { cerr << x; }

void print(long x) { cerr << x; }

void print(ll x) { cerr << x; }

void print(unsigned x) { cerr << x; }

void print(unsigned long x) { cerr << x; }

void print(unsigned ll x) { cerr << x; }

void print(float x) { cerr << x; }

void print(double x) { cerr << x; }

void print(long double x) { cerr << x; }

void print(char x) { cerr << '\'' << x << '\''; }

void print(const char *x) { cerr << '\"' << x << '\"'; }

void print(const string &x) { cerr << '\"' << x << '\"'; }

void print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void print(const pair<T, V> &x) {
    cerr << '{';
    print(x.first);
    cerr << ',';
    print(x.second);
    cerr << '}';
}

template<typename T>
void print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i: x)
        cerr << (f++ ? "," : ""), print(i);
    cerr << "}";
    print();
}


template<typename T, typename... V>
void print(T t, V... v) {
    print(t);
    if (sizeof...(v))
        cerr << ", ";
    print_(v...);
}

template<typename T, typename V>
/* compare only second value of pairs
 non-increasing*/
bool pairCompareOnlySecondDecreasing(const pair<T, V> &p1, const pair<T, V> &p2) {
    if (p1.second == p2.second)
        return (p1.first) > (p2.first);
    else
        return (p1.second) > (p2.second);
}

template<typename T, typename V>
/* compare only first value of pairs
 non-increasing*/
bool pairCompareOnlyFirstDecreasing(const pair<T, V> &p1, const pair<T, V> &p2) {
    if (p1.first == p2.first)
        return (p1.second) > (p2.second);
    else
        return (p1.first) > (p2.first);
}

template<typename T, typename V>
/* compare only second value of pairs
 non-decreasing*/
bool pairCompareOnlySecond(const pair<T, V> &p1, const pair<T, V> &p2) {
    if (p1.second == p2.second)
        return (p1.first) < (p2.first);
    else
        return (p1.second) < (p2.second);
}

template<typename T, typename V>
/* compare only first value of pairs
 non-decreasing*/
bool pairCompareOnlyFirst(const pair<T, V> &p1, const pair<T, V> &p2) {
    if (p1.first == p2.first)
        return (p1.second) < (p2.second);
    else
        return (p1.first) < (p2.first);
}

#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    print(x)
#else
#define debug(x...)
#endif

// int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int t = 1;
//    cin >> t;
    while (t--) solve();
    return 0;
}

unsigned int iter_factorial(unsigned int n) {
    unsigned int ret = 1;
    for (unsigned int i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}

unsigned ll gcd(unsigned long long int a, unsigned long long int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

unsigned ll lcm(unsigned long long int a, unsigned long long int b) {
    return a > b ? a * (b / gcd(a, b)) : b * (a / gcd(a, b));
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

template<typename T, typename V>
bool compare(const pair<T, V> &p1, const pair<T, V> &p2) {
    if (p1.first == p2.first)
        return (p1.second) < (p2.second);
    else
        return (p1.first) > (p2.first);
}


void solve() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    ll n, m, l = 0, cnt = 1, triangle = 1;
    cin >> n >> m;
    set<vll> a;
    vll prefDeg(n + 1, 0);
    vll d(n);

    forn(i, n) {
        cin >> d[i];
        l += d[i];
        cnt *= m, cnt %= 998244353;
        triangle *= m, triangle %= 998244353;
        prefDeg[i + 1] = prefDeg[i] + d[i];
    }
    triangle /= m, triangle /= m, triangle-=m;
    ll left = 0;
    bool ok = false, okok = false;
    int i = 0;
    while (i < n) {
        if (2 * (prefDeg[i+1] - prefDeg[left])  == l) {

            cnt -= triangle;
            ok = true;
            if (i + 1 == n) okok = true;
            i++;
        } else if (2 * (prefDeg[i+1] - prefDeg[left]) > l)
            left++;
        else {
            i++;
        }
    }
    if (!okok && (2 * (prefDeg[n] - prefDeg[left])  == l)) {
        cnt -= triangle;
        ok = true;
    }
    if (ok) cnt-=m;

    cout << cnt << endl;
}