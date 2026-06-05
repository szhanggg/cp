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
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string s; cin >> s;

    vector<int> ans(n);

    vector<int> vis1(n, -1);
    vector<int> vis2(n, -1);

    queue<array<int, 3>> q;
    // curindex, dist, index of S
    for(int i=0; i<n; i++) {
        if(s[i] == 'S') {
            q.push({i, 0, i});
        }
    }

    while(!q.empty()) {
        auto [ci, d, si] = q.front();
        q.pop();
        ans[ci] += d;
        for(auto x: adj[ci]) {
            if(vis2[x] != -1) continue;
            if(vis1[x] != -1) {
                if(vis1[x] == si) continue;
                vis2[x] = si;
                q.push({x, d+1, si});
            } else {
                vis1[x] = si;
                q.push({x, d+1, si});
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(s[i] == 'D') {
            cout << ans[i] << "\n";
        }
    }
    
}
