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
int ox; int oy;

int dist(int x, int y) {
  return abs(ox - x) + abs(oy - y);
}

array<int, 3> mdiff(int x, int y) {
  int land = x & y;
  array<int, 3> ans = {dist(x-land, y), x - land, y};
  if(land == 0) return ans;

  // find the first differing bit
  int highest = 0;
  int landc = land;
  while(landc) {
    landc >>= 1;
    highest++;
  }

  // consider moving up each number
  int next = 1LL << highest;
  int nx = next - (x & (next - 1));
  int ny = next - (x & (next - 1));
  if(nx < ans[0]) {
    auto nxans = mdiff(x + nx, y);
    if(nxans[0] < ans[0]) ans = nxans;
  }
  if(ny < ans[0]) {
    auto nyans = mdiff(x, y + ny);
    if(nyans[0] < ans[0]) ans = nyans;
  }
  // consider dropping down
  int mask = (1L << (highest - 1)) - 1;
  int dx = (mask & x) + 1;
  int dy = (mask & y) + 1;
  if(dx < ans[0]) {
    if(x - dx >= 0) {
      int nx = x - dx;
      int lx = nx & y;
      array<int, 3> dxans = {dist(nx-lx, y), nx - lx, y};
      if(dxans[0] < ans[0]) ans = dxans;
    }
  }
  if(dy < ans[0]) {
    if(y - dy >= 0) {
      int ny = y - dy;
      int ly = ny & x;
      array<int, 3> dyans = {dist(x, ny-ly), x, ny - ly};
      if(dyans[0] < ans[0]) ans = dyans;
    }
  }

  return ans;
}

void solve() {

  int x, y; cin >> x >> y;
  ox = x; oy = y;
  auto ans = mdiff(x, y);
  DEBUG(ans[0]);
  cout << ans[1] << " " << ans[2] << "\n";

}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    solve();
  }
}
