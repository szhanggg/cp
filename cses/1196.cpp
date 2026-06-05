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

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<pair<int, int>>> adj(n+1);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 1});
  vector<priority_queue<int>> dist(n + 1);
  dist[1].push(0);

  while (!pq.empty()) {
    auto [d, i] = pq.top();
    pq.pop();
    if(d > dist[i].top()) continue;
    for (auto y : adj[i]) {
      int t = d + y.second;
      if (dist[y.first].size() < k) {
        dist[y.first].push(t);
        pq.push({t, y.first});
      } else if (t < dist[y.first].top()) {
        dist[y.first].pop();
        dist[y.first].push(t);
        pq.push({t, y.first});
      }
    }
  }

  vector<int> ans;
  while (!dist[n].empty()) {
    ans.push_back(dist[n].top());
    dist[n].pop();
  }
  reverse(ans.begin(), ans.end());

  for (int i = 0; i < k; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
