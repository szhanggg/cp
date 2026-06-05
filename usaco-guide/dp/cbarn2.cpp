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

int solve(vector<int> &r, int n, int k) {
    vector<vector<int>> dp(k+1, vector<int>(n, INT_MAX));

    dp[1][0] = 0;

    for(int i=1; i<n; i++) {
        dp[1][i] = dp[1][i-1] + i*r[i];
    }

    for(int am=2; am<=k; am++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                //consider opening a door at j
                int cur = 0;
                for(int l=1; l<i-j+1; l++) {
                    cur += l*r[j+l];
                }
                dp[am][i] = min(dp[am][i], cur + (j > 0 ? dp[am-1][j-1] : 0));
            }
        }
    }

    return dp[k][n-1];

}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);

    int n, k; cin >> n >> k;
    vector<int> r(n); for(int i=0; i<n; i++) cin >> r[i];

    int ans = INT_MAX;

    for(int i=0; i<n; i++) {
        ans = min(ans, solve(r, n, k));
        int t = r[0];
        for(int i=0; i<n-1; i++) r[i] = r[i+1];
        r[n-1] = t;
    }

    cout << ans << "\n";
    
}
