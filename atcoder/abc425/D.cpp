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
    
    int h, w; cin >> h >> w;
    vector<string> a(h);

    for(int i=0; i<h; i++) cin >> a[i];

    queue<array<int, 3>> q;

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            if(a[i][j] == '#') q.push({i, j, 0});

    vector<vector<bool>> vis(h, vector<bool>(w));

    int curd = 0;
    vector<pair<int, int>> changes;

    while(!q.empty()) {
        auto [i, j, d] = q.front();
        q.pop();
        if(i < 0 || j < 0 || i >= h || j >= h) continue;
        int am = 0;

        if(d != curd) {
            for(auto pi: changes) {
                a[pi.first][pi.second] = '#';
            }
            curd = d;
            changes.clear();
        }

        if(i > 0)
            if(a[i-1][j] == '#') am++;
        if(j > 0)
            if(a[i][j-1] == '#') am++;
        if(i < h-1)
            if(a[i+1][j] == '#') am++;
        if(j < w-1)
            if(a[i][j+1] == '#') am++;

        if(am == 1) {
            changes.push_back({i, j});
        }
        if(am >= 1) vis[i][j] = true;

        if(a[i][j] == '#' || am == 1) {

        if(i > 0)
            if(!vis[i-1][j]) q.push({i-1, j, d+1});
        if(j > 0)
            if(!vis[i][j-1]) q.push({i, j-1, d+1});
        if(i < h-1)
            if(!vis[i+1][j]) q.push({i+1, j, d+1});
        if(j < w-1)
            if(!vis[i][j+1]) q.push({i, j+1, d+1});
        }

    }

    int ans = 0;
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            if(a[i][j] == '#') ans++;

    cout << ans << "\n";

}
