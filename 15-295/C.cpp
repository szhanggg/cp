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

vector<int> nx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> ny = {-1, 0, 1, -1, 1, -1, 0, 1};

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  int ci, cj; cin >> ci >> cj; ci--; cj--;
  int ri, rj; cin >> ri >> rj; ri--; rj--;

  vector<vector<int>> A(n, vector<int>(m));
  for(int i=0; i<n; i++) {
    for(int j=0;j < m; j++) {
      char c; cin >> c;
      A[i][j] = c - '0';
    }
  }

  vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {INT_MAX, INT_MAX}));
  vector<vector<bool>> vis(n, vector<bool>(m));
  // first element is number of changes second is the length of the path
  priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
  // number of changes
  pq.push({0, 1, ci*m+ cj});
  dp[ci][cj] = {0, 1};

  while(!pq.empty()) {
    auto [c, _, v] = pq.top(); pq.pop();
    int i = v / m; int j = v % m;
    if(i < 0 || j < 0 || i >= n || j >= m) continue;
    if(vis[i][j]) continue;
    vis[i][j] = true;
    DEBUG(i, j);
    for(int k=0; k<8; k++) {
      int ni = i + nx[k];
      int nj = j + ny[k];
      if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
      if(A[ni][nj] == 0) continue;
      int l = 1 - (A[ni][nj] == A[i][j]);
      pair<int, int> neww = {c + l, dp[i][j].second + 1};
      if(neww.first < dp[ni][nj].first) {
        dp[ni][nj] = neww;
      } else if(neww.first == dp[ni][nj].first) {
        dp[ni][nj].second = min(dp[ni][nj].second, neww.second);
      }
      if(!vis[ni][nj]) {
        pq.push({dp[ni][nj].first, dp[ni][nj].second, ni*m + nj});
      }
    }
  }

  if(dp[ri][rj].first == INT_MAX) {
    cout << "0 0\n";
  } else {
  cout << dp[ri][rj].second << " " << dp[ri][rj].first << "\n";
  }

}
