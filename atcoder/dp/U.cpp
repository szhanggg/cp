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

    int n; cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> a[i][j];

    int mx = (1 << n);
    vector<int> sm(mx);
    
    for(int m=0; m<mx; m++) {
        for(int i=0; i<n-1; i++) {
            if((m >> i) % 2 == 0) continue;
            for(int j=i+1; j < n; j++) {
                if((m >> j) % 2 == 0)  continue;
                sm[m] += a[i][j];
            }
        }
    }

    vector<int> dp(mx, LLONG_MIN);
    dp[0] = 0;

    for(int m=1; m<mx; m++) {
        // loop through all non-empty subsets
        for(int s=m; s; s=(s-1)&m) {
            dp[m] = max(dp[m], sm[s] + dp[m-s]);
        }
    }

    cout << dp[mx-1] << "\n";
    
}
