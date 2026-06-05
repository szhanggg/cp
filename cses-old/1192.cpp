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

int rooms = 0;

bool vis[1007][1007];
char g[1007][1007];


int n, m;

void dfs(int i, int j) {
    if(vis[i][j]) return;
    if(g[i][j] == '#') return;
    vis[i][j] = true;
    if(i > 0) dfs(i-1, j);
    if(i < n-1) dfs(i+1, j);
    if(j > 0) dfs(i, j-1);
    if(j < m-1) dfs(i, j+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> g[i][j]; 
        }
    }
   
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(g[i][j] == '.' && (!vis[i][j])) {
                dfs(i, j);
                rooms++;
            }
        }
    }

    cout << rooms << "\n";

}
