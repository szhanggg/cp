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
    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1);

    int s = -1;

    auto dfs = [&] (auto self, int x, int prev) -> void {
        vis[x] = 1;
        for(int y: adj[x]) {
            if(y == prev) continue;
            if(vis[y]) {
                s = y;
            } else {
                self(self, y, x);
            }
        }
    };

    for(int i=1; i<=n; i++) {
        if(!vis[i]) dfs(dfs, i, -1);
    }

    if(s == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path;

    fill(vis.begin(), vis.end(), 0);
    auto dfs2 = [&] (auto self, int x) -> bool {
        path.push_back(x);
        if(vis[x]) {
            if(x == s)
                if(path.size() > 3) return true;
            path.pop_back();
            return false;
        }
        vis[x] = 1;
        for(auto y: adj[x]) {
            if(self(self, y)) return true;
        }
        path.pop_back();
        return false;
    };

    dfs2(dfs2, s);

    cout << path.size() << "\n";
    for(int x: path) cout << x << " ";
    cout << "\n";
    
}
