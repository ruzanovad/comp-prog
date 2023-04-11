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

#define isOn(s, j) (s & (1<<j))
#define setBit(s, j) (s |= (1<<j))
#define clearBit(s, j) (s &= ~(1<<j))
#define toggleBit(s, j) (s ^= (1<<j))
#define lowBit(s) (s & (-s))
#define setAll(s, n) (s = (1<<n)-1)

#define modulo(s, N) ((s) & (N-1))   // returns s % N, where N is a power of 2
#define isPowerOfTwo(s) (!(s & (s-1)))
#define nearestPowerOfTwo(s) (1<<lround(log2(s)))
#define turnOffLastBit(s) ((s) & (s-1))
#define turnOnLastZero(s) ((s) | (s+1))
#define turnOffLastConsecutiveBits(s) ((s) & (s+1))
#define turnOnLastConsecutiveZeroes(s) ((s) | (s-1))

const string all = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const string numbers = "0123456789";
const string upperalpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string loweralpha = "abcdefghijklmnopqrstuvwxyz";
const int MAXN = 2e5 + 5;

unsigned ll gcd(unsigned ll a, unsigned ll b);

unsigned ll lcm(unsigned ll a, unsigned ll b);

vector<int> z_function(string s);

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

template<typename T>
vector<T> factors(T n);

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

template<typename T>
vector<T> factors(T n) {
    vector<T> f;
    for (T x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
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
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif // ONLINE_JUDGE
    int t = 1;
//    cin >> t;
    while (t--) solve();
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

unsigned long long binaryLength(unsigned ll n) {
    int count = 1;
    while (n / 2 != 0) {
        count++;
        n /= 2;
    }
    return count;
}

template<typename T, typename V>
bool compare(const pair<T, V> &p1, const pair<T, V> &p2) {
    if (p1.first == p2.first)
        return (p1.second) < (p2.second);
    else
        return (p1.first) > (p2.first);
}

void solve() {
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "right", stdin);
//    freopen("output.txt", "w", stdout);
//#endif // ONLINE_JUDGE
    int n;
    cin >> n;
    vi a = vi(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int left = a[n - 1], right = left;
    int i = 0, j = n - 2;
    ll sum = 0;
    while (i < j) {
        int
                li = abs(left - a[i]),
                lj = abs(left - a[j]),
                ri = abs(right - a[i]),
                rj = abs(right - a[j]);
        if (li <= ri && lj <= rj) {
            if (ri > rj) {
                sum += ri;
                right = a[i];
                i++;
            } else {
                sum += rj;
                right = a[j];
                j--;
            }
        } else {
            if (li > lj) {
                sum += li;
                left = a[i];
                i++;
            } else {
                sum += lj;
                left = a[j];
                j--;
            }
        }

    }
    sum += max(abs(right - a[i]), abs(left - a[i]));
    cout << sum;
}