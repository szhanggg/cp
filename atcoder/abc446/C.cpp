#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
      if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

#define int long long

void solve() {

  int n, d; cin >> n >> d;
  vector<int> a(n);
  vector<int> b(n);

  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];

  queue<pair<int, int>> q;
  for(int i=0; i<n; i++) {
    DEBUG(i);
    q.push({i, a[i]});
    int am = b[i];
    DEBUG(am);
    while(am > 0) {
      auto top = q.front();
      int rm = min(am, top.second);
      am -= rm;
      q.front().second -= rm;
      if(top.second == 0) q.pop();
    }
    while(q.size() != 0 && i - q.front().first >= d) q.pop();
    DEBUG(q.front());
  }

  int acc = 0;
  while(q.size() != 0) {
    auto top = q.front();
    acc += top.second;
    q.pop();
  }

  cout << acc << "\n";

}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    solve();
  }
}
