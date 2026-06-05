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
const int MAXX = 1e15;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n);

  for (int i = 0; i < m; i++) {
      int a, b, c; cin >> a >> b >> c; a--; b--;
      adj[a].push_back({b, c});
  }

  vector<array<int, 2>> dp(n, {MAXX, MAXX});
  vector<array<bool, 2>> vis(n);

  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
  // dist, status, number
  pq.push({0, 1, 0});

  dp[0][1] = 0;

  while (!pq.empty()) {
    auto [d, s, i] = pq.top();
    pq.pop();
    if (vis[i][s]) continue;
    vis[i][s] = true;
    for (auto y : adj[i]) {
      dp[y.first][s] = min(dp[y.first][s], dp[i][s] + y.second);
      pq.push({dp[y.first][s], s, y.first});
    }
    if (s == 1) {
      for (auto y : adj[i]) {
        dp[y.first][0] = min(dp[y.first][0], dp[i][s] + y.second / 2);
        pq.push({dp[y.first][0], 0, y.first});
      }
    }
  }

  cout << dp[n-1][0] << "\n";

}
