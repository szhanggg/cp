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

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> adj(n);

        for(int i=0; i<m; i++) {
            int u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
        }

        vector<int> d(n);

        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        vector<bool> vis(n);
        vis[0] = true;

        while(!q.empty()) {
            auto [x, dist] = q.front();
            d[x] = dist;
            q.pop();
            for(auto y: adj[x]) {
                if(!vis[y]) {
                    q.push(make_pair(y, dist + 1));
                    vis[y] = true;
                }
            }
        }

        vector<array<int, 2>> dp(n, {INT_MAX, INT_MAX});
        dp[0] = {0, 0};


        auto calc = [&] (int i, int ac, auto self) -> int {
            if(dp[i][ac] != INT_MAX) return dp[i][ac];
            int ans = d[i];
            for(auto x: adj[i]) {
                if(d[x] > d[i]) ans = min(ans, self(x, ac, self));
            }
            dp[i][ac] = ans;
            if(ac == 0) {
                for(auto x: adj[i]) {
                    if(d[x] <= d[i]) ans = min(ans, self(x, 1, self));
                }
                dp[i][0] = ans;
            }
            return dp[i][ac];
        };

        for(int i=0; i<n; i++) {
            calc(i, 0, calc);
            cout << min(dp[i][0], dp[i][1]) << " ";
        }
        cout << "\n";

    }
    
}
