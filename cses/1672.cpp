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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q; cin >> n >> m >> q;

    vector<vector<int>> d(n, vector<int>(n, 1e14));
    for(int i=0; i<m; i++) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }

    for(int i=0; i<n; i++) d[i][i] = 0;

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for(int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        if(d[a][b] != 1e14) {
            cout << d[a][b] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

}
