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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> pre(n+1);
    for(int i=0; i<n; i++) pre[i+1] = pre[i] + a[i];

    DEBUG(pre);

    vector<vector<int>> dp(n, vector<int>(n, LLONG_MAX));
    // dp[i][j] rep min answer from i..j

    for(int k=0; k<n; k++) {
        for(int i=0; i<n-k; i++) {
            int j = i+k;
            if(k == 0) {
                dp[i][j] = 0;
                continue;
            }
            if(k == 1) {
                dp[i][j] = pre[j+1] - pre[i];
                continue;
            }

            // consider all the possible last elements
            for(int l=i; l<j; l++) {
                dp[i][j] = min(dp[i][j], dp[i][l] + dp[l+1][j]);
            }
            dp[i][j] += pre[j+1] - pre[i];
            DEBUG(i, j, dp[i][j]);
        }
    }

    for(int i=0; i<n; i++) {
        DEBUG(i, dp[i]);
    }


    cout << dp[0][n-1] << "\n";
    
}
