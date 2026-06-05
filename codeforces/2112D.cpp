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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for(int i=0; i<n-1; i++) {
            int u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int root = -1;
        for(int i=0; i<n; i++) {
            if(adj[i].size() == 2) root = i;
        }

        if(root == -1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        int i1 = adj[root][0];
        int i2 = adj[root][1];

        cout << i1 + 1 << " " << root + 1 << "\n";
        cout << root + 1 << " " << i2 + 1 << "\n";


        vector<bool> vis(n);
        auto dfs = [&] (auto self, int i, bool dir) -> void {
            vis[i] = true;
            for(auto x: adj[i]) {
                if(!vis[x]) {
                    if(dir) {
                        cout << i + 1 << " " << x + 1 << "\n";
                    } else {
                        cout << x + 1 << " " << i + 1 << "\n";
                    }
                    self(self, x, !dir);
                }
            }
        };

        vis[root] = true;

        dfs(dfs, i1, true);
        dfs(dfs, i2, false);

    }
    
}
