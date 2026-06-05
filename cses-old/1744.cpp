#include <bits/stdc++.h>
using namespace std;
#define int long long
 
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

    int a, b; cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1));

    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            if(j == i) {
                dp[i][j] = 0;
                continue;
            }
            int mn = INT_MAX;
            // Hori cuts
            for(int ct = 1; ct<i; ct++) {
                mn = min(mn, dp[ct][j] + dp[i-ct][j]);
            }
            for(int ct=1; ct<j; ct++) {
                mn = min(mn, dp[i][ct] + dp[i][j-ct]);
            }
            dp[i][j] = mn + 1;
            DEBUG(i, j, dp[i][j]);
        }
    }

    cout << dp[a][b] << "\n";
    
}
