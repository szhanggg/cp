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

bool has_edge(array<int, 4> x, array<int, 4> y) {
    if(abs(x[0]-y[1]) == 1 || abs(x[1]-y[0]) == 1) {
        if(x[3] >= y[2] && x[3] <= y[3]) return true;
        if(x[2] >= y[2] && x[2] <= y[3]) return true;
        if(y[2] >= x[2] && y[2] <= x[3]) return true;
        if(y[3] >= x[2] && y[3] <= x[3]) return true;
    }
    if(abs(x[2]-y[3]) == 1 || abs(x[3]-y[2]) == 1) {
        if(x[1] >= y[0] && x[1] <= y[1]) return true;
        if(x[0] >= y[0] && x[0] <= y[1]) return true;
        if(y[0] >= x[0] && y[0] <= x[1]) return true;
        if(y[1] >= x[0] && y[1] <= x[1]) return true;
    }
    return false;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y; cin >> n >> x >> y;
    vector<char> c(n);
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> c[i] >> a[i] >> b[i];

    vector<array<int, 4>> chunks;
    // chunks are stored as (x1, x2, y1, y2) where those are the 4 boundaries
    // all boundaries are inclusive
    chunks.push_back({0, x-1, 0, y-1});
    DEBUG(chunks);

    for(int i=0; i<n; i++) {
        vector<array<int, 4>> newchunks;
        for(auto chunk: chunks) {
            if(c[i] == 'X') {
                if(chunk[0] <= a[i]-1) {
                    int rend = min(a[i]-1, chunk[1]);
                    newchunks.push_back({chunk[0], rend, chunk[2]-b[i], chunk[3]-b[i]});
                }
                if(chunk[1] >= a[i]) {
                    newchunks.push_back({max(a[i], chunk[0]), chunk[1], chunk[2]+b[i], chunk[3]+b[i]});
                }
            } else {
                if(chunk[2] <= a[i]-1) {
                    int rend = min(a[i]-1, chunk[3]);
                    newchunks.push_back({chunk[0]-b[i], chunk[1]-b[i], chunk[2], rend});
                }
                if(chunk[3] >= a[i]) {
                    newchunks.push_back({chunk[0]+b[i], chunk[1]+b[i], max(a[i], chunk[2]), chunk[3]});
                }
            }
        }
        chunks = newchunks;
        DEBUG(chunks);
    }

    int m = chunks.size();
    vector<vector<int>> adj(m);
    vector<int> sz(m);

    for(int i=0; i<m; i++) {
        int area = chunks[i][1] - chunks[i][0] + 1;
        area *= chunks[i][3] - chunks[i][2] + 1;
        sz[i] = area;
    }

    DEBUG(sz);

    for(int i=0; i<m; i++) {
        for(int j=i+1; j<m; j++) {
            if(has_edge(chunks[i], chunks[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    DEBUG(adj);

    vector<bool> vis(m);
    int cur = 0;
    auto dfs = [&](this auto self, int i) -> void {
        vis[i] = true;
        cur += sz[i];
        for(int nn: adj[i]) {
            if(!vis[nn]) self(nn);
        }
    };

    vector<int> ans;
    for(int i=0; i<m; i++) {
        cur = 0;
        if(!vis[i]) dfs(i);
        if(cur > 0) ans.push_back(cur);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto NN: ans) cout << NN << " ";
    cout << "\n";
 
}
