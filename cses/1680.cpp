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

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> in(n+1);
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }

    // Let dp[i] be the largest amount of nodes to get to i
    // Let p[i] be the previous parent
    queue<int> q;
    for(int i=2; i<=n; i++)
        if(in[i] == 0) q.push(i);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto x: adj[u]) {
            if(x == 1) continue;
            in[x]--;
            if(in[x] == 0) q.push(x);
        }
    }

    vector<int> dp(n+1);
    vector<int> p(n+1);

    q.push(1);
    dp[1] = 1;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto x: adj[u]) {
            in[x]--;
            if(in[x] == 0) q.push(x);
            if(dp[u] + 1 > dp[x]) {
                dp[x] = dp[u]+1;
                p[x] = u;
            }
        }
    }

    if(!dp[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << dp[n] << "\n";
    vector<int> path;
    for(int u = n; u != 0; u = p[u]) {
        path.push_back(u);
    }
    reverse(path.begin(), path.end());
    for(auto x: path) cout << x << " ";
    cout << "\n";

}
