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
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    int n, m, c; cin >> n >> m >> c;
    vector<int> mo(m);
    for(int i=0; i<n; i++) cin >> mo[i];

    vector<vector<int>> adj(n);

    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
    }

    vector<vector<int>> dp(1005, vector<int>(n, -1));
    dp[0][0] = 0;

    for(int t=0; t<1002; t++) {
        for(int i=0; i<n; i++) {
            if(dp[t][i] == -1) continue;
            for(auto x: adj[i]) {
                dp[t+1][x] = max(dp[t+1][x], dp[t][i] + mo[x]);
            }
        }
    }

    int ans = 0;
    for(int t=0; t<1002; t++) ans = max(ans, dp[t][0] - c*t*t);

    cout << ans << "\n";
    
}
