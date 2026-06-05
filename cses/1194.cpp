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

    vector<string> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    queue<array<int, 5>> q;
    vector<vector<array<int, 2>>> vis(n, vector<array<int, 2>>(m));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j] == '#') {
                vis[i][j][0] = 1;
                vis[i][j][1] = 1;
            }
            if(a[i][j] == 'M') q.push({i, j, 1, 0, 0});
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j] == 'A') q.push({i, j, 0, 0, 1});

    int ei = -1, ej = -1, ep = -1;

    while(!q.empty()) {
        auto [i, j, t, p, d] = q.front();
        q.pop();

        if(i < 0 || j < 0 || i >= n || j >= m) continue;

        if(vis[i][j][p] > 0) continue;

        DEBUG(i, j, t, p, d);

        if(t == 1) {
            vis[i][j][p] = 1;
        } else {
            vis[i][j][p] = d;
            if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                ei = i; ej = j; ep = p;
                break;
            }
        }
        q.push({i-1, j, t, 1-p, 'U'});
        q.push({i+1, j, t, 1-p, 'D'});
        q.push({i, j-1, t, 1-p, 'L'});
        q.push({i, j+1, t, 1-p, 'R'});
        q.push({i, j, t, 1-p, 'S'});
    }

    if(ei == -1) {
        cout << "NO\n";
        return 0;
    }

    string ans = "";
    while(a[ei][ej] != 'A') {
        ans += vis[ei][ej][ep];
        switch(vis[ei][ej][ep]) {
            case 'U':
                ei++;
                break;
            case 'D':
                ei--;
                break;
            case 'R':
                ej--;
                break;
            case 'L':
                ej++;
                break;
        }
        ep = 1-ep;
    }

    DEBUG(vis);

    reverse(ans.begin(), ans.end());
    cout << "YES\n" << ans.size() << "\n" << ans << "\n";

}
