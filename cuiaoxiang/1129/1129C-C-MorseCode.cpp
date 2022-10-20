// url:https://codeforces.com/contest/1129/problem/C
// time:2022-04-29 12:24:46
// name:C-MorseCode

// #define LOCAL
#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>

using namespace std;

template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const multiset<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
  return out;
}
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

template <class T> auto vect(const T& v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
  return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}

using int64 = long long;
using int128 = __int128_t;
using ii = pair<int, int>;
#define SZ(x) (int)((x).size())
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
mt19937_64 mrand(random_device{}());
int64 rnd(int64 x) { return mrand() % x; }
int lg2(int64 x) { return sizeof(int64) * 8 - 1 - __builtin_clzll(x); }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < SZ(a); ++i) cout << a[i] << " \n"[i + 1 == SZ(a)]; }
template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <class T> void dedup(vector<T>& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
void add_mod(int& x, int y) { x += y; if (x >= MOD) x -= MOD; }
void sub_mod(int& x, int y) { x += MOD - y; if (x >= MOD) x -= MOD; }

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

 private:
  int v;
  static int minv(int a, int m) {
    a %= m; assert(a);
    return a == 1 ? 1 : int(m - int64(minv(m, a)) * int64(m) / a);
  }

 public:
  modnum() : v(0) {}
  modnum(int64 v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { int64 v_; in >> v_; n = modnum(v_); return in; }
  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

  modnum inv() const { modnum res; res.v = minv(v, MOD); return res; }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const { modnum res; res.v = v ? MOD-v : 0; return res; }
  friend modnum neg(const modnum& m) { return m.neg(); }

  modnum operator- () const { return neg(); }
  modnum operator+ () const { return modnum(*this); }

  modnum& operator ++ () { ++v; if (v == MOD) v = 0; return *this; }
  modnum& operator -- () { if (v == 0) v = MOD; --v; return *this; }
  modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
  modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
  modnum& operator *= (const modnum& o) { v = int(int64(v) * int64(o.v) % MOD); return *this; }
  modnum& operator /= (const modnum& o) { return *this *= o.inv(); }

  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
  friend modnum power(modnum a, int64 n) {
    modnum ret = 1;
    for (; n; n >>= 1) {
      if (n & 1) ret *= a;
      a *= a;
    }
    return ret;
  }
};

using mint = modnum<MOD>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  auto lcp = vect<int>(0, n + 1, n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      lcp[i][j] = a[i - 1] == a[j - 1] ? 1 + lcp[i - 1][j - 1] : 0;
    }
  }

  auto dp = vect<mint>(0, n + 1, n + 1);

  vector<bool> forbid(16);
  forbid[3] = forbid[5] = forbid[14] = forbid[15] = 1;

  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 1;
    for (int k = 1; k <= 3 && k <= i; ++k) {
      for (int j = k; j <= i; ++j) {
        dp[i][j] += dp[i - k][j - k];
      }
    }
    if (4 <= i) {
      int sum = 0;
      for (int j = 0; j < 4; ++j) sum = sum * 2 + a[i - 4 + j];
      if (!forbid[sum]) {
        for (int j = 4; j <= i; ++j) {
          dp[i][j] += dp[i - 4][j - 4];
        }
      }
    }
    trace(i, dp[i]);
  }

  mint ret = 0;
  for (int i = 1; i <= n; ++i) {
    int len = 0;
    for (int j = 1; j < i; ++j) ckmax(len, lcp[i][j]);
    trace(i, len);
    for (int k = len + 1; k <= i; ++k) ret += dp[i][k];
    cout << ret << '\n';
  }
  return 0;
}

