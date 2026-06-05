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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
 
void solve() {

    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> a[i][j];

    int g = gcd(a[0][0], a[n-1][m-1]);
    int ans = 0;

    vector<vector<bool>> dp(n, vector<bool>(m));
    auto check = [&] (int x) -> bool {
        dp[0][0] = true;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i != 0 || j != 0) dp[i][j] = false;
                if(gcd(a[i][j], x) % x != 0) continue;
                if(i > 0)
                    if(dp[i-1][j]) dp[i][j] = true;
                if(j > 0)
                    if(dp[i][j-1]) dp[i][j] = true;
            }
        }

        return dp[n-1][m-1];
    };

    for(int i=1; i*i<=g; i++) {
        if(g % i != 0) continue;
        if(check(i)) ans = max(ans, i);
        if(check(g/i)) ans = max(ans, g/i);
    }

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
