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
    cin >> t;
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
    ll n;
    cin >> n;
    vll a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    priority_queue<ll> aa(all(a)), bb(all(b));
    ll cnt = 0;
    auto check = [&](ll a) {
        return (int) floor(log10(a));
    };
    while (!aa.empty()) {
        if (aa.top() == bb.top()) {
            aa.pop();
            bb.pop();
            continue;
        }
        cnt++;
        if (aa.top() > bb.top()) {
            aa.push(check(aa.top()));
            aa.pop();
        } else {
            bb.push(check(bb.top()));
            bb.pop();
        }
    }

//    vector<multiset<ll>> vv(9);
//    vector<multiset<ll>> uu(9);
//    forn(i, n) {
//        ll x;
//        cin >> x;
//        vv[check(x)].insert(x);
//    }
//    forn(i, n) {
//        ll x;
//        cin >> x;
//        if (vv[check(x)].find(x) == vv[check(x)].end())
//            uu[check(x)].insert(x);
//        else
//            vv[check(x)].erase(x);
//    }
//    forn(i, 9) {
//        ll a = vv[8 - i].size(), b = uu[8 - i].size();
//        if (i != 8) {
//            if (a > b) {
//                uu[8 - i].clear();
//                vv[8 - i].erase(vv[8 - i].begin(), next(vv[8 - i].begin(), b));
//                for (auto x: vv[8 - i]) {
//                    vv[0].insert(check(x)+1);
//                }
//
//            } else {
//
//                vv[8 - i].clear();
//                uu[8 - i].erase(uu[8 - i].begin(), next(uu[8 - i].begin(), a));
//                for (auto x: uu[8 - i]) {
//                    uu[0].insert(check(x)+1);
//                }
//            }
//            cnt += a+b;
//        } else {
//            for (auto x: uu[8 - i]) {
//                if (vv[8 - i].find(x) != vv[8 - i].end() && x != 1) {
//                    vv[8 - i].erase(x);
//                }
//            }
//            cnt += 2*vv[0].size() - vv[0].count(1) - uu[0].count(1);
//        }
//    }
    cout << cnt << endl;
}


