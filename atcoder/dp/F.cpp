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

    string s, t; cin >> s >> t;
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<vector<int>> dir(n+1, vector<int>(m+1));

    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int i=0; i<=m; i++) {
        dp[0][i] = 0;
        dir[0][i] = 1;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                dir[i][j] = 2;
            }
            if(dp[i-1][j] > dp[i][j]) {
                dp[i][j] = dp[i-1][j];
                dir[i][j] = 0;
            }
            if(dp[i][j-1] > dp[i][j]) {
                dp[i][j] = dp[i][j-1];
                dir[i][j] = 1;
            }
        }
    }

    string ans = "";
    int i = n; int j = m;
    while(i > 0 || j > 0) {
        if(dir[i][j] == 0) {
            i--;
        } else if(dir[i][j] == 1) {
            j--;
        } else {
            ans += s[i-1];
            i--; j--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
    
}
