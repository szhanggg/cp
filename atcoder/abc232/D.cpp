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

bool vis[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;

    vector<vector<char>> c(h, vector<char>(w));

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> c[i][j];
        }
    }

    queue<array<int, 3>> q;
    q.push({0, 0, 1});

    int maxdist = 0;

    while(!q.empty()) {
        auto [i, j, dist] = q.front(); q.pop();
        if(i == h || j == w) continue;
        if(c[i][j] == '#') continue;
        if(vis[i][j]) continue;
        maxdist = max(maxdist, dist);

        vis[i][j] = true;

        q.push({i, j+1, dist+1});
        q.push({i+1, j, dist+1});
    }

    cout << maxdist << "\n";

}
