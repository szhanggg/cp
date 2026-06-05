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

    int n, m; cin >> n >> m;

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> b(m);
    for(int i=0; i<m; i++) cin >> b[i];

    vector<vector<int>> dp(n, vector<int>(m));

    // dp[i][j] represents LCS of 0..i and 0..j
    // if a[i] == b[j] LCS = max(LCS[i-1][j-1] + 1)
    vector<vector<int>> mo(n, vector<int>(m));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i > 0) {
                if(dp[i-1][j] > dp[i][j]) {
                    dp[i][j] = dp[i-1][j];
                    mo[i][j] = 0;
                }
            }
            if(j > 0) {
                if(dp[i][j-1] > dp[i][j]) {
                    dp[i][j] = dp[i][j-1];
                    mo[i][j] = -1;
                }
            }
            if(a[i] == b[j]) {
                if(i > 0 && j > 0) {
                    if(dp[i-1][j-1] + 1 > dp[i][j]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                        mo[i][j] = a[i];
                    }
                } else {
                    if(1 > dp[i][j]) {
                        dp[i][j] = 1;
                        mo[i][j] = a[i];
                    }
                }
            }
        }
    }

    vector<int> ans;
    int i = n-1; int j = m-1;
    while(i >= 0 && j >= 0) {
        int mv = mo[i][j];
        if(mv == 0) {
            i--;
        } else if(mv == -1) {
            j--;
        } else {
            ans.push_back(mv);
            i--;
            j--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << dp[n-1][m-1] << "\n";
    for(auto x: ans) {
        cout << x << " ";
    }
    cout << "\n";
    
}
