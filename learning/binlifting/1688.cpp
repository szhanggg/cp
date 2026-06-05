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

const int maxlg = 20;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<vector<int>> j(maxlg+1, vector<int>(n+1));

    for(int i=2; i<=n; i++) cin >> j[0][i];

    for(int k=1; k<=maxlg; k++) {
        for(int i=1; i<=n; i++) {
            j[k][i] = j[k-1][j[k-1][i]];
        }
    }

    vector<int> depth(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=2; i<=n; i++) adj[j[0][i]].push_back(i);
    auto dfs = [&] (auto self, int x, int d) -> void {
        depth[x] = d;
        for(auto i: adj[x]) self(self, i, d+1);
    };

    dfs(dfs, 1, 0);

    DEBUG(j);
    DEBUG(depth);

    while(q--) {
        int a, b; cin >> a >> b;
        if(depth[a] < depth[b]) swap(a, b);

        int k = depth[a] - depth[b];
        for(int i=maxlg; i>=0; i--) {
            if(k >= (1 << i)) {
                a = j[i][a];
                k -= (1 << i);
            }
        }

        if(a == b) {
            cout << a << "\n";
            continue;
        }

        for(int i=maxlg; i>=0; i--) {
            if(j[i][a] != j[i][b]) {
                a = j[i][a];
                b = j[i][b];
            }
        }

        cout << j[0][a] << "\n";
    }
    
}
