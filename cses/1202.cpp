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
const int MOD = 1e9+7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> indeg(n+1);
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<array<int, 4>> dp(n+1, {(long long) 1e15, 0, (long long)1e15, 0});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dp[1] = {0, 1, 0, 0};
    q.push({0, 1});
    vector<bool> vis(n+1);

    while(!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [x, c]: adj[u]) {
            int tmp = dp[u][0] + c;
            if(tmp == dp[x][0]) {
                dp[x][1] += dp[u][1];
                dp[x][1] %= MOD;
                dp[x][2] = min(dp[x][2], dp[u][2]+1);
                dp[x][3] = max(dp[x][3], dp[u][3]+1);
            } else if(tmp < dp[x][0]) {
                dp[x][0] = tmp;
                dp[x][1] = dp[u][1];
                dp[x][2] = dp[u][2]+1;
                dp[x][3] = dp[u][3]+1;
            }
            q.push({dp[x][0], x});

        }
    }

    for(auto x: dp[n]) cout << x << " ";
    cout << "\n";

}
