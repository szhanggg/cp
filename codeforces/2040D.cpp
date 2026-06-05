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
    vector<vector<int>> adj(n);

    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n);
    vector<int> mk(n);
    int c1 = 2; int c2 = 2*n;

    // root it at 0
    auto dfs = [&] (this auto self, int x, int d) -> void {
        vis[x] = true;
        if(d % 2) {
            mk[x] = c1;
            c1 += 2;
        } else {
            mk[x] = c2;
            c2 -= 2;
        }
        for(int y: adj[x]) {
            if(!vis[y]) self(y, d+1);
        }
    };
    dfs(0, 0);
    fill(vis.begin(), vis.end(), false);
    auto dfs2 = [&] (this auto self, int x) -> void {
        vis[x] = true;
        for(int y: adj[x]) {
            if(adj[x].size() == 1 && abs(mk[adj[x][0]] - mk[x]) == 2) {
                mk[x] = mk[adj[x][0]]-1;
            }
            if(!vis[y]) self(y);
        }
    };
    dfs2(0);

    for(int i=0; i<n; i++) {
        cout << mk[i] << " ";
    }
    cout << "\n";
    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
