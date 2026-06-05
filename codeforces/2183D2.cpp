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

void solve() {

    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> d(n+1);
    vector<int> par(n+1, -1);
    vector<int> parent(n+1);

    auto dfs = [&] (this auto self, int x, int p) -> void {
        parent[x] = p;
        d[x] = d[p]+1;
        if(par[d[x]] == -1) par[d[x]] = p;
        if(par[d[x]] != p) {
            par[d[x]] = -100;
        }

        for(auto y: adj[x]) {
            if(y == p) continue;
            self(y, x);
        }
    };

    d[0] = -1;
    parent[1] = 0;
    dfs(1, 0);

    vector<set<int>> dist(n+1);
    for(int i=1; i<=n; i++) dist[d[i]].insert(i);

    int cmax = 0;

    for(int i=1; i<=n; i++) {
        int cur = dist[i].size();
        if(par[i] != -100) cur++;
        cmax = max(cmax, cur);
    }

    vector<set<int>> clusters;

    for(int i=1; i<=n; i++) {
        int cur = dist[i].size();
        if(cur == 0) continue;
        set<int> s;
        for(auto x: dist[i]) s.insert(x);
        if(par[i] != -100) s.insert(par[i]);
        clusters.push_back(s);
    }

    cout << cmax << "\n";


}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
