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
    int n, a, b; cin >> n >> a >> b;
    if(n % 2 == 1 || a % 2 == b % 2) {
        cout << "No\n";
        return;
    }

    bool swapped = false;
    if(a % 2 == 1) {
        swap(a, b);
        swapped = true;
    }

    string ans = "";

    vector<vector<bool>> vis(n, vector<bool>(n));
    vis[a-1][b-1] = true;

    bool d = true;
    bool reached = false;
    int i = 0; int j = 0;
    while(i != n-1 || j != n-1) {
        DEBUG(i, j);
        vis[i][j] = true;
        if(i == 0) d = true;
        if(i == n-1) d = false;
        if(j == b - 1) reached = true;
        if(j > 0 && !vis[i][j-1]) {
            ans += 'L';
            j--;
            continue;
        }
        if(reached && j == b - 1) {
            if(j < n-1 && !vis[i][j+1]) {
                ans += 'R';
                j++;
                continue;
            }
        }
        if(d) {
            if(i < n-1 && !vis[i+1][j]) {
                ans += 'D';
                i++;
                continue;
            }
            if(i > 0 && !vis[i-1][j]) {
                ans += 'U';
                i--;
                continue;
            }
        } else {
            if(i > 0 && !vis[i-1][j]) {
                ans += 'U';
                i--;
                continue;
            }
            if(i < n-1 && !vis[i+1][j]) {
                ans += 'D';
                i++;
                continue;
            }
        }
        if(j < n-1 && !vis[i][j+1]) {
            ans += 'R';
            j++;
            continue;
        }
        cout << "No\n";
        return;
    }

    if(swapped) {
        int m = ans.size();
        for(int i=0; i<m; i++) {
            if(ans[i] == 'L') ans[i] = 'U';
            else if(ans[i] == 'R') ans[i] = 'D';
            else if(ans[i] == 'U') ans[i] = 'L';
            else ans[i] = 'R';
        }
    }

    cout << "Yes\n";
    cout << ans << "\n";

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        solve();
    }

}
