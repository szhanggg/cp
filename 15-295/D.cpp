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

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, s, f; cin >> n >> m >> s >> f;
  int b, t; cin >> b >> t;

  int lb = 0; int ub = 1e7;
  vector<array<int, 5>> edges;
  for(int i=0; i<m; i++) {
    int u, v, c, tt, h;
    cin >> u >> v >> c >> tt >> h;
    edges.push_back({u, v, c, tt, h});
  }

  int am = min(s, n);

  auto test = [&] (auto self, int h) -> bool {
    vector<vector<int>> dp(n+1, vector<int>(am+1, INT_MAX));
    dp[s][0] = 0;
    for(int rd=0; rd<am; rd++) {
      for(auto e: edges) {
        auto [u, v, c, tt, hh] = e;
        if(hh > h) continue;
        for(int i=0; i<am; i++) {
          dp[v][i+c] = min(dp[v][i+c], dp[u][i] + tt);
        }
      }
    }
    DEBUG(h);
    DEBUG(dp);
    for(int i=0; i<=am; i++)
      if(dp[f][i] <= t) return true;
    return false;
  };

  while(lb < ub) {
    int mid = lb + (ub - lb) / 2;
    if(test(test, mid)) {
      ub = mid;
    } else {
      lb = mid + 1;
    }
  }
  cout << lb << "\n";
}
