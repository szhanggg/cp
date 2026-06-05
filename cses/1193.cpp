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
    vector<vector<char>> vis(n, vector<char>(m));
    queue<array<int, 3>> q;
    int ei = 0, ej = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j] == 'A') q.push({i, j, 0});
            if(a[i][j] == 'B') {
                ei = i; ej = j;
            }
            if(a[i][j] == '#') vis[i][j] = 1;
        }
    }

    while(!q.empty()) {
        auto p = q.front(); q.pop();
        int i = p[0], j = p[1], d = p[2];
        if(i < 0 || i >= n || j < 0 || j >= m) continue;
        if(vis[i][j]) continue;
        vis[i][j] = d;

        q.push({i-1,j,'U'});
        q.push({i+1,j,'D'});
        q.push({i,j-1,'L'});
        q.push({i,j+1,'R'});
    }

    if(!vis[ei][ej]) {
        cout << "NO\n";
        return 0;
    }

    string ans = "";
    while(a[ei][ej] != 'A') {
        char d = vis[ei][ej];
        ans += d;
        if(d == 'U') {
            ei++;
        } else if(d == 'D') {
            ei--;
        } else if(d == 'L') {
            ej++;
        } else {
            ej--;
        }
    }
    reverse(ans.begin(), ans.end());

    cout << "YES\n" << ans.size() << "\n" << ans << "\n";
    
}
