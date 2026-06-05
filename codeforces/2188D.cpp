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

array<int, 3> diff(int x, int y) {
  // find the first different bit
  int highest = -1;
  int land = x & y;
  array<int, 3> ans = {dist(x-land, y), x-land, y};

  // consider fixing this bit by going up
  int tmp = land;
  while(tmp) {
    tmp >>= 1;
    highest++;
  }
  if(highest == -1) return ans;
  int next = 1L << highest;
  int nexte = 1L << (highest+1);
  // whichever one is not 0 at the next bit
  if(x & nexte) {
    int nx = x + (x & (nexte-1));
    if(dist(nx, y) < ans[0]) {
      ans = {dist(nx, y), nx, y};
    }
  } else {
    int ny = y + (y & (nexte-1));
    if(dist(x, ny) < ans[0]) {
      ans = {dist(x, ny), x, ny};
    }
  }

  // consider the smallest number less than each number
  int lx = x & (next-1);
  int ly = y & (next-1);
  int nx = x - (next - ly);
  int ny = y - (next - lx);
  if(nx >= 0) {
    auto dxans = diff(nx, y);
    if(dxans[0] < ans[0]) ans = dxans;
  }
  if(ny >= 0) {
    auto dyans = diff(x, ny);
    if(dyans[0] < ans[0]) ans = dyans;
  }

  return ans;

}

void solve() {

  int x, y; cin >> x >> y;
  ox = x; oy = y;
  auto ans = diff(x, y);
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
